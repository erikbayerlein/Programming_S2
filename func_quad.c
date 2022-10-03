/*Escreva um programa para fazer o cálculo das
raízes quadradas de uma equação do segundo grau
(𝑎𝑥2 + 𝑏𝑥 +𝑐). Os valores dos coeficientes
(𝑎, 𝑏, 𝑐 reais) devem ser fornecidos via teclado. O valor
do coeficiente 𝑎 deve ser diferente de zero. O valor do delta (∆= 𝑏
2 − 4𝑎𝑐) deve ser calculado em
uma função separada, double delta(double a,
double b, double c), e impresso na principal (𝑚𝑎𝑖𝑛).
Escreva uma função que calcula as raízes
da equação. A função deve retornar o número de
raízes reais existentes e preencher os endereços
passados com os valores das raízes correspondentes, seguindo o protótipo:
int raizes(double a, double b, double c,
double *px1, double *px2). A quantidade de raízes e seus
valores devem ser mostrados na tela */

#include <stdio.h>
#include <math.h>

float delta (float a, float b, float c);
int raizes (float a, float b, float c, float d, float *px1, float *px2, int *pn);

int main () {
    float a, b, c, d, r1, r2;
    int n;

    printf ("Digite os valores de a, b e c: ");
    scanf ("%f %f %f", &a, &b, &c);

    while (a == 0) {
        printf ("Digite o valor de a novamente: ");
        scanf ("%f", &a);
    }

    d = delta (a, b, c);
    printf ("O delta e: %.2f\n", d);

    raizes (a, b, c, d, &r1, &r2, &n);

    if (n == 0) {
        printf ("A equacao nao possui raizes reais.");
    }

    else {
        printf ("A equacao possui %d raiz(es).\n", n);
        printf ("A(s) raiz(es) e(sao) %.2f, %.2f", r1, r2);
    }


    return 0;
}


float delta (float a, float b, float c) {
    float d = b*b - (4*a*c);
    return d;
}


int raizes (float a, float b, float c, float d, float *px1, float *px2, int *pn) {
    if (d < 0.0) {
        printf ("Nao ha valores reais para as raizes.\n");
        *pn = 0;
    }

    else if (d = 0.0) {    
        printf ("mae rodou");
        *px1 = (-b)/2*a;
        *pn = 1;
    }

    else if (d > 0.0) {
        *px1 = ((-b + sqrt(d))/(2*a));
        *px2 = ((-b - sqrt(d))/(2*a));
        *pn = 2;
    }
}