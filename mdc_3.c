#include <stdio.h>

int mdc (x, y);

int main (void) {
    int x, y, z;

    printf ("Digite tres numeros inteiros: ");
    scanf ("%d %d %d", &x, &y, &z);

    int result = mdc (x, y);
    int result2 = mdc (result, z);

    printf ("O MDC dos numeros e: %d", result2);

    return 0;
}

int mdc (x, y) {
    int resto;
    while (y != 0) {
        resto = x % y;
        x = y;
        y = resto;
    }
    
    return x;
}