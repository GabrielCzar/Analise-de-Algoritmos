typedef struct lista Lista;

// Cria nova lista vazia (igual a NULL).
Lista* lcd_cria();

// Insere novo nó antes do nó p.
void lcd_insere_antes(Lista *p, Lista *novo);

// Insere novo nó depois do nó p.
void lcd_insere_depois(Lista *p, Lista *novo);

// Insere novo nó no início da lista l com valor v.
Lista* lcd_insere_ini(Lista *l, int v);

// Insere novo nó no final da lista l com valor v.
Lista* lcd_insere_fim(Lista *l, int v);

// Libera a memória alocada para os nós da lista l.
void lcd_libera(Lista *l);

// Imprime valores (info) armazenados na lista l.
void lcd_imprime(Lista *l);

// Retorna 1 se a lista l está vazia, e 0 caso contrário.
int lcd_vazia(Lista *l);

// Retorna endereço do 1o nó na lista l que contém o valor v.
Lista* lcd_busca(Lista *l, int v);

// Retira da lista l o 1o nó com valor v. Retorna lista modificada.
Lista* lcd_retira(Lista *l, Lista *no);

// Retorna 1 se l1 e l2 possuem os mesmos valores armazenados (na mesma ordem), 0 caso contrário.
int lcd_igual(Lista *l1, Lista *l2);
