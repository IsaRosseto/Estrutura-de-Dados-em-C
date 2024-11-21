### **Resumo Completo da Aula 3 - Listas Dinâmicas Duplamente Encadeadas (LDDE)**

---

### **1. Estruturas de Dados Dinâmicas Duplamente Encadeadas**

- **Definição:** Uma estrutura de dados em que cada elemento (ou nó) possui dois ponteiros: um que aponta para o próximo elemento e outro que aponta para o elemento anterior.
- **Vantagem sobre listas simplesmente encadeadas:** Facilita a navegação bidirecional e a remoção/inserção em qualquer posição da lista.

---

### **2. Lista Dinâmica Duplamente Encadeada (LDDE)**

- **O que é?** Uma lista onde cada elemento tem dois ponteiros:
  1. **Ponteiro anterior** (“prev”): Aponta para o nó anterior.
  2. **Ponteiro próximo** (“next”): Aponta para o próximo nó da lista.
- **Elementos da LDDE:**
  - Cada nó contém:
    1. Um **valor** (os dados armazenados).
    2. Um **ponteiro anterior** que aponta para o elemento anterior (ou `NULL` se for o primeiro).
    3. Um **ponteiro próximo** que aponta para o próximo elemento (ou `NULL` se for o último).

---

### **3. Características da LDDE**

- **Navegação Bidirecional:** Possibilidade de percorrer a lista tanto para frente quanto para trás.
- **Facilidade em Inserções e Remoções:** Maior eficiência para adicionar e remover elementos em qualquer ponto da lista, pois cada elemento tem um ponteiro para o anterior e para o próximo.
- **Armazenamento Encadeado:** Cada elemento guarda um valor e dois ponteiros, formando uma estrutura em cadeia bidirecional.

---

### **4. Estrutura da Célula na LDDE**

- **Estrutura típica em C:**
  ```c
  typedef struct No {
      int valor;            // Valor armazenado no nó
      struct No* prev;      // Ponteiro para o nó anterior
      struct No* next;      // Ponteiro para o próximo nó
  } No;
  ```
- **Explicação das Linhas de Código:**
  - `typedef struct No { ... } No;`: Define uma estrutura chamada `No`, representando um nó da lista.
  - `int valor;`: Guarda o valor do nó.
  - `struct No* prev;`: Ponteiro que aponta para o nó anterior.
  - `struct No* next;`: Ponteiro que aponta para o próximo nó.

---

### **5. Inicialização da LDDE**

- Para inicializar uma lista duplamente encadeada, é necessário definir o primeiro elemento como `NULL`:
  ```c
  No* primeiro = NULL;
  No* ultimo = NULL;
  int n = 0;  // Contador de elementos na lista
  ```
  - **Explicação:** `primeiro` e `ultimo` são ponteiros que indicam o início e o fim da lista. Inicialmente, ambos são `NULL`, indicando que a lista está vazia.

---

### **6. Inserções na LDDE**

1. **Inserir em uma Lista Vazia:**
   - **Passos:**
     1. Alocar um novo nó.
     2. Definir o valor do nó.
     3. Fazer os ponteiros `prev` e `next` apontarem para `NULL`.
     4. Atualizar os ponteiros `primeiro` e `ultimo` para esse nó.
   - **Exemplo em C:**
     ```c
     No* novoNo = (No*) malloc(sizeof(No)); // Aloca memória para um novo nó
     novoNo->valor = 10;                    // Define o valor do nó como 10
     novoNo->prev = NULL;                   // Como é o primeiro, o ponteiro anterior é NULL
     novoNo->next = NULL;                   // Como é o último, o ponteiro próximo é NULL
     primeiro = novoNo;                     // Atualiza 'primeiro' para o novo nó
     ultimo = novoNo;                       // Atualiza 'ultimo' para o novo nó
     ```
   - **Explicação:** Cria-se um nó com valor `10`, que aponta para `NULL` tanto para frente quanto para trás, pois é o único nó da lista.

2. **Inserir no Início de uma Lista Não Vazia:**
   - **Passos:**
     1. Alocar um novo nó.
     2. Definir o valor do nó.
     3. Fazer o ponteiro `next` do novo nó apontar para o antigo primeiro.
     4. Atualizar o ponteiro `prev` do antigo primeiro nó para o novo nó.
     5. Atualizar o ponteiro `primeiro` para o novo nó.
   - **Exemplo em C:**
     ```c
     No* novoNo = (No*) malloc(sizeof(No)); // Aloca memória para um novo nó
     novoNo->valor = 20;                    // Define o valor do novo nó como 20
     novoNo->next = primeiro;               // Faz o novo nó apontar para o antigo primeiro
     novoNo->prev = NULL;                   // Como é o primeiro, o ponteiro anterior é NULL
     primeiro->prev = novoNo;               // Atualiza o ponteiro anterior do antigo primeiro nó
     primeiro = novoNo;                     // Atualiza 'primeiro' para o novo nó
     ```
   - **Explicação:** O novo nó é colocado no início da lista, e seus ponteiros são ajustados para apontar para o antigo primeiro.

3. **Inserir no Final de uma Lista Não Vazia:**
   - **Passos:**
     1. Alocar um novo nó.
     2. Definir o valor do nó.
     3. Fazer o ponteiro `prev` do novo nó apontar para o último nó.
     4. Fazer o ponteiro `next` do último nó apontar para o novo nó.
     5. Atualizar o ponteiro `ultimo` para o novo nó.
   - **Exemplo em C:**
     ```c
     No* novoNo = (No*) malloc(sizeof(No)); // Aloca memória para o novo nó
     novoNo->valor = 30;                    // Define o valor do novo nó como 30
     novoNo->prev = ultimo;                 // Faz o ponteiro anterior do novo nó apontar para o último nó
     novoNo

