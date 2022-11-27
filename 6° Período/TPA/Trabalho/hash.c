#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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