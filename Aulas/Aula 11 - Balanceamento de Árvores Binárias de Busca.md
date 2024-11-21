### **Resumo Completo da Aula 11 - Balanceamento de Árvores Binárias de Busca**

---

### **1. Por que Balancear Árvores Binárias de Busca?**

- **Importância do Balanceamento:** O balanceamento é essencial para garantir a eficiência das operações em uma Árvore Binária de Busca (ABB). Uma árvore balanceada assegura que a profundidade de todos os nós está minimizada, garantindo a complexidade de busca, inserção e remoção em O(log n).
- **Problemas com Árvores Desbalanceadas:** Se a ABB não for balanceada, ela pode se comportar como uma lista, resultando em uma complexidade de O(n) para as operações, o que degrada significativamente o desempenho.

---

### **2. Árvores AVL - Adelson-Velskii and Landis' Tree**

- **Definição:** As **árvores AVL** são um tipo de árvore binária de busca auto-balanceada. Elas garantem que, para qualquer nó, a diferença entre as alturas dos ramos esquerdo e direito é, no máximo, uma unidade.
- **Fator de Balanceamento (FB):** O fator de balanceamento de um nó é definido como a diferença entre a altura da sub-árvore direita e a altura da sub-árvore esquerda:
  - **FB(v) = altura(sub-árvore direita) - altura(sub-árvore esquerda)**
  - Um nó é considerado **balanceado** quando seu FB é -1, 0 ou 1.
  - Se o FB for menor que -1 ou maior que 1, o nó está **desbalanceado** e precisa ser corrigido.

- **Exemplo Visual:**

  Considere uma árvore AVL balanceada e outra desbalanceada:

  **Árvore AVL Balanceada:**
  ```
          30
         /  \
       20    40
      /  \     \
    10   25    50
  ```
  **Árvore Desbalanceada:**
  ```
          30
         /
       20
      /
    10
  ```
  Na árvore desbalanceada, a profundidade da sub-árvore esquerda é muito maior do que a da sub-árvore direita, tornando a busca ineficiente.

---

### **3. Cálculo do Fator de Balanceamento**

- **Exemplo de Código em C para Cálculo da Altura e do Fator de Balanceamento:**
  ```c
  int MAX(int x, int y) {
      return (x >= y) ? x : y;
  }

  int altura(Vertice *x) {
      if (x == NULL) {
          return -1;
      }
      return MAX(altura(x->esq), altura(x->dir)) + 1;
  }

  int fatorBalanceamento(Vertice *x) {
      return altura(x->dir) - altura(x->esq);
  }
  ```
  - **Explicação:**
    - `MAX(int x, int y)`: Função para retornar o maior valor entre `x` e `y`.
    - `int altura(Vertice *x)`: Calcula a altura de um nó, retornando -1 se o nó for `NULL`.
    - `int fatorBalanceamento(Vertice *x)`: Calcula o fator de balanceamento do nó, subtraindo a altura da sub-árvore esquerda da altura da sub-árvore direita.

---

### **4. Correção de Desbalanceamentos - Rotações**

- **Rotações para Balanceamento:** Quando um nó fica desbalanceado, existem quatro tipos de rotações que podem ser aplicadas para restaurar o balanceamento da árvore:
  1. **Rotação para a Esquerda (Left-Rotate):** Aplicada quando o fator de balanceamento é maior que 1 e o fator da sub-árvore direita é maior ou igual a 0.
  2. **Rotação para a Direita (Right-Rotate):** Aplicada quando o fator de balanceamento é menor que -1 e o fator da sub-árvore esquerda é menor ou igual a 0.
  3. **Rotação Dupla para a Direita (Right-Left Rotate):** Aplicada quando o fator de balanceamento é maior que 1 e o fator da sub-árvore direita é menor que 0.
  4. **Rotação Dupla para a Esquerda (Left-Right Rotate):** Aplicada quando o fator de balanceamento é menor que -1 e o fator da sub-árvore esquerda é maior que 0.

- **Exemplo de Código em C para Rotação Simples para a Direita:**
  ```c
  Vertice* rotacaoDireita(Vertice* y) {
      Vertice* x = y->esq;  // Define x como o filho esquerdo de y
      Vertice* T2 = x->dir; // Armazena a sub-árvore direita de x em T2

      // Realiza a rotação
      x->dir = y;           // Faz y ser o filho direito de x
      y->esq = T2;          // Faz T2 ser o filho esquerdo de y

      // Retorna a nova raiz
      return x;             // x se torna a nova raiz
  }
  ```
  - **Explicação Linha a Linha:**
    - `Vertice* rotacaoDireita(Vertice* y)`: Função que realiza uma rotação simples para a direita.
    - `Vertice* x = y->esq`: Define `x` como o filho esquerdo do nó `y`.
    - `Vertice* T2 = x->dir`: Armazena a sub-árvore direita de `x` em `T2`.
    - `x->dir = y`: Faz `y` ser o filho direito de `x`.
    - `y->esq = T2`: Faz `T2` ser o filho esquerdo de `y`.
    - `return x`: Retorna `x`, que agora é a nova raiz após a rotação.

---

### **5. Exemplos de Correção de Desbalanceamento**

- **Casos Comuns de Correção:**
  - **Caso 1:** Se o fator de um nó `R` é ≥ 2 e o fator do filho direito é ≥ 0, aplica-se uma rotação para a esquerda em `R`.
  - **Caso 2:** Se o fator de um nó `R` é ≥ 2 e o fator do filho direito é < 0, aplica-se uma rotação para a direita no filho direito e depois uma rotação para a esquerda em `R`.
  - **Caso 3:** Se o fator de um nó `R` é ≤ -2 e o fator do filho esquerdo é ≤ 0, aplica-se uma rotação para a direita em `R`.
  - **Caso 4:** Se o fator de um nó `R` é ≤ -2 e o fator do filho esquerdo é > 0, aplica-se uma rotação para a esquerda no filho esquerdo e depois uma rotação para a direita em `R`.

---

### **6. Conclusão sobre Balanceamento de Árvores Binárias de Busca**

- **Importância:** O balanceamento é crucial para manter a eficiência de árvores binárias de busca, garantindo que a profundidade seja mantida a um nível que permita buscas, inserções e remoções eficientes.
- **Rotinas de Manutenção:** As rotações são operações fundamentais para restaurar o balanceamento sempre que a estrutura árvores AVL seja afetada por uma inserção ou remoção.
- **Eficiência:** O uso de árvores AVL é especialmente vantajoso em cenários em que é necessário manter uma performance consistente nas operações, evitando que a árvore se degrade para um comportamento similar ao de uma lista.

---

