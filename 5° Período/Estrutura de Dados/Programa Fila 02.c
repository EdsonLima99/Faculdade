#include <stdio.h>
#include <stdlib.h>

typedef struct elem
{
    int info;
    struct elem *prox;
} tipo_elem;

typedef struct fila
{
    struct elem *inicio;
    struct elem *fim;
} tipo_fila;

void criarFila(tipo_fila *f);
void inserir(tipo_fila *f, int numero);
int remover(tipo_fila *f);
void mostrar(tipo_fila *f);

tipo_fila queue;

void main()
{
    criarFila(&queue);

    inserir(&queue, 35);
    inserir(&queue, 45);
    inserir(&queue, 96);
    inserir(&queue, 120);

    mostrar(&queue);

    int nr;
    do
    {
        nr = remover(&queue);
        printf("\n\nRemovido: %d", nr);
    } while (nr != NULL);
    system("PAUSE");
}

void criarFila(tipo_fila *f)
{
    f->inicio = NULL;
    f->fim = NULL;
}

void inserir(tipo_fila *f, int numero)
{
    tipo_elem *novo = (tipo_elem *)malloc(sizeof(tipo_elem));
    novo->info = numero;
    novo->prox = NULL;

    if (f->inicio == NULL)
    {
        f->inicio = novo;
        f->fim = novo;
    }
    else
    {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

int remover(tipo_fila *f)
{
    int resposta;

    if (f->inicio == NULL)
    {
        return NULL;
    }
    else
    {
        tipo_elem *atual = f->inicio;
        f->inicio = atual->prox;
        if (f->inicio == NULL)
            f->fim = NULL;
        resposta = atual->info;
        free(atual);
        return resposta;
    }
}

void mostrar(tipo_fila *f)
{
    printf("\n\n\t===| FILA |===\n\n");

    tipo_elem *atual = f->inicio;
    int cont = 0;

    while (atual != NULL)
    {
        printf("\n(%d) - %d", ++cont, atual->info);
        atual = atual->prox;
    }
    printf("\n\n");
    system("PAUSE");
}