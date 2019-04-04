#include <iostream>

struct listElem {
	int value;
	listElem* next;
};

struct List {
	int elements;
	listElem* first;
};

void emptyList(List* l) {
	l->first = 0;
	l->elements = 0;
}

void insertInList(List* l, listElem* where, listElem* ins) {
	if (where == nullptr) {
		//füge am Anfang ein
		ins->next = l->first;
		l->first = ins;
		l->elements += 1;
	} else {
		//füge nach where ein
		ins->next = where->next;
		where->next = ins;
		l->elements += 1;
	}
}

void printList(List *l) {
	for (listElem* p = l->first; p != nullptr; p = p->next) {
		std::cout << p->value << " -> ";
	}
	std::cout << "|" << std::endl;
}

listElem* removeFromList(List* l, listElem* where) {
	listElem* cache;

	if (where == nullptr) {
		//erstes Element löschen
		cache = l->first;
		if (cache != nullptr) { //ggf. keine Elemente
			l->first = cache->next;
			l->elements -= 1;
		}
		return cache;
	} else {
		cache = where->next;
		if (cache != nullptr) {
			where->next = cache->next;
			l->elements -= 1;
		}
		return cache;
	}
}

void reverseList(List* l) {
	if (l == nullptr) {
		std::cout << "No List, aborting." << std::endl;
		return;
	}

	listElem* current = l->first;
	listElem* whereToGo = nullptr;
	listElem* cache = nullptr;

	for (;;) {
		whereToGo = current->next;
		current->next = cache;
		cache = current;

		if (whereToGo == nullptr) {
			break;
		}

		current = whereToGo;
	}

	l->first = current;
}

int main() {
	List* l = new List;
	emptyList(l);

	listElem* rm = nullptr;

	for (int i = 0; i < 4; i++) {
		listElem* e = new listElem;
		e->value = i;
		e->next = nullptr;

		if (i == 2) {
			rm = e;
		}


		insertInList(l, nullptr, e);
	}
	delete removeFromList(l, rm);

	printList(l);
	reverseList(l);
	printList(l);
}
