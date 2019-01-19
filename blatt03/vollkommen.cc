#include "fcpp.hh"

int summeTeiler(int zahl, int summe, int teiler) {
	return cond(teiler < zahl,
	         	cond(zahl % teiler == 0,
	             	 summeTeiler(zahl, summe + teiler, teiler+1),
	             	 summeTeiler(zahl, summe, teiler+1)),
         		summe);
}


bool vollkommen(int zahl) {
	return cond(zahl == summeTeiler(zahl, 0, 1), true, false);
}

int main() {
	print(true);
	print(vollkommen(28));
	return 0;
}
