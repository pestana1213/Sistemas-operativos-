#include <fcntl.h>
#include <stdio.h> 
#include <unistd.h> 

int main(void){    
    int in = open("/etc/passwd", O_RDONLY); 
    int err = open("erros.txt", O_WRONLY | O_CREAT, 0666);  //saida
    int out = open("saida.txt", O_WRONLY | O_APPEND |  O_CREAT, 0666);  //saida

    //como fazer redirecionamento: 
    dup2(in,0); 
    close(in);
    dup2(out,1);
    close(out); 
    dup2(err,2); 
    close(err); 

    execlp("wc","wc",(char*)0); 
    _exit(1); 
}