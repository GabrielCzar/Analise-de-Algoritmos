#include <iostream>
#include <cmath>

using namespace std;

/*
Pedro Olímpio tem uma capacidade impressionante, dada uma sequência qualquer,
ele consegue dizer o tamanho da maior subsequência palindrome contida na sequência dada.
Desenvolva um algoritmo com a mesma capacidade do Pedro Olímpio.
Por exemplo, se a sequência é "BBABCBCAB", então o tamanho da maior subsequência palindrome é 7
e "BABCBAB"é um subsequência palindrome com esse tamanho.

msp(A, i, j):
 se i == j: retorne 1
 senão
  se i + 1 == j e A[i]==A[j]:
   retorne 2
 senão:
  se A[i]==A[j]:
   retorne msp(A, i+1, j-1)+2
  senão:
   retorne max(msp(A, i+1, j), msp(A, i, j-1))
*/

int msp(char A[], int i, int j) {
    if(i == j)
        return 1;
    else if(i + 1 == j && A[i] == A[j])
        return 2;
    else if(A[i] == A[j])
        return msp(A, i + 1, j - 1) + 2;
    return max(msp(A, i + 1, j), msp(A, i, j - 1));
}

int msp(string A, int tam) {
    int B[tam + 1][tam + 1] = {0};

    for (int i = 1; i <= tam; ++i) {
        for (int j = 1; j <= tam; ++j) {
            if (i >= j)
                B[i][j] = 1;
            else if (A[i] == A[j])
                B[i][j] = B[i + 1][j - 1] + 2;
            else
                B[i][j] = max(B[i + 1][j], B[i][j - 1]);
        }
    }

    for (int i = 1; i <= tam; ++i) {
        for (int j = 1; j <= tam; ++j)
            cout << B[i][j] << " ";
        cout << endl;
    }

    return B[tam][tam];
}

int main() {
    char pali[10] = "BBABCBCAB";

    cout << msp(pali, 0, 8) << endl;
    cout << msp(pali, 8) << endl;
    return 0;
}
