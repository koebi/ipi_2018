#include "fcpp.hh"

int check(int x, int y, int n) {
	return cond(x*x + y*y <= n*n, 1, 0);
}

int walkX(int start, int y, int n) {
	return cond(start <= n,
				check(start,y,n) + walkX(start+1,y,n),
				0);
}

int walkY(int y, int n) {
	return cond(y <= n,
			    walkX(-n, y, n) + walkY(y+1, n),
				0);
}

int imkreis(int n) {
	return walkY(-n, n);
}

int main() {
	print(imkreis(15));
}
