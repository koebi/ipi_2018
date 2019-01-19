#include <iostream>

int main()
	int feld[2] = {0,1}

	// Dieser Code kompiliert zwar, aber Zugriffe auf feld[-1], feld[2] und
	// feld[3] geben andere Zahlen zurück.
	//
	// Hier wird *(feld-1), *(feld+2) und *(feld+3) ausgeführt, was anscheinend
	// alles Pointer auf validen Speicher sind, aber nicht von uns aktiv
	// kontrolliert werden.
	std::cout << feld[-1] << std::endl;
	std::cout << feld[0] << std::endl;
	std::cout << feld[1] << std::endl;
	std::cout << feld[2] << std::endl;
	std::cout << feld[3] << std::endl;
	return 0;
}
