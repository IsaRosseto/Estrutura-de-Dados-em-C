### **Resumo da Aula 10 - Árvores Binárias de Busca**

---

### **1. Definição de Árvore**

- **Árvore**: Uma árvore é uma estrutura de dados não-linear composta por **nós**.
  - Cada nó possui um **pai** (exceto a raiz) e pode ter **filhos**.
  - A **raiz** é o nó que não possui pai.
  - **Nós-folha** são aqueles que não possuem filhos.
  - As árvores são usadas para modelar relações hierárquicas.

**Exemplo Visual de uma Árvore**:
```
       1 (Raiz)
      /  \
     2    3
    / \     \
   4   5     6
```
- O nó 1 é a raiz, 4 e 5 são nós-folha.

---

### **2. Árvore Binária**

- **Árvore Binária**: Cada nó pode ter no máximo **dois filhos**, chamados de **filho esquerdo** e **filho direito**.

**Representação Visual de Árvore Binária**:
```
       Pai
      /    \
  FilhoEsq  FilhoDir
```
- Cada nó possui até dois filhos.

---

### **3. Árvore Binária de Busca (ABB)**

- **Definição**: Em uma Árvore Binária de Busca, os valores na **sub-árvore esquerda** de um nó são menores ou iguais ao valor do próprio nó, enquanto os valores na **sub-árvore direita** são maiores ou iguais.
- Isso garante que a árvore esteja **ordenada**, facilitando buscas eficientes.

**Exemplo de Árvore Binária de Busca**:
```
       8
      / \
     3   10
    / \    \
   1   6   14
      / \   /
     4   7 13
```
- Os valores à esquerda são menores e à direita são maiores.

---

### **4. Travessia em Árvores**

- Como as árvores são estruturas não-lineares, podemos visitar seus nós de diferentes formas:
  - **Travessia em Ordem (In-Order)**: Primeiro visita a sub-árvore esquerda, depois o nó raiz, e por fim a sub-árvore direita.
  - **Travessia em Pré-Ordem (Pre-Order)**: Visita primeiro o nó raiz, depois a sub-árvore esquerda e em seguida a sub-árvore direita.
  - **Travessia em Pós-Ordem (Post-Order)**: Primeiro visita a sub-árvore esquerda, depois a direita, e por fim o nó raiz.

**Representação Visual das Travessias**:
- **Travessia em Ordem** (In-Order):
  ```
  1, 3, 4, 6, 7, 8, 10, 13, 14
  ```
- **Travessia em Pré-Ordem** (Pre-Order):
  ```
  8, 3, 1, 6, 4, 7, 10, 14, 13
  ```
- **Travessia em Pós-Ordem** (Post-Order):
  ```
  1, 4, 7, 6, 3, 13, 14, 10, 8
  ```

---

### **5. Operações em Árvores Binárias de Busca**

- **Inserção**:
  1. Começa pela raiz e compara o valor a ser inserido.
  2. Se o valor for menor, move para a sub-árvore esquerda; se for maior, move para a direita.
  3. Repete o processo até encontrar uma posição vazia.

**Representação Visual da Inserção**:
```
    8
   / \
  3   10
 / \    \
1   6   14
       
Inserindo 4:
      6
     /
    4
```
- O valor 4 foi inserido como filho esquerdo de 6.

**Código em C para Inserção em Árvore Binária de Busca**:
```c
#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

// Função para criar um novo nó
No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No)); // Aloca memória para o novo nó
    novoNo->valor = valor; // Define o valor do nó
    novoNo->esquerda = NULL; // Inicializa o filho esquerdo como NULL
    novoNo->direita = NULL; // Inicializa o filho direito como NULL
    return novoNo; // Retorna o novo nó criado
}

// Função para inserir um valor na árvore
No* inserir(No* raiz, int valor) {
    if (raiz == NULL) { // Se a árvore estiver vazia, cria um novo nó
        return criarNo(valor);
    }
    if (valor < raiz->valor) { // Se o valor for menor, insere na sub-árvore esquerda
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else { // Se o valor for maior ou igual, insere na sub-árvore direita
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz; // Retorna a raiz atualizada
}
```
- **Explicação do Código**:
  - `criarNo(int valor)`: Cria um novo nó e define seus filhos como `NULL`.
    - `malloc(sizeof(No))`: Aloca memória suficiente para armazenar um nó.
    - `novoNo->valor = valor`: Define o valor do nó como o valor fornecido.
    - `novoNo->esquerda = NULL` e `novoNo->direita = NULL`: Inicializa os filhos como nulos, já que o nó recém-criado ainda não possui filhos.
  - `inserir(No* raiz, int valor)`: Insere um valor na posição correta, seguindo as regras da Árvore Binária de Busca.
    - Se a `raiz` for `NULL`, cria um novo nó. Caso contrário, compara o valor e decide se deve inserir na sub-árvore esquerda ou direita.

- **Remoção**:
  1. Se o nó a ser removido não tiver filhos, simplesmente o remove.
  2. Se tiver um filho, o substitui pelo seu filho.
  3. Se tiver dois filhos, encontra o maior valor da sub-árvore esquerda ou o menor da sub-árvore direita para substitui-lo.

**Representação Visual da Remoção**:
```
    8
   / \
  3   10
 / \    \
1   6   14
       
Removendo 3:
    8
   / \
  6   10
 /    \
1     14
```
- O nó 3 foi removido e substituído pelo nó 6.

**Código em C para Remoção em Árvore Binária de Busca**:
```c
No* remover(No* raiz, int valor) {
    if (raiz == NULL) { // Se a árvore estiver vazia, retorna NULL
        return raiz;
    }
    if (valor < raiz->valor) { // Se o valor for menor, procura na sub-árvore esquerda
        raiz->esquerda = remover(raiz->esquerda, valor);
    } else if (valor > raiz->valor) { // Se o valor for maior, procura na sub-árvore direita
        raiz->direita = remover(raiz->direita, valor);
    } else { // Encontrou o nó a ser removido
        if (raiz->esquerda == NULL) { // Caso 1: Nó sem filho esquerdo
            No* temp = raiz->direita; // Armazena o filho direito
            free(raiz); // Libera a memória do nó atual
            return temp; // Retorna o filho direito
        } else if (raiz->direita == NULL) { // Caso 2: Nó sem filho direito
            No* temp = raiz->esquerda; // Armazena o filho esquerdo
            free(raiz); // Libera a memória do nó atual
            return temp; // Retorna o filho esquerdo
        }
        // Caso 3: Nó com dois filhos
        No* temp = raiz->direita; // Encontra o menor valor na sub-árvore direita
        while (temp && temp->esquerda != NULL) {
            temp = temp->esquerda;
        }
        raiz->valor = temp->valor; // Substitui o valor do nó a ser removido pelo menor valor encontrado
        raiz->direita = remover(raiz->direita, temp->valor); // Remove o nó duplicado na sub-árvore direita
    }
    return raiz; // Retorna a raiz atualizada
}
```
- **Explicação do Código**:
  - `remover(No* raiz, int valor)`: Remove um valor específico da árvore.
    - `if (raiz == NULL)`: Se a árvore estiver vazia, retorna `NULL`.
    - Encontra o nó a ser removido e trata os três casos possíveis: sem filhos, um filho, ou dois filhos.
    - Caso o nó tenha dois filhos, encontra o menor valor da sub-árvore direita para substituir o valor do nó removido.
    - `free(raiz)`: Libera a memória do nó que foi removido.

---

### **6. Propriedades das Árvores**

- **Tamanho**: Número total de nós na árvore.
- **Altura**: Distância da raiz até o nó mais profundo.
- **Profundidade (Nível)**: Distância de um nó até a raiz. O nó raiz normalmente tem nível 0.

**Exemplo Visual da Altura e Profundidade**:
```
       1
      / \
     2   3
    /
   4
```
- **Altura** da árvore: 3 (da raiz até o nó mais profundo).
- **Profundidade** do nó 4: 2.

---

### **7. Utilidade das Árvores Binárias de Busca**

- São úteis para **representar dados hierárquicos**.
- Operações como **inserção**, **remoção** e **busca** são eficientes, com complexidade de **O(log n)** no melhor caso, garantindo bom desempenho em grandes volumes de dados.

---

Este resumo cobre os principais conceitos abordados na aula sobre árvores binárias de busca, incluindo suas propriedades, travessias e operações fundamentais, com exemplos de código comentados linha a linha para maior compreensão. Caso precise de mais exemplos ou detalhamento adicional, estou à disposição!

