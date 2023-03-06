// Faça um programa em C que leia um número e um expoente, após a leitura, calcule e
// imprima a potência do número lido em relação ao expoente também lido.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
    float base, expoente, potencia;

    printf("Informe a base: ");
    scanf("%f", &base);
    
    printf("Informe o expoente: ");
    scanf("%f", &expoente);

    potencia = pow(base, expoente);
    printf("A potencia do numero e: %.2f \n", potencia);
}