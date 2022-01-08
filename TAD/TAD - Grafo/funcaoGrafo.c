#include <stdio.h>
#include <stdlib.h>
#include"funcaoGrafo.h"

//Estrutura da lista
 struct lista{
    int destino;
    int custo;
    struct lista *prox;
};

// inicialização do grafo
void inicializar(Lista **g, int n){
    int i;
    for(i=0;i<=n;i+1)
        g[i] = NULL;
}

//Inserir Aresta
void InserirAresta(Lista**g, int origem,int destino, int custo){
    g[origem] = InserirLista(g[origem], destino, custo);
}

//inserirLista
Lista *InserirLista(Lista *l, int d, int c){
    Lista *no = (Lista*) malloc (sizeof(struct lista));
    no->destino = d; no->custo = c;
    no->prox = l;
    return no;
}

Lista *Buscar(Lista *l, int valor){
    Lista *aux;
    int encontrou = 0;

    aux = l;
    while(encontrou == 0 && aux != NULL){
        if(aux->destino == valor)
            encontrou = 1;
        else 
            aux = (Lista *)aux->prox;
    }
    if(encontrou == 1)
        return aux;
    else 
        return NULL;
}

//Remover Aresta
void RemoverAresta(Lista**g, int origem, int destino){
    g[origem] = RemoverLista(g[origem], destino);
}

//remover lista
Lista *RemoverLista(Lista *l, int d){
    if(l == NULL)
        return NULL;
    if(l->destino == d){
        Lista *no = l;
        l = l->prox;
        free(no);
        return l;
    }
    l->prox = RemoverLista(l->prox, d);
    return l;
}

//Imprimir Grafo
void ImprimirGrafo(Lista**g, int n){
    int i;
    printf("Grafo:");
    for(i=1;i<=n;i++){
        printf("\n\t%d",i);
        ImprimirLista(g[i]);
    }
}

//ImprimirLista
void ImprimirLista(Lista *l){
    if(l != NULL){
        printf("-- (%d, %d)", l->destino, l->custo);
        ImprimirLista(l->prox);
    }
}

//Calcula Saída
int CalculaGrauSaida(Lista **g, int n, int pos ){
    int j = 0;
    Lista *aux;
    if(pos < n){
        for(aux = g[pos]; aux != NULL; aux = aux->prox)
            j++;
    }
    return j;
}

//Calcula Entrada
int CalculaGrauEntrada(Lista **g, int n, int pos){
    int i, j=0;
    Lista *aux;
    for(i = 0; i<n; i++){
        for(aux = g[i]; aux != NULL; aux = aux->prox){
            if(aux->destino == pos)
                j++;
        }
    }
    return j;
}

int ProcuraLista(Lista *l, int procura){
    Lista *p;
    for(p = l; p != NULL; p=p->prox){
        if(p->destino == procura)
            return 1;
    }
    return 0;
}

int VerificaCompleto(Lista **g, int n){
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
void Caminhos(Lista **g, int b,int *vet, int pos){
    if(vet[pos-1] == b){        // chegou no destino
        int i;
        printf("\n");
        for(i=0;i<pos;i++)
            printf("%d",vet[i]);
    }else{                                  //recursão
        Lista *p = g[vet[pos-1]];
        while(p != NULL){
            if(!existe(vet,p->destino,pos)){
                vet[pos] = p->destino;
                Caminhos(g,b,vet,pos+1);
            }
            p = p->prox;
        }
    }
}

void CaminhoMaisCurto(Lista **g, int b,int *vet, int pos,int*vetAux){
    if(vet[pos-1] == b){        // chegou no destino
        int i;
        if(vet <= vetAux){
            for(i=0;i<pos;i++)
                vet[i-1] = vetAux[i+1];
            vetAux[1] = pos;
        }
    }else{                                  //recursão
        Lista *p = g[vet[pos-1]];
        while(p != NULL){
            if(!existe(vet,p->destino,pos)){
                vet[pos] = p->destino;
                CaminhoMaisCurto(g,b,vet,pos+1,vetAux);
            }
            p = p->prox;
        }
    }
}

int CustoAresta(Lista **g, int a, int b){
    Lista *p = g[a];
    while(p != NULL){
        if(p->destino == b)
            return p->custo;
        p = p->prox;
    }
    return -1;
}

int CalculaCusto(Lista **g,int *vet, int n){
    int i,custo = 0;
    for(i=1;i<n;i++)
        custo += CustoAresta(g,vet[i-1],vet[i]);
    return custo;
}

void CaminhoMenosCustoso(Lista **g,int *vet, int pos,  int d, int*menor, int *vetAux, int *tam){
    if(vet[pos-1] == d){        // chegou no destino
      int custo = CalculaCusto(g,vet,pos);
        if(custo < *menor){
            int i;
            *menor = custo;
            *tam = pos;
            for(i=0;i<pos;i++)
                vetAux[i] = vet[i];
        }
    }else{                                  //recursão
        Lista *p = g[vet[pos-1]];
        while(p != NULL){
            if(!existe(vet,p->destino,pos)){
                vet[pos] = p->destino;
                CaminhoMenosCustoso(g,vet,pos+1,d,menor,vetAux,tam);
            }
            p = p->prox;
        }
    }
}

//destruir lista
void destruirLista(Lista **g){
    Lista *aux1, *aux2;
    aux1 = *g;
    while (aux1 != NULL){
        aux2 = (Lista *)aux1->prox;
        free(aux1);
        aux1 = aux2;
    }
    *g = NULL;
} 