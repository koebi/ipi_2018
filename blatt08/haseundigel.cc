#include "fcpp.hh"

// Ein Listenelement
struct IntListElem
{
  IntListElem* next;  // Zeiger auf naechstes Element
  int value;          // Daten zu diesem Element  
} ;

// Eine Liste
struct IntList
{
  IntListElem* first; // Zeiger auf erstes Element der Liste
} ;

// Initialisiere eine Listenstruktur
void empty_list( IntList* l )
{
  l->first = 0;   // 0 ist keine gueltige Adresse: Liste ist leer
}

// Fuege ein Element nach einem gegebenem ein
void insert_in_list( IntList* list, IntListElem* where, IntListElem* ins )
{
  if ( where == 0 ) // fuege am Anfang ein
  {
    ins->next = list->first;
    list->first = ins;
  }
  else              // fuege nach where ein
  {
    ins->next = where->next;
    where->next = ins;
  }
}

// Erzeugt ein Listenelement
IntListElem* create_element(int value) {
  IntListElem* element = new IntListElem;
  element->next = 0;
  element->value = value;
  return element;
}

// Erzeugt eine Liste der Laenge n mit beliebigen Werten
IntList create_list(int n)
{
  IntList liste;
  empty_list(&liste);
  for(int i = 0; i < n; ++i) {
    insert_in_list(&liste, 0, create_element(i));
  }
  return liste;
}

// Hase und Igel Algorithmus zur Erkennung von Zyklen und Bestimmung der
// Laenge des linearen und zyklischen Teils der Liste.
void hase_und_igel(IntList liste) {
  int k, n;
  IntListElem* hase;
  IntListElem* igel;

  // Iteriere bis zum ersten Treffen
  igel = liste.first;
  hase = liste.first;
  while(hase != 0) {
    igel = igel->next;
    hase = hase->next;
	// muss hier überprüft werden, da hase das letzte Element sein könnte,
	// hase->next somit 0 und 0->next schiefgeht.
    if(hase != 0) hase = hase->next;
    if(hase == igel) {
      break;
    }
  }
  //Schleifenende entweder über hase == igel oder über hase == 0
  
  // Kein Zyklus falls wir das Ende entdeckt haben
  if(hase == 0) {
    print("Kein Zyklus");
    // Zaehle Anzahl Listenelemente um k zu bestimmen
    k = 0;
    igel = liste.first;
    while(igel) {
      k = k + 1;
      igel = igel->next;
    }
    n = 0;
  } else {
    print("Zyklus");
    // Setze den Hasen zurueck auf die Startposition und lass diesmal beide
    // gleich schnell laufen um k zu bestimmen
	//
	// Die Idee hier ist, dass der Igel nach k Schritten den Anfang der Liste
	// erreicht hat. Der Hase ist zu diesem Zeitpunkt 2*k Schritte gelaufen,
	// befindet sich also irgendwo im Zyklus.
	//
	// Fall 1: n > k
	// Der Hase befindet sich an Element n-k des Zyklus. Der Abstand Hase-Igel
	// ist also n-k. Der Hase holt jede Iteration einen Schritt auf. Damit
	// treffen Hase und Igel sich nach n-k Schritten, also auf Element n-k.
	//
	// Lassen wir jetzt den Hasen vom Anfang und den Igel vom Treffpunkt laufen,
	// und beide gleich schnell, ist der Hase nach k Schritten am Anfang des
	// Zyklus, der Igel bei Element n des Zyklus, also auch am Anfang. Damit
	// treffen sie sich.
	//
	// Fall 2: n < k
	// Falls n < k gilt k = l*n + m.
	// Nach k Schritten ist der Igel also am Anfang des Zyklus, der Hase an
	// Element n-m des Zyklus (Er ist die k Schritte des Linearteils gelaufen
	// und dann nochmal k= l*n + m Schritte weiter, also l mal durch den Zyklus
	// und noch m Schritte). Zwischen Hase und Igel sind also n-m Elemente
	// Abstand, die beiden treffen sich an Element n-m.
	//
	// Lassen wir jetzt den Hasen vom Anfang und den Igel vom Treffpunkt gleich
	// schnell laufen, ist der Hase nach k Schritten am Anfang, der Igel nach k
	// Schritten an Element (n-m) + k = (n-m+ l*n + m) = (l+1)*n, also auch am
	// Anfang und die beiden treffen sich wieder.
    hase = liste.first;
    k = 0;
    while(hase != igel) {
      k = k + 1;
      igel = igel->next;
      hase = hase->next;
    }
    // Lass den Hasen fix und zaehle die benoetigten Schritte bis der Igel
    // wieder beim Hasen ankommt um n zu bestimmen
    n = 1;
    igel = igel->next;
    while(hase != igel) {
      n = n + 1;
      igel = igel->next;
    }
  }
  print("k:");
  print(k);
  print("n:");
  print(n);
}

int main(int argc, char** argv) {
  int k = readarg_int(argc, argv, 1);
  int n = readarg_int(argc, argv, 2);

  IntListElem* element;

  // Erzeuge Zykel der Laenge n
  IntList zykel = create_list(n);
  if(n > 0) {
    // Gehe zum letzten Element und setze next auf das erste Element
    element = zykel.first;
    while(element->next) {
      element = element->next;
    }
    element->next = zykel.first;
  }

  // Erzeuge Linearteil der Laenge k und setze letztes next auf erstes
  // Element des Zykels
  IntList liste;
  if(k > 0) {
    liste = create_list(k);
    element = liste.first;
    while(element->next) {
      element = element->next;
    }
    element->next = zykel.first;
  } else {
    liste.first = zykel.first;
  }

  hase_und_igel(liste);
}
