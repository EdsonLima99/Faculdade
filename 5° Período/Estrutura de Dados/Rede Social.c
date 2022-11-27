// NOME: EDSON LIMA E LAYS PIO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO 9

typedef char string[9];

typedef struct registro
{
    int adjacencia[TAMANHO][TAMANHO];
    string vertices[TAMANHO];
} TRegistro;

TRegistro dados;

void inicializa(TRegistro *d);
void menu(TRegistro *d);
void nomeUsuario(TRegistro *d);
void exibirAmigos(TRegistro *d, string *nome);
void maisRelacionado(TRegistro *d);
void maisSolitario(TRegistro *d);
void recomendacao(TRegistro *d);

int main()
{
    inicializa(&dados);
    menu(&dados);
}

//=====================\ Procedimentos e Funções /===========================//

void inicializa(TRegistro *d)
{
    int l, c;

    strcpy(d->vertices[0], "ANA");
    strcpy(d->vertices[1], "CINTHIA");
    strcpy(d->vertices[2], "PAULA");
    strcpy(d->vertices[3], "JOSE");
    strcpy(d->vertices[4], "CARLOS");
    strcpy(d->vertices[5], "SOFIA");
    strcpy(d->vertices[6], "NEIDE");
    strcpy(d->vertices[7], "ASDRUBAL");
    strcpy(d->vertices[8], "JAMBIRA");

    // Definição da Matriz de Adjacências
    for (l = 0; l < TAMANHO; l++)
    {
        for (c = 0; c < TAMANHO; c++)
        {
            d->adjacencia[l][c] = 0;
        } // for
    }     // for

    d->adjacencia[0][1] = 1; // Ana é amiga de Cínthia
    d->adjacencia[0][2] = 1; // Ana é amiga de Paula
    d->adjacencia[0][3] = 1; // Ana é amiga de José

    d->adjacencia[1][0] = 1; // Cínthia é amiga de Ana
    d->adjacencia[1][4] = 1; // Cínthia é amiga de Carlos

    d->adjacencia[2][0] = 1; // Paula é amiga de Ana
    d->adjacencia[2][4] = 1; // Paula é amiga de Carlos
    d->adjacencia[2][5] = 1; // Paula é amiga de Sofia
    d->adjacencia[2][6] = 1; // Paula é amiga de Neide
    d->adjacencia[2][7] = 1; // Paula é amiga de Asdrúbal

    d->adjacencia[3][0] = 1; // José é amigo de Ana
    d->adjacencia[3][5] = 1; // José é amigo de Sofia

    d->adjacencia[4][1] = 1; // Carlos é amigo de Cínthia
    d->adjacencia[4][2] = 1; // Carlos é amigo de Paula

    d->adjacencia[5][2] = 1; // Sofia é amiga de Paula
    d->adjacencia[5][3] = 1; // Sofia é amiga de José

    d->adjacencia[6][2] = 1; // Neide é amiga de Paula

    d->adjacencia[7][2] = 1; // Asdrúbal é amigo de Paula
    d->adjacencia[7][8] = 1; // Asdrúbal é amigo de Jambira

    d->adjacencia[8][7] = 1; // Jambira é amiga de Asdrúbal
}

void menu(TRegistro *d)
{
    int digita;

    do
    {
        printf("Opcoes: \n");
        printf("0 - Sair\n");
        printf("1 - Amigos de um usuario\n");
        printf("2 - Os 5 usuarios mais bem relacionados\n");
        printf("3 - Os 3 usuarios mais solitarios\n");
        printf("4 - Sugestao de novas amizades\n");
        printf("Informe um valor: ");
        scanf("%d", &digita);

        switch (digita)
        {
        case 0:
            break;
        case 1:
            nomeUsuario(d);
            break;
        case 2:
            maisRelacionado(d);
            break;
        case 3:
            maisSolitario(d);
            break;
        case 4:
            recomendacao(d);
            break;
        default:
            printf("Valor incorreto\n");
        }
    } while (digita != 0);
}

void nomeUsuario(TRegistro *d)
{
    string nome;
    int l;

    printf("\nInforme o nome do usuario: ");
    scanf("%s", &nome);

    exibirAmigos(d, &nome);
}

void exibirAmigos(TRegistro *d, string *nome)
{
    int l, c, encontrado = 0;

    printf("\n\n");
    printf("+==============| INICIO |===========================================================+\n");

    for (l = 0; l < TAMANHO; l++)
    {
        if (strcmp(d->vertices[l], strupr(*nome)) == 0)
        {
            encontrado = 1;

            for (c = 0; c < TAMANHO; c++)
            {
                if (d->adjacencia[l][c] == 1)
                {
                    printf("%s EH AMIGO/A DE %s\n", d->vertices[l], d->vertices[c]);
                }
            } // for
        }     // if
    }         // for

    if (encontrado == 0)
    {
        printf("Nome nao encontrado\n");
    } // if

    printf("+==============| FIM |===========================================================+\n\n");
    system("PAUSE");
}

void maisRelacionado(TRegistro *d)
{
    int l, c, i = 0, cont = 0;
    int qtd[5] = {0, 0, 0, 0, 0};
    char ordemD[5][TAMANHO];

    for (l = 0; l < TAMANHO; l++)
    {
        for (c = 0; c < TAMANHO; c++)
        {
            if (d->adjacencia[l][c] == 1)
                cont += 1;
        }
        if (cont > qtd[i])
        {
            qtd[i + 4] = qtd[i + 3];
            qtd[i + 3] = qtd[i + 2];
            qtd[i + 2] = qtd[i + 1];
            qtd[i + 1] = qtd[i];
            qtd[i] = cont;
            strcpy(ordemD[i + 4], ordemD[i + 3]);
            strcpy(ordemD[i + 3], ordemD[i + 2]);
            strcpy(ordemD[i + 2], ordemD[i + 1]);
            strcpy(ordemD[i + 1], ordemD[i]);
            strcpy(ordemD[i], d->vertices[l]);
        }
        else if (cont > qtd[i + 1])
        {
            qtd[i + 4] = qtd[i + 3];
            qtd[i + 3] = qtd[i + 2];
            qtd[i + 2] = qtd[i + 1];
            qtd[i + 1] = cont;
            strcpy(ordemD[i + 4], ordemD[i + 3]);
            strcpy(ordemD[i + 3], ordemD[i + 2]);
            strcpy(ordemD[i + 2], ordemD[i + 1]);
            strcpy(ordemD[i + 1], d->vertices[l]);
        }
        else if (cont > qtd[i + 2])
        {
            qtd[i + 4] = qtd[i + 3];
            qtd[i + 3] = qtd[i + 2];
            qtd[i + 2] = cont;
            strcpy(ordemD[i + 4], ordemD[i + 3]);
            strcpy(ordemD[i + 3], ordemD[i + 2]);
            strcpy(ordemD[i + 2], d->vertices[l]);
        }
        else if (cont > qtd[i + 3])
        {
            qtd[i + 4] = qtd[i + 3];
            qtd[i + 3] = cont;
            strcpy(ordemD[i + 4], ordemD[i + 3]);
            strcpy(ordemD[i + 3], d->vertices[l]);
        }
        else if (cont > qtd[i + 4])
        {
            qtd[i + 4] = cont;
            strcpy(ordemD[i + 4], d->vertices[l]);
        }
        cont = 0;
    }

    printf("OS 5 USUARIOS MAIS RELACIONADOS:\n");
    for (i = 0; i < 5; i++)
    {
        if (i != 4)
            printf("%s\n", ordemD[i]);
        else
            printf("%s\n\n", ordemD[i]);
    }

    system("PAUSE");
}

void maisSolitario(TRegistro *d)
{
    int l, c, i = 0, contador = 0, quantidade[3] = {0, 0, 0};
    char nome[3][TAMANHO];

    for (l = 0; l < TAMANHO; l++)
    {
        for (c = 0; c < TAMANHO; c++)
        {
            if (d->adjacencia[l][c] == 0)
                contador += 1;
        } // for

        if (contador > quantidade[i])
        {
            quantidade[i + 2] = quantidade[i + 1];
            quantidade[i + 1] = quantidade[i];
            quantidade[i] = contador;
            strcpy(nome[i + 2], nome[i + 1]);
            strcpy(nome[i + 1], nome[i]);
            strcpy(nome[i], d->vertices[l]);
        }
        else if (contador > quantidade[i + 1])
        {
            quantidade[i + 2] = quantidade[i + 1];
            quantidade[i + 1] = contador;
            strcpy(nome[i + 2], nome[i + 1]);
            strcpy(nome[i + 1], d->vertices[l]);
        }
        else if (contador > quantidade[i + 2])
        {
            quantidade[i + 2] = contador;
            strcpy(nome[i + 2], d->vertices[l]);
        }
        contador = 0;
    } // for

    printf("\nOS MAIS SOLITARIOS SAO: \n");

    for (i = 0; i < 3; i++)
    {
        if (i != 2)
            printf("%s\n", nome[i]);
        else
            printf("%s\n\n", nome[i]);
    }

    system("PAUSE");
}

void recomendacao(TRegistro *d)
{
    int l, c, n;

    for (l = 0; l < TAMANHO; l++)
    {
        printf("\n%s\n", d->vertices[l]);
        for (c = 0; c < TAMANHO; c++)
        {
            if (d->adjacencia[l][c] == 1)
            {
                for (n = 0; n < TAMANHO; n++)
                {
                    if (d->adjacencia[c][n] == 1 && l != n)
                        printf("%s PODE SER AMIGO DE %s POR %s SER UMA AMIGO EM COMUM\n", d->vertices[l], d->vertices[n], d->vertices[c]);
                }
            }
        }
    }
    printf("\n");
    system("PAUSE");
}