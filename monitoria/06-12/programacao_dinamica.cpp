itens = [5, 11, 5, 1]

def tesouro(soma, i):
    if soma == 0 and i == 0:
        return True
    if not soma == 0 and i == 0:
        return False
    if soma == 0 and not i == 0:
		return True
    global itens
    return tesouro (soma, i - 1) or tesouro(soma - itens[i], i - 1)

def main():
    global itens
    soma = 0
    n = 3
    for item in itens:
        soma += item
    if soma % 2 == 0:
        print tesouro(int(soma / 2), n)
    else:
        print False

main()

#include <iostream>
#include <vector>

using namespace std;

int vector<int> itens = {5, 11, 5, 1}

int main() {
    int soma = 0;
    int n = 3;
    for (int i = 0; i < n; i++)  soma += itens[i];

    if (soma % 2 == 0)
      the_last_
    else cout << "False" << 0;


    return 0;
}
