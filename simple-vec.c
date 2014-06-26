#include <stdio.h>

#define MAX_PROF_ITER ((int)1e7)
#include "Cycles-linux.h"

#define PV(x) (*(unsigned int *)(&x))
#define PV2(x) (*(unsigned long *)(&x))
#define PV3(x) (*(unsigned long long *)(&x))

#include <emmintrin.h>

#define LV(x) (_mm_load_si128 ((__m128i*)(&x)))
#define SV(x, y) (_mm_store_si128 ((__m128i*)(&x), y))

int main() {
        unsigned char A[128], B[128], C[128];
        int i, idx;

        for (i = 0; i < 128; ++i) {
                A[i] = i % 48;
                B[i] = 48 - A[i];
        }

        Cycles Start, Stop;
        START_PROFILING(Start);
        for (i = 0; i < 128; ++i) {
                C[i] = A[i] + B[i];
        }
        END_PROFILING(Stop);
        { PRINT_DIFFERENCE(Start, Stop); }

        for (i = 0; i < 128; ++i) {
                printf("%c", C[i]);
        }
        printf("\n");

        START_PROFILING(Start);
        for (i = 0; i < 128; i += 4) {
                PV(C[i]) = PV(A[i]) + PV(B[i]);
        }
        END_PROFILING(Stop);
        { PRINT_DIFFERENCE(Start, Stop); }

        for (i = 0; i < 128; ++i) {
                printf("%c", C[i]);
        }
        printf("\n");

        START_PROFILING(Start);
        for (i = 0; i < 128; i += 8) {
                PV2(C[i]) = PV2(A[i]) + PV2(B[i]);
        }
        END_PROFILING(Stop);
        { PRINT_DIFFERENCE(Start, Stop); }

        for (i = 0; i < 128; ++i) {
                printf("%c", C[i]);
        }
        printf("\n");

        START_PROFILING(Start);
        for (i = 0; i < 128; i += 16) {
                PV3(C[i]) = PV3(A[i]) + PV3(B[i]);
        }
        END_PROFILING(Stop);
        { PRINT_DIFFERENCE(Start, Stop); }

        for (i = 0; i < 128; ++i) {
                printf("%c", C[i]);
        }
        printf("\n");

        START_PROFILING(Start);
        for (i = 0; i < 128; i += 16) {
                SV(C[i], _mm_add_epi8(LV(A[i]), LV(B[i])));
        }
        END_PROFILING(Stop);
        { PRINT_DIFFERENCE(Start, Stop); }

        for (i = 0; i < 128; ++i) {
                printf("%c", C[i]);
        }
        printf("\n");

        return 0;
}
