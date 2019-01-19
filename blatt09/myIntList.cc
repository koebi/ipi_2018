#include <iostream>
#include "myIntList.hh"

IntList::IntList() {
	list = 0;
	count = 0;
}

//Destruktor
IntList::~IntList() {
	IntListElem *cur = list;

	// Liste einmal durchgehen, jedes Element löschen.
	// Dabei wird der next-Pointer des Elements noch benötigt, er muss also
	// zwsichengespeichert werden.
	while(cur) {
		IntListElem *next = cur->next;
		delete cur;
		cur = next;
	}
}

// Copy-Konstruktor
IntList::IntList(const IntList& other) {
	if (other.count > 0) {

		//Wir müssen alle Elemente kopieren, legen also eine neue Liste an.
		IntListElem *newList = new IntListElem;
		newList->value = other.list->value;
		newList->next = 0;

		//Wir müssen den Pointer auf das Erste Element speichern
		list = newList;
		count = other.count;

		for (IntListElem *old = other.list->next; old; old = old->next) {
			IntListElem *elem = new IntListElem;
			elem->value = old->value;
			elem->next = 0;

			//Da wir in unserer Liste das neue Element immer anhängen, müssen
			//wir das erste element oben explizit anglegen.
			newList->next = elem;
			newList = elem;
		}
	} else {
		list = 0;
		count = 0;
	}
}

// Zuweisungs-Operator
IntList& IntList::operator=(const IntList& other) {
	if (this != &other) {
		//Destruktor
		IntListElem *cur = list;

		while(cur) {
			IntListElem *next = cur->next;
			delete cur;
			cur = next;
		}

		//Deep Copy
		if (other.count > 0) {

			IntListElem *newList = new IntListElem;
			newList->value = other.list->value;
			newList->next = 0;

			list = newList;
			count = other.count;

			for (IntListElem *old = other.list->next; old; old = old->next) {
				IntListElem *elem = new IntListElem;
				elem->value = old->value;
				elem->next = 0;


				newList->next = elem;
				newList = elem;
			}
		} else {
			list = 0;
			count = 0;
		}
	}

	return *this;
}

int IntList::getCount() {
	return count;
}

bool IntList::isEmpty() {
	return (count == 0);
}

void IntList::print() {
	IntListElem *current = list;
	while(current) {
		std::cout << current->value << " ";
		current = current->next;
	}
	std::cout << std::endl;
	return;
}

int IntList::getElement(int position) {
	if (count < position && count > 0) {
		std::cout << "Gibbet nisch!" << std::endl;
		return -1;
	}
	IntListElem *cur = list;
	for (int i = 0; i < position; i += 1) {
		cur = cur->next;
	}
	return cur->value;
}


void IntList::insert(int element, int position) {
	if(position > 0 && position > count) {
		std::cout << "Position" << position << "gibbetnich." << std::endl;
		return;
	}

	//neues Element anlegen
	IntListElem *ins = new IntListElem;
	ins->value = element;

	//am Anfang einfügen
	if(position == 0) {
		ins->next = list;
		list = ins;
		count += 1;
	} else {
		// where bezeichnet den Punkt nach dem wir einfügen, damit wir den
		// Einfügungs-Code aus der Vorgabe nutzen können.
		// Diesen Punkt suchen wir hier
		IntListElem *where = list;

		for (int i = 0; i < (position-1); i += 1) {
			where = where->next;
		}

		//nach where einfügen
		ins->next = where->next;
		where->next = ins;
		count += 1;
	}
	return;
}

void IntList::remove(int position) {
	if (position >= count && count > 0) {
		std::cout << "Hammanich" << std::endl;
		return;
	}

	//Wir müssen das zu löschende Element speichern, damit wir es deleten
	//können
	IntListElem* p;

	if (position == 0) {
		p = list;
		//p->next könnte segfaulten, falls p == 0 
		if (p!=0) {
			list = p->next;
			count -= 1;
		}
		delete p;
		return;
	} else {
		IntListElem *where = list;

		for (int i = 0; i < (position-1); i += 1) {
			where = where->next;
		}

		p = where->next;
		if (p != 0) {
			where->next = p->next;
			count -= 1;
		}
		delete p;
		return;
	};
}
