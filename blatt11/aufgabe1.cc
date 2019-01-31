class A {
	public:
		int ap;
		void X();
	private:
		int aq;
		void aX();
};

class B : public A {
	public:
		int bp;
		void Y();
	private:
		int bq;
		void bY();
};

class C: public B {
	public:
		int cp;
		void Z();
	private:
		int cq;
		void cZ();
};

void B::Y() {
	bq = bp;
	//Geht nicht, weil aq private in A und daher aus B nicht zugänglich.
	//aq = ap;
	bY();
}

void C::cZ() {
	ap = 1;
	bp = 2;
	cq = 3;

	X();
	Y();
	//Geht nicht, weil aX private in A und daher aus C nicht zugänglich.
	//aX();
}

int main() {
	A a;
	B b;
	C c;

	a.X();
	//Geht nicht, weil bY private in B und daher "von außen" nicht zugänglich.
	b.bY();
	c.cp = 4;
	c.bp = 1;
	c.ap = 2;
	//Geht nicht, weil aq private in A und daher aus C nicht zugänglich.
	c.aq = 5;

	b.ap = c.ap;

	return 0;
}
