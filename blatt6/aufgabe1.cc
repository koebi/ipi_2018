#include "fcpp.hh"

int iterationen = 0;
const double genauigkeit = 1.0e-12;

double myAbs(double x) {
	return cond(x < 0, -x, x);
}

bool kleinGenug(double left, double right) {
	return cond(myAbs(left - right) <= genauigkeit, true, false);
}

bool genauGenug(double value, double target) {
	return cond(myAbs(value*value - target) <= genauigkeit, true, false);
}

double wurzelIter(double left, double right, double target) {
	iterationen += 1;

	double middle = 0.5*(left+right);

	if (kleinGenug(left, right)) {
		return middle;
	} else if ((middle*middle - target) > 0) {
		return wurzelIter(left, middle, target);
	} else {
		return wurzelIter(middle, right, target);
	}
}

double wurzel(double a) {
	return wurzelIter(0.0, 4.0, a);
}

int main() {
	print(wurzel(2));
	print(iterationen);

	iterationen = 0;
	print(wurzel(3));
	print(iterationen);

	iterationen = 0;
	print(wurzel(4));
	print(iterationen);
}
