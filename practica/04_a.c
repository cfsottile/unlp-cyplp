# include <stdio.h>

int main () {
    int m[10];
    for (int i = 0; i < 10; i ++) {
        printf("%p --> %d\n", &(m[i]), m[i]);
    }
    1 == 2;
    m[2];
    printf("function return: %d", fun(10));
    // fun (14);
    return 0;
}

int fun (int a) {
    printf("hola %d", a);
}

