#include <iostream>
#include <vector>

template<int N>
class RestKlassenVertreter{
    typedef RestKlassenVertreter<N> RKV;
    private:
        uint num;
    public:
        RestKlassenVertreter(int num){
            num = num % N;
            if(num < 0){
                num += N;
            }
            this->num = num;
        }
        
        void set(int num) {
            num = num % N;
            if(num < 0){
                num += N;
            }
            this->num = num;
        }
        
        uint get() const {
            return this->num;
        }

        RKV add(const RKV& rhs) const {
            return RKV(this->num + rhs.num);
        }

        RKV mul(const RKV& rhs) const {
            return RKV(this->num * rhs.num);
        }

        std::vector<int> reps(uint pos) const {
            std::vector<int> res;
            for(uint i = 0; i <= pos; ++i){
                res.push_back(this->num + i*N);
            }
            return res;
        }

        std::vector<int> reps(uint neg, uint pos) const {
            std::vector<int> res;
            for(int i = -((int)neg); i <= (int)pos; ++i){
                res.push_back(this->num + i*N);
            }
            return res;
        }

        RKV operator+(const RKV& rhs) const {
            return this->add(rhs);
        }

        RKV operator*(const RKV& rhs) const {
            return this->mul(rhs);
        }

        bool operator==(const RKV& rhs) const {
            return this->num == rhs.num;
        }

};

template<int N>
std::ostream& operator<<(std::ostream& os, const RestKlassenVertreter<N>& rhs){
    os << rhs.get();
    return os;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& rhs){
    os << "{";
    if(rhs.size() > 0){
        auto it = rhs.begin();
        for(;;){
            os << *it;
            if(++it != rhs.end()){
                os << ", ";
            } else {
                break;
            }
        }
    }
    os << "}";
    return os;
}

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