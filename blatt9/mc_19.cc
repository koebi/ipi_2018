#include <iostream>
int main() {
	const int i = 20, j = 15, *const ptr = &i;
	(*prt)++;
	ptr=&j;
	std::cout << i;
}

//Wir können obigen Code sinnigerweise folgendermaßen schreiben:
int main2() {
	const int i = 20;
	const int j = 15;
	//ptr ist ein konstanter Pointer auf konstanten Int
	const int *const ptr = &i;

	// Würde den (konstanten) Int, auf den ptr zeigt, verändern
	// (*ptr)++;

	// Würde den (konstanten) Pointer ptr verändern
	// ptr = &j;
	//
	std::cout << i;
}
