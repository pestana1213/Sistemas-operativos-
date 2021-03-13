#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(void){

    for(int i = 0; i<10; i++){  // o ciclo é o pai que o esta a executar 
        pid_t pid = fork(); 
        if(!pid){ //processo filho; 
            printf("Eu: %d\nPai: %d\n", getpid(),getppid()); 
            _exit(i+1); //NAO ESQUECER DESTA MERDA
        }
        int status; 
        wait(&status); //deposita no status
        if(WIFEXITED(status)){
            printf("%d\n",WEXITSTATUS(status)); //Espera que o filho que esta a correr termine o processo para depois correr outra vez o ciclo
        }
    }

}