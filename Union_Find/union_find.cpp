#include "union_find.hpp"

// Aloca memória, inicializa e retorna o nó.
Node * make_set(char id) {
    Node * no = new Node();
    no->id = id;
    no->rank = 0;
    no->pai = no;
    return no;
}

Node * find_set(Node * x) {
    if (x->pai != x)
        x->pai = find_set(x->pai);
    return x->pai;
}

Node * find_set2(Node * x) {
    if (x->pai == x)
        return x->pai;
    x->pai = find_set2(x->pai);
}

void uf_union(Node * x, Node * y) {
    Node * nox = find_set(x);
    Node * noy = find_set(y);
    if (nox->rank > noy->rank)
         noy->pai = nox;
    else {
        nox->pai = noy;
        if (nox->rank == noy->rank)
            noy->rank++;
    }
}
