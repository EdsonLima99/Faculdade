// 15. Fa�a um programa em C que leia o valor de um produto, o percentual do desconto desejado
// e imprima o valor do desconto e o valor do produto subtraindo o desconto.

#include <stdio.h>
#include <stdlib.h>

void main()
{
	float valor, percentual, desconto, valorDescontado;

	printf("Informe o valor do produto: ");
	scanf("%f", &valor);

	printf("Informe o percentual do desconto(em porcentagem): ");
	scanf("%f", &percentual);

	percentual /= 100;

	desconto = valor * percentual;
	valorDescontado = valor - desconto;

	printf("Valor do desconto: R$ %.2f\n", desconto);
	printf("Valor do produto com desconto: %.2f", valorDescontado);
}
