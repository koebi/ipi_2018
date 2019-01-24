#include "myArray.h"

int TwoDBoolArray::rows() const{
	return n;
}

int TwoDBoolArray::cols() const{
	return m;
}

TwoDBoolArray::TwoDBoolArray(int _n, int _m) {
	this->m = _m;
	this->n = _n;
	daten = new bool[m*n];
}

TwoDBoolArray::~TwoDBoolArray() {
	// Wir können ganz einfach das Array mit delete[] löschen
	delete[] daten;
}

TwoDBoolArray& TwoDBoolArray::operator=(const TwoDBoolArray& other) {
	if (this != &other) {
		n = other.rows();
		m = other.cols();

		//J: bevor wir daten überschreiben, sollten wir alles löschen.
		delete[] daten;
		daten = new bool[m*n];

		for (int i = 0; i < n*m; i++) {
			daten[i] = other.daten[i];
		}
	}
	return *this;
}

TwoDBoolArray::TwoDBoolArray(const TwoDBoolArray& other) {
	n = other.rows();
	m = other.cols();
	daten = new bool[n*m];

	for (int i = 0; i < n*m; i++) {
		daten[i] = other.daten[i];
	}
}

TwoDBoolArray::RowProxy TwoDBoolArray::operator[]( int i) {
	return RowProxy(daten, i, m);
}

TwoDBoolArray::RowProxy::RowProxy(bool* data, int zeile, int spalten) {
	this->_daten = data;
	this->zeilenindex = zeile;
	this->spaltenzahl = spalten;
}

bool& TwoDBoolArray::RowProxy::operator[](int j) {
	return _daten[zeilenindex*spaltenzahl + j];
}

std::ostream& operator<<(std::ostream& stream, TwoDBoolArray& array) {
	for (int i = 0; i < array.rows(); i += 1) {
		for (int j = 0; j < array.cols(); j += 1) {
			stream << array[i][j] << " ";
		}
		stream << std::endl;
	}
	return stream;
}

std::istream& operator>>(std::istream& stream, TwoDBoolArray& array)
{
	//Wir müssen erst n und m einlesen, bevor wir unser Array anlegen können
	int n, m;
	stream >> n;
	stream >> m;

	//Wir können nicht direkt ins Array lesen, weil das potentiell die falsche
	//Größe hat.
	TwoDBoolArray tmp(n, m);
	for (int i = 0; i<n; ++i) {
		for (int j = 0; j<m; ++j) {
			stream >> tmp[i][j];
		}
	}
	array = tmp;
	return stream;
}

