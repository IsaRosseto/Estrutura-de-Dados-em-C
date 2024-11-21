### **Resumo Completo da Aula 2 - Listas Dinâmicas Encadeadas (LDE)**

---

### **1. Estruturas de Dados Dinâmicas**
- **Definição:** Estruturas de dados que guardam informações de maneira flexível, podendo crescer ou diminuir conforme a necessidade. Elas não precisam ter um tamanho fixo como os vetores.
- **Por que usar?** Com listas dinâmicas, evitamos desperdiçar memória, pois criamos apenas o espaço que realmente precisamos. 

---

### **2. Lista Dinâmica Encadeada (LDE)**
- **O que é?** É como uma corrente de nós, onde cada nó (ou "célula") está conectado ao próximo através de um link chamado **ponteiro**. Cada nó tem um valor e aponta para o próximo.
- **Elementos da LDE:**
  - Cada "elo" da corrente, ou seja, cada **nó**, tem:
    1. Um **valor** que guarda a informação.
    2. Um **ponteiro** que mostra qual é o próximo nó da lista.
  - O último nó sempre aponta para **NULL** (nada), mostrando que é o fim da lista.

---

### **3. Características da LDE**
- **Armazenamento Encadeado:** Cada nó está ligado ao próximo, formando uma cadeia. Se quisermos acessar um elemento, precisamos ir de nó em nó.
- **Flexibilidade:** Podemos facilmente aumentar ou diminuir o tamanho da lista, adicionando ou removendo nós conforme necessário.
- **Tipos de Operações:**
  - **Consultas:** Procurar um elemento, achar o maior ou menor valor, etc.
  - **Modificações:** Adicionar ou remover nós da lista.

---

### **4. Estrutura da Célula na LDE**
- **Exemplo em C para criar um nó:**
  ```c
  typedef struct No {
      int valor;
      struct No* proximo;
  } No;
  ```
- **Explicação:**
  - `typedef struct No { ... } No;`: Cria um tipo chamado `No` que será usado para definir os nós da lista.
  - `int valor;`: Cada nó guarda um valor.
  - `struct No* proximo;`: Cada nó tem um ponteiro que aponta para o próximo nó da lista.

---

### **5. Inicialização da LDE**
- Para criar uma lista, começamos dizendo que não existe nenhum elemento nela:
  ```c
  No* primeiro = NULL;
  int n = 0;  // Contador de elementos na lista
  ```
  - **Explicação:** Aqui, `primeiro` é um ponteiro que aponta para o início da lista. Inicialmente, ele é `NULL`, pois a lista está vazia.

---

### **6. Inserção na LDE**
1. **Inserir no Início de uma Lista Vazia:**
   - **Passos:**
     1. Criar um novo nó.
     2. Colocar o valor no novo nó e apontar para `NULL`.
     3. Fazer o ponteiro `primeiro` apontar para esse novo nó.
   - **Exemplo em C:**
     ```c
     No* novoNo = (No*) malloc(sizeof(No));
     novoNo->valor = 10;
     novoNo->proximo = NULL;
     primeiro = novoNo;
     ```
   - **Explicação Simples:** Cria-se um novo nó com valor `10`, que aponta para nada (`NULL`). Agora, esse nó se torna o primeiro da lista.

2. **Inserir no Início de uma Lista Não Vazia:**
   - **Passos:**
     1. Criar um novo nó.
     2. Colocar o valor no novo nó.
     3. Fazer o novo nó apontar para o antigo primeiro.
     4. Atualizar o ponteiro `primeiro` para esse novo nó.
   - **Exemplo em C:**
     ```c
     No* novoNo = (No*) malloc(sizeof(No));
     novoNo->valor = 20;
     novoNo->proximo = primeiro;
     primeiro = novoNo;
     ```
   - **Explicação Simples:** Um novo nó com valor `20` é criado e colocado na frente do antigo primeiro nó. Assim, `20` passa a ser o novo primeiro.

3. **Inserir no Final de uma Lista:**
   - **Passos:**
     1. Criar um novo nó e definir seu valor, apontando para `NULL`.
     2. Percorrer a lista até o último nó.
     3. Fazer o último nó apontar para o novo nó.
   - **Exemplo em C:**
     ```c
     No* novoNo = (No*) malloc(sizeof(No));
     novoNo->valor = 30;
     novoNo->proximo = NULL;
     No* atual = primeiro;
     while (atual->proximo != NULL) {
         atual = atual->proximo;
     }
     atual->proximo = novoNo;
     ```
   - **Explicação Simples:** Criamos um nó com valor `30`. Depois, caminhamos até o final da lista e conectamos esse nó no final.

---

### **7. Remoção na LDE**
1. **Remover do Início:**
   - **Passos:**
     1. Criar um ponteiro temporário que aponta para o primeiro nó.
     2. Atualizar `primeiro` para apontar para o próximo nó.
     3. Liberar a memória do nó removido.
   - **Exemplo em C:**
     ```c
     No* temp = primeiro;
     primeiro = primeiro->proximo;
     free(temp);
     ```
   - **Explicação Simples:** O primeiro nó é removido, e agora o segundo nó passa a ser o novo primeiro.

2. **Remover do Final:**
   - **Passos:**
     1. Percorrer a lista até encontrar o penúltimo nó.
     2. Fazer o penúltimo nó apontar para `NULL`.
     3. Liberar a memória do último nó.
   - **Exemplo em C:**
     ```c
     No* atual = primeiro;
     No* anterior = NULL;
     while (atual->proximo != NULL) {
         anterior = atual;
         atual = atual->proximo;
     }
     anterior->proximo = NULL;
     free(atual);
     ```
   - **Explicação Simples:** Andamos até o penúltimo nó, desconectamos o último e liberamos sua memória.

---

### **8. Exemplo Visual**
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


