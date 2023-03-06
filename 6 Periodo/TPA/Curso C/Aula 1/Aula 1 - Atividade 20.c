// 20. Fa�a um programa em C que efetue a apresenta��o do valor da convers�o em
// real (R$) de um valor lido em d�lar (US$). Para isso, ser� necess�rio tamb�m ler o
// valor da cota��o do d�lar.

#include <stdio.h>
#include <stdlib.h>

void main()
{
	float valor, real;

	printf("Informe o valor: ");
	scanf("%f", &valor);

	real = valor * 5;

	printf("$ %.2f em Real: R$ %.2f\n", valor, real);
}
