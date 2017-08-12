Utilizando o problema HAMILTONIANO, mostre que o problema CAIXEIRO_VIAJANTE é NP-Completo.
Assuma que o problema HAMILTONIANO é NP-Completo.

HAMILTONIANO: Dado um grafo não-direcionado G, ele contém ciclo hamiltoniano?
Um ciclo hamiltoniano é um ciclo que passa exatamente uma vez em cada vértice, ou seja, todos os vértices no grafo incidem em exatamente duas arestas do ciclo.

CAIXEIRO_VIAJANTE: Dado um grafo não-direcionado completo G com pesos não-negativos nas arestas, e um limite k, existe um ciclo que passa em todos os vértices e possui custo no máximo k?

Você deve mostrar que:
- CAIXEIRO_VIAJANTE pertence a NP.
- Existe um algoritmo polinomial que transforma uma entrada G de HAMILTONIANO em uma entrada de CAIXEIRO_VIAJANTE, de modo que CAIXEIRO_VIAJANTE responde SIM sse G possui ciclo hamiltoniano.
Dica: use custos binários no grafo de entrada do CAIXEIRO_VIAJANTE.

-----------------
Assumindo uma instancia do CAIXEIRO_VIAJANTE. Utilizando uma sequencia de n vertices, o algoritmo de verificacao confirma que a sequencia contem cada vertice apenas uma vez e verifica se a soma é no maximo k. De certo modo, esse processo pode ser realizado em tempo polinomial. Com isso podemos assumir que o CAIXEIRO_VIAJANTE pertence a NP.

Seja G = (V, E) uma instancia do caminho HAMILTONIANO. Seja G' um grafo do CAIXEIRO_VIAJANTE construida em tempo polinomial, onde G' = (V, E'), com E' = {(i, j) | i, j pertence a V, i != j} com custo C (i, j) = 0 se (i, j) pertence a E, e C(i, j) = 1 se (i, j) nao pertence a E.

Suponha que o grafo G tenha um ciclo HAMILTONIANO H. Cada aresta em H pertence a E e, portanto, tem custo 0 em G'. Desse modo, H é um circuito em G' com custo 0. Reciprocamente, suponhamos que o grafo G' tem um circuito H' de custo maximo 0. Tendo em vista que os custos em E' sao 0 e 1, o custo da viagem H' é exatamente 0, e cada aresta no circuito deve ter custo 0. Entao, H' contem apenas arestas em E. Concluimos que H' é um ciclo HAMILTONIANO no grafo G.
