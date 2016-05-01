#include <stdio.h>

const int glob;

int main () {
    const int loc = 4;
    printf("%d", loc);
    loc = 10;
    printf("%d", loc);
}
