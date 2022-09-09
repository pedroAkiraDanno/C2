 /**********************************************
  * OBJETIVO  : ESTRUTURA-DE-DADOS-list        *
  * CRIACAO   : 06-01-2019	                   *
  * VERSAO    : 1.0		                       *
  * AUTOR     : Pedro Akira Danno Lima         *
  **********************************************/



------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

[ED] Aula 67 - Árvores


 
 #include <stdio.h>
 #include <stdlib.h>

 int main(){
 	"arvore"
 	-sao um tipo especial de grafo.
 	-qualquer par de vertices esta conectado a apenas uma aresta.
 	-grafo conexo (existe exatamente um caminho entre quaisquer dois de seus vertices)
 	 e aciclico (nao possui ciclos).
    

    "arvore"
    -como sao um tipo especial de grafos, elas são definidas como um conjunto nao vazio de "vertices" (ou nos) 
     e "arestas" que satisfazem requisitos.


     "vertices"
     - É cada uma das entidades representadas na arvore (depende da natureza do problema)
     - NODE, NÓ


     "arestas"
     - E uma conexao entre dois "vertices"
     - LINHAS 



     arvore EXEMPLO - DIRETORIOS 
     ESTRUTURA DE DIRETORIOS PODE SER REPRESENTADO POR ARVORES.




     APLICAÇÕES
     -arvores sao adequadas para representar estruturas hieranquicas nao lineares

     exmeplos:
     -relacoes de descendencia (pai,filho,etc)
     -diagrama hierarquico de uma organizacao 
     -compeonatos de modalidades despotivas
     -taxonomia 


     "em computacao"
     -estrutura de diretorios (pastas)
     -busca de dados armazenados no computador
     -representacao de espaço de solucoes (ex: jogo de xadrez)
     -modelagem de algoritmos




     Formas de represntacao 
     -grafos
     -diagrama de venn

 	return 0;
 }





 #include <stdio.h>
 #include <stdlib.h>

 int main(){
 	exixstem varios tipos de arvores em computacao, desenvolvidas para diferentes
 	tipos de aplicacoes:
 	-arvore binaria de busca
 	-arvore AVL (arvores balanceada)
 	-arvore rubro-negra 	
 	-arvore b,b+,b*
 	-arvore 2-3
 	-arovore 2-3-4
 	-quadtree (seguimentacao, jogos)
 	-octree
 	-etc


	return 0;
 }






fonte: 
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------






------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


[ED] Aula 68 - Árvores - Propriedades



 #include <stdio.h>
 #include <stdlib.h>

 int main(){
 	"Propriedades"
 	-"pai":    é o antecessor imediato de um vertice
 	-"filho":  é o sucessor imediato de um vertice
 	-"raiz":   é o vertice que nao possui "pai"
 	-"nos terminais" ou "folhas": qualquer vertice que nao possui filhos.
 	-"nos nao-terminais" ou "internos": qualquer vertice que possui pelo menos "1" filho.



    -"caminho em uma arvore"
    -É uma sequencia de vertices de modo que existe sempre uma aresta ligada o vertice anterior
    com o seguinte.

    -existe exatamente um caminho entre a raiz e cada um dos nos da arvore



    "sub arvore"
    -dado um determiado vertice, cada "filho" seu é uma "raiz" de uma nova sub-arvore

    -de fato, qualquer vertice é a raiz de uma sub-arvore consistindo dele e dos nos abaixo dele



    -"grau de um vertice"
    -É o numero de sub-arvores do vertice.


    "Altura da arvore"
    -tambem chamdad de "profundidade"
    -É o comprimento do caminho mais longo da "raiz" ate uma das suas folhas.




    "Nivel"
    -numa arvore, os vertices sao classificados em niveis 
    -o Nivel é o numero de nos no caminho entre o vertice e a raiiz 











	return 0;
 }







fonte: https://www.youtube.com/watch?v=U7IiLJlMfnU&list=PL8iN9FQ7_jt7LwqmdiyhVVu2J4jQQ9uRW&index=2
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------





















------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

[ED] Aula 69 - Árvore Binária: Definição






 #include <stdio.h>
 #include <stdlib.h>

 int main(){

 -"arvore binaria"
 -é um tipo especial de arvore
 -cada vertice pode possuir duas "sub-arvore"
 -sub-arvore esquerda e sub-arvore direita
 -o grau de cada vertice (numero de filhos) pode ser de 0,1 ou 2





"arvore estritamente binaria"
-cada no(vertice) possui 0 ou 2 sub-arvores
-nenhum no tem "filho unico"
-nos internos (nao folhas) sempre tem 2 filhos






"arovre binaria completa"
-É "estritamente binaria" e todos os seus "nos-folha" estao no mesmo nivel.
-O numero de nos de uma arvore binara completa é 2^h-1, onde "h" é a altura da arvore



"arvore binaria quase completa"
-a diferenca de altura entre as sub-arvores de qualquer no é no maximo 1.
-se a altura da arvore é D, cada no folha esta no nivel "D" ou "D-1".






	return 0;
 }





fonte: https://www.youtube.com/watch?v=9WxCeWX9qDs&list=PL8iN9FQ7_jt7LwqmdiyhVVu2J4jQQ9uRW&index=3
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------












  /*****************************************************************************************************************
  *                                                   REFERENCIAS      	                                           *
  *https://www.youtube.com/watch?v=iLvpaqAoVD8&list=PL8iN9FQ7_jt7LwqmdiyhVVu2J4jQQ9uRW&index=1					   *
  *https://www.youtube.com/watch?v=U7IiLJlMfnU&list=PL8iN9FQ7_jt7LwqmdiyhVVu2J4jQQ9uRW&index=2					   *
  *https://www.youtube.com/watch?v=9WxCeWX9qDs&list=PL8iN9FQ7_jt7LwqmdiyhVVu2J4jQQ9uRW&index=3					   *
  ******************************************************************************************************************/