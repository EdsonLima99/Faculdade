// O escritório de contabilidade Super Contábil está realizando o reajuste do salário dos
// funcionários de todos os seus clientes. Para isso, estão utilizando como referência o
// reajuste acordado com os sindicatos de cada classe trabalhadora, conforme apresentado
// na tabela a seguir. Para ajudar o escritório nesta tarefa, faça um programa em C que
// receba o salário atual, o cargo conforme especificado na tabela a seguir e realize o
// cálculo do reajuste do salário. Ao término do cálculo o programa deve imprimir o valor
// do reajuste e o novo salário do funcionário.
// |-----------------------------------------------------------|
// | Cód. cargo |         Cargo          | % reajuste acordado |
// |-----------------------------------------------------------|
// |      1     | Auxiliar de escritório |         7%          |
// |      2     |     Secretário(a)      |         9%          |
// |      3     |     Cozinheiro(a)      |         5%          |
// |      4     |     Entregador(a)      |         12%         |
// |-----------------------------------------------------------|

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int cargo;
    float salAtual, reajuste;

    printf("Informe o cargo do funcionario: ");
    scanf("%d", &cargo);

    printf("Informe o salario atual: ");
    scanf("%f", &salAtual);

    if (cargo == 1)
        reajuste = (salAtual * 7) / 100;
    else if (cargo == 2)
        reajuste = (salAtual * 9) / 100;
    else if (cargo == 3)
        reajuste = (salAtual * 5) / 100;
    else
        reajuste = (salAtual * 12) / 100;

    printf("O reajuste e: %f\n", reajuste);
    printf("O novo salario e: %f", salAtual + reajuste);
}
