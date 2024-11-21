### **Resumo Completo da Aula 6 - Filas Dinâmicas**

---

### **1. Definição de Filas Dinâmicas**

- **O que são Filas Dinâmicas?**
  - Uma fila dinâmica é uma estrutura de dados que segue a regra FIFO (First In, First Out), ou seja, o primeiro elemento a ser inserido é o primeiro a ser removido.
  - Diferente da fila estática, a fila dinâmica utiliza alocação dinâmica de memória, permitindo que o tamanho da fila cresça ou diminua conforme a necessidade.

---

### **2. Etapas da Implementação**

1. **Criação dos Modelos**
   - A fila dinâmica é composta por nós, cada nó possuindo um valor e um ponteiro que aponta para o próximo elemento da fila.

   - **Representação Visual Detalhada:**
     ```
     +-------+     +-------+     +-------+
     | Valor |     | Valor |     | Valor |
     |  10   | --> |  20   | --> |  30   | --> NULL
     +-------+     +-------+     +-------+
        |             |             |
      Ponteiro      Ponteiro      Ponteiro
     (próximo)     (próximo)     (próximo)
     ```
     Cada retângulo representa um nó, contendo um valor e um ponteiro para o próximo nó. O ponteiro indica o próximo nó na sequência ou `NULL` se for o último.

2. **Inicialização de uma Fila**
   - A fila dinâmica é inicializada com o ponteiro `head` apontando para `NULL`, indicando que a fila está vazia no início.

3. **Enfileiramento em uma Fila Vazia**
   - Para inserir um elemento em uma fila vazia, um novo nó é criado e os ponteiros `head` e `tail` são atualizados para apontar para esse novo nó.
   - **Exemplo de Código em C:**
     ```c
     typedef struct No {
         int valor;
         struct No* proximo;
     } No;

     No* head = NULL;
     No* tail = NULL;

     // Inserção em uma fila vazia
     No* novoNo = (No*) malloc(sizeof(No));
     novoNo->valor = 10;
     novoNo->proximo = NULL;
     head = novoNo;
     tail = novoNo;
     ```
   - **Explicação Linha a Linha:**
     - `typedef struct No {...} No;`: Define a estrutura de um nó da fila, contendo um valor e um ponteiro para o próximo nó.
     - `No* head = NULL;`, `No* tail = NULL;`: Inicializa os ponteiros `head` e `tail` como `NULL` para indicar que a fila está vazia.
     - `No* novoNo = (No*) malloc(sizeof(No));`: Aloca dinamicamente memória para um novo nó.
     - `novoNo->valor = 10;`: Define o valor do novo nó como `10`.
     - `novoNo->proximo = NULL;`: Como é o único nó, seu ponteiro `proximo` aponta para `NULL`.
     - `head = novoNo;`, `tail = novoNo;`: Atualiza os ponteiros `head` e `tail` para apontar para o novo nó.

   - **Representação Visual após Inserção:**
     ```
     head/tail -> +-------+
                  | Valor |
                  |  10   | -> NULL
                  +-------+
                     |
                   Ponteiro (próximo)
     ```
     Aqui, `head` e `tail` apontam para o mesmo nó, pois há apenas um elemento na fila.

4. **Enfileiramento em uma Fila Não Vazia**
   - Quando a fila já possui elementos, um novo nó é criado e o ponteiro `tail->proximo` é atualizado para apontar para esse novo nó, e em seguida o ponteiro `tail` é atualizado.
   - **Exemplo de Código em C:**
     ```c
     No* novoNo = (No*) malloc(sizeof(No));
     novoNo->valor = 20;
     novoNo->proximo = NULL;
     tail->proximo = novoNo;
     tail = novoNo;
     ```
   - **Explicação Linha a Linha:**
     - `No* novoNo = (No*) malloc(sizeof(No));`: Aloca dinamicamente memória para um novo nó.
     - `novoNo->valor = 20;`: Define o valor do novo nó como `20`.
     - `novoNo->proximo = NULL;`: Como será o último nó, o ponteiro `proximo` aponta para `NULL`.
     - `tail->proximo = novoNo;`: Atualiza o ponteiro `proximo` do nó atual de `tail` para apontar para o novo nó.
     - `tail = novoNo;`: Atualiza o ponteiro `tail` para apontar para o novo nó.

   - **Representação Visual após Inserção:**
     ```
     head -> +-------+     +-------+
             | Valor |     | Valor |
             |  10   | --> |  20   | -> NULL
             +-------+     +-------+
                |             |
              Ponteiro      Ponteiro
             (próximo)     (próximo)
                           tail
     ```
     Agora, o `tail` aponta para o último nó inserido, enquanto `head` permanece no primeiro nó. Os ponteiros de cada nó conectam ao próximo elemento.

5. **Desenfileiramento em uma Fila Não Vazia**
   - Para remover um elemento da fila, o nó apontado por `head` é removido e `head` é atualizado para apontar para o próximo nó.
   - **Exemplo de Código em C:**
     ```c
     if (head != NULL) {
         No* temp = head;
         head = head->proximo;
         free(temp);
     }
     ```
   - **Explicação Linha a Linha:**
     - `if (head != NULL)`: Verifica se a fila não está vazia.
     - `No* temp = head;`: Cria um ponteiro temporário `temp` para armazenar o nó atual de `head`.
     - `head = head->proximo;`: Atualiza `head` para apontar para o próximo nó da fila.
     - `free(temp);`: Libera a memória do nó removido.

   - **Representação Visual após Remoção:**
     ```
     head -> +-------+
             | Valor |
             |  20   | -> NULL
             +-------+
                |
              Ponteiro
             (próximo)
             tail
     ```
     O ponteiro `head` agora aponta para o segundo nó, e o nó anterior é removido da memória.

6. **Desenfileiramento do Último Elemento**
   - Quando o último elemento é removido, tanto `head` quanto `tail` são atualizados para `NULL`, indicando que a fila está vazia novamente.

   - **Representação Visual após Remoção do Último Elemento:**
     ```
     head -> NULL
     tail -> NULL
     ```
     Com a remoção do último elemento, ambos os ponteiros `head` e `tail` indicam que a fila está vazia.

---

### **3. Conclusão sobre Filas Dinâmicas**

- **Vantagens:**
  - **Flexibilidade:** A fila pode crescer ou diminuir dinamicamente, evitando o desperdício de memória.
  - **Melhor Gerenciamento de Espaço:** Como a memória é alocada dinamicamente, o uso de memória é mais eficiente do que em uma fila estática.

- **Desvantagens:**
  - **Complexidade de Implementação:** Mais difícil de implementar do que uma fila estática, devido ao uso de ponteiros e alocação dinâmica de memória.
  - **Overhead de Memória:** Existe um custo adicional devido ao armazenamento dos ponteiros e ao gerenciamento da memória dinâmica.

---

Este resumo abrange os principais conceitos de filas dinâmicas, detalhando cada uma das etapas da implementação, com exemplos de código em C e explicações passo a passo. Caso precise de mais exemplos ou mais detalhes sobre as operações, estou à disposição!

