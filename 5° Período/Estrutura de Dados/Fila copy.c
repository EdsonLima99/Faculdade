#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO 40

typedef struct elem
{
    char nome[TAMANHO];
    int prioridade;
    struct elem *prox;
} tipo_elem;

typedef struct fila
{
    struct elem *inicio;
    struct elem *fim;
    int quantidade;
} tipo_fila;

void menu(tipo_fila *f);
void criarFila(tipo_fila *f);
void inserirElem(tipo_fila *f);
void inserir(tipo_fila *f, char *pessoa, int num);
void removerPrioridade(tipo_fila *f, tipo_elem *atual, int prioridade);
void remover(tipo_fila *f);
void exibir(tipo_fila *f);
void exibirMuitos(tipo_fila *f);

tipo_fila queue;

void main()
{
    criarFila(&queue);
    menu(&queue);
}

void menu(tipo_fila *f)
{
    int digita;

    do
    {
        printf("Opcoes: \n");
        printf("0 - Sair\n");
        printf("1 - Inserir na Fila\n");
        printf("2 - Remover da Fila\n");
        printf("3 - Exibir Fila\n");
        printf("4 - Exibir os 6 Proximos Elementos a Serem Atendidos\n");
        printf("Informe um valor: ");
        scanf("%d", &digita);
        getchar();

        switch (digita)
        {
        case 0:
            break;
        case 1:
            inserirElem(f);
            break;
        case 2:
            remover(f);
            break;
        case 3:
            exibir(f);
            break;
        case 4:
            exibirMuitos(f);
            break;
        default:
            printf("Valor incorreto\n");
        }
    } while (digita != 0);
}

void criarFila(tipo_fila *f)
{
    f->inicio = NULL;
    f->fim = NULL;
    f->quantidade = 0;
}

void inserirElem(tipo_fila *f)
{
    char nome[40];
    int num;

    printf("\nNome do cliente: ");
    gets(nome);

    do
    {
        printf("Prioridade(1-2-3): ");
        scanf("%d", &num);
    } while (num < 1 || num > 3);

    inserir(f, nome, num);
}

void inserir(tipo_fila *f, char *nome, int num)
{
    tipo_elem *novo = (tipo_elem *)malloc(sizeof(tipo_elem));
    strcpy(novo->nome, nome);
    novo->prioridade = num;
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
    f->quantidade += 1;
    printf("\n");
}

void remover(tipo_fila *f)
{
    int qtd = 0;
    tipo_elem *aux = NULL;

    if (f->inicio == NULL)
        printf("\n\tFila vazia\n\n");
    else
    {
        printf("\n\n\t===| ELEMENTO REMOVIDO DA FILA |===\n\n");
        tipo_elem *atual = f->inicio;

        while (atual != NULL && f->quantidade > (f->quantidade - 1))
        {
            while (atual != NULL && qtd == 0)
            {
                if (atual->prioridade == 1 && qtd == 0)
                {
                    aux = atual;

                    printf("%s - %d\n", aux->nome, aux->prioridade);
                    atual->prioridade = 0;
                    f->quantidade--;
                    qtd = 1;
                }
                atual = atual->prox;
            }
            atual = f->inicio;
            while (atual != NULL && qtd == 0)
            {
                if (atual->prioridade == 2 && qtd == 0)
                {
                    f->inicio = atual->prox;
                    printf("\n\n\t===| ELEMENTO REMOVIDO DA FILA |===\n\n");
                    printf("%s - %d\n", atual->nome, atual->prioridade);
                    atual->prioridade = 0;
                    f->quantidade--;
                    qtd = 1;
                }
                atual = atual->prox;
            }
            atual = f->inicio;
            while (atual != NULL && qtd == 0)
            {
                if (atual->prioridade == 3 && qtd == 0)
                {
                    f->inicio = atual->prox;
                    printf("\n\n\t===| ELEMENTO REMOVIDO DA FILA |===\n\n");
                    printf("%s - %d\n", atual->nome, atual->prioridade);
                    atual->prioridade = 0;
                    f->quantidade--;
                    qtd = 1;
                }
                atual = atual->prox;
            }
            atual = f->inicio;
        }

        if (f->quantidade == 0)
        {
            printf("\nNão há mais elementos\n\n");
            f->inicio = NULL;
            f->fim = NULL;
        }
        free(atual);
        free(aux);
    }
}

void exibir(tipo_fila *f)
{
    printf("\n\n\t===| FILA |===\n\n");

    tipo_elem *atual = f->inicio;
    int cont = 0;

    while (atual != NULL)
    {
        printf("(%d) - Nome: %s - Prioridade: %d\n", ++cont, atual->nome, atual->prioridade);
        atual = atual->prox;
    }
    printf("\n");
    // system("PAUSE");
}

void exibirMuitos(tipo_fila *f)
{
    printf("\n\n\t===| FILA DOS 6 PROXIMOS|===\n\n");

    tipo_elem *aux = f->inicio;
    int i = 1, qtd = 0;

    if (f->inicio == NULL)
        printf("\nFila Vazia\n\n");

    while (aux != NULL && qtd < 6)
    {
        if (aux->prioridade == 1)
        {
            printf("(%d) - Nome: %s - Prioridade: %d \n", i++, aux->nome, aux->prioridade);
            qtd++;
        }
        aux = aux->prox;
    }

    aux = f->inicio;
    while (aux != NULL && qtd < 6)
    {
        if (aux->prioridade == 2)
        {
            printf("(%d) - Nome: %s - Prioridade: %d \n", i++, aux->nome, aux->prioridade);
            qtd++;
        }
        aux = aux->prox;
    }

    aux = f->inicio;
    while (aux != NULL && qtd < 6)
    {
        if (aux->prioridade == 3)
        {
            printf("(%d) - Nome: %s - Prioridade: %d \n", i++, aux->nome, aux->prioridade);
            qtd++;
        }
        aux = aux->prox;
    }

    if (qtd < 5)
    {
        printf("Não há mais elementos\n\n");
    }
}