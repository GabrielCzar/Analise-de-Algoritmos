
# Demostrações

#### Seja f[u] o instante de término do vértice u após uma DFS no grafo acíclico G. Para toda arestas (u,v) de G, temos que f[u] > f[v].

- V1

```
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
```

- V2

``` 
Caso 1º Quando U é encontrado antes de V no DFS.
Se existe uma aresta de U para V, e U é encontrado primeiro do que V, podemos concluir que no momento de que U é Inicializado existe um caminho branco de U para V, pois U é anterior de V e não existe uma aresta de retorno de V para U, pois o gráfico G é acíclico. Pela estrutura de parênteses, se U é anterior de V o D(V) e F(V) está contido dentro de D(U) e F(U), logo F(U) > F(V).

Caso 2º Quando V é encontrado antes de U no DFS.
Se existe aresta de U para V e o gráfico G é acíclico, significa que é não existe um caminho ou aresta de V para U, isso significa que U é inacessível  a partir de V, logo quando U for descoberto significa que V já terá terminado todo o seu DFS, assim podemos concluir que V já estará preto no momento que U inicializar,  então tanto o D(U) é maior que F(V) como também F(U) > F(V).
```

- V3

``` 
Considere que f[u] é o instante final do vértice u e f[v] é o instante final do vértice v após ocorrer a DFS em um grafo acíclico G.

Considere o instante que a aresta (u,v) foi identificada. Neste momento v não pode ser cinza, pois caso contrário a aresta (u,v) seria uma aresta de retorno. Pela definição, um grafo G admite ordenação topológica se e somente se G é acíclico. Deste modo, se houver uma aresta de retorno o grafo G apresentará ciclo, assim, não permitindo ordenação topológica e invalidando a propriedade que queremos provar: f[u] > f[v].

Caso v seja branco, v é descendente de u, logo v será finalizado antes de u, então f[v] < f[u].

Caso v seja preto, v já foi finalizado e já temos o instante f[v], porém u ainda não foi finalizado, logo f[v] < f[u].
```

- V4 

``` 

```

