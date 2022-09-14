// Escreva um programa que converta um valor
// de ângulo dado em radianos para o valor
// correspondente expresso em graus, minutos e segundos.
// Sabe-se que 1 radiano equivale a 57.29578 graus.
// Escolha um formato de saída apropriado.

#include <stdio.h>

int main (void) {
    float rad, grau, min, seg_final;
    int min_final, grau_final;

    printf ("Digite o angulo em radianos: ");
    scanf ("%f", &rad);

    grau = rad * 0.29578;
    grau_final = rad * 57;

    min_final = 60 * grau;

    if (min_final > 60) {
        min = (60 * grau) - min_final;
        min_final = min_final - 60;
        seg_final = 60 * min;
    }
    else {
        seg_final = 0;
    }

    printf ("%d graus, %d minutos e %02.2f segundos.", grau_final, min_final, seg_final);

    return 0;
}