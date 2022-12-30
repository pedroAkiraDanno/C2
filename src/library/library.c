#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

typedef struct {
        int matricula;
        char nome[60];
        char curso[50];
        int emprestimos;
} aluno;
        

typedef struct {
        char isbn[17];
        char titulo[120];
        char autores[180];
        char editora[30];
        int exemplares;
        int disponiveis;
} livro;


typedef struct {
        int dia;
        int mes;
        int ano;
} data;


typedef struct {
        char isbn[18];
        int matricula;
        data emprestimo;
        data prevista;   // data prevista para a devolução do livro
        data devolucao;  // data efetiva da devolução
} emprestimo;


typedef struct{
        data dte;
        data dtp;
} aux;
 
void CadastroAluno();
void CadastroLivro();
void Emprestimos();
void Devolucao();
void ConsultaAluno();
void ConsultaAcervo();
void learquivo();
data dataAtual();

     
   int main (){
       
       int opcao;
       
       do{
       printf("\n\n\n");
       printf("\n\t\t\t     Sistema de biblioteca\n\n");
       printf("\n\t\t     ( 1 ) Cadastrar Alunos\n");
       printf("\t\t     ( 2 ) Cadastrar Livros\n");
       printf("\t\t     ( 3 ) Emprestimos de Livros\n");
       printf("\t\t     ( 4 ) Devolucao de Livros\n");
       printf("\t\t     ( 5 ) Consultar alunos cadastrados\n");
       printf("\t\t     ( 6 ) Consultar livros cadastrados\n");
       printf("\t\t     ( 0 ) Sair do programa\n");
       printf("\nOpcao Desejada: ");
       scanf("%d", &opcao);
       
       switch ( opcao ){
              case 1:
                   CadastroAluno();
                   break;
              case 2:
                   CadastroLivro();
                   break;
              case 3:
                   Emprestimos();
                   break;
              case 4:
                   Devolucao();
                   break;
              case 5:
                   ConsultaAluno();
                   break;
              case 6:
                   ConsultaAcervo();
                   break;
              case 7:
                   learquivo();
                   break;
              case 0:
                   break;
              default:
                   printf("\n\t\t\tOpcao invalida !\n\n");
                   }
       }while( opcao != 0 );
              
       system("pause");
       return 0;
       
       }
       
       
  
 /******************************************* Função Cadastra alunos ****************************************/
  
       
   void CadastroAluno(){
        FILE * fp;
        aluno DadosAluno;
        int auxmatricula;
        char CadAluno;
        DadosAluno.emprestimos = 0;
        
        printf("\n\t\t\tCampo: Cadastro de alunos.\n\n");
        
        if(( fp = fopen("alunos.dat", "ab")) == NULL ){
             printf("\nErro de abertura do arquivo alunos.dat!");
             return;
             }
 
            
        fseek(fp,0,SEEK_END);
        auxmatricula = ftell(fp) / sizeof(aluno);
        
        do{
        DadosAluno.emprestimos = 0;
        DadosAluno.matricula = ++auxmatricula;
        printf("\nMatricula...: %08d\n", DadosAluno.matricula);
        printf("Nome........: ");
        scanf(" %59[^\n]", DadosAluno.nome);
        printf("Curso.......: ");
        scanf(" %49[^\n]", DadosAluno.curso);
        printf("Emprestimos.: %d\n", DadosAluno.emprestimos);
        fwrite(&DadosAluno,sizeof(aluno),1,fp);
        do{
        printf("\nCadastrar outro aluno ( S / N ): ");
        scanf(" %c", &CadAluno);
        CadAluno = toupper(CadAluno);
        }while( CadAluno != 'S' && CadAluno != 'N');
        }while( CadAluno == 'S' );
        fclose(fp);
        
        system("cls");
   }
        
    
    
    
 /********************************************* Função Cadastra Livros ****************************************/
 
 
    
     
   void CadastroLivro(){
        FILE * fp;
        livro DadosLivro;
        char Cadlivro;
        
        if(( fp = fopen ("livros.dat", "ab")) == NULL ){
             printf("\nErro na abertura do arquivo livros.dat !\n\n");
             return;
             }
                    
        printf("\n\t\t\t     Campo: Cadastrar Livros\n\n");
        
        do{
        printf("\nISBN..................: ");
        scanf(" %16[^\n]", DadosLivro.isbn);
        printf("Titulo................: ");
        scanf(" %129[^\n]", DadosLivro.titulo);
        printf("Autores...............: ");
        scanf(" %179[^\n]", DadosLivro.autores);
        printf("Editora...............: ");
        scanf(" %29[^\n]", DadosLivro.editora);
        printf("Numero de Exemplares..: ");
        scanf("%d", &DadosLivro.exemplares);
        DadosLivro.disponiveis = DadosLivro.exemplares;
        printf("Exemplares disponiveis: %d\n", DadosLivro.disponiveis);
        fwrite(&DadosLivro,sizeof(livro),1,fp);
        
        do{
        printf("\nDeseja Cadastrar outro livro ( S / N ): ");
        scanf(" %c", &Cadlivro);
        Cadlivro = toupper(Cadlivro);
        }while( Cadlivro != 'S' && Cadlivro != 'N' );
        
       }while( Cadlivro == 'S' );
       fclose(fp);
       system("cls");
   }
   
  
  
  /********************************************** Função Emprestimo*********************************************/
  
  void Emprestimos(){
       FILE * fp, * fpa, * fpl, * fpr;
       emprestimo DadosEmprestimo;
       emprestimo auxisbn;
       emprestimo guard_valor;
       aluno DadosAluno;
       livro DadosLivro;
       aux Dataaux;
       data Controle;
       int cont=1, AuxEmp=0, Auxdia, Auxmes, Auxano, auxmatricula=0, contseq=0;
       char op, auxis[17], auxisb[17];   
              
       if(( fp = fopen ("emprestimos.dat", "ab")) == NULL ){
            printf("\n\nErro na abertura do arquivo emprestimos.dat !\n\n");
            return;
            }
            
            
       if(( fpl = fopen ("livros.dat", "r+b")) == NULL ){
           printf("\nErro na leitura do arquivo livros.dat");
           return;
           }
           
       if(( fpa = fopen ("alunos.dat", "r+b")) == NULL ){
           printf("\nErro na leitura do arquivo alunos.dat !\n\n");
           return;
           }
           
       if(( fpr = fopen ("emprestimos.dat", "rb")) == NULL ){
           printf("\n\nErro na abertura do arquivo emprestimos.dat !\n\n");
           return;
           }
           
  
                              
       printf("\n\n\n\t\t\tCampo: Emprestimos de livros\n\n");
          
       printf("\nIsbn..................: ");
       scanf(" %16[^\n]", auxisbn.isbn);
       strcpy(auxisb,auxis);
       
       /*Verifica se o isbn é válido e exibe as informações*/
                      
       while(1){
       fread(&DadosLivro,sizeof(livro),1,fpl);
       if(feof(fpl)){
       printf("\nNao ha livro com o este ISBN no acervo da biblioteca !\n\n");  
       return;
       }
       if(strcasecmp (auxisbn.isbn,DadosLivro.isbn) == 0 ){
       printf("Titulo................: %s\n", DadosLivro.titulo);
       printf("Total de exemplares...: %d\n", DadosLivro.exemplares); 
       printf("Exemplares disponiveis: %d\n", DadosLivro.disponiveis);
       guard_valor = auxisbn;
       break;
       }
    }
       printf("\nMatricula.............: ");
       scanf("%d", &DadosEmprestimo.matricula);
       auxmatricula = DadosEmprestimo.matricula; 
       
       /*Verifica se a matricula é válida e exibe as informações*/
       
       while(1){
       fread(&DadosAluno,sizeof(aluno),1,fpa);
       if(feof(fpa)){
       printf("\nA matricula %d nao esta cadastrada !\n\n", DadosEmprestimo.matricula);
       return;
       }
       if(DadosEmprestimo.matricula == DadosAluno.matricula){
       printf("Matricula.............: %d\n", DadosAluno.matricula);
       printf("Nome..................: %s\n", DadosAluno.nome);
       printf("Livros Emprestados....: %d\n", DadosAluno.emprestimos);
       break;
       }
    }       
    
 
        Dataaux.dte = dataAtual(Controle);
        Dataaux.dte.mes += 1;
        

       if(DadosAluno.emprestimos < 3){ // Verifica se o aluno possui mais de três emprestimos
        
       /*Verifica se o aluno possui pendências de entrega*/
        
       fseek(fpr,0,SEEK_CUR);
       while(1){
       fread(&DadosEmprestimo,sizeof(emprestimo),1,fpr);
       if(feof(fpr)){
       break;
       }
       
       
       if(DadosEmprestimo.matricula == auxmatricula){
       if(DadosEmprestimo.prevista.ano <= Dataaux.dte.ano){
       if(DadosEmprestimo.prevista.mes <= Dataaux.dte.mes){
       if(DadosEmprestimo.prevista.dia <= Dataaux.dte.dia && DadosEmprestimo.devolucao.dia == 0){
       printf("\n\t\t\tEntrega pendente\n\n");
       return;
       }
      }
     }
     
     if(DadosEmprestimo.prevista.mes < Dataaux.dte.mes && DadosEmprestimo.devolucao.mes == 00){
     printf("\n\t\t\tEntrega pendente\n\n");
     return;
     }

     if(DadosEmprestimo.prevista.ano < Dataaux.dte.ano && DadosEmprestimo.devolucao.ano == 0000){
     printf("\n\t\t\tEntrega pendente\n\n");
     return;
    }
   }
  }

      
        /*Tratamento das datas*/
      
        Dataaux.dtp = dataAtual(Controle);
        Dataaux.dtp.dia += 10;
        Dataaux.dtp.mes += 1;
        
        while( cont <= 12 ){
        if(Dataaux.dtp.mes <= 7 ){
        if(cont == 2 && Dataaux.dtp.dia > 28 && Dataaux.dtp.mes == 2){
         Dataaux.dtp.dia -= 28; Dataaux.dtp.mes += 1;break;
         }
         else{
              if(cont % 2 == 1 && Dataaux.dtp.dia > 31 && Dataaux.dtp.mes == cont){
              Dataaux.dtp.dia -= 31; Dataaux.dtp.mes += 1;break;
              }
         else{
              if(cont % 2 == 0 && Dataaux.dtp.dia > 30 && Dataaux.dtp.mes == cont){
              Dataaux.dtp.dia -= 30; Dataaux.dtp.mes += 1;break;
              } } } }
         else{
              if(Dataaux.dtp.dia > 31 && Dataaux.dte.mes == 12){ 
              Dataaux.dtp.dia -= 31; Dataaux.dtp.ano += 1;
              Dataaux.dtp.mes = 1;break;
              }
         else{
              if(cont % 2 == 0 && Dataaux.dtp.dia > 31 && Dataaux.dtp.mes == cont){
              Dataaux.dtp.dia -= 31; Dataaux.dtp.mes += 1;break;
              }
         else{
              if(cont % 2 == 1 && Dataaux.dtp.dia > 30 && Dataaux.dtp.mes == cont){
              Dataaux.dtp.dia -= 30; Dataaux.dtp.mes += 1;break;
              } } } }
           
     cont++;
  }
  
        if(DadosLivro.disponiveis >= 1){ //Verifica se Há livros disponíveis
        
        /*Efetua a escrita no arquivo emprestimos.dat*/
        
        while(1){
        DadosEmprestimo = auxisbn;
        printf("\nIsbn........................: %s\n", DadosEmprestimo.isbn);
        
        DadosEmprestimo.devolucao.dia = DadosEmprestimo.devolucao.mes = DadosEmprestimo.devolucao.ano = 0;
        DadosEmprestimo.emprestimo.dia = Dataaux.dte.dia; DadosEmprestimo.emprestimo.mes = Dataaux.dte.mes;
        DadosEmprestimo.emprestimo.ano = Dataaux.dte.ano;
        DadosEmprestimo.prevista.dia = Dataaux.dtp.dia; DadosEmprestimo.prevista.mes = Dataaux.dtp.mes;
        DadosEmprestimo.prevista.ano = Dataaux.dtp.ano;
         
        DadosEmprestimo.matricula = auxmatricula;
               
        printf("Matricula...................: %08d\n", DadosEmprestimo.matricula);
        printf("Data do emprestimo..........: ");
        printf("%02d %02d %d\n", DadosEmprestimo.emprestimo.dia, DadosEmprestimo.emprestimo.mes, DadosEmprestimo.emprestimo.ano);
        printf("Data prevista para devolucao: ");
        printf("%02d %02d %d\n", DadosEmprestimo.prevista.dia, DadosEmprestimo.prevista.mes, DadosEmprestimo.prevista.ano);
        printf("Data da efetiva devolucao...: ");
        printf("%02d %02d %04d\n\n", DadosEmprestimo.devolucao.dia, DadosEmprestimo.devolucao.mes, DadosEmprestimo.devolucao.ano);
        fwrite(&DadosEmprestimo,sizeof(emprestimo),1,fp);
        break;
        }
      
  
        rewind(fpa);
        while(1){
        fread(&DadosAluno,sizeof(aluno),1,fpa);
        if(feof(fpa)){
        printf("\nError");
        break;
        }
        if(DadosAluno.matricula == DadosEmprestimo.matricula){
        DadosAluno.emprestimos += 1;
        fseek(fpa, -sizeof(aluno),SEEK_CUR);
        fwrite(&DadosAluno,sizeof(aluno),1,fpa);
        printf("\t\t\tTotal Emprestimos Aluno.: %d\n", DadosAluno.emprestimos);
        break;
        }
     }
        rewind(fpl);
        while(1){
        fread(&DadosLivro,sizeof(livro),1,fpl);
        if(feof(fpl)){
        printf("\nError");
        break;
        }
        if(strcasecmp (DadosEmprestimo.isbn,DadosLivro.isbn) == 0){
        DadosLivro.disponiveis -= 1;
        fseek(fpl, -sizeof(livro),SEEK_CUR);
        fwrite(&DadosLivro,sizeof(livro),1,fpl);
        printf("\t\t\tTotal Livros Disponiveis: %d\n", DadosLivro.disponiveis);
        break;
        }
     }
 }

 
      
 else{
      printf("\n\n\t\t\tNao ha livros disponiveis\n");
      
      /*Calcula e devolve a data da entrega mais próxima*/ 
      
        rewind(fpr);
        while(1){
        fread(&DadosEmprestimo,sizeof(emprestimo),1,fpr);
        if(feof(fpr)){
        fclose(fpr);
        break;
        }
        if(strcasecmp (guard_valor.isbn,DadosEmprestimo.isbn) == 0){
        if(contseq == 0){
        Auxano = DadosEmprestimo.prevista.ano;
        Auxmes = DadosEmprestimo.prevista.mes;
        Auxdia = DadosEmprestimo.prevista.dia;
        }
        if( DadosEmprestimo.devolucao.dia == 00 ){
        if(Auxano >= DadosEmprestimo.prevista.ano){
                  if(Auxmes >= DadosEmprestimo.prevista.mes){
                            if(Auxdia >= DadosEmprestimo.prevista.dia){
                            Auxano = DadosEmprestimo.prevista.ano;
                            Auxmes = DadosEmprestimo.prevista.mes;
                            Auxdia <= DadosEmprestimo.prevista.dia;
                            }
                         }
                      }
                   }
                                    
        
        }
        cont++;
     }
     
     printf("\n\n\t\tData da entrega mais proxima: %02d %02d %d\n", Auxdia, Auxmes, Auxano);
      
     }
 }
      
      else{
      printf("\n\t\t\tCota de livros atingida\n\n");
      return;
      }
           
  
    fclose(fp);  
    fclose(fpl);
    fclose(fpa);
    
      
}
       
       
       
/****************************************** Função Consulta Alunos ********************************************/       
       
       
       
       
  void ConsultaAluno(){
      FILE * fp, * fpe, * fpl;
      emprestimo DadosEmprestimo;
      livro DadosLivro;
      aluno DadosAluno;
      aluno auxaluno;
      char Nome[60], continuar, opcao1;
      int Matricula, cont, cont_controle=0;
      
      if(( fp = fopen ("alunos.dat", "r+b")) == NULL ){
        printf("Erro na leitura do arquivo alunos.dat !\n\n");
        return;
      }
      
      if(( fpe = fopen ("emprestimos.dat", "rb")) == NULL){
           printf("\nErro na leitura do arquivo emprestimos.dat\n\n");
           return;
           }
           
      if(( fpl = fopen ("livros.dat", "rb")) == NULL){
           printf("\nErro na leitura do arquivo livros.dat\n\n");
           return;
           }
      
     
      fseek(fp,0,SEEK_SET);
      cont=0;
      printf("\n\n\t\t\tCampo: Buscar alunos\n");
      printf("\n\n\t\t\t  Formas de busca:\n");
      printf("\n\t\t\t ( M ) - Matricula\n");
      printf("\t\t\t ( N ) - Nome\n");
      printf("\n\nOpcao Desejada: ");
      scanf(" %c", &continuar);
      continuar = toupper(continuar);
      
      switch ( continuar ){
            case 'M':
             rewind(fp);
             printf("\nMatricula: ");
             scanf("%d", &Matricula);
             while(1){
             fread(&DadosAluno,sizeof(aluno),1,fp);
             if(feof(fp)){
             printf("\n\n\t\tNao ha aluno cadastrado com a matricula: %08d\n\n", Matricula);
             return;
             }
             if( Matricula == DadosAluno.matricula){
             printf("\n\nMatricula....: %d\n", DadosAluno.matricula);
             printf("Nome.........: %s\n", DadosAluno.nome);
             printf("Curso........: %s\n", DadosAluno.curso);
             printf("Total de emprestimos: %d\n", DadosAluno.emprestimos);
             cont++;
             break;
             }
          }break;
          
            case 'N':
             rewind(fp);
             printf("\n\nNome: ");
             scanf(" %59[^\n]", Nome);
             while(1){
             fread(&DadosAluno,sizeof(aluno),1,fp);
             if(feof(fp)){
             printf("\n\t\tRegistro nao encotrado. Nome: %s\n\n", Nome);
             return;
             }
             if( strcasecmp (Nome,DadosAluno.nome) == 0 ){
             auxaluno = DadosAluno;
             printf("\n\nMatricula...: %d\n", DadosAluno.matricula);
             printf("Nome.........: %s\n", DadosAluno.nome);
             printf("Curso........: %s\n\n", DadosAluno.curso);
             printf("Total de emprestimos: %d\n", DadosAluno.emprestimos);
             cont++;
             break;
             }
          }break;
          
            default:
                    printf("\n\n\t\t\tOpcao invalida !\n");
                    return;
                    }
                              
            if(cont >= 1){
            printf("\n\nLivros em posse do aluno:\n\n");
            rewind(fpe);
            rewind(fpl);
            while(1){
            fread(&DadosEmprestimo,sizeof(emprestimo),1,fpe);
            if(feof(fpe)){
            if(cont_controle == 0){
            printf("\n\t\t\tNao ha livros com o aluno\n\n");
            return;
            }
            break;
            }
            if( auxaluno.matricula == DadosEmprestimo.matricula || Matricula == DadosEmprestimo.matricula){
            if( DadosEmprestimo.devolucao.dia == 00){
            cont_controle++;
            while(1){
            fread(&DadosLivro,sizeof(livro),1,fpl);
            if(feof(fpl)){
            break;
            }
            if( strcasecmp (DadosEmprestimo.isbn,DadosLivro.isbn) == 0){
            printf("ISBN...: %s\n", DadosLivro.isbn);
            printf("Titulo.: %s\n", DadosLivro.titulo);
            printf("Autores: %s\n", DadosLivro.autores);
            fseek(fpl,0,SEEK_SET);
            break;
            }
          }
           printf("Data do emprestimo..........: ");
           printf("%02d %02d %d\n", DadosEmprestimo.emprestimo.dia, DadosEmprestimo.emprestimo.mes, DadosEmprestimo.emprestimo.ano);
           printf("Data prevista para devolucao: ");
           printf("%02d %02d %d\n\n", DadosEmprestimo.prevista.dia, DadosEmprestimo.prevista.mes, DadosEmprestimo.prevista.ano);
           }
          }
         }
        }
           
   
          fclose(fp);
          fclose(fpe);
          fclose(fpl);
          
          
      }
      
      
  
 /**********************************************Funçao Consulta Acervo*****************************************/
        
        
   
  void ConsultaAcervo(){
      FILE * fp;
      livro DadosLivro;
      char Isbn[17], Titulo[120], Autores[180];
      char opcao, continuar;
      
      if((fp = fopen("livros.dat","r+b")) == NULL){
        printf("Erro de leitura do arquivo livros.dat!\n\n");
        return;
      } 
     
     do{
     printf("\n\n\t\t\t    Campo: Buscar livros\n\n\n");
     printf("\t\t\tFormas de Busca dos livros:\n\n");
     printf("\t\t\t\t( I ) - Isbn\n");
     printf("\t\t\t\t( T ) - Titulo\n");
     printf("\t\t\t\t( A ) - Autor\n\n");
     printf("\nOpcao Desejada: ");
     scanf(" %c", &opcao);
     opcao = toupper(opcao);
      
     switch ( opcao ){
            
            case 'I':
             rewind(fp);
             printf("\nIsbn..........: ");
             scanf(" %16[^\n]",Isbn);
             while(1){
             fread(&DadosLivro,sizeof(livro),1,fp);
             if(feof(fp)){
    	     printf("\n\nNao ha livro com Isbn: %d no acervo da biblioteca !\n\n", Isbn);
    	     break;
             }
             if(strcasecmp (Isbn,DadosLivro.isbn) == 0){
             printf("\n\nIsbn............................: %s\n", DadosLivro.isbn);
    	     printf("Titulo..........................: %s\n", DadosLivro.titulo);
    	     printf("Autor(es).......................: %s\n", DadosLivro.autores);
    	     printf("Nuumero de exemplares no acervo.: %d\n", DadosLivro.exemplares);
    	     printf("Numero de exemplares disponíveis: %d\n", DadosLivro.disponiveis);
    	     break;
          }
        }break;
            
            case 'T':
             rewind(fp);
             printf("\nTítulo: ");
             scanf(" %119[^\n]",Titulo);
             while(1){
             fread(&DadosLivro,sizeof(livro),1,fp);
             if(feof(fp)){
    	     printf("Nao ha livro no acervo com o titulo: %s\n\n", Titulo );
       	     break;
             }
             if(strcasecmp (Titulo,DadosLivro.titulo) == 0){
       	     printf("\n\nIsbn............................: %s\n", DadosLivro.isbn);
       	     printf("Titulo..........................: %s\n", DadosLivro.titulo);
         	 printf("Autor(es).......................: %s\n", DadosLivro.autores);
   	         printf("Numero de exemplares do acervo..: %d\n", DadosLivro.exemplares);
   	         printf("Numero de exemplares disponiveis: %d\n", DadosLivro.disponiveis);
   	         break;
          }
        }break;
      
            case 'A':
            rewind(fp);
            printf("\nAutor...........: ");
            scanf(" %179[^\n]",Autores);
            while(1){
            fread(&DadosLivro,sizeof(livro),1,fp);
            if(feof(fp)){
    	    printf("Nao ha livro com do(s) autor(es) %s no acervo da biblioteca !\n\n");
    	    break;
            }
            if(strcasecmp (Autores,DadosLivro.autores) == 0){
     	    printf("\n\nIsbn..............................: %s\n", DadosLivro.isbn);
    	    printf("Título..........................: %s\n", DadosLivro.titulo);
    	    printf("Autor(es).......................: %s\n", DadosLivro.autores);
    	    printf("Numero de exemplares do acervo..: %d\n", DadosLivro.exemplares);
    	    printf("Numero de exemplares disponiveis: %d\n", DadosLivro.disponiveis);
    	    break;
          }
        }break;
        
        default:
                printf("\n\t\t\tOpcao invalida !\n\n");
      }
      
      printf("\nDeseja buscar outro livro ( S / N ): ");
      scanf(" %c", &continuar);
      continuar = toupper(continuar);
      
      }while( continuar == 'S');
            
      fclose(fp);
      system("cls");
    }
    
    
    
    
 /************************************************* Funcao Data ************************************************/
   
   
       
    data dataAtual() {
        struct tm * dataAtual;
        time_t hora;
        data dtAtual;
        hora = time(NULL);
        dataAtual = localtime(&hora);
        dtAtual.dia = dataAtual->tm_mday;
        dtAtual.mes = dataAtual->tm_mon;
        dtAtual.ano = dataAtual->tm_year+1900;
    return dtAtual;
    }
    
    
  
    
 /****************************************** Funcao Devolucao de livros ****************************************/
    
  
  
  void Devolucao(){
       FILE * fpe, * fpa, * fpl;
       emprestimo DadosEmprestimo;
       emprestimo auxisbn;
       livro DadosLivro;
       aluno DadosAluno;
       aux Dataaux;
       data Controle;
       int matricula, opcao, op, cont=0;
       
       if(( fpe = fopen ("emprestimos.dat", "r+b")) == NULL ){
            printf("\nErro na leitura do arquivo emprestimos.dat !\n\n");
            return;
            }
            
       if(( fpa = fopen ("alunos.dat", "r+b")) == NULL ){
            printf("\nErro na leitura do arquivo alunos.dat !\n\n");
            return;
            }
            
       if(( fpl = fopen ("livros.dat", "r+b")) == NULL ){
            printf("\nErro na leitura do arquivo livros.dat !\n\n");
            return;
            }
            
       printf("\n\nMatricula do aluno: ");
       scanf("%d", &matricula);
            
        
        /*Exibe os títulos dos livros que se encontram com o aluno*/
            
            rewind(fpa);
            rewind(fpe);
            rewind(fpl);
                  
            while(1){
            fread(&DadosAluno,sizeof(aluno),1,fpa);
            if(feof(fpa)){
            break;
            }
            if(matricula == DadosAluno.matricula){
            printf("\nNome: %s\n", DadosAluno.nome);
            fseek(fpe,0,SEEK_SET); 
            while(1){
            fread(&DadosEmprestimo,sizeof(emprestimo),1,fpe);
            if(feof(fpe)){
            break;
            }
            if(matricula == DadosEmprestimo.matricula){
            if(DadosEmprestimo.devolucao.dia == 00){
            
            while(1){
            fread(&DadosLivro,sizeof(livro),1,fpl);
            if(feof(fpl)){
            break;
            }
            if( strcasecmp (DadosEmprestimo.isbn,DadosLivro.isbn) == 0){
            cont++;
            printf("\n\n");
            printf("Titulo.: %s\n", DadosLivro.titulo);
            fseek(fpl,0,SEEK_SET);
            break;
            }
           }
          }
         }
        }
       }
      }      
       
       
       if( cont == 0 ){
       printf("\n\n\n\t\t\t     Nao ha livros pendentes\n\n");
       return;
       }
 
       
       printf("\n\n\t\t\t1 - Devolver um livro por vez\n\t\t\t2 - Devolver todos os livros\n\n");
       
       printf("Opcao desejada: ");
       scanf(" %d", &opcao);
       
       Dataaux.dte = dataAtual(Controle);
       Dataaux.dte.mes += 1;
       printf("\nData da devolucao: ");
       printf("%02d %02d %d\n", Dataaux.dte.dia, Dataaux.dte.mes, Dataaux.dte.ano);
       
       switch ( opcao ){
              case 1:
                   
                   do{
                   fseek(fpe,0,SEEK_SET);
                   fseek(fpl,0,SEEK_SET);
                   fseek(fpa,0,SEEK_SET);                  
                   printf("\nInforme o isbn do livro: ");
                   scanf(" %16[^\n]", auxisbn.isbn);
                   
                   do{
                   
                   fread(&DadosEmprestimo,sizeof(emprestimo),1,fpe);
                   if(feof(fpe)){
                   break;
                   }
                   if(strcasecmp(auxisbn.isbn,DadosEmprestimo.isbn) == 0){
                   if( DadosEmprestimo.matricula == matricula){
                   if(DadosEmprestimo.devolucao.dia == 00){
                   DadosEmprestimo.devolucao.dia = Dataaux.dte.dia;
                   DadosEmprestimo.devolucao.mes = Dataaux.dte.mes;
                   DadosEmprestimo.devolucao.ano = Dataaux.dte.ano;
                   fseek(fpe, -sizeof(emprestimo),SEEK_CUR);
                   fwrite(&DadosEmprestimo,sizeof(emprestimo),1,fpe);
                   break;
                   }
                 }
              
              }
              
           }while(!feof(fpe));
              
       
                    rewind(fpl); 
                    while(1){
                    fread(&DadosLivro,sizeof(livro),1,fpl);
                    if(feof(fpl)){
                    break;
                    }
                    if(strcasecmp(auxisbn.isbn,DadosLivro.isbn) == 0){
                    DadosLivro.disponiveis += 1;
                    fseek(fpl, -sizeof(livro),SEEK_CUR);
                    fwrite(&DadosLivro,sizeof(livro),1,fpl);
                    break;
                    }
                 }
                                      
                     rewind(fpa);
                     while(1){
                     fread(&DadosAluno,sizeof(aluno),1,fpa);
                     if(feof(fpa)){
                     break;
                     }
                     if(DadosAluno.matricula == matricula){
                     DadosAluno.emprestimos -= 1;
                     fseek(fpa, -sizeof(aluno),SEEK_CUR);
                     fwrite(&DadosAluno,sizeof(aluno),1,fpa);
                     printf("\n\n\t\t\t   Total de emprestimos: %d\n\n", DadosAluno.emprestimos);
                     break;
                     }
                   }

   
       printf("Deseja devolver outro livro ( S / N ): ");
       scanf(" %c", &op);
       op = toupper(op);
       }while( op == 'S');
       
       break;
       
              case 2:
                   rewind(fpe);
                   while(1){
                   fread(&DadosEmprestimo,sizeof(emprestimo),1,fpe);
                   if(feof(fpe)){
                   break;
                   }
                   if( DadosEmprestimo.matricula == matricula){
                   if(DadosEmprestimo.devolucao.dia == 00){
                   auxisbn = DadosEmprestimo;
                   DadosEmprestimo.devolucao.dia = Dataaux.dte.dia;
                   DadosEmprestimo.devolucao.mes = Dataaux.dte.mes;
                   DadosEmprestimo.devolucao.ano = Dataaux.dte.ano;
                   fseek(fpe, -sizeof(emprestimo),SEEK_CUR);
                   fwrite(&DadosEmprestimo,sizeof(emprestimo),1,fpe);
                   
                                       
                    rewind(fpl);
                    while(1){
                    fread(&DadosLivro,sizeof(livro),1,fpl);
                    if(feof(fpl)){
                    break;
                    }
                    if(strcasecmp (auxisbn.isbn,DadosLivro.isbn) == 0){
                    DadosLivro.disponiveis += 1;
                    fseek(fpl, -sizeof(livro),SEEK_CUR);
                    fwrite(&DadosLivro,sizeof(livro),1,fpl);
                    break;
                    }
                 }   
                               
                     
                     rewind(fpa);
                     while(1){
                     fread(&DadosAluno,sizeof(aluno),1,fpa);
                     if(feof(fpa)){
                     break;
                     }
                     if(DadosAluno.matricula == matricula){
                     DadosAluno.emprestimos -= 1;
                     fseek(fpa, -sizeof(aluno),SEEK_CUR);
                     fwrite(&DadosAluno,sizeof(aluno),1,fpa);
                     break;
                     }
                 }
                   
                 fseek(fpe,0,SEEK_SET);
              }
           }
        }
        printf("\n\n\t\t\t   Total de emprestimos: %d\n\n", DadosAluno.emprestimos);
        break;
       
              default:
                      printf("\n\t\t\tOpcao invalida!\n\n");
                                                            
  }
       
       fclose(fpe);
       fclose(fpa);
       fclose(fpl);
       
       }
              
                       
    
/********************************************* Funcao teste ***************************************************/



    void learquivo(){
         FILE * fp;
         emprestimo DadosEmprestimo;
         
         if((fp = fopen ("emprestimos.dat","rb")) == NULL){
                printf("\nError");
                return;
                }
                rewind(fp);
                while(1){
                fread(&DadosEmprestimo,sizeof(emprestimo),1,fp);
                if(feof(fp)){
                break;
                }
                printf("Isbn: %s\n", DadosEmprestimo.isbn);
                printf("Matricula: %d\n", DadosEmprestimo.matricula);
                printf("Data do emprestimo..........: ");
                printf("%02d %02d %d\n", DadosEmprestimo.emprestimo.dia, DadosEmprestimo.emprestimo.mes, DadosEmprestimo.emprestimo.ano);
                printf("Data prevista para devolucao: ");
                printf("%02d %02d %d\n", DadosEmprestimo.prevista.dia, DadosEmprestimo.prevista.mes, DadosEmprestimo.prevista.ano);
                printf("Data da efetiva devolucao...: ");
                printf("%02d %02d %04d\n\n", DadosEmprestimo.devolucao.dia, DadosEmprestimo.devolucao.mes, DadosEmprestimo.devolucao.ano);
                        }         
                
                fclose(fp);
                
                }
                
   
   
   
   
//reference: https://gist.github.com/samuel1992/091b6484c05b81a1e1f4afdaa9b7abce


