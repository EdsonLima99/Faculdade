// Faça um programa em C que leia o destino do passageiro, se a viagem inclui retorno
//(ida e volta) e informe o preço da passagem conforme a tabela a seguir:
// |-----------------------------------------------------------|
// | CÓD. DESTINO |       DESTINO       |  IDA   | IDA E VOLTA |
// |-----------------------------------------------------------|
// |       1      |     Região Norte    | 500,00 |    900,00   |
// |       2      |   Região Nordeste   | 350,00 |    650,00   |
// |       3      | Região Centro-oeste | 350,00 |    600,00   |
// |       4      |      Região Sul     | 300,00 |    550,00   |
// |-----------------------------------------------------------|

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int destino, trecho;

    printf("Informe o destino conforme tabela a seguir: \n");
    printf("1-Regiao Norte \t 3-Regiao Centro-oeste \n");
    printf("2-Regiao Nordeste \t 4-Regiao Sul \n");
    scanf("%d", &destino);

    printf("Informe o trecho: <1-IDA ou 2-IDA E VOLTA>");
    scanf("%d", &trecho);
    
    if (destino == 1)
    {
        if (trecho == 1)
            printf("Regiao norte[IDA] = 500,00");
        else
            printf("Regiao norte[IDA E VOLTA] = 900,00");
    }
    else if (destino == 2)
    {
        if (trecho == 1)
            printf("Regiao nordeste[IDA] = 350,00");
        else
            printf("Regiao nordeste[IDA E VOLTA] = 650,00");
    }
    else if (destino == 3)
    {
        if (trecho == 1)
            printf("Regiao centro-oeste[IDA] = 350,00");
        else
            printf("Regiao centro-oeste[IDA E VOLTA] = 600,00");
    }
    else
    {
        if (trecho == 1)
            printf("Regiao sul[IDA] = 300,00");
        else
            printf("Regiao sul[IDA E VOLTA] = 550,00");
    }
}