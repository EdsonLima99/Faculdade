// 7. Fa�a um programa em C que leia o nome o endere�o e o telefone de um cliente e
// ao final, imprima esses dados.

#include <stdio.h>
#include <stdlib.h>

void main()
{
	char nome[50], endereco[100], telefone[11];

	printf("Informe o nome: ");
	fgets(nome, 50, stdin);

	printf("Informe o endereco: ");
	fgets(endereco, 100, stdin);

	printf("Informe o telefone(apenas numeros): ");
	fgets(telefone, 11, stdin);

	printf("Nome: %s\n", nome);
	printf("Endereco: %s\n", endereco);
	printf("Telefone: %s", telefone);
}
