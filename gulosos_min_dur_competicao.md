Cada competidor nada 200m e em seguida corre 2km. Ganha quem completar as duas provas no menor tempo. Quando um competidor sai da piscina o próximo entra.

Usando uma estimativa do tempo de natação ni e de corrida ci de cada competidor i, encontre uma ordem dos competidores que minimiza o tempo total da prova.

Prove que a ordem sugerida é ótima, e forneça pseudo-código e complexidade de algoritmo para determinar a duração total da prova.

___

Para minimizar o tempo total da prova.

Antes: MAX {Si + Ni + Ci, Si + Ni + Nj + Cj}
                A                B

Depois: MAX {Si + Nj + Cj, Si + Nj + Ni + Ci}
                C                  D

Basta provar que:

(I) A >= C ou B >= C

(II) A >= D ou B >= D

Para:
(I) Ni + Ci >= Nj + Cj ou Ni + Nj + Cj >= Nj + Cj
para Ni >= 0, a expressão a direita sera verdadeira.

(II) Ni + Ci >= Nj + Ni + Ci ou Ni + Nj + Cj >= Nj + Ni + Ci
para satisfazer a expressão a direita basta Cj >= Ci.

Ou seja basta fazer o guloso escolher em ordem crescente da corrida, pois i e j estão invertidos na solução ótima inicial.


MIN_DUR_COMP (N, C, T):
   armazene em S, em ordem crescente de corrida       // n log n
   Si <- Ni + Ci                                      // C
   para i de 2 ate n:                                 // n - C
      Si <- Si + Ni + Ci                              // n - C
   retorne Si                                         // C

T(n) = Θ(n . log n + 2n + 4C) = Θ(n log n)
