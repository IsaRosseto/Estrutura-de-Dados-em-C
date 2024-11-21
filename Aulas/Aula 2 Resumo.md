### **Resumo Completo da Aula 2 - Listas Dinâmicas Encadeadas (LDE)**

---

### **1. Estruturas de Dados Dinâmicas**

- **Definição:** Estruturas de dados que alocam memória de forma dinâmica, permitindo aumentar ou diminuir de tamanho conforme a necessidade.
- **Vantagem sobre listas estáticas:** Mais flexibilidade, evitando desperdício de memória e problemas relacionados ao tamanho fixo dos arrays.

---

### **2. Lista Dinâmica Encadeada (LDE)**

- **O que é?** Uma lista dinâmica em que cada elemento (ou célula) está ligado ao próximo através de um ponteiro.
- **Elementos da LDE:**
  - Cada célula contém:
    1. Um **valor** (os dados armazenados).
    2. Um **ponteiro** que aponta para o próximo elemento da lista.
  - A última célula tem um ponteiro nulo (`NULL`), indicando o fim da lista.

---

### **3. Características da LDE**

- **Armazenamento Encadeado:** Cada elemento armazena o valor e o ponteiro para o próximo, formando uma cadeia.
- **Flexibilidade:** Permite o crescimento dinâmico, adicionando ou removendo elementos conforme a necessidade.
- **Tipos de Operações: **
  - **Consultas:** Buscar um elemento, identificar menor/maior valor, retornar sucessor ou predecessor.
  - **Modificações:** Inserção ou remoção de elementos.

---

### **4. Estrutura da Célula na LDE**

- **Estrutura típica em C:**
  ```c
  typedef struct No {
      int valor;           // Campo que armazena o valor do nó
      struct No* proximo;  // Ponteiro para o próximo nó na lista
  } No;                    // Define o tipo 'No' para ser usado na lista
  ```
- **Explicação das Linhas de Código:**
  - `typedef struct No { ... } No;`: Cria uma estrutura chamada `No`, que representa um elemento da lista.
  - `int valor;`: Cada nó guarda um valor.
  - `struct No* proximo;`: Define um ponteiro que aponta para o próximo nó da lista, formando a cadeia de elementos.

---

### **5. Inicialização da LDE**

- Para inicializar uma lista dinâmica encadeada, precisamos definir o primeiro elemento como nulo:
  ```c
  No* primeiro = NULL;
  int n = 0;  // Contador de elementos na lista
  ```
  - **Explicação:** Aqui, `primeiro` é um ponteiro que aponta para o início da lista. No início, ele aponta para `NULL`, indicando que a lista está vazia.

---

### **6. Inserção na LDE**

1. **Inserir no Início de uma Lista Vazia:**
   - **Passos:**
     1. Alocar uma nova célula.
     2. Definir o valor e o ponteiro da nova célula.
     3. Fazer o ponteiro `primeiro` apontar para a nova célula.
   - **Exemplo em C:**
     ```c
     No* novoNo = (No*) malloc(sizeof(No)); // Alocando memória para um novo nó
     novoNo->valor = 10;                   // Definindo o valor do novo nó como 10
     novoNo->proximo = NULL;               // Como a lista estava vazia, o próximo aponta para NULL
     primeiro = novoNo;                    // Faz o ponteiro 'primeiro' apontar para o novo nó
     ```
   - **Explicação:** Cria-se um novo nó com valor `10`, que aponta para nada (`NULL`). Agora, esse nó se torna o primeiro da lista.

2. **Inserir no Início de uma Lista Não Vazia:**
   - **Passos:**
     1. Alocar uma nova célula.
     2. Definir o valor da nova célula.
     3. Fazer a nova célula apontar para o antigo primeiro elemento.
     4. Atualizar `primeiro` para apontar para a nova célula.
   - **Exemplo em C:**
     ```c
     No* novoNo = (No*) malloc(sizeof(No)); // Alocando memória para um novo nó
     novoNo->valor = 20;                   // Definindo o valor do novo nó como 20
     novoNo->proximo = primeiro;           // Faz o novo nó apontar para o antigo primeiro nó
     primeiro = novoNo;                    // Atualiza 'primeiro' para o novo nó
     ```
   - **Explicação:** Um novo nó com valor `20` é criado e colocado na frente do antigo primeiro nó. Assim, `20` passa a ser o novo primeiro.

3. **Inserir no Final de uma Lista:**
   - **Passos:**
     1. Alocar uma nova célula.
     2. Definir o valor da nova célula e fazer seu ponteiro apontar para `NULL`.
     3. Percorrer a lista até encontrar o último elemento.
     4. Fazer o último elemento apontar para a nova célula.
   - **Exemplo em C:**
     ```c
     No* novoNo = (No*) malloc(sizeof(No)); // Alocando memória para o novo nó
     novoNo->valor = 30;                   // Definindo o valor do novo nó como 30
     novoNo->proximo = NULL;               // Como será o último, aponta para NULL
     No* atual = primeiro;                 // Cria um ponteiro para percorrer a lista
     while (atual->proximo != NULL) {      // Percorre a lista até o último elemento
         atual = atual->proximo;
     }
     atual->proximo = novoNo;              // Faz o último elemento apontar para o novo nó
     ```
   - **Explicação:** Criamos um nó com valor `30`. Depois, caminhamos até o final da lista e conectamos esse nó no final.

---

### **7. Remoção na LDE**

1. **Remover do Início:**
   - **Passos:**
     1. Criar um ponteiro temporário que aponta para o primeiro nó.
     2. Atualizar `primeiro` para apontar para o próximo nó.
     3. Liberar a memória do nó removido.
   - **Exemplo em C:**
     ```c
     No* temp = primeiro;          // Cria um ponteiro temporário que aponta para o primeiro nó
     primeiro = primeiro->proximo; // Atualiza 'primeiro' para apontar para o próximo nó
     free(temp);                   // Libera a memória do nó removido
     ```
   - **Explicação:** O primeiro nó é removido, e agora o segundo nó passa a ser o novo primeiro.

2. **Remover do Final:**
   - **Passos:**
     1. Percorrer a lista até encontrar o penúltimo elemento.
     2. Fazer o penúltimo elemento apontar para `NULL`.
     3. Liberar a memória do último elemento.
   - **Exemplo em C:**
     ```c
     No* atual = primeiro;       // Ponteiro para percorrer a lista
     No* anterior = NULL;        // Ponteiro para guardar o nó anterior
     while (atual->proximo != NULL) { // Percorre até o último elemento
         anterior = atual;
         atual = atual->proximo;
     }
     anterior->proximo = NULL;   // O penúltimo nó passa a apontar para NULL
     free(atual);                // Libera a memória do último nó
     ```
   - **Explicação:** Andamos até o penúltimo nó, desconectamos o último e liberamos sua memória.

---

### **8. Exemplo Visual Melhorado**

Para ilustrar como funciona uma lista dinâmica encadeada, imagine os nós da lista como vagões de um trem, onde cada vagão guarda um número e aponta para o próximo vagão. Vamos usar uma representação visual mais clara:

```plaintext
[ Início ] -> [ 20 | * ] -> [ 10 | * ] -> [ 30 | NULL ]
```
- **Inserir no início:** Adicionar `40` no início da lista:
  ```plaintext
  [ Início ] -> [ 40 | * ] -> [ 20 | * ] -> [ 10 | * ] -> [ 30 | NULL ]
  ```
  Aqui, o novo nó com valor `40` foi adicionado antes do valor `20`. O ponteiro do nó `40` aponta para o próximo nó (`20`), e o ponteiro do nó `30` aponta para `NULL`, indicando que é o fim da lista.

- **Remover o último elemento:** Remover o valor `30` do final da lista:
  ```plaintext
  [ Início ] -> [ 40 | * ] -> [ 20 | * ] -> [ 10 | NULL ]
  ```
  O último nó (`30`) foi removido, e agora o nó `10` é o último, apontando para `NULL`.

---

