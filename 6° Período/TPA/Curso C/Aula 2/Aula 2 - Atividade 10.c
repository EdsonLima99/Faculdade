// 10. Faça um programa em C que leia três números inteiros e imprima os três em
// ordem crescente.

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int num1, num2, num3;

    printf("Informe o primeiro numero: ");
    scanf("%d", &num1);

    printf("Informe o segundo numero: ");
    scanf("%d", &num2);

    printf("Informe o terceiro numero: ");
    scanf("%d", &num3);

    if (num1 > num2 && num1 > num3){
        if(num2 > num3)
            printf("%d, %d, %d", num3, num2, num1);
        else
            printf("%d, %d, %d", num2, num3, num1);
    }else if (num2 > num1 && num2 > num3){
        if(num1 > num3)
            printf("%d, %d, %d", num3, num1, num2);
        else
            printf("%d, %d, %d", num1, num3, num2);
    }else{
        if(num1 > num2)
            printf("%d, %d, %d", num2, num1, num3);
        else
            printf("%d, %d, %d", num1, num2, num3);
    }
}