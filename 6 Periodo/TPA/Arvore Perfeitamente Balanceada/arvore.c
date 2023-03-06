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
    novo->altura = 0;
    return novo;
}
// Função que verifica e imprime na tela a altura da árvore ou do nó
int altura(TNo **nodo)
{
    if ((*nodo) == NULL)    // Se raiz for nulo
        return -1;          // retorna 0
    return (*nodo)->altura; // Senão usa recursividade
}
// Função que retorna o fator de balanceamento do nó
int balanceamento(TNo **nodo)
{
    if ((*nodo) == NULL)
        return 0;
    return altura(&(*nodo)->esq) - altura(&(*nodo)->dir);
}
// Função que retorna o maior valor entre dois long longeiros (Utilizado pelas rotações)
int maior(int a, int b)
{
    return (a > b) ? a : b;
}
// Função para a rotação da sub-árvore (à direita)
TNo *rotDir(TNo **nodo)
{
    TNo *auxiliarEsquerda = (*nodo)->esq;
    TNo *auxiliarDireita = auxiliarEsquerda->dir;

    // Realizando rotação
    auxiliarEsquerda->dir = (*nodo);
    (*nodo)->esq = auxiliarDireita;

    // Atualizando alturas
    (*nodo)->altura = maior(altura(&(*nodo)->esq), altura(&(*nodo)->dir)) + 1;
    auxiliarEsquerda->altura = maior(altura(&(auxiliarEsquerda)->esq), altura(&(auxiliarEsquerda)->dir)) + 1;

    // Retornando a nova raiz (Raiz alterada)
    return auxiliarEsquerda;
}

// Função para a rotação da sub-árvore (à esquerda)
TNo *rotEsq(TNo **nodo)
{
    TNo *auxiliarDireita = (*nodo)->dir;
    TNo *auxiliarEsquerda = auxiliarDireita->esq;

    // Realizando rotação
    auxiliarDireita->esq = (*nodo);
    (*nodo)->dir = auxiliarEsquerda;

    // Atualizando alturas
    (*nodo)->altura = maior(altura(&(*nodo)->esq), altura(&(*nodo)->dir)) + 1;
    auxiliarDireita->altura = maior(altura(&(auxiliarDireita)->esq), altura(&(auxiliarDireita)->dir)) + 1;

    // Retornando a nova raiz (Raiz alterada)
    return auxiliarDireita;
}
// Insere nó na árvore
TNo *insere(TNo **nodo, int valor)
{
    if ((*nodo) == NULL)
    {
        (*nodo) = criaNo(valor);
    }
    else if (valor < (*nodo)->valor)
    {
        (*nodo)->esq = insere(&(*nodo)->esq, valor);
    }
    else if (valor > (*nodo)->valor)
    {
        (*nodo)->dir = insere(&(*nodo)->dir, valor);
    }
    else
    {
        printf("\n\tValor %d já existe\n", (*nodo)->valor);
        return (*nodo);
    } // if

    /* Passo 2 - Atualiza a altura do novo nó (em relação ao anterior) */
    (*nodo)->altura = maior(altura(&(*nodo)->esq), altura(&(*nodo)->dir)) + 1;

    /* Passo 3 - Declarada uma váriável inteira que tem por objetivo obter o fator de balanceamento deste nó em relação ao anterior(pai) para saber se a arvore ficou desbalanceada*/
    int fb = balanceamento(&(*nodo)); // Verifica o fator de balanceamento

    // Se o novo nó causou desbalanceamento da árvore, será necessário obter o balanceamento por meio de uma das 4 formas (dependendo do caso)

    // Rotação simples à esquerda
    if (fb > 1 && valor < (*nodo)->esq->valor) // Se o fator de balanceamento da Raiz for maior que 1 e o Id informado pelo usuário for menor que o Id que está na Raiz -> Esquerda
        (*nodo) = rotDir(&(*nodo));                // Retorna a Raiz, depois de aplicada a Rotação à Direita(Função)

    // Rotação simples à direita
    if (fb < -1 && valor > (*nodo)->dir->valor)
        (*nodo) = rotEsq(&(*nodo));

    // Rotação dupla à esquerda
    if (fb > 1 && valor > (*nodo)->esq->valor)
    {
        (*nodo)->esq = rotEsq(&(*nodo)->esq);
        (*nodo) = rotDir(&(*nodo));
    }

    // Rotação dupla à direita
    if (fb < -1 && valor < (*nodo)->dir->valor)
    {
        (*nodo)->dir = rotDir(&(*nodo)->dir);
        (*nodo) = rotEsq(&(*nodo));
    } // Fim das rotações

    /* Passo 4 - Retorna a nova Raiz(alterada) */
    return (*nodo);
}
// Insere novo numero na árvore
void inserir(TNo **nodo)
{
    int valor;

    printf("\tInsira a valor: ");
    scanf("%d", &valor);

    insere(nodo, valor);
}
// Remove nó da árvore
TNo *remover(TNo **nodo, int valor)
{
    if ((*nodo) == NULL)
    {
        // interrompe
        return NULL;
    }
    else if ((*nodo)->valor > valor)
    {
        // desce pela esquerda
        (*nodo)->esq = remover(&(*nodo)->esq, valor);
    }
    else if ((*nodo)->valor < valor)
    {
        // desce pela direita
        (*nodo)->dir = remover(&(*nodo)->dir, valor);
    }
    else
    {
        // Encontrou Nó a ser removido...
        if ((*nodo)->dir == NULL && (*nodo)->esq == NULL)
        {
            // Nó a ser removido NÂO tem FILHOS.
            free((*nodo));
            (*nodo) = NULL;
        }
        else if ((*nodo)->esq == NULL)
        {
            // Nó a ser removido tem apenas FILHO à DIREITA.
            TNo *temporario = (*nodo);
            (*nodo) = (*nodo)->dir;
            free(temporario);
        }
        else if ((*nodo)->dir == NULL)
        {
            // Nó a ser removido tem apenas FILHO à ESQUERDA.
            TNo *temporario = (*nodo);
            (*nodo) = (*nodo)->esq;
            free(temporario);
        }
        else
        {
            // Nó tem dois FILHOS.
            TNo *prov = (*nodo)->esq;
            while (prov->dir != NULL)
            {
                prov = prov->dir;
            } // while
            // Trocando os dados entre os nodos ...
            (*nodo)->valor = prov->valor;
            prov->valor = valor;

            (*nodo)->esq = remover(&(*nodo)->esq, valor);
        }
    }

    if ((*nodo) == NULL) // Se a árvore for nula
        return (*nodo);  // Retorna ela própria

    /* Passo 2 - Atualiza a altura do novo nó (em relação ao anterior) */
    (*nodo)->altura = maior(altura(&(*nodo)->esq), altura(&(*nodo)->dir)) + 1;

    /* Passo 3 - Declarada uma váriável inteira que tem por objetivo obter o fator de balanceamento deste nó em relação ao anterior(pai) para saber se a arvore ficou desbalanceada*/
    int fb = balanceamento(&(*nodo));

    // Se o novo nó causou desbalanceamento da árvore, será necessário obter o balanceamento por meio de uma das 4 formas (dependendo do caso)

    // Rotação simples à esquerda
    if (fb > 1 && balanceamento(&(*nodo)->esq) >= 0)
        return rotDir(&(*nodo));

    // Rotação dupla à esquerda
    if (fb > 1 && balanceamento(&(*nodo)->esq) < 0)
    {
        (*nodo)->esq = rotEsq(&(*nodo)->esq);
        return rotDir(&(*nodo));
    }

    // Rotação simples à direita
    if (fb < -1 && balanceamento(&(*nodo)->dir) <= 0)
        return rotEsq(&(*nodo));

    // Rotação dupla à direita
    if (fb < -1 && balanceamento(&(*nodo)->dir) > 0)
    {
        (*nodo)->dir = rotDir(&(*nodo)->dir);
        return rotEsq(&(*nodo));
    }

    return (*nodo);
}
// Remove valor da árvore
void removerValor(TNo **nodo)
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
        printf("\n\tAltura: %d -> %d", nodo->altura, nodo->valor);
        caminhamento_em_ordem(nodo->dir);
    } // if
}
// Imprime em pre ordem
void caminhamento_pre_ordem(TNo *nodo)
{
    if (nodo != NULL)
    {
        printf("\n\tAltura: %d -> %d", nodo->altura, nodo->valor);
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
        printf("\n\tAltura: %d -> %d", nodo->altura, nodo->valor);
    } // if
}
// Busca nó na árvore
void buscarNo(TNo **nodo, int procurado)
{
    if ((*nodo) == NULL)
    {
        printf("\n<<VALOR INEXISTENTE NA ARVORE>>\n\n\n");
    }
    else if ((*nodo)->valor == procurado)
    {
        printf("\n<<ENCONTRADO>>\n\n\n");
    }
    else if ((*nodo)->valor > procurado)
    {
        printf("\nPROCURADO: %d\tVISITADO: %d", procurado, (*nodo)->valor);
        printf("\n\n... Descendo pela Sub-Arvore ESQUERDA.");
        buscarNo(&(*nodo)->esq, procurado);
    }
    else
    {
        printf("\nPROCURADO: %d\tVISITADO: %d", procurado, (*nodo)->valor);
        printf("\n\n... Descendo pela Sub-Arvore DIREITA.");
        buscarNo(&(*nodo)->dir, procurado);
    }
}
// Busca valor na árvore
void buscaValor(TNo **nodo, int procurado)
{
    if ((*nodo) == NULL)
    {
        printf("\n\n\tÁrvore VAZIA ... Impossível iniciar busca de %d.\n\n", procurado);
    }
    else
    {
        printf("\n\n\tIniciando BUSCA pelo valor %d", procurado);
        printf("\n\n\tVisitando a RAIZ (%d).\n", (*nodo)->valor);
        buscarNo(nodo, procurado);
    }
    // system("PAUSE");
}
// Busca valor
void buscar(TNo **nodo)
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
        buscar(nodo);
        break;
    case 3:
        removerValor(nodo);
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