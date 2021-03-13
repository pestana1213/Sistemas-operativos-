#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <sys/wait.h> /* chamadas wait*() e macros relacionadas */
#include <stdio.h>

//pid_t getpid(void);
//pid_t getppid(void);
//pid_t fork(void);
//void _exit(int status);
//pid_t wait(int *status); // espera que o primeiro filho termine e retorna aquele que terminou 
//pid_t waitPID(pid_t pid, int *status, int options); // espera que um certo filho termine (identificado pelo pid)
//int WIFEXITED(int status); /* macro */
//int WEXITSTATUS(int status); /* macro */


int main (void){

    pid_t pid = fork();  //Pede ao sistema operativo para nos clonar (passa a haver o processo original e a copia que tem o conteudo da memoria); A partir do clone "cada" um vai à sua vida  //Cria um novo processo
    //o fork retorna: a um processo a uma coisa e a outro processo outra coisa 
    
    if(pid == 0 ){  // pid = 0 -> Estamos no processo filho
        printf("FILHO: O meu pid: %d pid pai: %d\n",getpid(),getppid());
    } 
    else{printf("PAI: meu pid:%d, o pid pai: %d, o pid do filho: %d\n",getpid(), getppid(),pid);}

}
