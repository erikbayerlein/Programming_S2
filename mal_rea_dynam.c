/* Crie um vetor 𝑣 com 𝑛 inteiros,
onde 𝑛 é um valor inteiro fornecido pelo usuário.
O vetor só deve ser alocado na memória depois que o usuário
fornecer o valor de 𝑛 (utilize a função malloc() pra isso).
Depois disso, leia do teclado 𝑛 inteiros e armazene em 𝑣.
Depois disso, pergunte se o usuário deseja inserir mais elementos,
caso a resposta dele seja sim, leia a quantidade de elementos
que ele deseja adicionar e aumente o tamanho do vetor sem,
no entanto, perder os valores já lidos (utilize a função realloc() pra isso).
Esse processo deve se repetir até que o usuário 
informe que não deseja mais adicionar elementos ou 
a memória se esgote (faça um código que trate essa ocorrência).
Ao final, imprima todos os elementos fornecidos pelo usuário
e libere a memória (utilize a função free() pra isso). */

// declaracao de bibliotecas
#include <stdio.h>
#include <stdlib.h>

// declaracao das funcoes de preencher e adicionar
int preencher (int n, int *v);
int adicionar (int n, int *v);


int main (void) {
    // declaracao do ponteiro v e das variaveis necessarias 
    int *v;
    int n, resp;

    // tamanho do vetor é guardado em n
    printf ("Digite o tamanho do vetor desejado: ");
    scanf ("%d", &n);

    // preenche-se o vetor utilizando a funcao malloc (alocação dinamica na memoria)
    v = (int*) malloc(n * sizeof(int));

    // se o tamanho da memoria nao é suficiente, v recebera NULL
    if (v == NULL) {
        printf("Memoria insuficiente.\n");
        exit(1);
    }

    // chamada da funcao para preencher o vetor, passando n (tamanho) e v (vetor)
    *v = preencher(n, v);

    printf ("Voce deseja adicionar mais elementos?\nDigite 1 para Sim e 0 para Nao: ");
    scanf ("%d", &resp);

    // enquanto resp for 1, ira repetir
    while (resp == 1) {
        // chamada da funcao para adicionar no vetor, passando n (tamanho) e v (vetor)
        *v, n = adicionar(n, v);

        printf ("Voce deseja adicionar mais elementos?\nDigite 1 para Sim e 0 para Nao: ");
        scanf ("%d", &resp);
    }

    // print no vetor
    for (int j = 0; j < n; j++) {
        printf ("%d\n", v[j]);
    }

    // libera o espaço ocupado por v da memória
    free (v);

    return 0;
}


int preencher (int n, int *v) {
    for (int i = 0; i < n; i++) {
        printf ("Digite o inteiro para a posicao %d: ", i);
        scanf ("%d", &v[i]);
    }

    return *v;
}


int adicionar (int n, int *v) {
    // variavel para conter quantos espacos seram adicionados
    int x;

    printf ("Digite quantos elementos serao adicionados: ");
    scanf ("%d", &x);

    // funcao realloc altera a quantidade de elementos de v, mas nao os elementos ja existentes em v
    v = realloc (v, x*sizeof(int));

    // preenchimento dos novos espacos de v
    for (int i = 0 ; i < x; i++) {
        // n é a quantidade total de elementos, logo i+n será a primeira nova posicao adicionada
        printf ("Digite o inteiro para a posicao %d: ", i+n);
        scanf ("%d", &v[i+n]);
    }

    if (v == NULL) {
        printf("Memoria insuficiente.\n");
        exit(1);
    }

    // incrementa x a n, atualizando o numero de elementos de v
    n += x;

    return *v, n;
}