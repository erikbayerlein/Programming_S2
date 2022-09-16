/* Implemente um programa que faz
o cálculo da média (𝑚) e da variância (𝑣) de uma amostra de tamanho n. */

#include <stdio.h>
#include <math.h>

int main (void) {
    int n = 0;
    float m = 0, v = 0, x = 0, s = 0, sv = 0, y = 0;

    printf ("Digite o tamanho da amostra: ");
    scanf ("%d", &n);

    float A[n];

    // preenchimento do vetor
    for (int i = 0; i < n; i++) {
        printf ("Digite um numero para o lugar %d: ", i);
        scanf ("%f", &x);

        A[i] = x;
    }

    // mêdia
    for (int i = 0; i < n; i++) {
        s += A[i];
    } 

    m = s/n;

    printf ("A media e: %.2f\n", m);

    // variância
    for (int i = 0; i < n; i++) {
        y = (A[i] - m);
        sv += y;
    } 

    sv = sqrt(sv);
    v = sv/(n-1);

    printf ("A variancia e: %.2f", v);

    return 0;
}