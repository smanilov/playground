#include <iostream>
#include <vector>
#include <random>

using std::cout;
using std::vector;

using std::default_random_engine;
using std::uniform_real_distribution;

typedef unsigned int uint;

template <typename T>
vector<T> gen(int n) {
    vector<T> res(n);
    default_random_engine g;
    uniform_real_distribution<T> d(0.0f,1.0f);

    for (int i = 0; i < n; ++i) {
        res[i] = d(g);
    }
    return res;
}

template <typename T>
T test(const vector<T>& fs, const uint REPEAT) {
    T res;
    for (int i = 0; i < REPEAT; ++i) {
        for (auto f : fs) {
            res += f; 
        }
    }
    return res;
}

int main() {
    const uint REPEAT = 1 << 17;

    auto fs = gen<float>(1024);
    auto f = test<float>(fs, REPEAT);
    cout << f << '\n';
    cout << sizeof(float) << '\n';

    /*
    auto ds = gen<double>(1024);
    auto d = test<double>(ds, REPEAT);
    cout << d << '\n';
    cout << sizeof(double) << '\n';
    */

    /*
    auto ds = gen<long double>(1024);
    auto d = test<long double>(ds, REPEAT);
    cout << d << '\n';
    cout << sizeof(long double) << '\n';
    */


    return 0;
}
