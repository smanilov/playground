#include <stdio.h>

#define HELLO(val) printf("hello " #val ":%d\n", val);

int main() {
        HELLO(3);  // Outputs "hello 3:3"
        int x = 10;
        HELLO(x);  // Outputs "hello x:10"
        int y = 15;
        HELLO(x+y);  // Outputs "hello x+y:25"
        return 0;
}
