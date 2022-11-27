// 6. A prefeitura do Rio de Janeiro abriu uma linha de crédito para os funcionários
// estatutários. O valor máximo da prestação não poderá ultrapassar 30% do salário
// bruto. Faça um programa em linguagem C que permita entrar com o salário bruto
// e o valor da prestação e informar se o empréstimo pode ou não ser concedido.

#include <stdio.h>
#include <stdlib.h>

void main()
{
    float salario, prestacao;

    printf("Informe o valor do salario bruto: ");
    scanf("%f", &salario);

    printf("Informe o valor da prestacao (em porcentagem): ");
    scanf("%f", &prestacao);

    if (prestacao > 30)
        printf("Lamento, emprestimo nao pode ser concedido");
    else
        printf("Emprestimo pode ser concedido");
}