#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stddef.h>
#include "hash.h"

/*Cálcular se o número é primo ou não*/
int numPrimo(int num)
{
    int i, resultado = 0;

    if (num == 1)
    {
        resultado = 1;
    }
    else
    {
        for (i = 2; i <= (num / 2); i++)
        {
            if ((num % i) == 0)
            {
                resultado++;
                break;
            }
        }
    }

    return resultado;
}

/*Cálculo de tamanho da hash*/
int calcularTamanho(int tamanho)
{
    int resultado, i = 0;

    tamanho = tamanho * 1.5;

    do
    {
        resultado = numPrimo(tamanho + i);
        i++;
    } while (resultado != 0);

    tamanho += i - 1;

    return tamanho;
}

/*Ler a quantidade de linhas do arquivo e retorna o cálculo para preencher o tamanho da hash*/
int inicializaTamanho(FILE *arquivo)
{
    int numero, tamanho = 0;

    if ((arquivo = fopen("Lista_Aluno_Matricula.txt", "r")) == NULL)
        printf("Arquivo nao encontrado!\n");
    else
        while (!feof(arquivo))
        {
            fscanf(arquivo, "%d", &numero);
            tamanho++;
        }
    fclose(arquivo);

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

// Cálcula o módulo
int calcularMod(int numero, int tam)
{
    int mod;

    mod = numero % tam;

    return mod;
}

// Busca na lista a numero e retorna 1 se encontrar e 0 se não encontrar
int buscaLista(TDados **hash, int numero, int tam)
{
    int pos = calcularMod(numero, tam);
    TDados *lista = hash[pos];

    while (lista != NULL)
    {
        if (numero == lista->numero)
            return 1; // Se encontrou retorna verdadeiro

        lista = lista->prox;
    }
    return 0;
}

// Insere elemento na lista da tabela hash
void inserirLista(TDados **hash, int numero, int tam)
{
    int rerepos, repos, i = 0, pos = calcularMod(numero, tam);
    TDados **lista = &hash[pos];

    if (*lista == NULL)
    {
        *lista = (TDados *)malloc(sizeof(TDados));
        if (*lista == NULL)
        {
            printf("\nErro na alocacao da memoria!");
            exit(1);
        }
        (*lista)->numero = numero;
        (*lista)->prox = NULL;

        printf("\n\tInserido hash[%d]", pos);
    }
    else
    { // Caso ocorrer colisao
        printf("\n\tColisao  hash[%d]", pos);

        repos = calcularMod(numero, tam - 1) + 1;
        lista = &hash[repos]; // armazena posicao inicial do ponteiro

        if (*lista == NULL)
        {
            *lista = (TDados *)malloc(sizeof(TDados));
            (*lista)->numero = numero;
            (*lista)->prox = NULL;

            printf("\n\tInserido hash[%d]", repos);
        }
        else
        {
            printf("\n\tColisao  hash[%d]", repos);
            do
            {

                rerepos = calcularMod((repos + pos + i), tam);
                lista = &hash[rerepos];
                i++;
                if (*lista != NULL)
                printf("\n\tColisao  hash[%d]", rerepos);
            } while (*lista != NULL);
            *lista = (TDados *)malloc(sizeof(TDados));
            (*lista)->numero = numero;
            (*lista)->prox = NULL;

            printf("\n\tInserido hash[%d]", rerepos);
        }
    }
}

// Insere na hash, os registros do arquivo
void inserirNaHash(TDados **hash, int tam, FILE *arquivo)
{
    int numero = 0, i, vetor[13];

    if ((arquivo = fopen("Lista_Aluno_Matricula.txt", "r")) == NULL)
        printf("Arquivo nao encontrado!");
    else
    {
        while (!feof(arquivo))
        {
            fscanf(arquivo, "%d", &numero);

            int posicao = calcularMod(numero, tam);

            if (hash[posicao] != NULL)
            {
                if (buscaLista(hash, numero, tam))
                {
                    printf("\n\tO item %d ja foi cadastrado", numero);
                    return;
                }
            }
            inserirLista(hash, numero, tam);
        }
    }
    fclose(arquivo);

} // inserirNaHash()

// Insere elemento na lista e verifica se a número já está cadastrada
void inserirElemento(TDados **hash, int numero, int tam)
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

    inserirLista(hash, numero, tam);
} // inserirElemento()

// Insere novo numero na lista
void inserir(TDados **hash, int tam)
{
    int numero;

    printf("\tInsira o numero: ");
    scanf("%d", &numero);

    inserirElemento(hash, numero, tam);
}

// Informe o número para busca ou exclusão
int elementoPergunta()
{
    int numero;

    printf("\tInforme o numero: ");
    scanf("%d", &numero);

    return numero;
}

// Busca na hash o número informado e printa na tela
void busca(TDados **hash, int tam)
{
    int numero = elementoPergunta();
    int posi = calcularMod(numero, tam);
    int exibe = 0, repos = 0, rerepos = 0, i = 0;
    TDados *lista = hash[posi];

    if (numero == lista->numero)
    {
        printf("\n\tHash[%d] -> Numero: %d", posi, lista->numero);
        exibe = 1;
    }
    else
    {
        repos = calcularMod(numero, tam - 1) + 1;
        lista = hash[repos];

        if (numero == lista->numero)
        {
            printf("\n\tHash[%d] -> %d", repos, lista->numero);
            exibe = 1;
        }
        else
        {
            do
            {
                rerepos = calcularMod((repos + posi + i), tam);
                lista = hash[rerepos];
                i++;
            } while (numero != lista->numero);

            if (numero == lista->numero)
            {
                printf("\n\tHash[%d] -> %d", rerepos, lista->numero);
                exibe = 1;
            }
        } // else

    } // else

    if (!exibe)
        printf("\n\tNumero nao existe");
}

// Exclui da hash o número informado
void excluir(TDados **hash, int tam)
{
    int numero = elementoPergunta();
    int pos = calcularMod(numero, tam);
    int repos = 0, rerepos = 0, i = 0;

    // if (!buscaLista(hash, numero, tam))
    // { // verificando se item pertence a tabela
    //     printf("\n\tItem nao encontrado\n");
    //     return;
    // }

    TDados *lista = hash[pos];
    
    if (numero == lista->numero)
    {
        free(lista);
        return;
    }
    else
    {
        repos = calcularMod(numero, tam - 1) + 1;
        lista = hash[repos];

        if (numero == lista->numero)
        {
            free(lista);
            return;
        }
        else
        {
            do
            {
                rerepos = calcularMod((repos + pos + i), tam);
                lista = hash[rerepos];
                i++;
            } while (numero != lista->numero);

            if (numero == lista->numero)
            {
                free(lista);
                return;
            }
        } // else

    } // else
}

// Percorre lista e printa na tela
void percorreLista(TDados **hash, int pos)
{
    TDados *lista = hash[pos];

    while (lista != NULL)
    {
        printf(" Numero: %d\n\t\t->", lista->numero);
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
        TDados *lista = hash[i];

        if (lista != NULL)
        {
            printf("\n\tHash[%d] ->", i);
            percorreLista(hash, i);
        }
    }
}

// Salva no arquivo os novos registros da tabela hash
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
            fprintf(arquivo, "%d\n", lista->numero);
            lista = lista->prox;
        }
    }
    fclose(arquivo);

    printf("\n\tArquivo salvo com sucesso!\n");
}

// Opções: Inserir, exluir, buscar, exibir(EXTRA) e salvar
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

// Menu printado na tela
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