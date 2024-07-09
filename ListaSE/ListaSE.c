#include <stdio.h>
#include <stdlib.h>
#include "ListaSE.h";

void criaLista(ListaSE *lista) {
    lista->inicio = NULL;
}

int incluiNoInicio(ListaSE *lista, Dado dado) {
    Nodo *pNodo;

    pNodo = (Nodo *) malloc (sizeof (Nodo));
    if(pNodo == NULL) return FALTOU_MEMORIA;
    else {
        pNodo->info = dado;
        pNodo->prox = lista->inicio;
        lista->inicio = pNodo;
        return SUCESSO;
    }

}

void exibe(ListaSE lista) {
    Nodo *pAux;

    printf("\n ####### EXIBE #######");
    printf("\n[End. Nodo] -- [Codigo] - [Peso] -- [End. Prox. Nodo]");
    for(pAux=lista.inicio; pAux!=NULL; pAux=pAux->prox) {
        printf("\n%p -- %d -- %.2f -- %p", pAux, pAux->info.cod, pAux->info.peso, pAux->prox);
    }
    printf("\n#####################\n");
}

int quantidadeNodos(ListaSE lista) {
     Nodo *pAux; int contador;

    for(pAux=lista.inicio, contador=0; pAux!=NULL; pAux=pAux->prox) contador++;
    return contador;
}

int estaVazia(ListaSE lista) {
    if(lista.inicio == NULL) return 1;
    else return 0;
}

int excluiDoInicio(ListaSE *lista, Dado *dado) {
    Nodo *pTemp;

    if(lista->inicio == NULL) return LISTA_VAZIA;
    else {
        *dado = lista->inicio->info;
        pTemp = lista->inicio;
        lista->inicio = lista->inicio->prox;
        free(pTemp);
        return SUCESSO;
    }
}

int incluiNoFim(ListaSE *lista, Dado dado) {
    Nodo *pNodo, *pAux;

    pNodo = (Nodo *) malloc (sizeof (Nodo));
    if(pNodo == NULL) return FALTOU_MEMORIA;
    else {
        pNodo->info = dado;
        if(lista->inicio == NULL) {
            pNodo->prox = NULL;
            lista->inicio = pNodo;
        } else {
            for(pAux=lista->inicio; pAux->prox!=NULL; pAux=pAux->prox) { }
            pAux->prox = pNodo;
            pNodo->prox = NULL;
        }
        return SUCESSO;
    }
}

int excluiDoFim(ListaSE *lista, Dado *dado) {
    Nodo *pAux, *pTemp;

    if(lista->inicio == NULL) return LISTA_VAZIA;
    else {
        if(lista->inicio->prox == NULL) excluiDoInicio(lista, dado);
        else {
            for(pAux=lista->inicio; pAux->prox->prox!=NULL; pAux=pAux->prox){ }
            *dado = pAux->prox->info;
            pTemp = pAux->prox;
            pAux->prox = NULL;
            free(pTemp);
        }
        return SUCESSO;
    }
}

int consultaPorCodigo(ListaSE lista, int codigo, Dado *dado) {
    Nodo *pAux;

    if(lista.inicio == NULL) return CODIGO_INEXISTENTE;
    else {
        for(pAux=lista.inicio; pAux!=NULL; pAux=pAux->prox) 
            if(pAux->info.cod == codigo){
                *dado = pAux->info;
                return SUCESSO;
            }
        return CODIGO_INEXISTENTE;     
    }
}

int incluiDepois(ListaSE *lista, Dado dado, int codigo) {
    Nodo *pNodo, *pAux;

    pNodo = (Nodo *) malloc (sizeof (Nodo));
    if(pNodo == NULL) return FALTOU_MEMORIA;
    else {
        for(pAux=lista->inicio; pAux!=NULL; pAux=pAux->prox) {
            if(pAux->info.cod == codigo){
                pNodo->info = dado;
                pNodo->prox = pAux->prox;
                pAux->prox = pNodo;
                return SUCESSO;
            }
        }
        return CODIGO_INEXISTENTE;
    }
}

int excluiNodo(ListaSE *lista, Dado *dado, int codigo) {
    Nodo *pAux, *pTemp;

    if(lista->inicio == NULL) return CODIGO_INEXISTENTE;
    else if(lista->inicio->info.cod == codigo) excluiDoInicio(lista, dado);
    else if(lista->inicio->prox != NULL){
        for(pAux=lista->inicio; pAux->prox!=NULL; pAux=pAux->prox) {
            if(pAux->prox->info.cod == codigo) {
                *dado = pAux->prox->info;
                pTemp = pAux->prox;
                pAux->prox = pAux->prox->prox;
                free(pTemp);
                return SUCESSO;
            }
        }
    }
    return CODIGO_INEXISTENTE;
}

