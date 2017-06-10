#include <iostream>
#include <stdlib.h>

using namespace std;

int A[] = {0, 1, 2, 3}
,   f[] = {3, 1, 8, 5}
,   d[] = {3, 5, 6, 9}
,   n = 4;

int cmp_func(const void *a, const void *b){
    return d[*(int *)a] - d[*(int *)b];
}

void ordenar_por_deadline(int vet[], int n){
    qsort(vet, n, sizeof(int), cmp_func);
}

int min_maior_atraso (int A[], int f[], int d[], int n) {
    ordenar_por_deadline(A, n);                  // n log n
   int matraso = 0, si = 0;                      // 1
   for (int i = 0; i < n; i++) {                 // n
       if (si + f[A[i]] - d[A[i]] > matraso)     // n - 1
            matraso = si + f[A[i]] - d[A[i]];
       si = si + f[A[i]];                        // n - 1
   }
   return matraso;                               // 1
}                                                // n log n + 3n
                                                 // Θ(n log n + n)
                                                 // Θ(n log n)
int main() {

    cout << min_maior_atraso(A, f, d, n);

    return 0;
}
