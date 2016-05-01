#include <stdlib.h>
#include <stdio.h>

int main () {
    int *p, *q, *c;
    p = malloc(sizeof(p));
    q = p;
    *p = 3;

    printf("p: %p\n", p);
    printf("*p: %d\n", *p);
    printf("q: %p\n", q);
    printf("*q: %d\n", *q);

    printf("free(q)\n");
    free(p);

    for (int i = 0; i < 1000000; i++) {
        c = malloc(sizeof(c));
        *c = 2 *  2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2; 
        printf("%i\n", i);
    }

    printf("p: %p\n", p);
    printf("*p: %d\n", *p);
    printf("q: %p\n", q);
    printf("*q: %d\n", *q);

    return 0;
}
