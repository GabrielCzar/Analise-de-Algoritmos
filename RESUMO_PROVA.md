1. Explique como o uso de uma HEAP reduz a complexidade do algoritmo de PRIM.

Quando busca a aresta a aresta mais leve (ou mais barata) em um grafo é necessario
verificar todas as arestas para cada vertice existente. Logo a complexidade é O(v * (v + e)).

Com o uso de uma min-HEAP encontrar a arestas mais leve custaria log V. Quando adicionar um vertice
ao corte tem que usar o decrease-key em todos os vizinhos. Portanto, temos a complexidade de O(e * log v).

2. Programacao dinamica para o distancia de edicao. Mostre o prenchimento da matriz.

S1 = Correto
S2 = Certo

    C O R R E T O
  0 1 2 3 4 5 6 7
C 1 0 1 2 3 4 5 6
E 2 1 1 2 3 3 4 5
R 3 2 2 1 2 3 4 5
T 4 3 3 2 2 3 3 4
O 5 4 3 3 3 3 4 3



4. Processo de formcacao de um NP e exmplos de demosntracao 
