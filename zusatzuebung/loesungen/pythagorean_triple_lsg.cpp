/*Pythagoreische Tripel sind drei natürliche Zahlen a < b < c sodass a^2 + b^c =
 *c^2. Es gibt genau ein Tripel mit a + b + c = 1000. Der vorliegende Code soll
 *deren Produkt a*b*c ausgeben.
 *
 *a) Der Code enthält X syntaktische und semantische Fehler. Diese sind zu
 *   finden, zu erklären und zu beheben.
 *   [Falsche Zeilen auskommentiert und behoben, Lsg. in eckigen Klammern]
 *
 *b) Der Code tätigt in Zeile XX (while c < 500) eine implizite Annahme über das
 *   Problem. Beweisen sie diese.
 *
 *c) Der Code nutzt while-Schleifen. Schreiben sie den Code so um, dass er
 *   for-Schleifen verwendet. 
 *
 *d) Es werden jetzt folgende Änderungen eingefügt:
 *   Zeile 36: int n = input();  (Input ist eine Funktion, die in einer
 *   beliebigen Art und Weise eine Zahl einliest)
 *   Zeile 37: 500 -> n/2 + 1
 *   Zeile 41: 1000 -> n
 *
 *   Bestimmen Sie die Laufzeit der main() Funktion abhängig von der Zahl, die
 */


#include <iostream>
//#include <output> 
//[output ist kein valider header aus der STL']

void output(int a, int b, int c) {
//void output(int a, b, c) {
//[b und c brauchen auch einen Typ, das funktioniert nicht wie in
//Variablendeklarationen]
	std::cout << a  << ", " << b << ", " << c 
	<< " sind pyth. Tripel mit Summe 1000 und Produkt " 
//	a*b*c << std::endl;
//	[hier fehlt einfach ein "<<"]
	<< a*b*c << std::endl;
}


int main() {
	
	//int a, b, c = 0;
	//[a, b zwar deklariert, aber nicht initialisiert]
	int a = 0;
	int b = 0;
	int c = 0;

	while (c<500) {
		while (b < c) {
			while (a < b) {
				if (a*a + b*b == c*c) {
				//if ( a^2 + b^2 == c^2) {
				//[^ ist nicht potenz, sondern bitweise xor]
					if ((a+b+c) == 1000) {
					//if ((a+b+c) = 1000) {
					//[Vergleiche nicht mit = sondern mit ==]
						output(a,b,c);
						//std::output(a,b,c);
						//[output ist oben definiert, std::output gibts nicht]
					}
				}
				++a;
			}
			a = 0;
			b += 1;
		}
		a = 0;
		b = 0;
		//[b=0 hinzufügen, ansonsten wird b nicht zurückgesetzt und die innere
		//Schleife läuft nicht über den ganzen Bereich]
		c++;
		//c =+ 1;
		//[c soll inkrementiert werden, =+ macht wenig Sinn]
	}
}

/* Lösung b)
 *
 * Die Annahme ist, dass c nicht größer 500 sein kann.
 * Beweis:
 * Seien a < b < c natürliche Zahlen mit a^2 + b^2 = c^2 und a + b + c = 1000.
 * Angenommen c >= 500.
 * Dann gilt a + b = 1000 - c <= 500, also (a+b)^2 <= 500^2 <= c^2.
 * Da mit a < b mindestens eine von a und b größer 0, gilt weiter
 * a^2 + b^2 < a^2 + 2*a*b + b^2 = (a + b)^2 <= c^2, was im Widerspruch zu a^2 +
 * b^2 = c^2 steht.
 * Somit muss c < 500 sein.
 */

/* Lösung c)
 *
 * Jede der drei Schleifen kann einfach durch for(;<SCHLEIFENBED>;) ersetzt
 * werden, also:
 *
 * while (c<500) {
 *     while (b < c) {
 *         while (a < b) {

 * wird zu 
 *
 * for (;c<500;) {
 *     for (;b < c;) {
 *         for(;a < b;) {
 *
 * Schöner wäre allerdings folgender Code:
 */
	for (c = 0; c<500; c++ ) {
		for (b = 0; b < c; b++) {
			for (a = 0; a < b; a++) {
				if (a*a + b*b == c*c) {
					if ((a+b+c) == 1000) {
						output(a,b,c);
					}
				}
			}
		}
	}

/* Dieser ist auch in der Datei pythagorean_triple_for.cpp zu finden.
 * Dort wurden die Variablen-Deklarationen in die for-Schleifen verschoben, was
 * den Code nochmal Kürzer und klarer macht.
 */

/* Lösung d)
 *
 * Jede der drei Schleifen läuft maxmal bis n/2, hat also für sich eine Laufzeit
 * von O(n). Die beiden Vergleiche a^2 + b^2 = c^2 und a+b=c sowie der Aufruf
 * von output() haben je Laufzeit O(1).
 * Die drei Schleifen sind ineinander verschachtelt, also hat der gesamte Code
 * Laufzeit O(n^3).
