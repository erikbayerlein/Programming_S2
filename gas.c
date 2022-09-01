// Escreva um programa que calcule o preço da
// gasolina por litro no Brasil se aqui fosse adotado o
// mesmo preço cobrado nos Estados Unidos. 
// O programa deve capturar dois valores fornecidos via
// teclado: o preço do galão de gasolina praticado
// nos Estados Unidos (em dólares) e a taxa de
// conversão do dólar para o real. 
// O programa então deve exibir o preço do litro de gasolina
// correspondente em reais. Sabe-se que um galão tem 3.7854 litros.

#include <stdio.h>

int main (void) {
    float eua, taxa, br;

    printf("Digite o preco de um galao de gasolina nos EUA: ");
    scanf("%f", &eua);

    printf("Digite a cotagem do dolar: ");
    scanf("%f", &taxa);

    br = taxa*eua;
    br = br/3.7854;

    printf("O preco da gasolina no Brasil e: %g", br);

    return 0;
} 