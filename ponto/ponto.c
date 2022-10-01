#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

struct ponto {
    float x;
    float y;
};

int main (void) {
    int n;
    Ponto *v;

    v = (Ponto*) malloc(sizeof(Ponto));

    if (v == NULL) {
        printf ("Espaco insuficiente na memoria");
        exit (1);
    }

    printf ("Digite quantos pontos com coordenadas (x,y) gostaria de adicionar: ");
    scanf ("%d", &n);

    for (int i = 0; i <= n; i++) {
        v[i] = pto_cria();
    }

    free(v);





    return 0;
}


Ponto pto_cria () {
    Ponto p;

    printf ("Digite os valores x e y do ponto: ");
    scanf ("(%f, %f)", &p.x, &p.y);

    return p;
}

void pto_libera(Ponto *v) {
    free (v);


}
