#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>


int main(void){

    for(int i = 0; i<10; i++){  // o ciclo é o pai que o esta a executar 
        pid_t pid = fork(); 
        if(!pid){ //processo filho; 
            printf("Eu: %d\nPai: %d\n", getpid(),getppid()); 
            _exit(i); //NAO ESQUECER DESTA MERDA
        }
    }
        int status[10]; 
        for(int i = 0; i<10; i++){  // vai esperar que o codigo filho todo execute primeiro e depois faz esta merda de maneira a correr concorrentemente
        wait(&status[i]); //deposita no status
        }
        for(int i = 0; i<10; i++){  // vai esperar que o codigo filho todo execute primeiro e depois faz esta merda de maneira a correr concorrentemente
        if(WIFEXITED(status[i])){
            printf("filho numero: %d\n",WEXITSTATUS(status[i])); //Espera que o filho que esta a correr termine o processo para depois correr outra vez o ciclo
        }
    }

}