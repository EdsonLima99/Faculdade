#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "hash.h"

#define TAM 40000000

/*Cálculo de tamanho da hash*/
int calcularTamanho(int tamanho)
{
    tamanho = (tamanho / 2) * 1.5;
    return tamanho;
}

/*Ler a quantidade de linhas do arquivo e retorna o cálculo para preencher o tamanho da hash*/
int inicializaTamanho(FILE *arquivo)
{
    int numero[TAM], tamanho = 0;

    if ((arquivo = fopen("Lista_Aluno_Matricula.txt", "r")) == NULL)
        printf("Arquivo nao encontrado!\n");
    else
        while (!feof(arquivo)){
            fscanf(arquivo, "%d", &numero[tamanho]);
            tamanho++;
        }
    fclose(arquivo);
    tamanho++;

    tamanho = calcularTamanho(tamanho);

    return tamanho;
}

/*Inicializa a hash*/
void inicializa(TDados **hash, int tam)
{
    int i;

    for (i = 0; i < tam; i++)
        hash[i] = NULL;
}

//Cálcula o módulo
int calcularMod(long long numero, int tam)
{
    int mod;

    mod = numero % tam;

    return mod;
}

//Busca na lista a matricula e retorna 1 se encontrar e 0 se não encontrar
int buscaLista(TDados **hash, long long numero, int tam)
{
    int posi = calcularMod(numero, tam);
    TDados *lista = hash[posi];

    while (lista != NULL)
    {
        if (numero == lista->matricula)
            return 1; // Se encontrou retorna verdadeiro
        lista = lista->prox;
    }
    return 0;
}

//Insere elemento na lista da tabela hash
void inserirLista(TDados **hash, long long numero, string *nome, int tam)
{
    int pos = calcularMod(numero, tam);
    TDados **lista = &hash[pos];

    if (*lista == NULL)
    {
        *lista = (TDados *)malloc(sizeof(TDados));
        if (*lista == NULL)
        {
            printf("\nErro na alocacao da memoria!");
            exit(1);
        }
        (*lista)->matricula = numero;
        strcpy((*lista)->nome, (*nome));
        (*lista)->prox = NULL;

        printf("\n\tInserido hash[%d]", pos);
    }
    else
    { // Caso ocorrer colisao
        printf("\n\tColisao  hash[%d]", pos);

        TDados *armazena = hash[pos]; // armazena posicao inicial do ponteiro

        while ((*lista)->prox != NULL)
            // Verifica fim da lista caso contenha mais de 2 numeros
            *lista = (*lista)->prox;

        (*lista)->prox = (TDados *)malloc(sizeof(TDados));
        if ((*lista)->prox == NULL)
        {
            printf("\nErro na alocacao da memoria!");
            exit(1);
        }

        *lista = (*lista)->prox;
        (*lista)->matricula = numero;
        strcpy((*lista)->nome, (*nome));
        (*lista)->prox = NULL;

        hash[pos] = armazena; // retornando ponteiro para a posi�ao inicial
    }
}

//Insere na hash, os registros do arquivo
void inserirNaHash(TDados **hash, int tam, FILE *arquivo)
{
    string nome;
    long long numero = 0;
    int i;
    int vetor[13];
    char *c;

    if ((arquivo = fopen("Lista_Aluno_Matricula.txt", "r")) == NULL)
        printf("Arquivo nao encontrado!");
    else
    {
        while (!feof(arquivo))
        {
            fgets(nome, sizeof(nome), arquivo);
            fscanf(arquivo, "%lld\n", &numero);

            int posicao = calcularMod(numero, tam);

            if (hash[posicao] != NULL)
            {
                if (buscaLista(hash, numero, tam))
                {
                    printf("O item %d ja foi cadastrado", numero);
                    return;
                }
            }

            inserirLista(hash, numero, &nome, tam);
        }
    }
    fclose(arquivo);

} // inserirNaHash()

//Insere elemento na lista e verifica se a matrícula já está cadastrada
void inserirElemento(TDados **hash, long long numero, string *nome, int tam)
{
    int posicao = calcularMod(numero, tam);

    if (hash[posicao] != NULL)
    {
        if (buscaLista(hash, numero, tam))
        {
            printf("O item %d ja foi cadastrado", numero);
            return;
        }
    }

    inserirLista(hash, numero, nome, tam);
} // inserirElemento()

//Insere nova matricula e nome na lista
void inserir(TDados **hash, int tam)
{
    long long numero;
    string nome;

    printf("\tInsira a matricula: ");
    scanf("%lld", &numero);

    getchar();
    printf("\tInsira o nome: ");
    fgets(nome, sizeof(nome), stdin);

    inserirElemento(hash, numero, &nome, tam);
}

//Informe o matrícula para busca ou exclusão
long long elementoPergunta()
{
    long long numero;

    printf("\tInforme o numero da matricula: ");
    scanf("%lld", &numero);

    return numero;
}

//Busca na hash a matrícula informada e printa na tela
void busca(TDados **hash, int tam)
{
    long long numero = elementoPergunta();
    int posi = calcularMod(numero, tam);
    int exibe = 0;
    TDados *lista = hash[posi];

    while (lista != NULL)
    {
        if (numero == lista->matricula)
        {
            printf("\n\tHash[%d] -> Matricula: %lld \n\t\tNome: %s", posi, lista->matricula, lista->nome);
            exibe = 1;
        }
        lista = lista->prox;
    }

    if (!exibe)
        printf("\n\tNumero nao existe");
}

//Exclui da hash a matrícula informada
void excluir(TDados **hash, int tam)
{
    long long numero = elementoPergunta();
    int pos = calcularMod(numero, tam);

    if (!buscaLista(hash, numero, tam))
    { // verificando se item pertence a tabela
        printf("\n\tItem nao encontrado\n");
        return;
    }

    TDados **lista = &hash[pos];
    TDados *anterior = *lista;
    TDados *proximo = (*lista)->prox;
    TDados *guarda = hash[pos]; // guardando posicao do ponteiro

    while (*lista != NULL)
    { // la�o percorre lista
        if ((*lista)->matricula == numero)
        { // Se encontrou o item
            if (*lista == anterior)
            { // Se o item esta no inicio
                if ((*lista)->prox == NULL)
                { // Se a lista possui um unico item
                    free(*lista);
                    hash[pos] = NULL;
                }
                else
                {
                    (*lista)->prox = proximo->prox;
                    (*lista)->matricula = proximo->matricula;
                    strcpy((*lista)->nome, proximo->nome);
                    hash[pos] = guarda;
                }
            }
            else
            { // Se o item NAO esta no inicio
                anterior->prox = proximo;
                free(*lista);
                hash[pos] = guarda;
            }
            printf("\n\tMatricula removido\n");
            return;
        } // fim la�o encontrou o item
        anterior = *lista;
        *lista = (*lista)->prox;
        proximo = (*lista)->prox;
    } // fim la�o percorre lista

    hash[pos] = guarda; // retonando ponteiro para posicao inicial
    free(anterior);
    free(proximo);
    free(guarda);
}

// Percorre lista e printa na tela
void percorreLista(TDados **hash, int pos)
{
    TDados *lista = hash[pos];

    while (lista != NULL)
    {
        printf(" Matricula: %lld\n\t\tNome: %s \t\t->", lista->matricula, lista->nome);
        lista = lista->prox;
    }
    printf(" NULL");
}

// Exibe tabela hash
void exibir(TDados **hash, int tam)
{ 
    int i;

    printf("\n");
    for (i = 0; i < tam; i++)
    {
        printf("\n\tHash[%d] ->", i);
        percorreLista(hash, i);
    }
}

//Salva no arquivo os novos registros da tabela hash
void salvar(TDados **hash, int tam)
{
    int i;
    FILE *arquivo;
    TDados *lista;

    arquivo = fopen("Lista_Aluno_Matricula.txt", "w");

    for (i = 0; i < tam; i++)
    {
        lista = hash[i];
        while (lista != NULL)
        {
            fprintf(arquivo, "%s", lista->nome);
            fprintf(arquivo, "%lld\n", lista->matricula);
            lista = lista->prox;
        }
    }
    fclose(arquivo);

    printf("\n\tArquivo salvo com sucesso!\n");
}

//Opções: Inserir, exluir, buscar, exibir(EXTRA) e salvar
void opcao(TDados **hash, int num, int tam)
{
    switch (num)
    {
    case 0:
        break;
    case 1:
        inserir(hash, tam);
        break;
    case 2:
        busca(hash, tam);
        break;
    case 3:
        excluir(hash, tam);
        break;
    case 4:
        exibir(hash, tam);
        break;
    case 5:
        salvar(hash, tam);
        break;
    default:
        printf("\t\nNao existe essa opcao!");
        break;
    }
}

//Menu printado na tela
void menu(TDados **hash, int tam)
{
    int op;
    do
    {
        printf("\n\n----------	|| MENU ||	--------------\n\n");
        printf("\t0. Sair\n");
        printf("\t1. INSERIR na tabela\n");
        printf("\t2. BUSCAR elemento na tabela\n");
        printf("\t3. REMOVER elemento da tabela\n");
        printf("\t4. EXIBIR tabela hash\n");
        printf("\t5. SALVAR tabela hash\n");

        printf("Escolha a opcao: ");
        scanf("%d", &op);

        opcao(hash, op, tam);

    } while (op != 0);
}