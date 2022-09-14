// Considerando a existência de notas (cédulas)
// nos valores R$ 100, R$ 50, R$ 20, R$ 10, R$ 5, R$ 2 e R$ 1,
// escreva um programa que capture um valor inteiro em reais (R$)
// e determine o menor número de notas para se obter o montante fornecido.
// O programa deve exibir o número de notas para 
// cada um dos valores de nota existentes.

#include <stdio.h>

int main(void) {
    int valor, cem, cinq, vinte, dez, cinco, dois, um;

    printf ("Digite um valor inteiro em reais: ");
    scanf ("%d", &valor);
    
    while ((valor / 100) > 0) {
        cem += 1;
    }
    if (cem > 0) {
        while (((valor % (cem * 100)) / 50) > 0) {
            cinq += 1;
        }
    }
    else {
        while (((valor % 100) / 50) > 0) {
            cinq += 1;
        }
    }
    return 0;
}