#include <stdio.h>
#include <stdlib.h>
#include "fila_interface.h"

void imprimirFila(Fila *f){

    if(f == NULL || f->inicio == NULL){
        return;
    }
    
    printf(" Fila: ");

    nodeFila *atual = f->inicio;

    do{
        int* dado = atual->dados;
        printf(" %d ", *dado);
        atual = atual->ant;

    } while (atual != f->inicio);

    printf(" \n ");
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
    *elemento = 80;
    enfileirar(myFila, elemento, &resultadoEnfileirar);
    printf("\n Enfileirado?: %d \n", resultadoEnfileirar);

    //Enfileirando 2
    int resultadoEnfileirar2;
    int* elemento2 = malloc(sizeof(int));
    *elemento2 = 785;
    enfileirar(myFila, elemento2, &resultadoEnfileirar2);
    printf("\n Enfileirado?: %d \n", resultadoEnfileirar2);

    //Enfileirando 3
    int resultadoEnfileirar3;
    int* elemento3 = malloc(sizeof(int));
    *elemento3 = 982;
    enfileirar(myFila, elemento3, &resultadoEnfileirar3);
    printf("\n Enfileirado?: %d \n", resultadoEnfileirar3);

    int resultadoDesenfileirar;
    int* dadoDesinfileirado = desenfileirar(myFila, &resultadoDesenfileirar);
    printf("\n Desenfileirado?: %d \n", resultadoDesenfileirar);
    printf("\n Dado Desenfileirado: %d \n", *dadoDesinfileirado);

    imprimirFila(myFila);

    int resultadoDestruir;
    destruir(myFila, &resultadoDestruir);
    printf("\n Destruido?: %d \n", resultadoDestruir);

    printf("\n HERE \n");
    
}
