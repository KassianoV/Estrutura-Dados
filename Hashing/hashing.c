#include<stdio.h>
#include<stdlib.h>
#define N 11

typedef struct registro{
    int info;
    int disponibilidade;
    void *item;
}*Registro;

int hash(int key, int size){
    return key % size;
}

void inicializar(char *nomeArq){
    FILE *arq = fopen(nomeArq, "wb");
    Registro a = (Registro) malloc(sizeof(struct registro));
    int i;
    a->disponibilidade = 1;
    for(i=0; i<N; i++)
        fwrite(&a, sizeof(Registro), 1,arq);
    fclose(arq);    
}

 AcharPosicao(char * nomeArq, int x){
    FILE *arq = fopen(nomeArq, "rb");
    int pos = hash(x,N);

    Registro aux = (Registro) malloc(sizeof(struct registro));

    fseek(arq, pos * sizeof(Registro), SEEK_SET);
    fread(aux, sizeof(Registro), 1, arq);

    while(aux->disponibilidade == 0){
        pos = (pos+1)%N;
        fseek(arq, pos*sizeof(Registro),SEEK_SET);
        fread(&aux, sizeof(Registro), 1,arq);
    }
    fclose(arq);
    return pos;
}

void inserir(char *nomeArq, int x, void*obj){
    int pos = AcharPosicao(nomeArq, x);
    FILE *arq = fopen(nomeArq, "r+b");
    Registro a = (Registro) malloc (sizeof(Registro));

    a->info = x;
    a->disponibilidade = 0;
    a->item = obj;

    fseek(arq, pos * sizeof(Registro), SEEK_SET);
    fwrite(&a, sizeof(Registro), 1, arq);
    fclose(arq);
}

void ImprimirArquivo(char *nomeArq){
    FILE *arq = fopen(nomeArq, "rb");
    Registro a = (Registro) malloc(sizeof(Registro));
    int i;
    for (i=0;i<N;i++){
        fread(a,sizeof(Registro),1,arq);
        if(a->disponibilidade =0)
            printf("Matricula: %d\n", a->info);
        else    
            printf("Espaco %d esta disponivel\n",i);
    }
    fclose(arq);
}

typedef struct aluno{
	int matricula;
	char nome[150];
	char email[150];
	float CR;
}*Aluno;

int BuscarObj(char *nomeArq, int key, void *obj){
	FILE *arq=fopen(nomeArq,"rb");
	Registro reg=(Registro) malloc(sizeof(struct registro));
	
	int pos=hash(key,N);
	fseek(arq,pos*sizeof(struct registro),SEEK_SET);

	fread(reg,sizeof(struct registro),1,arq);
	if(reg->info==key){
		obj=reg->info;
		return 1;
	}else{
		int vrf=0;
		for(int i=pos;i<N;i++){
			fread(reg,sizeof(struct registro),1,arq);
			if(reg->disponibilidade==0){
				obj=reg->info;
				return 1;
			}
			if(pos==N-1 && vrf==0){
				pos=0;
				vrf=1;
			}
		}
	}
	return 0;
}
Aluno CriaAluno(){
	Aluno a=(Aluno) malloc(sizeof(struct aluno));

	getchar();
	printf("\nDigite o nome do aluno: ");
	fgets(a->nome,150,stdin);
	
	if(a->nome[strlen(a->nome)-1]=='\n')
		a->nome[strlen(a->nome)-1]='\0';

	printf("\nDigite o email do aluno: ");
	fgets(a->email,150,stdin);

	if(a->email[strlen(a->email)-1]=='\n')
		a->email[strlen(a->email)-1]='\0';

	printf("\nDigite a matricula do aluno: ");	
	scanf("%d",&a->matricula);

	printf("\nDigite o CR do aluno: ");
	scanf("%f",&a->CR);

	return a;
}

int menu(){
	int opc=0;		
	printf("\nEscolha uma opcao\n"); 
	printf("[1] Inserir um novo aluno\n");
	printf("[2] Imprimir as informações de um determinado aluno\n");
	printf("[3] Imprimir a tabela de dispersao\n");
	printf("[4] Sair\n");
	scanf("%d",&opc);
	return opc;
}

int main(){
	int opc=0,mat;
	Aluno al;
	char nomeArq[15];
	strcpy(nomeArq,"registro.bin");
	Inicializar(nomeArq);

	while(opc!=4){
		opc=menu();
		switch(opc){
			case 1:
				al=CriaAluno();
				Inserir(nomeArq,al->matricula,al);
				break;
			case 2: printf("Digite o numero da matricula do aluno: ");
				scanf("%d",&mat);

				if(BuscarObj(nomeArq,mat,al)==1){
					al=(Aluno) al;
					printf("O nome do aluno eh %s\nO email do aluno eh %s\nA matricula do aluno eh %d\nO CR do aluno eh %.2f",al->nome,al->email,al->matricula,al->CR);
				}else{
					printf("O aluno nao esta na lista\n");
				}
				break;
			case 3:
				ImprimirArquivo(nomeArq);
				//Imprimir tabela hash
				break;
			case 4:
				//Sair
				break;
			default:
				printf("\nPor favor digite uma opcao valida[1-4]\n");
		}
	}
	return 0;
}