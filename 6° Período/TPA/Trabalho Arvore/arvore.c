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
TNo *criaNo(long long matricula, string *nome)
{
    TNo *novo = (TNo *)malloc(sizeof(TNo));
    novo->matricula = matricula;
    strcpy(novo->nome, (*nome));
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}
// Insere nó na árvore
TNo *insere(TNo **nodo, long long matricula, string *nome)
{
    if ((*nodo) == NULL)
    {
        (*nodo) = criaNo(matricula, nome);
    }
    else if (matricula < (*nodo)->matricula)
    {
        (*nodo)->esq = insere(&(*nodo)->esq, matricula, nome);
    }
    else if (matricula > (*nodo)->matricula)
    {
        (*nodo)->dir = insere(&(*nodo)->dir, matricula, nome);
    }
    else
    {
        printf("\n\tAluno %s com a matricula %lld já existe\n", (*nodo)->nome, (*nodo)->matricula);
    } // if
    return (*nodo);
}
// Insere na arvore, os registros do arquivo
void inserirNaArvore(TNo **nodo)
{
    FILE *arquivo;
    string nome;
    long long matricula = 0;
    int i;

    if ((arquivo = fopen("Lista_Aluno_Matricula_Atual.txt", "r")) == NULL)
        printf("Arquivo nao encontrado!");
    else
    {
        while (!feof(arquivo))
        {
            fgets(nome, sizeof(nome), arquivo);
            fscanf(arquivo, "%lld\n", &matricula);

            insere(nodo, matricula, &nome);
        }
    }
    fclose(arquivo);
}
// Insere novo numero na árvore
void inserir(TNo **nodo)
{
    long long matricula;
    string nome;

    printf("\tInsira a matricula: ");
    scanf("%lld", &matricula);

    getchar();
    printf("\tInsira o nome: ");
    fgets(nome, sizeof(nome), stdin);

    insere(nodo, matricula, &nome);
}
// Remove nó da árvore
TNo *remover(TNo **nodo, long long matricula)
{
    if ((*nodo) == NULL)
    {
        // interrompe
        return NULL;
    }
    else if ((*nodo)->matricula > matricula)
    {
        // desce pela esquerda
        (*nodo)->esq = remover(&(*nodo)->esq, matricula);
    }
    else if ((*nodo)->matricula < matricula)
    {
        // desce pela direita
        (*nodo)->dir = remover(&(*nodo)->dir, matricula);
    }
    else
    {
        // Encontrou Nó a ser removido...
        if ((*nodo)->dir == NULL && (*nodo)->esq == NULL)
        {
            // Nó a ser removido NÂO tem FILHOS.
            free(*nodo);
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
            (*nodo)->matricula = prov->matricula;
            strcpy((*nodo)->nome, prov->nome);
            prov->matricula = matricula;

            (*nodo)->esq = remover(&(*nodo)->esq, matricula);
        }
    }
    return (*nodo);
}
// Remove valor da árvore
void removerValor(TNo **nodo)
{
    long long numero;

    printf("\tInsira o numero: ");
    scanf("%lld", &numero);

    remover(nodo, numero);
}
// Imprime em ordem
void caminhamento_em_ordem(TNo *nodo)
{
    if (nodo != NULL)
    {
        caminhamento_em_ordem(nodo->esq);
        printf("\n\tMatricula: %lld", nodo->matricula);
        printf("\n\tNome: %s", nodo->nome);
        caminhamento_em_ordem(nodo->dir);
    } // if
}
// Imprime em pre ordem
void caminhamento_pre_ordem(TNo *nodo)
{
    if (nodo != NULL)
    {
        printf("\n\tMatricula: %lld", nodo->matricula);
        printf("\n\tNome: %s", nodo->nome);
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
        printf("\n\tMatricula: %lld", nodo->matricula);
        printf("\n\tNome: %s", nodo->nome);
    } // if
}
// Busca nó na árvore
void buscarNo(TNo **nodo, long long procurado)
{
    if ((*nodo) == NULL)
    {
        printf("\n<<VALOR INEXISTENTE NA ARVORE>>\n\n\n");
    }
    else if ((*nodo)->matricula == procurado)
    {
        printf("\n<<ENCONTRADO>>\n\n\n");
        printf("\n\tMatricula: %lld", (*nodo)->matricula);
        printf("\n\tNome: %s", (*nodo)->nome);
    }
    else if ((*nodo)->matricula > procurado)
    {
        printf("\nPROCURADO: %lld\tVISITADO: %lld", procurado, (*nodo)->matricula);
        printf("\n\n... Descendo pela Sub-Arvore ESQUERDA.");
        buscarNo(&(*nodo)->esq, procurado);
    }
    else
    {
        printf("\nPROCURADO: %lld\tVISITADO: %lld", procurado, (*nodo)->matricula);
        printf("\n\n... Descendo pela Sub-Arvore DIREITA.");
        buscarNo(&(*nodo)->dir, procurado);
    }
}
// Busca valor na árvore
void buscaValor(TNo **nodo, long long procurado)
{
    if ((*nodo) == NULL)
    {
        printf("\n\n\tÁrvore VAZIA ... Impossível iniciar busca de %lld.\n\n", procurado);
    }
    else
    {
        printf("\n\n\tIniciando BUSCA pelo valor %lld", procurado);
        printf("\n\n\tVisitando a RAIZ (%lld).\n", (*nodo)->matricula);
        buscarNo(nodo, procurado);
    }
    // system("PAUSE");
}
// Busca valor
void buscar(TNo **nodo)
{
    long long numero;

    printf("\tInsira o numero: ");
    scanf("%lld", &numero);

    buscaValor(nodo, numero);
}
// Salva no arquivo os novos registros da arvore
void salvarRegistros(TNo **nodo, FILE *arquivo)
{
    fprintf(arquivo, "%s%lld\n", (*nodo)->nome,(*nodo)->matricula);
    if ((*nodo)->esq)
        salvarRegistros(&(*nodo)->esq, arquivo);
    if ((*nodo)->dir)
        salvarRegistros(&(*nodo)->dir, arquivo);
}
// Salva no arquivo os novos registros da arvore
void salvar(TNo **nodo)
{
    int i;
    FILE *arquivo;

    arquivo = fopen("Lista_Aluno_Matricula_Atual.txt", "w");

    salvarRegistros(nodo, arquivo);

    fclose(arquivo);

    printf("\n\tArquivo salvo com sucesso!\n");
}
// Opções: Inserir, buscar, remover, imprimir em pre, pos e em ordem
void opcao(TNo **nodo, long long num)
{
    switch (num)
    {
    case 0:
        break;
    case 1:
        inserir(nodo);
        break;
    case 2:
        removerValor(nodo);
        break;
    case 3:
        buscar(nodo);
        break;
    case 4:
        salvar(nodo);
        break;
    case 5:
        caminhamento_pre_ordem(*nodo);
        break;
    case 6:
        caminhamento_em_ordem(*nodo);
        break;
    case 7:
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
        printf("\t1. INSERIR novo aluno\n");
        printf("\t2. REMOVER aluno\n");
        printf("\t3. BUSCAR aluno\n");
        printf("\t4. SALVAR base de dados\n");
        printf("\t5. IMPRIMIR em pre ordem\n");
        printf("\t6. IMPRIMIR em ordem\n");
        printf("\t7. IMPRIMIR em pos ordem\n");

        printf("Escolha a opcao: ");
        scanf("%d", &op);

        opcao(nodo, op);

    } while (op != 0);
}