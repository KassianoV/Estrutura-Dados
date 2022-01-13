#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

#define N 15
#define PROF 1
#define ALUNO 2

typedef struct professor{
    int matricula;
    char nome[100];
    float salario;
}Prof;

typedef struct aluno{
    int matricula;
    char nome[100];
    char curso[100];
    int anoIni;
}Aluno;

typedef struct pessoa{
    int tipo;                   // 1 = professor e 2 = aluno
    void *item;
    struct pessoa *prox;
}Pessoa;

void Inicializar(Pessoa *p, int tam){
    int i;
    for(i=0;i<tam;i++){
        p[i].tipo = 0;
        p[i].item = NULL;
    }
}

Pessoa *CriaPessoa(int tipo, void *item){
    Pessoa *novo = (Pessoa *) malloc(sizeof(struct pessoa));
    if(tipo == PROF){
        novo->tipo = 1;
        novo->item = item;
    }else if(tipo == ALUNO){
        novo->tipo = 2;
        novo->item =item;
    }
    novo->prox = NULL;
    return novo;
}

void Inserir(Pessoa *p, void *info, int tipo){
    Pessoa *aux = CriaPessoa(tipo,info);
    aux->prox = p;
    return aux;
}

void RemoverMatricula(Pessoa *p, int mat){
    if(p != NULL){
        Pessoa *aux = p;
        Pessoa *ant = NULL;

        while (aux != NULL){
            if(aux->tipo == ALUNO){
                Aluno *a = (Aluno *) aux->item;
                if(a->matricula == mat){
                    free(a);
                    break;}
            }
            else if(aux->tipo == PROF){
                Prof *m= (Prof *) aux->item;
                if(m->matricula == mat){
                    free(m);
                    break;}
            }
            ant = aux;
            aux =  aux->prox;
        }
        if(aux == NULL){
            printf("matricula nao encotrada!!!");
            return p;    
        }
    }   
}

void BuscarMatricula(Pessoa *p, int tam, int mat){
    int i;
    for(i=0;i<tam;i++){
        if(p[i].tipo == PROF){
            Prof *m = (Prof *) p[i].item;
            if(m->matricula == mat){
                printf("nome: %s\n",m->nome);
                printf("matricula: %d\n",m->matricula);
                printf("salario: %.2f",m->salario);
            }   
        }else if(p[i].tipo == ALUNO){
            Aluno *a = (Aluno *) p[i].item;
            if(a->matricula == mat){
                printf("nome: %s\n",a->nome);
                printf("matricula: %d\n",a->matricula);
                printf("salario: %.s\n",a->curso);
                printf("ano de inicio: %d\n",a->anoIni);
            }
        }
    }
}

int ContarCurso(Pessoa *p, int tam,char *curso){
    int i;
    int cont = 0;

    for(i=0;i<tam; i++){
        if(p[i].tipo == ALUNO){
            Aluno *a = (Aluno *) p[i].item;
            if(strcmp(a->curso,curso) == 0)
                cont++;
        }
    }
    return cont;
}
void MaiorSalario(Pessoa *p, int tam, int sal){
    sal = 0;
    int i;
    for(i=0;i<tam;i++){
        if(p[i].tipo == PROF){
            Prof *m = (Prof *) p[i].item;
            if(m->salario > sal)
                sal = m->salario;
        }
    }
    for(i=0;i<tam;i++){
        if(p[i].tipo == PROF){
            Prof *m = (Prof *) p[i].item;
            if(m->salario == sal)
                printf("nome: %s\n",m->nome);
        }
    }
}

void LiberaLista(Pessoa *p){
    int i;
    for(i=0;i<N;i++){
        free(p[i].item);
    }
}

int main(){
    Pessoa p[N];
    inicializar(p, N);
    Prof *m;
    m = (Prof*) malloc(sizeof(Prof));
    Aluno *a;
    a = (Aluno*) malloc(sizeof(Aluno));
    int pos,tipo,mat,sal;
    char c[100];
    pos = 0;
    int opcao;

    printf("\tMenu:\n");
    printf("1-Inserir\n 2-Remover pela matricula\n3-Buscar matricula\n 4-Contar alunos de curso\n 5-Professor maior salário\n 6 - Sair\n ");
    while(opcao != 6){
        switch (opcao)
        {
        case 1:
            printf("Qual pessoa quer inserir ?");
            scanf("%d", &tipo);
            if(tipo == PROF){
                printf("Digite a matricula: ");
                scanf("%d\n",&m->matricula);
                printf("Digite a nome: ");
                gets(m->nome);
                printf("Digite salario: ");
                scanf("%f\n",&m->salario);
                Inserir(p,m,PROF);
            }else if(tipo == ALUNO){
                printf("Digite a matricula: ");
                scanf("%d\n",&a->matricula);
                printf("Digite a nome: ");
                gets(a->nome);
                printf("Digite a curso: ");
                gets(a->curso);
                printf("Digite ano: ");
                scanf("%f\n",&a->anoIni);
                Inserir(p,a,ALUNO);
            }
            break;
        case 2:
            printf("Qual matricula quer remover?");
            scanf("%d", &mat);
            RemoverMatricula(p,mat);
            break;

        case 3:
            printf("Qual matricula deseja ver as informacoes");
            scanf("%d",&mat);
            BuscarMatricula(p, N, mat);
            break;

        case 4:
            printf("Qual curso deseja ver? ");
            gets(c);

            ContarCurso(p,N, c);
            break;
        case 5:
            printf("Professor(es) com maior(es) salarios:");
            MaiorSalario(p,N,sal);
            break;
        case 6:
            printf("Saindo...");
            LiberaLista(p);
            break;
        }
    }
}