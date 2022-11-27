#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

char pilha[N];
int t;
char meuString[N];
char *mstring;

int bemFormada(char s[]);
void criapilha(void);
void empilha(char y);
char desempilha(void);
int pilhavazia(void);
char *infixaParaPosfixa(char *inf);

int main()
{
    strcpy(meuString, "(100 + 90)");
    printf("\n\nTestanto a express?o: %s\n", meuString);
    int resultado = bemFormada(meuString);

    if (resultado == 1)
    {
        printf("\nEXPRESSAO OK.\n\n");
        mstring = infixaParaPosfixa(meuString);
        printf("\nNOTACAO POLONESA:\n\t %s\n\n", mstring);
    }
    else
    {
        printf("\nEXPRESSAO FALHA.\n\n");
    }

    system("PAUSE");
}

// Esta fun??o devolve 1 se a string ASCII s
// cont?m uma sequ?ncia bem-formada de
// par?nteses e colchetes e devolve 0 se
// a sequ?ncia ? malformada.

int bemFormada(char s[])
{
    criapilha();
    for (int i = 0; s[i] != '\0'; ++i)
    {
        char c;
        switch (s[i])
        {
        case ')':
            if (pilhavazia())
                return 0;
            c = desempilha();
            if (c != '(')
                return 0;
            break;
        case ']':
            if (pilhavazia())
                return 0;
            c = desempilha();
            if (c != '[')
                return 0;
            break;
        case '(':
            empilha(s[i]);
            break;
        case '[':
            empilha(s[i]);
            break;
        }
    }
    return pilhavazia();
}

void criapilha(void)
{
    t = 0;
}

void empilha(char y)
{
    pilha[t++] = y;
}

char desempilha(void)
{
    return pilha[--t];
}

int pilhavazia(void)
{
    return t <= 0;
}

// Esta fun??o recebe uma express?o infixa inf
// e devolve a correspondente express?o posfixa.

char *infixaParaPosfixa(char *inf)
{
    int n = strlen(inf);
    char *posf;
    posf = (char *)malloc((n + 1) * sizeof(char));
    criapilha();
    empilha(inf[0]); // empilha '('

    int j = 0;
    for (int i = 1; inf[i] != '\0'; ++i)
    {
        switch (inf[i])
        {
            char x;
        case '(':
            empilha(inf[i]);
            break;
        case ')':
            x = desempilha();
            while (x != '(')
            {
                posf[j++] = x;
                x = desempilha();
            }
            break;
        case '+':
        case '-':
            x = desempilha();
            while (x != '(')
            {
                posf[j++] = x;
                x = desempilha();
            }
            empilha(x);
            empilha(inf[i]);
            break;
        case '*':
        case '/':
            x = desempilha();
            while (x != '(' && x != '+' && x != '-')
            {
                posf[j++] = x;
                x = desempilha();
            }
            empilha(x);
            empilha(inf[i]);
            break;
        default:
            posf[j++] = inf[i];
        }
    }
    posf[j] = '\0';
    return posf;
}