  /***********************************************
  * OBJETIVO  : ESTRUTURA-DE-DADOS-strack/pilha  *
  * CRIACAO   : 25-09-2019	                 *
  * VERSAO    : 1.0		                 *
  * AUTOR     : Pedro Akira Danno Lima           *
  ************************************************/


    #include <stdio.h>
    #include <stdlib.h>

    
    /* Protótipos da funçoes */


    int main(void)
    {

        return(0);
    }





  /*

  A PILHA
  
  Um dos conceitos mais úteis na ciência da computação é o de pilha. Neste
  capítulo, examinaremos essa estrutura de dados decepcionantemente sim-
  ples e verificaremos por que ela desempenha esse proeminente papel nas
  áreas de programação e de linguagens de programação. Definiremos o
  conceito abstrato de uma pilha e provaremos como esse conceito pode ser
  transformado numa ferramenta concreta e valiosa para a solução de problemas.

  DEFINIÇÃO E EXEMPLOS

  Uma pilha é um conjunto ordenado de itens no qual novos itens podem ser
  inseridos e a partir do qual podem ser eliminados itens em uma extremidade
  chamada topo da pilha. Podemos ilustrar uma pilha como a da Figura 2.1.1.


  Ao contrário do que acontece com o vetor, a definição da pilha
  compreende a inserção e a eliminação de itens, de modo que uma pilha é um
  objeto dinâmico, constantemente mutável. Por conseguinte, surge então a
  pergunta: como uma pilha muda? A definição especifica que uma única
  extremidade da pilha é designada como o topo da pilha. Novos itens podem
  ser colocados no topo da pilha (em cujo caso este topo será deslocado para
  cima, de modo a corresponder ao novo primeiro elemento), ou os itens que

  estiverem no topo da pilha poderão ser removidos (em cujo caso esse topo
  será deslocado para baixo, de modo a corresponder ao novo primeiro elemen-
  to). Para responder à pergunta qual é o lado de cima?, precisaremos
  determinar que extremidade da pilha será designada como topo — isto é, em
  que extremidade serão incluídos ou eliminados itens. Desenhando a Figura
  2.1.1 de modo que F esteja fisicamente em cima na página em relação aos
  outros itens na pilha, estaremos implicando que F é o atual elemento superior
  da pilha. Se forem incluídos novos itens na pilha, eles serão colocados acima
  de F e, se forem eliminados alguns itens, F será o primeiro a ser eliminado.
  Isso é também indicado pelas linhas verticais que se estendem além dos itens
  da pilha, na direção do topo da pilha.


A Figura 2.1.2 é um filme de uma pilha conforme ela se expande e
se reduz com o passar do tempo. A Figura 2.1.2a mostra um instantâneo da
pilha da Figura 2.1.1. Na Figura 2.1.2b, o item G é incluído na pilha. De
acordo com a definição, só existe um local na pilha onde'ele pode ser incluído
— no topo. Agora, o primeiro elemento da pilha é G. Com a movimentação
da imagem pelos quadros c, d e e, os itens H, I e J são sucessivamente
incluídos na pilha. Observe que o último item inserido (neste caso, J) está
no topo da pilha. Entretanto, a partir do quadro f, a pilha começa a diminuir,
quando primeiro J, depois I,H e G são sucessivamente removidos. Em cada
etapa, o elemento superior é removido, uma vez que uma eliminação só pode
ser feita a partir do topo. 0 item G não poderia ser removido da pilha antes
dos itens J, I e H. Isso ilustra o atributo mais importante de uma pilha, em
que o último elemento inserido numa pilha é o primeiro elemento eliminado.
Sendo assim, J é eliminado antes de I porque J foi inserido depois de I. Por
essa razão, ocasionalmente uma pilha é chamada lista last-in, first-out (LIFO
— ou UEPS, o último a entrar é o primeiro a sair).88
Estruturas de Dados Usando C Cap. 2
Entre os quadros j e k, a pilha parou de diminuir e começou a crescer
novamente, com a inclusão do item K. Entretanto, esse crescimento tem vida
curta, porque, em seguida, a pilha se reduz a apenas três itens no quadro n.
Observe que não há como distinguir entre o quadro a e o quadro i,
examinando o estado da pilha nas duas ocorrências. Em ambos os casos, a
pilha contém os mesmos itens, na mesma ordem, e apresenta o mesmo topo.
Não existe um registro do fato de que quatro itens tenham sido incluídos e
eliminados na pilha, nesse ínterim. De modo semelhante, não há como
distinguir entre os quadros d e f, ou j e 1. Se for necessário um registro dos
itens intermediários que passaram pela pilha, esse registro deverá ser
mantido em outro lugar; ele não existe dentro da própria pilha.
Na realidade, apresentamos uma visão estendida do que é realmente
observado numa pilha. A verdadeira imagem de uma pilha é dada por uma
visualização de cima para baixo, em vez de por uma visão em perfil, de fora
para dentro. Sendo assim, na Figura 2.1.2, não existe uma diferença percep-
tível entre os quadros h e o. Em cada caso, o elemento posicionado no topo
é G. Embora a pilha no quadro h e a pilha no quadro o não sejam iguais, a
única maneira de determinar esse fato é removendo todos os elementos das
duas pilhas e comparando-os individualmente. Mesmo que tenhamos obser-
vado perfis laterais de pilhas para simplificar nosso entendimento, deve-se
observar que o fizemos arbitrariamente e que não há uma possibilidade real
de existir tal imagem.
OPERAÇÕES PRIMITIVAS
As duas mudanças que podem ser introduzidas numa pilha recebem nomes
especiais. Quando um item é incluído numa pilha, ele é empilhado sobre a
pilha e, quando um item é removido, ele é desempilhado. Em função de
uma pilha s e de um item i, executar a operação push(s, i) incluirá o item i
no topo da pilha s. De modo semelhante, a operação pop(s) removerá o
elemento superior e o retornará como valor da função. Assim, a operação de
atribuição:
i = pop(s);
remove o elemento posicionado no topo de s e atribui seu valor a i.



Por exemplo, se s for a pilha da Figura 2.1.2, executaremos a
operação push(s, G), ao passar do quadro a para o b. Em seguida, executamos
sucessivamente as seguintes operações:
push
push
push
pop
pop
pop
pop
pop
push
pop
pop
pop
push
(s,H);
(s,I) ',
(s,J);
(s);
(s);
(s);
(s);
(s);
(s,K);
(s);
(s);
(s);
(s,G);
(quadro ( c ) )
(quadro ( d ) )
(quadro ( e ) )
(quadro ( f ) )
(quadro ( g ) )
(quadro ( h ) )
(quadro ( i ) )
(quadro ( j ) )
(quadro ( k ) )
(quadro ( l ) )
(quadro (m))
(quadro ( n ) )
(quadro ( o ) ) .
Devido à operação push que adiciona elementos a uma pilha, uma
pilha é às vezes lista pushdown








CHUNK
DIRETRIZES
ISCSI


  */














  /*****************************************************************************************************************
  *                                                   REFERENCIAS      	                                           *
  *https://www.cin.ufpe.br/~garme/public/(ebook)Estruturas%20de%20Dados%20Usando%20C%20(Tenenbaum).pdf             *
  ******************************************************************************************************************/

































