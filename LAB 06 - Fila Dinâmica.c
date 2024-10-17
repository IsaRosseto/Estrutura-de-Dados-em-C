#include <stdio.h>
#include <stdlib.h>

typedef struct Celula {
  int valor;
  struct Celula *proximo;
  struct Celula *anterior;
} Celula;

typedef struct {
  Celula *head;
  Celula *tail;
  int qtde;
} Queue;

Queue *cria_queue(){
  Queue *queue = malloc(sizeof(Queue));
  queue->qtde = 0;
  queue->head = NULL;
  queue->tail = NULL;
  return queue;
}

Celula *cria_celula(int valor){
  Celula *celula = malloc(sizeof(Celula));
  celula->valor = valor;
  celula->proximo = NULL;
  celula->anterior = NULL;
  return celula;
}

void enqueue(Queue *queue, int valor){
  Celula *novo = cria_celula(valor);

  if(queue->qtde == 0){
    queue->head = novo;
    queue->tail = novo;
    queue->qtde++;
  } 

  else {
    Celula *atual = queue->tail;

    novo->anterior = atual;
    atual->proximo = novo;
    queue->tail = novo;
    queue->qtde++;
  }
}

int dequeue(Queue *queue){
  if(queue->qtde == 0){
    printf("Erro!\n");
    return -1;
  }

  else if(queue->qtde == 1){
    free(queue->head);
    queue->head = NULL;
    queue->qtde--;
  }

  else {
    Celula *proximo = queue->head->proximo;
    free(queue->head);
    queue->head = proximo;
    queue->qtde--;
  }
  return 0;
}

void show_invertido(Queue *queue){
  Celula *atual = queue->head;

  while(atual != NULL){
    printf("%d", atual->valor);
    atual = atual->proximo;
  }
  printf("\n");
}

void show(Queue *queue){
  Celula *atual = queue->tail;

  while(atual != NULL){
    printf("%d", atual->valor);
    atual = atual->anterior;
  }
  printf("\n");
}

Queue *soma(Queue *qnum1, Queue *qnum2, Queue *res){

  Celula *atual1 = qnum1->tail;
  Celula *atual2 = qnum2->tail;
  int resto = 0;

  while(atual1 != NULL){

    int soma = atual1->valor + atual2->valor + resto;

    if(soma > 9){
      soma = soma - 10;
      resto = 1;
    }
    else{
      resto = 0;
    }

    enqueue(res, soma);
    res->qtde++;

    atual1 = atual1->anterior;
    atual2 = atual2->anterior;

  }

  if(resto == 1){
    enqueue(res, resto);
  }

  return res;
}

int main(void){
  Queue *qnum1 = cria_queue();
  Queue *qnum2 = cria_queue();
  Queue *res = cria_queue();

  char num1[100];
  char num2[100];
  fgets(num1, sizeof(num1), stdin);
  fgets(num2, sizeof(num2), stdin);

  int i = 0;
  while (num1[i] != '\n') {
    enqueue(qnum1, (int)(num1[i]) - 48);
    enqueue(qnum2, (int)(num2[i]) - 48);
    i++;
  }

  soma(qnum1, qnum2, res);
  show(res);

  return 0;
}
