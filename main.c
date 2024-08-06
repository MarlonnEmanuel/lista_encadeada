#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

void menu() {
    printf("\nMenu:\n");
    printf("1. Adicionar no início\n");
    printf("2. Inserir em posição específica\n");
    printf("3. Remover de posição específica\n");
    printf("4. Modificar elemento\n");
    printf("5. Imprimir lista\n");
    printf("6. Verificar se lista está vazia\n");
    printf("7. Tamanho da lista\n");
    printf("8. Obter elemento de posição específica\n");
    printf("9. Sair\n");
    printf("Escolha uma opção: ");
}

int main() {
    No* lista = criar_lista();
    int opcao, valor, posicao;

    while (1) {
        menu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                ad_No_Inicio(&lista, valor);
                break;

            case 2:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                printf("Digite a posição: ");
                scanf("%d", &posicao);
                inserir_No_Posicao(&lista, valor, posicao);
                break;

            case 3:
                printf("Digite a posição: ");
                scanf("%d", &posicao);
                remover_No_Posicao(&lista, posicao);
                break;

            case 4:
                printf("Digite a posição: ");
                scanf("%d", &posicao);
                printf("Digite o novo valor: ");
                scanf("%d", &valor);
                modificar_elemento(lista, posicao, valor);
                break;

            case 5:
                imprimirLista(lista);
                break;

            case 6:
                if (lista_vazia(lista)) {
                    printf("A lista está vazia.\n");
                } else {
                    printf("A lista não está vazia.\n");
                }
                break;

            case 7:
                printf("Tamanho da lista: %d\n", tamanho_lista(lista));
                break;

            case 8:
                printf("Digite a posição: ");
                scanf("%d", &posicao);
                valor = elemento_No(lista, posicao);
                if (valor != -1) {
                    printf("Elemento na posição %d: %d\n", posicao, valor);
                }
                break;

            case 9:
                free_lista(lista);
                exit(0);
                break;

            default:
                printf("Opção inválida.\n");
                break;
        }
    }

    return 0;
}
