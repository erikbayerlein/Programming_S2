/* Durante uma corrida automobilística com 𝑁 voltas de duração,
foram anotados para um piloto, na ordem,
os tempos registrados em cada volta.
Fazer um programa em C para ler os
tempos das 𝑁 voltas, guardar em um vetor,
implementar funções para calcular e imprimir:
(i) melhor tempo; 
(ii) a volta em que o melhor tempo ocorreu; 
(iii) pior tempo;
(iv) a volta em que o pior tempo ocorreu;
e (v) o tempo médio das 𝑁 voltas. */

#include <stdio.h>

float melhor_t (float *A, int n);
float pior_t (float *A, int n);
float t_medio (float *A, int n);

int main (void) {
    int n;
    float t;

    printf ("Digite quantas voltas o piloto deu: ");
    scanf ("%d", &n);

    float A[n];

    for (int i = 1; i <= n; i++) {
        printf ("Digite o tempo em segundos da %dª volta: ", i);
        scanf ("%f", &t);

        A[i-1] = t;
    }

    melhor_t (A, n);
    pior_t (A, n);
    t_medio (A, n);

    return 0;
}


float melhor_t (float *A, int n) {
    float x = A[0];
    int y = 0;

    for (int i = 0; i < n; i++) {
        if (x > A[i]) {
            x = A[i];
            y = i;
        }
    }

    y++;

    printf ("O melhor tempo foi: %.2f\n", x);
    printf ("Na volta %d\n", y);

    return 0;
}


float pior_t (float *A, int n) {
    float x = A[0];
    int z = 0;

    for (int i = 0; i < n; i++) {
        if (x < A[i]) {
            x = A[i];
            z = i;
        }
    }

    z++;

    printf ("\nO pior tempo foi: %.2f\n", x);
    printf ("Na volta %d\n", z);

    return 0;
}


float t_medio (float *A, int n) {
    float a = 0, b = 0;

    for (int i = 0; i < n; i++) {
        a += A[i];
    }

    b = a/n;

    printf ("\nO tempo medio em cada volta foi: %.2f segundos", b);

    return 0;
}