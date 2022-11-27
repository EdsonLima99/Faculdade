// 9. Fa�a um programa em C que leia um n�mero real e imprima � deste n�mero.

#include <stdio.h>
#include <stdlib.h>

void main()
{
	float num, umQuarto;

	printf("Informe o numero: ");
	scanf("%f", &num);

	umQuarto = num / 4;

	printf("1/4 do numero %.2f: %.2f", num, umQuarto);
}
