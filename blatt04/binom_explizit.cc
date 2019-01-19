#include "fcpp.hh"
#include <climits>

int fakIter(int produkt,int zaehler,int ende) {
	return cond(zaehler>ende,
 	            produkt,
  	            fakIter(produkt*zaehler,zaehler+1,ende));
}

int fakultaet(int n) {
	return fakIter(1,1,n);
}

int fakultaet_gekuerzt(int n, int k) {
	return fakIter(1, n-k+1, n);
}

int binomial_iter(int n, int k) {
	return cond(k > n,
			    -1,
				fakultaet(n)/(fakultaet(k)*fakultaet(n-k)));
}

int binomial_fast(int n,int k) {
	return cond(k>n,
			    -1,
                fakultaet_gekuerzt(n,k)/(fakultaet(k)));
}

int main(int argc, char* argv[]) {
	print(binomial_fast(readarg_int(argc, argv, 1), readarg_int(argc, argv, 2)));
	print(binomial_iter(readarg_int(argc, argv, 1), readarg_int(argc, argv, 2)));
	return 0;
}
