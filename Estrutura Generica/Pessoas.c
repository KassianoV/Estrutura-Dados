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

Pessoa *CriaLista(Pessoa *p){
        p->tipo = 0;
        p->item = NULL;
        p->prox = NULL;
}

Pessoa *Inserir(Pessoa *p, void *info, int tipo){
    Pessoa *novo = (Pessoa *) malloc (sizeof(Pessoa));
    if(p->tipo == PROF){
        novo->tipo = tipo;
        novo->item = info;
    }else if(p->tipo == ALUNO){
        novo->tipo = tipo;
        novo->item = info;
    }
    novo->prox = NULL;
    return novo;
}

Pessoa *RemoverMatricula(Pessoa *p, int mat){
    Pessoa *aux = p;
    if(aux != NULL){
        while (aux != NULL){
            if(aux->tipo == ALUNO){
                Aluno *a = (Aluno *) aux->item;
                if(a->matricula == mat){
                    free(aux->item);
                    free(aux);
                }
                aux->prox = RemoverMatricula(p->prox,mat);
            }
            else if(aux->tipo == PROF){
                Prof *m= (Prof *) aux->item;
                if(m->matricula == mat){
                    free(aux->item);
                    free(aux);
                }
                aux->prox = RemoverMatricula(p->prox,mat);
            }
        }
    }  
    if(aux == NULL){
            printf("matricula nao encotrada!!!");
            return p;    
    } 
}

Pessoa *BuscarMatricula(Pessoa *p, int tam, int mat){
    int i;
    for(i=p;i==NULL;i=p->prox){
        if(p->tipo == PROF){
            Prof *m = (Prof *) p->item;
            if(m->matricula == mat){
                printf("nome: %s\n",m->nome);
            } 
        }else if(p->tipo == ALUNO){
            Aluno *a = (Aluno *) p[i].item;
            if(a->matricula == mat){
                printf("nome: %s\n",a->nome);
            }
        }
    }
}

int ContarCurso(Pessoa *p, int tam,char *curso){
    int i;
    int cont = 0;

    for(i=p;i==NULL;i=p->prox){
        if(p->tipo == ALUNO){
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
    for(i=p;i==NULL;i=p->prox){
        if(p[i].tipo == PROF){
            Prof *m = (Prof *) p[i].item;
            if(m->salario > sal)
                sal = m->salario;
        }
    }
   for(i=p;i==NULL;i=p->prox){
        if(p[i].tipo == PROF){
            Prof *m = (Prof *) p[i].item;
            if(m->salario == sal)
                printf("nome: %s\n",m->nome);
        }
    }
}

void LiberaLista(Pessoa *p){
    int i;
    for(i=p;i==NULL;i = p->prox){
        free(p->item);
    }
}

int main(){
    Pessoa *p = CriaLista(p);
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
        switch (opcao){
        case 1:
            printf("Qual pessoa quer inserir ?");
            scanf("%d", &tipo);
            if(tipo == PROF){
                printf("Digite a matricula: ");
                scanf("%d\n",&m->matricula);
                printf("Digite a nome: ");
                scanf("%s", &m->nome);
                printf("Digite salario: ");
                scanf("%f\n",&m->salario);
                p = Inserir(p,m,PROF);
            }else if(tipo == ALUNO){
                printf("Digite a matricula: ");
                scanf("%d\n",&a->matricula);
                printf("Digite a nome: ");
                scanf("%s", &a->nome);
                printf("Digite a curso: ");
                scanf("%s", &a->curso);
                printf("Digite ano: ");
                scanf("%f\n",&a->anoIni);
                p = Inserir(p,a,ALUNO);
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
            scanf("%s",&c);
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