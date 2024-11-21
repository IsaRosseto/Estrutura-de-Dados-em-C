### **Resumo Completo da Aula 8 - Heaps**

---

### **1. O que é um Heap?**

- **Definição:** Em ciência da computação, um **heap** é uma estrutura de dados usada para armazenar um conjunto de elementos, geralmente em forma de árvore binária.
- **Tipos de Heap:** Existem dois tipos principais de heaps:
  - **Max-Heap:** Cada nó tem um valor maior ou igual ao dos seus filhos. O maior valor está na raiz.
  - **Min-Heap:** Cada nó tem um valor menor ou igual ao dos seus filhos. O menor valor está na raiz.

---

### **2. Propriedades dos Heaps**

- **Balanceamento Estrutural:** O heap é uma árvore binária quase completa, com exceção do último nível. Quando o último nível não está completo, as folhas devem estar o mais à esquerda possível.
- **Propriedade Estrutural:** Em um max-heap, o valor de cada nó é maior ou igual ao valor de seus filhos. Em um min-heap, o valor de cada nó é menor ou igual ao valor de seus filhos.

---

### **3. Representação de um Heap em um Vetor**

- **Armazenamento em Vetor:** Um heap pode ser armazenado em um vetor, onde cada posição do vetor corresponde a um nó da árvore.
- **Cálculo dos Filhos e Pais:**
  - **Raiz:** Sempre localizada na posição `0` do vetor.
  - **Filho Esquerdo:** O filho esquerdo de um nó de índice `i` é dado por `fe = 2 * i + 1`.
  - **Filho Direito:** O filho direito de um nó de índice `i` é dado por `fd = 2 * i + 2`.
  - **Pai:** O pai de um nó de índice `i` é dado por `p = (i - 1) / 2` (parte inteira).

- **Representação Visual Detalhada:**

  Um exemplo de max-heap:
  
  ```
          50
         /  \
       30    20
      /  \     \
    10  15     5
  ```
  Cada número representa um nó do heap, contendo um valor. O nó raiz contém o valor máximo (para um max-heap), e cada nó pai tem um valor maior ou igual ao de seus filhos.

---

### **4. Manutenção da Propriedade Estrutural (Sift)**

- **O que é Sift?** Caso um nó perca sua propriedade estrutural, podemos recuperá-la trocando-o com seu filho de maior valor (para max-heap) ou menor valor (para min-heap).

- **Exemplo de Sift em um Max-Heap:**

  Imagine que um nó no meio do heap tenha um valor menor que seu filho em um max-heap. Aplicamos o processo de **peneirar** (“sift”) para trocá-lo com o filho de maior valor, até que a propriedade seja restabelecida.

  **Passo a Passo do Processo de Sift:**
  
  - **Antes do sift:**
    ```
          20
         /  \
       50    30
    ```

  - **Depois do sift:**
    ```
          50
         /  \
       20    30
    ```
  No exemplo acima, o valor do nó raiz (20) é menor que o valor do filho esquerdo (50). Assim, realizamos a troca para manter a propriedade do max-heap.

---

### **5. Construção de um Heap**

- **Construir Heap a partir de um Vetor Qualquer:**
  - Podemos transformar qualquer vetor em um heap aplicando o processo de **sift** em todos os nós que são pais.
  - **Como Fazer:** Começamos pelos nós pais do último nível (índice `(n / 2) - 1` até `0`) e aplicamos o sift para cada um deles.

- **Representação Visual da Construção de um Heap:**

  - **Vetor Original:** `[10, 20, 15, 30, 40]`
  - **Passo 1 (aplicar sift no nó de índice 1):**
    ```
          40
         /  \
       30    15
      /
    10
    ```
  - **Passo 2 (aplicar sift no nó de índice 0):**
    ```
          40
         /  \
       30    15
      /
    10
    ```
  Após aplicar o sift em cada nó pai, o vetor original é transformado em um max-heap.

---

### **6. Operações Básicas em um Heap**

1. **Incluir Item no Heap**
   - **Passos:** Adicionamos o novo elemento na primeira posição livre do vetor e depois aplicamos o sift para cima, garantindo que a propriedade do heap seja mantida.
   - **Exemplo de Código em C:**
     ```c
     void inserirHeap(int heap[], int* tamanho, int valor) {
         heap[*tamanho] = valor;
         int i = *tamanho;
         (*tamanho)++;
         while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
             int temp = heap[i];
             heap[i] = heap[(i - 1) / 2];
             heap[(i - 1) / 2] = temp;
             i = (i - 1) / 2;
         }
     }
     ```
   - **Explicação Linha a Linha:**
     - `void inserirHeap(int heap[], int* tamanho, int valor)`: Função para inserir um valor no heap.
     - `heap[*tamanho] = valor;`: Adiciona o valor na primeira posição livre do vetor.
     - `int i = *tamanho;`: Inicializa o índice `i` com a posição do novo elemento.
     - `(*tamanho)++`: Incrementa o tamanho do heap.
     - `while (i > 0 && heap[(i - 1) / 2] < heap[i])`: Verifica se o valor do pai é menor que o valor do nó atual (para max-heap).
     - `int temp = heap[i]; heap[i] = heap[(i - 1) / 2]; heap[(i - 1) / 2] = temp;`: Troca os valores entre o pai e o nó atual.
     - `i = (i - 1) / 2;`: Atualiza o índice `i` para o pai, continuando o sift para cima.

2. **Remover Item do Heap (Remover o Máximo)**
   - **Passos:** Remover o elemento da raiz, substituir pela última folha, e aplicar o sift para baixo para restaurar a propriedade do heap.
   - **Exemplo de Código em C:**
     ```c
     int removerMaxHeap(int heap[], int* tamanho) {
         int max = heap[0];
         heap[0] = heap[*tamanho - 1];
         (*tamanho)--;
         int i = 0;
         while (2 * i + 1 < *tamanho) {
             int maiorFilho = 2 * i + 1;
             if (maiorFilho + 1 < *tamanho && heap[maiorFilho + 1] > heap[maiorFilho]) {
                 maiorFilho++;
             }
             if (heap[i] >= heap[maiorFilho]) break;
             int temp = heap[i];
             heap[i] = heap[maiorFilho];
             heap[maiorFilho] = temp;
             i = maiorFilho;
         }
         return max;
     }
     ```
   - **Explicação Linha a Linha:**
     - `int removerMaxHeap(int heap[], int* tamanho)`: Função para remover o valor máximo de um max-heap.
     - `int max = heap[0];`: Armazena o valor da raiz (maior valor).
     - `heap[0] = heap[*tamanho - 1];`: Substitui a raiz pela última folha.
     - `(*tamanho)--`: Reduz o tamanho do heap.
     - `int i = 0;`: Começa o sift para baixo a partir da raiz.
     - `while (2 * i + 1 < *tamanho)`: Percorre o heap enquanto houver filhos.
     - `int maiorFilho = 2 * i + 1;`: Inicializa `maiorFilho` com o filho esquerdo.
     - `if (maiorFilho + 1 < *tamanho && heap[maiorFilho + 1] > heap[maiorFilho])`: Verifica se o filho direito é maior que o esquerdo.
     - `if (heap[i] >= heap[maiorFilho]) break;`: Se o nó atual for maior ou igual ao maior filho, a propriedade está restabelecida.
     - `int temp = heap[i]; heap[i] = heap[maiorFilho]; heap[maiorFilho] = temp;`: Troca o nó atual com o maior filho.
     - `i = maiorFilho;`: Atualiza `i` para continuar o sift.

---

### **7. Conclusão sobre Heaps**

- **Vantagens dos Heaps:**
  - Permitem acesso rápido ao maior ou menor elemento.
  - São utilizados em algoritmos eficientes, como a ordenação por heap (Heapsort) e em filas de prioridade.
- **Limitações:**
  - Apesar de eficientes para acesso ao maior/menor elemento, o acesso a outros elementos do heap não é tão eficiente quanto em outras estruturas, como arrays ordenados.

---

