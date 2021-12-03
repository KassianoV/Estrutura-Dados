#include<stdio.h>
#include<stdlib.h>

//1 - Toda as compinações de {a, e, i} de tamanho n, que o número de a's é maior que a suma de todos de e's e de i's
void ImprimirCombinacoes1(char *vet, int pos, int n, char *vetAux){                   //vetAux = {a,e,i}
    int i;
    if(pos == n){
        int cont_a = 0;
        int cont_e = 0;
        int cont_i = 0;
        for(i=0;i<n;i++){
            if(vet[i] == 'a')
                cont_a++;
            else if(vet[i] == 'e')
                cont_e ++;
            else if(vet[i] == 'i')
                cont_i ++;
        }
        if(cont_a > cont_e+cont_i){
            printf("\n");
            for(i=0;i<n;i++)
                printf("%c",vet[i]);
        }
            
    }else  {
        for(i=0;i<=3;i++){
            vet[pos] = vetAux[i];
            ImprimirCombinacoes1(vet, pos+1, n, vetAux);
        }
    }
}

//Todas as combinações de {15,31,55,44}, de tamanho n, cuja soma dos elementos da combinação é par
void ImprimirCombinacoes2(int *vet,int pos,int n,int *vetAux){                       //vetAux[15, 31,55,44] 
    int i;
    if(pos == n){
        int Soma = 0;
        for(i=0;i<n;i++)
            Soma += vet[i];
        if(Soma % 2 == 0){
            printf("\n");
            for(i=0;i<n;i++)
                printf("%d",vet[i]);
        }    
    }else {
        for(i=0;i<4;i++){
            vet[pos] = vetAux[i];;
            ImprimirCombinacoes2(vet,pos+1,n,vetAux);
        }
    }
}

//Dado um valor em centavos, imprimir todas as maneiras de representa-lo utilizando moedas de 1,5,10,25,50 centavos
void ImprimirCombinacoes3(int *vet,int pos,int n, int *vetAux,int valor){                  //vetAux[1,5,10,,25,50]
    int i;
    if(pos == n){
        int soma = 0;
        for (i=0;i<n;i++)
            soma += (vet[i]*vetAux[i]);
        if(soma == n){
            printf("\n");
            for(i=0;i<n;i++)
                printf("%d",vet[i]);
        }
    }else {
        int maximo = (int) valor/vetAux[pos];
        for (i=0;i<=maximo;i++){
            vet[pos] = i;
            ImprimirCombinacoes3(vet,pos+1,n,vetAux,valor);
        }
    }
}

int main(){
    char *vetchar;
    char vetAux[3] = {'a','e','i'};
    int n;    
    printf("Digite o tamanho da combinacao 1:");
    scanf("%d",&n);
    ImprimirCombinacoes1(vetchar, 0, n, vetAux);

    int *vet;
    int vetAux[4] = {15,31,55,44};
    printf("Digite o tamanho da combinacao 2:");
    scanf("%d",&n);
    ImprimirCombinacoes2(vet,0,n,vetAux);

    int vetValor[5] = {1,5,10,25,50};
    int valor;
    printf("Digite o tamanho da combinacao 3:");
    scanf("%d",&n);

    printf("Qual o valor em centavos ?");
    scanf("%d", &valor);
    ImprimirCombinacoes3(vet,0,n,vetValor,valor);
}