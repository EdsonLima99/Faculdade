#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string[40];

typedef struct tipoNo
{
    string nome;
    char sexo;
    float salario;
    struct tipoNo *prox;
} TNo;

typedef struct tipoLista
{
    int total;
    TNo *inicio;
    TNo *fim;
} TLista;

TLista lista;

void inicializa(TLista *L);
int menu();
void insere(TLista *L);
void exibe(TNo *atual);
void mostraLista(TLista *L);
void remover(TLista *L);
void reordenarPorSalario(TLista *L);
void reordenarPorNome(TLista *L);

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
            mostraLista(&lista);
            break;
        case 3:
            remover(&lista);
            break;
        case 4:
            reordenarPorSalario(&lista);
            break;
        case 5:
            reordenarPorNome(&lista);
        } // switch

    } while (op != 0);
}

void inicializa(TLista *L)
{
    L->inicio = NULL;
    L->fim = NULL;
    L->total = 0;
}

int menu()
{
    int opcao;
    system("CLS"); // Limpa a Tela e posiciona o
                   // CURSOR no canto esquerdo superior da mesma
    printf("\n\n\n\t     =====| MENU |=====\n\n");
    printf("0 - SAIR (Encerrar Programa).\n\n");
    printf("1 - Inserir.\n");
    printf("2 - Exibir Lista Completa.\n");
    printf("3 - Excluir.\n");
    printf("4 - Ordenar por Salário.\n");
    printf("5 - Ordenar por Nome.\n\n");
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

void insere(TLista *L)
{
    TNo *novo = (TNo *)malloc(sizeof(TNo));
    int inserido = 0;

    printf("\n\n\n");
    printf("\t=====| INSERE NOVO NO |=====\n\n");
    printf("Informe o NOME: ");
    fgets(novo->nome, sizeof(novo->nome), stdin);

    printf("Informe o SEXO (M ou F): ");
    scanf("%c", &novo->sexo);
    
    do
    {
        printf("Informe o SALARIO: ");
        scanf("%f", &novo->salario);
    } while (novo->salario < 0);

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
            if (atual->salario >= novo->salario)
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

    L->total++;
}

void exibe(TNo *atual)
{
    printf("\n+-------------------+");
    printf("\n\tNome: %s", atual->nome);
    printf("\tSexo: %c", atual->sexo);
    printf("\n\tSalario: %.2f", atual->salario);
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

    while (atual != NULL)
    {
        if (strcmp(atual->nome, parametro) == 0)
        {
            proximo = atual->prox;
            if (previo == NULL)
                L->inicio = proximo;
            else
                previo->prox = proximo;

            free(atual);
            L->total--;
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

void reordenarPorSalario(TLista *L){
    TNo *muda = L->inicio;
	if(muda == NULL || muda->prox == NULL)
	    return;
	TNo *aux = muda, *t;
	string dado;
    char gen;
	int conta;
	
	while(aux != NULL){
	    t = aux->prox;
	    while(t != NULL){
	        if(aux->salario > t->salario){
	            strcpy(dado, aux->nome);
	            strcpy(aux->nome, t->nome);
	            strcpy(t->nome, dado);
	            
	            gen = aux->sexo;
	            aux->sexo = t->sexo;
	            t->sexo = gen;
	            
	            conta = aux->salario;
	            aux->salario = t->salario;
	            t->salario = conta;
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
                strcpy(dado, aux->nome);
                strcpy(aux->nome, t->nome);
                strcpy(t->nome, dado);

                gen = aux->sexo;
                aux->sexo = t->sexo;
                t->sexo = gen;

                conta = aux->salario;
                aux->salario = t->salario;
                t->salario = conta;
            }
            t = t->prox;
        }
        aux = aux->prox;
    }
}