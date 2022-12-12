#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "hash.c"

void main()
{
    int tamanho;
    FILE *arquivo;

    tamanho = inicializaTamanho(arquivo);
    TDados *hash[tamanho];

    inicializa(hash, tamanho);

    time_t begin = time(NULL);

    inserirNaHash(hash, tamanho, arquivo);

    time_t end = time(NULL);

    //Tempo de 3 segundos para o arquivo de 1K e o tempo de 0 segundos para o arquivo de 100K
    printf("\n\tO tempo foi de %d segundos", (end - begin));

    menu(hash, tamanho);
}