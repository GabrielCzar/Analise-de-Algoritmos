# Union Find
_Estrutura de Dados para Conjuntos Disjuntos_

Uma ED para conjuntos disjuntos mantém uma coleção {S1,S2,…,Sk} de conjuntos disjuntos, e suporta as operações:

- MAKE-SET(x):
cria novo conjunto {x}.

- UNION(x,y):
une os conjuntos (disjuntos) que contém x e y, digamos Sx e Sy, em um novo conjunto Sx∪Sy.
Os conjuntos Sx e Sy são descartados.

- FIND-SET(x):
retorna ponteiro para elemento representante do (único) conjunto que contém x.

_Exemplo de aplicação_: encontrar componentes conexos em grafo não direcionado.
```pseudo
COMPONENTES(Adj,n):
   para vértice v, faça MAKE-SET(v)      O(V) chamadas MAKE-SET
   para cada aresta (u,v),               O(E)
      se FIND-SET(u) != FIND-SET(v)      O(E) chamadas FIND-SET
         UNION(u,v)                      O(V) chamadas UNION

MESMO-COMPONENTE(u,v):
   retorne (FIND-SET(u) == FIND-SET(v))  O(1) chamadas FIND-SET
```

Uma operação isoladamente pode ter complexidade alta, mas queremos que a complexidade da sequência seja baixa (análise amortizada).

### Implementação com lista encadeada

O primeiro nó é o representante. Existe ponteiro para o último.
Cada elemento aponta para o representante.

- MAKE-SET(x): O(1).
- FIND-SET(x): O(1).
- UNION(x,y) concatena duas listas e gasta O(n), pois é necessário atualizar ponteiros para o representante.

Realizando N operações de MAKE-SET e UNION entre os valores.

Número de operações: 2n − 1 ∈ Θ(n).
Custo total: Θ(n2).
Custo amortizado por operação: Θ(n).

Podemos melhorar colocando a menor lista no final da maior.

Se atualizamos o representante de x, então x está na menor lista, e portanto a lista que contém x pelo menos dobra de tamanho em cada atualização. Portanto, o número de atualização de representante de um elemento é O(lgn).

Assim, o custo total será Θ(m + n . lg n).
Se m ≫ n, então o custo amortizado por operação será Θ(1).
Se m ∈ Θ(n), então cada operação terá custo amortizado Θ(lg n).

### Implementação com floresta de conjuntos disjuntos

Cada conjunto é uma árvore enraizada.
Cada elemento aponta para o pai.
A raiz é o representante, e aponta para si mesma.

```
MAKE-SET(x):
   pai[x] <- x

FIND-SET(x):
   se pai[x] = x, retorne x
   retorne FIND-SET(pai[x])

UNION(x,y):
   x' <- FIND-SET(x)
   y' <- FIND-SET(y)
   pai[y'] <- x'
```

A complexidade não é melhor, pois no pior caso cada árvore é uma lista encadeada, e localizar o representante seria O(n).

As heurísticas union by rank e path compression podem melhorar a complexidade, embora a análise não seja simples.

- Union by rank: na união colocamos a menor árvore como filha da maior árvore. rank[] fornece estimativa da altura da árvore.

```
MAKE-SET(x):
   pai[x] <- x
   rank[x] <- 0

UNION(x,y):
   x' <- FIND-SET(x)
   y' <- FIND-SET(y)
   se rank[x'] > rank[y'], então pai[y'] <- x'
   senão, pai[x'] <- y'
          se rank[x'] = rank[y']
             rank[y'] <- rank[y'] + 1
```

- Path compression: quando o representante passar por um nó nas chamadas recursivas de FIND-SET, aproveite e torne o nó filho do representante.

```
FIND-SET(x):
   se pai[x] != x
      pai[x] <- FIND-SET(pai[x])
   retorne pai[x]
```

Uma sequência de m operações MAKE-SET, UNION e FIND-SET pode ser executada em tempo O(m ⋅ α(n)) quando usamos floresta de conjuntos disjuntos com union by rank e path compression.

A função α(n) cresce muito lentamente: se n ≤ 22048 ≈ 3×10616, então α(n) ≤ 4. Portanto, em termos práticos, podemos tratar α(n) como uma constante.

Assim, o custo amortizado por operação é O(1).
