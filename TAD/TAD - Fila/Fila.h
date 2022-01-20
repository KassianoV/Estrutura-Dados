#ifndef  Fila_H
#define Fila_H

typedef struct fila *Fila;
Fila CriaFila (Fila f);
int Inserir(Fila f, int num);
int  Remover (Fila f);
void ImprimirFila(Fila f);

#endif