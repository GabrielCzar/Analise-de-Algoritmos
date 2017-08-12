#include <iostream>

using namespace std;

int W = 11;
int TAM = 4;
int P[4] = {6, 3, 4, 2};
int V[4] = {30, 14, 16, 9};

int MOCHILA(int W){
    int M[W] = {0};
    for (int i = 1; i < W; i++) {
        int maior = 0;
        for (int j = 0; j < TAM; j++){
            if (i >= P[j]){
                int v = V[j] + M[i - P[j]];
                if (v > maior)
                    maior = v;
            }
        }
        M[i] = maior;
    }
    return M[W-1];
}
int main(){
    cout << "Dinamica "<< MOCHILA(W) << endl;

    return 0;
}
