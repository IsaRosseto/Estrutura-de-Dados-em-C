### **Resumo Completo da Aula 1 - Listas Estáticas Sequenciais (LES)**

---

### **1. Estruturas de Dados**

- **Definição:** São formas organizadas de armazenar, acessar e manipular dados de forma eficiente.
- **Por que usar?** Para resolver problemas de forma estruturada, otimizando recursos e operações.

---

### **2. Lista**

- **O que é?** Uma sequência de elementos em uma ordem específica.
- **Principais implementações:**
  1. **Lista Estática:** Usa arrays e tem tamanho fixo.
  2. **Lista Dinâmica:** Usa ponteiros para alocar memória conforme a necessidade.

---

### **3. Lista Linear**

- **🔎 Características:**
  1. 🛠️ Organização sequencial (elemento após elemento).
  2. 🤖 Cada elemento tem no máximo um predecessor (anterior) e um sucessor (seguinte).
- **👩‍💻 Importância:** É uma estrutura básica usada para criar outras estruturas mais complexas.

---

### **4. Tipos de Listas Lineares**

1. **📅 Lista Estática Sequencial (LES):**
   - 🛠️ Elementos armazenados em memória contígua usando arrays.
2. **🤖 Lista Estática Encadeada (LEE):**
   - Combina arrays com ponteiros para representar conexões.
3. **📀 Lista Dinâmica Encadeada (LDE):**
   - Usa alocação dinâmica de memória e ponteiros.
4. **🤜🤛 Lista Dinâmica Duplamente Encadeada (LDDE):**
   - Cada elemento tem dois ponteiros: um para o anterior e outro para o seguinte.

---

### **5. Características da LES**

1. **🔠 Acesso Direto:**
   - Elementos acessados pelo índice. Exemplo: `Lista[2]` acessa diretamente o terceiro elemento.
2. **📅 Tamanho Fixo:**
   - Definido no momento da criação. Não pode crescer ou diminuir.
3. **🧐 Uso de Memória Contígua:**
   - Elementos armazenados em sequência na memória, o que melhora a eficiência de acesso devido à localidade espacial.

---

### **6. Vantagens da LES**

1. **🚀 Eficiência no Acesso:**
   - Acesso rápido (O(1)) a qualquer elemento.
2. **👍 Simplicidade:**
   - Fácil de implementar e manipular, especialmente em linguagens como C.

---

### **7. Desvantagens da LES**

1. **💩 Flexibilidade Limitada:**
   - Tamanho fixo pode desperdiçar memória ou ser insuficiente.
2. **💡 Inserção e Remoção Ineficientes:**
   - No meio ou início da lista, exige deslocamento de elementos.

---

### **8. Operações Básicas da LES**

1. **🛠️ Inserção:**

   - **No final:** Simples, basta ocupar o próximo índice vazio.
   - **No meio/início:** Requer deslocar elementos para abrir espaço.
   - **Complexidade:**
     - Final: O(1).
     - Meio/Início: O(n).

   **Exemplo Visual e Código em C: Inserindo um elemento no final**
   ```plaintext
   Lista: [2, 4, 5, 8, _]
   Inserindo 10 no final:
   Lista: [2, 4, 5, 8, 10]
   ```
   ```c
   int lista[5] = {2, 4, 5, 8}; // Definindo um array com 4 valores e um espaço vazio
   lista[4] = 10; // Inserindo o valor 10 na última posição disponível
   ```
   - Aqui, estamos adicionando o valor `10` na última posição disponível da lista.

2. **🛠️ Remoção:**

   - **No final:** Simples, basta liberar a última posição.
   - **No meio/início:** Requer deslocar elementos para preencher o espaço.
   - **Complexidade:**
     - Final: O(1).
     - Meio/Início: O(n).

   **Exemplo Visual e Código em C: Removendo um elemento do meio**
   ```plaintext
   Lista: [2, 4, 5, 8, 10]
   Removendo 5:
   Lista: [2, 4, 8, 10, _]
   ```
   ```c
   int lista[5] = {2, 4, 5, 8, 10}; // Definindo um array com 5 valores
   for (int i = 2; i < 4; i++) {     // Iniciando um loop para mover elementos, começando da posição do valor a ser removido
       lista[i] = lista[i + 1];     // Cada elemento é substituído pelo próximo, movendo os valores para a esquerda
   }
   lista[4] = 0; // Limpa a última posição para indicar que não está sendo usada
   ```
   - Nesse exemplo, removemos o valor `5` e movemos os outros elementos para preencher o espaço.

3. **🔍 Acesso:**

   - Direto pelo índice. Exemplo: `Lista[3]` acessa o quarto elemento.
   - **Complexidade:** O(1).
   
   **Exemplo em C:**
   ```c
   int valor = lista[2]; // Acessando o terceiro elemento do array (índice 2)
   ```
   - Aqui, acessamos o terceiro elemento da lista (índice 2).

4. **🛡 Pesquisa:**

   - Verifica cada elemento até encontrar o valor desejado.
   - **Complexidade:** O(n).
   
   **Exemplo em C:**
   ```c
   int valor_procurado = 8; // Valor que queremos encontrar na lista
   for (int i = 0; i < 5; i++) { // Percorrendo cada elemento do array
       if (lista[i] == valor_procurado) { // Se o valor do array na posição i for igual ao valor procurado
           printf("Valor encontrado na posição %d\n", i); // Imprime a posição onde o valor foi encontrado
           break; // Encerra o loop após encontrar o valor
       }
   }
   ```
   - Este código procura pelo valor `8` na lista e imprime a posição onde ele foi encontrado.

5. **🗒 Atualização:**

   - Substitui o valor de um índice específico.
   - **Complexidade:** O(1).

   **Exemplo em C:**
   ```c
   lista[2] = 7; // Atualizando o valor na posição 2 para 7
   ```
   - Aqui, estamos atualizando o valor da posição 2 para `7`.

---

### **9. Ponteiros e Movimentação em Listas Dinâmicas**

#### **🔌 Ponteiros**

- Um **ponteiro** é uma variável que guarda o endereço de memória de outra variável.

- **Ponteiros em listas dinâmicas** permitem a criação de estruturas que podem crescer ou diminuir conforme a necessidade, diferente da LES que tem tamanho fixo.

- **Exemplo em C:** Para criar um nó que armazena um valor e aponta para o próximo:

  ```c
  typedef struct No {
      int valor;           // Campo que armazena o valor do nó
      struct No* proximo;  // Ponteiro para o próximo nó na lista
  } No;                    // Define o tipo 'No' para ser usado na lista
  ```
  Aqui, `struct No* proximo` é um ponteiro que aponta para o próximo nó na lista.

#### **🚴 Movimentação dos Ponteiros**

- **Inserção em Listas Dinâmicas:**

  1. Crie um novo nó.
  2. Atualize o ponteiro do nó anterior para apontar para o novo nó.
  3. O novo nó deve apontar para o próximo nó (se houver).

  - **Exemplo:**
    ```c
    No* novoNo = (No*) malloc(sizeof(No)); // Alocando memória para um novo nó
    novoNo->valor = 10;                   // Definindo o valor do novo nó como 10
    novoNo->proximo = atual->proximo;     // Faz o novo nó apontar para o próximo nó da lista
    atual->proximo = novoNo;              // Atualiza o nó atual para apontar para o novo nó
    ```
    **Explicação das Linhas de Código:**
    - `No* novoNo = (No*) malloc(sizeof(No));`: Aloca memória para um novo nó e armazena o endereço em `novoNo`.
    - `novoNo->valor = 10;`: Atribui o valor `10` ao campo `valor` do novo nó.
    - `novoNo->proximo = atual->proximo;`: Faz o ponteiro `proximo` do novo nó apontar para o próximo nó na sequência.
    - `atual->proximo = novoNo;`: Atualiza o ponteiro do nó atual para apontar para o novo nó, inserindo-o na lista.

- **Remoção em Listas Dinâmicas:**

  1. Atualize o ponteiro do nó anterior para apontar para o nó seguinte ao que será removido.
  2. Libere a memória do nó removido.

  - **Exemplo:**
    ```c
    No* temp = atual->proximo;         // Cria um ponteiro temporário que aponta para o nó a ser removido
    atual->proximo = temp->proximo;    // Faz o nó atual apontar para o próximo nó, removendo a referência ao nó intermediário
    free(temp);                        // Libera a memória alocada para o nó removido
   

