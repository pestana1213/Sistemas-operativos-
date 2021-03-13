#include "guiaoheader.h"
#include <stdio.h>

//enche o vetor com o value

void fill(int* vector, int size, int value){
    
    for (int i=0; i<= size;i++){
        vector[i]=value
    }
}

// encontra o valor no vetor 

int find(int* vector, int size, int value){
int res = 0; 
    for (int i = 0; i<=size){
        if(vector[i]==value)
        res = 1
    }
return res; 
}
