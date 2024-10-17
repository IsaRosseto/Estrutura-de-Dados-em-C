#include <stdio.h>
#include <stdlib.h>

#define tam_hash 11

typedef struct Celula{
 int valor;
 struct Celula *proximo;
}Celula;

typedef struct Lista {
  int qtde;
  Celula *primeiro;
}Lista;

typedef struct Hash {
  Lista *tabela[tam_hash];
}Hash;

Hash* start_hash(){
  Hash *hash = (Hash *)malloc(sizeof(Hash));
  for (int i = 0; i < tam_hash; i++) {
    hash->tabela[i]  = (Lista* )malloc(sizeof(Lista)); 
    hash->tabela[i] ->primeiro = NULL; //inicia o primeiro como null
    hash->tabela[i]->qtde = 0; //m quantidade de elementos começa como 0
  }
    return hash;
}

void inserir_hash(Hash* hash, int valor){
  int indice = valor % tam_hash; //indice é igual o resto da divisão do valor por tamanho
  Celula*novo = (Celula*)malloc(sizeof(Celula)); //aloca memoria
  novo-> valor = valor;
  novo-> proximo = hash->tabela[indice]->primeiro; //o procimo do novo é o antigo primeiro
  hash->tabela[indice]->primeiro = novo;
  hash->tabela[indice]->qtde++;
}

void remover_hash(Hash* hash, int valor){
  int indice = valor % tam_hash;
  Celula *atual = hash->tabela[indice]->primeiro; 
  Celula *anterior = NULL;

  //percorre a lista até achar o valor
  while (atual != NULL && atual->valor != valor) {
      anterior = atual; 
      atual = atual->proximo;
  }

  if (atual == NULL) // se o valor não foi encontrado
      return;

  if (anterior == NULL) //se é o primeiro da lista
      hash->tabela[indice]->primeiro = atual->proximo;
  else
      anterior->proximo = atual->proximo;

  free(atual);
  hash->tabela[indice]->qtde--;
}

void imprimir(Hash* hash){
      printf("---------------------\n");
      for (int i = 0; i < tam_hash; i++) {
          printf("%d -> ", i); // Imprime o índice
          Celula *atual = hash->tabela[i]->primeiro; 
          while (atual != NULL) {
              printf("%d ", atual->valor); // Imprime o valor do elemento
              atual = atual->proximo; // Move para o próximo elemento
          }
          printf("\n");
      }
      printf("---------------------\n");
  }


int main(void) {
  Hash* hash = start_hash();
  int valor;
  while(1){
    scanf("%d", &valor);
    if(valor == 0)
      break;
    inserir_hash(hash, valor);
  }
  imprimir(hash);
  while(1){
    scanf("%d", &valor);
    if(valor == 0)
      break;
    remover_hash(hash, valor);
  }
  imprimir(hash);
  return 0;
}
