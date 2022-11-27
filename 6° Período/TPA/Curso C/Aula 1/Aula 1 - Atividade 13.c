// 13. Fa�a um programa em C que leia o saldo de uma conta poupan�a e imprima o
// novo saldo, considerando um reajuste de 2%.

#include <stdio.h>
#include <stdlib.h>

void main()
{
	float saldo, reajuste;

	printf("Informe o saldo: ");
	scanf("%f", &saldo);

	reajuste = saldo + (saldo * 0.2);

	printf("Novo saldo: %.2f", reajuste);
}
