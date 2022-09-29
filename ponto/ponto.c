#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

struct ponto {
    float x;
    float y;
};

int main (void) {
    pto_cria();





    return 0;
}


Ponto* pto_cria (float x, float y) {
    Ponto p;
    Ponto* v;

    v = (Ponto*) malloc(2*sizeof(Ponto));

    if (v == NULL) {
        exit (1);
    }

    printf ("Digite o x e y do ponto 1: ");
    scanf ("%f %f", &p.x, &p.y);

    v[0] = p;

    return p;
}

void pto_libera(Ponto *v) {
    free (v);


}
