#include "Fila.h"
#include<stdio.h>
#include<stdlib.h>

int main (){
    Fila f;
    int opcao, numInserido,numRemovido,resp;

    CriaFila(f);

    while(opcao != 4){
        printf("\tMenu:\n 1 - Inserir\n 2 - Remover\n 3 - Imprimir\n 4 - Sair\n");
        printf("O que deseja fazer?");
        scanf("%d",&opcao);
        switch (opcao)
        {
        case 1:
            printf("Qual numero quer inserir?");
            scanf("%d",&numInserido);
            resp = Inserir(f,numInserido);
            if(resp == 0)
                printf("Fila está cheia");
            else 
                printf("Elemento inserido na fila");
            break;

            case 2:
                numRemovido = Remover(f);
            if(numRemovido == 0)
                printf("Fila está vazia");
            else 
                printf("Elemento removido foi: %d\n", numRemovido);
            break;

            case 3:
                ImprimirFila(f);
            break;

            case 4:
                printf("Saindo!!!");
            break;

        }
    }
}  