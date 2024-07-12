#ifndef ListaDE_H
#define ListaDE_H

#define SUCESSO 0
#define LISTA_VAZIA 1
#define FALTOU_MEMORIA 2
#define CODIGO_INEXISTENTE 3

typedef struct {
    int cod; float peso;
} Dado;

typedef struct nodo Nodo;

struct nodo {
    Dado info; Nodo *prox, *ant;
};

typedef struct {
    Nodo *inicio, *fim;
    int n;
} ListaDE;

void criaLista(ListaDE *lista);
int incluiNoInicio(ListaDE *lista, Dado dado);
void exibe(ListaDE lista);

#endif