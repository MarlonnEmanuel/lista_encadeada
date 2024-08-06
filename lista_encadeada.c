#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

No* criar_lista() {
    return NULL;
}

No* criar_No(int valor) {
    No* Novo_No = (No*)malloc(sizeof(No));
    if (Novo_No == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    Novo_No->valor = valor;
    Novo_No->proximo = NULL;

    return Novo_No;
}

void ad_No_Inicio(No** cabeca, int valor) {
    No* NovoNo = criar_No(valor);
    NovoNo->proximo = *cabeca;
    *cabeca = NovoNo;
}

void inserir_No_Posicao(No** cabeca, int valor, int posicao) {
    No* NovoNo = criar_No(valor);

    if (posicao == 0) {
        NovoNo->proximo = *cabeca;
        *cabeca = NovoNo;
        return;
    }

    No* atual = *cabeca;
    for (int i = 0; i < posicao - 1 && atual != NULL; i++) {
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Posição inválida.\n");
        free(NovoNo);
        return;
    }

    NovoNo->proximo = atual->proximo;
    atual->proximo = NovoNo;
}

void remover_No_Posicao(No** cabeca, int posicao) {
    if (*cabeca == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    No* atual = *cabeca;

    if (posicao == 0) {
        *cabeca = atual->proximo;
        free(atual);
        return;
    }

    No* anterior = NULL;
    for (int i = 0; i < posicao && atual != NULL; i++) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Posição inválida.\n");
        return;
    }

    anterior->proximo = atual->proximo;
    free(atual);
}

void modificar_elemento(No* cabeca, int posicao, int novo_valor) {
    if (cabeca == NULL) {
        printf("Erro, lista vazia.\n");
        return;
    }
    
    int tamanho = tamanho_lista(cabeca);
    if (posicao < 0 || posicao >= tamanho) {
        printf("Erro, posição inválida.\n");
        return;
    }

    No* aux = cabeca;
    for (int cont = 0; cont < posicao; cont++) {
        aux = aux->proximo;
    }
    
    aux->valor = novo_valor;
}

int lista_vazia(No* cabeca) {
    return cabeca == NULL;
}

void imprimirLista(No* cabeca) {
    No* atual = cabeca;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

void free_lista(No* lista) {
    No* atual = lista;
    No* proximoNo;

    while (atual != NULL) {
        proximoNo = atual->proximo;
        free(atual);
        atual = proximoNo;
    }
}

int tamanho_lista(No* cabeca) {
    int tamanho = 0;
    No* atual = cabeca;
    while (atual != NULL) {
        tamanho++;
        atual = atual->proximo;
    }
    return tamanho;
}

int elemento_No(No* cabeca, int posicao) {
    if (cabeca == NULL) {
        printf("Erro, lista vazia.\n");
        return -1;  // Código de erro
    }
    
    int tamanho = tamanho_lista(cabeca);
    if (posicao < 0 || posicao >= tamanho) {
        printf("Erro, posição inválida.\n");
        return -1;  // Código de erro
    }

    No* aux = cabeca;
    for (int cont = 0; cont < posicao; cont++) {
        aux = aux->proximo;
    }
    
    return aux->valor;
}
