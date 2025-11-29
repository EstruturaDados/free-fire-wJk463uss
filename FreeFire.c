#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITENS 10
#define TAM_NOME 30
#define TAM_TIPO 20

// Estrutura para representar um item da mochila
typedef struct {
    char nome[TAM_NOME];
    char tipo[TAM_TIPO];
    int quantidade;
} Item;

// Função para efetuar limpeza do buffer
void limparBufferEntrada() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);

}

 int main() {
    Item mochila[MAX_ITENS];
    int totalItens = 0;
    int opcao;

    do {
        printf("\n==== MOCHILA ====\n");
        printf("1. Adicionar item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limparBufferEntrada(); // Limpa o buffer do teclado

        switch (opcao) {
            case 1:
                if (totalItens >= MAX_ITENS) {
                    printf("Mochila cheia! Nao é possivel adicionar mais itens.\n");
                } else {
                    printf("Nome do item: ");
                    fgets(mochila[totalItens].nome, TAM_NOME, stdin);
                    mochila[totalItens].nome[strcspn(mochila[totalItens].nome, "\n")] = '\0';                       printf("Tipo do item: ");
                    fgets(mochila[totalItens].tipo, TAM_TIPO, stdin);
                    mochila[totalItens].tipo[strcspn(mochila[totalItens].tipo, "\n")] = '\0';

                                    printf("Quantidade: ");
                    scanf("%d", &mochila[totalItens].quantidade);
                    limparBufferEntrada(); // Limpa o buffer
                    totalItens++;
                    printf("Item adicionado com sucesso!\n");
                }
                break;

            case 2: {
                char nomeRemover[TAM_NOME];
                int encontrado = 0;
                printf("Digite o nome do item a remover: ");
                fgets(nomeRemover, TAM_NOME, stdin);
                nomeRemover[strcspn(nomeRemover, "\n")] = '\0';
                                for (int i = 0; i < totalItens; i++) {
                    if (strcmp(mochila[i].nome, nomeRemover) == 0) {
                        for (int j = i; j < totalItens - 1; j++) {
                            mochila[j] = mochila[j + 1];
                        }
                        totalItens--;
                        encontrado = 1;
                        printf("Item removido com sucesso!\n");
                        break;
                    }
                }
                                if (!encontrado) {
                    printf("Item não encontrado.\n");
                }
                break;
                  }
            case 3:
                if (totalItens == 0) {
                    printf("A mochila está vazia.\n");
                } else {

                    printf("\n%-30s %-20s %-10s\n", "Nome", "Tipo", "Quantidade");
                    printf("-------------------------------------------------------------\n");
                    for (int i = 0; i < totalItens; i++) {
                        printf("%-30s %-20s %-10s\n", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
                    }
                }
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opcao inválida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
