#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h> 

#define R 32
#define C 1000000
#define MAX 10000
int m[R][C];

void gera_matriz(){

    for (int i=0; i<R;i++){
        for(int j=0;j<C;j++){
            m[i][j] = rand()%MAX;
        }
    }
}

int procura_linha(int x, int c, int l[c]){
    for (int i=0; i<R;i++){
        if(l[i]==x)
        return 1;
    }
    return 0;
}

int lookup(int pid, int c,pid_t l[c]){
    for (int i=0; i<R;i++){
        if(l[i]==pid)
        return 1;
    }
    exit(1);
}

void ocorrencias(int x, int r, int c, int m[r][c]){

    pid_t pids[r];
    int res[r]; 
    for(int i= 0; i<r;i++){
        pids[i] = fork();
        if(!pids[1]){
            _exit(procura_linha(x,c,m[i]));
        }
    }
    for(int i=0;i<r;i++){
        int status; 
        pid_t pid = wait(&status);
        if(WIFEXITED(status) )
            res[lookup(pid, r, pids)] = WEXITSTATUS(status); 
    }

     for(int i=0;i<r;i++){
         if(res[i]){
             printf("\nExiste na linha %d",i);
         }
     }   
    
}

int main(int argc, char* argv[argc + 1]){
    int x = atoi(argv[1]); 
    gera_matriz();
    ocorrencias(x,R,C,m);
}
