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

int procura(int x, int r, int c, int m[r][c]){

    for(int i= 0; i<r;i++){
        if(!fork()){
            _exit(procura_linha(x,c,m[i]));
        }
    }
    for(int i=0;i<r;i++){
        int status; 
        wait(&status);
        if(WEXITSTATUS(status) && WIFEXITED(status) == 1)
            return 1;
    }
    return 0; 
}

int main(int argc, char* argv[argc + 1]){
    int x = atoi(argv[1]); 
    gera_matriz();
    int res = procura(x,R,C,m);
    printf("%s\n",res == 1 ? "Existe" : "Nao existe");
    

}
