// Uma agência bancária de uma cidade do interior tem, no máximo, 10 mil clientes. Criar
// um programa em C que possa entrar com o número da conta, o nome e o saldo de cada
// cliente. Imprimir todas as contas, os respectivos saldos e uma das mensagens: positivo
// / negativo. A digitação acaba quando se digita -999 para número da conta ou quando
// chegar a 10 mil clientes. Ao final, deverá sair o total de clientes com saldo negativo, o
// total de clientes da agência e o saldo da agência.

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int conta, cTotNeg = 0, cTot = 0;
    float saldo, soma = 0;
    char nome[30];

    printf("Digite o numero da conta ou -999 para terminar: ");
    scanf("%d", &conta);

    while (conta > 0 && cTot < 10000)
    {
        cTot++;

        printf("Nome: ");
        scanf("%s", &nome);

        printf("Saldo: ");
        scanf("%f", &saldo);

        soma += saldo;

        if (saldo < 0)
        {
            cTotNeg++;
            printf("%d - %.2f - negativo \n", conta, saldo);
        }
        else
        {
            printf("%d - %.2f - positivo \n", conta, saldo);
        }

        printf("Digite o numero da conta ou -999 para terminar: ");
        scanf("%d", &conta);
    }

    printf("\n Total de clientes com saldo negativo: %d", cTotNeg);
    printf("\n Total de clientes da agencia: %d", cTot);
}