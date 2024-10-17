#include <stdio.h>
#include <stdlib.h>

#define LEN 10

typedef struct {
  int valores[LEN];
  int qtde;
} heap;

int filho_esq(int pai) { return 2 * pai + 1; }

int filho_dir(int pai) { return 2 * pai + 2; }

int pai(int filho) { return ((filho - 1) / 2); }

int ultimo_pai(heap *h) { return (h->qtde / 2) - 1;}

void peneirar(heap *h, int pai) {
  int primogenito = pai;
  int esquerda = filho_esq(pai);
  int direita = filho_dir(pai);

  // até aqui nós estamos vendo qual é o maior "filho" que seria o nosso
  // primogenito
  if (esquerda < h->qtde && h->valores[esquerda] > h->valores[primogenito])
    primogenito = esquerda;

  if (direita < h->qtde && h->valores[direita] > h->valores[primogenito])
    primogenito = direita;

  // se o primogenito for maior que o pai, então trocamos
  if (primogenito != pai) {
    int troca = h->valores[pai];
    h->valores[pai] = h->valores[primogenito];
    h->valores[primogenito] = troca;
    peneirar(h, primogenito);
  }
  
}

void mostrar(heap *h) {
  for (int i = 0; i < h->qtde; i++) {
    printf("%d ", h->valores[i]);
  }
  printf("\n");
}

void construir(heap *h) {
  // o construir basicamente percorre toda a árvore e coloca os pais em ordem
  for (int i = ultimo_pai(h); i >= 0; i--) {
    peneirar(h, i);
  }
}

void inserir(heap *h, int valor) {
  // verifica se o vetor está cheio
  if (h->qtde < LEN) {

    h->valores[h->qtde] = valor;
    h->qtde++;
     construir(h);
    }
   
}

void remover(heap *h) {
  // verifica se o vetor está vazio
  if (h->qtde > 0) {
    h->valores[0] = h->valores[h->qtde - 1];
    h->qtde--;

    construir(h);
  }
}

int main(void) {
  heap *h = malloc(sizeof(heap));
  int valor;
  h->qtde = 0;
  for (int i = 0; i < LEN; i++) {
    scanf("%d", &valor);
    inserir(h, valor);
    mostrar(h);
  }
  for (int i = 0; i < LEN; i++) {
    remover(h);
    mostrar(h);
  }

  return 0;
}
