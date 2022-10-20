#include "Fila.h"
#include <stdio.h>
#include <stdlib.h>

struct node {
  Aluno *aluno;
  struct node *proximo;
};

typedef struct node No;

struct fila {
  No *primeiro;
};

/* Aloca espaço em memória e retorna uma fila */
Fila *fila_cria() {
  Fila *fila = (Fila *)malloc(sizeof(Fila));
  fila->primeiro = NULL;
  return fila;
}

/* Libera a memória de uma fila previamente criada e atribui NULL ao ponteiro
 * fila. Retorna 1 caso seja possível fazer a liberação e 0 caso a fila
 * informada seja NULL. */
int fila_libera(Fila **fila) {
  if (fila != NULL) {
    if ((*fila)->primeiro != NULL) {
      No *aux = (*fila)->primeiro;
      do {
        alu_libera(&aux->aluno);
        aux = aux->proximo;
      } while (aux != NULL);
    }
    free(*fila);
    *fila = NULL;
    return 1;
  }
  return 0;
}

/* Insere um aluno na fila. Retorna 1 se foi possível adicionar, 0 caso já
 * exista um aluno com a mesma matricula (nesse caso, o aluno não pode ser
 * adicionado) e -1 caso a fila ou aluno sejam NULL
 */
int fila_insere(Fila *fila, Aluno *aluno) {
  if (fila == NULL || aluno == NULL) {
    return -1;
  }

  char curso[30];
  char nome[50];
  int matricula;

  alu_acessa(aluno, &matricula, nome, curso);

  Aluno *a;
  a = fila_busca(fila, matricula);
  if (a != NULL) {
    return 0;
  }

  No *n = (No *)malloc(sizeof(No));
  n->aluno = aluno;
  n->proximo = NULL;

  No *aux = fila->primeiro;
  if (aux == NULL) {
    fila->primeiro = n;
    return 1;
  }

  for (No *aux = fila->primeiro; aux != NULL; aux = aux->proximo) {
    if (aux->proximo == NULL) {
      aux->proximo = n;
      return 1;
    }
  }
}

/* Remove um aluno na fila. Retorna o aluno ou NULL caso a fila esteja vazia ou
 * seja NULL */
Aluno *fila_retira(Fila *fila) {
  if (fila == NULL || fila_quantidade(fila) == 0) {
    return NULL;
  }

  No *n_prim = fila->primeiro;
  No *n_aux = n_prim->proximo;

  fila->primeiro = n_aux;

  return n_prim->aluno;
}

/* Recupera o primeiro aluno da fila. Retorna o aluno ou NULL caso a fila esteja
 * vazia ou seja NULL */
Aluno *fila_primeiro(Fila *fila) {
  if (fila == NULL || fila_quantidade(fila) == 0) {
    return NULL;
  }

  char curso[30];
  char nome[50];
  int matricula;

  No *n_prim = fila->primeiro;

  Aluno *a = n_prim->aluno;

  alu_acessa(a, &matricula, nome, curso);

  return a;
}

/* Busca aluno pelo número de matricula. Retorna o aluno se este estiver na
 * lista e NULL caso contrário, isto é, (i) fila vazia; (ii) não exista aluno
 * com a matricula fornecida; ou (iii) a fila seja NULL */
Aluno *fila_busca(Fila *fila, int matricula) {
  if (fila == NULL || fila_quantidade(fila) == 0) {
    return NULL;
  }

  int matricula_aux;
  char nome[50];
  char curso[30];

  for (No *n_aux = fila->primeiro; n_aux != NULL; n_aux = n_aux->proximo) {
    alu_acessa(n_aux->aluno, &matricula_aux, nome, curso);
    if (matricula_aux == matricula) {
      return n_aux->aluno;
    }
  }
  return NULL;
}

/* Verifica se a fila está vazia. Retorna 1 se a fila estiver vazia, 0 caso não
 * esteja vazia e -1 se a fila for NULL
 */
int fila_vazia(Fila *fila) {
  if (fila == NULL) {
    return -1;
  }

  if (fila->primeiro == NULL) {
    return 1;
  }

  return 0;
}

/* Computa a quantidade de alunos alunos na fila. Retorna a quantidade de alunos
 * ou -1, caso a fila for NULL.
 */
int fila_quantidade(Fila *fila) {
  if (fila == NULL) {
    return -1;
  }

  int i = 0;
  for (No *aux = fila->primeiro; aux != NULL; aux = aux->proximo) {
    i++;
  }

  return i;
}