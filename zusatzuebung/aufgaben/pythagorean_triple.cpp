/*Pythagoreische Tripel sind drei natürliche Zahlen a < b < c sodass a^2 + b^2 =
 *c^2. Es gibt genau ein Tripel mit a + b + c = 1000. Der vorliegende Code soll
 *deren Produkt a*b*c ausgeben.
 *
 *a) Der Code enthält 9 syntaktische und semantische Fehler. Diese sind zu
 *   finden, zu erklären und zu beheben.
 *
 *b) Der Code tätigt in Zeile 37 eine implizite Annahme über das
 *   Problem. Beweisen sie diese.
 *
 *c) Der Code nutzt while-Schleifen. Schreiben sie den Code so um, dass er
 *   for-Schleifen verwendet.
 *
 *d) Es werden jetzt folgende Änderungen eingefügt:
 *   Zeile 36: int n = input();  (Input ist eine Funktion, die in einer
 *   beliebigen Art und Weise eine Zahl einliest)
 *   Zeile 37: 500 -> n/2 + 1
 *   Zeile 41: 1000 -> n
 *
 *   Bestimmen Sie die Laufzeit der main() Funktion abhängig von der Zahl, die
 *   von input() eingelesen wird.
 */

#include <iostream>
#include <output>

void output(int a, b, c) {
	std::cout << a  << ", " << b << ", " << c
	<< " sind pyth. Tripel mit Summe 1000 und Produkt "
	a*b*c << std::endl;
}


int main() {
	int a, b, c = 0;

	while (c<500) {
		while (b < c) {
			while ( a < b ) {
				if ( a^2 + b^2 == c^2) {
					if ((a+b+c) = 1000 ) {
						std::output(a,b,c);
					}
				}
				++a;
			}
			a = 0;
			b += 1;
		}
		a = 0;
		c =+ 1;
	}
}
