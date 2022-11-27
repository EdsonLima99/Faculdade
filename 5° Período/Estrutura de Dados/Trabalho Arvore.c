/*EDSON LIMA E LAYS PIO*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string[40];

typedef struct tipoNo
{
    string matricula;
    string nome;
    char sexo;
    struct tipoNo *prox;
} TNo;

typedef struct tipoNodo
{
    string nome;
    struct tipoNo *enderecoLista;
    struct tipoNodo *esq, *dir;
} TNodo;

typedef struct tipoLista
{
    TNo *inicio;
    TNo *fim;
    TNodo *raiz;
} TLista;

TLista lista;

void inicializa(TLista *L);
int menu();
void insere(TLista *L);
void exibe(TNo *atual);
void mostraLista(TLista *L);
void remover(TLista *L);
void reordenarPorMatricula(TLista *L);
void reordenarPorNome(TLista *L);
TNodo *criaNo(TNo *novo);
TNodo *inserirNodo(TNodo **nodo, TNo *novo);
TNodo *removerNodo(TNodo *nodo, TNo *novo);
void consultar(TLista *L);
void buscaValor(TNodo *nodo, char *procurado);
void busca(TNodo *nodo, char *procurado);

int main()
{
    int op;

    inicializa(&lista);

    do
    {
        op = menu();
        getchar();

        switch (op)
        {
        case 1:
            insere(&lista);
            break;
        case 2:
            reordenarPorMatricula(&lista);
            mostraLista(&lista);
            break;
        case 3:
            reordenarPorNome(&lista);
            mostraLista(&lista);
            break;
        case 4:
            consultar(&lista);
            break;
        case 5:
            remover(&lista);
        } // switch

    } while (op != 0);
}

void inicializa(TLista *L)
{
    L->inicio = NULL;
    L->fim = NULL;
    L->raiz = NULL;
}

int menu()
{
    int opcao;
    system("CLS"); // Limpa a Tela e posiciona o
    //  CURSOR no canto esquerdo superior da mesma
    printf("\n\n\n\t     =====| MENU |=====\n\n");
    printf("0 - SAIR (Encerrar Programa).\n\n");
    printf("1 - Inserir Pessoa.\n");
    printf("2 - Listar Pessoas por ordem crescente de matricula.\n");
    printf("3 - Listar Pessoas por ordem crescente alfabética de nome.\n");
    printf("4 - Consultar Pessoa por Nome.\n");
    printf("5 - Remover Pessoa.\n\n");
    printf("\tInforme OPCAO desejada: ");

    scanf("%d", &opcao);

    if ((opcao > 5) || (opcao < 0))
    {
        printf("\n\n\n");
        printf("\n\t+-------------------------------------------------+");
        printf("\n\t|   ERRO:                                         |");
        printf("\n\t|                                                 |");
        printf("\n\t|   OPCAO INVALIDA!!!                             |");
        printf("\n\t|                                                 |");
        printf("\n\t|   Tente outra vez.                              |");
        printf("\n\t+-------------------------------------------------+\n\n");
        system("PAUSE");
    }
    return opcao;
}

void insere(TLista *L)
{
    TNo *novo = (TNo *)malloc(sizeof(TNo));
    int inserido = 0;

    printf("\n\n\n");
    printf("\t=====| INSERE NOVO NO |=====\n\n");
    printf("\tInforme a MATRICULA: ");
    fgets(novo->matricula, sizeof(novo->matricula), stdin);

    printf("\tInforme o NOME: ");
    fgets(novo->nome, sizeof(novo->nome), stdin);

    do
    {
        printf("\tInforme o SEXO (M ou F): ");
        fscanf(stdin, " %c", &novo->sexo);
        strcpy(&novo->sexo, strupr(&novo->sexo));
    } while (novo->sexo != 'F' && novo->sexo != 'M');

    strcpy(novo->matricula, strupr(novo->matricula));
    strcpy(novo->nome, strupr(novo->nome));

    novo->prox = NULL;

    if (L->inicio == NULL)
    {
        // Lista VAZIA: inserir o primeiro N�.
        L->inicio = novo;
        L->fim = novo;
    }
    else
    {
        // Lista possui pelo menos um N�: Inserir dados em
        // ordem crescente.
        TNo *atual = L->inicio;
        TNo *previo = NULL;

        while (atual != NULL)
        {
            if (strcmp(atual->nome, novo->nome) == 1)
            {
                inserido = 1;
                novo->prox = atual;

                if (previo == NULL)
                {
                    // Inserir novo no in�cio da Lista
                    L->inicio = novo;
                }
                else
                {
                    // Inserir novo em algum ponto no meio da Lista
                    previo->prox = novo;
                } // if else
                break;
            } // if
            previo = atual;
            atual = atual->prox; // movimenta ponteiro ATUAL para
                                 // o N� SEGUINTE.
        }                        // while

        if (!inserido)
        {
            // Inserir novo no final da Lista
            L->fim->prox = novo;
            L->fim = novo;
        } // if

    } // if ... else

    inserirNodo(&L->raiz, novo);
}

void exibe(TNo *atual)
{
    printf("\n+-------------------+");
    printf("\n\tMatricula: %s", atual->matricula);
    printf("\tNome: %s", atual->nome);
    printf("\tSexo: %c\n", atual->sexo);
}

void mostraLista(TLista *L)
{
    TNo *atual = L->inicio;

    printf("\n\n\n");
    printf("\t=====| EXIBE LISTA COMPLETA |=====\n\n");

    while (atual != NULL)
    {
        exibe(atual);
        atual = atual->prox;
    } // while
    printf("\n\n");
    system("PAUSE");
}

void remover(TLista *L)
{
    TNo *atual = L->inicio, *previo = NULL, *proximo;
    string parametro;
    int removido = 0;

    if (L->inicio == NULL)
        proximo = NULL;
    else
        proximo = atual->prox;

    printf("\n\n\t=====| REMOVER No |=====\n\n");
    printf("\tInforme o NOME a ser REMOVIDO: ");
    fgets(parametro, sizeof(parametro), stdin);

    strcpy(parametro, strupr(parametro));

    while (atual != NULL)
    {
        if (strcmp(atual->nome, parametro) == 0)
        {
            proximo = atual->prox;
            if (previo == NULL)
                L->inicio = proximo;
            else
                previo->prox = proximo;
            L->raiz = removerNodo(L->raiz, atual);
            if(atual == L->fim)
                L->fim = previo;
            free(atual);
            removido = 1;
            break;
        } // if
        previo = atual;
        atual = atual->prox;
        if (atual != NULL)
            proximo = atual->prox;
        else
            proximo = NULL;
    } // while

    if (removido)
    {
        printf("\n\n\n");
        printf("+--------------------------------------+\n");
        printf("|  AVISO:                              |\n");
        printf("|                                      |\n");
        printf("|  No REMOVIDO com SUCESSO !!!         |\n");
        printf("|                                      |\n");
        printf("+--------------------------------------+\n\n\n");
        system("PAUSE");
    }
    else
    {
        printf("\n\n\n");
        printf("+--------------------------------------+\n");
        printf("|  ALERTA:                             |\n");
        printf("|                                      |\n");
        printf("|  No NAO ENCONTRADO e nem REMOVIDO!!! |\n");
        printf("|                                      |\n");
        printf("+--------------------------------------+\n\n\n");
        system("PAUSE");
    }
}

void reordenarPorMatricula(TLista *L)
{
    TNo *muda = L->inicio;
    if (muda == NULL || muda->prox == NULL)
        return;
    TNo *aux = muda, *t;
    string dado, matricula;
    char gen;
    int str;

    while (aux != NULL)
    {
        t = aux->prox;
        while (t != NULL)
        {
            str = strcmp(aux->matricula, t->matricula);
            if (str > 0)
            {
                strcpy(matricula, aux->matricula);
                strcpy(aux->matricula, t->matricula);
                strcpy(t->matricula, matricula);

                strcpy(dado, aux->nome);
                strcpy(aux->nome, t->nome);
                strcpy(t->nome, dado);

                gen = aux->sexo;
                aux->sexo = t->sexo;
                t->sexo = gen;
            }
            t = t->prox;
        }
        aux = aux->prox;
    }
}

void reordenarPorNome(TLista *L)
{
    TNo *muda = L->inicio;
    if (muda == NULL || muda->prox == NULL)
        return;
    TNo *aux = muda, *t;
    string dado;
    char gen;
    int str, conta;

    while (aux != NULL)
    {
        t = aux->prox;
        while (t != NULL)
        {
            str = strcmp(aux->nome, t->nome);
            if (str > 0)
            {
                strcpy(dado, aux->matricula);
                strcpy(aux->matricula, t->matricula);
                strcpy(t->matricula, dado);

                strcpy(dado, aux->nome);
                strcpy(aux->nome, t->nome);
                strcpy(t->nome, dado);

                gen = aux->sexo;
                aux->sexo = t->sexo;
                t->sexo = gen;
            }
            t = t->prox;
        }
        aux = aux->prox;
    }
}

TNodo *criaNo(TNo *novo)
{
    TNodo *nodo = (TNodo *)malloc(sizeof(TNodo));
    strcpy(nodo->nome, novo->nome);
    nodo->enderecoLista = novo;
    nodo->esq = NULL;
    nodo->dir = NULL;
    return nodo;
}

TNodo *inserirNodo(TNodo **nodo, TNo *novo)
{
    if ((*nodo) == NULL)
    {
        (*nodo) = criaNo(novo);
    }
    else if (strcmp(novo->nome, (*nodo)->nome) < 0)
    {
        (*nodo)->esq = inserirNodo(&(*nodo)->esq, novo);
    }
    else
    {
        (*nodo)->dir = inserirNodo(&(*nodo)->dir, novo);
    } // if
    return (*nodo);
}

TNodo *removerNodo(TNodo *nodo, TNo *novo)
{
    if (nodo == NULL)
    {
        // interrompe
        return NULL;
    }
    else if (strcmp(novo->nome, nodo->nome) < 0)
    {
        // desce pela esquerda
        nodo->esq = removerNodo(nodo->esq, novo);
    }
    else if (strcmp(novo->nome, nodo->nome) > 0)
    {
        // desce pela direita
        nodo->dir = removerNodo(nodo->dir, novo);
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
            TNodo *temporario = nodo;
            nodo = nodo->dir;
            free(temporario);
        }
        else if (nodo->dir == NULL)
        {
            // Nó a ser removido tem apenas FILHO à ESQUERDA.
            TNodo *temporario = nodo;
            nodo = nodo->esq;
            free(temporario);
        }
        else
        {
            // Nó tem dois FILHOS.
            TNodo *prov = nodo->esq;
            while (prov->dir != NULL)
            {
                prov = prov->dir;
            } // while
            // Trocando os dados entre os nodos ...
            strcpy(nodo->nome, prov->nome);
            strcpy(prov->nome, novo->nome);

            nodo->esq = removerNodo(nodo->esq, novo);
        }
    }
    return nodo;
}

void consultar(TLista *L)
{
    string consulta;

    printf("\n\n\tInforme o nome da PESSOA para consulta: ");
    fgets(consulta, sizeof(consulta), stdin);

    strcpy(consulta, strupr(consulta));

    printf("\n\n\n");
    printf("\t=====| EXIBE CONSULTA |=====\n\n");

    buscaValor(L->raiz, consulta);
}

void buscaValor(TNodo *nodo, char *procurado)
{
    if (nodo == NULL)
    {
        printf("\n\n\tÁrvore VAZIA ... Impossível iniciar busca por %s.\n\n", procurado);
    }
    else
    {
        printf("\n\n\tIniciando BUSCA por %s", procurado);
        printf("\n\n\tVisitando a RAIZ da %s\n", nodo->nome);
        busca(nodo, procurado);
    }
    system("PAUSE");
}

void busca(TNodo *nodo, char *procurado)
{
    if (nodo == NULL)
    {
        printf("\n<<VALOR INEXISTENTE NA ARVORE>>\n\n\n");
    }
    else if (strcmp(nodo->nome, procurado) == 0)
    {
        printf("\n<<ENCONTRADO>>\n\n\n");
        exibe(nodo->enderecoLista);
    }
    else if (strcmp(nodo->nome, procurado) > 0)
    {
        printf("\nPROCURADO: %s\tVISITADO: %s", procurado, nodo->nome);
        printf("\n\n... Descendo pela Sub-Arvore ESQUERDA.");
        busca(nodo->esq, procurado);
    }
    else
    {
        printf("\nPROCURADO: %s\tVISITADO: %s", procurado, nodo->nome);
        printf("\n\n... Descendo pela Sub-Arvore DIREITA.");
        busca(nodo->dir, procurado);
    }
}
