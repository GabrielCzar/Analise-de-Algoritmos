#include <iostream>
#include <vector>

using namespace std;

int n_moedas(vector<int> moedas, int troco){
	int qtd = 0, tam = moedas.size();
	for (int i = tam - 1; i >= 0; i--) {
		int aux = troco / moedas[i];
		troco -= aux * moedas[i];
		qtd += aux;
	}
	return qtd;
}

int main () {	
	vector<int> moedas;
	int troco;

	troco = 26;
	moedas.push_back(1);
	moedas.push_back(2);
	moedas.push_back(5);
	moedas.push_back(10);
	moedas.push_back(20);

	cout << "Numero de moedas: " << n_moedas(moedas, troco);

	return 0;
}

