#include <iostream>

using std::cout;

#include <memory>
#include <vector>

using std::unique_ptr;
using std::vector;

class A {
protected:
        vector<unique_ptr<int>> hellos;
public:
        virtual void sayHello(unique_ptr<int> say) = 0;

        inline void f() { cout << "hey!\n"; }
};

class B : public A {
public:
        void sayHello(unique_ptr<int> say) override {
                hellos.push_back(unique_ptr<int>{ say.release() });
        }
};

int main() {
        A* a;
        a = new B;
        int* hello = new int(2);
        // B b = dynamic_cast<B&>(*a);  // does not compile, because cannot copy
        B& b = dynamic_cast<B&>(*a);  // works
        a->sayHello(unique_ptr<int>(hello));

        cout << *hello << "\n";
}
