#include <emmintrin.h>

constexpr int N = 1 << 25;
char arr[N];

int main() {
    __m128i x;
    for (int i = 0; i < N; ++i) {
        arr[i] = i & 255;
    }
    for (int j = 0; j < 100; ++j) {
        for (int i = 0; i < N; i += 16) {
            x = _mm_loadu_si128(reinterpret_cast<__m128i*>(arr + i));   // 0.5761 +- 0.0039
            x = _mm_load_si128(reinterpret_cast<__m128i*>(arr + i));    // 0.5749 +- 0.0043
            x = *(reinterpret_cast<__m128i*>(arr + i));                 // 0.5917 +- 0.0085
        }
    }
}
