/* Crie um programa em C que possua dois vetores
de inteiros (𝑎[] 𝑒 𝑏[]) cada um com a capacidade de 10 elementos.
O programa deve permitir que seja lido via teclado
os dez elementos de cada vetor. Além disso,
o programa possui uma função que calcula o produto escalar dos dois vetores */

#include <stdio.h>

int main () {
    int a[10], b[10], prod_escalar = 0;

    for (int i = 0; i < 10; i++) {
        printf ("Digite o %d elemento do vetor A: ", i);
        scanf ("%d", &a[i]);
    }

    for (int i = 0; i < 10; i++) {
        printf ("Digite o %d elemento do vetor B: ", i);
        scanf ("%d", &b[i]);
    }

    for (int i = 0; i < 10; i++) {
        prod_escalar = (a[i]*b[i]) + prod_escalar;
    }

    printf ("O produto escalar dos vetores e: %d", prod_escalar);

    return 0;
}