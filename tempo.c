// Escreva um programa que capture do teclado o
// número de segundos transcorridos num evento e
// imprima o tempo no formato hora-minuto-segundo: h:m:s,
// onde hora e minuto são exibidos com
// dois dígitos, preenchidos com zero à esquerda (%02d),
// e segundo exibido com duas casas decimais,
// também preenchido com zero à esquerda (%05.2f).

#include <stdio.h>

int main (void) {
    int hor, min;
    float seg;

    min = 0;

    printf ("Digite a quantidade de segundos passados: ");
    scanf ("%f", &seg);

    while (seg >= 60) {
        min = min + 1;
        seg = seg - 60;
        hor = 0;

        while (min >= 60) {
            hor = hor + 1;
            min = min - 60;
        }
    }

    printf ("Passaram %02d horas, %02d min e %05.2f segundos.",hor, min, seg);
    
    return 0;
}