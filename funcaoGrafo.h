#ifndef ARVFUNCOES_H_INCLUDED
#define ARVFUNCOES_H_INCLUDED
#endif //ARVFUNCOES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define NULL __null

//Estrutura da lista
typedef struct lista{
    int destino;
    int custo;
    struct lista *prox;
}lista;

// inicialização do grafo
void inicializar(lista **g, int n){
    int i;
    for(i=0;i<=n;i+1)
        g[i] = NULL;
}

//Inserir Aresta
void InserirAresta(lista**g, int origem,int destino, int custo){
    g[origem] = InserirLista(g[origem], destino, custo);
}

//inserirLista
lista *InserirLista(lista *l, int d, int c){
    lista *no = (lista*) malloc (sizeof(lista));
    no->destino = d; no->custo = c;
    no->prox = l;
    return no;
}

lista *Buscar(lista *l, int valor){
    lista *aux;
    int encontrou = 0;

    aux = l;
    while(encontrou == 0 && aux != NULL){
        if(aux->destino == valor)
            encontrou = 1;
        else 
            aux = (lista *)aux->prox;
    }
    if(encontrou == 1)
        return aux;
    else 
        return NULL;
}

//Remover Aresta
void RemoverAresta(lista**g, int origem, int destino){
    g[origem] = RemoverLista(g[origem], destino);
}

//remover lista
lista *RemoverLista(lista *l, int d){
    if(l == NULL)
        return NULL;
    if(l->destino == d){
        lista *no = l;
        l = l->prox;
        free(no);
        return l;
    }
    l->prox = RemoverLista(l->prox, d);
    return l;
}

/* lista *Remover(lista *l, int d){
    lista *no = Buscar(l,d);
      if(no == NULL)
        return NULL;
    if(no->destino == d){
        lista *no = l;
        l = l->prox;
        free(no);
        return l;
    }
    l->prox = RemoverLista(l->prox, d);
    return l;
}*/

//Imprimir Grafo
void ImprimirGrafo(lista**g, int n){
    int i;
    printf("Grafo:");
    for(i=1;i<=n;i++){
        printf("\n\t%d",i);
        ImprimirLista(g[i]);
    }
}

//ImprimirLista
void ImprimirLista(lista *l){
    if(l != NULL){
        printf("-- (%d, %d)", l->destino, l->custo);
        ImprimirLista(l->prox);
    }
}

//Calcula Saída
int CalculaGrauSaida(lista **g, int n, int pos ){
    int j = 0;
    lista *aux;
    if(pos < n){
        for(aux = g[pos]; aux != NULL; aux = aux->prox)
            j++;
    }
    return j;
}

//Calcula Entrada
int CalculaGrauEntrada(lista **g, int n, int pos){
    int i, j=0;
    lista *aux;
    for(i = 0; i<n; i++){
        for(aux = g[i]; aux != NULL; aux = aux->prox){
            if(aux->destino == pos)
                j++;
        }
    }
    return j;
}

int ProcuraLista(lista *l, int procura){
    lista *p;
    for(p = l; p != NULL; p=p->prox){
        if(p->destino == procura)
            return 1;
    }
    return 0;
}

int VerificaCompleto(lista **g, int n){
    int i,j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(j != i){
                if(ProcuraLista(g[i], j) == 0)
                    return 0;
            }
        }
    }
    return 1;
}

int existe(int *vet,int valor,int pos){
    int i;
    for(i=0;i<pos;i++)
        if(vet[i] == valor)
            return 1;
    return 0;
}

// Imprimir caminho 
void Caminho(lista **g, int b,int *vet, int pos){
    if(vet[pos-1] == b){        // chegou no destino
        int i;
        printf("\n");
        for(i=0;i<pos;i++)
            printf("%d",vet[i]);
    }else{                                  //recursão
        lista *p = g[vet[pos-1]];
        while(p != NULL){
            if(!existe(vet,p->destino,pos)){
                vet[pos] = p->destino;
                Caminho(g,b,vet,pos+1);
            }
            p = p->prox;
        }
    }
}

//destruir lista
void destruirLista(lista **g){
    lista *aux1, *aux2;
    aux1 = *g;
    while (aux1 != NULL){
        aux2 = (lista *)aux1->prox;
        free(aux1);
        aux1 = aux2;
    }
    *g = NULL;
} 