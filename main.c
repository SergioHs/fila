#include <stdio.h>
#include <stdlib.h>
#include "fila_interface.h"

void imprimirFila(Fila *f){

    if(f->fim == f->inicio){
        char* dado = f->fim->dados;
        printf("\n Print - Elemento unico: %d \n", *dado);

    } else {
        //while(f->fim != f->inicio){
        
            char* dado = f->inicio->dados;
            printf("\n Print - Elemento 1: %d \n", *dado);

            char* dado1 = f->inicio->ant->dados;
            printf("\n Print - Elemento 2: %d \n", *dado1);


        //}   
    }
}

int main()
{
    //Criando a fila
    int resultado;
    Fila* myFila = criar(sizeof(int), &resultado); 
    printf("\n Tamanho dos dados: %d \n", myFila->tamanhoDados);
    printf("\n Criado?: %d \n", resultado);

    //Enfileirando 1
    int resultadoEnfileirar;
    int* elemento = malloc(sizeof(int));
    *elemento = 1;
    enfileirar(myFila, elemento, &resultadoEnfileirar);
    printf("\n Enfileirado?: %d \n", resultadoEnfileirar);

    //Enfileirando 2
    int resultadoEnfileirar2;
    int* elemento2 = malloc(sizeof(int));
    *elemento2 = 2;
    enfileirar(myFila, elemento2, &resultadoEnfileirar2);
    printf("\n Enfileirado?: %d \n", resultadoEnfileirar2);

    int resultadoDesenfileirar;
    desenfileirar(myFila, &resultadoDesenfileirar);
    printf("\n Desenfileirado?: %d \n", resultadoDesenfileirar);

    imprimirFila(myFila);

}
