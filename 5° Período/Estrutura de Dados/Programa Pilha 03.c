#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct reg
{
    char conteudo;
    struct reg *prox;
} celula;

typedef struct Pilha
{
    celula *topo;
    int quantidade;
} TPilha;

void criaPilha(TPilha **p);
void empilha(char y, TPilha **p);
char desempilha(TPilha **p);
int pilhaVazia(TPilha *p);

TPilha *pilha = NULL;
char nomeOriginal[100];
char nomeInvertido[100];
char caractere;

int main()
{
    criaPilha(&pilha);
    strcpy(nomeOriginal, "CECILIA NEIDE SOFIA DE SOUZA");
    strcpy(nomeInvertido, "");

    int tamanho = strlen(nomeOriginal);
    int i;
    for (i = 0; i < tamanho; i++)
    {
        empilha(nomeOriginal[i], &pilha);
    } // for

    do
    {
        caractere = desempilha(&pilha);
        nomeInvertido[strlen(nomeInvertido)] = caractere;
        int posicao = strlen(nomeInvertido) + 1;
        nomeInvertido[posicao] = '\0';
    } while (!pilhaVazia(pilha));

    printf("\n\n\tNOME ORIGINAL: %s", nomeOriginal);
    printf("\n\n\tNOME INVERTIDO: %s", nomeInvertido);

    if (strcmp(nomeOriginal, nomeInvertido) == 0)
    {
        printf("\n\nPALINDROMO !!!\n\n");
    }
    else
    {
        printf("\n\nNAO PALINDROMO !!!\n\n");
    }

    system("PAUSE");
}

void criaPilha(TPilha **p)
{
    (*p) = (TPilha *)malloc(sizeof(TPilha));
    (*p)->topo = NULL;
    (*p)->quantidade = 0;
}

void empilha(char y, TPilha **p)
{
    celula *nova;
    nova = (celula *)malloc(sizeof(celula));
    nova->conteudo = y;
    nova->prox = (*p)->topo;
    (*p)->topo = nova;
    (*p)->quantidade++;
}

char desempilha(TPilha **p)
{
    celula *cel;
    cel = (*p)->topo;
    char x = (*p)->topo->conteudo;
    (*p)->topo = (*p)->topo->prox;
    free(cel);
    (*p)->quantidade--;
    return x;
}

int pilhaVazia(TPilha *p)
{
    if (p->topo == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}