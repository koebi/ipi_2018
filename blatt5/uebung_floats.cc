#include <cmath>
#include "fcpp.hh"
#include <iostream>
#include <iomanip>
#include <bitset>

void print_bits(float f) {
	int *b = reinterpret_cast<int*>(&f); // use reinterpret_cast function
	int bit = 0;
	for (int k = 31; k >=0; k--) { // for loop to print out binary pattern
		bit = ((*b >> k)&1); // get the copied bit value shift right k times, then and with a 1.
		std::cout << bit; // print the bit.
	}
	std::cout << std::endl;
}

float det(float a, float b, float c, float d) {
	return a*d - b*c;
}

double ddet(double a, double b, double c, double d) {
	return a*d - b*c;
}

float leftadd(float a, float b, float c) {
	return (a+b) + c;
}

float rightadd(float a, float b, float c) {
	return a + (b + c);
}

float floatequal(float a, float b, float eps) {
	return abs(a - b) < eps;
}

int main() {
	float a = 100;
	float b = 0.01;
	print(det(a, b, -b, a));

	double da = 100;
	double db = 0.01;
	print(ddet(da, db, -db, da));
	print_precise(ddet(da, db, -db, da));
	
	double out = 100000+0.000001;
	print(out);

	for (int n = 0; n < 15; n++) {
		float aa = pow(10,n);
		float ab = -aa;
		float ac = 1/aa;

		
		print(floatequal(leftadd(aa, ab, ac),rightadd(aa, ab, ac), 2*ac ));
	}
	//float from1 = 0.1, to1 = std::nextafter(std::nextafter(0.1, 0), 0);
    //std::cout << "The next representable float before " << std::setprecision(30) << from1
         //     << " is " << to1 << "\n";

	print("Bits of 0.125:");
	print_bits(0.125);

	print("Bits of 0:");
	print_bits(0);

	print("Bits of 96:");
	print_bits(96);
}


