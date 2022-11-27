// Na Usina de Angra dos Reis, os técnicos analisam a perda de massa de um material
// radioativo. Sabendo-se que este perde 25% de sua massa a cada 30 segundos, criar um
// programa em C que imprima o tempo necessário para que a massa deste material se
// torne menor que 0,10 grama. O programa deve calcular o tempo para várias massas.

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int conTempo = 0;
    float massa, tempo;
    char resp;

    printf("Digite S se desejar novo calculo ou qualquer letra para terminar: ");
    scanf("%s", &resp);

    while (resp == 'S' || resp == 's')
    {
        printf("Digite a massa em gramas do material: ");
        scanf("%f", &massa);

        while (massa >= 0.10)
        {
            conTempo++;
            massa *= 0.75;
        }
        tempo = (conTempo * 30) / 60;
        printf("O tempo foi de: %.2f minutos. \n", tempo);

        printf("\nDigite S se desejar novo calculo ou qualquer letra para terminar: ");
        scanf("%s", &resp);
    }
}