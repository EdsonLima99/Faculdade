#include <stdio.h>
#include <stdlib.h>

/*Estrutura da lista*/
typedef struct tipoDados
{
    int numero;
    struct tipoDados *prox;
} TDados;