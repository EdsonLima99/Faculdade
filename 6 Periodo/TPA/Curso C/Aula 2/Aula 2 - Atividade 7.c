// 7. Faça um programa em C que leia um número e indique se o número está compreendido entre 20 e 50 ou não.

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int num;

    printf("Informe o numero: ");
    scanf("%d", &num);

    if (num > 20 && num < 50)
        printf("Esse numero esta compreendido entre 20 e 50");
    else
        printf("Esse numero nao esta compreendido entre 20 e 50");
}