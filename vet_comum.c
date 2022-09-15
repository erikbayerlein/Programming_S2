#include <stdio.h>

#define tam_a 5
#define tam_b 8

int preencher_vetor (x, y);
int mesmo_valor (a, b);

int main (void) {
    int a[tam_a], b[tam_b];

    *a = preencher_vetor(a, tam_a);
    printf ("\n");
    *b = preencher_vetor(b, tam_b);
    printf ("\n");
    mesmo_valor(a, b);

    return 0;
}

int preencher_vetor (int *a, int tam) {
    int x, i;

    for (i = 0; i < tam; i++) {
        printf ("Digite a posicao %d do vetor: ", i);
        scanf ("%d", &x);
        a[i] = x;
    }

    return a;
}

int mesmo_valor (int *a, int *b) {
    int j, n;

    for (j = 0; j < tam_a; j++) {
        for (n = 0; n < tam_b; n++){
            if (a[j] == b[n]) {
                printf ("%d esta presente em ambos\n", a[j]);
            }
        }
    }
}