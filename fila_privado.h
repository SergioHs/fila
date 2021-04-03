typedef struct nodeFila {
    void *dados;
    struct nodeFila *ant;
} nodeFila;

typedef struct Fila {
    nodeFila *inicio, *fim;
    int tamanhoDados;

} Fila;

int cheia(Fila *f); // ver qual é o sentido
int vazia(Fila *f);