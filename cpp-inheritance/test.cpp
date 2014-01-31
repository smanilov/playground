#include <iostream>

class A {
public:
        void f();
        void g();
};

class B : public A {
public:
        void f();
};



class C {
public:
        virtual void f();
        void g();
};

class D : public C {
public:
        void f();
};



void A::f() {
        std::cout << "A\n";
}

void A::g() {
        f();
}

void B::f() {
        std::cout << "B\n";
}


void C::f() {
        std::cout << "C\n";
}

void C::g() {
        f();
}

void D::f() {
        std::cout << "D\n";
}

int main() {
        B b;
        A &a = b;

        a.g();  // A

        D d;
        C &c = d;

        c.g();  // D
        return 0;
}
