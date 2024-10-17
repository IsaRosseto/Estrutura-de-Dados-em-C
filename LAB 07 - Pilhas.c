#include <stdio.h>
#include <stdlib.h>

typedef struct Celula {
  struct Celula *proximo;
  int valor;
} Celula;

typedef struct {
  Celula *topo;
  int qtd;
} Stack;

Celula *criar_celula(int valor) {
  Celula *celula = malloc(sizeof(Celula));
  celula->proximo = NULL;
  celula->valor = valor;
  return celula;
}

Stack *criar_pilha() {
  Stack *pilha = malloc(sizeof(Stack));
  pilha->topo = NULL;
  pilha->qtd = 0;
  return pilha;
}

void push(Stack *pilha, int valor) {
  Celula *novo = criar_celula(valor);
  novo->proximo = pilha->topo;
  pilha->topo = novo;
  pilha->qtd++;
}

int pop(Stack *pilha) {
  if (pilha->qtd == 0) {
    return -1;
  }

  int valor = pilha->topo->valor;
  Celula *temp = pilha->topo;
  pilha->topo = pilha->topo->proximo;
  pilha->qtd--;
  free(temp);
  return valor;
}

void show(Stack *pilha) {
  Celula *atual = pilha->topo;
  while (atual != NULL) {
    printf("%d ", atual->valor);
    atual = atual->proximo;
  }
  printf("\n");
}

int main() {
  Stack *pilha = criar_pilha();
  char expr[100];
  fgets(expr, sizeof(expr), stdin);

 
  int flag = 1;
  int chave = 0;
  int colchete = 0;
  int parenteses = 0;

  for (int i = 0; expr[i] != '\0'; i++) {

    char entrada = expr[i];

    if (entrada == '{') {
      push(pilha, entrada);
      chave++;
      if (colchete > 0) {
        flag = 0;
        break;
      }
    }

    if (entrada == '[') {
      push(pilha, entrada);
      colchete++;
      if (parenteses > 0) {
        flag = 0;
        break;
      }
    }

    if (entrada == '(') {
      push(pilha, entrada);
      parenteses++;
    }

    if (entrada == '}') {
      char x = pop(pilha);
      if (x != '{') {
        flag = 0;
        break;
      }
      chave--;
    }

    if (entrada == ']') {
      char x = pop(pilha);
      if (x != '[') {
        flag = 0;
        break;
      }
      colchete--;
    }

    if (entrada == ')') {
      char x = pop(pilha);
      if (x != '(') {
        flag = 0;
        break;
      }
      parenteses--;
    }

    
  }
    if (flag == 0) {
          printf("incorreto\n");
        } else {
          printf("correto\n");
        }
    return 0;
}

