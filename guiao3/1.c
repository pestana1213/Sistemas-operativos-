#include <unistd.h>

int main void(){
    execlp(“ls”, “ls”, “-l”, (char*)0);                                            //também poderia ser NULL em vez de 0

    printf(“falhou\n”);
}