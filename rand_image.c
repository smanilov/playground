/*****************************************************************************
 * rand_image.c: records time differences which indicate the speed of the    *
 * CPU. The red bands in the image indicate the amount of time differences   *
 * recorded for the specified granularity (amount of micro seconds). The     *
 * green bands show an approximation of the amount of records per micro      *
 * second for the respective row.                                            *
 *****************************************************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

/* Get the microseconds from the start of the second. */
int usec() {
        struct timeval timevals;
        gettimeofday(&timevals, NULL);
        return (int)timevals.tv_usec;
}

int main()
{
        // width, height, and granularity
        int w = 500, h = 800, g = 1000;

        // read input
//        scanf("%d%d%d", &w, &h, &g);

        int i, j;
        int **times;

        // allocate memory
        times = (int**) malloc (sizeof(int*) * w);
        for (j = 0; j < w; ++j) {
                times[j] = (int*) malloc (sizeof(int) * h);
        }

        // record times
        int start = usec();

        for (i = 0; i < h; ++i) {
                for (j = 0; j < w; ++j) {
                        int next = (usec() - start) % g 
                                   / (1 + ((g - 1) / 256));
                        times[j][i] = next;
                }
        }

        // print image
        printf("P6 %d %d 255 ", w, h);
        for (i = 0; i < h; ++i) {
                int c = 0;
                for (j = 0; j < w; ++j) {
                        c += times[j][i] == times[0][i];
                        c += i > 0 && times[j][i - 1] == times[w - 1][i - 1];
                }
                for (j = 0; j < w; ++j) {
                        printf("%c%c%c", times[j][i], 255 * (j < c), 0);
                }
        }
}
