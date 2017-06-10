/**
Implemente uma pilha de inteiros que tem a operação mínimo que devolve o menor elemento da pilha.
Faça a contagem de instruções e forneça a complexidade.
Envie como mensagem privada no moodle (estou no mesmo curso de paa q vcs).
*/

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class Pilha {
    list<int> conteudo;
    list<int> minimos;

    void insert_minimo (int value) {
        if (value > minimos.back()) {
            minimos.push_back(value);
            return;
        }
        for (list<int>::iterator it = minimos.begin(); it != minimos.end(); it++) {
            if (value < *it) {
                minimos.insert(it, value);
                return;
            }
        }
        minimos.push_back(value);
    }

public:

    int min () {
        return minimos.empty() ? -1 : minimos.front();
    }

    int top () {
        return is_empty() ? -1 : conteudo.front();
    }

    void push (int value) {
        if (value < minimos.front())
            minimos.push_front(value);
        else
            insert_minimo(value);
        conteudo.push_front(value);
    }

    void pop () {
        if (is_empty())
            return;
        int v;
        v = conteudo.front();
        conteudo.pop_front();
        minimos.remove(v);
    }

    bool is_empty () {
        return conteudo.empty();
    }

    int size () {
        return conteudo.size();
    }

    void print () {
        if (is_empty())
            cout << "VAZIA";
        for (list<int>::iterator it = conteudo.begin(); it != conteudo.end(); it++)
            cout << *it << " ";
        cout << endl;
    }
};

int main () {
    return 0;
}
