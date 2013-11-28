#include <stdio.h>

int main()
{
#define W 509
#define H 509
        printf("P6 %d %d 255 ", W, H);
        int i, j;
        for (i = 0; i < W; ++i) {
                for (j = 0; j < H; ++j) {
                        int red   = (i * H + j) % 256;
                        int green = (j * W + i) % 256;
                        int blue  = (j + i) * 2 % 256;
                        printf("%c%c%c", red, green, blue);
                }
        }
}
