// 1. Faça um programa em C que leia dois valores numéricos inteiros e efetue a adição,
// caso o resultado seja maior que 10, apresentá-lo.

#include <stdio.h>
#include <stdlib.h>

void main()
{
	int num1, num2;

	printf("Digite o primero numero: ");
	scanf("%d", &num1);

	printf("Digite o segundo numero: ");
	scanf("%d", &num2);

	if((num1 + num2) > 10)
		printf("Resultado da soma %d + %d é maior que 10: %d", num1, num2, (num1 + num2));
}
