
### **Resumo Completo da Aula 9 - Tabela de Espalhamento (Hash)**

---

### **1. O que é uma Tabela de Espalhamento (Hash)?**

- **Definição:** Uma **tabela de espalhamento (hash)** é uma estrutura de dados especial que associa **chaves** de pesquisa a **valores**.
- **Finalidade:** Facilitar uma busca eficiente de elementos, com a complexidade de acesso **O(1)** no melhor dos casos.

---

### **2. Estratégias de Busca: Comparando Técnicas**

- **Busca Linear (lista não ordenada):** Complexidade **O(n)**.
- **Busca Binária (lista ordenada):** Complexidade **O(log n)**.
- **Tabela Hash:** Complexidade **O(1)** no melhor caso, devido ao uso de uma **função de espalhamento** que mapeia as chaves para índices da tabela.

---

### **3. Tabela de Endereçamento Direto**

- **Definição:** A tabela de endereçamento direto utiliza um vetor grande o suficiente para armazenar todos os valores possíveis, associando diretamente a chave ao índice do vetor.
- **Problema:** Se o conjunto de chaves for muito grande, o vetor pode ser extremamente espaçoso, desperdiçando muita memória, pois muitas posições ficarão vazias.

- **Exemplo de Código Explicado:**
  ```c
  #include <stdio.h>
  #include <stdlib.h>

  typedef struct {
      int idx;
      char nome[15];
      int idade;
  } registro;

  int main(void) {
      registro *tabela = malloc(10 * sizeof(registro));  // Alocando memória para 10 registros
      registro r1 = {2, "Joao", 14};
      tabela[2] = r1;  // Inserindo o registro r1 na posição 2 da tabela
      registro r2 = {3, "Jose", 23};
      tabela[3] = r2;  // Inserindo o registro r2 na posição 3 da tabela
      registro r3 = {5, "Pedro", 64};
      tabela[5] = r3;  // Inserindo o registro r3 na posição 5 da tabela
      registro r4 = {8, "Maria", 32};
      tabela[8] = r4;  // Inserindo o registro r4 na posição 8 da tabela

      // Exibindo todos os registros da tabela
      for (int i = 0; i < 10; i++) {
          printf("ID: %d\n", i);
          printf("Nome: %s\n", tabela[i].nome);
          printf("Idade: %d\n", tabela[i].idade);
          puts("");
      }
      return 0;
  }
  ```
  - **Explicação Detalhada:**
    - `registro *tabela = malloc(10 * sizeof(registro));` - Aloca um vetor de 10 registros para armazenar as informações.
    - Cada registro é inserido em uma posição específica (`tabela[2]`, `tabela[3]`, etc.).
    - Este exemplo mostra que muitas posições da tabela podem ficar vazias, o que leva ao desperdício de memória.

  - **Problema do Exemplo:** Caso tivéssemos chaves como `2` e `100002`, precisaríamos de um vetor com `100002` posições, desperdiçando espaço.

---

### **4. O que é uma Função Hash?**

- **Definição:** Uma **função hash** é uma função que mapeia uma chave para um valor inteiro, que será o índice da tabela hash.
- **Características Importantes:**
  - Deve ser fácil e rápida de computar.
  - Deve criar uma distribuição uniforme das chaves na tabela.
- **Exemplos de Funções Hash:**
  - **Método da Divisão:** `h(k) = k mod m`, onde `m` é o tamanho da tabela.
  - **Método da Dobra, Multiplicação, Hashing Universal**.

---

### **5. Colisões em Tabelas Hash**

- **O que é uma Colisão?** Quando duas chaves diferentes são mapeadas para o mesmo índice da tabela hash.
- **Como Resolver Colisões?**
  - **Encadeamento Externo (Separado):** Cada posição da tabela aponta para uma lista encadeada de chaves com o mesmo valor de hash.
  - **Endereçamento Aberto (Reespalhamento):** Utiliza uma nova função para buscar a próxima posição livre.
    - **Espalhamento Linear:** Busca pela próxima posição livre de maneira sequencial.

- **Exemplo Visual Explicado de Encadeamento Externo:**
  ```
  Índice:     Lista Encadeada
  0          -> NULL
  1          -> NULL
  2          -> [Joao, 14] -> NULL
  3          -> [Jose, 23] -> NULL
  4          -> NULL
  5          -> [Pedro, 64] -> NULL
  6          -> NULL
  7          -> NULL
  8          -> [Maria, 32] -> NULL
  9          -> NULL
  ```
  - **Explicação do Exemplo:** Neste exemplo, cada índice da tabela aponta para uma lista encadeada. No índice `2`, por exemplo, há um registro de "Joao" com `idade 14`. Caso haja colisão, os registros seriam adicionados como nós adicionais na lista encadeada correspondente ao índice.

---

### **6. Tratamento de Colisões - Endereçamento Aberto**

- **Endereçamento Aberto (Rehash):**
  - Consiste em aplicar uma função de reespalhamento `rh()` que, ao encontrar uma posição ocupada, busca a próxima posição livre.
  - **Espalhamento Linear:** Define a função de reespalhamento como a busca da próxima posição livre.
  - **Fórmula:** `rh(k) = (h(k) + i) mod M`, onde `i` é o número de tentativas e `M` é o tamanho da tabela.

- **Exemplo Explicado de Endereçamento Aberto - Espalhamento Linear:**
  - **Situação de Colisão:** Suponha que a chave `k` dê colisão na posição `h(k) = 5` e essa posição esteja ocupada.
  - **Reespalhamento:** O próximo índice a ser verificado é `rh(k) = (5 + 1) mod 10 = 6`.
  - **Colisão Repetida:** Se o índice `6` também estiver ocupado, busca-se `rh(k) = (5 + 2) mod 10 = 7`.
  - **Continuação:** O processo continua até encontrar uma posição livre.
  - **Explicação Visual:**
    ```
    Posição Inicial: 5 -> Ocupada
    Reespalhamento 1: 6 -> Ocupada
    Reespalhamento 2: 7 -> Livre (insere aqui)
    ```
  Esse exemplo ilustra como o espalhamento linear é usado para encontrar a próxima posição disponível.

---

### **7. Exemplo Completo de Inserção e Remoção em uma Tabela Hash**

- **Conjunto de Valores:** `{190, 322, 172, 89, 13, 4, 769, 61, 15, 76, 97, 28, 80, 76, 88}`.
- **Passos para Construir a Tabela Hash:**
  1. A tabela hash será um arranjo, de tamanho igual à quantidade de valores esperada, no qual cada posição é uma **Lista Duplamente Encadeada (LDE)**.
  2. Inicialize cada posição da hash com uma LDE vazia.
  3. Construa um procedimento para **inserir** um valor na hash.
  4. Construa um procedimento para **remover** um valor da hash.

- **Explicação Visual:**
  - Cada posição da tabela hash será inicializada como uma lista vazia. Quando um valor for mapeado para uma posição, ele será adicionado à lista correspondente.
  - **Inserção de `190` na posição `0`:**
    ```
    Índice 0: [190] -> NULL
    ```
  - **Inserção de `322` na mesma posição (colisão):**
    ```
    Índice 0: [190] -> [322] -> NULL
    ```
  - Isso mostra como as colisões são tratadas utilizando listas encadeadas.

---

### **8. Conclusão sobre Tabelas Hash**

- **Vantagens:**
  - Acesso extremamente rápido aos elementos, com complexidade **O(1)** no melhor caso.
  - Adequada para buscas eficientes.
- **Limitações:**
  - Em casos de muitas colisões, a performance pode ser prejudicada.
  - A escolha da função hash é crucial para o desempenho da tabela.

---

Este resumo abrange os principais conceitos sobre tabelas hash, desde a motivação e definição, até a construção e as principais estratégias de tratamento de colisões, com exemplos práticos e detalhados. Caso precise de mais exemplos ou queira explorar mais aplicações das tabelas hash, estou à disposição!

