#include "fcpp.hh"
#include "myIntList.hh"

/*
 * Üblicherweise schreibt man eine Deklaration der Klasse in ein Header-File
 * (.hh). Damit umgeht man die Probleme, dass Implementationen der Klasse
 * potentielle private Variablen, die am Ende der Klassendeklaration angelegt
 * werden, nicht kennen.
 *
 * Die Klassenmethoden selber werden dann in einer eigenen Code-Datei (.cc)
 * angelegt.
 *
 * Das Header-File wird dann in dem Code, in dem die Klasse benötigt wird,
 * eingebunden.
 *
 * Das Ganze wird kompiliert mittels "g++ myIntList_test.cc myIntList.cc",
 * sprich dem Compiler werden sowohl der Code, der die Klasse nutzt als auch der
 * Code, der sie implementiert, übergeben.
 */
int main()
{
  print("Test 1: insert");
  IntList list;
  list.insert(30, 0);
  list.insert(20, 0);
  list.insert(10, 0);
  list.print();

  print("\nTest 2: remove");
  list.remove(2);
  list.print();

  print("\nTest 3: insert at");
  list.insert(30,2);
  list.print();

  print("\nTest 4: insert at");
  list.insert(40,3);
  list.print();

  print("\nTest 5: copy constructor");
  IntList copy(list);
  copy.print();

  print("\nTest 6: remove from copy");
  copy.remove(copy.getCount()-1);
  print("copy:");
  copy.print();
  print("original:");
  list.print();

  print("\nTest 7: = operator");
  copy = list;
  print("copy after equal:");
  copy.print();
}
