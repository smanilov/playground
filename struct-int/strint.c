#include <stdio.h>

typedef struct { unsigned char _[4]; } uint8x4_t;

void print_uint8x4_t(uint8x4_t xx) {
        printf("%d %d %d %d\n", xx._[3], xx._[2], xx._[1], xx._[0]);
}

int main() {
        int x;
        scanf("%d", &x);
        uint8x4_t* xxptr = (uint8x4_t*)((void*)&x);
        print_uint8x4_t(*xxptr);
}
