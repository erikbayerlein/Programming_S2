// Implemente uma função iterativa (usando laço)
// para calcular o máximo divisor comum de dois
// números inteiros positivos, MDC(x, y),
// usando o algoritmo de Euclides. Este algoritmo é baseado no
// fato de que se o resto da divisão de x por y,
// representado por r, for igual a zero, y é o MDC. Se o
// resto r for diferente de zero, o MDC de
// x e y é igual ao MDC de y e r. O processo se repete até que
// o valor do resto da divisão seja zero

#include <stdio.h>

int mdc (x, y);

int main (void) {
    int x, y, resultado;
    
    printf ("Digite dois numeros inteiros positivos: ");
    scanf ("%d", &x);
    scanf ("%d", &y);

    if (x % y == 0) {
        resultado = y;
        printf("O MDC dos dois numeros e: %d", resultado);
    }
    else {
        resultado = mdc (x, y);
        printf("O MDC dos dois numeros e: %d", resultado);
    }

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