// Faça um programa em linguagem C que funcione através do menu a seguir:
// 1-SOMA VARIOS NUMEROS
// 2-MULTIPLICA VARIOS NUMEROS
// 3-SAI DO PROGRAMA
// OPCAO: |

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int op;
    float num, soma, prod;

    do
    {
        printf("1 - Soma varios numeros\n");
        printf("2 - Multiplica varios numeros\n");
        printf("3 - Encerrar o programa\n");
        printf("Opcao: ");
        scanf("%d", &op);

        if (op == 1)
        {
            soma = 0;

            printf("\nDigite numero ou -999 para finalizar: ");
            scanf("%f", &num);

            while (num != -999)
            {
                soma += num;

                printf("\nDigite numero ou -999 para finalizar: ");
                scanf("%f", &num);
            }
            printf("\nSoma: %.2f\n", soma);
        }
        else if (op == 2)
        {
            prod = 1;
            printf("\nDigite numero ou -999 para finalizar: ");
            scanf("%f", &num);
            while (num != -999)
            {
                prod *= num;
                printf("\n Digite numero ou -999 para finalizar: ");
                scanf("%f", &num);
            }
            printf("\nProduto: %.2f\n", prod);
        }
        else if (op == 3)
        {
            printf("\nPrograma encerrado!");
        }
        else
        {
            printf("\nOpcao nao disponivel!");
        }
    } while (op != 3);
}