typedef struct lista Lista;

// Cria nova lista vazia (igual a NULL).
Lista* les_cria();

// Insere novo nó no início da lista l.
Lista* les_insere(Lista *l, int chave, void *info);

// Libera a memória alocada para os nós da lista l.
void les_libera(Lista *l, void (*libera_info)(void*));

// Imprime valores (info) armazenados na lista l.
	void les_imprime(Lista *l, void (*imprime_info)(void*));

// Retorna 1 se a lista l está vazia, e 0 caso contrário.
int les_vazia(Lista *l);

// Retorna endereço da estrutura info no 1o nó na lista l que contém a chave.
void* les_busca(Lista *l, int chave);		

// Retira da lista l o 1o nó com valor v. Retorna lista modificada.
Lista* les_retira(Lista *l, int chave, void (*libera_info)(void*));

// Retorna 1 se l1 e l2 possuem as mesmas chaves armazenadas (na mesma ordem), 0 caso contrário.
//int les_igual(Lista *l1, Lista *l2);
