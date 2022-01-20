#include<stdio.h>
#include<stdlib.h>
#include"Pessoas.h"
#define N 15
#define PROF 1
#define ALUNO 2

int main(){
    Pessoa p = CriaLista(p);
    Prof  *m;
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