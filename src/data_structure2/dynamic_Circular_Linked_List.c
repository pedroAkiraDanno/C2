  /***************************************************************
  * OBJETIVO  : ESTRUTURA-DE-DADOS-dynamic_list_circular.c       *
  * CRIACAO   : 03-01-2020	                    				 *
  * VERSAO    : 1.0		                        				 *
  * AUTOR     : Pedro Akira Danno Lima          				 *
  ***************************************************************/





/*
Lista Dinamica Circular encadeada/ligada

-Tipo de lista onde cada elemento aponta para o seu sucessor e 
o ultimo elemento aponta para o primeiro da lista

-usa um ponteiro especial para o primeiro elemento da lista

-nao existe um indicacao de final de lista 

-Cada elemento é tratado como um ponteiro que é alocado dinamicamente, 
a medida que os dados sao inseridos.

-Para guardar o primeiro elemento, utilizamos um "ponteiro para poneiro"

-Assim, fica facil mudar quem esta no inicio da lista mudando o "conceudo"
do "Ponteiro para ponteiro"


Vantagens:
	-Melhor utilização dos recursos de memroia
	-Nao precisa movimentar os elementos nas operacoes de insercao e remocao 
	-Possibilidade de percorrer a lista diversas vezes
	-Nao precisamos considerar casos especiais de inclusao e remocao de elementos (primeiro e ultimo)


Desvantagens:
	-Acesso indireto aos elementos
	-Necessidade de percorrer a lista para acesar um elemnto
	-Lista nao possui final definido 


Quando utlizar essa lista?
	-Nao ha necessidade de garantir um espaco minimo p/ a execucao
	-Insercao/remocao em lista ordenada sao as operacoes mais frequente
	-Quando a necessidade de voltar ao primeiro item da lista depois de percorre-la




Implementando uma "Lista Dinamica Circular"
	
ListaDinEncadCirc.h: definir
	-os prototipos das funcoes
	-o tipo de dados armazenado na lista
	-o ponteiro lista


ListaDinEncadCirc.c: definir
	-o tipo de dados lista
	-implementar as suas funcoes





*/




//Arquivo ListaDinEncadCirc.h


struct aluno
{
	int matricula;
	char nome[30];
	float n1,n2,n3;
};
typedef struct elemento* Lista;


Lista* criar_lista();



//arquivo listaDinEncadCirc.c
struct elemento
{
	struct aluno dados;
	struct elemento *prox;
};
typedef struct elemento Elem;



Lista



//programa principal

Lista *li; //ponteiro /p ponteiro












  /*****************************************************************************************************************
  *                                                   REFERENCIAS      	                                           *
  *https://www.youtube.com/watch?v=Tvk8FxOSD_k									                		   		   *
  ******************************************************************************************************************/