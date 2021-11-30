#include<stdio.h>
#include<stdlib.h>

//Extrutura Base
typedef struct lista{
	int info;
	struct lista *prox;
}lista;

//1 - somar todos os elementos da lista
int Somar(lista *l){
	if(l == NULL)
		return 0;
	else{
		int num;
		num = num + Somar(l->prox);	 
		return num;
	}
}

//2- Contar o numero de ocorrencias de um elemento na lista
int ContarOcorrencias(lista *l, int x){
	int num = 0;
	if(l == NULL)
		return 0;
	else if(l->info == x){
		num++;
		return num += ContarOcorrencias(l->prox, x);
	}else
		return 0;
}

//3 - Remover um elemento x da lista, pode supor que o elemento existe na lista
int Remover(lista *l, int num){
	if(l != NULL){
		if(l->info == num){
			lista *aux = l->prox;
			free(l);
			return aux;
		}else
			l->prox = Remover(l->prox,num);
	}
	return 1;				
}