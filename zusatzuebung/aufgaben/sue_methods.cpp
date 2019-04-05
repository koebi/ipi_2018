/*
 *  Die folgende Klasse implementiert Restklassenvertreter, sprich die Elemente eines Restklassenrings.
 *  (Restklassenringe sind jene Mengen aus LA, die mit Z/nZ bzw F_n bezeichnet werden.)
 *  Jedes Objekt speichert seinen Vertreter als uint num und die Kardinalität des Rings als Templateparameter N.
 *  Es soll also gewährleistet werden, dass für ein fixes N num zwischen 0 und N-1 liegt. (num = i % N)
 *  Die Klasse soll derart ergänzt werden, dass für die main-Funktion unten die hier angegeben Ausgabe entsteht.
 *  Achtet vorallem auf const-correctness und darauf, dass der %-Operator in C++ für neg. Zahlen nicht wie erwartet funktioniert.
 *  Für einige, jedoch nicht alle Methoden existieren Skelette. Außerdem muss ein Operator mehrmals überladen werden.
 *  OUTPUT:
 *    a := 3
 *    b := 4
 *    c := 1
 *
 *    a := 3
 *    b := 5
 *    c := 0
 * 
 *    (a * b) und (a + b) sind gleich.
 *    Weitere Vertreter von 3 sind {-25, -18, -11, -4, 3, 10, 17, 24, 31, 38}
 *    Weitere pos. Vertreter von 5 sind {5, 12, 19, 26, 33, 40, 47}
 *
 */

#include <iostream>
#include <vector>

template<int N>
class RestKlassenVertreter{
    typedef RestKlassenVertreter<N> RKV;
    private:
        uint num;
    public:

        /* Fehlt hier was? */

        void set(int num) {/* Code Here */}
        
        uint get() {/* Code Here */}

        RKV add(const RKV& rhs) {
            /* Code Here */
        }

        RKV mul(const RKV& rhs) {
            /* Code Here */
        }

        std::vector<int> reps(uint pos) {
            /* Code Here */
        }

        std::vector<int> reps(uint neg, uint pos) {
            /* Code Here */
        }

        /* Return Type */ operator+(/* Parameter */) {
            return this->add(rhs);
        }


};

int main(){
    const RestKlassenVertreter<7> a(17);
    RestKlassenVertreter<7> b(-3);
    RestKlassenVertreter<4> c(1);

    std::cout << "a := " << a << std::endl;
    std::cout << "b := " << b << std::endl;
    std::cout << "c := " << c << std::endl;
    std::cout << std::endl;

    b.set(12);
    c.set(-16);

    std::cout << "a := " << a << std::endl;
    std::cout << "b := " << b << std::endl;
    std::cout << "c := " << c << std::endl;
    std::cout << std::endl;

    std::cout << "(a * b) und (a + b) sind " << ( (a+b)==(a*b) ? "" : "nicht " )
              << "gleich." << std::endl;

    std::cout << "Weitere Vertreter von " << a.get()
              << " sind " << a.reps(4,5) << std::endl;
    std::cout << "Weitere pos. Vertreter von " << b.get()
              << " sind " << b.reps(6) << std::endl;
}