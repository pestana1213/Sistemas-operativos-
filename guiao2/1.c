#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

//pid_t getpid(void);
//pid_t getppid(void);
//pid_t fork(void);
//void _exit(int status);
//pid_t wait(int *status); // espera que o primeiro filho termine e retorna aquele que terminou 
//pid_t waitPID(pid_t pid, int *status, int options); // espera que um certo filho termine (identificado pelo pid)
//int WIFEXITED(int status); /* macro */
//int WEXITSTATUS(int status); /* macro 

void main (){

    printf("Eu: %d\n", getpid());
    printf("Meu pai: %d\n", getppid());


}