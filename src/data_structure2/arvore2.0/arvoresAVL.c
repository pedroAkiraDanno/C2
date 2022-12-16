  /************************************************
  * OBJETIVO  : ESTRUTURA-DE-DADOS-AVL_tree       *
  * CRIACAO   : 31-01-2020	                      *
  * VERSAO    : 1.0		                          *
  * AUTOR     : Pedro Akira Danno Lima            *
  ************************************************/






/*
ARVORES AVL

-O AVL vem de seus autores Adelson-Velskii e landis (em 1962)

-Basicamente:
	-Sao arvores binarias com balanceadas
	-Mas o que é esse tal "balanceamento"?
	-Um lado nao é mais "pesado" que o outro
	-Ha um limete maximo para a "diferenca" de altura dos filhos

-Calculamos um "fator de balanceamento", que indica se um no da arvore tem filhos 
que pendem para um lado ou outro(ou nenhum - equilibrio)

-Por que é bom?
	-Garante-se um tempo maximo de busca - que é log2(n)
	*obs: 1024 elementos-em no maximo 10 passos. Se dobra elementos, so aumenta 1 passo.  1 milhao de elementos - 20 passos
	-A arvore deve sempre estar organizada 


      tree
      ----
       5    <-- root
     /   \
    3      8  
  /   \   /  \
 1    4  7    9
 				\
 				10
 				 \
 				 11	<-- leaves 	deu ruim


Por que deu ruim?
	-Na verdade a arvore ficou "desbalanceada"
	-Como sabemos, entao qual é esse "balanceamento"?
	-A diferenca de altura dos descendentes de um no tem que ser, no maximo
		-0- quando nao ha filhos ou a altura dos filhos é a mesma
		-1- quando ha no maximo 1 nivel a mais na sub-arvore direita
		-1- quando ha no maximo 1 nivel a mais na sub-arvore esquerda



-E como deixar esse balanceamento correto a cada insercao/remoceo?

-2 passos
	-Calcular o fator de balanceamento de cada no
	-Se o fator de balanceamento superar 1 ou -1, ai aplicar as devidas 
	rotacoes para poder inserir/remover correramente o novo no
	
-Sao operacoes simetricas
	-Rotacao Simples a esquerda/Rotacao simples a direira
	-Rotacoa Dupla a esquerda/Rotacao Dupla a Direita 

*/





/*
ARVORES AVL

Balanceamento é importante

Contudo, um balanceamento perfeito é algo computacionalmente caro

O bom é inimigo do otimo e vice-versa
O otimo é inimigo do bom

pq eu preciso do perfeito se eu posso ter o bom balanceamento? 

Algorimo de Adelson-Velshkii e landis(as arvores AVL)


AVL é uma arvore de busca binaria balanceada com relacao a altura de suas subarvores

Uma arvore AVL verifica a altura das subarvores da esquerda e da direita, gerantindo que essa diferenca n seja maior que mais ou menos  1 (n pode passar de 1)

Esta diferenca é seu fator de balanceamento 

altura = comprimeito do maior caminho ate um NO folha.

o fator de balanceamento é calculado a cada no


a altura de uma arvore vazia é -1




balanceado = no maximo 1 a diferença entre o altura da subarvore da esqueda com a direita 



apos a insecao, voltamos ate a raiz, no por no atualizando as alturas
se um novo fator de balanceamento para um determinado no for 2 ou -2 ajustamos a arvore 
rotacionado em torno desse no 


existem dois tipos de rotacao:
	-rotacao a esquerda
	-gira para esquerda 


      ----
       x  			->    y
        \ 				 /	
         y  			x	


	-rotacao a direita
	-gira para direita

      ----
       y  			->    x
      /   				 	\	
      x     				 y	





insecoes na parte mais externa da arvore sao resolvidas com rotacao simples

na subarvore esquerda do filho esquerdo do no desbalanceado




E quando a insecao é na parte mais interna?
Na subarvore direita do filho esquerdo do no desbalanceado




enquanto insercoes na parte mais externa da arvore sao resolvidas com rotacao simples
insercoes na parte mais interna da arvore sao resolvidas com rotacao duplas




fazemos uma rotacao a ESQUERDA se um NO foi inserido na subarvore direita do filho a direita 

A
 \
  B 		->		B
   \			   / \	
	C 			  A	  C





fazemos uma rotacao a DIREITA se um NO foi inserido na subarvore ESQUERDA do filho a ESQUERDA


	  A
 	 /
	B 			->       B
   /				    /  \
  C                    C    A



fazemos uma rotacao esquerda-direta se um no foi inserido na subarvore direita do filho a esquerda


		A 	  ->    A  	->				C
	   /           /				   / \
	  B            C                  B   A
	  \  		  /
	   C         B



fazemos uma rotacao direita-esquerda se um NO foi inserido na sub-arvore esquerda do filho a direita


	A 			-> 			A			->			C
	 \						 \					   / \
	 B 					     C 					   A  B
	/ 						 \
   C 						 B


*/




/*

ArvoreAVL.h: definir:
	-os prototipos das funcoes
	-o tipo de dado armazenado na arvore
	-o ponteiro arvore

ArvoreAVL.c definir:
	-o tipo de dado arvore
	-implementar as suas funcoes 

*com execao da insecao e da remocao as demais funcoes da arvore AVL sao 
identicas a da arvore binaria

*/



//arquivo arvoreAVL.h
typedef struct  NO* ArvAVL;



//arquivo arvoreAVL.c

#include <stdio.h>
#include <stdlib.h>
#include "ArvoreAVL.h"

struct NO{
	int info;
	int alt; //altura daquela sub-arvore
	struct NO *esq;
	struct NO *dir;
};



//funcoes auxiliares 

//calcula a altura de um no 
int alt_NO(struct NO* no){
	if(no == NULL)
		return -1;
	else
		return no->alt;
}


//calcula o fator de balancemento de um no
//escolher o tipo de balanceamento
int fatorBalancemanto_NO(struct NO* no){
	return labs(alt_NO(no->esq) - alt_NO(no->dir));
}



//calcula o maior valor
int maior(int x,int y){
	if(x > y)
		return x;
	else 
		return y;
}




/*
Rotacao 

-considerando q o NO c foi inserido como filho do no b, e que b é filho do no a 


se o fator de balanceamento for:
	-A = +2 e B = +1: rotacao LL
	-A = -2 e B = -1: rotacao RR
	-A = +2 e B = -1: rotacao LR
	-A = -2 e B = +1: rotacao RL

As rotacoes LL e RR sao simetricas entre si 
assim como LR RL 
(sinais iguais ou diferentes)	


Implementando as rotacoes 
	-as rotacoes sao aplicadas no ancestral 
	mais proximo do NO inserdo cujo fator de balancemento passa a ser +2 ou -2
    -esse é o parametro das funcoes implementadas

    -as rotacoes simples (LL e RR) atualizam as novas alturas das sub-arvore

    -as rotacoes duplas (LR e RL) podem ser implementadas com 2 rotacoes simples	

*/




void rotacaoLL (ArvoreAVL *raiz){
	struct NO no;
	no = (*raiz)->esq;
	(*raiz)->esq = no->dir;
	no->dir = *raiz;
	(*raiz)->altura = maior(alt_NO(*raiz)->esq),
					  altura_NO((*raiz)->dir) +1;
    no->altura = maior(alt_NO(no->esq),(*raiz)->altura) +1;

    *raiz = no;

}











  /*****************************************************************************************************************
  *                                                   REFERENCIAS      	                                           *
  *https://www.youtube.com/watch?v=RDtJ6CCU6ZU&list=PLjcmNukBom6_nyEVge9stJLdq-bAeDoWx&index=15  				   *
  ******************************************************************************************************************/