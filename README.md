# Soma de Riemann por meio de iterações

O seguinte código aproxima a área do gráfico de uma função qualquer e possui mecanismos de verificação para checar se o resultado é muito discrepante do obtido através dos meios rigorosos de integração. A Soma de Riemann consiste numa aproximação feita por meio da divisão da área abaixo de uma curva em retângulos ínfimos.

## Como funciona
 O cerne do programa reside nas duas primeiras funções. Primeiramente, *computar_soma_Riemann* pega uma função de x, um intervalo de *a* até *b* e um pequeno incremento para o valor de x (convenientemente denominado *dx*, embora não seja infinitesimal) e, por repetidas iterações, vai acrescentando o produto $f(x) \cdot dx$ a uma variável chamada *somatório*, que começa com valor zero. Ao final, o gráfico foi dividido em $\frac{(b-a)}{dx}$ retângulos, que foram somados e cujo somatório é retornado pela função. O valor assumido por dx varia ao longo do código: normalmente usa-se $10^{-7}$, mas quando mais precisão é necessária usa-se $10^{-8}$.
    
    
   Posteriormente, a *função testar_funcao* usa o valor retornado por *computar_soma_Riemann* para uma função matemática qualquer especificada e compara-o com o valor obtido pela integração tradicional. Caso o módulo da diferença seja menor que a tolerância (que vale $10^{-6}$), o teste passa. Do contrário, reprova.

## Casos de teste
  O código possui ao todo 10 casos de teste. São eles:
  - Função linear: $f(x) = 2x$
  - Função quadrática: $f(x) = x^2 + 1$
  - Função raiz quadrada: $f(x) = \sqrt{x}$
  - Função seno: $f(x) = \sin{x}$
  - Função cosseno: $f(x) = \cos{x}$
  - Função polinomial: $f(x) = x^5 + 2x^4 + x^2$
  - Função racional: $f(x) = \frac{1}{1+x}$
  - Função logarítmica de base $e$: $f(x) = \ln(x)$
  - Função exponencial: $f(x) = 2^{x}$
  - Função ímpar de intervalo simétrico: $f(x) = x^5 - x^3 + 7x$

## Input
Caso o usuário queira fazer um teste com uma função própria num intervalo próprio, ele deve, primeiramente, declarar sua função matemática na *main*. Digamos que se queira saber a soma de Riemann da função $f(x) = \sin{2x}$ no intervalo de $0$ a $\frac{\pi}{2}$. Digamos, ainda, que ela saiba que o resultado da integral é $1$. Nesse caso, declare na função *main*:

`auto funcao_qualquer = [](double x){return sin(2x); };`

Em seguida, chame a função teste:

`testar_funcao(funcao_qualquer, 0, pi/2, 1e-7, 1.0, "funcao qualquer");`

Em outros termos, aproximar-se-á:

$$\int_0^{\frac{\pi}{2}}sin(2x)dx$$

Aparecerá a mensagem no terminal comparando o valor esperado e o calculado. Lembrando: quanto menor o dx, que neste caso é "1e-7", ou $10^{-7}$, mais preciso o cálculo.

## Vídeo rodando o código
