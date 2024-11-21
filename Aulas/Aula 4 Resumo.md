### **Resumo Completo da Aula 4 - Complexidade de Algoritmos**

---

### **1. O que é Complexidade de Algoritmos?**

- **Definição:** A complexidade de um algoritmo é uma medida da eficiência em termos de tempo de execução e consumo de recursos, considerando o tamanho da entrada.
- **Importância:** Determinar a complexidade nos ajuda a entender o quão eficiente é uma solução para um determinado problema, independentemente do hardware ou do compilador utilizado.

---

### **2. Como Medir a Complexidade?**

- Podemos contar quantas vezes as operações são executadas em um código.
- **Exemplo prático:** Em vez de medir diretamente o tempo, contamos quantas vezes um laço repete, pois o tempo pode variar com o hardware e o compilador.
- **Foco no termo dominante:** A análise de complexidade costuma focar no termo que mais cresce conforme o tamanho da entrada (n).

---

### **3. Tipos de Complexidade**

- **Melhor Caso:** Cenário em que o algoritmo executa o menor número possível de operações.
- **Pior Caso:** Cenário em que o algoritmo realiza o maior número de operações.
- **Caso Médio:** Um valor intermediário que representa uma situação comum de execução.

---

### **4. Exemplos de Código e Análise de Complexidade**

#### **Exemplo 1: Laço Simples**

- **Código:**
  ```c
  #include <stdio.h>

  int main(void) {
      int count = 0;
      int i = 1;
      while(i <= 1000) {
          printf("%d\n", i);
          i = i + 1;
          count = count + 1;
      }
      printf("%d\n", count);
      return 0;
  }
  ```
- **Explicação Linha a Linha:**
  - `int count = 0;`: Inicializa o contador que será usado para contar quantas vezes o laço é executado.
  - `int i = 1;`: Inicializa a variável `i` com o valor 1, que será usada para controlar o laço.
  - `while(i <= 1000)`: O laço executa enquanto `i` for menor ou igual a 1000. Como `i` começa em 1 e é incrementado até 1000, o laço executa exatamente 1000 vezes.
  - `printf("%d\n", i);`: Imprime o valor atual de `i` a cada iteração do laço.
  - `i = i + 1;`: Incrementa `i` em 1 a cada iteração.
  - `count = count + 1;`: Incrementa `count` em 1 a cada iteração para contar quantas vezes o laço executou.
  - `printf("%d\n", count);`: Imprime o valor final de `count`, que será 1000.
- **Complexidade:**
  - O laço executa 1000 vezes, portanto, a complexidade é **O(n)**, onde **n = 1000**.

#### **Exemplo 2: Laço com Entrada Variável**

- **Código:**
  ```c
  #include <stdio.h>

  int main(void) {
      int n;
      scanf("%d", &n);
      int count = 0;
      int i = 1;
      while(i <= n) {
          printf("%d\n", i);
          i = i + 1;
          count = count + 1;
      }
      printf("%d\n", count);
      return 0;
  }
  ```
- **Explicação Linha a Linha:**
  - `int n;`: Declara a variável `n` que irá armazenar o valor de entrada.
  - `scanf("%d", &n);`: Lê um valor inteiro do usuário e armazena em `n`.
  - `int count = 0;`: Inicializa o contador para contar as iterações do laço.
  - `int i = 1;`: Inicializa a variável `i` com o valor 1 para controlar o laço.
  - `while(i <= n)`: O laço executa enquanto `i` for menor ou igual a `n`. Portanto, o número de iterações depende do valor de `n` fornecido pelo usuário.
  - `printf("%d\n", i);`: Imprime o valor de `i` a cada iteração.
  - `i = i + 1;`: Incrementa `i` em 1 a cada iteração.
  - `count = count + 1;`: Incrementa `count` para contar as iterações.
  - `printf("%d\n", count);`: Imprime o valor final de `count`, que será igual ao valor de `n`.
- **Complexidade:**
  - O laço repete **n** vezes, portanto, a função de complexidade é **f(n) = n**.

#### **Exemplo 3: Encontrar o Elemento Máximo**

- **Código:**
  ```c
  #include <stdio.h>

  int main(void) {
      int v[] = {5, 7, 9, 6, 2, 4, 7, 8, 10, 1};
      int max = v[0];
      for(int i = 1; i < 10; i++) {
          if(v[i] > max)
              max = v[i];
      }
      printf("%d\n", max);
      return 0;
  }
  ```
- **Explicação Linha a Linha:**
  - `int v[] = {5, 7, 9, 6, 2, 4, 7, 8, 10, 1};`: Declara um vetor `v` com 10 elementos inteiros.
  - `int max = v[0];`: Inicializa a variável `max` com o primeiro valor do vetor, assumindo que este seja o maior inicialmente.
  - `for(int i = 1; i < 10; i++)`: Inicia um laço para percorrer o vetor a partir do segundo elemento (índice 1) até o último (índice 9).
  - `if(v[i] > max)`: Verifica se o elemento atual do vetor é maior que o valor armazenado em `max`.
  - `max = v[i];`: Se a condição for verdadeira, atualiza `max` com o novo valor maior.
  - `printf("%d\n", max);`: Imprime o maior valor encontrado no vetor.
- **Complexidade:**
  - No pior caso, percorre todos os 9 elementos restantes do vetor, portanto, a complexidade é **f(n) = n - 1**.

---

### **5. Notação Assintótica**

- **O que é?** Uma forma de descrever o crescimento de uma função, permitindo classificar a eficiência de algoritmos sem precisar de valores exatos.
- **Principais Notações:**
  - **O(f(n))**: Limite superior do crescimento (pior caso).
  - **Ω(f(n))**: Limite inferior (melhor caso).
  - **Θ(f(n))**: Crescimento equivalente (caso médio).

---

### **6. Exemplos de Funções de Complexidade**

- **Função Constante (f(n) = c):**
  - O número de operações é sempre o mesmo, independentemente do tamanho da entrada.

- **Função Logarítmica (f(n) = log n):**
  - Algoritmos que dividem o problema em partes menores, como na busca binária.

- **Função Linear (f(n) = n):**
  - O número de operações é proporcional ao tamanho da entrada, como em um laço simples.

- **Função Quadrática (f(n) = n²):**
  - Algoritmos que possuem dois laços aninhados, como em alguns algoritmos de ordenação.

- **Função Exponencial (f(n) = 2^n):**
  - Algoritmos que duplicam o número de operações a cada incremento da entrada, geralmente considerados ineficientes.

---

### **7. Exemplo Visual de Complexidades**

Imagine diferentes formas de crescimento do tempo de execução de acordo com o tamanho da entrada **n**:

- **Constante (O(1))**: 👍 Sempre o mesmo tempo, não importa quantos elementos tenhamos.
- **Linear (O(n))**: ⬆️ Cresce proporcionalmente ao tamanho da entrada.
- **Quadrática (O(n²))**: 🛠️ O crescimento é mais rápido, com dois laços aninhados.
- **Exponencial (O(2^n))**: ⚡ Crescimento muito rápido, dificilmente prático para grandes entradas.

---

### **8. Busca Sequencial e Bubble Sort**

- **Busca Sequencial:**
  - **Melhor Caso:** 1 (o elemento está na primeira posição).
  - **Pior Caso:** n (o elemento está na última posição ou não está).
  - **Complexidade:** O(n).

- **Bubble Sort:**
  - **Melhor Caso:** O(n) (quando o vetor já está ordenado).
  - **Pior Caso e Caso Médio:** O(n²).

---

### **9. Conclusão sobre Complexidade**

- **Por que entender a complexidade?**
  - Para escolher a solução mais eficiente e que melhor se adapte ao problema.
  - Evitar soluções que não sejam práticas para grandes volumes de dados.
- **Dicas Importantes:**
  - Sempre tente simplificar a função de complexidade focando no termo dominante.
  - Entenda a diferença entre **pior caso**, **melhor caso** e **caso médio** para fazer uma boa análise de desempenho.

---


