/* Dada uma matriz 𝐴𝑚×𝑛 de inteiros,
escreva uma função que diga quantas vezes
uma dado número aparece na matriz
(int repeticoes(int numero)). */

#include <stdio.h>

int buscar_mat (int m, int n, int A[m][n]);

int main () {
    int m, n, k;

    printf ("Digite a quantidade de linhas e colunas da matriz: ");
    scanf ("%d %d", &m, &n);

    int A[m][n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf ("Digite o elemento da posicao [%d][%d]: ", i, j);
            scanf ("%d", &A[i][j]);
        }
    }

    k = buscar_mat (m, n , A);

    printf ("%d", k);

    return 0;
}


int buscar_mat (int m, int n, int A[m][n]) {
    int k = 0, num;

    printf ("Digite o numero a ser contabilizado: ");
    scanf ("%d", &num);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] == num) {
                k++;
            } 
        }
    }
    return k;
}