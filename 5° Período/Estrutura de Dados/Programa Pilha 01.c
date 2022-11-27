#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

char pilha[N];
int t;
char meuString[N];

int bemFormada(char s[]);
void criapilha(void);
void empilha(char y);
char desempilha(void);
int pilhavazia(void);

int main()
{
    strcpy(meuString, "[100 + (25 * 4 / (50 + 101))]");
    printf("\n\nTestanto a express?o: %s\n", meuString);
    int resultado = bemFormada(meuString);

    if (resultado == 1)
    {
        printf("\nEXPRESSAO OK.\n\n");
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
