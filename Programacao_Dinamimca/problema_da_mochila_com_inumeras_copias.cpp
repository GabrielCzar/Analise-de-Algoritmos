#include <iostream>
#define NULO -1

using namespace std;
int n = 4;
int W = 11;
int P[4] = {6, 3, 4, 2}; //{5, 3, 6, 2};
int V[4] = {30, 14, 16, 9}; //{24, 13, 30, 8};
int M[11] = {0};

int mochila(int w){
    int maior = 0;
    for (int i = 0; i < n; ++i){
        if(w >= P[i]){
            int v = V[i] + mochila(w - P[i]);
            if(v > maior) maior = v;
        }
    }
    return maior;
}

int mochila_mem(int w){
    if(M[w] != 0)
        return M[w];
    int maior = 0;
    for(int i = 0; i < n; i++){
        if(w >= P[i]){
            int v = V[i] + mochila_mem(w - P[i]);
            if(v > maior) maior = v;
        }
    }
    M[w] = maior;
    return maior;
}

void mochila_prog_dinamica() {
      M[0] = 0;
      for (int w = 0; w < W; w++) {
         int maior = 0;
         for(int i = 0; i < n; i++) {
            if (w >= P[i]) {
               int v = V[i] + M[w - P[i]];
               if (v > maior)
                   maior = v;
            }
         }
         M[w] = maior;
      }
}

int main(void){
    cout << "Sem memorizacao: " << mochila(W - 1) << endl;

    cout << "Com memorizacao: " << mochila_mem(W - 1) << endl;

    mochila_prog_dinamica();
    cout << "Programacao dinamica: " << M[W - 1] << endl;

    return 0;
}
