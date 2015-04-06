#include <emmintrin.h>

#include <iostream>

using namespace std;

int main() {
    __m128i a, b, c;
    a = _mm_set_epi16(10, 2, 7, 8, 3, 40000, 5, 4);
    b = _mm_set_epi16(17, 5, 2, 8, 12, 40000, 7, 9);
    c = _mm_add_epi16(a, b);
    cout << _mm_extract_epi16(c, 7) << ' '
         << _mm_extract_epi16(c, 6) << ' ' 
         << _mm_extract_epi16(c, 5) << ' ' 
         << _mm_extract_epi16(c, 4) << ' ' 
         << _mm_extract_epi16(c, 3) << ' ' 
         << _mm_extract_epi16(c, 2) << ' ' 
         << _mm_extract_epi16(c, 1) << ' ' 
         << _mm_extract_epi16(c, 0) << '\n';
    return 0;
}
