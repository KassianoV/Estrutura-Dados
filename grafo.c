#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

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
            if(l->destino == pos)
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

//destruir lista
void destruirLista(lista **g){
    lista *aux1, *aux2;
    aux1 = g;
    while (aux1 != NULL){
        aux2 = (lista *)aux1->prox;
        free(aux1);
        aux1 = aux2;
    }
    g = NULL;
} 

int main (){
    setlocale(LC_ALL, "Portuguese");
    int n, origem, destino,custo;
    int entrada e saida,pos,Verifica;
    printf("Quantos nós vai ter o grafo?");
    scanf("%d",&n);
   
    //Declaração do grafo dinamica
    lista**g;
    g = (lista**) malloc ((n+1)*sizeof(lista*));

    int opcoes;
    while(opcoes != 6){
        printf("Menu:");
        printf("1 - Inserir Aresta\n2 - Remover Aresta\n3 - Imprimir Grafo\n4 - Imprimir os graus (entrada e saída)\n5 - Verificar se um grafo é completo\n6 - Sair");
        switch (opcoes){
            case 1:
                printf("Qual elemento deseja inserir?(Origem -> Destino | Custo ");
                printf("Origem:");
                scanf("%d \n",&origem);
                printf("Destino:");
                scanf("%d \n",&destino);
                printf("Custo:");
                scanf("%d \n",&custo);
                InserirAresta(g,origem,destino,custo);
            break;
            
            case 2:
                printf("Qual elemento deseja remover?(Origem -> Destino");
                printf("Origem:");
                scanf("%d \n",&origem);
                printf("Destino:");
                scanf("%d \n",&destino);
                RemoverAresta(g,origem,destino);
            break;

            case 3:
            ImprimirGrafo(g,n);
            break;

            case 4:
            print("Qual a posição de entrada e saída que deseja ver?");
            scanf("%d", &pos);
            entrada = CalculaGrauEntrada(g, n,pos);
            saida = CalculaGrauSaida(g, n, pos);

            printf("Entrada: %d\nSaída: %d\nOs dois graus:%d\n ", entrada, saida, entrada+saida);
            break;

            case 5:
                Verifica = VerificaCompleto(g,n);

                if(Verifica == 1)
                    printf("É completa!!!");
                else 
                    printf("Não é completa!!!");
            break;

            case 6:
            printf("Saindo...");
            destruirLista(g);
            break;

            default:
                printf("Digite outro numero");
            break;
        }
    }
    
}