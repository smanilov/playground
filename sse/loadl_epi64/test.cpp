#include <emmintrin.h>

constexpr int N = 1 << 25;
char arr[N];

int main() {
    __m128i x;
    for (int i = 0; i < N; ++i) {
        arr[i] = i & 255;
    }
    for (int i = 1; i < N; i += 16) {
        x = _mm_loadl_epi64(reinterpret_cast<__m128i*>(arr + i));
    }
}
