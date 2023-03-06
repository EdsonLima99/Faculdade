// 6. Fa�a um programa em C que leia um n�mero inteiro e imprima o seu antecessor e o seu sucessor.

#include <stdio.h>
#include <stdlib.h>

void main()
{
	int num;

	printf("Informe o numero: ");
	scanf("%d", &num);

	printf("Antecessor: %d\n", (num - 1));
	printf("Sucessor: %d\n", (num + 1));
}
