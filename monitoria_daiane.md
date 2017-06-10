EXERCÍCIO EM MONITORIA - 01/11/2016


ORDENAÇÃO TOPOLÓGICA: Uma outra forma de obter uma ordenação topológica em um grafo orientado acíclico é repetidamente encontrar um vértice com grau de entrada 0, imprimi-lo e removê-lo juntamente com todas as arestas que saem desse vértice.
PSEUDOCÓDIGO:


	GRAUS_ENTRADA():
      inicialize o vetor d[1..n] com zeros
      para u <- 1 até n
            para cada v em Adj[u]
                  d[v] <- d[v]+1


ORDENACAO_TOPOLÓGICA( ):
      Calcule o grau de entrada d[v] de cada vértice v.
      Armazene em S cada vértice v com d[v]=0.
      Enquanto S != vazio
            u <-  um elemento qualquer de  S
            Imprima u
            Para cada v em Adj[u]	
                  d[v] <- d[v] - 1
                  Se d[v] = 0 então
                        insira v em S.


GRAFO PARA TESTE:
void inicializa_grafo(){
    enum Vertices {cueca,calca,cinto,camisa,gravata,paleto,meia,sapato,relogio};
                  //  0     1     2      3      4      5      6     7      8
   Adj[cueca].push_back(calca);
   Adj[cueca].push_back(sapato);
   Adj[calca].push_back(cinto);
   Adj[calca].push_back(sapato);
   Adj[meia].push_back(sapato);
   Adj[cinto].push_back(paleto);
   Adj[camisa].push_back(cinto);
   Adj[camisa].push_back(gravata);
   Adj[gravata].push_back(paleto);
}


EXERCÍCIO:
Assuma que o grafo está representado por lista de adjacências e implemente o algoritmo que dado o grafo orientado acíclico imprime uma ordenação topológica e forneça a análise de complexidade.

--------------

 EXERCÍCIO EM MONITORIA - 04/10/2016

Problema dos Hotéis:
Você fará uma viagem de L km, e deseja fazer o menor número de paradas possíveis em hotéis. As posições dos possíveis hotéis são fornecidas no vetor  x[1..n] (em ordem crescente). Não é permitido viajar mais de D km sem fazer uma parada. A viagem começa na posição 0. Assuma que a distância entre hotéis consecutivos é no máximo D, tal que x[1] <= D e x[n] = L.

EXERCÍCIO:
Apresente pseudocódigo para o problema dos hotéis, implemente o algoritmo guloso e mostre a complexidade de tempo.


-----------

EXERCÍCIO EM MONITORIA - 05/09/2016

DFS - Busca em Profundidade

PSEUDOCÓDIGO:
DFS-VISIT(u)
   cor[u] <- cinza
   d[u] <- tempo <- tempo + 1
   para cada v adjacente a u
      se cor[v] = branco
         pi[v] <- u
         DFS-VISIT(v)
   cor[u] <- preto
   f[u] <- tempo <- tempo + 1

DFS(Adj[], n)
   para cada vértice u
      cor[u] <- branco; pi[u] <- NULO
   tempo <- 0
   para cada vértice u
      se cor[u] = branco
         DFS-VISIT(u)

Exercício : Implementar o algoritmo de Busca em Profundidade com lista de adjacência e analisar o tempo pra grafo denso e espaço

---------

EXERCÍCIO EM MONITORIA - 05/10/2016

Problema da Mochila Fracionária
Imagine que tenho n objetos que eu gostaria de colocar em uma mochila de capacidade W.  Cada objeto i tem peso pi e valor vi. Posso escolher uma fração (entre 0% e 100%) de cada objeto para colocar na mochila. Quero fazer isso de modo a respeitar a capacidade da mochila W e maximizar o seu valor. 

Exemplo para W = 10
i         1        2        3       4
p        6        3        4       2
v       30      14       16      9
v/p      5     4.7       4       4.5

Solução Gulosa: 6 do 1, 3 do 2, e 1 do 4 = 30+14+9/2 = 48.5

Assuma que a propriedade de Escolha gulosa ótima já foi provada.

EXERCÍCIO:

Prove que o problema tem subestrutura ótima.

PARA PRATICAR:
Implementar o algoritmo da solução gulosa.

PSEUDOCÓDIGO:

MOCHILA_FRACIONARIO(V[],P[],n,W):
    ordene os itens em ordem decrescente V[i]/P[i].
    v <- 0
    S <- {}
    para i <- 1 até n faça
        d <- min{W, P[i]}
        v <- v + d*V[i]/P[i]
        S <- S U {(i,d)}
        W <- W - d
        se W = 0, retorne (v,S)
    retorne (v,S)

Complexidade : T (n) = Θ(n.lg n + n) = Θ(n.lg n). 


--------


      EXERCÍCIO EM MONITORIA - 05/12/2016


Classe de Problemas
Quase todos os algoritmos que estudamos até agora foram algoritmos de tempo polinomial: dada uma entrada de tamanho n, seu tempo de execução do pior caso é O(n^k) para alguma constante k. É natural imaginar se todos os problemas podem ser resolvidos em tempo polinomial. A resposta é não. Por exemplo, existem problemas, como o famoso “Problema da parada (halting)” de Turing, que não pode ser resolvido por qualquer computador que conhecemos, não importa quanto tempo seja fornecido. Também existem problemas que podem ser resolvidos, mas não em tempo polinomial e sim em tempo exponencial. Em geral, imaginamos problemas que podem ser resolvidos por algoritmos em tempo polinomial como sendo tratáveis, e os outros problemas  como intratáveis ou difíceis.


EXERCÍCIO:

1 - Explique informalmente o que significa um problema ser da classe P e da classe NP-Completo e dê exemplos de problemas para cada uma das classes. Do ponto de vista prático, qual é a relevância de se determinar que um certo problema é NP-Completo?


2 - Para cada item abaixo, diga se é verdadeiro ou falsa. Dê uma justificativa curta para cada resposta.
a - Não há problemas em P que são NP-Completos.
b - Existem problemas em P que estão em NP.
c - Existem problemas em P que estão em NP-Completo.
d -  Se A pode ser polinomialmente reduzido a B, e B é NP-Completo, então A está em P.
e - O problema do Caixeiro Viajante (TSP) é NP-Completo
f - A classe NP-completo é o conjunto de todos os problemas que podem ser resolvidos por uma algoritmo em tempo não polinomial.

--------

EXERCÍCIO EM MONITORIA - 06/09/2016

Caminho em Grafo (Print-Path)

PSEUDOCÓDIGO:
Print-Path(G, s, v )
   se v = s então
      imprime s
   senão
      se pi[v ] = NULO então
         imprime não existe caminho de s a v .
      senão
         Print-Path(G, s, pi[v ])
         imprime v 
 
Complexidade: O(comprimento do caminho) = O(V ).
Exercício: Imprima o caminho mais curto, em número de aresta, de s a v .

------

EXERCÍCIO EM MONITORIA - 06/12/2016

Redução polinomial e NP-completude
Se A pode ser polinomialmente reduzido a B, e B é NP-Completo, então A é NP-Completo.

O problema de cobertura de vértices
Uma cobertura de vértices de um grafo não orientado G = (V,E) é um subconjunto V* está em V tal que (u,v) pertence a E, então u pertence a V* ou v  pertence a V* (ou ambos). Isto é, cada vértice “cobre” suas arestas incidentes, e uma cobertura de vértices para G é um conjunto de vértices que cobre todas as arestas em E. O tamanho de uma cobertura de vértices é o número de vértices que ela contém.

O problema de cobertura de vértices é encontrar uma cobertura de vértices de tamanho mínimo em um dado grafo. Enunciando novamente esse problema de otimização como um problema de decisão, desejamos determinar se um grafo tem uma cobertura de vértices de um dado tamanho k. Como uma linguagem, definimos:
VERTEX-COVER = { <G,k> : grafo G tem uma cobertura de vértices de tamanho k}.

Teorema 34.12: O problema de cobertura de vértices é NP-Completo. (CLRS)  (cap. 34 pág 812)

EXERCÍCIO:
Prove o teorema 34.12. Dica:  O problema de cobertura de vértices pode ser reduzido para o problema de CLIQUE.

ATENÇÃO: 

Segue o link para o livro do cormen: http://www.inf.ufrgs.br/~tsrodrigues/utilidades/cormem.pdf

Vejam o 34 sobre  problemas NP-Completos a partir da pág 781. 


-------

      EXERCÍCIO EM MONITORIA - 07/11/2016

Problema Árvore Geradora Mínima - Como encontrar arestas seguras.
Teorema 23.1: (CLRS)
Seja G um grafo com pesos nas arestas dado por w. Seja A um subconjunto de arestas contido em uma AGM. Seja δ(S) um  corte que respeita A e (u,v) uma aresta leve desse corte. Então (u,v) é uma aresta segura. 

EXERCÍCIO:
Mostre que a volta do Teorema 23.1 não necessariamente ocorre, ou seja, se A é um subconjunto de arestas contido em alguma AGM, δ(S) é um corte que respeita A e (u,v) é uma aresta segura, então não necessariamente (u,v) é uma aresta leve.

----


EXERCÍCIO EM MONITORIA - 07/12/2016

Conteúdo AP2:
Algoritmos gulosos em Grafo:
     Árvore geradora mínima, Algoritmo Prim e Algoritmo Kruskal. 

Programação Dinâmica. 

Algoritmos com programação dinâmica em Grafo:
      Problema Caminho Mínimo, algoritmo usando ordenação topológica, algoritmo Dijkstra, algoritmo Bellman-Ford e algoritmo Floyd-Warshall.

NP-Completude.


EXERCÍCIO:
Dado os conteúdos estudados durante a segunda parte da disciplina, escolha um conteúdo e deste resolva um exercício. 


Link para corte de hastes: http://danieleoliveira.com.br/data/_uploaded/file/Ensino/ED2/Corte%20de%20Hastes.pdf


-----


EXERCÍCIO EM MONITORIA - 08/11/2016

Problema Troco em Moedas.
Suponha o conjunto de moedas com os seguintes valores { 1, 5, 10, 25 e 100 } centavos. Dado um valor V, pague este valor utilizando o menor número de moedas.

Exemplo: V = 24
Solução Ótima: 24 = 4x1 + 2x10 (total de 6 moedas)

Abordagem Recursiva: Considere que um subproblema S[v] consiste no menor número de moedas que podemos utilizar para pagar o valor v. Para cada moeda i com valor  moedas[i] <= v, considere incluir a moeda i na solução.

PSEUDOCÓDIGO:
TROCO_MOEDAS ( v ):
      se v = 0 então, retorne 0
      menor = oo
      para i <- 1 até n
            se moedas[i] <= v
                  s = 1 + TROCO_MOEDAS ( v - moedas[i] )
                  se s < menor então, menor <- s
      retorne menor

EXERCÍCIO:
Implemente o algoritmo recursivo que forneça a solução ótima, logo após para acelerar o algoritmo recursivo implemente utilizando a técnica de memorização e teste com diferentes valores as duas abordagens, comparando o tempos.

-----

EXERCÍCIO EM MONITORIA - 09/11/2016

Problema Troco em Moedas.
Suponha o conjunto de moedas com os seguintes valores { 1, 5, 10, 25 e 100 } centavos. Dado um valor V, pague este valor utilizando o menor número de moedas.

Exemplo: V = 24
Solução Ótima: 24 = 4x1 + 2x10 (total de 6 moedas)

Abordagem Recursiva: Considere que um subproblema S[v] consiste no menor número de moedas que podemos utilizar para pagar o valor v. Para cada moeda i com valor moedas[i] <= V, considere incluir a moeda i na solução.

PSEUDOCÓDIGO:
TROCO_MOEDAS ( v ):
      se v = 0 então, retorne 0
      menor = oo
      para i <- 1 até n
            se moedas[i] <= v
                  s = 1 + TROCO_MOEDAS ( v - moedas[i] )
                  se v < menor então, menor <- v
      retorne menor

EXERCÍCIO:
Dado o algoritmo recursivo que fornece a solução ótima, analise e entenda como funciona o preenchimento da tabela, implemente o algoritmo de programação dinâmica e diga qual a sua complexidade.w

------

EXERCÍCIO EM MONITORIA - 10/10/2016

Algoritmos Gulosos: Argumento de Troca
Quando a solução é uma sequência dos elementos de entradas (ao invés de um subconjunto), normalmente é mais simples provar que a solução gulosa é ótima usando argumento de troca.
Argumento de Troca: dada uma solução ótima qualquer, e dois elementos consecutivos a e b desta solução que não estão na mesma ordem da solução gulosa, mostramos que a inversão de a com b é viável, ou seja não piora a solução.

Problema Escalonamento para minimizar maior atraso:
Cada intervalo i tem duração t[i] e deadline d[i]. Se o intervalo i é alocado para iniciar no instante si, então termina no instante fi = si + t[i]. O atraso do intervalo i vale ci = max {fi - d[i], 0}. Desejamos minimizar o custo C = maxi ci.

Exemplo:
i    1   2   3   4
t    3   1   8   5
d   3   5   6   9

Solução: 1,2,3,4 com valor de custo = 8.

EXERCÍCIO:
Dado o problema, usando Argumento de Troca, prove que a solução gulosa é ótima.

-----


EXERCÍCIO EM MONITORIA - 11/10/2016

Problema Escalonamento para minimizar maior atraso:
Cada intervalo i tem duração t[i] e deadline d[i]. Se o intervalo i é alocado para iniciar no instante si, então termina no instante fi = si + t[i]. O atraso do intervalo i vale ci = max {fi - d[i], 0}. Desejamos minimizar o custo C = maxi ci.

Exempo:
i    1   2   3   4
t    3   1   8   5
d   3   5   6   9
Solução: 1,2,3,4 com valor de custo = 8.

EXERCÍCIO:
Dado o problema,  pense no pseudocódigo, implemente-o e forneça a complexidade.     

-----

EXERCÍCIO EM MONITORIA - 12/09/2016

O GRAFO É BIPARTIDO?

PSEUDOCÓDIGO (usando DFS):

DFS-VISIT-BIPARTIDO(u)                        // Mesma complexidade da DFS.
   cor[u] <- cinza
   para cada v adjacente a u
         se DFS-VISIT-BIPARTIDO(v) = falso
             retorne falso
      senão se conj[v] = conj[u]              (*)
      se cor[v] = branco
         pi[v] <- u
         conj[v] <- (conj[u] = A) ? B : A     (*)
         retorne falso (contém ciclo ímpar)   (*)
   retorne verdadeiro                         (*)
    
DFS-BIPARTIDO(Adj[], n)
   para cada vértice u
      cor[u] <- branco; pi[u] <- NULO
  
   para u <- 1 até n
      se cor[u] = branco
    conj[u] <- A // primeiro vértice da componente em A      (*)
         se DFS-VISIT-BIPARTIDO(u) = falso    (*)
            retorne falso                     (*)
   retorne verdadeiro                         (*)

IMPRIME-CICLO-IMPAR(u, v)
    se u=v então
        imprime u
    w <- v
    enquanto w != u faça
        imprime w 
        w <- pi[w]
    imprime w


enum Vertices {cueca,calca,cinto,camisa,gravata,paleto,meia,sapato,relogio};
             //  0     1     2      3      4      5      6     7      8
void inicializa_grafo(){
   Adj[cueca].push_back(calca);
   Adj[cueca].push_back(sapato);
   Adj[calca].push_back(cinto);
   Adj[calca].push_back(sapato);
   Adj[meia].push_back(sapato);
   Adj[cinto].push_back(paleto);
   Adj[camisa].push_back(cinto);
   Adj[camisa].push_back(gravata);
   Adj[gravata].push_back(paleto);  

}



EXERCÍCIO:
Finalizar a atividade da aula do dia 09/09 (da última aula), ou seja implementar um algoritmo para checar se um grafo é bipartido, testar em um grafo com ciclo par e um com ciclo ímpar, se não for bipartido imprimir o ciclo ímpar. 
OBS.: O algoritmo para imprimir ciclo ímpar considera um grafo não direcionado.

------

EXERCÍCIO EM MONITORIA - 13/09/2016

Ordenação Topológica.

Dado o Grafo:

enum Vertices {A, B, C, D, E, F, G, H};
                       //  0  1   2   3   4   5   6  7 

void inicializa_grafo(list<int> Adj[]){
   Adj[A].push_back(C);
   Adj[B].push_back(C);
   Adj[C].push_back(D);
   Adj[C].push_back(E);
   Adj[D].push_back(F);
   Adj[E].push_back(F);
   Adj[F].push_back(G);
   Adj[F].push_back(H);
}

Exercício:
Execute o algoritmo de ordenação topológica baseado em DFS. Para o grafo proposto como exemplo.
Qual ordem topológica é encontrada pelo algoritmo? 
Este grafo possui só uma ordenação topológica? Se não, mostre outro exemplo.
Quais são as fontes e sorvedouros do grafo?

-----


EXERCÍCIO EM MONITORIA - 14/09/2016

Classificação das Arestas
As arestas (u,v) podem ser classificadas pela cor do vértice v  que é alcançado quando se passa pela aresta a primeira vez.
Branco: aresta de árvore
Cinza: aresta de retorno
Preto:
        Se u é descoberto antes de v então  (u,v) é uma aresta de avanço
        Se v é descoberto antes de u  então (u,v) é uma aresta de cruzamento

Verificando se um Grafo é acíclico:
Se uma aresta de retorno é encontrada na busca em profundidade então o grafo possui um ciclo. Um grafo é acíclico se e somente se na busca em profundidade não for encontrada nenhuma aresta de retorno.

Dado o Grafo:

#define N 8
enum Vertices {s,t,u,v,x,y,w,z};
                        //0 1 2 3 4 5 6 7
list<int> Adj[N];

void inicializa_grafo() {
   Adj[s].push_back(z);
   Adj[s].push_back(w);
   Adj[z].push_back(y);
   Adj[z].push_back(w);
   Adj[y].push_back(x);
   Adj[x].push_back(z);
   Adj[w].push_back(x);
   Adj[t].push_back(v);
   Adj[t].push_back(u);
   Adj[v].push_back(w);
   Adj[v].push_back(s);
   Adj[u].push_back(v);
   Adj[u].push_back(t);
}

EXERCÍCIO:
Realize uma busca em profundidade no grafo e classifique cada aresta como aresta de árvore, aresta de retorno, aresta de avanço ou aresta cruzada e determine se o grafo é acíclico ou não./
OBS.: Para testar se o grafo é acíclico, basta comentar aresta (x,z) e aresta (u,t).  

-----

EXERCÍCIO EM MONITORIA - 16/11/2016

Problema Multiplicação de Matrizes:
Dada uma sequência de matrizes <A1, A2, … , An >, a Matriz Ai tem dimensionalidade PxQ, tal que P = A[i-1] e Q = A[i]. Encontrar uma parentização para o produto AxA2x… xAn minimizando o número escalar de multiplicações.

Exemplo:
i        0       1     2     3      4
M   50     20    1    10    100
Solução Ótima = 7000

PSEUDOCÓDIGO:

MULT_MATRIZES (i, j):
        se i = j então
                retorne 0
        menor <- oo
        para k <- i até j-1 faça
                v <- MULT_MATRIZES( i , k ) + MULT_MATRIZES( k+1 , j ) + M[ i-1] *M[ k ]*M[ j ] 
                se menor > v então
                        menor = v
        retorne menor


EXERCÍCIO:
Implemente o algoritmo que resolva o problema com programação dinâmica e forneça a complexidade. 


-----

EXERCÍCIO EM MONITORIA - 17/10/2016

Problema dos Hotéis:
Você fará uma viagem de L km, e deseja fazer o menor número de paradas possíveis em hotéis. As posições dos possíveis hotéis são fornecidas no vetor  x[1..n] (em ordem crescente). Não é permitido viajar mais de D km sem fazer uma parada. A viagem começa na posição 0. Assuma que a distância entre hotéis consecutivos é no máximo D, tal que x[1] <= D e x[n] = L.

Exemplo:  
D = 200   e   L=490
i      0       1       2         3        4          5          6          7          8          9        10
x     0     50     80     160    200      210      330      350      410      420      490
SOLUÇÃO ÓTIMA: 4,7,10. Total de paradas = 3.

Abordagem Recursiva: Considere um subproblema S[i] como o número mínimo de paradas em hotéis até o hotel i, assumindo que o hotel i está na solução. Crie o hotel fictício x[0] = 0.  S[n] é a última parada, logo está presente na solução. 
   
PSEUDOCÓDIGO:
HOTEIS(i):
     se i=0 então retorne 0
     menor <- oo
     para j <- 0 até i-1
          se x[i] - x[j] <= D
               NumParadas <- 1+ HOTEIS(j)
               se menor > NumParadas então 
                    menor <- NumParadas
     retorne menor

PRINCIPAL():
     imprima HOTEIS(n)
   
EXERCÍCIO:
Implemente o algoritmo que retorne o número mínimo de parada para o problema dos hotéis, o número de chamadas recursiva e o tempo gasto para encontrar a solução ótima. O algoritmo deve seguir a abordagem recursiva, portanto deve testar todos os casos possíveis e retorna a solução ótima. Forneça a ordem de crescimento do algoritmo.


------


EXERCÍCIO EM MONITORIA - 18/10/2016

Problema dos Hotéis:
Você fará uma viagem de L km, e deseja fazer o menor número de paradas possíveis em hotéis. As posições dos possíveis hotéis são fornecidas no vetor  x[1..n] (em ordem crescente). Não é permitido viajar mais de D km sem fazer uma parada. A viagem começa na posição 0. Assuma que a distância entre hotéis consecutivos é no máximo D, tal que x[1] <= D e x[n] = L.

Abordagem Recursiva: Considere um subproblema S[i] como o número mínimo de paradas em hotéis até o hotel i, assumindo que o hotel i está na solução. Crie o hotel fictício x[0] = 0.  S[n] é a última parada, logo está presente na solução. 

Técnica de Memorização: É uma técnica que pode ser utilizada para reduzir o número de chamadas desnecessárias. A memorização consiste em guardar os valores computados para que eles não precisem ser computados novamente.

PSEUDOCÓDIGO:
HOTEIS(i):
      se i=0 então retorne 0
(*)  se S[i] != NULL então retorne S[i]
      menor <- oo
      para j <- 0 até i-1
           se x[i] - x[j] <= D
                NumParadas <- 1+ HOTEIS(j)
                se menor > NumParadas então 
                     menor <- NumParadas
(*)  S[i] <- menor      
      retorne menor

PRINCIPAL():
     imprima HOTEIS(n)

EXERCÍCIO:
Implemente o algoritmo que retorne o número mínimo de parada para o problema dos hotéis, o número de chamadas recursiva e o tempo gasto para encontrar a solução ótima. O algoritmo deve seguir a abordagem recursiva e usar a técnica de memorização para acelerar o algoritmo. O algoritmo melhorou? Explique e compare o número de chamadas recursiva com o algoritmo sem memorização. 

-----


EXERCÍCIO EM MONITORIA - 18/10/2016

Problema dos Hotéis:
Você fará uma viagem de L km, e deseja fazer o menor número de paradas possíveis em hotéis. As posições dos possíveis hotéis são fornecidas no vetor  x[1..n] (em ordem crescente). Não é permitido viajar mais de D km sem fazer uma parada. A viagem começa na posição 0. Assuma que a distância entre hotéis consecutivos é no máximo D, tal que x[1] <= D e x[n] = L.

Abordagem Recursiva: Considere um subproblema S[i] como o número mínimo de paradas em hotéis até o hotel i, assumindo que o hotel i está na solução. Crie o hotel fictício x[0] = 0.  S[n] é a última parada, logo está presente na solução. 

Técnica de Memorização: É uma técnica que pode ser utilizada para reduzir o número de chamadas desnecessárias. A memorização consiste em guardar os valores computados para que eles não precisem ser computados novamente.

PSEUDOCÓDIGO:
HOTEIS(i):
      se i=0 então retorne 0
(*)  se S[i] != NULL então retorne S[i]
      menor <- oo
      para j <- 0 até i-1
           se x[i] - x[j] <= D
                NumParadas <- 1+ HOTEIS(j)
                se menor > NumParadas então 
                     menor <- NumParadas
(*)  S[i] <- menor      
      retorne menor

PRINCIPAL():
     imprima HOTEIS(n)

EXERCÍCIO:
Implemente o algoritmo que retorne o número mínimo de parada para o problema dos hotéis, o número de chamadas recursiva e o tempo gasto para encontrar a solução ótima. O algoritmo deve seguir a abordagem recursiva e usar a técnica de memorização para acelerar o algoritmo. O algoritmo melhorou? Explique e compare o número de chamadas recursiva com o algoritmo sem memorização. 

----

EXERCÍCIO EM MONITORIA - 19/09/2016

Árvore de Recursão:

T(n) = 2T(n/2) + 0 
T(n) = T(n-2) + 4 
T(n) = 2T(n/2) + 1

Exercício: Use uma árvore de recursão para determinar a função de crescimento das recorrências acima e prove sua resposta.

ATENÇÃO :

Link para respostas:       https://goo.gl/ICzw4L

----


EXERCÍCIO EM MONITORIA - 19/10/2016

Programação Dinâmica:
Muitos algoritmos eficientes seguem o paradigma da programação dinâmica.  Esse paradigma, ou estratégia de projeto de algoritmos, é uma espécie de tradução iterativa inteligente da recursão e pode ser definido, vagamente, como "recursão com apoio de uma tabela".
Para que o paradigma da programação dinâmica possa ser aplicado, é preciso que o problema tenha a propriedade de subestrutura ótima:  a solução de toda instância do problema deve "conter" soluções de instâncias do subproblema.  Essa estrutura recursiva pode, em geral, ser representada por uma recorrência e a recorrência pode ser traduzida em um algoritmo recursivo.  O algoritmo recursivo é tipicamente ineficiente porque refaz, muitas vezes, a solução de cada subproblema.  Uma vez escrito o algoritmo recursivo, entretanto, é “fácil” construir uma tabela para armazenar as soluções dos subproblemas e assim evitar que as soluções sejam recalculadas.  A tabela é a base de um algoritmo de programação dinâmica. 
Assim a característica distintiva da programação dinâmica é a tabela que armazena as soluções das várias soluções do subproblema.  O consumo de tempo do algoritmo é, em geral, proporcional ao tamanho da tabela.
(Referência: http://www.ime.usp.br/~pf/analise_de_algoritmos/aulas/dynamic-programming.html)

Problema dos Hotéis:
Você fará uma viagem de L km, e deseja fazer o menor número de paradas possíveis em hotéis. As posições dos possíveis hotéis são fornecidas no vetor  x[1..n] (em ordem crescente). Não é permitido viajar mais de D km sem fazer uma parada. A viagem começa na posição 0. Assuma que a distância entre hotéis consecutivos é no máximo D, tal que x[1] <= D e x[n] = L.

PSEUDOCÓDIGO:
HOTEIS():
    S[0] <- 0
    para i <- 1 até n
        menor <- oo
        para j <- 0 até i-1
             se x[i] - x[j] <= D
                 NumParadas <- 1+ S[j]
                 se menor > NumParadas então 
                     menor <- NumParadas
        S[i]  <- menor
    retorne S[n]

EXERCÍCIO:
Implementar o Algoritmo que resolva o problema dos Hotéis com a nova técnica, fornecer a complexidade e explicar o preenchimento da tabela.


----

EXERCÍCIO EM MONITORIA - 20/09/2016

Árvore de Recursão:

T(n) = 4T(n/2) + n
T(n) = 3T(n/4) + n

Exercício: Use uma árvore de recursão para determinar a função de crescimento das recorrências acima e prove sua resposta.

ATENÇÃO :

Link para respostas: https://goo.gl/Y8VX4T

-----

EXERCÍCIO EM MONITORIA - 21/09/2016

Árvore de Recursão:

T(n) = T(n/3) + T(2n/3) +  n
T(n) = 3T(n/4) + 1
T(n) = 3T(n/2) + n

Exercício: Use uma árvore de recursão para determinar a função de crescimento das recorrências acima e prove sua resposta.


ATENÇÃO :

Link para respostas: https://goo.gl/iTT3w5

-----

   EXERCÍCIO EM MONITORIA - 21/11/2016
Problema Maior Subsequência Comum.
O problema da maior subsequência comum (longest commom subsequence) (LCS) é o problema de encontrar a maior subsequência comum a duas sequências X e Y. Este é um problema clássico para comparação de arquivos e bioinformática. 


Por exemplo, dado as strings que representam duas sequências:
A = “0121401”
B = “142010'”
Resultado: A maior subsequência comum para este exemplo é “1201” de tamanho 4.


PSEUDOCÓDIGO:
MSC ( i ,  j):
    se i==0 ou j == 0, então
        retorne 0
    se A[i-1] = B[j-1]
       res =   1 + MSC(i-1, j-1)
   else
             res = max ( MSC(i-1, j) , MSC (i, j-1) )
   retorne res




EXERCÍCIO:
Implemente o algoritmo que resolva o problema com programação dinâmica retornando o tamanho da maior subsequência comum e forneça a complexidade. 

-----
   EXERCÍCIO EM MONITORIA - 21/11/2016
Problema Maior Subsequência Comum.
O problema da maior subsequência comum (longest commom subsequence) (LCS) é o problema de encontrar a maior subsequência comum a duas sequências X e Y. Este é um problema clássico para comparação de arquivos e bioinformática. 


Por exemplo, dado as strings que representam duas sequências:
A = “0121401”
B = “142010'”
Resultado: A maior subsequência comum para este exemplo é “1201” de tamanho 4.


PSEUDOCÓDIGO:
MSC ( i ,  j):
    se i==0 ou j == 0, então
        retorne 0
    se A[i-1] = B[j-1]
       res =   1 + MSC(i-1, j-1)
   else
             res = max ( MSC(i-1, j) , MSC (i, j-1) )
   retorne res




EXERCÍCIO:
Implemente o algoritmo que resolva o problema com programação dinâmica retornando o tamanho da maior subsequência comum e forneça a complexidade. 


------

EXERCÍCIO EM MONITORIA - 22/11/2016

Problema Distância de Edição
Dadas duas palavras X e Y, definimos a distância de edição D(X, Y) entre elas como a quantidade mínima de operações necessárias para transformar X em Y ou vice-versa. As operações podem ser:
Substituição (Replacement), Inserção (Insertion),  Remoção (Deletion) e Pareamento (Match). A operação de pareamento não é contada na distância de edição e valores menores indicam menor distância de edição.
Exemplo:
X = “EXPONENCIAL”
Y = “POLINOMIAL”
 Solução ótima: distância = 6.

PSEUDOCÓDIGO:
DISTANCIA_EDICAO (  i ,  j ):
       se i = 0 então j
       se j = 0 então i 
       se X[i-1] = Y[j-1] então d = 0
       senão d = 1
       return min( DISTANCIA_EDICAO(i-1, j-1)+d ,
                             DISTANCIA_EDICAO(i-1,j)+1 ,
                             DISTANCIA_EDICAO(i, j-1)+1 )




EXERCÍCIO:
Implemente o algoritmo que resolva o problema com programação dinâmica e forneça a complexidade. 

------

EXERCÍCIO EM MONITORIA - 23/11/2016

Problema  do(s) Caminho(s) Mínimo(s)
Seja G um grafo orientado e suponha que para cada aresta (u, v ) associamos um peso (custo, distância) w(u,v).  
Problema do Caminho Mínimo entre Dois Vértices:
          Dados dois vertices s e t em  um grafo, encontrar um caminho (de peso) mínimo de s a t.

LINK GRAFOS: https://goo.gl/58FvLu

EXERCÍCIO:
Para cada grafo proposto indique o algoritmo mais adequado para encontrar os caminhos mínimos do vértices A para todos os outros vértices, caso não seja possível mostre por quê. Além disso escolha um dos grafos e preencha uma tabela informando o predecessor de todos os vértices e a distância do vértice A para todos os outros vértices.


-----

EXERCÍCIO EM MONITORIA - 24/10/2016

Problema Árvore Geradora Mínima:
Definição: Um subgrafo gerador de um grafo G=(V,E) é um grafo G1=(V,E1) que possui os mesmos vértices de G. Quando o subgrafo gerador é uma árvore ele recebe o nome de árvore geradora.
Definição: Seja G=(V,E) um grafo conexo onde cada aresta e possui um peso p(e). Denomina-se peso de uma árvore geradora T=(V,ET) de G a soma dos pesos das arestas ET. Uma árvore geradora mínima é a árvore geradora de G que possui peso mínimo dentre todas as árvore geradoras de G.
O problema tem solução se e somente se o grafo G é conexo.  Outra observação: se todos as arestas tiverem o mesmo custo então toda árvore geradora é uma mst. Para mais detalhes acessem: http://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/mst.html e http://www.lcad.icmc.usp.br/~nonato/ED/Grafos/node81.html

PSEUDOCÓDIGO:

AGM-PRIM (G, w, r )
      para cada u ∈ V [G]
            key[u] ← ∞
            π[u] ← NIL
      key[r ] ← 0
      Q ← V [G]  // BUILD-MIN-HEAP(V(G))
      enquanto Q != ∅ faça
            u ← EXTRACT-MIN (Q)
            para cada v adjacente Adj[u]
                  se v ∈ Q e w(u, v ) < key[v] então
                        π[v ] ← u
                        key[v ] ← w(u, v )
                        DECREASE-KEY(Q)
                        


GRAFO PARA TESTE:
Segue no LINK:       https://goo.gl/9cIccC


EXERCÍCIO:
Implemente o Algoritmo Prim, teste para   o grafo fornecido e imprima as arestas que pertencem a árvore geradora mínima.E qual a complexidade do Prim? 



-----

EXERCÍCIO EM MONITORIA - 25/10/2016

Problema Árvore Geradora Mínima.

PSEUDOCÓDIGO:

AGM-KRUSKAL(Adj,n,w[]):
   para v <- 1 até n, faça MAKE-SET(v)                     
   ordene as arestas em ordem não-decrescente de peso      
   para cada aresta (u,v) nesta ordem,                       
      se FIND-SET(u) != FIND-SET(v)                        
         imprima (u,v)                                     
         UNION(u,v)                                        

GRAFO PARA TESTE:
Segue no LINK: https://goo.gl/9cIccC

EXERCÍCIO: 
Implemente o Algoritmo Kruskal, teste para o grafo fornecido e imprima as arestas que pertencem a árvore geradora mínima.  Forneça a complexidade. Para os que já implementaram em aula, simule o algoritmo no seguinte grafo:  https://goo.gl/HIagYs.
-

-----

   EXERCÍCIO EM MONITORIA - 26/09/2016

Um vetor A[1...n] é dito ter um elemento majoritário se mais do que a metade de suas entradas tem o mesmo valor. Portanto, x é um elemento majoritário de A se o número de ocorrências de x em A é maior do que n/2.  Para este problema temos uma solução simples, se  o vetor estiver ordenado, mas para ordenar um vetor gastamos Theta(n.log n), conseguimos uma solução melhor com divisão e conquista.

PSEUDOCÓDIGO:

majoritario( A, n, x, c)
    
    se c=0 então
        se n=0 então retorne -1
        se n=1 então retorne A[1];
        se A[n-1] != A[n-2] então
            retorne majoritario(A, n-2, x, c)
        senão
            retorne majoritario(A, n-2, A[n-1], c+2)
    senão
        se n=0 então retorne x;
        se A[n-1] = x então
            retorne majoritario(A, n-1, x, c+1)
        senão
            retorne majoritario(A, n-1, x, c-1)    

principal()
    m <- majoritario (A, n, oo, 0) 
    verifica se m é majoritário, se sim imprima m, senão imprima -1

EXERCÍCIO:
Implementar um algoritmo que, dado um vetor com tamanho de entrada n, determina se há um majoritário e, se for o caso, imprima-o. Teste com diferentes vetores e mostre qual a complexidade deste algoritmo.    

-----

EXERCÍCIO EM MONITORIA - 26/10/2016

Componentes Conexos utilizando a estrutura de dados para conjuntos disjuntos (UNION-FIND).
O problema: Dado um grafo não-orientado G determinar seus componentes conexos. Após determinar seus componentes conexos, é possível verificar com eficiência se para quaisquer dois vértices do grafo eles pertencem ao mesmo componente?
PSEUDOCÓDIGOS:
CONNECTED-COMPONENTS (G): ́
      para cada v ∈ V [G] faça
            M AKE-SET (v )
      para cada aresta (u, v ) ∈ E[G] faça
            se F IND-SET (u) != F IND-SET (v ) então
                  U NION (u, v )

SAME-COMPONENT (u, v ):
      se F IND-SET (u) = F IND-SET (v ) então
            retorne VERDADEIRO
      senão
            retorne FALSO

EXERCÍCIO:
Implemente o algoritmo que determine quais os componentes conexos do grafo fornecido para teste, forneça a complexidade e diga se após executar o algoritmo é possível verificar em O(1) se dois vértices estão no mesmo componente, se sim, como? GRAFO TESTE : https://goo.gl/uUIEz2


-----


EXERCÍCIO EM MONITORIA - 27/09/2016

PSEUDOCÓDIGO:

Solução FUP:
pow (a,n):
   p <- a
    para i <- 2 até n faça
        p <- p * a
    return p

Solução DeC:
pow(a,n):
    se n=0 então
        return 1
    m <- piso(n/2)
    p <- pow(a, m)
    se n é par então 
        return p*p
    senão 
        return p*p*a
    

O problema consiste em computar a^n, tal que n pertence aos Naturais.

EXERCÍCIO:
Implemente os dois algoritmos e calcule o tempo para diferentes entradas



-----

EXERCÍCIO EM MONITORIA - 28/09/2016

   PSEUDOCÓDIGO:

Mergesort (A, p, r) 
    se  p < r  então  
        q ← ⌊(p+r)/2⌋ 
        Mergesort (A, p, q) 
        Mergesort (A, q+1, r) 
        Intercala (A, p, q, r) 


Intercala (A, p, q, r) 
    para  i crescendo de p  até  q  faça 
        B[i] ← A[i] 
    para  j crescendo de q+1  até  r  faça 
        B[r+q+1−j] ← A[j] 
    i ← p
    j ← r   
    para  k crescendo de p  até  r  faça 
        se  B[i] ≤ B[j] então 
            A[k] ← B[i] 
            i ← i+1 
        senão  A[k] ← B[j] 
            j ← j−1 


EXERCÍCIO:
Implemente e o algoritmo do MergeSort e calcule sua complexidade (Dica: Use o Teorema Mestre).


------

EXERCÍCIO EM MONITORIA - 28/09/2016

   PSEUDOCÓDIGO:

Mergesort (A, p, r) 
    se  p < r  então  
        q ← ⌊(p+r)/2⌋ 
        Mergesort (A, p, q) 
        Mergesort (A, q+1, r) 
        Intercala (A, p, q, r) 


Intercala (A, p, q, r) 
    para  i crescendo de p  até  q  faça 
        B[i] ← A[i] 
    para  j crescendo de q+1  até  r  faça 
        B[r+q+1−j] ← A[j] 
    i ← p
    j ← r   
    para  k crescendo de p  até  r  faça 
        se  B[i] ≤ B[j] então 
            A[k] ← B[i] 
            i ← i+1 
        senão  A[k] ← B[j] 
            j ← j−1 


EXERCÍCIO:
Implemente e o algoritmo do MergeSort e calcule sua complexidade (Dica: Use o Teorema Mestre).

----

EXERCÍCIO EM MONITORIA - 28/11/2016
Problema Caminho Mínimo em Grafo

Considere o algoritmo Dijkstra abaixo. Suponha que estamos decidindo qual estrutura de dados utilizar para representar Q, dentre as possibilidades: 
1- Lista Encadeada, ou 
2- Min-Heap. 


DIJKSTRA(s):
       para todo vértice v, faça
              d[v] <- oo
              pi[v] <- NULO
       d[s] <- 0
       Q <- inicializadas com todos os vértices
       enquanto Q não está vazia
              u <- Pegar o menor em Q
       para cada vértice v em Adj[u]
                     RELAX(u,v)
                     atualizaQ(v,d[v]) 


EXERCÍCIO:
Determine qual estrutura de dados é mais apropriada para Q. Justifique comparando as complexidades.

----

EXERCÍCIO EM MONITORIA - 29/08/2016
 
Selection Sort: A ordenação por seleção consiste, em cada etapa, selecionar o menor (ou o maior) elemento e colocá-lo em sua posição correta dentro da futura lista ordenada. 

PSEUDOCÓDIGO:

SELECTION-SORT(A)
para i<-0 até n-1 faça             
    min <- i                        
    para j<-(i+1) até n faça              
        se A[j] < A[min] então
            min <- j
    se i != min então
        troca A[i] <-> A[min]


Exercício - 
PARTE I - Implementar o algoritmo SELECTION-SORT, analisar o tempo do algoritmo em seu melhor e pior caso, para vetores de entrada grandes.
PARTE II - Calcular a complexidade para o melhor e pior caso, indicando a função de crescimento do algoritmo.

      
-----

/*EXERCÍCIO EM MONITORIA - 29/11/2016

Problema Caminho Mínimo em Grafo
Após realizar uma busca em profundidade em um grafo orientado G = (V,E), você observou que não existe aresta (u,v) 
pertencente ao conjunto de arestas E tal que d[v] < d[u] < f[u] < f[v]. O que se pode extrair de informação da 
afirmação anterior?



LINK para o GRAFO: https://goo.gl/h1cpHv

EXERCÍCIO:
Implemente um algoritmo que retorna o tamanho do caminho mínimo de A para todos os outros vértices no grafo e 
forneça a complexidade. Atenção escolha o algoritmo com menor complexidade possível para este tipo de grafo.*  

void inicializa_grafo(){
    enum Vertices {A,B,C,D,E,F,G,H,I};
                 //0 1 2 3 4 5 6 7 8
   Adj[A].push_back(B); w[A][B] = 4;
   Adj[A].push_back(D); w[A][D] = 24;
   Adj[B].push_back(C); w[B][C] = 17;
   Adj[B].push_back(E); w[B][E] = 7;
   Adj[C].push_back(F); w[C][F] = 2;
   Adj[D].push_back(B); w[D][B] = 26;
   Adj[D].push_back(E); w[D][E] = 14;
   Adj[D].push_back(G); w[D][G] = 7;
   Adj[E].push_back(F); w[E][F] = 13;
   Adj[E].push_back(H); w[E][H] = 17;
   Adj[F].push_back(I); w[F][I] = 7;
   Adj[G].push_back(H); w[G][H] = 4;
   Adj[H].push_back(F); w[H][F] = 7;
   Adj[H].push_back(I); w[H][I] = 12;
}

-----

EXERCÍCIO EM MONITORIA - 30/08/2016

Multiplicação de Matrizes

PSEUDOCÓDIGO:

MULT_MATRIZES(A, la, ca, B, lb,cb, C )
para lc <- 0 até la faça
      para cc <- 0 até cb faça
           para k <- 0 até lb faça
                  C[lc][cc] <- C[lc][cc] + A[lc][k]*B[k][cc]


Exercício:
PARTE I: Implemente o algoritmo de multiplicação de matrizes e analise o tempo para matrizes de tamanho diferentes.
PARTE II: Analise o algoritmo e dê a ordem de grandeza pra operação de mutiplicação de matrizes.

-----


EXERCÍCIO EM MONITORIA - 30/11/2016

Uma string S com n caracteres possui um texto que parece estar corrompido. O que está claro neste texto é o fato de todos os espaços e pontuações terem sido removidos, restando apenas as letras. Por exemplo, a string poderia ser “exercíciodequartamonitoria”. 
Considere que você dispõe de uma função dic(w) que retorna verdadeiro quando a palavra w pertence ao dicionário, e falso caso contrário. Assuma que esta função executa em tempo constante.
O objetivo é reconhecer se o texto é válido.

Solução Recursiva  (de tempo exponencial)
PSEUDOCÓDIGO:

STRING_VALIDA(i):
      se i > n então
            retorne verdadeiro
      para j <- i até n
            se dic(i,j) e STRING_VALIDA( j+1)
                  retorne verdadeiro
      retorne falso
            
EXERCÍCIO:
Implemente o algoritmo que resolva o problema com programação dinâmica retornando se a string é válida e forneça a complexidade.    

-----

EXERCÍCIO EM MONITORIA - 31/08/2016

Exercício 
Gere um grafo Aleatório com 10000 vértices e densidade 0,1. 
Declare uma matriz para representar o grafo. Gere o complemento do grafo Aleatório pra nova matriz.

O complemento de um grafo G, denotado por  G’, é um grafo com
V(G’) = V(G)      e   (v,u)  pertence  E(G’) sse (v,u)  não pertence E(G)
Exemplo: O complemento de um grafo completo é um grafo nulo.

-----

EXERCÍCIO EM MONITORIA - 31/10/2016


Problema Árvore Geradora Mínima:
Correções e Finalizar Algoritmo Prim


PSEUDOCÓDIGO:

   
AGM_PRIM( raiz):
      para u <- 1 até N faça
            vertices[u].key = oo
            vertices[u].pi = NULL
      vertices[raiz].key = 0;
      crie uma min heap Q contendo vértices priorizado pela key
      inicialize Q com os vértices setando a flag para verdadeiro
      enquanto Q != vazio faça
            u = EXTRACT_MIN( Q ) 
            vertices[u.id].flag = falso
            para cada aresta it em Adj[u]
                  se vertices[it.v].flag and it.peso < vertices[it.v].key então
                        vertices[it.v].pi = u.id
                        vertices[it.v].key = it.peso
                        DECREASE-KEY( Q ) 


GRAFO PARA TESTE:
Segue o link com o inicializar do grafo e detalhes para testar o algoritmo. LINK: https://goo.gl/9cIccC


EXERCÍCIO:
Implemente o Algoritmo Prim, teste para o grafo fornecido e imprima as arestas que pertencem a árvore geradora mínima. Qual a complexidade do Prim?
   

   