#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <libvalidacao.h> 
#define TAM 2
//ESTRUTURA CADASTRO
typedef struct cad {
  char nome[25],sobrenome[50];
  int idade,CPF,RG,dias,NQuartos,QPessoas;
}Cadastro;

//VETOR~/BANCO DE DADOS CLIENTE 1
Cadastro Cli[TAM];

int i = 0;
int Ncli = 0;


void cadastro () {

  printf("Programa hotel!!\n");
  printf("Nome:");
  scanf("%s",Cli[Ncli].nome);
  system("clear");

  printf("Programa hotel!!\n");
  printf("Sobrenome:");
  scanf("%s",Cli[Ncli].sobrenome);
  system("clear");

  printf("Programa hotel!!\n");
  printf("Idade:");
  scanf("%d",&Cli[Ncli].idade);
  system("clear");

  printf("Programa hotel!!\n");
  printf("Digite o número do CPF sem pontos, espaços ou traços:");
  scanf("%d",&Cli[Ncli].CPF);
  system("clear");

  printf("Programa hotel!!\n");
  printf("Digite o número do RG sem pontos, espaços ou traços:");
  scanf("%d",&Cli[Ncli].RG);
  system("clear");

  printf("Programa hotel!!\n");
  printf("dias:");
  scanf("%d",&Cli[Ncli].dias);
  system("clear");

  printf("Programa hotel!!\n");
  printf("Numeros de quartos:");
  scanf("%d",&Cli[Ncli].NQuartos);
  system("clear");

  printf("Programa hotel!!\n");
  printf("Quantidade de Pessoas:");
  scanf("%d",&Cli[Ncli].QPessoas);
  system("clear");
  Ncli++;
  main ();
}

void Dados () {
  int op;

  for (i = 0;i < Ncli;i++){
    printf("\n");
    printf("---------------------------------------\n");
    printf("Codigo: %d\n", i+1);
    printf("Nome:%s\n",Cli[i].nome);
    printf("Sobrenome:%s\n",Cli[i].sobrenome);
    printf("Idade:%d\n",Cli[i].idade);
    printf("CPF:%d\n",Cli[i].CPF);
    printf("RG:%d\n",Cli[i].RG);
    printf("Dias:%d\n",Cli[i].dias);
    printf("Numero de Quartos:%d\n",Cli[i].NQuartos);
    printf("Quantidade de Pessoas:%d\n",Cli[i].QPessoas);
    printf("---------------------------------------\n");
    printf("\n");
  }

  do{
  printf("Digite 1 para voltar ao menu!\n");
  printf(":");
  scanf("%d",&op);
  system("clear");
  }while (op != 1);
  if (op == 1){
    main();
  }
}

void Editar () {
  int cliente,op2;
  printf("Digite o Numero de indetificacao do clitente cadastrado!!\n");
  printf(":");
  scanf("%d",&cliente);
  system("clear");

  printf("Selecione o dado que ddeseja alterar!!\n");
  printf("1- Nome\n");
  printf("2- Sobrenome\n");
  printf("3- idade\n");
  printf("4- CPF\n");
  printf("5- RG\n");
  printf("6- dias\n");
  printf("7- Numero de quartos\n");
  printf("8- Numeros de pessoas\n");

  printf(":");
  scanf("%d",&op2);
  system("clear");

  switch (op2) {
    case 1:
      printf("Nome:");
      scanf("%s",Cli[cliente-1].nome);
      system("clear");
    break;
    case 2:
      printf("Sobrenome:");
      scanf("%s",Cli[cliente-1].sobrenome);
      system("clear");
    break;
    case 3:
      printf("idade:");
      scanf("%d",&Cli[cliente-1].idade);
      system("clear");
    break;
    case 4:
      printf("Digite o número do CPF sem pontos, espaços ou traços:");
      scanf("%d",&Cli[cliente-1].CPF);
      system("clear");
    break;
    case 5:
      printf("Digite o número do RG sem pontos, espaços ou traços:");
      scanf("%d",&Cli[cliente-1].RG);
      system("clear");
    break;
    case 6:
      printf("dias:");
      scanf("%d",&Cli[cliente-1].dias);
      system("clear");
    break;
    case 7:
      printf("Numero de quartos:");
      scanf("%d",&Cli[cliente-1].NQuartos);
      system("clear");
    break;
    case 8:
      printf("Quantidade de pessoas:");
      scanf("%d",&Cli[cliente-1].QPessoas);
      system("clear");
    break;

    default:
      Editar ();
  }
  main ();
}

void Excluir () {
  int cliente,op2;
  printf("Digite o Numero de indetificacao do clitente cadastrado!!\n");
  printf(":");
  scanf("%d",&cliente);
  system("clear");

  printf("Selecione o dado que ddeseja excluir!!\n");
  printf("1- Nome\n");
  printf("2- Sobrenome\n");
  printf("3- idade\n");
  printf("4- CPF\n");
  printf("5- RG\n");
  printf("6- dias\n");
  printf("7- Numero de quartos\n");
  printf("8- Numeros de pessoas\n");

  printf(":");
  scanf("%d",&op2);
  system("clear");

  switch (op2) {
    case 1:
      printf("Nome removido!!");
      strcpy(Cli[cliente-1].nome, "Sem dado");
      system("clear");
    break;
    case 2:
      printf("Sobrenome removido!!");
      strcpy(Cli[cliente-1].sobrenome, "Sem dado");
      system("clear");
    break;
    case 3:
      printf("idade removido!!");
      Cli[cliente-1].idade = 0;
      system("clear");
    break;
    case 4:
      printf("CPF removido!!");
      Cli[cliente-1].CPF = 0;
      system("clear");
    break;
    case 5:
      printf("RG removido!!");
      Cli[cliente-1].RG = 0;
      system("clear");
    break;
    case 6:
      printf("dias removido!!");
      Cli[cliente-1].dias = 0;
      system("clear");
    break;
    case 7:
      printf("Numero de quartos removido!!");
      Cli[cliente-1].NQuartos = 0;
      system("clear");
    break;
    case 8:
      printf("Quantidade de pessoas removido!!");
      Cli[cliente-1].QPessoas = 0;
      system("clear");
    break;

    default:
      Excluir ();
  }
  main ();
}

int menu () {
  int op;
  printf("Programa hotel!!\n");
  printf("1- Cadastro!\n");
  printf("2- Conferir dados dos clientes cadastrados!\n");
  printf("3- Editar cadastro!\n");
  printf("4- Excluir dado de um cadastro!\n");
  printf("0- Sair!\n");
  printf(":");
  scanf("%d",&op);
  system("clear");
  return op;
}

int main() {
  int op;

  op = menu ();

  switch (op) {
    case 0:
    break;
    case 1:
      if (Ncli == TAM) {
          printf("\nBanco de dados sem espaco!!\n");
          break;
      }
      cadastro ();
      break;
    break;
    case 2:
      Dados ();
    break;
    case 3:
      Editar ();
    break;
    case 4:
      Excluir ();
    break;
    default:
        printf("||||| OPCAO INVALIDA |||||\n\n");
        main ();
  }


  return 0;
}