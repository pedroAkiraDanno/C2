



#include <stdio.h>













int main (){


	/*definição da struct, por isso em ate o ;, nome e quais sao os componentes dele*/
struct ficha_aluno
{

	char nome[40];
	int numero;
	float nota; 	
	
}; /*definicao da struct - isso criar um tipo*/ 




	struct ficha_aluno aluno;

	printf("informe seu nome: \n" );
	fgets(aluno.nome, 40, stdin);

    printf("informe seu num: \n");
	scanf("%d", &aluno.numero);

    printf("informe sua nota: \n" );
	scanf("%f", &aluno.nota);







	return(0);
}