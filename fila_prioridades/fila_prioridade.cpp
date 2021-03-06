// No pseudocódigo o vetor A vai de 1 até n, e em C vai de 0 até n-1.
// Dica de implementação: ao traduzir de pseudocódigo para C, adapte apenas os
// indices do vetor A, subtraindo cada índice de 1.
// Por exemplo, se A[x] aparece no pseudocódigo, implemente como A[x-1].
#include <iostream>

using namespace std;

void max_heapify(int A[], int n, int i)
{
    int esq = 2 * i, dir = 2 * i + 1, maior = i;              // O(1)
    if (esq <= n && A[esq - 1] > A[maior - 1])
        maior = esq;                                          // O(1)
    if (dir <= n && A[dir - 1] > A[maior - 1])
        maior = dir;                                          // O(1)
    if (maior != i)
    {                                                         // O(1)
        swap(A[i - 1], A[maior - 1]);                          // O(1)
        max_heapify(A, n, maior);                             // T(n - 1)
    }
}

void make_max_heap(int A[], int n)
{
    for (int i = n / 2; i >= 1; i--)
        max_heapify(A, n, i);
}

int maximum(int A[], int n) // O(1)
{
    return A[1 - 1];
}

int extract_max(int A[], int n) // O(lg n)
{
    int max = A[1 - 1];
    swap(A[1 - 1], A[n - 1]);
    max_heapify(A, n - 1, 1);
    return max;
}

void increase_key(int A[], int i, int p) //
{
    A[i - 1] = p;
    while (i > 1 && A[i - 1] > A[(i / 2) - 1])
    {
          swap(A[i - 1], A[(i / 2) - 1]);
          i = i / 2;
    }
}

void decrease_key(int A[], int n, int i, int p)
{
    A[i - 1] = p;
    max_heapify(A, n, i);
}

void heap_insert(int A[], int n, int p)
{
    increase_key(A, n + 1, p);
}
