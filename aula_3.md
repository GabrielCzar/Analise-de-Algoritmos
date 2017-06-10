BFS(G, s): // busca em largura
   // INICIALIZAÇÃO                                       // Lista       // Matriz
 1 para cada vértice u de G (excluindo o s)               // O(v)
 2    cor[u] <- branco; d[u] <- oo; pi[u] <- NULO         // O(v)
 3 cor[s] <- cinza; d[s] <- 0; pi[s] <- NULO              // O(1)

 4 declare uma fila vazia Q                               // O(1)
 5 insira s na fila Q                                     // O(1)
 6 enquanto Q não é vazia                                 // O(v)
 7    remova o próximo elem. da fila Q e o armazene em u  // O(v)
 8    para cada vértice v em Adj[u]                       // O(v + e)    // O(v²)
 9       se cor[v] = branco                               // O(e)        // 
10          cor[v] <- cinza; d[v] <- d[u] + 1; pi[v] <- u // O(e)        // 
11          insira v na fila Q                            // O(e)        // 
12    cor[u] <- preto                                     // O(v)        // 
                                                          //---------
                                                          // O(v + e)
-------------------------------------                     // Denso e = O(v²) - muistas aresta
                                                          // Espaço e = O(v)

//Seja dist(v) o menor numero de arestas de s ate vazia
//Para toda aresta (u, v), temos q que dist(v) < dist(w) + 1




DFS-VISIT(u)
   cor[u] <- cinza
   d[u] <- tempo <- tempo + 1
   para cada v adjacente a u
      se cor[v] = branco
         pi[v] <- u
         DFS-VISIT(v)
   cor[u] <- preto
   f[u] <- tempo <- tempo + 1

DFS(Adj[], n)
   para cada vértice u
      cor[u] <- branco; pi[u] <- NULO
   tempo <- 0BFS(G,s):
   // INICIALIZAÇÃO
 1 para cada vértice u de G (excluindo o s)
 2    cor[u] <- branco; d[u] <- oo; pi[u] <- NULO
 3 cor[s] <- cinza; d[s] <- 0; pi[s] <- NULO

 4 declare uma fila vazia Q
 5 insira s na fila Q
 6 enquanto Q não é vazia
 7    remova o próximo elem. da fila Q e o armazene em u
 8    para cada vértice v em Adj[u]
 9       se cor[v] = branco
10          cor[v] <- cinza; d[v] <- d[u] + 1; pi[v] <- u
11          insira v na fila Q
12    cor[u] <- preto

---------------------------

DFS-VISIT(u)
   cor[u] <- cinza
   d[u] <- tempo <- tempo + 1
   para cada v adjacente a u
      se cor[v] = branco
         pi[v] <- u
         DFS-VISIT(v)
   cor[u] <- preto
   f[u] <- tempo <- tempo + 1

DFS(Adj[], n)
   para cada vértice u
      cor[u] <- branco; pi[u] <- NULO
   tempo <- 0
   para cada vértice u
      se cor[u] = branco
         DFS-VISIT(u)

----------------------------

// Grafo não direcionado do exemplo da busca em largura:

#define N 8
list<int> Adj[N];
enum Vertices {s,w,r,t,x,v,u,y};
             //0 1 2 3 4 5 6 7

void inicializa_grafo()
{
   Adj[s].push_back(w);
   Adj[s].push_back(r);
   Adj[r].push_back(s);
   Adj[r].push_back(v);
   Adj[v].push_back(r);
   Adj[w].push_back(s);
   Adj[w].push_back(t);
   Adj[w].push_back(x);BFS(G,s):
   // INICIALIZAÇÃO
 1 para cada vértice u de G (excluindo o s)
 2    cor[u] <- branco; d[u] <- oo; pi[u] <- NULO
 3 cor[s] <- cinza; d[s] <- 0; pi[s] <- NULO

 4 declare uma fila vazia Q
 5 insira s na fila Q
 6 enquanto Q não é vazia
 7    remova o próximo elem. da fila Q e o armazene em u
 8    para cada vértice v em Adj[u]
 9       se cor[v] = branco
10          cor[v] <- cinza; d[v] <- d[u] + 1; pi[v] <- u
11          insira v na fila Q
12    cor[u] <- preto

-------------------------------------

DFS-VISIT(u)
   cor[u] <- cinza
   d[u] <- tempo <- tempo + 1
   para cada v adjacente a u
      se cor[v] = branco
         pi[v] <- u
         DFS-VISIT(v)
   cor[u] <- preto
   f[u] <- tempo <- tempo + 1

DFS(Adj[], n)
   para cada vértice u
      cor[u] <- branco; pi[u] <- NULO
   tempo <- 0BFS(G,s):
   // INICIALIZAÇÃO
 1 para cada vértice u de G (excluindo o s)
 2    cor[u] <- branco; d[u] <- oo; pi[u] <- NULO
 3 cor[s] <- cinza; d[s] <- 0; pi[s] <- NULO

 4 declare uma fila vazia Q
 5 insira s na fila Q
 6 enquanto Q não é vazia
 7    remova o próximo elem. da fila Q e o armazene em u
 8    para cada vértice v em Adj[u]
 9       se cor[v] = branco
10          cor[v] <- cinza; d[v] <- d[u] + 1; pi[v] <- u
11          insira v na fila Q
12    cor[u] <- preto

---------------------------

DFS-VISIT(u)
   cor[u] <- cinza
   d[u] <- tempo <- tempo + 1
   para cada v adjacente a u
      se cor[v] = branco
         pi[v] <- u
         DFS-VISIT(v)
   cor[u] <- preto
   f[u] <- tempo <- tempo + 1

DFS(Adj[], n)
   para cada vértice u
      cor[u] <- branco; pi[u] <- NULO
   tempo <- 0
   para cada vértice u
      se cor[u] = branco
         DFS-VISIT(u)

----------------------------

// Grafo não direcionado do exemplo da busca em largura:

   Adj[t].push_back(w);
   Adj[t].push_back(x);
   Adj[t].push_back(u);
   Adj[x].push_back(w);
   Adj[x].push_back(t);
   Adj[x].push_back(u);
   Adj[x].push_back(y);
   Adj[u].push_back(t);
   Adj[u].push_back(x);
   Adj[u].push_back(y);
   Adj[y].push_back(x);
   Adj[y].push_back(u);
}

-----------------------------------

// Grafo direcionado do exemplo da busca em profundidade:

#define N 8
enum Vertices {s,t,u,v,x,y,w,z};
             //0 1 2 3 4 5 6 7
list<int> Adj[N];

void inicializa_grafo()
{
   Adj[s].push_back(z);
   Adj[s].push_back(w);
   Adj[z].push_back(y);
   Adj[z].push_back(w);
   Adj[y].push_back(x);
   Adj[x].push_back(z);
   Adj[w].push_back(x);
   Adj[t].push_back(v);
   Adj[t].push_back(u);
   Adj[v].push_back(w);
   Adj[v].push_back(s);
   Adj[u].push_back(v);
   Adj[u].push_back(t);
}

   para cada vértice u
      se cor[u] = branco
         DFS-VISIT(u)

----------------------------------

// Grafo não direcionado do exemplo da busca em largura:

#define N 8
list<int> Adj[N];
enum Vertices {s,w,r,t,x,v,u,y};
             //0 1 2 3 4 5 6 7

void inicializa_grafo()
{
   Adj[s].push_back(w);
   Adj[s].push_back(r);
   Adj[r].push_back(s);
   Adj[r].push_back(v);
   Adj[v].push_back(r);
   Adj[w].push_back(s);
   Adj[w].push_back(t);
   Adj[w].push_back(x);
   Adj[t].push_back(w);
   Adj[t].push_back(x);
   Adj[t].push_back(u);
   Adj[x].push_back(w);
   Adj[x].push_back(t);
   Adj[x].push_back(u);
   Adj[x].push_back(y);
   Adj[u].push_back(t);
   Adj[u].push_back(x);
   Adj[u].push_back(y);
   Adj[y].push_back(x);
   Adj[y].push_back(u);
}

-----------------------------------

// Grafo direcionado do exemplo da busca em profundidade:

#define N 8
enum Vertices {s,t,u,v,x,y,w,z};
             //0 1 2 3 4 5 6 7
list<int> Adj[N];

void inicializa_grafo()
{
   Adj[s].push_back(z);
   Adj[s].push_back(w);
   Adj[z].push_back(y);
   Adj[z].push_back(w);
   Adj[y].push_back(x);
   Adj[x].push_back(z);
   Adj[w].push_back(x);
   Adj[t].push_back(v);
   Adj[t].push_back(u);
   Adj[v].push_back(w);
   Adj[v].push_back(s);
   Adj[u].push_back(v);
   Adj[u].push_back(t);
}
