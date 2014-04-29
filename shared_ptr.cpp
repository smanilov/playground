#include <iostream>
using std::cout;
#include <vector>
using std::vector;
#include <memory>
using std::shared_ptr;
using std::make_shared;
#include <functional>
using std::function;
#include <initializer_list>
using std::initializer_list;


class Shape {
private:
        bool red;

        vector<shared_ptr<Shape>> sub_shapes;
public:
        Shape() : red(false) {}
        Shape(bool r) : red(r) {}
        Shape(initializer_list<Shape> l) {
                red = false;

                for (auto& s : l) {
                        sub_shapes.push_back(make_shared<Shape>(std::move(s)));
                }
        }

        vector<shared_ptr<Shape>> find_all(function<bool(const Shape&)> pred) {
                vector<shared_ptr<Shape>> result;
                if (pred(*this))  result.push_back(make_shared<Shape>(*this));
                for (auto& sub : sub_shapes) {
                        auto ss = sub->find_all(pred);
                        result.insert(result.end(), 
                                        make_move_iterator(ss.begin()),
                                        make_move_iterator(ss.end()));
                }
                return result;
        }

        bool isRed() const { return red; }
};

int main() {
        Shape s {Shape(false),
                Shape{Shape(true), Shape(true), Shape(false)},
                Shape(true)};
        cout << s.find_all([](const Shape& s) {return s.isRed();}).size() << '\n';
        return 0;
}
