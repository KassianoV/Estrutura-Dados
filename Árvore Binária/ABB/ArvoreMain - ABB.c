#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>
#include"ArvFuncoes.h"

int main(){
    ARVORE *a = inicia_arv();
    int opcoes;
    char endereco[50];
    int imprimir, elemento, nivel, existe;
    FILE *arq;
    
    while(opcoes != 8){
        printf("\t\t\t Menu: (Escolha um numero )");
        printf("\n 1) Ler Arvore");
        printf("\n 2) Imprimir Arvore");
        printf("\n 3) Verificar se um elemento x existe");
        printf("\n 4) Imprimir Nivel de um No");
        printf("\n 5) Imprimir as folhas menores que um No");
        printf("\n 6) Inserir um No ");
        printf("\n 7) Remover um No x da arvore");
        printf("\n 8) Sair");
        printf("\n\t Digite uma opcao: ");
        scanf("%d", &opcoes);
        switch(opcoes){
            case 1:                                                                            //Ler Arvore Binaria fornecida pelo usúario     
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
                    printf("Arrvore nao leu!\n");
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
                existe = Existir(a, elemento);
                if(existe == 1)
                    printf("Elemento existe na arvore");
                else 
                    printf("Elemento nao existe na arvore");
            break;
            case 4:                                                                              // Imprimir nivel de um No       
                printf("Qual No deseja imprimir o nivel?");
                scanf("%d",&elemento);
                nivel = NivelNo(a, elemento); 
                printf("Nivel: %d",nivel);
            break;
            case 5:                                                                              //Imprimir as folhas menores que um valor x
                printf("Deseja imprimir valores menores que ?");
                scanf("%d", &elemento);
                ImprimirFolhaMenor(a,elemento);
            break;
            case 6:                                                                              //Inserir um No x na arvore
               printf("Qual No deseja inserir na arvore?");
               scanf("%d",&elemento);
               a = Inserir(a,elemento);
            break;
            case 7:                                                                             //Remover um No x da arvore   ver antes se o no existe  antes de remover .
                printf("Qual No deseja remover?");
                scanf("%d", &elemento);
                existe = Existir(a, elemento);
                if(existe == 1)
                     a = RemoverNo(a, elemento);
                else 
                    printf("Elemento nao existe na arvore");
            break;
            case 8:                                                                             // Sair
                printf("\n Obrigado por usar o programa ! \n");   
                a = Destruir(a);
            break;
            default:
                printf("Digite uma opção valida!");                                      
             break;
        }
    }
}