// Num frigorífico existem 90 bois. Cada boi traz preso em seu pescoço um cartão contendo
// seu número de identificação e seu peso. Faça um programa que imprima a identificação
// e o peso do boi mais gordo e do boi mais magro (supondo que não haja empates).

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int i, idBoi, idBoiGordo, idBoiMagro;
    float pesoBoi, boiGordo = 0, boiMagro = 0;

    for (i = 1; i <= 90; i++)
    {
        printf("Informe a identificacao do boi: ");
        scanf("%d", &idBoi);

        printf("Informe o peso do boi: ");
        scanf("%f", &pesoBoi);

        if (pesoBoi > boiGordo)
        {
            idBoiGordo = idBoi;
            boiGordo = pesoBoi;
        }
        if (pesoBoi < boiMagro || i == 1)
        {
            idBoiMagro = idBoi;
            boiMagro = pesoBoi;
        }
    }
    printf("Identificacao do boi mais gordo: %d\n", idBoiGordo);
    printf("Peso do boi mais gordo: %.2f\n", boiGordo);
    printf("Identificacao do boi mais magro: %d\n", idBoiMagro);
    printf("Peso do boi mais magro: %.2f\n", boiMagro);
}