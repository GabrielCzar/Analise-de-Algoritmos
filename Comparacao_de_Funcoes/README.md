# Comparação de Funções

_Determine qual função cresce mais rápido (ou se crescem iguais). Anote quais regras e simplificações você usou, e verifique se está de acordo com a resposta fornecida._

- Regras  

  1. Constantes multiplicativas podem ser omitidas.  
  ```
  F(x) = N
  G(x) = 2N
  Resposta: Crescem iguais.
  ```
  2. Polinômio de maior grau domina.
  ```
  F(x) = N³
  G(x) = N²
  Resposta: F(x) domina.
  ```
  3. Potência de maior base domina.
  ```
  F(x) = 4^x
  G(x) = 5^x
  Resposta: G(x) domina.
  ```
  4. Fatorial domina exponencial.
  ```
  F(x) = N!
  G(x) = N¹⁰⁰
  Resposta: F(x) domina.
  ```
  5. Exponencial com base maior que 1 (ou fatorial) domina polinômio.
  ```
  F(x) = 100^N
  G(x) = N¹⁰⁰
  Resposta: F(x) domina.
  ```
  6. Polinômio domina potência de logaritmo.
  ```
  F(x) = (log N)⁹
  G(x) = N¹
  Resposta: G(x) domina.
  ```
  7. Crescimento de logaritmo não depende
  da base.
  ```
  F(x) = log N, na base 10
  F(x) = log N, na base 2
  Resposta: Crescem iguais.
  ```
  8. Ao comparar funções, use o termo que domina em cada uma delas.
  ```
  F(x) = N² + N!
  G(x) = N!
  Resposta: N! domina na F(x), então agora F(x) = N!. Logo as funções crescem iguais.
  ```

Obs.:
- Fatorial(n!): É muitas vezes dito ter complexidade exponencial, apesar de o fatorial ter comportamento muito pior.
Geralmente ocorre quando se usa uma solução de força bruta.  

- Exponencial(a^n): Geralmente quando se usa uma solução força bruta.

- Cubica(n³): Ocorre em multiplicações de matrizes, com três estruturas de repetição
aninhadas.

- Quadrática(n²): Ocorre frequentemente quando os dados são processados aos pares,
com laços de repetição aninhados.

- Log linear(n . log n): Típico de algoritmos que resolvem um problema transformando-o em problemas menores, resolvem cada um de forma independente e depois ajunta as soluções.

- Linear(n): Em geral, uma certa quantidade de operações é realizada sobre cada um dos elementos de entrada. Melhor situação para quando é preciso processar n elementos de entrada e obter n elementos de saída.

- Logarítmica(log n): Típica de algoritmos que resolvem um problema transformando-o em
problemas menores.

- Constante(1): Independente do tamanho de n, operações executadas um número fixo
de vezes.
