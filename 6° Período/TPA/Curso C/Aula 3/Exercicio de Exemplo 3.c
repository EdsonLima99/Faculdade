// Faça um programa em C que imprima todos os valores entre 0 e 100 múltiplos de 10.

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int i;
    
    for (i = 0; i <= 100; i += 10)
    {
        printf("Multiplo de 10: %d \n", i);
    }
}
