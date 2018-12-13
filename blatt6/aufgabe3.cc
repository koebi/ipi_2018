#include "fcpp.hh"

void printArray(int array[10]) {
	for (int i = 0; i < 10; i++) {
		if (array[i] != 0) {
			std::cout << array[i] << " ";
		}
		if (array[i] == 0) {
			std::cout << "-" << " ";
		}
	}
	std::cout << "\n";
}


int main() {
	int array[10] = {0,0,0,0,0,0,0,0,0,0};

	// 0 wird nicht ins array eingelesen, Zahlen werden von vorne nach hinten
	// ins array geschrieben, sobald an der letzten Stelle eine Zahl steht ist
	// das array voll.
	while (array[9] == 0) {
		int number = enter_int("Gib eine Zahl ein: ");

		if (number == 0) {
			printArray(array);
			continue;
		}

		if (number == -1) {
			std::cout << "Abbruch" << std::endl;
			return 0;
		}

		if (number < -1) {
			std::cout << "Das ist keine gültige Eingabe, Abbruch!" << std::endl;
			return 0;
		}

		// target bezeichnet die Stelle des Arrays, an die die Zahl muss.
		int target = 0;
		for (int i = 0; i < 10; i++) {
			if (array[i] == 0) {
				continue;
			}
			if (array[i] < number) {
				target += 1;
			}
		}

		// ab target wird jede Zahl um eins nach hinten geschoben
		for (int i = target; i < 10; i++) {
			int tmp = array[i];
			array[i] = number;
			number = tmp;
		}
	}

	std::cout << "Genug Zahlen eingegeben :). Das ist dein Array: ";
	printArray(array);

	return 0;
}
