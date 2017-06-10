# Algoritmos Gulosos

_Você fará uma viagem de L km, e deseja fazer o menor número de paradas em hotéis.
As posições dos possíveis hotéis são fornecidas no vetor x[1..n] (em ordem crescente).
Não é permitido viajar mais de D km sem fazer uma parada.
A viagem começa na posição 0. Assuma que a distância entre hotéis consecutivos é no máximo D, que x[1]≤D, e que x[n]=L (ou seja, a chegada é no último hotel)._

- Forneça algoritmo guloso: prove que a solução gulosa é ótima, apresente pseudocódigo e sua complexidade de tempo.

Escolha gulosa ótima seria a distância máxima menor ou igual a D até um hotel u.
Onde Su = min(x[u], D) km do hotel u que possa minimizar a quantidade total de hotéis visitados.

Considere uma solução ótima O qualquer que não contém a primeira escolha gulosa u.
Como o u tem a maior distancia permitida, trocando Su de outros hotéis por Su do hotel u não piora a soluçao.

Desta forma, seja u a primeira escolha gulosa, S o subproblema que resulta da escolha u, e O' uma solução ótima qualquer para o subproblema S. Pela propriedade de escolha gulosa ótima, u está contida em alguma solução ótima O.

(i) O' U {u} não será viável no problema original se O' tem uma quantidade não nula do item u, ou se O' ocupar mais de L − Su km do percurso. Da forma como definimos o subproblema S, estas situações não podem ocorrer.

(ii) O − {u} é viável para S, pois utiliza no máximo L − Su km, e toda a quantidade disponível de u já foi retirada de O.

O valor de O − {u} não pode ser maior que o valor de O', pois O' é ótima para S.
Incluindo u em O − {u} e em O', temos que o valor de cada solução aumenta da mesma proporção. Portanto, o valor de O não é maior que o valor de O' U {u}.

Algoritmo guloso:
```
hoteis_consecutivos (x[], n, D, L):
  O <- {}                             1
  para u de n - 1 ate 0               n + 1
    su <- min((L - X[u]), D)          n
    O  <- O U {u}                     n
    L  <- L - su                      n
    se L <= 0, retorne O              n
  retorne O                           1
```
T(n) = 5n + 3 E O(n)
