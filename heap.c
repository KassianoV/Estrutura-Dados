#include<stdio.h>
#include<stdlib.h>
#include<math.h>
        
int totalElementos = 0;
int heap[5];

int indiceFilhoEsq(int x){
    int indice = (2*x)+1;
    if(x>=totalElementos || indice >= totalElementos)
        return -1;
    else 
        return indice;
}

int indiceFilhoDir(int x){
    int indice = (2*x)+2;
    if(x>=totalElementos || indice>= totalElementos)
        return -1;
    else 
        return indice;
}

indicePai (int x){
    int indice = (int)floor((x-1)/2);
    if(x<= 0 || x>= totalElementos)
        return -1;
    else
        return indice;
}

void AjustarSubindo(int *heap, int pos){
    if(pos != -1){
        int pai = indicePai(pos);
        if(pai != -1){
            if(heap[pos] > heap[pai]){
                int aux = heap[pos];
                heap[pos] = heap[pai];
                heap[pai] = aux;
                AjustarSubindo(heap, pai);
            }
        }
    }
}

void Inserir(int *heap, int x){
    heap[totalElementos] = x;
    totalElementos++;

    AjustarSubindo(heap, totalElementos-1);
}

void AjustarDescendo(int *heap, int pos){
    if(pos != -1 && indiceFilhoEsq(pos) != -1){     //Descobrido maior filho
        int indiceMaiorFilho = indiceFilhoEsq(pos);
        if(indiceFilhoDir(pos) != -1 && heap[indiceFilhoDir(pos)] > heap[indiceMaiorFilho])
            indiceMaiorFilho = indiceFilhoDir(pos);
        if(heap[indiceMaiorFilho] > heap[pos]){         //Verificando se existe filho maior que o nó atual
            int aux = heap[pos];
            heap[pos] = heap[indiceMaiorFilho];
            heap[indiceMaiorFilho] = aux;
            AjustarDescendo(heap, indiceMaiorFilho);
        }
    }
}

int Remover(int *heap){
    if(totalElementos == 0)
        return -1;
    else{
        int retorno = heap[0];
        heap[0] = heap[totalElementos -1];
        totalElementos--;
        AjustarDescendo(heap, 0);
        return retorno;
    }
}

int main (){
    int valor;
    int heap[5];
    printf("Menu:");
    printf("1 - Inserir um elemento \n 2 - Remover um elemento\n 3 - Imprimir \n 4 - Sair");
    int opcao;
    while(opcao != 4){
        switch (opcao){
            case 1:
                printf("qual elemento deseja inserir?");
                scanf("%d",&valor);
                Inserir(heap, valor);
            break;
            
            case 2:
                Remover(heap);
            break;

            case 3:
                for(int i=0; i<totalElementos; i++)
                    printf("%d",heap[i]);
            break;

            case 4:
                printf("fechando Heap!!");
            break;
        }
    }
}