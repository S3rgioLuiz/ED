#include <stdio.h>
#include <stdlib.h>
#include "ListaDE.h";

void criaLista(ListaDE *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->n = 0;
}

int incluiNoInicio(ListaDE *lista, Dado dado) {
    Nodo *pNodo;

    pNodo = (Nodo *) malloc (sizeof (Nodo));
    if(pNodo == NULL) return FALTOU_MEMORIA;
    else {
        pNodo->info = dado; 
        pNodo->ant = NULL; pNodo->prox = lista->inicio;
        if(lista->n == 0) lista->fim = pNodo;
        else lista->inicio->ant = pNodo;
        lista->inicio = pNodo;
        lista->n++;
        return SUCESSO;
    }
}

void exibe(ListaDE lista) {
    Nodo *pAux;

    printf("\n ####### EXIBE #######");
    printf("\nInicio: %p", lista.inicio);
    printf("\n ----------------------");
    printf("\n[End. Nodo Ant] - [End. Nodo] - [Codigo] - [Peso] - [End. Prox. Nodo]");
    for(pAux=lista.inicio; pAux!=NULL; pAux=pAux->prox) 
        printf("\n%p - %p - %d - %.2f - %p", pAux->ant, pAux, pAux->info.cod, pAux->info.peso, pAux->prox);
    printf("\n ----------------------");
    printf("\nFim: %p", lista.fim);
    printf("\n #####################");
}