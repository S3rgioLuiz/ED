#include <stdio.h>
#include <stdlib.h>
#include "ListaSE.c";

main() {
    ListaSE lista; Dado dado;
    int operacao=-1, auxiliar, codigo;

    criaLista(&lista);

    for( ; operacao!=0; ) {
        printf("\n*******************************");
        printf("\n\t MENU");
        printf("\n------------------------");
        printf("\n0. Fim                       6. Inclui no Fim");
        printf("\n1. Inclui no Inicio          7. Exclui do Fim");
        printf("\n2. Exibe Lista               8. Consulta por Codigo");
        printf("\n3. Quantidade de Nodos       9. Inclui Depois");
        printf("\n4. Exibe Situacao da Lista   10. Exclui Nodo");
        printf("\n5. Exclui do Inicio");
        printf("\n*******************************");
        printf("\nDigite a Operacao: ");
        scanf("%d", &operacao);

        if(operacao == 1) {
            printf("\nDigite o Codigo: ");
            scanf("%d", &dado.cod);
            printf("\nDigite o Peso: ");
            scanf("%f", &dado.peso);
            if(incluiNoInicio(&lista,dado) == SUCESSO)
                printf("\nSucesso!!\n\n");
            else printf("\nFaltou Memoria\n\n");
        }
        else if(operacao == 3) {
            printf("\nQuantidade de Nodos: %d\n\n", quantidadeNodos(lista));
        }
        else if(operacao == 4) {
            if(estaVazia(lista) == 1) printf("\nLista Vazia!!\n\n");
            else printf("\nLista Possui 1 ou mais Nodos!!\n\n");
        }
        else if(operacao == 5) {
            if(excluiDoInicio(&lista, &dado) == SUCESSO) 
                printf("\nDados Excluidos: Codigo - %d | Peso - %.2f\n\n", dado.cod, dado.peso);
            else
                printf("\nLista Vazia!!\n\n");
        }
        else if(operacao == 6) {
            printf("\nDigite o Codigo: ");
            scanf("%d", &dado.cod);
            printf("\nDigite o Peso: ");
            scanf("%f", &dado.peso);
            if(incluiNoFim(&lista,dado) == SUCESSO)
                printf("\nSucesso!!\n\n");
            else printf("\nFaltou Memoria\n\n");
        }
        else if(operacao == 7) {
            if(excluiDoFim(&lista, &dado) == SUCESSO)
                printf("\nDados Excluidos: Codigo - %d | Peso - %.2f\n\n", dado.cod, dado.peso);
            else printf("\nLista Vazia!!\n\n");
        }
        else if(operacao == 8) {
            printf("\nDigite o Codigo Referencia: ");
            scanf("%d", &codigo);
            if(consultaPorCodigo(lista, codigo, &dado) == CODIGO_INEXISTENTE)
                printf("\nCodigo Inexistente!!\n\n");
            else printf("\nEncontrado: Codigo - %d | Peso - %.2f\n\n", dado.cod, dado.peso);
        } 
        else if(operacao == 9) {
            printf("\nCodigo Referencia p/ Inclusao: ");
            scanf("%d", &codigo);
            printf("\nDigite o Codigo: ");
            scanf("%d", &dado.cod);
            printf("\nDigite o Peso: ");
            scanf("%f", &dado.peso);
            auxiliar = incluiDepois(&lista, dado, codigo);
            if(auxiliar == SUCESSO) printf("\nSucesso!!\n\n");
            else if(auxiliar == CODIGO_INEXISTENTE) printf("\nCodigo Inexistente\n\n");
            else printf("\nFaltou Memoria!!\n\n");
        }
        else if(operacao == 10) {
            printf("\nDigite o Codigo Referencia: ");
            scanf("%d", &codigo);
            if(excluiNodo(&lista, &dado, codigo) == CODIGO_INEXISTENTE)
                printf("\nCodigo Inexistente!!\n\n");
            else printf("\nDados Excluidos: Codigo - %d | Peso - %.2f\n\n", dado.cod, dado.peso);
        }
        exibe(lista);
    }
}