// Faça um programa em C que armazene as 3 notas de 4 alunos. Após a leitura o programa
// deve calcular a nota final com o somatório das três notas. Ao final deve imprimir as
// notas e a nota final para cada aluno.

#include <stdio.h>
#include <stdlib.h>

void main()
{
    float matNotas[4][4];
    int i, j;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("Para o aluno %d informe a nota %d: ", i + 1, j + 1);
            scanf("%f", &matNotas[i][j]);
        }
        matNotas[i][3] = matNotas[i][0] + matNotas[i][1] + matNotas[i][2];
    }

    // imprimindo as notas dos alunos
    for (i = 0; i < 4; i++)
    {
        printf("Notas do Aluno %d\n", i + 1);
        for (j = 0; j < 3; j++)
        {
            if (j != 2)
                printf("%.2f\t", matNotas[i][j]);
            else
                printf("%.2f\n", matNotas[i][j]);
        }
        printf("Nota final......: %f\n", matNotas[i][3]);
    }
}