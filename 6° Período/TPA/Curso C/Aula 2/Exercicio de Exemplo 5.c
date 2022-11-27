// O hospital local está fazendo uma campanha para receber doação de sangue. O propenso doador deve inicialmente se cadastrar informando o seu nome completo, sua
// idade, seu peso, responder a um breve questionário e apresentar um documento oficial
// com foto. Faça um programa que permita ao hospital realizar o cadastro dos voluntários
// para avaliar a aptidão quanto à doação de sangue. Para estar apto a doar, o voluntário
// deve ter idade entre 16 e 69, pesar pelo menos 50 kg, estar bem alimentado e não estar
// resfriado. O programa deve ler os dados e imprimir no final o nome do voluntário e se
// ele está apto ou não.

#include <stdio.h>
#include <stdlib.h>

void main()
{
    char nome[30];
    int idade, bemAlimentado, resfriado;
    float peso;

    printf("Informe o nome: ");
    scanf("%s", &nome);

    printf("Informe o peso: ");
    scanf("%f", &peso);

    printf("Informe a idade: ");
    scanf("%d", &idade);

    printf("Esta bem alimentado? <1-SIM / 0-NAO>\n");
    scanf("%d", &bemAlimentado);

    printf("Esta resfriado? <1-SIM / 0-NAO>\n");
    scanf("%d", &resfriado);

    if (peso >= 50 && (idade >= 16 && idade <= 69) && bemAlimentado && !resfriado)
        printf("O voluntario %s esta apto!", nome);
    else
        printf("O voluntario %s NAO esta apto", nome);
}