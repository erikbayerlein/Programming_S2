// Considerando a função que determina se um número é ou não primo,
// escreva um programa para:
// a) Imprimir todos os números primos menores que um valor x, fornecido via teclado.
// b) Imprimir os primeiros n números primos, onde n é fornecido via teclado.

#include <stdio.h>
#include <math.h>

int primo (int n);

int main (void) {
    int x, n, resultado, i, c;

    // item a
    printf ("Digite um valor para imprimir todos os numeros primos menores que ele: ");
    scanf ("%d", &x);

    for (i = 1; i <= x; i++) {
        resultado = primo(i);
        if (resultado == 1) {
            printf ("%d\n", i);
        }
        else {
            continue;
        }
    }

    // item b 
    // AINDA PRECISA FAZER
    printf ("Digite quantos numeros primos serao apresentados: ");
    scanf ("%d", &n);

    while (c <= n) {
        resultado = primo(c);
        if (resultado == 1) {
            printf ("%d\n", c);
        }
        else {
            continue;
        }
    }   

    return 0;
}


int primo (int n) {
    if (n == 2) {
        return 1;
    } 
    else if (n<2 || (n%2)== 0) {
        return 0;
    } 
    else {
        int lim = (int) sqrt(n);
        for (int i=3; i<= lim; i+=2) {
            if (n% i == 0) {
                return 0;
            }
        }
        return 1;
    }
}
