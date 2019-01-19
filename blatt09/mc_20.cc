#include <typeinfo>
#include<iostream>

int main() {
	int** a, *b;
	int c = 4, *d = &(c);
	a = &d;
	b = *a;
	std::cout << *b << std::endl;
}

//Wir können das sinnigerweise schreiben als:
int main2() {
	int c = 4;

	//Pointer auf int
	int *d = &c;

	//Pointer auf (Pointer auf int)
	int **a = &d;

	//Pointer auf int
	int *b;

	//Wert von B wird auf Wert des Objekts auf das a zeigt gesetzt.
	b = *a
	//a zeigt auf d, d hat Wert "&c"
	//=> äquivalent zu b = &c;

	std::cout << b << std::endl;
	// zur Verdeutlichung:
	std::cout << &c << std::endl;
