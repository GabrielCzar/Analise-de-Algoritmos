Pedro Henrique trabalha no caixa de um supermercado. Ele precisa passar o troco milhares de vezes durante o dia. Só que ele é apaixonado por moedas e quer entregar o menor números de moedas possível a cada cliente. Dado um valor N e um estoque infinito de cada uma das M moedas de diferentes valores m1, m2, . . . , mM , desenvolva um algoritmo que encontra quantas moedas você deve entregar ao cliente de modo que o total de moedas seja o mínimo possível. Por exemplo, dado N=49 e 5 moedas de valores 1,5,6,13,27 o menor número de moedas para N=49 são duas moedas de valor 5, duas moedas de 6 e um moeda de 27.


### algoritmo guloso

```c++
int num_moedas (std::vector<int> & moedas, int troco) {
    int qte_moedas = 0;
    int tam_moedas = moedas.size();

    for (int i = tam_moedas - 1; i >= 0; i++) {
        int aux = troco / moedas[i];
        troco -= aux * moedas[i];
        qte_moedas += aux_moedas;
    }

    return qte_moedas;
}
```

### programacao dinamica

```c++
int qtd_moedas(vector<int> moedas, int troco) {
    int S[troco + 1] = {0};
    for (int i = 1; i <= troco; ++i) {
        S[i] = 999999999;
        for (int j = 0; j < (int) moedas.size(); ++j)
            if (i - moedas[j] >= 0)
                S[i] = min(S[i], S[i - moedas[j]] + 1);
    }

    return S[troco];
}
```
