// 3. Faça um programa que leia um número e imprima uma das duas mensagens: "É
// múltiplo de 3"ou "Não é múltiplo de 3".

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int num;

    printf("Informe o numero: ");
    scanf("%d", &num);

    if ((num % 3) == 0)
        printf("E multiplo de 3");
    else
        printf("Nao e multiplo de 3");
}