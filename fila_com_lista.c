#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

struct lista {
   //float v;
   	void *v;
   struct lista *prox; // Ponteiro para o próximo elemento na lista
};
typedef struct lista Lista;

struct fila {
   Lista *ini; // Ponteiro para o 1o elemento na fila.
   Lista *fim; // Ponteiro para o último elemento na fila.
};

Fila* fila_cria()
{
   Fila *f = (Fila*) malloc(sizeof(Fila));
   f->ini = NULL;
   f->fim = NULL;
   return f;
}

void fila_libera(Fila *f)
{
   while (!fila_vazia(f))
      fila_remove(f);
   free(f);
}

int fila_vazia(Fila *f)
{
   return f->ini == NULL;
}

void fila_insere(Fila *f, void *v)
{
   Lista *novo = (Lista*) malloc(sizeof(Lista));
   if (novo == NULL) {
      printf("Erro: estouro de fila.\n");
      exit(1);
   }
   novo->v = v;
   novo->prox = NULL;
   if (fila_vazia(f))
      f->ini = novo;
   else
      f->fim->prox = novo;
   f->fim = novo;
}

void* fila_remove(Fila *f)
{
   if (fila_vazia(f)) {
      printf("Erro: fila vazia.\n");
      exit(1);
   }
   Lista *t = f->ini;
   void *v = t->v;
   f->ini = t->prox;
   if (f->ini == NULL)
      f->fim == NULL;
   free(t);
   return v;
}

void* fila_inicio(Fila *f)
{
   if (fila_vazia(f)) {
      printf("Erro: fila vazia.\n");
      exit(1);
   }
   return f->ini->v;
}

/*
void fila_imprime(Fila *f)
{
   Lista *t = f->ini;
   printf("[ ");
   for (; t != NULL; t = t->prox)
      printf("%.1f ", t->v);
   printf("]\n");
}
*/