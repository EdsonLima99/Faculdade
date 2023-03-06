// Faça um programa em C que receba um número inteiro e verifique se este número é
// maior que 20, em caso afirmativo o programa deverá multiplicar o valor por 2 e após
// o cálculo imprimir a mensagem: "Resultado: <valor do resultado>", em que <valor do
// resultado> deve ser substituído pelo resultado do cálculo.

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int num, resul;
    
    printf("Informe o numero: ");
    scanf("%d", &num);

    if (num > 20)
    {
        resul = num * 2;
        printf("Resultado: %d", resul);
    }
}