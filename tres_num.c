// Escreva um programa em C que receba três
// números inteiros como entrada e imprima,
// como saída: (i) o maior número recebido;
// e (ii) os números em ordem crescente.

#include <stdio.h>

int main (void) {
    int x, y, z, aux, j;

    printf ("Digite tres numeros: ");
    scanf ("%d %d %d", &x, &y, &z);

    int A[] = {x, y, z};

    for (int i = 1; i <= 3; i++) {
        aux = A[i];
        j = i - 1;
        A[0] = aux;
        while (aux < A[j]) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = aux;
    }

    printf ("\n");

    for (int b = 0; b < 3; ++b) {
        int a = A[b];
        printf ("%d", a);
    }

    return 0;
}