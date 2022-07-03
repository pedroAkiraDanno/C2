

/*
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *
 * 07-11-2020, v1.0, Pedro Akira Danno Lima
 *
 * Compile: gcc -Wall -O2 logrotate.c -o logrotate
 */





 /**********************************************
  * OBJETIVO  : LOG ROTATE                     *
  * CRIACAO   : 07-11-2020                     *
  * VERSAO    : 1.0                            *
  * AUTOR     : Pedro Akira Danno Lima         *
  **********************************************/





/*
    DESCRICAO:



*/



/*
    study:


    buffer = local na memoria para armazenar uma certa qtd para depois colocar no arquivo, para melhorar a performace
    imagina colocar byte por byte no disco ridigo ia ser muito demorado 
    buffer = algo temporario, tmp

*/


/*
    test:

    system("clear");
    man 2 pipe

    exec:
    ./test1 | ./logrotate file.log 1000 10 1 

    1000 = bytes of size file file.log
    10 = LOGFILEGROUP
    1 = archiveLogEnabled

     file offset - deslocamento


*/



//header files 
#include <stdio.h> //to system call rename
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h> //fstat stat 
#include <limits.h>
#include <fcntl.h> // to system call open 
#include <unistd.h> //to system call write,read
#include <fcntl.h>
#include <string.h> //because memset -> man memset 
//
//MACROS 
#define _VERSION "1.0"
#define _BUF_SIZE_IN 2048 //bytes
#define _BUF_SIZE_TS 64 //bytes



/*structs*/
typedef struct
{

    char *name ; //name of log file
    unsigned long MAX_SIZE ; //max size of log file - bytes
    unsigned int LOGFILEGROUP; //int quantidade de log files no logrotate referencia banco de dados oracle ex: file.log.1, file.log.2, file.log.3, file.log.4
    unsigned int LOGFILEMEMBER;
    int archiveLogEnabled;      // 0 = false (1 or > true)    process  LGWR ARCn processes -  True if log archiving is enabled for the source
    char *archiveLogDestination; // destination where go archive files .arc ex: /u01/arc/*.arc*
    int swithlogfile; //force swith log file ex: file.log.1 to file.log.2 
    char *logDestination; // destination where go LOG files .log ex: /var/log/*.log*
    int lognumbers; //to use in logroate for: file.log.1, file.log.2  file.log.3 ...
    /*each switch log need archivelog copy */
    unsigned long long SEQUENCE; //ref by oracle - redo log  Log sequence number
    int STATUS;  //ref by oracle -Log status: UNUSED CURRENT ACTIVE CLEARING CLEARING_CURRENT INACTIVE 
    //unsigned long long SequenceArcLog=1;
    int SequenceArcLog;

}controlfile;





/*Prototipos da funcoes*/
 int printLineTS(char *buf, int maxLen, char *extra); // ex:2020-11-21 09:27:44 > extra   _BUF_SIZE_TS 64
 unsigned long long getFileSize(int fd); // get the size file
 int openOutput(void); //open a file, open a file mean create a pointer to file in memory to hard disk 
 int loadBuffer(void *buf, int pos, int size); //system call read 
 void rotateLog(int *fd); //if MAX_SIZE > file log switch to another file 
 void process(void);
 void archivelog( char *name); //function to archivelog file ex: file.arc.1, file.arc.2 ... each switch logfile/rotatelog enable copy to .arc_nn
 void print_copyright(void);
 void help();
 void controfile(char *values); //create the file controlfile to control where the sequence stop, the names of file and etc... to control everything





/* variaveis globais */
static char *name = NULL; //name of log file
static unsigned long MAX_SIZE = 0; //max size of log file - bytes
unsigned int LOGFILEGROUP =  4; //int quantidade de log files no logrotate referencia banco de dados oracle ex: file.log.1, file.log.2, file.log.3, file.log.4
unsigned int LOGFILEMEMBER =  1;
int archiveLogEnabled = 0;      // 0 = false (1 or > true)    process  LGWR ARCn processes -  True if log archiving is enabled for the source
char *archiveLogDestination = NULL; // destination where go archive files .arc ex: /u01/arc/*.arc*
int swithlogfile = 0; //force swith log file ex: file.log.1 to file.log.2 
char *logDestination = NULL; // destination where go LOG files .log ex: /var/log/*.log*
int lognumbers= 1; //to use in logroate for: file.log.1, file.log.2  file.log.3 ...
/*each switch log need archivelog copy */
unsigned long long SEQUENCE=1; //ref by oracle - redo log  Log sequence number
int STATUS;  //ref by oracle -Log status: UNUSED CURRENT ACTIVE CLEARING CLEARING_CURRENT INACTIVE 
//unsigned long long SequenceArcLog=1;
int SequenceArcLog=1;
//int LOG_ARCHIVE_DEST_n =1; //ref by oracle database
//char *LOG_ARCHIVE_FORMAT //ref by oracle database
//int LOG_ARCHIVE_MAX_PROCESSES //ref by oracle database
//int LOG_ARCHIVE_TRACE //ref by oracle database
char string[1024]; //string to storage buffer the controlfile 








/*main*/
int
main(int argc, char *argv[]){


    //to help(void)
    if (strcmp(argv[1], "help") == 0){
        help();
        exit(EXIT_SUCCESS);                
    }



    // Check Params
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <pathname> <size-limit-bytes>\n", argv[0]);
        fprintf(stderr, "error = %s\n",strerror(errno)); //show explanation ex: file name too long, file not exist
        exit(EXIT_FAILURE);
    }



    //ex:       top | ./logrotate file.log 1000
    
    name = argv[1]; //name of log file
    MAX_SIZE = atol(argv[2]); //atol -> Convert String to Long Integer
    LOGFILEGROUP = atol(argv[3]);
    archiveLogEnabled = atol(argv[4]);


    //system("clear|cls"); 


    //print the argvs
    int i;
    printf("argc= %d\n", argc);
    for(i =0; i< argc; i++){
      printf("argv[%d] =%s\n",i, argv[i]);
    }

    




    //
    process();
    //


    //
   exit(EXIT_SUCCESS);

   return 0;
}











/*funcao*/ 
 int
printLineTS(char *buf, int maxLen, char *extra) // ex:2020-11-21 09:27:44 > extra
{

//-1 Maximum number of bytes to be used in the buffer.The generated string has a length of at most n-1, leaving space for the additional terminating null character. size_t is an unsigned integral type


       time_t t = time(NULL);
       struct tm *p_tm = localtime(&t);
       return snprintf(buf, maxLen, "%04d-%02d-%02d %02d:%02d:%02d%s", p_tm->tm_year+1900, p_tm->tm_mon+1, p_tm->tm_mday, p_tm->tm_hour, p_tm->tm_min, p_tm->tm_sec, extra);

       //return snprintf  = 
       //The function returns an integer, which is the number of characters that 
       //would have been written if the buff_size argument had been large enough.
      


      //or
      //time_t t = time(NULL);
      //struct tm *p_tm = localtime(&t);
      //p_tm = localtime(&t);
      //printf("Current local time and date: %s", asctime(p_tm));
      //return snprintf(buf, maxLen, "%s %s",asctime(p_tm), extra);
}




//
//modificadores  unsigned=positive 
/*
stat in linux/unix
ref How to get a file's size in C? (stat, fstat, fileno) https://www.youtube.com/watch?v=FT2A2HQbTkU
[root localhost ~]# stat arquivo.txt
*/
 unsigned long long
getFileSize(int fd) // get the size file
{
    struct stat sb;
    int res = fstat(fd, &sb);


    if (res != 0) {
        fprintf(stderr, "Error fstat res(%d): %d (%s)\n", res, errno, strerror(errno));
        exit(EXIT_FAILURE);
    }
    return sb.st_size;
}
//






//
// use a system call open 
/*
man 2 open 

*/
 int
openOutput(void)
{
    int fd = -1;
    // Open Output File
    //fd = open(name, O_CREAT|O_APPEND|O_WRONLY|O_LARGEFILE, S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
    fd = open(name, O_CREAT|O_APPEND|O_WRONLY,777);
    if (fd < 0) {
        fprintf(stderr, "Error open: %d (%s)\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }
    return fd;
}



//
/*
use a system call read 
man 2 read 
*/
 int
loadBuffer(void *buf, int pos, int size)
{

        /*verbose debug and show informations 
          printf("buf: %s", buf);
          printf("size: %s", size);
          printf("pos: %d", pos);
        */

    return read(0, buf + pos, size - pos); 

    /*
    Returns: How many bytes were actually read
    return Number of bytes read on success
    return 0 on reaching end of file
    return -1 on error
    return -1 on signal interrupt


    and storaged in buffer buf
    so can print after, because its in de memory 
    */



}
//





//
 void 
rotateLog(int *fd)
{


    //count the performed 
    clock_t start_time, end_time;
    double total_time;
    start_time = clock();









    if (*fd == -1) {
        *fd = openOutput(); //open a file|create if not exist 
    } else {
        unsigned long long fileSize = getFileSize(*fd); //get the size of file 

        if (fileSize > MAX_SIZE) { //check if the current(atual) file is > MAX_SIZE(the user choose the size in argvs)
            char newname[2048]; //newname
            close(*fd); 
            *fd = -1;
            //snprintf(newname, sizeof(newname), "%s.old", name); //firt parameter buffer(newname), second (size of buffer), and format string
            snprintf(newname, sizeof(newname), "%s.old.%d", name, lognumbers); //firt parameter buffer(newname), second (size of buffer), and format string
            rename(name, newname); //system call, man 2 rename 
            *fd = openOutput();

            //to verbose 
            printf("swithlogfile %d \n",lognumbers);   
            printf("sequence %llu \n",SEQUENCE);


            //to controfile
            sprintf(string, "swithlogfile %d", lognumbers);
            controfile(string);
            //            




            lognumbers++;
            SEQUENCE++;

             //count the performed 
             end_time = clock();
             total_time  =  (double) (end_time - start_time);
             total_time =   total_time / CLOCKS_PER_SEC;
             printf("Time for logfile rotate = %.6f seconds\n", total_time); 





            /*archivelog*/
            if(archiveLogEnabled != 0){
                printf("archivelog  %d \n",SequenceArcLog);                
                archivelog(newname);
            }
       
        }

        if(lognumbers  >= LOGFILEGROUP){
            lognumbers =1; //reset the number of log file 

            //to verbose 
            printf("rotateLog completed %d \n", LOGFILEGROUP);        
        }

    }
}
//






void archivelog( char *name){



    //count the performed 
    clock_t start_time, end_time;
    double total_time;
    start_time = clock();




    
    //read fd1 
    //fd2 write to copy fd1 content
    char nameArcLog[2048]; //newname    
    FILE *fd1,*fd2;

    //verbose
    printf("name of logfile: %s\n",name );

    char ch;
    fd1 = fopen (("%s", name),"r");
   
    snprintf(nameArcLog, sizeof(nameArcLog), "file.arc.%d", SequenceArcLog); // puts string into buffer
   
    //verbose 
    printf("name of archivelog: %s\n",nameArcLog );

    fd2 =fopen(("%s", nameArcLog),"w");

    //copy content name to nameArcLog
    if(fd1 == NULL || fd2 == NULL){
        printf("Error: Cannot open file\n");
    }

    //copy content name to nameArcLog
    // infinit while because not know how much caraters content in file 
    while(1){
        ch=fgetc(fd1);
        if(ch==EOF) //END OF FILE
            break;

        fputc(ch,fd2);
    }    

    fclose(fd1);
    fclose(fd2);
    SequenceArcLog++;



    //count the performed 
    end_time = clock();
    total_time  =  (double) (end_time - start_time);
    total_time =   total_time / CLOCKS_PER_SEC;
    printf("Time for archivelog = %.6f seconds\n", total_time);        

    

}






//
/*

*/
void
process(void) 
{
    ssize_t readed = 0;
    int fd = -1; //File descriptor
    int i;
    int head = 0;
    int eol = 0; //EOL End of Line
    int newlined = 0; // /n
    char bufin[_BUF_SIZE_IN]; // 2048 bytes
    char bufts[_BUF_SIZE_TS]; //64 bytes


 
    //
    //memset is used to fill(preencher) a block of memory with a particular value //copy data using memset
    //
    memset(bufin, 0, sizeof(bufin)); //PUT A BUFIN WITH VALUES 0000000...
    //printf("%s\n",bufin);

    //void* loc = memset (loc, 'Z',4);    h e l l o=4bytes=hell    -> zzzo      
    //memset is mush faster than other initializers like calloc()
    //the memory will be set byte by byte

    /*void *memset(void *str, int ch, size_t n)
    ch: This is the value that is to be copied to the memory block. This is an integer value, but it is converted to an unsigned character before copied.
    Return values:
    memset() returns the first address of the memory block from where it starts to set the value

    the integer value is greater than one byte and the memset 
    function converts the value to an unsigned character before copied.
    **we have seen using the memset function how we can initialize or set the value of a memory block efficiently
    **Memset function is faster to set a large chunk of contiguous memory in comparison with simply setting the location using a loop.
    */




    while ((readed = loadBuffer(bufin, head, sizeof(bufin)-1)) > 0) { //loadBuffer -> system call read 
        bufin[readed] = 0;

        /*verbose debug and show informations 
          printf("bufin: %s\n", bufin);
          printf("bufts: %s\n", bufts);
          printf("newlined: %d\n", newlined);
          printf("readed %zu\n", readed);
        */

        //Escape Sequences = EOL EOB
        for (i = 0; i < readed; i++) {
            if (bufin[i] == 10 || bufin[i] == 13 || bufin[i] == 0) { // EOL(-1) End of Line             \n          \t'  EOF            //Note that EOF is not a character, but a macro for the value returned by some functions when an end-of-file condition is encountered (or returned when there is an error in some cases)

                bufin[i] = 0; // EOB  new line    #define EOL '\n'
                write(fd, bufin + head, i - head);

                if (eol == 0) {
                    write(fd, "\n", 1);
                }

                head = i+1;
                eol++; 
                newlined=0;
            } else {

                if (!newlined) {
                    int len = printLineTS(bufts, sizeof(bufts)-1, " > "); //int printLineTS ex:2020-11-21 09:27:44 > extra
                    rotateLog(&fd);
                    write(fd, bufts, len);
                    newlined++;
                }

                eol = 0;
            }
        }


        if (!eol) {
            write(fd, bufin + head, readed - head);
        }
        
        head = 0;
    }

    if (newlined) {
        write(fd, "\n", 1);
    }

}
//





 void print_copyright(void){



  puts("Licensed under the Apache License, Version 2.0, the 'License'\n"
   "you may not use this file except in compliance with the License.\n"
   "You may obtain a copy of the License at\n\n"
 
   "http://www.apache.org/licenses/LICENSE-2.0\n\n"
 
   "Unless required by applicable law or agreed to in writing, software\n"
   "distributed under the License is distributed on an AS IS BASIS,\n"
   "WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.\n"
   "See the License for the specific language governing permissions and\n"
   "limitations under the License.\n\n\n"
 
 
   "07-11-2020   08-01-2021, v3.0, Pedro Akira Danno Lima\n\n\n\n");
 
 
 }






 void help(){

    //fprintf(output, "logrotate utility is designed to simplify the administration of log files.\n\n");
    printf("logrotate utility is designed to simplify the administration of log files.\n\n");

    printf("Usage:\n");
    printf("  logrotate [OPTIONS]... \n\n\n");


    printf("Compile:\n");
    printf("  gcc -Wall -O2 logrotate.c -o logrotate\n\n\n");



    printf("Simple Example run:\n");
    printf("  ./test1 | ./logrotate file.log 1000 10 1\n"); 
    printf("  firt argv file.log file name\n");   
    printf("  second argv 1000 = bytes of size file file.log\n");    
    printf("  third argv 10 = LOGFILEGROUP\n");
    printf("  fourth argv 1 = archiveLogEnabled\n\n\n");  




    printf("Full Example run:\n");
    printf("  step 1 create test1.sh:\n");
    printf("  touch test1\n");     
    printf("  #!/bin/bash\n  for (( ; ; ))  \n  do  \n  echo \"test\"  \n  sleep 10  \n  done  \n\n");

    printf("  step 2 give permision to file test1.sh:\n");    
    printf("  chmod +x test1\n\n");

    printf("  step 3 compile logrotate:\n");    
    printf("  gcc -Wall -O2 logrotate.c -o logrotate\n\n");

    printf("  step 4 exec with argvs logrotate:\n");    
    printf("  ./test1 | ./logrotate file.log 1000 10 1\n\n\n");


    printf("For more informations access doc in <https://github.com/pedroAkiraDanno> \n\n\n");

   
    

 }








 void controfile(char *values){


   FILE *fptr;

   //
   fptr = fopen("controfile.ctl","aw");

   if(fptr == NULL)
   {
      printf("Error: Cannot open file\n");
      exit(1);             
   }


   fprintf(fptr,"%s",values);
   fclose(fptr);






 }














  /*****************************************************************************************************************
  *                                                   REFERENCIAS                                                  *
  * https://pt.stackoverflow.com/questions/104118/qual-%C3%A9-a-finalidade-dos-comandos-size-t-e-ssize-t-em-c      *
  ******************************************************************************************************************/











