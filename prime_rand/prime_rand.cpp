#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using std::vector;
using std::cout;

vector<int> primes;
vector<int> random_vec;

// assume wouldn't be asked for too big numbers
bool isPrime(int x) {
        int sq = static_cast<int>(floor(sqrt(x)));
        for (int p : primes) {
                if (x % p == 0) {
                        return false;
                }
                if (p >= sq) {
                        return true;
                }
        }
        // not enough info! return true for corner cases
        return true;
}

// generate randomness for N and append it to random_vec
void appendRandomVec(int x) {
        int sq = static_cast<int>(floor(sqrt(x)));
}

// fill the primes vector with primes up to N
int genPrimes(int N) {
        primes.clear();
        for (int i = 2; i < N; ++i) {
                if (isPrime(i)) {
                        primes.push_back(i);
                }
        }
}

int main() {
        genPrimes(64);

        int i = 0;
        for (int p : primes) {
                cout << "\t" << p;
        }
        cout << '\n';
        for (int p : primes) {
                cout << p;
                for (int q : primes) {
                        cout << "\t";
                        if (q <= p) continue;
                        ++i;
                        cout << std::setprecision(3) << double(q % p) / p;
                        if (i == 20) {
                    //            cout << '\n';
                                i = 0;
                        }
                }
                cout << '\n';
        }
        cout << '\n';

        return 0;
}
