/* Crie um programa em C que lê uma sequência de 𝑛 inteiros,
onde 𝑛 é um valor inteiro fornecido pelo usuário.
Depois disso, implemente uma função de busca
(int buscar(int numero, int* sequencia))
que recebe um número fornecido pelo usuário e verifica
se esse número encontra-se a sequência.
Caso o número se encontre na sequência,
a função deve retornar seu índice, 
caso contrário deve retornar -1. 
Com base no retorno da função de busca, 
informe se o número buscado se encontra na lista e,
se afirmativo, em qual posição. */

#include <stdio.h>
#include <stdlib.h>

void buscas (int b, int *a, int n);

int main () {
    int n, b;

    printf ("Digite quantos inteiros voce quer digitar: ");
    scanf ("%d", &n);

    int a[n];

    for (int i = 0; i < n; i++) {
        printf ("Digite o numero para a posicao %d: ", i);
        scanf ("%d", &a[i]);
    }

    printf ("Digite o numero que deseja buscar no vetor: ");
    scanf ("%d", &b);

    buscas (b, a, n);

    return 0;
}


void buscas (int b, int *a, int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] == b) {
            printf ("O numero %d esta na posicao %d", b, i);
            return 0;
        }
        else {
            printf ("O numero desejado nao esta no vetor.");
            return 0;
        }
    }
}