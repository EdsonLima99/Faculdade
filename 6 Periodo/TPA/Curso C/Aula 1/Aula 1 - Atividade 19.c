// 19. Fa�a um programa em C que calcule o valor de uma presta��o em atraso. Para
// isso, o programa deve ler o valor da presta��o vencida, a taxa peri�dica de juros
// e o per�odo de atraso. Ao final, o programa deve imprimir o valor da presta��o
// atrasada, o per�odo de atraso, os juros que ser�o cobrados pelo per�odo de atraso,
// o valor da presta��o acrescido dos juros. Considere juros simples.

#include <stdio.h>
#include <stdlib.h>

void main()
{
	float valor, taxa, periodo, juros, valorJuros;

	printf("Informe o valor da prestacao vencida: ");
	scanf("%f", &valor);

	printf("Informe a taxa periodica de juros(em porcentagem): ");
	scanf("%f", &taxa);

	printf("Informe o periodo de atraso: ");
	scanf("%f", &periodo);

	juros = valor * (taxa / 100) * periodo;

	valorJuros = valor + juros;

	printf("Valor da prestacao atrasada: %.2f\n", valor);
	printf("Periodo de atraso: %.2f\n", periodo);
	printf("Juros que serao cobrados pelo periodo de atraso: %.2f\n", juros);
	printf("Valor da prestaaoo acrescido dos juros: %.2f\n", valorJuros);
}
