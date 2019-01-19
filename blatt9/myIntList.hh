#pragma once

class IntList {
	public:
		// Konstruktor, erzeugt eine leere Liste
		IntList();

		// Copy-Konstruktor
		IntList(const IntList& other);

		// Zuweisungs-Operator
		IntList& operator=(const IntList& other);

		// Destruktor, loescht gesamten Listeninhalt
		~IntList();

		// Gibt Anzahl der Elemente zurueck
		int getCount();

		// Gibt zurueck, ob die Liste leer ist
		bool isEmpty();

		// Gibt die Liste aus
		void print();

		// Fuegt die Zahl 'element' an der Position 'position' ein
		void insert(int element, int position);

		// Loescht das Element an der Position 'position'
		void remove(int position);

		// Gibt den Wert des Elements an der Position 'position' zurueck
		int getElement(int position);

	private:
		struct IntListElem {
			IntListElem *next;
			int value;
		};

		int count;

		IntListElem *list;
};
