// 8. Faça um programa que leia um número e imprima uma das mensagens: "Maior
// do que 20", "Igual a 20"ou "Menor do que 20".

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int num;

    printf("Informe o numero: ");
    scanf("%d", &num);

    if (num > 20)
        printf("Maior do que 20");
    else if (num == 20)
        printf("Igual a 20");
    else
        printf("Menor do que 20");
}