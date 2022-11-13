#include "ABB.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  int chave;
  char conteudo;
  No *esq;
  No *dir;
};

/* Aloca e retorna um No com os dados passados por parâmetro. Retorna o nó
 * criado ou NULL caso não seja posivel criar o nó. */
No *abb_cria_no(int chave, char conteudo) {
  if (conteudo < 0) {
    return NULL;
  }

  No *no = (No *)malloc(sizeof(No *));

  if (no == NULL) {
    return NULL;
  }

  no->esq = (No *)malloc(sizeof(No));
  no->dir = (No *)malloc(sizeof(No));
  no->chave = chave;
  no->conteudo = conteudo;

  return no;
}

/* Libera a memória de um nó e toda as suas sub-árvores. Retorna 1 se for
 * possivel fazer a liberação ou 0 caso o nó seja NULL. */
int abb_libera_no(No *no) {
  if (no == NULL) {
    return 0;
  }

  abb_libera_no(no->esq);
  abb_libera_no(no->dir);
  free(no);

  return 1;
}

/* Retorna a chave do nó ou -1 caso o nó seja NULL.  */
int abb_chave_no(No *no) {
  if (no == NULL) {
    return -1;
  }

  return no->chave;
}

/* Retorna o conteúdo do no ou '#' caso o nó seja NULL. */
char abb_conteudo_no(No *no) {
  if (no == NULL) {
    return '#';
  }
  return no->conteudo;
}

/* Adiciona um nó à esquerda ou à direita do no raiz. Retorna a raiz da árvore
 * resultante ou NULL caso (i) a raiz e o nó sejam NULL e (ii) caso o nó possua
 * mesma chave que outro nó previamente inserido na árvore. */
No *abb_insere_no(No *raiz, No *no) {
  if (raiz == NULL && no == NULL) {
    return NULL;
  }

  if (abb_busca_no(raiz, no->chave) == NULL) {
    if (no->chave < raiz->chave) {
      raiz->esq = abb_insere_no(raiz->esq, no);
    } else {
      raiz->dir = abb_insere_no(raiz->dir, no);
    }
    return raiz;
  }

  return NULL;
}

/* Procura o nó pela chave. Retorna o nó caso a busca obtenha sucesso ou NULL
 * em caso contrário. */
No *abb_busca_no(No *raiz, int chave) {
  if (raiz == NULL) {
    return NULL;
  }

  if (chave == raiz->chave) {
    return raiz;
  } else if (chave < raiz->chave) {
    return abb_busca_no(raiz->esq, chave);
  } else {
    return abb_busca_no(raiz->dir, chave);
  }
}

/* Remove o nó com a chave fornecida. Retorna a raiz da arvore atualizada ou
 * NULL em caso a raiz fornecida seja NULL. */
No *abb_remove_no(No *raiz, int chave) {
  if (raiz == NULL) {
    return NULL;
  }

  if (raiz->chave == chave) {
    if (raiz->esq == NULL && raiz->dir == NULL) {
      free(raiz);
      return NULL;
    } else {
      if (raiz->esq != NULL && raiz->dir != NULL) {
        No *esq = raiz->esq;
        while (esq->dir != NULL) {
          esq = esq->dir;
        }
        raiz->chave = esq->chave;
        esq->chave = chave;
        raiz->esq = abb_remove_no(raiz->esq, chave);
        return raiz;

      } else {
        No *aux;
        if (raiz->esq != NULL) {
          aux = raiz->esq;
        } else {
          aux = raiz->dir;
        }
        free(raiz);
        return aux;
      }
    }
  } else {
    if (chave < raiz->chave) {
      raiz->esq = abb_remove_no(raiz->esq, chave);
    } else {
      raiz->dir = abb_remove_no(raiz->dir, chave);
    }
    return raiz;
  }
}

/* Retorna a altura da árvore ou -1 caso araiz seja NULL. */
int abb_altura(No *raiz) {
  if (raiz == NULL) {
    return -1;
  }

  int dir = abb_altura(raiz->dir);
  int esq = abb_altura(raiz->esq);

  if (dir > esq) {
    return dir + 1;
  } else {
    return esq + 1;
  }
}

/* Retorna o número de nós da árvore ou -1 caso a raiz seja NULL. */
int abb_numero(No *raiz) {
  if (raiz == NULL) {
    return -1;
  }

  return abb_numero(raiz->dir) + abb_numero(raiz->esq) + 1;
}

/*Retorna a concatenação do conteúdo da árvore fazendo percurso em pré-ordem à
 * partir do nó ou '#' caso o nó seja NULL. */
char *abb_pre_ordem(No *no) {
  char *conc = (char *)malloc(sizeof(char));

  if (no == NULL) {
    return '#';
  }

  strcat(conc, &no->conteudo);
  abb_pre_ordem(no->esq);
  abb_pre_ordem(no->dir);

  return conc;
}

/*Retorna a concatenação do conteúdo da árvore fazendo percurso em ordem à
 * partir do nó ou '#' caso o nó seja NULL. */
char *abb_ordem(No *no) {
  if (no == NULL) {
    return "#";
  }

  char *conc = (char *)malloc(sizeof(char));

  abb_ordem(no->esq);
  strcpy(conc, &no->conteudo);
  abb_ordem(no->dir);

  return conc;
}

/*Retorna a concatenação do conteúdo da árvore fazendo percurso em pós-ordem à
 * partir do nó ou '#' caso o nó seja NULL. */
char *abb_pos_ordem(No *no) {
  if (no == NULL) {
    return '#';
  }

  char *conc = (char *)malloc(sizeof(char));

  abb_pos_ordem(no->esq);
  abb_pos_ordem(no->dir);
  strcpy(conc, &no->conteudo);

  return conc;
}