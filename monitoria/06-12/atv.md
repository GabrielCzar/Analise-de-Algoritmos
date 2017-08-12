Enoque e Leonardo encontraram um tesouro secreto no campus de Quixadá. O tesouro é composto por n itens de valores v1,v2,...,vn. Eles querem saber se é possível particionar os itens do tesouro em dois subconjuntos de tal maneira que ambos recebam o mesmo valor. Por exemplo, se eles encontrarem um tesouro composto por 4 itens de valores 5, 11, 5, 1. Esse tesouro pode ser particionado como {5, 5, 1} e {11}.

	Escreva o código, utilizando programação dinâmica, que resolva o problema.

Pseudo-código recursivo:
itens é um vetor global, indexado de [1,n], que guarda os valores dos itens.
```
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
```
