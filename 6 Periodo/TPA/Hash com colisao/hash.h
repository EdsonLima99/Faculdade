#include <stdio.h>	
#include <stdlib.h>
#include <string.h>
#include <time.h>

//--------------------------------- Definições variáveis --------------------

// tipo Elemento
typedef struct {
    int valor;
} Elemento;

// tipo nó usado na lista encadeada
typedef struct no {
    Elemento *elemento;
    struct no *proximo;
} No;

// tipo lista com um ponteiro para o primeiro nó
typedef struct {
    No *inicio;
    int tam;
} Lista;