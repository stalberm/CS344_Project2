#include <stdio.h>


int main(void) {

    int x = 12;
    float y = 3.14;
    char *s = "Hello, world!\n";

    printf("x is %u, y is %f\n%s", x, y, s);
    for(int i = 0; i < 5; i++) {
        printf("%u x 5 = %u\n", i, i*5);
    }
}
