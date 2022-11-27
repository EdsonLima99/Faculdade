#include <stdio.h>
#include <stdlib.h>

/*Estrutura da Árvore*/
typedef struct tipoNo
{
    int valor;
    struct tipoNo *esq, *dir;
    int altura;
} TNo;