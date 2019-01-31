#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

template<class T, int N>
class Vektor {
	private:
		std::vector<T> v;
		int size = N;

	public:
		Vektor() {
			//Wir wollen dass unser Vektor die passende Größe hat und mit
			//Null-Elmenten gefüllt ist.
			for(int i = 0; i < size; i++){
				//(T)0 erzeugt eine "Null" vom Typ T - je nach Typ kann das z.B.
				//nullptr, eine 0 oder anderes sein.
				this->v.push_back((T)0);
			}
			//Das sorgt dafür, dass aller zuviel allokierte Speicher wieder
			//freigegeben wird und v genau so groß ist wie es muss.
			this->v.shrink_to_fit();
		};

		//Maximumsfunktion
		T max() {
			//Zugriff über STL-Algorithmus
			return *(std::max_element(this->v.begin(),this->v.end()));
		};

		//Zugriffsoperator, um Vektor wie einen std::vector verwenden zu können
		T& operator[](unsigned int i) {
			//Zugriff über []
			return v[i];
		};

		//Skalarmultiplikation
		//Ja: vneu = valt*7;
		//Nein: valt*7 (und damit v verändert)
		template<class U>
		Vektor<T, N> operator*(U multiplikator){
			Vektor<T, N> ergebnis;
			int i = 0;
			for(auto x : v){
				ergebnis[i] = (x * multiplikator);
				i += 1;
			}
			return ergebnis;
		}

		//Vektoraddition
		//wie oben :)
		Vektor<T, N> operator+( Vektor<T, N>& summand) {
			Vektor<T, N> ergebnis;
			for(int i = 0; i < N; i++){
				ergebnis[i] = (summand[i] + this->v[i]);
			}
			return ergebnis;
		};

};

//Skalarmultiplikation von links
template<class T, int N, class U>
Vektor<T, N> operator*(U multiplikator, Vektor<T, N>& multiplikand){
	return multiplikand*multiplikator;
}

//Schnellerer Output über stream-operator
template<class T, int N>
std::ostream& operator<<(std::ostream& stream, Vektor<T, N> vec){
	stream << "(";
	for(int i = 0; i < N; i++){
		stream << vec[i] << ((i==N-1)?")":",");
	}
	return stream;
}

int main(){
	Vektor<double, 3> v1;
	v1[0] = 4;
	v1[1] = 16;
	v1[2] = 9;
	std::cout << "v1:\t" << v1 << std::endl;
	std::cout << "Max:\t " << v1.max() << std::endl;
	std::cout << "3*v1:\t " << (3*v1) << std::endl;

	Vektor<double, 3> v2;
	v2[0] = 1;
	v2[1] = 2;
	v2[2] = 3;
	std::cout << "v2:\t" << v2 << std::endl;
	std::cout << "Sum:\t " << (v1+v2) << std::endl;
	std::cout << "v2*7:\t " << (v2*7) << std::endl;
}
