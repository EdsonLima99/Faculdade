// Faça um programa em C que receba um número inteiro e verifique se este número é
// maior que 20, em caso afirmativo o programa deverá multiplicar o valor por 2 e em caso
// negativo deve multiplicar por 4. Após realizar o cálculo o programa deve imprimir a
// mensagem: "Resultado: <valor do resultado>", em que <valor do resultado> deve ser
// substituído pelo resultado do cálculo.

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
        // printf("Resultado: %d", resul);
    }
    else
    {
        resul = num * 4;
        // printf("Resultado: %d", resul);
    }
    printf("Resultado: %d", resul);
}
