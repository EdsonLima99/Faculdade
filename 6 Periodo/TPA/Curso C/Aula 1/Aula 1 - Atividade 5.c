// 5. Fa�a um programa em C que leia dois n�meros reais e os imprima.

#include <stdio.h>
#include <stdlib.h>

void main()
{
	float num1, num2;

	printf("Informe o primeiro numero: ");
	scanf("%f", &num1);

	printf("Informe o segundo numero: ");
	scanf("%f", &num2);

	printf("Numeros inseridos: %.2f e %.2f", num1, num2);
}
