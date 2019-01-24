#include <iostream>
#include <cmath>

class FehlerWert {
	public:
		// setzt Null
		FehlerWert();

		// setzt Wert mit absolutem Fehler
		FehlerWert(double zahl, double fehler);

		// Zugriff auf den Wert
		double wert();

		// Zugriff auf die Fehler
		double absolut();
		double relativ();

		// Rechenregeln
		FehlerWert operator+(FehlerWert f);
		FehlerWert operator*(FehlerWert f);

	private:
		double w;
		double fehler;
};

FehlerWert::FehlerWert() {
	w = 0.0;
	fehler = 0.0;
}

FehlerWert::FehlerWert(double zahl, double f) {
	w = zahl;
	fehler = f;
}

double FehlerWert::wert() {
	return w;
}

double FehlerWert::absolut() {
	return fehler;
}

double FehlerWert::relativ() {
	return absolut()/wert();
}

FehlerWert FehlerWert::operator+(FehlerWert z) {
	// neu ist nicht das Objekt der Klasse, auf das mit dieser Methode
	// zugegriffen wird. Daher lieber nicht auf private-member zugreifen,
	// sondern das im Konstruktor lösen, wie in operator*
	FehlerWert neu;
	neu.w = wert() + z.wert();
	neu.fehler = std::sqrt(absolut()*absolut() + z.absolut()*z.absolut());

	return neu;
}

FehlerWert FehlerWert::operator*(FehlerWert z) {
	double produkt = wert() * z.wert();
	double produktfehler = std::sqrt(relativ()*relativ() + z.relativ()*z.relativ());

	//der Fehler hier ist ein relativer Fehler
	return FehlerWert(produkt, produkt*produktfehler);
}

int main () {
	// Konstruktor nimmt zwei double-Werte: den Wert und den absoluten Fehler
	FehlerWert a(12.0, 3.0), b(6.0, 2.0);

	FehlerWert s = a + b;

	std::cout << s.wert() << " +- " << s.absolut() <<
		" (" << s.relativ() * 100 << " %)" << std::endl;

	FehlerWert p = a * b;

	std::cout << p.wert() << " +- " << p.absolut() <<
		" (" << p.relativ() * 100 << " %)" << std::endl;
}

