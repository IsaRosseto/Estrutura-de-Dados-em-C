#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
     int valor;
     struct celula *anterior;
     struct celula *proximo;
} celula;

typedef struct ldde{
     int qtde;
     celula *primeiro;
} ldde;

ldde *criar_lista(){
     ldde *l = malloc(sizeof(ldde));
     l->primeiro = NULL;
     l->qtde = 0;
     return l;
}

celula *criar_celula(int valor){
     celula *c = malloc(sizeof(celula));
     c->valor = valor;
     c->anterior = NULL;
     c->proximo = NULL;
     return c;
}

void inserir(ldde *l, int valor)
{
  celula *nova = criar_celula(valor);

  if (l->qtde == 0)
  {
    l->primeiro = nova;
  }
  else
  {
    celula *atual = l->primeiro;
    celula *anterior = NULL;
    while(atual != NULL && atual->valor < valor)
    {
      anterior = atual;
      atual = atual->proximo;
    }
    if(atual == NULL)
    {
      anterior->proximo = nova;
      nova->anterior = anterior;
    }else if (anterior == NULL)
    {
      l->primeiro = nova;
      nova->proximo = atual;
      atual->anterior = nova;
    }else
    {
      atual->anterior = nova;
      anterior->proximo = nova;

      nova->anterior = anterior;
      nova->proximo = atual;
    } 
  }

  l->qtde ++;
}



void mostrar(ldde *l)
{
  celula *atual = l->primeiro;
  printf("Início -> ");
  while(atual != NULL)
  {
    printf("%d ", atual->valor);
    atual = atual->proximo;
  }
  printf("<- Final\n");
}



void mostrar_invertido(ldde *l){
     celula *atual = l->primeiro;
     celula *anterior = NULL;
     while (atual != NULL)
     {
       anterior = atual;
    atual = atual->proximo;
     }

     printf("Final -> ");
     while(anterior != NULL)
     {
       printf("%d ", anterior->valor);
       anterior = anterior->anterior;
     }
     printf("<- Início\n");
}

void remover(ldde *l, int valor){

  celula *atual = l->primeiro;
  celula *anterior = NULL;

  while(atual != NULL && atual->valor != valor)  
  {
    anterior = atual;
    atual = atual->proximo;
  }
  if(atual == NULL)
    return;

  if(l->qtde == 1)
  {
    l->primeiro = NULL;
  }else if(anterior == NULL)
  {
    l->primeiro = atual->proximo;
    atual->proximo->anterior = NULL; 
  }else if(atual->proximo == NULL)
  {
    anterior->proximo = NULL;
  }else
  {
    atual->proximo->anterior = anterior;
    anterior->proximo = atual->proximo;
  }


  free(atual);
  l->qtde --;






}

int main(void) {
    ldde *l = criar_lista();
     inserir(l, 10);
     mostrar(l);
     mostrar_invertido(l);
     inserir(l, 5);
     mostrar(l);
     mostrar_invertido(l);
     inserir(l, 20);
     mostrar(l);
     mostrar_invertido(l);
     inserir(l, 15);
     mostrar(l);
     mostrar_invertido(l);

     remover(l, 5);
     mostrar(l);
     mostrar_invertido(l);
     remover(l, 15);
     mostrar(l);
     mostrar_invertido(l);
     remover(l, 20);
     mostrar(l);
     mostrar_invertido(l);
     remover(l, 10);
     mostrar(l);
     mostrar_invertido(l);
     for(int i = 0; i < 10; i++){
          inserir(l, i + 1);
     }
     mostrar(l);
     mostrar_invertido(l);
     for(int i = 0; i < 10; i++){
          remover(l, i + 1);
     }
     mostrar(l);
     mostrar_invertido(l);

     inserir(l, 100);
     remover(l, 100);
     mostrar(l);
     mostrar_invertido(l);

     inserir(l, 10);
     inserir(l, 10);
     inserir(l, 10);
     mostrar(l);
     mostrar_invertido(l);


  return 0;
}
