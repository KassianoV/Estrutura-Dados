#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>
#include"ArvFuncoes.h"

int main(){
     ARVORE *a = inicia_arv();
    int opcoes;
    char endereco[50];
    int imprimir, elemento, nivel, x;
    FILE *arq;

    while(opcoes != 9){
        printf("\t\t\t Menu: (Escolha um numero )");
        printf("\n 1) Ler Arvore");
        printf("\n 2) Imprimir Arvore");
        printf("\n 3) Verificar se um elemento x existe");
        printf("\n 4) Contar o numero de elementos na arvore ");
        printf("\n 5) Imprimir os nós folhas da arvoree");
        printf("\n 6) Verificar se uma arvore esta balanceada ");
        printf("\n 7) Verificar se uma arvore eh cheia");
        printf("\n 8) Imprimir o nivel de um no x");
        printf("\n 9) Sair");
        printf("\n\t Digite uma opcao: ");
        scanf("%d", &opcoes);
        switch(opcoes){
            case 1:              //Ler Arvore
               printf("Digite o endereco do arquivo: ");
                fflush(stdin);

                fgets(endereco,30,stdin);
                fflush(stdin);
                
                if(endereco[strlen(endereco)-1] == '\n') endereco[strlen(endereco)-1] ='\0';
                arq = fopen (endereco,"r");
                a = LerArvore(arq);

                if(arq != NULL) 
                    printf("Arvore lida com sucesso\n");
                else 
                    printf("Arvore nao leu!\n");
                fflush(stdin);
                fclose(arq);
            break;
            case 2:                                                                         //Imprimir Arvore
               while(imprimir != 5){
                    printf("1 - Imprimir pre Ordem:\n");
                    printf("2 - Imprimir em Ordem:\n");
                    printf("3 - Imprimir pos Ordem:\n");
                    printf("4 - Imprimir em Largura:\n");
                    printf("5 - Sair:\n");
                    printf("Como deseja imprimir a arvore: \n");
                    scanf("%d",&imprimir);
                    if(imprimir == 1)
                        ImprimirPreOrdem(a);
                    else if(imprimir == 2)
                        ImprimirEmOrdem(a);
                    else if(imprimir == 3)
                        ImprimirPosOrdem(a);
                    else if(imprimir == 4)
                        ImprimirEmLargura(a);     
                }
            break;
            case 3:                                                                             //Verificar se um elemento x existe
                printf("Elemento:");
                scanf("%d",&elemento);
                int existe = Existir(a, elemento);
                if(existe == 1)
                    printf("Elemento existe na arvore");
                else 
                    printf("Elemento nao existe na arvore");
            break;
            case 4:                                                                              // Contar o numero de elementos na arvore
                int Contar = ContarArvore(a);
                if(Contar != NULL )
                    printf("Essa arvore tem %d elementos",Contar);
                else
                     printf("Essa arvore esta vazia");
                break;
            case 5:                                                                              //Imprimir os nós folhas da árvore 
                ImprimirFolha(a);
            break;
            case 6:                                                                              //Verificar se uma arvore está balanceada
                int balanceada = Balanceada(a);
                if(balanceada == 1)
                    printf("Arvore balanceada");
                else 
                    printf("Arvore não balanceada");
            break;
            case 7:                                                                             //Verificar se uma árvore é cheia
               int cheia = ArvoreCheia(a);
               if(cheia == 1)
                   printf("Arvore cheia!");
               else    
                    printf("Arvore não cheia");
            break;
            case 8:                                                                             //Imprimir o nível de um nó x
                printf("Qual elemento deseja saber o nivel?");
                scanf("%d", &x);
                int existe = Existir(a, x);
                if(x == 1){
                    ImprimirNo(a, x, 0);
                }else 
                    printf("elemento não existe"); 
            break;
            case 9:                                                                             // Sair
                printf("\n Obrigado por usar o programa ! \n");       
                a = Destruir(a);          
            break;
            default:
                printf("Digite uma opção valida!");                                      
            break;
        }
    }
}