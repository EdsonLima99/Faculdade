// Inserir, Remover, Imprimir e Buscar
// CLARISSE DINIZ SILVA

#include "hash.h"

// cria e retorna um tipo Elemento
Elemento *criarElemento()
{
    Elemento *e = malloc(sizeof(Elemento));
    printf("Digite o valor: ");
    scanf("%d", &e->valor);
    return e;
}

// imprime um elemento
void imprimirElemento(Elemento *e)
{
    printf("\tValor: %d\n", e->valor);
}

// cria uma lista vazia e retorna seu endere�o na mem�ria
Lista *criarLista()
{
    Lista *l = malloc(sizeof(Lista));
    l->inicio = NULL;
    l->tam = 0;
    return l;
}

/*
    inserir no in�cio da lista
    PAR�METROS
    e - novo elemento a ser inserido
    *lista - endere�o de uma lista encadeada.
*/
void inserirFim(Elemento *e, Lista *lista)
{
    No *novo = malloc(sizeof(No));
    novo->elemento = e;
    novo->proximo = NULL;
    if (lista->inicio == NULL)
    {
        lista->inicio = novo;
    }
    else
    {
        No *ultimo = lista->inicio;
        while (ultimo->proximo != NULL)
        {
            ultimo = ultimo->proximo;
        }
        ultimo->proximo = novo;
    }
    lista->tam++;
}

// Buscar elementos dentro da lista
No *buscarNo(int val, No *inicio)
{

    while (inicio != NULL)
    {
        if (inicio->elemento->valor == val)
            return inicio;
        else
            inicio = inicio->proximo;
    }
    return NULL;
}

void imprimirLista(No *inicio)
{
    while (inicio != NULL)
    {
        imprimirElemento(inicio->elemento);
        inicio = inicio->proximo;
    }
}
//---------------------------------- fim fun��es lista -------------------------

// inicializa a tabela com uma lista vazia em cada posi��o do vetor
void inicializar(Lista **tabela, int tamanho)
{
    int i;

    for (i = 0; i < tamanho; i++)
        tabela[i] = criarLista();
}

// Fun��o para calcular o mod
int funcaoEspalhamento(Lista **tabela, int valor, int tamanho)
{
    return valor % tamanho;
}

// Cria��o do elemento e inser��o na tabela
void inserirTabela(Lista **tabela, int tamanho)
{
    Elemento *elem = criarElemento();
    int indice = funcaoEspalhamento(tabela, elem->valor, tamanho);

    // Verificar se o elemento já existe na lista encadeada
    No *no = buscarNo(elem->valor, tabela[indice]->inicio);
    if (no)
    {
        printf("O elemento %d já existe na tabela.\n", elem->valor);
        free(elem);
    }
    else
    {
        // Adicionar o elemento na próxima posição da lista encadeada
        inserirFim(elem, tabela[indice]);
        printf("Elemento %d adicionado à tabela.\n", elem->valor);
    }
}

// Fun��o de buscar elementos na tabela
Elemento *buscarElementoTabela(Lista **tabela, int valor, int tamanho)
{
    int indice = funcaoEspalhamento(tabela, valor, tamanho);
    No *no = buscarNo(valor, tabela[indice]->inicio);
    if (no)
        return no->elemento;
    else
        return NULL;
}

// Excluir elementos da lista
void removerElementoTabela(Lista **tabela, int valor, int tamanho)
{
    // Achar índice do número a ser removido
    int indice = funcaoEspalhamento(tabela, valor, tamanho);

    Lista *lista = tabela[indice];
    No *no = lista->inicio;
    No *aux = NULL;
    Elemento *elemento = NULL;

    if (no != NULL)
    {
        elemento = no->elemento;

        if (elemento->valor == valor)
        {
            aux = no;
            no = no->proximo;
            lista->inicio = no;
            lista->tam--;
            printf("\nElemento removido: %d", aux->elemento->valor);
            free(aux);
        }
        else
        {
            aux = no->proximo;
            No *anterior = no;

            while ((aux != NULL) && (aux->elemento->valor != valor))
            {
                anterior = aux;
                aux = aux->proximo;
            }

            if (aux != NULL)
            {
                anterior->proximo = aux->proximo;
                lista->inicio = no;
                lista->tam--;
                printf("\nElemento removido: %d", aux->elemento->valor);
                free(aux);
            }
            else
            {
                printf("\nElemento nao encontrado\n");
            }
        }
    }
    else
    {
        printf("\nElemento nao encontrado\n");
    }
}

// Imprimir a tabela. Cada posi��o com todos os valores que est�o nela;
void imprimirTabela(Lista **tabela, int tamanho)
{
    int i;
    printf("\n---------------------TABELA-------------------------\n");
    for (i = 0; i < tamanho; i++)
    {
        printf("%d Lista tamanho: %d\n", i, tabela[i]->tam);
        imprimirLista(tabela[i]->inicio);
    }
    printf("---------------------FIM TABELA-----------------------\n");
}

// Ler o arquivo e contar o número de elementos
int contarElementosArquivo()
{
    FILE *arquivo = fopen("arquivo.txt", "r");
    int contador = 0;
    int valor;

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return 0;
    }

    while (fscanf(arquivo, "%d", &valor) == 1)
    {
        contador++;
    }

    fclose(arquivo);

    return contador * 1.5;
}

void salvarElementosArquivo(Lista **tabela, int tamanho)
{
    FILE *arquivo;
    int i;

    arquivo = fopen("arquivo.txt", "w");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    for (i = 0; i < tamanho; i++)
    {
        No *atual = tabela[i]->inicio;
        while (atual != NULL)
        {
            fprintf(arquivo, "%d\n", atual->elemento->valor);
            atual = atual->proximo;
        }
    }

    printf("Elementos salvos no arquivo\n");

    fclose(arquivo);
}

void lerArquivo(Lista **tabela, int tamanho)
{
    FILE *arquivo;
    int valor;

    // Abrir o arquivo em modo de leitura
    arquivo = fopen("arquivo.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return;
    }

    // Ler os valores inteiros do arquivo, um por vez
    while (fscanf(arquivo, "%d", &valor) != EOF)
    {
        // Inserir cada valor lido na tabela
        Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
        novo->valor = valor;
        int indice = funcaoEspalhamento(tabela, novo->valor, tamanho);

        // Verificar se o elemento já existe na lista encadeada
        No *no = buscarNo(novo->valor, tabela[indice]->inicio);
        if (no)
        {
            printf("O elemento %d já existe na tabela.\n", novo->valor);
            free(novo);
        }
        else
        {
            // Adicionar o elemento na próxima posição da lista encadeada
            inserirFim(novo, tabela[indice]);
            printf("Elemento %d adicionado à tabela.\n", novo->valor);
        }
    }

    // Fechar o arquivo
    fclose(arquivo);
}