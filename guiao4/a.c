#include <fcntl.h> 
#include <stdio.h>

int main(void){

    int fd = open("XXX.txt", O_RDONLY); //fd = 3 
    printf("%d\n",fd);
    int fd2 = dup(fd);
    printf("%d\n",fd2);
    char buf[100]; 
    read(fd,buf,2);      //fd = 3 
    read(fd2,buf+2,2);    //fd2 = 4 
    buf[4]=0;
    printf("%s\n",buf);
}