#include <stdio.h>
#include <stdlib.h>
#include "fila_interface.h"

Fila* criar(int tamanhoDados, int *resultado){
    Fila* pFila = malloc(sizeof(Fila));
    if(pFila == NULL){
        *resultado = 0;
    } else {
        pFila->fim = NULL;
        pFila->inicio = NULL;
        pFila->tamanhoDados = tamanhoDados;
        *resultado = 1;
    }
    return pFila;
}

void enfileirar(Fila *f, void *elemento, int *resultado){
    nodeFila* novoNode = malloc(sizeof(nodeFila));
    if(novoNode == NULL){
        *resultado = 0;
    } else {
        novoNode->dados = elemento;
        novoNode->ant = NULL;
        
        if(f->inicio == NULL){
            f->inicio = novoNode;
        } else {
            f->fim->ant = novoNode;
        }

        novoNode->ant = f->inicio;
        f->fim = novoNode;

        *resultado = 1;
    }
}

void* desenfileirar(Fila *f, int *resultado){

    if(f->inicio != NULL){
        if(f->fim->ant == f->inicio){
            //pilha com só 1 elemento
            //nodeFila* auxiliar = f->inicio;
            f->inicio = f->inicio->ant;
            *resultado = 1;
        } else {
            //pilha com varios elementos
            //nodeFila* auxiliar = f->inicio;
            f->inicio = f->inicio->ant;
            *resultado = 1;
        }
    } else {
        *resultado = 0;
    }
}

void destruir(Fila *f, int *resultado){

    *resultado = 0;
    
}