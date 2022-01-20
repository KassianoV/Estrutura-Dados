#include<stdio.h>
#include<stdlib.h>
#define N 11

typedef struct aluno{
    int matricula;
    char nome[50];
    char curso[50];
}Aluno;

int hash1(int key, int size){
    key = key % 100;
    return key % size;
}

int hash2(int key, int size){
    return size-2-(key%(size-2));
}

typedef struct registro{
    int info;
    int disponibilidade;
}registro;

void inicializar(char *nomeArq){
    FILE *arq = fopen(nomeArq, "wb");
    registro a;
    int i;
    a.disponibilidade = 1;
    for(i=0; i<N; i++)
        fwrite(&a, sizeof(registro), 1,arq);
    fclose(arq);    
}

int AcharPosicao(char * nomeArq, int x){
    int pos = hash1(x);
    registro a;

    FILE *arq = fopen(nomeArq, "rb");
    fseek(arq, pos * sizeof(registro), SEEK_SET);
    fread(&a, sizeof(registro), 1, arq);

    while(a.disponibilidade == 0){
        pos = (pos+1) % N;
        fseek(arq, pos *sizeof(registro), SEEK_SET);
        fread(&a, sizeof(registro), 1, arq);
    }
    fclose(arq);
    return pos;
}

void inserir(char *nomeArq, int x){
    int pos = AcharPosicao(nomeArq, x);
    FILE *arq = fopen(nomeArq, "r+b");
    registro a;

    a.info = x;
    a.disponibilidade = 0;

    fseek(arq, pos * sizeof(registro), SEEK_SET);
    fwrite(&a, sizeof(registro), 1, arq);
    fclose(arq);
}
int BuscarAlu
no(Aluno *a, int mat){
    if(a != NULL){
        if(a->matricula == mat)
            return 1;
        else 
            return 0;
    }
    return 0;
}


int main (){
    
}

