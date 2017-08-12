#include <iostream>

using namespace std;
/*
AGM_PRIM( raiz):
      para u <- 1 até N faça
            vertices[u].key = oo
            vertices[u].pi = NULL
      vertices[raiz].key = 0;
      crie uma min heap Q contendo vértices priorizado pela key
      inicialize Q com os vértices setando a flag para verdadeiro
      enquanto Q != vazio faça
            u = EXTRACT_MIN( Q )
            vertices[u.id].flag = falso
            para cada aresta it em Adj[u]
                  se vertices[it.v].flag and it.peso < vertices[it.v].key então
                        vertices[it.v].pi = u.id
                        vertices[it.v].key = it.peso
                        DECREASE-KEY( Q )

*/



int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
