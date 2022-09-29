/* Considerando as declarações a seguir
para representar o cadastro de alunos de uma disciplina,
implemente um programa que leia e exiba
na tela o número de matrícula, o nome,
a turma e a média de todos os alunos que foram aprovados na disciplina.
(OBS. A matriz que armazenará as informações
dos alunos por turma deve ser alocada dinamicamente – i.e., usando malloc()).

ex.:
   struct aluno {
       char nome[81];
       char matricula[8];
       float p1;
       float p2;
       float p3;
};
    typedef struct aluno Aluno;
    void imprime_aprovados (int num_rows, int num_cols, Aluno** turmas); */

#include <stdio.h>
#include <stdlib.h>

char preencher_aluno (char *v, int n);
char preencher_mat (char *mat, char *v);
void mostrar_mat (char *mat);
void aprovados (char *mat);

struct aluno {
    char nome;
    char matricula;
    float ap1;
    float ap2;
    float ap3;
};

typedef struct aluno Aluno;

int main (void) {
    int n;
    char *v;
    char *mat;

    printf ("Digite quantos alunos há na turma: ");
    scanf ("%d", &n);

    v = (char*) malloc(n*sizeof(char));

    if (v == NULL) {
        printf("Memoria insuficiente.\n");
        exit(1);
    }

    *v = preencher_aluno(v, n);


    mat = (char*) malloc(n*sizeof(char));

    if (mat == NULL) {
        printf("Memoria insuficiente.\n");
        exit(1);
    }

    mat = preencher_mat(mat, v);
    
    mostrar_mat(mat);
    aprovados(mat);

    return 0;
}


char preencher_aluno (char *v, int n) {
    Aluno a;
    char vet[5];

    for (int i = 0; i < n; i++) {
        printf ("Digite as informacoes a seguir do %d aluno: ")

        printf ("Nome: ");
        scanf ("%c\n", &a.nome);
        
        printf ("Matricula: ");
        scanf ("%c\n", &a.matricula);
        
        printf ("Ap1: ");
        scanf ("%c\n", &a.ap1);
        
        printf ("Ap2: ");
        scanf ("%c\n", &a.ap2);
        
        printf ("Ap3: ");
        scanf ("%c\n", &a.ap3);

        
    }




    return v;
}