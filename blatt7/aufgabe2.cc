#include "fcpp.hh"

void printBuffer(int buffer[], int out, int in, int size) {
	for (int i = 0; i < size; i += 1) {
        if(i == in && i == out) {
          print("<>",buffer[i],0);
        }

        if(i == in && i != out) {
          print(" >",buffer[i],0);
        }

        if(i != in && i == out) {
          print("< ",buffer[i],0);
        }

        if(i != in && i != out) {
          print("  ",buffer[i],0);
        }
      }
}

int main() {
	const int size = 10;
	int buffer[10] = {1,0,0,0,0,0,0,0,0,0};

	int out = 0;
	int in = 1;

	while(true) {
		int eingabe = enter_int("Gib eine Zahl ein: ");

		// Ein- und Ausgabe von Zahlen wird kompliziert, sobald In- und
		// Out-Pointer den gleichen Wert haben. Das passiert, sobald der Buffer
		// komplett leer oder komplett voll ist.
		//
		// Im Leer-Fall (überall 0) funktioniert die Eingabe wie üblich.
		// Für die Ausgabe sorgt Zeile 48 dafür, dass hier nichts ausgegeben
		// wird. 
		//
		// Im Voll-Fall (überall != 0) funktioniert die Ausgabe wie üblich.
		// Für die Eingabe muss dafür gesorgt werden, dass der Out-Pointer sich
		// mitbewegt - hierfür sind Zeilen 58-61 zuständig.
		if (eingabe < 0) {
			std::cout << "Abbruch" << std::endl;
			return 0;
		} else if (eingabe == 0) {
			if (buffer[out] == 0) {
				std::cout << "Buffer ist leer." << std::endl;
			} else {
				std::cout << "Aeltestes Element: " << buffer[out] << std::endl;
				buffer[out] = 0;
				out = (out+1)%size;
			}
			printBuffer(buffer, out, in, size);
		} else {
			if (in == out) {
				if (buffer[out] != 0) {
					std::cout << "Alte Werte werden überschrieben!!!" << std::endl;
					out = (out+1)%size;
				}
			}

			buffer[in] = eingabe;
			in = (in+1)%size ;

			printBuffer(buffer, out, in, size);
		}
	}

	printBuffer(buffer, out, in, size);

	return 0;
}
