// Escreva um programa em linguagem C que leia um peso na Terra e o número de um
// planeta e imprima o valor correspondente do peso neste planeta. A relação de planetas
//é dada a seguir juntamente com o valor das gravidades relativas à Terra.
//
// |----------------------------------------|
// | Código | Gravidade Relativa | Planeta  |
// |    1   |        0,37        | Mercúrio |
// |    2   |        0,88        |  Vênus   |
// |    3   |        0,38        |  Marte   |
// |    4   |        2,64        | Júpiter  |
// |    5   |        1,15        | Saturno  |
// |    6   |        1,17        |  Urano   |
// |----------------------------------------|
//
// Para calcular o peso no planeta use a fórmula:
// PP = PT × G
//     --
//     10
//
// Em que:
//• PP = Peso no planeta
//• PT = Peso na Terra
//• G = Gravidade relativa

#include <stdio.h>
#include <stdlib.h>

void main()
{
    // declaracao das variaveis
    float pesoTerra, pesoPlaneta;
    int numPlaneta;

    // leitura do peso na terra e escolha do planeta
    printf("Informe o peso na terra: ");
    scanf("%f", &pesoTerra);

    printf("Informe o numero do planeta conforme a tabela: \n");
    printf("1-Mercurio\t 2-Venus\t 3-Marte\n");
    printf("4-Jupiter\t 5-Saturno\t 6-Urano\n");
    scanf("%d", &numPlaneta);

    // switch responsavel pela escolha do calculo
    switch (numPlaneta)
    {
    case 1:
        pesoPlaneta = (pesoTerra / 10) * 0.37;
        break;
    case 2:
        pesoPlaneta = (pesoTerra / 10) * 0.88;
        break;
    case 3:
        pesoPlaneta = (pesoTerra / 10) * 0.38;
        break;
    case 4:
        pesoPlaneta = (pesoTerra / 10) * 2.64;
        break;
    case 5:
        pesoPlaneta = (pesoTerra / 10) * 1.15;
        break;
    case 6:
        pesoPlaneta = (pesoTerra / 10) * 1.17;
        break;
    default:
        printf("Planeta invalido!\n");
    }

    // impressao do peso no planeta escolhido
    printf("Peso no planeta escolhido: %.2f \n", pesoPlaneta);
}