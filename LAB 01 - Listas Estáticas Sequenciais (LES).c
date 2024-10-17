#include <stdio.h>

#define TAMANHO 10

typedef struct {
  int valores[TAMANHO];
  int n;
} Lista;

int esta_cheia(Lista *lista) { return lista->n == TAMANHO; }

int esta_vazia(Lista *lista) { return lista->n == 0; }


int encontrar_posicao(Lista *lista, int valor) {
  for (int i = 0; i < lista->n; i++) {
    if (lista->valores[i] == valor) {
      return i;
    }
  }
  return -1;
}

void deslocar_direita(Lista *lista, int indice) {
  for (int i = lista->n; i > indice; i--) {
    lista->valores[i] = lista->valores[i - 1];
  }
}

void deslocar_esquerda(Lista *lista, int indice) {
  for (int i = indice; i < lista->n; i++) {
    lista->valores[i] = lista->valores[i + 1];
  }
}

int inserir(Lista *lista, int valor) {
  if (!esta_cheia(lista)) {
    for (int i = 0; i < lista->n; i++){
      if (lista->valores[i] > valor) {
        deslocar_direita(lista, i);
        lista->valores[i] = valor;
        lista->n++;
        return 1;
      }
  }
  lista->valores[lista->n] = valor;
  lista->n++;
  return 1;
}
return 0;
}

int remover(Lista *lista, int valor) {
  if (!esta_vazia(lista)) {
    int idx = encontrar_posicao(lista, valor);
    if (idx != -1) {
      deslocar_esquerda(lista, idx);
      lista->n--;
      return 1;
    }
    
} return 0;
}

void exibir_lista(const Lista *lista) {
  for (int i = 0; i < lista->n; i++) {
    printf("%d ", lista->valores[i]);
  }
  printf("\n");
}

int main(void) {
  Lista lista = {.n = 0};
  Lista *pl = &lista;
  int valores[] = {21, 14, 13, 10, 87, 35, 27, 56, 85, 29};

  for (int i = 0; i < TAMANHO; i++) {
    inserir(pl, valores[i]);
    exibir_lista(pl);
  }

  for (int i = 0; i < TAMANHO; i++) {
    printf("O valor %d está na posição %d\n", valores[i],
           encontrar_posicao(pl, valores[i]));
  }

  for (int i = 0; i < TAMANHO; i++) {
    remover(pl, valores[i]);
    exibir_lista(pl);
  }

  return 0;
}

