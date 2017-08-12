#include <iostream>

using namespace std;

/*
DIJKSTRA(s):
       para todo vértice v, faça
              d[v] <- oo
              pi[v] <- NULO
       d[s] <- 0
       Q <- inicializadas com todos os vértices
       enquanto Q não está vazia
              u <- Pegar o menor em Q
       para cada vértice v em Adj[u]
                     RELAX(u,v)
                     atualizaQ(v,d[v])

*/

void dijkstra (int s) {
    for (int i = 0; i < MAX; i++) {

    }
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
