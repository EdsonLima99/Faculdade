// 9. Faça um programa em C que permita entrar com o ano de nascimento da pessoa
// e com o ano atual. O programa deve imprimir a idade da pessoa. Não se esqueça
// de verificar se o ano de nascimento informado é válido.

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int anoNascimento, anoAtual;

    printf("Informe o ano de nascimento: ");
    scanf("%d", &anoNascimento);

    printf("Informe o ano atual: ");
    scanf("%d", &anoAtual);

    if (anoNascimento > 0 && anoNascimento <= anoAtual)
        printf("Voce tem %d ano(s) de idade", (anoAtual - anoNascimento));
    else
        printf("Ano de nascimento ou ano atual invalido");
}