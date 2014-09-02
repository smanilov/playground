#include <stdio.h>
#include <stdint.h>

#define N (1 << 16)
#define SEED 1

#define EXTRACT_BYTE0(x) (x & 0x000000ff)
#define EXTRACT_BYTE1(x) ((x & 0x0000ff00) >> 8)
#define EXTRACT_BYTE2(x) ((x & 0x00ff0000) >> 16)
#define EXTRACT_BYTE3(x) ((x & 0xff000000) >> 24)

#define REPS ((int)(1e5))

void init(uint8_t *const array);
void f(uint8_t const *const array);
void g(uint8_t const *const array);

int main() {
        uint8_t array[N];

        init(array);

        f(array);

        g(array);

        return 0;
}

void init(uint8_t *const array) {
        int i;
        srand(SEED);
        for (i = 0; i < N; ++i) {
                array[i] = (uint8_t)(rand() % 256);
        }
}

void f(uint8_t const *const array) {
        int i, iter;
        uint32_t acc;
        for (iter = 0; iter < REPS; ++iter) {
                acc = 0;
                for (i = 0 ; i < N; ++i) {
                        acc += array[i];
                }
        }
        printf("[f] acc=%d\n", acc);
}

void g(uint8_t const *const array) {
        int i, iter;
        uint32_t acc;
        uint32_t tmp;
        for (iter = 0; iter < REPS; ++iter) {
                acc = 0;
                for (i = 0 ; i < N; i += 4) {
                        tmp = *((uint32_t*)&array[i]);
                        acc += EXTRACT_BYTE0(tmp);
                        acc += EXTRACT_BYTE1(tmp);
                        acc += EXTRACT_BYTE2(tmp);
                        acc += EXTRACT_BYTE3(tmp);
                }
        }
        printf("[g] acc=%d\n", acc);
}
