// Segundo uma tabela médica, o peso ideal está relacionado com a altura e o sexo. Faça
// um programa em C que receba a altura e o sexo de uma pessoa, após isso calcule e
// imprima o seu peso ideal, utilizando as seguintes fórmulas:
//• Para homens: (72,7 * A) – 58
//• Para mulheres: (62,1 * A) – 44,7
//• Em que:
//     A = Altura

#include <stdio.h>
#include <stdlib.h>

void main()
{
    float altura, pesoIdeal;
    char sexo;

    printf("Informe a altura: ");
    scanf("%f", &altura);

    printf("Informe o sexo: <M ou F>\n");
    scanf("%s", &sexo);
    
    if (sexo == 'm' || sexo == 'M')
        pesoIdeal = (72.7 * altura) - 58;
    else
        pesoIdeal = (62.1 * altura) - 44.7;
    printf("O peso ideal e: %.2f", pesoIdeal);
}