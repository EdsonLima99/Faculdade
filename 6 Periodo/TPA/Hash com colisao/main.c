#include "TabelaHash.c"

int main()
{
    int opcao, valor;
    Elemento *e;

    // ler o arquivo e contar o número de elementos
    int numElementos = contarElementosArquivo();

    // declaração da tabela
    Lista *tabela[numElementos];

    int tamanho = sizeof(tabela) / sizeof(Lista*);

    inicializar(tabela, tamanho);

    time_t begin = time(NULL);

    lerArquivo(tabela, tamanho);

    time_t end = time(NULL);

    printf("\n\tO tempo foi de %d segundos", (end - begin));

    do
    {
        printf("\n---------------- MENU ------------------\n");
        printf("1 - Inserir\n");
        printf("2 - Buscar\n");
        printf("3 - Remover\n");
        printf("4 - Imprimir tabela\n");
        printf("5 - Salvar tabela\n");
        printf("0 - Sair\n");
        printf("Digite sua opção: ");
        scanf("%d", &opcao);
        
        switch (opcao)
        {
        case 0:
            printf("Fim...\n");
            break;
        case 1:
            inserirTabela(tabela, tamanho);
            break;
        case 2:
            printf("Qual o elemento a ser buscado? ");
            scanf("%d", &valor);
            e = buscarElementoTabela(tabela, valor, tamanho);
            if (e)
                printf("Elemento encontrado: %d", e->valor);
            else
                printf("Elemento nao encontrado!\n");
            break;
        case 3:
            printf("Qual o elemento deseja excluir? ");
            scanf("%d", &valor);
            removerElementoTabela(tabela, valor, tamanho);
            break;
        case 4:
            imprimirTabela(tabela, tamanho);
            break;
        case 5:
            salvarElementosArquivo(tabela, tamanho);
            break;
        default:
            printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
