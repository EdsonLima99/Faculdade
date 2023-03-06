// Faça um programa em C que armazene 15 números inteiros em um vetor NUM e
// imprima uma listagem dos números lidos.

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int i, NUM[15];

    // lendo os valores
    for (i = 0; i < 15; i++)
    {
        printf("Informe um numero: ");
        scanf("%d", &NUM[i]);
    }

    // imprimindo os valores
    for (i = 0; i < 15; i++)
    {
        printf("Numero: %d \n", NUM[i]);
    }
}