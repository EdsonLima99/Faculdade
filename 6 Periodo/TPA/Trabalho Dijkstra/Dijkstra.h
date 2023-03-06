#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANHO 20

typedef char string[20];

typedef struct registro
{
    int caminhos[TAMANHO][TAMANHO];
    string vertices[TAMANHO];
    int estimativas[TAMANHO];
    int precendentes[TAMANHO];
    int finalizado[TAMANHO];
} TRegistro;

void inicializa(TRegistro *d);//Inicializa a estrutura
void busca(int origem, int destino, TRegistro *d);//Busca  a distância entre a origem e o destino
void exibe(TRegistro *d);//Exibe as informações de todos os caminho de uma cidade até todas as outras
int encontreMenorEstimativa(TRegistro *d);//Vértice com menor distância
void geraCaminho(TRegistro *d, int origem, int destino);//Gera caminho da origem até o destino, de baixo pra cima
void menu(TRegistro *d);//Código da origem e do destino para ser calulada
void opcoes(TRegistro *d, int origem, int destino);//Opções se o usuário deseja continuar ou não