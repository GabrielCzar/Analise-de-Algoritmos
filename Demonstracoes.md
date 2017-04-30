
# Demostrações

- Seja f[u] o instante de término do vértice u após uma DFS no grafo acíclico G. Para toda arestas (u,v) de G, temos que f[u] > f[v].

O tempo final de um vértice x será representado desta maneira: f[x]

Quando se aplica uma ordenação topológica baseada na DFS em um grafo G,
os vértices são dispostos da esquerda para a direita.
Supondo que existe um caminho branco entre dois vértices distintos u e v,
isso implica que v é descendente de u na árvore de descendência.
Como temos um grafo acíclico logo não podemos ter uma aresta de retorno de v a u.
Na ordenação topológica como v é descendente de u,
o vértice u vem antes do v, com isso para o vértice u ser finalizado será necessário que o sejam exploradas as arestas de v,
logo ao percorrer todas as arestas de v esse mesmo vértice será finalizado,
deste modo se não tem aresta de retorno o vértice u só sera finalizado apos o vértice v, logo f[u] > f[v] para quaisquer vértices.
