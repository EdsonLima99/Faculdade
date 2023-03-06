// 16. Fa�a um programa em C que calcule o reajuste do sal�rio de um funcion�rio. Para
// isso, o programa dever� ler o sal�rio atual do funcion�rio e ler o percentual de
// reajuste. Ao final imprimir o valor do novo sal�rio.

#include <stdio.h>
#include <stdlib.h>

void main()
{
	float salario, percentual, novoSalario;

	printf("Informe o valor do salario: ");
	scanf("%f", &salario);

	printf("Informe o percentual de reajuste(em porcentagem): ");
	scanf("%f", &percentual);

	percentual /= 100;

	novoSalario = salario + (salario * percentual);

	printf("Novo salario: %.2f", novoSalario);
}
