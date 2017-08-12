# 1 - Usando a definicao formal de θ, prove que (6n^3) ∉ θ(n^2)
Pela definição: 
	Co, C1, No tal que
	Co * n^2 <= 6n^3 <= C1 * n^2    All *  1/n^2
	Co * 1 <= 6n <= C1 * 1
	Logo, não é possivel encontrar C1, de modo que C1 >= 6n, para N > No,
	pois C1 é constante e N pode crescer infinitamente.


# 2 - Usando a definição formal de θ, prove que (6n³) ∈ θ(n³)
Pela definição:
	Co, C1, No tal que
	Co * n³ <= 6n³ <= C1 * n³  All * 1/n³
	Co <= 6 <= C1
	Logo, é possivel encontrar um valor C1 onde C1 > 6 pois todos os valos 
	são constantes, para N > No. Ex.: Co = 1, C1 = 7 e No = 6
	

# 3 - Complete com θ, O ou Ω:
	n^100 _ 2^n                0 
	2^n _ 2^(n/2)              Ω 
	n^(log m) _ m^(log n)	   θ
