#ifndef  Pessoa_H
#define Pessoa_H

typedef struct professor *Prof;
typedef struct aluno *Aluno;
typedef struct pessoa *Pessoa;
Pessoa *CriaLista(Pessoa p);
Pessoa *Inserir(Pessoa p, void *info, int tipo);
Pessoa *RemoverMatricula(Pessoa p, int mat);
Pessoa *BuscarMatricula(Pessoa p, int tam, int mat);
int ContarCurso(Pessoa p, int tam,char *curso);
void MaiorSalario(Pessoa p, int tam, int sal);
void LiberaLista(Pessoa p);

#endif