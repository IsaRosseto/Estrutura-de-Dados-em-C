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


2. **🛠️ Remoção:**
   - **No final:** Simples, basta liberar a última posição.
   - **No meio/início:** Requer deslocar elementos para preencher o espaço.
   - **Complexidade:**
     - Final: O(1).
     - Meio/Início: O(n).


3. **🔍 Acesso:**
   - Direto pelo índice. Exemplo: `Lista[3]` acessa o quarto elemento.
   - **Complexidade:** O(1).

4. **🛡 Pesquisa:**
   - Verifica cada elemento até encontrar o valor desejado.
   - **Complexidade:** O(n).

5. **🗒 Atualização:**
   - Substitui o valor de um índice específico.
   - **Complexidade:** O(1).

---

### **9. Ponteiros e Movimentação em Listas Dinâmicas**

#### **🔌 Ponteiros**
- Um **ponteiro** é uma variável que guarda o endereço de memória de outra variável.
- **Ponteiros em listas dinâmicas** permitem a criação de estruturas que podem crescer ou diminuir conforme a necessidade, diferente da LES que tem tamanho fixo.


- **Exemplo em C:** Para criar um nó que armazena um valor e aponta para o próximo:
  ```c
  typedef struct No {
      int valor;
      struct No* proximo;
  } No;
  ```
  Aqui, `struct No* proximo` é um ponteiro que aponta para o próximo nó na lista.

  **Explicação das Linhas de Código:**
  - `typedef struct No { ... } No;`: Define uma estrutura chamada `No`, que representa um elemento da lista.
  - `int valor;`: Define um campo que guarda o valor do nó.
  - `struct No* proximo;`: Define um ponteiro que aponta para o próximo nó da lista, permitindo a criação de uma cadeia de nós.

#### **🚴 Movimentação dos Ponteiros**
- **Inserção em Listas Dinâmicas:**
  1. Crie um novo nó.
  2. Atualize o ponteiro do nó anterior para apontar para o novo nó.
  3. O novo nó deve apontar para o próximo nó (se houver).
  - **Exemplo:**
    ```c
    No* novoNo = (No*) malloc(sizeof(No));
    novoNo->valor = 10;
    novoNo->proximo = atual->proximo;
    atual->proximo = novoNo;
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
    No* temp = atual->proximo;
    atual->proximo = temp->proximo;
    free(temp);
    ```

    **Explicação das Linhas de Código:**
    - `No* temp = atual->proximo;`: Cria um ponteiro temporário `temp` que aponta para o nó que será removido.
    - `atual->proximo = temp->proximo;`: Atualiza o ponteiro do nó atual para apontar para o próximo nó do nó que será removido.
    - `free(temp);`: Libera a memória alocada para o nó removido, evitando vazamento de memória.


---

### **10. Exemplo Visual**
Para uma lista de tamanho 5:
```plaintext
Índice:      0    1    2    3    4
Lista:      [2]  [4]  [5]  [8]  [_]
```
- **🛠️ Inserção no final:** `Lista[4] = 10` → `[2, 4, 5, 8, 10]`.
- **🛠️ Remoção no meio:** Remover índice 1 → `[2, 5, 8, 10, _]`.
- **🗒 Atualização:** Alterar índice 2 para `7` → `[2, 5, 7, 10, _]`.


---


