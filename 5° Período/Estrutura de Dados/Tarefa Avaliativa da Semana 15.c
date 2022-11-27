#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string[50];

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
    struct tipoNo *inicio;
    struct tipoNo *fim;
    struct tipoNodo *raiz;
} TLista;

TLista lista;
TNodo raiz;

void inicializa(TLista *L);
int menu();
TNodo *criaNo(TNo *novo, string dado, string ident, char gen);
TNodo *insereNodo(TNo *novo, TNodo **R, string dado, string ident, char gen);
void insere(TLista *L, string dado, string ident, char gen);
void exibe(TNo *atual);
void mostraLista(TLista *L);
void reordenaPorMatricula(TLista *L);
void reordenaPorNome(TLista *L);
void consultaPorNome(TLista *L);
// void remover(TLista *L);

//==========================================================================================
int main()
{
    int op;
    string pessoa;

    inicializa(&lista);

    insere(&lista, "LAYS SANTOS PIO", "2020122760226", 'F');
    insere(&lista, "EDSON LIMA", "2020122760227", 'M');

    do
    {
        op = menu();
        getchar();

        switch (op)
        {
        case 1:
            break;
        case 2:
            reordenaPorMatricula(&lista);
            break;
        case 3:
            reordenaPorNome(&lista);
            break;
            /*case 4:
            printf("\nInsira o nome:\n");
            gets(pessoa);
            strcpy(pessoa, strupr(pessoa));
            buscaValor(raiz, pessoa);
            break;
            case 5: remover(&lista); break; */
        } // switch

    } while (op != 0);
}
//==========================================================================================
void inicializa(TLista *L)
{
    L->inicio = NULL;
    L->fim = NULL;
    L->raiz = NULL;
    //
    // L->raiz->dir = NULL;
    // L->raiz->esq = NULL;
    // L->raiz->enderecoLista = NULL;
    // L->raiz->nome = NULL;
}
//==========================================================================================
int menu()
{
    int opcao;
    system("CLS"); // Limpa a Tela e posiciona o
                   // CURSOR no canto esquerdo superior da mesma
    printf("\n\n\n\t     =====| MENU |=====\n\n");
    printf("0 - SAIR (Encerrar Programa).\n\n");
    printf("1 - Inserir Pessoa.\n");
    printf("2 - Listar Pessoas por ordem crescente de matrícula.\n");
    printf("3 - Listar Pessoas por ordem crescente alfabética de nome.\n");
    printf("4 - Consultar Pessoa por Nome.\n");
    printf("5 - Remover Pessoa.\n");
    printf("\tInforme OPCAO desejada: ");

    scanf("%d", &opcao);

    if ((opcao > 5) || (opcao < 0))
    {
        printf("\n\n\n");
        printf("\t+-------------------------------------------------+");
        printf("\t|   ERRO:                                         |");
        printf("\t|                                                 |");
        printf("\t|   OPCAO INVALIDA!!!                             |");
        printf("\t|                                                 |");
        printf("\t|   Tente outra vez.                              |");
        printf("\t+-------------------------------------------------+\n\n");
        system("PAUSE");
    }
    return opcao;
}
//==========================================================================================
void insere(TLista *L, string dado, string ident, char gen)
{
    TNo *novo = (TNo *)malloc(sizeof(TNo));
    TNodo *nodo = (TNodo *)malloc(sizeof(TNodo));
    int inserido = 0;

    strcpy(novo->nome, dado);
    strcpy(novo->matricula, ident);
    novo->sexo = gen;

    novo->prox = NULL;

    if (L->inicio == NULL)
    {
        // Lista VAZIA: inserir o primeiro N?.
        L->inicio = novo;
        L->fim = novo;
        nodo->enderecoLista = novo;
        strcpy(nodo->nome, dado);
    }
    else
    {
        // Lista possui pelo menos um N?: Inserir dados em
        // ordem crescente.
        TNo *atual = L->inicio;
        TNo *previo = NULL;
        TNodo *R = L->inicio;

        while (atual != NULL)
        {
            if (strcmp(atual->nome, novo->nome) >= 0)
            {
                inserido = 1;
                novo->prox = atual;

                if (previo == NULL)
                {
                    // Inserir novo no in?cio da Lista
                    L->inicio = novo;
                    R->enderecoLista = novo;
                    strcpy(R->nome, dado);
                }
                else
                {
                    // Inserir novo em algum ponto no meio da Lista
                    previo->prox = novo;
                    R = insereNodo(novo, &R, dado, ident, gen);
                } // if else
                break;
            } // if
            previo = atual;
            atual = atual->prox; // movimenta ponteiro ATUAL para
                                 // o N? SEGUINTE.
        } // while

        if (!inserido)
        {
            // Inserir novo no final da Lista
            L->fim->prox = novo;
            L->fim = novo;
        } // if

    } // if ... else
}
//==========================================================================================
TNodo *criaNo(TNo *novo, string dado, string ident, char gen)
{
    TNodo *R;
    strcpy(R->nome, dado);
    R->enderecoLista = novo;
    R->esq = NULL;
    R->dir = NULL;
    return R;
}
//==========================================================================================
TNodo *insereNodo(TNo *novo, TNodo **R, string dado, string ident, char gen)
{
    if ((*R) == NULL)
    {
        (*R) = criaNo(novo, dado, ident, gen);
    }
    else if (strcmp(dado, (*R)->nome) < 0)
    {
        (*R)->esq = insereNodo(novo, &(*R)->esq, dado, ident, gen);
    }
    else
    {
        (*R)->dir = insereNodo(novo, &(*R)->dir, dado, ident, gen);
    }
    return (*R);
}
//==========================================================================================

void exibe(TNo *atual)
{
    printf("\n\t+-------------------+");
    printf("\n\t%s - %s - %c\n", atual->nome, atual->matricula, atual->sexo);
}
//==========================================================================================
void mostraLista(TLista *L)
{
    TNo *atual = L->inicio;

    printf("\n\n\n");
    printf("\t=====| EXIBE LISTA ORDENADA |=====\n\n");

    while (atual != NULL)
    {
        exibe(atual);
        atual = atual->prox;
    } // while
    printf("\n\n");
    system("PAUSE");
}
//==========================================================================================
void reordenaPorMatricula(TLista *L)
{
    TNo *muda = L->inicio;
    if (muda == NULL || muda->prox == NULL)
        return;
    TNo *aux = muda, *t;
    string dado, ident;
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
                strcpy(dado, aux->nome);
                strcpy(aux->nome, t->nome);
                strcpy(t->nome, dado);

                strcpy(ident, aux->matricula);
                strcpy(aux->matricula, t->matricula);
                strcpy(t->matricula, ident);

                gen = aux->sexo;
                aux->sexo = t->sexo;
                t->sexo = gen;
            }
            t = t->prox;
        }
        aux = aux->prox;
    }
    mostraLista(L);
}
//==========================================================================================
void reordenaPorNome(TLista *L)
{
    TNo *muda = L->inicio;
    if (muda == NULL || muda->prox == NULL)
        return;
    TNo *aux = muda, *t;
    string dado, ident;
    char gen;
    int str;

    while (aux != NULL)
    {
        t = aux->prox;
        while (t != NULL)
        {
            str = strcmp(aux->nome, t->nome);
            if (str > 0)
            {
                strcpy(dado, aux->nome);
                strcpy(aux->nome, t->nome);
                strcpy(t->nome, dado);

                strcpy(ident, aux->matricula);
                strcpy(aux->matricula, t->matricula);
                strcpy(t->matricula, ident);

                gen = aux->sexo;
                aux->sexo = t->sexo;
                t->sexo = gen;
            }
            t = t->prox;
        }
        aux = aux->prox;
    }
    mostraLista(L);
}
//==========================================================================================
/*void remover(TLista *L){
TNo *atual = L->inicio, *previo = NULL, *proximo;
string parametro;
int removido = 0, str;

if(L->inicio == NULL) proximo = NULL;
else proximo = atual->prox;

printf("\n\n\t=====| REMOVER No |=====\n\n");
printf("\tInforme PESSOA a ser REMOVIDA: ");
gets(parametro);

strcpy(parametro, strupr(parametro));

while(atual != NULL){
str = strcmp(atual->nome, parametro);
  if(str == 0) {
   proximo = atual->prox;
   if(previo == NULL) L->inicio = proximo;
   else previo->prox = proximo;

 TNo *nodo;
 removerNodo(nodo, atual->nome, atual->matricula, atual->sexo);
 free(atual);
 L->total--;
 removido = 1;
 break;
  }//if
  previo = atual;
  atual = atual->prox;
  if(atual != NULL) proximo = atual->prox;
  else proximo = NULL;
}//while

if(removido){
printf("\n\n\n");
printf("+--------------------------------------+\n");
printf("|  AVISO:                              |\n");
printf("|                                      |\n");
printf("|  No REMOVIDO com SUCESSO !!!         |\n");
printf("|                                      |\n");
printf("+--------------------------------------+\n\n\n");
system("PAUSE");
} else {
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
*/