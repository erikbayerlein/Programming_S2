/* O Jogo da Velha é um jogo típico de tabuleiro,
onde dois jogadores intercalam jogadas.
Um jogador usa a marca × e outro jogador
usa a marca Ο para indicar a sua jogada
em um tabuleiro de 𝐴3×3. Vence o jogo o
jogador que conseguir preencher uma fileira completa,
Seja na vertical, na horizontal ou na transversal.
Escreva um programa que implemente a dinâmica
do jogo utilizando uma matriz. O programa deve
permitir que os dois jogadores intercalem suas
jogadas e avise quando houve um ganhador. */

#include <stdio.h>

char jogada (char A[3][3]);
int fim (char A[3][3]);
void imprime (char A[3][3]);

int main () {
    char A[3][3];
    int result, w;

    printf ("O jogador 1 utilizara X.\n");
    printf ("Enquanto o jogador 2 utilizara O.\n");

    for (int i = 1; i <= 9; i++) {
        printf ("Jogador 1: \n");
        A[3][3] = jogada (A);
        imprime(A);
        result, w = fim (A);
        if (result == 1) {
            break;
        }

        printf ("Jogador 2: \n");
        A[3][3] = jogada (A);
        imprime(A);
        result, w = fim (A);
        if (result == 1) {
            break;
        }
    }

    if (w == 1) {
        printf ("O ganhador foi o Jogador 1!");
    }
    else if (w == 2) {
        printf ("O ganhador foi o Jogador 2!");
    }
    else {
        printf ("Deu velha!");
    }

    return 0;
}


char jogada (char A[3][3]) {
    int n = 0, m = 0;
    char x;
    
    printf ("Digite as coordenadas da casa: ");
    scanf ("%d %d", &n, &m);

    printf ("Digite o simbolo: ");
    scanf ("%c\n", &x);

    A[n][m] = x;
    
    return A[3][3];
}


void imprime (char A[3][3]) {
    printf ("%c | %c | %c\n%c | %c | %c\n%c | %c | %c", A[0][0], A[0][1], A[0][2],
     A[1][0], A[1][1], A[1][2], A[2][0], A[2][1], A[2][2]);
}


int fim (char A[3][3]) {
    int w, result;

    // VERIFICACAO DAS LINHAS
    for (int i = 0; i < 3; i++) {
        if (A[i][0] == A[i][1] && A[i][0] == A[i][2]) {
            if (A[i][0] == "X") {
                w = 1;
                result = 1;
                return result, w;
            }
            else if (A[i][0] == "O") {
                w = 2;
                result = 2;
                return result, w;
            }
        }
    }

    // VERIFICACAO DAS COLUNAS
    for (int i = 0; i < 3; i++) {
            if (A[0][i] == A[1][i] && A[0][i] == A[2][i]) {
                if (A[0][i] == "X") {
                    w = 1;
                    result = 1;
                    return result, w;
                }
                else if (A[0][i] == "O") {
                    w = 2;
                    result = 2;
                    return result, w;
                }
            }
        }

    // DIAGONAIS
    if (A[0][0] == A[1][1] && A[0][0] == A[2][2]) {
        if (A[0][0] == "X") {
            w = 1;
            result = 1;
            return result, w;
        }
        else if (A[0][0] == "O") {
            w = 2;
            result = 2;
            return result, w;
        }
    }
    if (A[0][2] == A[1][1] && A[0][2] == A[2][0]) {
        if (A[0][2] == "X") {
            w = 1;
            result = 1;
            return result, w;
        }
        else if (A[0][2] == "O") {
            w = 2;
            result = 2;
            return result, w;
        }
    }

    return result = 0, w = 0;
}