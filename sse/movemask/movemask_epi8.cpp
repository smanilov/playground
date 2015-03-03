#include <iostream>
#include <iomanip>
#include <bitset>

#include <functional>
#include <random>

#include <emmintrin.h>

using std::bitset;
using std::cout;
using std::endl;

using std::uniform_int_distribution;
using std::default_random_engine;
using std::random_device;
using std::bind;

void f();

int main() {
    auto hey = bind(uniform_int_distribution<>{0x00,0xff},
                    default_random_engine{random_device{}()});
    char a[] = {hey(), hey(), hey(), hey(), hey(), hey(), hey(), hey(),
                hey(), hey(), hey(), hey(), hey(), hey(), hey(), hey()};
    int n = 16;
    __m128i x = _mm_loadu_si128(reinterpret_cast<__m128i*>(a));
    uint16_t max_ = _mm_movemask_epi8(x);

    cout << "\n*** uint16_t _mm_movemask_epi8(__m128i a) ***\n";
    cout << "The most significant bit of every byte in *a* is taken to form the "
            "result:\n";
    for (int i = n - 1; i >= 0; --i) {
        // set offset to match first bits with result of mask
        cout << std::setw((n - i - 1) + 8);
        // cast each a[i] to a bitset, so it is output in binary:
        cout << static_cast<bitset<8>>(a[i]) << endl;
    }
    cout << static_cast<bitset<16>>(max_) << endl;

    f();
}

void f() {
    cout << "\n";
    cout << "Reverse popcount table:\n";

    unsigned char tab[256];
    for( int j = 0; j < 256; j++ )
    {
        int val = 0;
        for( int mask = 1; mask < 256; mask += mask )
            val += (j & mask) == 0;
        tab[j] = (unsigned char)val;
    }

    for (int i = 0; i < 256; i += 16) {
        for (int j = 0; j < 16; ++j) {
            cout << static_cast<int>(tab[i + j]) << ' ';
        }
        cout << '\n';
    }
}
