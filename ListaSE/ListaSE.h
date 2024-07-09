#ifndef ListaSE_H
#define ListaSE_H

#define SUCESSO 0
#define LISTA_VAZIA 1
#define FALTOU_MEMORIA 2
#define CODIGO_INEXISTENTE 3

typedef struct {
    int cod;
    float peso;
} Dado;

typedef struct nodo Nodo;

struct nodo {
    Dado info;
    Nodo *prox;
};

typedef struct {
    Nodo *inicio;
} ListaSE;

void criaLista(ListaSE *lista);
int incluiNoInicio(ListaSE *lista, Dado dado);
void exibe(ListaSE lista);
int quantidadeNodos(ListaSE lista);
int estaVazia(ListaSE lista);
int excluiDoInicio(ListaSE *lista, Dado *dado);
int incluiNoFim(ListaSE *lista, Dado dado);
int excluiDoFim(ListaSE *lista, Dado *dado);
int consultaPorCodigo(ListaSE lista, int codigo, Dado *dado);
int incluiDepois(ListaSE *lista, Dado dado, int codigo);
int excluiNodo(ListaSE *lista, Dado *dado, int codigo);

#endif