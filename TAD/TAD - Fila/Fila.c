#include "Fila.h"
#include <stdio.h>
#include <stdlib.h>
#define MFILA 10

//Estrutura fila 
struct fila{
    float elementos[MFILA];
    int inicio,fim;
    int qtd;
};

//Cria o vetor zerado
Fila CriaFila (Fila f){
    f->elementos;
    f->inicio =0;
    f->fim = -1;
    f->qtd = 0;
    return f;
}

int Inserir(Fila f, int num){
    if(f->qtd == MFILA)
        return 0;
    f->fim++;
    f->elementos[f->fim] = num;
    f->fim = (f->fim++) % MFILA;
    f->qtd++;
    return 1;
}

int  Remover (Fila f){
    if(f->qtd == 0)
        return 0;
    else{
        int num = f->elementos[f->inicio++];
        if(f->inicio == MFILA)
            f->inicio = 0;
        f->qtd --;
        return num;
    }
}

void ImprimirFila(Fila f){
    int cont, i;
    if(f->qtd == 0)
        printf("Fila vazia");
    else{
        for(cont = 0, i = f->inicio; cont < f->qtd; cont++){
            printf("%f\n",f->elementos[i++]);
            if(i == MFILA)
                i=0;
        }
    }
}