#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>


int main(void){

    for (int i = 0; i<10;i++){
        
        if(fork()){ 
            break;
        }
    }
    printf("Eu: %d\nPai: %d\n",getpid(), getppid());
    wait(0);

}
