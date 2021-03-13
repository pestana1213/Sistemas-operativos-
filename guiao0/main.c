#include <stdio.h>
#include <stdlib.h>
#include "guiaoheader.h"
#define TAM 10

//variavel globald de tamanho 10
int global[TAM];


int main () {
    int local [TAM]; 
    int *dinamica = calloc(TAM, sizeof(int));

    //PARA VARIAVEIS LOCAIS:
    fill(local, TAM, 1);
    printf("Variavel local:\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", local[i]);
    }
    printf("\nFind (%d): %d\n", 1, find(local, TAM, 1));

    //VARIAVEIS GLOBAIS:
    fill(global, TAM, 3);
    printf("Variavel global:\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", global[i]);
    }
    printf("\nFind (%d): %d\n", 7, find(global, TAM, 7));

    //VARIAVEIS DINAMICAS
    fill(dinamica, TAM, 5);
    printf("Variavel dinamica:\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", dinamica[i]);
    }
    printf("\nFind (%d): %d\n", 1, find(dinamica, TAM, 1));
    free(dinamica); //libertar a memoria ocupada
    //Conclusao: Todos os tipos de definição do array funcionam com a API.
}

//EXERCICIO 3
/*
Ao redefinirmos a funcao find como find(int* vector, int size, int begin, int end, int size);
poderiamos alterar a função de modo a que a procura seja feita na janela entre "begin" e "end", incluindo
uma variavel com o tamanho total do array, de modo a nos certificarmos de que este tamanho nunca é excedido.
*/

//EXERCICIO 4
/*
Se tentarmos preencher alguma posição que excede o tamanho do array (i.e. tentar preencher v[12] quando v esta 
definido como int v[10];), o programa vai dar um erro do tipo "segmentation fault", o que impede a execução do mesmo.
Por esta razão, deveremos sempre certficar-nos de que nao acedemos a mais memória do que aquela que reservámos.
*/


}