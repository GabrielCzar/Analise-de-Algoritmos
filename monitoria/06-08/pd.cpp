#include<iostream>
#include<vector>

using namespace std;

//Guloso
int num_moedas(vector<int> moedas, int troco) {
    int qte_moedas = 0;
    int tam_moedas = moedas.size();

    for (int i = tam_moedas - 1; i >= 0; i--) {
        int aux = troco / moedas[i];
        troco -= (aux * moedas[i]);
        qte_moedas += aux;
    }

    return qte_moedas;
}

// Programacao dinamica
int qtd_moedas(vector<int> moedas, int troco) {
    int S[troco + 1] = {0};
    for (int i = 1; i <= troco; ++i) {
        S[i] = 999999999;
        for (int j = 0; j < (int) moedas.size(); ++j)
            if (i - moedas[j] >= 0)
                S[i] = min (S[i], S[i - moedas[j]] + 1);
    }

    return S[troco];
}

int main() {
    vector<int> moedas = {1, 5, 6, 13, 27};
    int p = 49;
    cout << "Guloso: " << num_moedas(moedas, p) << endl;
    cout << "Programacao Dinamica: " << qtd_moedas(moedas, p) << endl;
    return 0;
}
