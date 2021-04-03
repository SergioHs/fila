#include "fila_privado.h"

Fila* criar(int tamanhoDados, int *resultado);

void enfileirar(Fila *f, void *elemento, int *resultado);

void* desenfileirar(Fila *f, int *resultado);

void destruir(Fila *f, int *resultado);

//Requisito: alocar um item (tamanho de dados) por vez