#include <stdio.h>
#include <stdlib.h>

void main()
{
	int soma, num1, num2;

	// Trecho responsavel pela entrada dos dados
	printf("Informe o primeiro numero: ");
	scanf("%d", &num1);
	printf("Informe o segundo numero: ");
	scanf("%d", &num2);

	/*
	O trecho a seguir e responsavel pela soma dos valores de num 1 e num 2
	informados pelo usuario do programa
	*/
	soma = num1 + num2;

	printf("Resultado da soma: %d", soma);
}
