#ifndef ARVFUNCOES_H_INCLUDED
#define ARVFUNCOES_H_INCLUDED

typedef struct ARVORE **ARVORE;
ARVORE  *inicia_arv();
ARVORE *LerArvore(FILE *arq);
void ImprimirPreOrdem(ARVORE *a);
void ImprimirEmOrdem(ARVORE *a);
void ImprimirPosOrdem(ARVORE *a);
void ImprimirEmLargura(ARVORE *a);
int Existir (ARVORE *a, int x);
int NivelNo(ARVORE *a, int x);
void ImprimirFolhaMenor(ARVORE *a, int x);
ARVORE *Inserir(ARVORE *a, int x);
ARVORE *RemoverNo(ARVORE *a, int x);
ARVORE *Destruir (ARVORE *a);

#endif
