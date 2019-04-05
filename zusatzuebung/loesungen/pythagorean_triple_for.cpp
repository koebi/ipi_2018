
#include <iostream>

void output(int a, int b, int c) {
	std::cout << a  << ", " << b << ", " << c 
	<< " sind pyth. Tripel mit Summe 1000 und Produkt " 
	<< a*b*c << std::endl;
}


int main() {
	for (int c = 0; c<500; c++ ) {
		for (int b = 0; b < c; b++) {
			for (int a = 0; a < b; a++) {
				if (a*a + b*b == c*c) {
					if ((a+b+c) == 1000) {
						output(a,b,c);
					}
				}
			}
		}
	}
}
