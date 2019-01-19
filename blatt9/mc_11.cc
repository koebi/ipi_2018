#include <iostream>

int main() {
	std::cout << "Gib mir ein N!" << std::endl;

	int n = 0;
	std::cin >> n;

	std::cout << "Diese (natürlichen) Zahlen sind kleiner:" << std::endl;

	// For -> While:
	// Initialisierung (alles vor erstem ";") vor Schleife, Inkrement (alles
	// nach zweitem ";") ganz ans Schleifenende.
	// Schleife in eigenen Scope, "for" -> "while"
	//
	// While -> For:
	// vor, nach Schleifenbedingung je ein ";" (Initialisierung und Inkrement
	// können leer bleiben), "while" -> "for"

	{
	int i = 0;
	for (; i < n;) {
		std::cout << i << std::endl;
		i += 1;
	}
	}

	return 0;
}
