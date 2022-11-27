// Faça um programa em linguagem C que leia 10 números positivos e imprima o quadrado
// de cada número. Para cada entrada de dados deverá haver um trecho de validação para
// que um número negativo não seja aceito pelo programa.

#include <stdio.h>
#include <stdlib.h>

void main()
{
    float num;
    int i;

    for (i = 1; i <= 10; i++)
    {
        printf("Informe um numero: ");
        scanf("%f", &num);
        
        while (num <= 0)
        {
            printf("\n ATENCAO! Informe um numero maior que zero: ");
            scanf("%f", &num);
        }
        printf("Quadrado: %.2f \n", num * num);
    }
}