// Faça um programa em C que leia um número e após a leitura, calcule e imprima a raiz
// quadrada deste número.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
    float numero, raiz;

    printf("Informe um numero: ");
    scanf("%f", &numero);

    raiz = sqrt(numero);

    printf("A raiz quadrada do numero e: %.2f \n", raiz);
}
