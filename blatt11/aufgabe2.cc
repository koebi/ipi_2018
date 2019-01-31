#include <iostream>

class A {
	public:
		void a(){
			std::cout << "Calling a() from A" << std::endl;
		}
		virtual void va() = 0;
		virtual void a(int n){
			std::cout << "Calling a(int) from A" << std::endl;
		}
	private:
		void c() {
			std::cout << "Calling c() from A" << std::endl;
		}
};

class B : public A {
	public:
		void b(){
			std::cout << "Calling b() from B" << std::endl;
		}
		virtual void vb(){
			std::cout << "Calling vb() from B" << std::endl;
		}
		void a(double d){
			std::cout << "Calling a(double) from B" << std::endl;
		}
		void a(int i){
			std::cout << "Calling a(int) from B" << std::endl;
		}
		virtual void va(){
			std::cout << "Calling va() from B" << std::endl;
		}
};

class C : public B {
	public:
		virtual void c(){
			std::cout << "Calling c() from C" << std::endl;
		}
		void a(float){
			std::cout << "Calling a(float) from C" << std::endl;
		}
		virtual void a(){
			std::cout << "Calling a() from C" << std::endl;
		}
		virtual void va(){
			std::cout << "Calling va() from C" << std::endl;
		}
};


int main() {
	//A a; //A enthaelt pure virtual fcn => abstrakte Klasse => keine Objects
	B b;
	C c;
	A *pa=&b;
	B *pb=&c;
	float x = 1.2;
	int i = 1;

	pa->a(); // a() from A
	pa->va(); // va() from B
	pa->a(1); // a(int) from B
	//pa->c(); //c() ist private in A.
	//pa->b(); //b() gibt es in A nicht.
	//pa->vb(); //vb() gibt es in A nicht.
	pa->a(x); // typecast in A, a(int) from B

	std::cout << std::endl;

	//pb->a(); //a(double/int) shadowt a() aus A, nach dem name lookup wird nicth weiter gesucht.
	pb->va(); //va() from C
	pb->a(1); //a(int) from B
	//pb->c(); //c() gibt es in B nicht, in A private
	pb->b(); //b() from B
	pb->vb(); //vb() from B
	pb->a(x); //a(double) from B

	std::cout << std::endl;
	pa = &c;

	pa->a(); //a() from A
	pa->va(); //va() from C
	pa->a(1); // in B nicht mehr virtual
	//pa->c(); //c() private in A
	//pa->b(); //b() gibt es in A nicht
	//pa->vb(); //vb() gibt es in A nicht
	pa->a(x); // typecast in A, zuerst in "Basisklasse" gucken, a(int) from B
}
