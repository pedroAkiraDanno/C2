  /***************************************************************
  * OBJETIVO  : ESTRUTURA-DE-DADOS-dynamic_list_circular.c       *
  * CRIACAO   : 03-01-2020	                    				         *
  * VERSAO    : 1.0		                        				           *
  * AUTOR     : Pedro Akira Danno Lima          				         * 
  ***************************************************************/





/*
Lista Dinamica Circular encadeada/ligada

-Algumas aplicacoes necessitam representar conjuntos ciclicos

-Numa Lista Circular, o ultimo elemento tem como proximo o primeiro elemento da lista,
formando um ciclo.

-Para percorrer os elementos de uma lista circular,
visitamos todos os elemntos a partir do ponteiro do eleento inicla ate alcancarmos novemanete esse mesmo elemento.


*/



#include <stdio.h>
#include <string.h>
#include <stdlib.h>



//LISTA CIRCULAR 

//define a estrutura do nodo
typedef struct TipoNo
{
	int info;
	struct TipoNo *prox;
}TNo;




//cria o inicio da Lista
typedef struct TipoLista
{
	TNo *inicio;
	TNo *fim;
};















  /*****************************************************************************************************************
  *                                                   REFERENCIAS      	                                           *
  *https://www.youtube.com/watch?v=ReCVBVY5pzo								                		   		                           *
  ******************************************************************************************************************/