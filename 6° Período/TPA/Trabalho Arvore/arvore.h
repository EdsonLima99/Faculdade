#include <stdio.h>
#include <stdlib.h>

/*Estrutura com nome string do tipo char*/
typedef char string[300];

/*Estrutura da Árvore*/
typedef struct tipoNo
{
    long long matricula;
    string nome;
    struct tipoNo *esq, *dir;
} TNo;