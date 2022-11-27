// 4. Faça um programa que leia um número e informe se ele é ou não divisível por 5.

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int num;

    printf("Informe o numero: ");
    scanf("%d", &num);

    if ((num % 5) == 0)
        printf("E divisivel por 5");
    else
        printf("Nao e divisivel por 5");
}