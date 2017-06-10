
struct Node {
   struct Node *pai;
   int rank;
   char id; // identificador
};

Node* make_set(char id); // Aloca memória, inicializa e retorna o nó.
Node* find_set(Node *x);
void uf_union(Node *x, Node *y);
