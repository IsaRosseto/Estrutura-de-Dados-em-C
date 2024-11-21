### **Resumo Completo da Aula 5 - Fila Estática**

---

### **1. O que é um Arranjo (Vetor)?**

- **Definição:** Um arranjo, ou vetor, é uma estrutura de dados que armazena elementos do mesmo tipo em uma sequência contígua de memória.
- **Alocação:** A alocação de um vetor é feita definindo o tipo de dado e a quantidade de elementos. Um bloco contíguo de memória é reservado para armazenar todos os elementos.
- **Acesso:** O acesso aos elementos é fácil, pois eles estão organizados de forma sequencial, facilitando cálculos aritméticos para acessar qualquer posição.

---

### **2. Alocação de Memória para Vetores**

- **Bloco de Memória Contígua:** Um vetor reserva uma quantidade específica de bits contíguos na memória. Por exemplo, para armazenar um vetor de inteiros positivos `V = [4, 7, 10, 3, 2, 4, 5]`, cada valor pode ocupar 4 bytes, o que totaliza 28 bytes contíguos na memória.
- **Cálculo do Endereço:** Para acessar um elemento específico, multiplicamos o índice do elemento pelo tamanho do tipo de dado (em bytes) e somamos ao endereço base do vetor. Por exemplo, acessar o elemento de índice 5 significa calcular `5 x 4 = 20` bytes a partir do endereço inicial.

---

### **3. Fila Estática**

- **Definição:** Uma fila estática é uma estrutura de dados que segue a regra FIFO (First In, First Out), ou seja, o primeiro elemento a entrar é o primeiro a sair.
- **Implementação com Vetores:** A fila pode ser implementada usando um vetor estático, onde os elementos são inseridos e removidos de acordo com a regra FIFO.

---

### **4. Regra FIFO (First In, First Out)**

- **Analogia:** Imagine uma fila de pessoas em um banco. A primeira pessoa que chega é a primeira a ser atendida. A mesma ideia se aplica para as filas em estruturas de dados.
- **Pontos de Acesso:**
  - **Head (Cabeça):** O ponto onde os elementos são removidos da fila.
  - **Tail (Cauda):** O ponto onde os elementos são inseridos na fila.

---

### **5. Operações na Fila Estática**

1. **Inserção (Enqueue):**
   - **Condição:** Para inserir um novo elemento na fila, deve haver espaço disponível. Se a fila estiver cheia, não é possível inserir mais elementos.
   - **Exemplo de Código em C:**
     ```c
     #include <stdio.h>
     #define TAMANHO_FILA 5

     int main() {
         int fila[TAMANHO_FILA];
         int tail = 0;
         int novo_elemento = 10;

         if (tail == TAMANHO_FILA) {
             printf("Fila cheia, não é possível inserir um novo elemento\n");
         } else {
             fila[tail] = novo_elemento; // Insere o novo elemento na posição indicada por 'tail'
             tail++; // Incrementa o ponteiro 'tail' para a próxima posição
         }

         return 0;
     }
     ```
   - **Explicação Linha a Linha:**
     - `#define TAMANHO_FILA 5`: Define o tamanho máximo da fila como 5.
     - `int fila[TAMANHO_FILA];`: Declara um vetor `fila` com tamanho 5 para armazenar os elementos.
     - `int tail = 0;`: Inicializa o ponteiro `tail` que indica onde o próximo elemento será inserido.
     - `int novo_elemento = 10;`: Define o valor do novo elemento a ser inserido.
     - `if (tail == TAMANHO_FILA)`: Verifica se a fila está cheia comparando `tail` com o tamanho da fila.
     - `fila[tail] = novo_elemento;`: Insere o novo elemento na posição indicada por `tail`.
     - `tail++;`: Incrementa `tail` para a próxima posição disponível na fila.

2. **Remoção (Dequeue):**
   - **Condição:** A remoção só pode ocorrer se houver elementos na fila. Se a fila estiver vazia, não há nada para remover.
   - **Exemplo de Código em C:**
     ```c
     #include <stdio.h>
     #define TAMANHO_FILA 5

     int main() {
         int fila[TAMANHO_FILA] = {10, 20, 30, 40, 50};
         int head = 0;
         int tail = 5; // Indica que há 5 elementos na fila

         if (head == tail) {
             printf("Fila vazia, não é possível remover um elemento\n");
         } else {
             int elemento_removido = fila[head]; // Remove o elemento na posição 'head'
             printf("Elemento removido: %d\n", elemento_removido);
             head++; // Incrementa 'head' para apontar para o próximo elemento
         }

         return 0;
     }
     ```
   - **Explicação Linha a Linha:**
     - `#define TAMANHO_FILA 5`: Define o tamanho máximo da fila como 5.
     - `int fila[TAMANHO_FILA] = {10, 20, 30, 40, 50};`: Inicializa a fila com 5 elementos.
     - `int head = 0;`: Inicializa o ponteiro `head` que indica o próximo elemento a ser removido.
     - `int tail = 5;`: Define `tail` como 5, indicando que todos os espaços estão ocupados.
     - `if (head == tail)`: Verifica se a fila está vazia comparando `head` com `tail`.
     - `int elemento_removido = fila[head];`: Remove o elemento da posição indicada por `head`.
     - `printf("Elemento removido: %d\n", elemento_removido);`: Imprime o elemento removido.
     - `head++;`: Incrementa `head` para apontar para o próximo elemento da fila.

---

### **6. Problemas da Fila Estática**

- **Limitação de Espaço:** Uma vez que a fila atinge o tamanho máximo, novos elementos não podem ser inseridos, mesmo que haja espaços livres nas primeiras posições devido às remoções. Isso é chamado de **problema do subaproveitamento**.
- **Solução:** Para resolver esse problema, podemos usar uma **fila circular**, onde os ponteiros `head` e `tail` voltam ao início do vetor quando chegam ao fim.

---

### **7. Fila Circular**

- **Definição:** A fila circular é uma modificação da fila estática, onde os ponteiros `head` e `tail` são reajustados para o início do vetor assim que alcançam o final, aproveitando melhor o espaço.
- **Exemplo de Código em C:**
  ```c
  #include <stdio.h>
  #define TAMANHO_FILA 5

  int main() {
      int fila[TAMANHO_FILA];
      int head = 0, tail = 0;
      int novo_elemento = 10;

      // Inserção na Fila Circular
      if ((tail + 1) % TAMANHO_FILA == head) {
          printf("Fila cheia, não é possível inserir um novo elemento\n");
      } else {
          fila[tail] = novo_elemento; // Insere o novo elemento na posição indicada por 'tail'
          tail = (tail + 1) % TAMANHO_FILA; // Atualiza 'tail' de forma circular
      }

      return 0;
  }
  ```
- **Explicação Linha a Linha:**
  - `#define TAMANHO_FILA 5`: Define o tamanho máximo da fila como 5.
  - `int fila[TAMANHO_FILA];`: Declara um vetor `fila` com tamanho 5 para armazenar os elementos.
  - `int head = 0, tail = 0;`: Inicializa os ponteiros `head` e `tail` indicando que a fila está vazia.
  - `int novo_elemento = 10;`: Define o valor do novo elemento a ser inserido.
  - `if ((tail + 1) % TAMANHO_FILA == head)`: Verifica se a fila está cheia usando o operador módulo para permitir comportamento circular.
  - `fila[tail] = novo_elemento;`: Insere o novo elemento na posição indicada por `tail`.
  - `tail = (tail + 1) % TAMANHO_FILA;`: Atualiza `tail` de forma circular para apontar para a próxima posição disponível.

---

### **8. Conclusão sobre Filas Estáticas**

- **Vantagens:**
  - Simples de implementar.
  - Boa para cenários em que sabemos previamente o número máximo de elementos.

- **Desvantagens:**
  - O tamanho é fixo e não pode ser alterado durante a execução.
  - Problemas de subaproveitamento de espaço, que podem ser resolvidos com a implementação de filas circulares.

---


