# Heaps
_Arvores Heaps_

Após um pré-processamento em tempo Θ(n), uma heap permite obter repetidamente o maior/menor elemento em tempo Θ(log n). A inclusão de elementos na heap é feita em Θ(log n).

- Usando vetor ordenado:

  - Obter o maior/menor elemento seria em Θ(1).
  - Porém, gastaríamos
    - Θ(nlogn) no pré-processamento (ordenar o vetor).
    - Θ(n) para inserir elemento.

### Representação de heap em vetor
Uma heap é uma árvore binária complet(exceto talvez o último nível). Entãopode ser representada em vetor.
```
              01
      02              03
  04      05      06      07
08  09  10  11  12  13  14  15
```
Pai de i está na posição ⌊i/2⌋. Nó não tem pai.

Nó i tem 2i como filho esquerdo, 2i + 1 como filho direito.

Nó i tem filho esquerdo se 2i ≤ n, direito se 2i + 1 ≤ n.

Nó i é folha se não tem filhos, oseja, 2i > n.

Portanto, as folhas são ⌊n/2⌋ + 1, … , n − 1, n.

### Altura de um nó

Nós no nível p estão nas posições abaixo: (exceto talvez último nível)  
```2p, 2p+1, …, 2p + 1 − 1.```  
Logo,  
```2p ≤ i < 2p + 1 ⇒ log 22p ≤ log 2i < log 22p + 1 ⇒ p ≤ log 2i < p + 1.```  
Portanto, o nó i pertence ao nível p = ⌊log2i⌋. Assim, o total de níveis vale 1 + ⌊log2n⌋.

Altura do nó i: maior número de arestas de i até uma folha. Folhas tem altura zero.

Altura de i é o comprimento da sequência seguindo sempre o filho à esquerda:  
```2i, 22i, 23i, …, 2hi,```  
onde  
```2hi ≤ n < 2h + 1i.```  

```
log 2 (2hi) ≤ log 2n < log2(2h + 1i) ⇒ h + log 2i ≤ log 2n < (h + 1) + log 2i ⇒ h ≤ log 2(n / i) < h + 1
```
Portanto, a altura de i vale ```h=⌊log2(n/i)⌋```.

### Max-heaps

Um nó i satisfaz a propriedade de max-heap se o valor armazenado no pai é maior ou igual ao valor dos filhos, ou seja, ```A[i] ≥ A[⌊i / 2⌋] e A[i] ≥ A[⌊i / 2⌋ + 1]```. Uma árvore binária completa é max-heap se todo nó satisfaz a propriedade de max-heap. Definição é similar para min-heap. Portanto, o maior elemento sempre está na raiz da max-heap.

##### Heapify

A operação max-heapify recebe uma árvore binária completa onde apenas o elemento da raiz não satisfaz a propriedade de max-heap, e transforma esta árvore em uma max-heap. É um algoritmo recursivo, onde a 1a chamada deve ser MAX-HEAPIFY(A, n, 1).
```
MAX-HEAPIFY(A,n,i):
   esq <- 2*i; dir <- 2*i + 1; maior <- i                 O(1)
   se esq <= n e A[esq] > A[maior], então maior <- esq    O(1)
   se dir <= n e A[dir] > A[maior], então maior <- dir    O(1)
   se maior != i                                          O(1)
      troque A[i] com A[maior]                            O(1)
      MAX-HEAPIFY(A,n,maior)                              T(h-1)
```

```
T(h)=T(h−1)+O(1)∈O(h).
```

Então, T(h) ∈ O(lg n), pois h=⌊log 2n⌋.


### Make-heap

Como transformar um vetor inicial em uma heap (operação make-heap)?

Chame heapify do último até o 1o elemento. Assim, em cada chamada apenas a raiz não satisfaz a propriedade de max-heap. Como as folhas já satisfazem a propriedade, basta começar em ⌊n/2⌋.

```
MAKE-MAX-HEAP(A,n):
   para i <- |_n/2_| até 1 (ordem decrescente)
      MAX-HEAPIFY(A,n,i)
```

T(n) ∈ O(n . lg n).
Na verdade é possível mostrar que T(n) ∈ O(n).

Seja S(h) a soma das alturas dos nós de uma árvore binária completa de altura h. Então, S(0) = 0 e S(h) = 2 S(h − 1) + h. A solução desta recorrência vale S(h) = 2h + 1 − h − 2.

Prova por indução: Caso Base: S(0) = 20 + 1 − 0 − 2 = 0 (V).

Hipótese: S(h − 1) = 2h − 1 + 1 − (h − 1) − 2 = 2h − h − 1.
S(h) = 2S(h − 1) + h = 2(2h − h − 1) + h = 2h + 1 − h − 2.

Como make-heap realiza O(S(h)) = O(2h) operações, e h ∈ O(lg n), temos que make-heap é O(n).

### Heapsort
O heapsort utiliza uma max-heap para encontrar o maior elemento, inserindo no final do vetor. Em cada iteração ele troca o último elemento com o 1o, reduz em 1 o tamanho da heap, e chama max-heapify na raiz.
```
HEAPSORT(A,n):
   MAKE-MAX-HEAP(A,n)                     O(n)
   para tam_heap <- n até 2 (decrescente) O(n)
      troca A[1] com A[tam_heap]          O(n)
      MAX-HEAPIFY(A, tam_heap-1, 1)       O(n lg n)
```
T(n) ∈ O(n . lg n).

### Fila com prioridades
Tipo abstrato de dados que consiste em uma coleção S de itens, cada um com uma prioridade, e as operações:

- MAXIMUM(S): retorna o elemento de S com maior prioridade.
- EXTRACT-MAX(S): remove e retorna o elemento de S com maior prioridade.
- INCREASE-KEY(S,x,p): aumenta a prioridade de x para p.
- DECREASE-KEY(S,x,p): reduz a prioridade de x para p.
- INSERT(S,x,p): insere em S elemento x com prioridade p.


### Implementação com heap
```
MAXIMUM(A,n): // O(1)
   retorne A[1]

EXTRACT-MAX(A,n): // O(lg n)
   max <- A[1]
   troca A[1] com A[n]
   MAX-HEAPIFY(A, n-1, 1)
   retorne max

INCREASE-KEY(A,i,p): // O(lg n). Assume que p >= A[i].
   A[i] <- p
   enquanto i > 1 e A[i] > A[|_i/2_|]
      troca A[i] com A[|_i/2_|]
      i <- |_i/2_|

DECREASE-KEY(A,n,i,p): // O(lg n). Assume que p <= A[i].
   A[i] <- p
   MAX-HEAPIFY(A,n,i)

HEAP-INSERT(A,n,p): // O(lg n). Assume que A tem espaço p/ novo elemento.
   INCREASE-KEY(A, n+1, p)
```
