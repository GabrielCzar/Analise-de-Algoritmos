#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;

/*
Nas suas horas vagas, Décio gosta de descobrir o número mínimo de caracteres que precisam ser inserido em um string
para que ela torne-se palindrome. Porém, ele faltou a aula de Programação Dinâmica e agora não sabe resolver este problema
de maneira ótima. Desenvolva um algoritmo para o Décio que dada uma string qualquer, devolva o número mínimo de caracteres
 que precisam ser inseridos. Por exemplo, dada a string s = "Ab3bd", o número mínimo de caracteres que precisa ser inserido é 2
 e podemos obter "dAb3bAd"ou "Adb3bdA".

tornar_palin(A, i, j):
    se i == j:
        retorne 0
    se j == i + 1:
        se A[i] == A[j]:
            return 0
        senao:
            return 1
    se A[i] == A[j]:
        retorne tornar_palin(A, i + 1, j - 1)
    retorne 1 + min{tornar_palin(A, i + 1, j), tornar_palin(A, i, j - 1)}
*/

string A = "Ab3bd";

int tornar_palin (string A, int i, int j) {
    if (i == j)
        return 0;
    if (j == (i + 1) && A[i] == A[j])
        return 0;
    if (j == (i + 1))
        return 1;
    if (A[i] == A[j])
        return tornar_palin(A, i + 1, j - 1);
    return 1 + min(tornar_palin(A, i + 1, j), tornar_palin(A, i, j - 1));
}

int tornar_palin (string A, int tam) {
    int table[tam][tam] = {0};

    /*
    for (int k = 1; k < tam; k++) {
        for (int i = 0, j = k; h < tam; ++i, ++j) {
            if (A[i] == A[j])
                table[i][j] = table[i + 1][j - 1];
            else
                table[i][j] = 1 + min(table[i][j - 1], table[i + 1][j]);
        }
    }
    */

    for (int k = 1; k < tam; k++) {
        for (int i = 0; i < tam; ++i) {
            for (int j = k; j < tam; ++j) {
                if (i >= j)
                    table[i][j] = 0;
                if (A[i] == A[j])
                    table[i][j] = table[i + 1][j - 1];
                else
                    table[i][j] = 1 + min(table[i][j - 1], table[i + 1][j]);
            }
        }
    }

    return table[0][tam - 1];
}

int main (){
    string A = "abcde";
    int total = A.size();
    cout << "Recursivo: " << tornar_palin(A, 0, total - 1) << endl;
    cout << "Dinamica: " << tornar_palin(A, total) << endl;

    return 0;
}
