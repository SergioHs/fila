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
        void *dados = f->inicio->dados;

        if(f->fim == f->inicio){
            free(f->inicio);
            f->inicio = NULL;
            f->fim = NULL;
            *resultado = 1;

        } else {
            f->fim->ant = f->inicio->ant;
            free(f->inicio);
            f->inicio = f->fim->ant;
            *resultado = 1;
        }
        return dados;
    } else {
        *resultado = 0;
        return NULL;
    }
}

void destruir(Fila *f, int *resultado){

    int ultimo = 0;

    if(f->inicio == NULL){
        *resultado = 0;
        return;
    }
    
    nodeFila *atual = f->inicio;

    do{
        nodeFila *paraExcluir = atual;
        atual = atual->ant;
        f->fim->ant = atual;
    
        if(paraExcluir == atual){
            ultimo = 1;
        }
        free(paraExcluir->dados);
        free(paraExcluir);

    } while (ultimo != 1);

    free(f);

    *resultado = 1;

}