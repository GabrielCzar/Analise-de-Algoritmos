# Floyd-Warshall
_Esse algoritmo é utilizado para encontrar caminhos minimos entre todos os pares_

Para encontrar os caminhos mínimos entre todos os pares de vértices, podemos executar |V| vezes:
- Dijkstra (quando não tem pesos negativos), gastando V * O(V^2 . logV) = O(V^3 . log V) em grafos densos.
- Bellman-Ford (quando não tem ciclo negativo), gastando V×O(V3)=O(V4) em grafos densos.

Podemos melhorar usando prog. dinâmica: algoritmo de Floyd-Warshall.

Como no Bellman-Ford, vamos supor que existem arestas de peso negativo, mas sem ciclo negativo.

Convencionamos que arestas que não existem no grafo são inseridas com peso w[i, j] = ∞.

Seja d(i, j, k) a função que retorna o tamanho do caminho mínimo de i até j passando apenas pelos vértices {1, 2, …, k}.

d(i, j, 0) = w[i, j], pois aresta direta não passa por outros vértices.

A solução final é obtida chamando d(i, j, n).

Como calcular d(i, j, k) usando d(i, j, k − 1)?

```py
def d(i, j, k):
   if k = 0:
     return w[i, j]
   return min (d(i, j, k - 1), d(i, k, k - 1) + d(k,j,k-1))
```
- Observação: Preenchimento de D[i,j,k] pode ser em qualquer ordem para i e j, mas deve ser em ordem crescente para k.

- Complexidade: O(V^3).

Para 15 vértices, a programação dinâmica executou em 0.000013 segundos, e o algoritmo recursivo em 37.6289 segundos. Ou seja, a programação dinâmica foi 2.9 milhões de vezes mais rápida.

- Floyd-Warshall com programação dinâmica:

```c++
using namespace std;

template <const unsigned int N>
void floyd_warshall(double w[N + 1][N + 1], double D[N + 1][N + 1][N + 1]) {
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      D[i][j][0] = w[i][j];

  for (int k = 1; k <= N; k++)
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= N; j++)
        D[i][j][k] = min(D[i][j][k - 1], D[i][k][k - 1] + D[k][j][k - 1]);
}

```
