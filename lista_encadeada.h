#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

struct No {
    int valor;
    struct No* proximo;
};

typedef struct No No;

No* criar_lista();
No* criar_No(int valor);
void ad_No_Inicio(No** cabeca, int valor);
void inserir_No_Posicao(No** cabeca, int valor, int posicao);
void remover_No_Posicao(No** cabeca, int posicao);
void modificar_elemento(No* cabeca, int posicao, int novo_valor);
int lista_vazia(No* cabeca);
void imprimirLista(No* cabeca);
void free_lista(No* lista);
int tamanho_lista(No* cabeca);
int elemento_No(No* cabeca, int posicao);

#endif
