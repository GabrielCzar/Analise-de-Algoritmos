#include <iostream>

using namespace std;
/*
Retorna valor ótimo da mochila, e grava em pred o vetor de predecessores.
- W: tamanho inicial da mochila.
- n: número de itens.
- P: vetor de pesos dos itens, do índice 1 até n (inclusive).
- V: vetor de valores dos itens, do índice 1 até n (inclusive).
- pred: vetor de predecessores (inicializado com -1).
        Ou seja, pred[w] contém o índice do item escolhido quando mochila tem
        capacidade w, ou -1 se nenhum item cabe na mochila.


// Global: W, P, V, n e pred (inicializado com -1).
// Retorna o valor ótimo para os i primeiros itens, e mochila de tamanho w.

MOCHILA(w,i):
   se i = 0, retorne 0
   maior <- MOCHILA(w, i - 1)
   se P[i] <= w
      v <- V[i] + MOCHILA(w - P[i], i - 1)
      se v > maior
         maior <- v
         pred[w] <- i
   retorne maior

IMPRIME_SOLUCAO(w)
   se w > 0 e pred[w] > 0
      imprime pred[w]
      IMPRIME_SOLUCAO(w - P[pred[w]])
*/

double mochila_prog_din(int W, int n, int P[], double V[], int pred[]) {
    double matriz [W + 1][n + 1] = {0};
    for (int w = 1; w <= W; ++w){
        for (int i = 1; i <= n; ++i) {
            double maior = matriz[w][i - 1];
            if (P[i] <= w) {
                double v = V[i] + matriz[w - P[i]][i - 1];
                if (v > maior) {
                    maior = v;
                    pred[w] = i;
                }
            }
            matriz[w][i] = maior;
        }
    }
    return matriz[W][n];
}

int main(void) {
    cout << "Hello World!" << endl;
    return 0;
}
