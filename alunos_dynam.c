/* Considerando as declarações a seguir para
representar o cadastro de alunos de uma disciplina,
implemente um programa que leia e exiba na tela
o número de matrícula, o nome, a turma e a média
de todos os alunos que foram aprovados na disciplina.
(OBS. A matriz que armazenará as informações dos
alunos por turma deve ser alocada dinamicamente – i.e., usando malloc()). */

#include <stdio.h>
#include <stdlib.h>
struct aluno {
    char nome[81];
    char matricula[8];
    char turma;
    float p1;
    float p2;
    float p3;
};

typedef struct aluno Aluno;

void imprime_aprovados (int num_rows, int num_cols, Aluno** turmas);


int main (void) {
    



    return 0;
}