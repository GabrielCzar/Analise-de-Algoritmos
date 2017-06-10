# Arvore de Recorrencias

T(n) = T(n / 3) + T(2n / 3) + n
|
|	               n                    n
H                   /     \                
|	         n/3        2n/3            n
|	       /   \      /    \
log n 3/2      n/9    2n/9  2n/9  4n/9      n
                                  Total = O(n * log n)

