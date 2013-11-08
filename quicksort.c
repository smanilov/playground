#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MIN_N 1
#define MAX_N 1000000
#define A_REASONABLE_NUMBER 1024

void printUsage(char **argv) {
        printf("An exercise of implementing quicksort.");
        printf("Usage:\n%s n\n    where n is the size of the test array.\n",
                argv[0]);
}

/**
 * Checks if the arguments to the program are valid and exits if not.
 */
void validateArgs(int argc, char **argv) {
        char good = 1;
        if (argc != 2) {
                good = 0;
        }
        if (!good) {
                printUsage(argv);
                exit(1);
        }
}

/**
 * Checks if the input is in a reasonable range.
 */
void validateInput(int n) {
        char good = 1;
        if (MIN_N > n || MAX_N < n) {
                good = 0;
        }
        if (!good) {
                printf("Input out of bounds: was %d; has to be between %d and"
                       "%d.", MIN_N, MAX_N, n);
                exit(2);
        }
}

/**
 * Prints the elements of an array, prefixed with a message. 1007!!
 */
void printArray(int *array, int n, char *message) {
        printf("%s", message);
        int i;
        for (i = 0; i < n - 1; ++i) {
                printf("%d ", array[i]);
        }
        printf("%d\n", array[n-1]);
}

/**
 * Swap two elements of an array. Big deal.
 */
void swap(int *array, int i, int j) {
        int t = array[i];
        array[i] = array[j];
        array[j] = t;
}

/**
 * The quicksort algorithm using a random pivot. On average, the complexity
 * should be O (n * log n). Will write a proof one day. Also, this is a
 * non-optimized naive just-for-fun implementation. Beliebe in it!
 */
void quicksort(int *array, int n) {

        if (n <= 1) {
                return;
        }

        int pivotIndex = rand() % n;
        int smallIndex = 0;
        int largeIndex = n - 1;
        /* meh, variable names */
        
        while (smallIndex < largeIndex) {
                while (smallIndex < pivotIndex) {
                        if (array[smallIndex] > array[pivotIndex]) {
                                swap(array, smallIndex, pivotIndex);
                                pivotIndex = smallIndex;
                                break;
                        } else {
                                /* Unneeded else, but hey - it is symmetric! */
                                ++smallIndex;
                        } 
                }
                while (pivotIndex < largeIndex) {
                        if (array[pivotIndex] > array[largeIndex]) {
                                swap(array, pivotIndex, largeIndex);
                                pivotIndex = largeIndex;
                                break;
                        } else {
                                --largeIndex;
                        } 
                }
        }

        quicksort(array, smallIndex);
        quicksort(array + smallIndex + 1, n - smallIndex - 1);
}

void verifyResult(int *array, int n) {
        char good = 1;
        int i;
        for (i = 1; i < n; ++i) {
                if (array[i-1] > array[i]) {
                        good = 0;
                        break;
                }
        } 
        if (!good) {
                printf("Test failed.\n");
        } else {
                printf("Test succeeded.\n");
        }
}

int main(int argc, char **argv) {
        validateArgs(argc, argv);

        /* Arguments have been checked, so this is safe. OR IS IT?!?! */
        int n;
        sscanf(argv[1], "%d", &n);
        validateInput(n);

        int *array = (int *) malloc (sizeof(int) * n);
        
        /* Randomize once, rather than every time which would be the case if
         * this was called in the quicksort function. */
        srand(time(NULL));
        int i;
        for (i = 0; i < n; ++i) {
                array[i] = rand() % A_REASONABLE_NUMBER;
        }

        printArray(array, n, "a: ");

        /* quicksort is in-place, so there is no need for an additional array.
         * Sad times, due to 80 char line restriction, this has to be 2-lines */
        quicksort(array, n); 

        printArray(array, n, "b: ");

        verifyResult(array, n);

        free(array);
        return 0;
}
