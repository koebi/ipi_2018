#include <fstream>
#include <iostream>

void add_linenumbers(std:: string filename){
	//Input- und Output-Filestream-Dateien können direkt im Konstruktor
	//angegeben werden
	std::ifstream inputstream(filename + ".txt");
	std::ofstream outputstream(filename + "-a.txt");

	int zeilennummer=1;
	while (inputstream.good()){
		//Variablen immer direkt da deklarieren, wo sie gebraucht werden
		std::string zeile;

		std::getline(inputstream, zeile);
		outputstream << zeilennummer << ": "<< zeile<< "\n";
		zeilennummer+=1;
	}

	inputstream.close();
	outputstream.close();
}

int main(int argc, char* argv[]){
	/* Wird der Dateiname als Kommandozeilenparameter übergeben,
	 * so steht er in argv.
	 * Wie wir an der signatur der main() erkennen, ist argv ein Array von
	 * (Pointer auf Char), also quasi ein Array von string.
	 * Daher können wir argv[1], also den ersten Parameter für unser Programm,
	 * direkt an unsere Funktion übergeben:
	 * add_linenumbers(argv[1]);
	 */

	/* Alternativ können wir den Dateinamen von der Konsole einlesen:
	 * std::string dateiname;
	 * std::cout << "Bitte gib einen Dateinamen ein: ";
	 * std::cin >> dateiname;
	 * add_linenumbers(dateiname);
	 */

	// Hardcoden ist aber auch nicht falsch ;)
	add_linenumbers("faust")
}
