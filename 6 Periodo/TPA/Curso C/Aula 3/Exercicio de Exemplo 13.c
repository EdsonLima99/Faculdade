// Uma transportadora utiliza caminhões que suportam até 10 toneladas de peso, as caixas
// transportadas tem tamanho fixo e o caminhão comporta no máximo 200 volumes,
// assim, esta transportadora precisa controlar a quantidade e o peso dos volumes para
// acomodar nos caminhões. Faça um programa que leia n caixas e seu peso, ao final, o
// programa deve imprimir a quantidade de volumes, o peso total dos volumes e o peso
// médio dos volumes.

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int resp, qtdVolumes = 0;
    float peso, pesoTotal = 0, pesoMedio = 0;

    printf("Deseja cadastrar uma caixa? 1-SIM / 2-NAO\n");
    scanf("%d", &resp);

    while (resp == 1)
    {
        qtdVolumes++;

        printf("Informe o peso da caixa: ");
        scanf("%f", &peso);

        pesoTotal += peso;

        printf("Deseja cadastrar uma caixa? 1-SIM / 2-NAO\n");
        scanf("%d", &resp);
    }
    pesoMedio = pesoTotal / qtdVolumes;

    printf("Quantidade de volumes: %d\n", qtdVolumes);
    printf("Peso total dos volumes: %.2f\n", pesoTotal);
    printf("Peso medio dos volumes: %.2f\n", pesoMedio);
}