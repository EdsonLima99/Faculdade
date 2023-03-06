// Faça um programa em C que calcule a área de um retângulo, para isso o programa deve
// ler a altura e a base. O cálculo deve ser feito em uma função. Após calcular o programa
// deve imprimir o valor da área do retângulo.

#include <stdio.h>
#include <stdlib.h>

float areaRetangulo(float base, float altura)
{
    float area = base * altura;
    return area;
}

void main()
{
    float vbase, valtura, varea;

    printf("Informe a base do retangulo: ");
    scanf("%f", &vbase);
    
    printf("Informe a altura do retangulo: ");
    scanf("%f", &valtura);
    
    varea = areaRetangulo(vbase, valtura);
    
    printf("A area do retangulo e: %.2f \n", varea);
}