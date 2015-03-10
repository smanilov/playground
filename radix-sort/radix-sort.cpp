#include <iostream>
using std::cout;
#include <random>
using std::default_random_engine;
using std::uniform_real_distribution;
#include <limits>
using std::numeric_limits;

int main() {
    default_random_engine gen;
    uniform_real_distribution<double> dist(numeric_limits<double>::min(),
                                           numeric_limits<double>::max());
    double d = dist(gen);
    cout << d << '\n';
    return 0;
}
