/* Faça um programa para corrigir uma prova com 10
questões de múltipla escolha (a, b, c, d ou e), em uma turma com 3 alunos.
Cada questão vale 1 (um) ponto. Leia o gabarito, e para cada 
aluno leia sua matricula (número inteiro) e suas respostas. Calcule e escreva:
a) Para cada aluno, escreva sua matrícula, suas respostas, e sua nota.
b) O percentual de aprovação, assumindo média 7.0. */

#include <stdio.h>

struct aluno {
    char nome;
    float nota;
};

struct gabarito {
    char item;
};

typedef struct aluno aluno;
typedef struct gabarito gabarito;

aluno preencher_aluno (void);
gabarito preencher_gabarito (void);

int main (void) {
    gabarito resp[10];
    
    aluno mat[3][11];
    aluno a;

    for (int i = 0; i < 3; i++) {
        a = preencher_aluno();
        mat[i][0] = a;
    }

    resp[10] = preencher_gabarito ();



    return 0;
}


aluno preencher_aluno (void) {
    aluno a;

    printf ("Nome........: ");
    scanf ("%s", &a.nome);

    printf ("\nMatricula........: ");
    scanf ("%s", &a.matricula);

    printf ("\nNota........: ");
    scanf ("%s", &a.nota);

    return a;
}

gabarito preencher_gabarito (void) {
    gabarito resp[10];
    gabarito k;

    for (int i = 0; i < 10; i++) {
        printf ("\nDigite a resposta da questao %d: ", i+1);
        scanf ("%s", &k.item);
        resp[i] = k;
    }

    return resp[10];
}