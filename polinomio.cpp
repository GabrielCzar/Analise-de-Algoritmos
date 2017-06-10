#include <iostream>

using namespace std;

float calcular_polinomio (float A[], int n, int i, float x) {
    if (i == n)
        return A[i];
    float aux = calcular_polinomio(A, n, i + 1, x);
    aux = (aux * x) + A[i];
    return aux;
}

int main () {
    int n;
    float A[10000], x;
    cout << "N: " << endl;
    cin >> n;
    cout << "X: " << endl;
    cin >> x;
    for (int i = 0; i <= n; ++i)
        cin >> A[i];

    cout << calcular_polinomio(A, n, 0, x) << endl;
    return 0;
}
