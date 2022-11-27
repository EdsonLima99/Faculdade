// 8. Fa�a um programa em C que leia dois n�meros inteiros e imprima a subtra��o deles.

#include <stdio.h>
#include <stdlib.h>

void main()
{
	int num1, num2, subtracao;

	printf("Informe o primeiro numero: ");
	scanf("%d", &num1);

	printf("Informe o segundo numero: ");
	scanf("%d", &num2);

	subtracao = num1 - num2;

	printf("Resultado da subtracao: %d", subtracao);
}
