#include "fcpp.hh"

bool deck_check(int deck[], int n) {
	for (int i = 0; i < n; i += 1) {
		if (deck[i] != i) {
			// Sobald wir an einer Stelle nicht die richtige Karte finden, ist
			// das Deck nicht korrekt sortiert
			return false;
		}
	}
	return true;
}

int main() {
	// Ich nutze einen const int, um nicht aus versehen n zu überschreiben.
	const int n = 52;
	int deck[n];

	// Deck initialisieren
	for (int i = 0; i < n; i += 1) {
		deck[i] = i;
	}

	int shuffles = 0;

	// Dem ungeschmischten Zustand ganz am Anfang entspricht der 0. Shuffle,
	// diesen müssen wir explizit abfragen.
	while ((shuffles == 0) or (not deck_check(deck, n))) {
		// Temporäre Variable, um den aktuellen Mischzustand zu speichern.
		int shuffle[n];

		for (int i = 0; i < n/2; i += 1) {
			//Karten aus der ersten Deckhälfte gehen an gerade Positionen
			shuffle[2*i] = deck[i];

			// Karten aus der zweiten Deckhälfte gehen an ungerade Positionen
			shuffle[2*i + 1] = deck[i+n/2];
		}

		// Mischzustand wird wieder ins Deck übertragen
		for (int i = 0; i < n; i += 1) {
			deck[i] = shuffle[i];
		}

		shuffles += 1;
	}

	std::cout << "Ein In-Shuffle braucht " << shuffles << " Mischvorgänge." << std::endl;

	// Out-Shuffle
	shuffles = 0;

	while ((shuffles == 0) or (not deck_check(deck, n))) {
		int shuffle[n];
		for (int i = 0; i < n/2; i += 1) {
			// Karten aus der zweiten Deckhälfte gehen an gerade Positionen
			shuffle[2*i] = deck[i+n/2];

			// Karten aus der ersten Deckhälfte gehen an ungerade Positionen
			shuffle[2*i + 1] = deck[i];
		}
		for (int i = 0; i < n; i += 1) {
			deck[i] = shuffle[i];
		}

		shuffles += 1;
	}

	std::cout << "Ein Out-Shuffle braucht " << shuffles << " Mischvorgänge." << std::endl;

	return 0;
}
