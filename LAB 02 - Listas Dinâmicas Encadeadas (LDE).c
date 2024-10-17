#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int valor;
    struct Nodo *proximo;
} Nodo;

typedef struct Lista {
    int quantidade;
    Nodo *primeiro;
} Lista;

Lista *criar_lista() {
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    lista->quantidade = 0;
    lista->primeiro = NULL;
    return lista;
}

void inserir_ordenado(Lista *lista, int valor) {
    Nodo *novo_nodo = (Nodo *)malloc(sizeof(Nodo));
    novo_nodo->valor = valor;
    novo_nodo->proximo = NULL;

    if (lista->primeiro == NULL || lista->primeiro->valor > valor) {
        novo_nodo->proximo = lista->primeiro;
        lista->primeiro = novo_nodo;
    } else {
        Nodo *atual = lista->primeiro;
        while (atual->proximo != NULL && atual->proximo->valor < valor) {
            atual = atual->proximo;
        }
        novo_nodo->proximo = atual->proximo;
        atual->proximo = novo_nodo;
    }

    lista->quantidade++;
}

void remover_valor(Lista *lista, int valor) {
    if (lista->primeiro == NULL) {
        return;
    }

    Nodo *atual = lista->primeiro;
    Nodo *anterior = NULL;

    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        return;
    }

    if (anterior == NULL) {
        lista->primeiro = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
    lista->quantidade--;
}

void imprimir_lista(Lista *lista) {
    Nodo *atual = lista->primeiro;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

int main(void) {
    Lista *lista = criar_lista();
    int valores[] = {2, 1, 0, 9, 3, 8, 5, 7, 6, 4};

    for (int i = 0; i < 10; i++) {
        inserir_ordenado(lista, valores[i]);
        imprimir_lista(lista);
    }

    for (int i = 0; i < 10; i++) {
        remover_valor(lista, valores[i]);
        imprimir_lista(lista);
    }

    free(lista);
    return 0;
}
