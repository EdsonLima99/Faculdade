// 11. Fa�a um programa em C que leia dois n�meros reais e calcule as quatro opera��es
// b�sicas entre estes dois n�meros, adi��o, subtra��o, multiplica��o e divis�o. Ao
// final, o programa deve imprimir os resultados dos c�lculos.

#include <stdio.h>
#include <stdlib.h>

void main()
{
	float num1, num2, soma, subtracao, multiplicacao, divisao;

	printf("Informe o primeiro numero: ");
	scanf("%f", &num1);

	printf("Informe o segundo numero: ");
	scanf("%f", &num2);

	soma = num1 + num2;
	subtracao = num1 - num2;
	multiplicacao = num1 * num2;
	divisao = num1 / num2;

	printf("Resultado da soma: %.2f\n", soma);
	printf("Resultado da subtracao: %.2f\n", subtracao);
	printf("Resultado da multiplicacao: %.2f\n", multiplicacao);
	printf("Resultado da divisao: %.2f\n", divisao);
}
