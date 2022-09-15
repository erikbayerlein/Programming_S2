/*Faça um programa que determina o máximo
e o mínimo de um conjunto de 𝑛 números inteiros
armazenados num vetor 𝑎 de 10 elementos.
Faça duas funções, uma que retorna o máximo e outra
que retorne o mínimo.*/

#include <stdio.h>

int max (a);
int min (a);

int main (void) {
    int a[10], i, x;

    for (i = 0; i < 10; i++) {
        printf ("Digite o elemento da posicao %d de a: ", i);
        scanf ("%d", &x);
        
        a[i] = x;
    }

    max (a);
    min (a);

    return 0;
}

int max (int *a) {
    int x = a[0], i;

    for (i = 0; i < 10; i++) {
        if (x < a[i]) {
            x = a[i];
        }
    }

    printf ("O maior valor e: %d", x);
}

int min (int *a) {
    int x = a[0], i;

    for (i = 0; i < 10; i++) {
        if (x > a[i]) {
            x = a[i];
        }
    }

    printf ("\nO menor valor e: %d", x);
}