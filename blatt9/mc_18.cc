#include <iostream>

int main() {
	//Sinnvoller Output von True/False
	std::cout << std::boolalpha;
	
	// int sum = 10, **acc = new int*[10]; lieber in zwei Zeilen schreibe
	int sum = 10;
	int **acc = new int*[10]; //Pointer auf Array von Pointern von Int
	//*(acc+2) = &(*(&sum)); vereinfacht zu
	acc[2] = &sum;

	//std::cout << (&(*(acc[2])) == &sum) << std::endl; vereinfacht zu
	std::cout << acc[2] == &sum << std::endl;

	//std::cout << (*(*(acc+2)) == *(&sum) ) << std::endl; vereinfacht zu
	std::cout << *(acc[2]) == *(&sum) ) << std::endl;

	// folgender Aufruf greift auf den Pointer an index 0 in acc zu - der nicht
	// gesetzt ist. 
	std::cout << ( acc[0][2] == sum ) << std::endl;
};
