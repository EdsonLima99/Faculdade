// Faça um programa em C que leia "n" valores. O programa deve inicialmente solicitar ao
// usuário que informe a quantidade desejada de valores a ser informada, depois ler os
//"n" valores e ao final imprimir a média aritmética dos valores lidos.

#include <stdio.h>
#include <stdlib.h>

void main()
{
    float num, soma = 0, media = 0;
    int qtdNum, i;

    printf("Informe a quantidade de numeros: ");
    scanf("%d", &qtdNum);

    // inicio do laco for
    for (i = 1; i <= qtdNum; i++)
    {
        // a partir deste ponto sao as instrucoes
        // que devem ser executadas nas iteracoes
        printf("Informe o numero: ");
        scanf("%f", &num);
        
        soma += num;
    }
    // a media deve ser calculada apos a iteracao
    media = soma / qtdNum;
    printf("A media e: %.2f", media);
}