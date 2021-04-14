#include <fcntl.h>
#include <stdio.h> 
#include <unistd.h> 

int main(void){

    int fd2 = dup(1); 
    
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

    char c; 
    while(1){
        int n = read(0,&c,1); 
        if (n<=0) break; 

        write(1,&c,1);
        write(2,&c,1);
    }



}