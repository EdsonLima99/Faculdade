// Faça um programa em linguagem C que permita entrar com números e imprimir o
// quadrado de cada número digitado até entrar um número múltiplo de 6 que deverá ter
// seu quadrado impresso também.

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int num;

    do
    {
        printf("\nDigite um numero ou multiplo de 6 para encerrar: ");
        scanf("%d", &num);

        printf("Quadrado: %d \n", num * num);
    } while ((num % 6) != 0);
}