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

void preencher_turma ();
char preencher_aluno ();
char preencher_mat (char *mat, char *v);
void mostrar_mat (char *mat);
void aprovados (char *mat);

struct aluno {
    char nome;
    char matricula;
    float ap1;
    float ap2;
    float ap3;
    float media;
};

typedef struct aluno Aluno;

int main (void) {
    int n;
    void *v;

    printf ("Digite quantas alunos vocês gostaria de adicionar: ");
    scanf ("%d", &n);

    for (int i = 0; i <= n; i++) {
        v = preencher_aluno ();
        
    }


    
    return 0;
}




char preencher_aluno () {

        
    }


