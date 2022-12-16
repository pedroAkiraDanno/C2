
 /**********************************************
  * OBJETIVO  : BINARY SEARCH		           *
  * CRIACAO   : 20-01-2020	                   *
  * VERSAO    : 1.0		                       *
  * AUTOR     : Pedro Akira Danno Lima         *
  **********************************************/




    /*
        É necessário que os elemtos estejam ordenados.
        Realiza sucessivas divisões do espaço de busca comparando o elemento buscado(chave) 
        com o elemento do meio do vetor.
    
        Melhor caso -> O(1)
        Caso médio  -> O(log(n))
        Pior caso   -> O(log(n))
    
    */












#include<stdio.h>
#include<stdlib.h>
#define VETORSIZE 100


/*Prototipos da funcoes*/
int binsrch(int* vet, int n);




/*main*/
int main(){
	int i;

	int vet[]={3,5,7,9,13};


	i = binsrch(vet,3);
	printf("index: %d \n", i);



	return 0;
}













/*funcao*/
int binsrch(int size, int* vet, int n){
	int size = sizeof(vet)/sizeof(int);

	int inicio=0;
	int fim = size -1;
	int meio;


	while(inicio <= fim){
		meio = (inicio + fim)/2;

		if(n < vet[meio]){
			fim = meio -1;
		}else if(n > vet[meio]){
			inicio= meio +1;
		}else return meio;
	} 
		return -1;


}
















  /*****************************************************************************************************************
  *                                                   REFERENCIAS      	                                           *
  *estrutura de dados tenenbaum	(em C)																			   *
  ******************************************************************************************************************/