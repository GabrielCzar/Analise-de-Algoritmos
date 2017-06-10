#include <stdio.h>
#include <stdlib.h>

struct arv {
   char v;
   struct arv *esq;
   struct arv *dir;
};
typedef struct arv Arv;

Arv* arv_cria(char v, Arv *sae, Arv *sad)
{
   Arv* a = (Arv*) malloc(sizeof(Arv));
   a->v = v;
   a->esq = sae;
   a->dir = sad;
   return a;
}

int arv_vazia(Arv *a) {
   return a == NULL;
}

void arv_imprime(Arv *a)
{
   printf("<");
   if (!arv_vazia(a)) {
      printf("%c ", a->v);
      arv_imprime(a->esq);
      arv_imprime(a->dir);
   }
   printf(">");
}

void arv_imprime_indent(Arv *a, int nivel)
{
   int i; for (i=0; i < nivel; i++) printf("  ");
   if (!arv_vazia(a)) {
      printf("%c\n", a->v);
      if (!arv_vazia(a->esq) || !arv_vazia(a->dir)) {
         arv_imprime_indent(a->esq, nivel+1);
         arv_imprime_indent(a->dir, nivel+1);
      }
   }
   else 
      printf("-\n");
}

Arv* arv_libera(Arv *a)
{
   if (!arv_vazia(a)) {
      arv_libera(a->esq);
      arv_libera(a->dir);
      free(a);
   }
   return NULL;
}

int arv_pertence(Arv *a, char c) 
{
   if (arv_vazia(a)) return 0;
   if (a->v == c) return 1;
   return arv_pertence(a->esq, c) || arv_pertence(a->dir, c);
}

int arv_num_vertices(Arv *a)
{
   if (arv_vazia(a)) return 0;
   return arv_num_vertices(a->esq) + arv_num_vertices(a->dir) + 1;
}

int arv_num_folhas(Arv *a)
{
   if (arv_vazia(a)) return 0;
   if ((a->esq == NULL) && (a->dir == NULL)) return 1;
   return arv_num_folha(a->esq) + arv_num_folha(a->dir);
}

int arv_altura(Arv *a);
Arv* arv_copia(Arv *a);
int arv_igual(Arv *a, Arv *b);

main()
{
   Arv *a = arv_cria('a', arv_cria('b', NULL, arv_cria('d',NULL,NULL)), arv_cria('c', arv_cria('e',NULL,NULL), arv_cria('f',NULL,NULL)));
   arv_imprime_indent(a,0);
 
   printf("arv_pertence(a,'d') = %d\n", arv_pertence(a,'d'));
   printf("arv_pertence(a,'g') = %d\n", arv_pertence(a,'g'));
   printf("num_vertices = %d\n", arv_num_vertices(a));
   printf("num_vertices = %d\n", arv_num_folhas(a));
   
   a->esq = arv_libera(a->esq);
   arv_imprime_indent(a,0);
   
   system("pause");
}
