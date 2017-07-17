# Distância de Edição

Dadas duas strings A[1..m] e B[1..n], determine o número mínimo de edições de caracteres (inclusão, remoção ou troca) p/ igualá-las.

```
S - N O W Y         - S N O W - Y
S U N N - Y         S U N - - N Y
= i = t r =         i t = r r i =
custo = 3           custo = 5
```

O número de subproblemas é o produto dos tamanhos das duas strings. Gastamos tempo constante para calcular cada elemento da matriz. Portanto, a complexidade da programação dinâmica será O(mn), onde m é o tamanho da 1a string e n é o tamanho da 2a string.

Utilizando strings aleatórias com 17 caracteres cada, o algoritmo recursivo executou em 739.476 segundos, e a programação dinâmica em 0.002 segundos. Ou seja, a programação dinâmica foi 370 mil vezes mais rápido para uma instância com apenas 17 caracteres!

```c++
#include <algorithm>

using namespace std;

int dist_edicao(char A[], char B[], int m, int n)
{
   int distancias[m+1][n+1];
   for (int i = 0; i <= n; i++) distancias[0][i] = i;
   for (int i = 0; i <= m; i++) distancias[i][0] = i;

   for (int i = 0; i <= m; i++) {
       for (int j = 0; j <= n; j++) {
           if (A[i] == B[j]) {
               distancias[i][j] = distancias[i - 1][j - 1];
           } else {
               int troca = 1 + distancias[i - 1][j - 1];
               int ins = 1 + distancias[i][j - 1];
               int rem = 1 + distancias[i - 1][j];
               distancias[i][j] = min(troca, min(ins, rem));
          }
       }
   }
   return distancias[m][n];
}

```
