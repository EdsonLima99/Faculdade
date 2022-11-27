// Faça um programa em C que receba um número inteiro e verifique se este número é
// maior que 20, em caso afirmativo o programa deverá imprimir a mensagem: "Maior
// que 20".

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int num;

    printf("Informe o numero: ");
    scanf("%d", &num);

    if (num > 20)
        printf("Maior que 20");
}