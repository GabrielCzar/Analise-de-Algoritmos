#include <iostream>
#include <algorithm>

using namespace std;

int majoritario_forca_bruta(int A[], int total) {
    for (int i = 0; i < total / 2 + 1; ++i) {
        int cont = 0;
        for (int j = i; j < total; ++j) {
            if (A[i] == A[j])
                cont++;
            if (cont > total / 2)
                return A[i];
        }
    }
    return -1;
}

int majoritario_ordenando(int A[], int n) {
    sort(A, A+n);
    for (int i = 0; i < (n - 1) / 2 + 1; ++i)
        if (A[i] == A[i + n / 2])
            return A[i];
    return -1;
}

struct STRUCT {
    int qtd;
    int valor;

    STRUCT(int qtd, int valor){
        this->qtd = qtd;
        this->valor = valor;
    }
};

// Após cancelar pares de elementos distintos, resta apenas 'qte' elementos com o mesmo valor ('valor').
STRUCT majoritario_rec(int A[], int ini, int fim){
   if (ini == fim)
       return STRUCT(1, A[ini]);
   int meio = (ini + fim) / 2;
   STRUCT one = majoritario_rec(A, ini, meio);
   STRUCT two = majoritario_rec(A, meio + 1, fim);
   if (one.valor == two.valor)
      return STRUCT(one.qtd + two.qtd, one.valor);
   else if (one.qtd > two.qtd)
      return STRUCT(one.qtd - two.qtd, one.valor);
   else
      return STRUCT(two.qtd - one.qtd, two.valor);
}

int majoritario_divisao_conquista(int A[], int n) {
    STRUCT maj = majoritario_rec(A, 0, n - 1);
    int cont = 0;
    for (int i = 0; i < n; ++i)
        if (maj.valor == A[i])
            cont++;
    if (maj.qtd > 0 && cont > n / 2)
        return maj.valor;
    return -1;
}

int majoritario_iterativo(int A[], int n) {
    int qte = 0, valor = 0;
    for (int i = 0; i < n; ++i) {
        if (qte == 0) {
            qte ++;
            valor = A[i];
        } else {
            if (A[i] == valor) {
                qte ++;
            } else {
                qte --;
            }
        }
    }
    if (qte == 0)
        return -1;
    int cont = 0;
    for (int i = 0; i < n; ++i)
        if (valor == A[i])
            cont ++;
    if (cont > n / 2)
        return valor;
    return -1;
}

