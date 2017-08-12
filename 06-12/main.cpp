#include <iostream>
#include <vector>

using namespace std;

/*
Enoque e Leonardo encontraram um tesouro secreto no campus de Quixadá.
O tesouro é composto por n itens de valores v1,v2,...,vn.
Eles querem saber se é possível particionar os itens do tesouro em dois subconjuntos de tal maneira que ambos recebam o mesmo valor.
Por exemplo, se eles encontrarem um tesouro composto por 4 itens de valores 5, 11, 5, 1.
Esse tesouro pode ser particionado como {5, 5, 1} e {11}.

    Escreva o código, utilizando programação dinâmica, que resolva o problema.

Pseudo-código recursivo:
itens é um vetor global, indexado de [1,n], que guarda os valores dos itens.

tesouro(soma, i):
    se soma == 0 e i == 0:
        retorne Verdade
    se soma != 0 e i == 0:
        retorne Falso
    se soma == 0 e i != 0:
        retorne Verdade
    retorne tesouro(soma, i - 1) ou tesouro(soma - itens[i], i - 1)

principal:
    soma = 0
    para cada item em itens:w
        soma += item
    se soma % 2 == 0:
        print tesouro(soma / 2, n)
    senao
        print Falso
*/
int N = 4;
vector<int> W = {5, 11, 5, 1};

bool tesouro_dinamico (int soma, int i) {
    int T[soma + 1][i + 1] = {true};

    for (int j = 1; j <= i; ++j) {
        for (int k = 1; k <= i; ++k) {
            if (soma == 0) {
                T[j][k] = true;
            } else {
                T[j][k] = (T[soma][k - 1] || T[soma - W[j]][k - 1]);
            }
        }
    }
    return T[soma][i];
}

bool tesouro (int soma, int i) {
    if (soma == 0 && i == 0)
        return true;
    if (soma == 0 && i != 0)
        return true;
    if (soma != 0 && i == 0)
        return false;
    return tesouro(soma, i - 1) || tesouro(soma - W[i], i - 1);
}

int main() {
    int soma = 0;
    for (int item = 0; item < N; item++)
        soma += W[item];
    if (soma % 2 == 0) {
        cout << "Recursivo: " << tesouro(soma / 2, N) << endl;
        cout << "Dinamica: " << tesouro_dinamico(soma / 2, N) << endl;
    } else
        cout << false;

    return 0;
}
