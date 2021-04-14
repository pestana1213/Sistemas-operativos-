#include <fcntl.h>
#include <stdio.h> 
#include <unistd.h> 
#include <string.h> 

int main(int argc, char* argv[]){
    if (argc < 2) return 1; 

    int i = 1;

    if (!strcmp(argv[1], "-i")){
        if (argc < i+3) return 1; 
        int in = open(argv[i+1], O_RDONLY); 
        dup2(in,0); 
        close(in); 
        i += 2; 
    }

    if (!strcmp(argv[1], "-o")){
        if (argc < i+3) return 1; 
        int out = open(argv[i+1], O_WRONLY | O_CREAT | O_TRUNC, 0666); 
        dup2(out,1); 
        close(out); 
        i += 2; 
    }

    execvp(argv[i], argv+1);
    
}