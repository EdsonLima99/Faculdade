#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
// Inicializar Árvore
TNo *inicializaArvore(TNo **nodo)
{
    (*nodo) = NULL;
}
// Cria nó na árvore
TNo *criaNo(int valor)
{
    TNo *novo = (TNo *)malloc(sizeof(TNo));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}
// Insere nó na árvore
TNo *insere(TNo **nodo, int valorNovo)
{
    if ((*nodo) == NULL)
    {
        (*nodo) = criaNo(valorNovo);
    }
    else if (valorNovo < (*nodo)->valor)
    {
        (*nodo)->esq = insere(&(*nodo)->esq, valorNovo);
    }
    else
    {
        (*nodo)->dir = insere(&(*nodo)->dir, valorNovo);
    } // if
    return (*nodo);
}
// Insere novo numero na árvore
void inserir(TNo **nodo)
{
    int numero;

    printf("\tInsira o numero: ");
    scanf("%d", &numero);

    insere(nodo, numero);
}
// Remove nó da árvore
TNo *remover(TNo *nodo, int valorNovo)
{
    if (nodo == NULL)
    {
        // interrompe
        return NULL;
    }
    else if (nodo->valor > valorNovo)
    {
        // desce pela esquerda
        nodo->esq = remover(nodo->esq, valorNovo);
    }
    else if (nodo->valor < valorNovo)
    {
        // desce pela direita
        nodo->dir = remover(nodo->dir, valorNovo);
    }
    else
    {
        // Encontrou Nó a ser removido...
        if (nodo->dir == NULL && nodo->esq == NULL)
        {
            // Nó a ser removido NÂO tem FILHOS.
            free(nodo);
            nodo = NULL;
        }
        else if (nodo->esq == NULL)
        {
            // Nó a ser removido tem apenas FILHO à DIREITA.
            TNo *temporario = nodo;
            nodo = nodo->dir;
            free(temporario);
        }
        else if (nodo->dir == NULL)
        {
            // Nó a ser removido tem apenas FILHO à ESQUERDA.
            TNo *temporario = nodo;
            nodo = nodo->esq;
            free(temporario);
        }
        else
        {
            // Nó tem dois FILHOS.
            TNo *prov = nodo->esq;
            while (prov->dir != NULL)
            {
                prov = prov->dir;
            } // while
            // Trocando os dados entre os nodos ...
            nodo->valor = prov->valor;
            prov->valor = valorNovo;

            nodo->esq = remover(nodo->esq, valorNovo);
        }
    }
    return nodo;
}
// Remove valor da árvore
void removerValor(TNo *nodo)
{
    int numero;

    printf("\tInsira o numero: ");
    scanf("%d", &numero);

    remover(nodo, numero);
}
// Imprime em ordem
void caminhamento_em_ordem(TNo *nodo)
{
    if (nodo != NULL)
    {
        caminhamento_em_ordem(nodo->esq);
        printf("\n\t(%d).", nodo->valor);
        caminhamento_em_ordem(nodo->dir);
    } // if
}
// Imprime em pre ordem
void caminhamento_pre_ordem(TNo *nodo)
{
    if (nodo != NULL)
    {
        printf("\n\t(%d).", nodo->valor);
        caminhamento_pre_ordem(nodo->esq);
        caminhamento_pre_ordem(nodo->dir);
    } // if
}
// Imprime em pos ordem
void caminhamento_pos_ordem(TNo *nodo)
{
    if (nodo != NULL)
    {
        caminhamento_pos_ordem(nodo->esq);
        caminhamento_pos_ordem(nodo->dir);
        printf("\n\t(%d).", nodo->valor);
    } // if
}
// Busca valor na árvore
void buscaValor(TNo *nodo, int procurado)
{
    if (nodo == NULL)
    {
        printf("\n\n\tÁrvore VAZIA ... Impossível iniciar busca de %d.\n\n", procurado);
    }
    else
    {
        printf("\n\n\tIniciando BUSCA pelo valor %d", procurado);
        printf("\n\n\tVisitando a RAIZ (%d).\n", nodo->valor);
        buscaValor(nodo, procurado);
    }
    // system("PAUSE");
}
// Busca valor
void buscar(TNo *nodo)
{
    int numero;

    printf("\tInsira o numero: ");
    scanf("%d", &numero);

    buscaValor(nodo, numero);
}
// Opções: Inserir, buscar, remover, imprimir em pre, pos e em ordem
void opcao(TNo **nodo, int num)
{
    switch (num)
    {
    case 0:
        break;
    case 1:
        inserir(nodo);
        break;
    case 2:
        buscar(*nodo);
        break;
    case 3:
        removerValor(*nodo);
        break;
    case 4:
        caminhamento_pre_ordem(*nodo);
        break;
    case 5:
        caminhamento_em_ordem(*nodo);
        break;
    case 6:
        caminhamento_pos_ordem(*nodo);
        break;
    default:
        printf("\t\nNao existe essa opcao!");
        break;
    }
}
// Menu printado na tela
void menu(TNo **nodo)
{
    int op;
    do
    {
        printf("\n\n----------	|| MENU ||	--------------\n\n");
        printf("\t0. Sair\n");
        printf("\t1. INSERIR na arvore\n");
        printf("\t2. BUSCAR na arvore\n");
        printf("\t3. REMOVER da arvore\n");
        printf("\t4. IMPRIMIR em pre ordem\n");
        printf("\t5. IMPRIMIR em ordem\n");
        printf("\t6. IMPRIMIR em pos ordem\n");

        printf("Escolha a opcao: ");
        scanf("%d", &op);

        opcao(nodo, op);

    } while (op != 0);
}