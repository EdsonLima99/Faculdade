// 5. Faça um programa em C que leia um número e informe se ele é divisível por 3 e
// por 7.

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int num;

    printf("Informe o numero: ");
    scanf("%d", &num);

    if ((num % 3) == 0 && (num % 7) == 0)
        printf("E divisivel por 3 e por 7");
    else
        printf("Nao e divisivel por 3 e 7 ao mesmo tempo");
}