#include <stdio.h>
#include <stdlib.h>

#include "arvore.c"

int main()
{
    TNo *raiz;

    inicializaArvore(&raiz);
    
    menu(&raiz);
}