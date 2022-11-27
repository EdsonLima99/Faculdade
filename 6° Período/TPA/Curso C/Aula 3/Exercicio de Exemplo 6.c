// Faça um programa em C que imprima uma matriz de 4 linhas por 4 colunas, sendo que
// na primeira linha devem ser impressos os valores de 1 à 4 e partir da segunda linha, os
// valores impressos devem ser múltiplos da linha anterior.

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int i, j;

    // inicio do laco do primeiro for
    for (i = 1; i <= 4; i++)
    {
        // inicio do laco do segundo for
        for (j = 1; j <= 4; j++)
        {
            if (j < 4)
                printf("%d \t", j * i);
            else
                printf("%d \n", j * i);
        }
    }
}
