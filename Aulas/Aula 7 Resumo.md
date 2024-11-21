### **Resumo Completo da Aula 7 - Pilhas**

---

### **1. O que é uma Pilha?**

- **Definição:** Uma pilha é uma estrutura de dados onde as operações de inserção e remoção são realizadas em um único ponto, denominado **topo**.
- **Regras de Acesso:** A pilha segue a regra **LIFO** (Last In, First Out), ou seja, o último elemento inserido é o primeiro a ser removido.

- **Analogia:** Imagine uma pilha de pratos. O último prato colocado é sempre o primeiro a ser retirado, enquanto o primeiro prato colocado fica na base da pilha e só pode ser acessado depois de retirar todos os pratos que estão acima dele.

---

### **2. Operações Básicas em uma Pilha**

1. **Inserção (Push)**
   - **Descrição:** Inserir um novo elemento no topo da pilha.
   - **Exemplo de Código em C:**
     ```c
     #include <stdio.h>
     #define TAMANHO_MAX 5

     int pilha[TAMANHO_MAX];
     int topo = -1;

     void push(int valor) {
         if (topo == TAMANHO_MAX - 1) {
             printf("Pilha cheia, não é possível inserir o valor\n");
         } else {
             topo++;
             pilha[topo] = valor;
         }
     }
     ```
   - **Explicação Linha a Linha:**
     - `#define TAMANHO_MAX 5`: Define o tamanho máximo da pilha.
     - `int pilha[TAMANHO_MAX];`: Declara um vetor `pilha` com tamanho 5 para armazenar os elementos da pilha.
     - `int topo = -1;`: Inicializa o ponteiro `topo` em -1, indicando que a pilha está vazia.
     - `void push(int valor) {...}`: Função para inserir um elemento na pilha.
     - `if (topo == TAMANHO_MAX - 1)`: Verifica se a pilha está cheia.
     - `topo++`: Incrementa o valor de `topo` para apontar para a próxima posição livre.
     - `pilha[topo] = valor;`: Insere o valor na posição indicada por `topo`.

   - **Representação Visual Detalhada após Inserção:**
     ```
     +-------+
     | Valor |
     |  10   | <- topo
     +-------+
        |
      Ponteiro (topo)
     ```
     O elemento `10` está no topo da pilha e é o único elemento presente. O ponteiro `topo` indica a posição desse elemento.

2. **Remoção (Pop)**
   - **Descrição:** Remover o elemento do topo da pilha.
   - **Exemplo de Código em C:**
     ```c
     void pop() {
         if (topo == -1) {
             printf("Pilha vazia, não há elemento para remover\n");
         } else {
             int elemento_removido = pilha[topo];
             printf("Elemento removido: %d\n", elemento_removido);
             topo--;
         }
     }
     ```
   - **Explicação Linha a Linha:**
     - `void pop() {...}`: Função para remover um elemento da pilha.
     - `if (topo == -1)`: Verifica se a pilha está vazia.
     - `int elemento_removido = pilha[topo];`: Armazena o valor do elemento que será removido.
     - `topo--`: Decrementa o valor de `topo`, movendo-o para a posição anterior.

   - **Representação Visual Detalhada após Remoção:**
     ```
     Pilha vazia
     topo -> -1
     ```
     Após a remoção do único elemento, o valor de `topo` volta a ser `-1`, indicando que a pilha está vazia.

3. **Verificar se a Pilha está Cheia**
   - **Função em C:**
     ```c
     int estaCheia() {
         return topo == TAMANHO_MAX - 1;
     }
     ```
   - **Explicação:** Retorna verdadeiro (`1`) se `topo` estiver na última posição, indicando que a pilha está cheia.

4. **Verificar se a Pilha está Vazia**
   - **Função em C:**
     ```c
     int estaVazia() {
         return topo == -1;
     }
     ```
   - **Explicação:** Retorna verdadeiro (`1`) se `topo` for igual a `-1`, indicando que a pilha está vazia.

---

### **3. Pilha Dinâmica**

- **Definição:** Uma pilha dinâmica utiliza alocação dinâmica de memória, permitindo que a pilha cresça conforme a necessidade, diferente da pilha estática, cujo tamanho é fixo.

1. **Inserção na Pilha Dinâmica (Push)**
   - **Exemplo de Código em C:**
     ```c
     typedef struct No {
         int valor;
         struct No* proximo;
     } No;

     No* topo = NULL;

     void push(int valor) {
         No* novoNo = (No*) malloc(sizeof(No));
         novoNo->valor = valor;
         novoNo->proximo = topo;
         topo = novoNo;
     }
     ```
   - **Explicação Linha a Linha:**
     - `typedef struct No {...} No;`: Define a estrutura de um nó da pilha, contendo um valor e um ponteiro para o próximo nó.
     - `No* topo = NULL;`: Inicializa o ponteiro `topo` como `NULL`, indicando que a pilha está vazia.
     - `void push(int valor) {...}`: Função para inserir um elemento na pilha dinâmica.
     - `No* novoNo = (No*) malloc(sizeof(No));`: Aloca dinamicamente memória para um novo nó.
     - `novoNo->valor = valor;`: Define o valor do novo nó.
     - `novoNo->proximo = topo;`: Faz o ponteiro `proximo` do novo nó apontar para o antigo topo.
     - `topo = novoNo;`: Atualiza `topo` para apontar para o novo nó.

   - **Representação Visual Detalhada após Inserção:**
     ```
     +-------+      +-------+      +-------+
     | Valor |      | Valor |      | Valor |
     |  30   | -->  |  20   | -->  |  10   | --> NULL
     +-------+      +-------+      +-------+
        |              |              |
      topo         Próximo         Próximo
                   (nó anterior)   (nó anterior)
     ```
     Cada nó possui um valor e um ponteiro para o nó que estava abaixo dele (nó anterior). O ponteiro `topo` sempre aponta para o último elemento inserido.

2. **Remoção na Pilha Dinâmica (Pop)**
   - **Exemplo de Código em C:**
     ```c
     void pop() {
         if (topo == NULL) {
             printf("Pilha vazia, não há elemento para remover\n");
         } else {
             No* temp = topo;
             int elemento_removido = topo->valor;
             topo = topo->proximo;
             free(temp);
             printf("Elemento removido: %d\n", elemento_removido);
         }
     }
     ```
   - **Explicação Linha a Linha:**
     - `if (topo == NULL)`: Verifica se a pilha está vazia.
     - `No* temp = topo;`: Cria um ponteiro temporário `temp` para armazenar o nó atual de `topo`.
     - `int elemento_removido = topo->valor;`: Armazena o valor do nó que será removido.
     - `topo = topo->proximo;`: Atualiza `topo` para apontar para o próximo nó da pilha.
     - `free(temp);`: Libera a memória do nó removido.

   - **Representação Visual Detalhada após Remoção:**
     ```
     +-------+      +-------+
     | Valor |      | Valor |
     |  20   | -->  |  10   | --> NULL
     +-------+      +-------+
        |              |
      topo          Próximo
                    (nó anterior)
     ```
     Após remover o elemento do topo, o ponteiro `topo` é atualizado para o próximo nó na pilha.

---

### **4. Conclusão sobre Pilhas**

- **Pilha Estática vs. Pilha Dinâmica**
  - **Pilha Estática:** Simples de implementar, mas com tamanho fixo, o que pode levar ao desperdício ou falta de memória.
  - **Pilha Dinâmica:** Mais flexível, pois cresce conforme a necessidade, mas requer alocação dinâmica e é mais complexa de gerenciar.

---

Este resumo abrange os principais conceitos de pilhas, abordando tanto a implementação estática quanto a dinâmica, com exemplos de código em C e explicações linha a linha. Se precisar de mais exemplos ou detalhes, estou à disposição!

