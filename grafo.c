#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include"funcaoGrafo.h"

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
    while(opcoes != 9){
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
                
            break;

            case 7:
             
            break;

            case 8:
             
            break;

            case 9:
            printf("Saindo...");
            destruirLista(g);
            break;

            default:
                printf("Digite outro numero");
            break;
        }
    }
    
}