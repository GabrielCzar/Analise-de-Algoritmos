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
