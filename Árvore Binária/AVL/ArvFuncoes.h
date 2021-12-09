#ifndef ARVFUNCOES_H_INCLUDED
#define ARVFUNCOES_H_INCLUDED
#endif //ARVFUNCOES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Estrutura da Árvore
typedef struct ARVORE  {
    int info;
    int FB;
    struct ARVORE *esq; 
    struct ARVORE *dir;
}ARVORE;

// Árvore vazia
ARVORE *inicia_arv(){
    return NULL;
}

//Criar Árvore
ARVORE *CriaNo(int num){
    ARVORE *a = (ARVORE*)malloc(sizeof(ARVORE));
    a->info = num;
    return a;
}

void AjustarFB(ARVORE *a){
    if(a != NULL){
        int he = Altura(a->esq);
        int hd = Altura(a->dir);
        a->FB = hd - hd;

        AjustarFB(a->esq);
        AjustarFB(a->dir);
    }
}

//1 - Ler uma árvore de um arquivo fornecido pelo usuário
ARVORE *LerArvore(FILE *arq){
    char c;
    int num;

    fscanf(arq,"%c",&c);  // Ler '('
    fscanf(arq,"%d",&num); // Ler a raiz

    if(num == -1){  //se num for == -1 quer dizer que não tem valor, É NULL
        fscanf(arq,"%c",&c);  //Ler ')'
        return NULL;
    }else{
        ARVORE *a = CriaNo(num);

        a->esq = LerArvore(arq);  // Sub.arq
        a->dir = LerArvore(arq);  // Sub.dir

        fscanf(arq,"%c",&c);   //Ler')'
        AjustarFB(a);
        return a; 
    }
}

//Altura da Árvore
int Altura(ARVORE *a){
    if(a == NULL)
        return 0;
    else {
        int he = Altura(a->esq);
        int hd = Altura(a->dir);
        if(he>hd)  
            return he + 1;    
        else                       // Raiz 
            return hd + 1;
    }
}

void ImprimirNivel(ARVORE *a, int cont, int nivel){
     if(a != NULL){                // NULL?
        if(cont == nivel)
            printf("%d",a->info);  // Raiz
        else{
            ImprimirNivel(a->esq,cont+1,nivel);
            ImprimirNivel(a->dir,cont+1,nivel);
        }
     }
}

//2 - Imprimir a árvore (opções: pré-ordem; em-ordem; pós-ordem; e em largura) ok
void ImprimirPreOrdem(ARVORE *a){
    if(a != NULL){
        printf("%d ",a->info);         // Raiz
        ImprimirPreOrdem(a->esq);     //SubArvore esquerda
        ImprimirPreOrdem(a->dir);     //SubArvore Direita
    }
    printf("\n");
}

void ImprimirEmOrdem(ARVORE *a){
    if(a != NULL){
        ImprimirEmOrdem(a->esq);     //SubArvore esquerda
        printf("%d ",a->info);   // Raiz
        ImprimirEmOrdem(a->dir);     //SubArvore Direita
    }
    printf("\n");
}

void ImprimirPosOrdem(ARVORE *a){
    if(a != NULL){
        ImprimirPosOrdem(a->esq);     //SubArvore esquerda
        ImprimirPosOrdem(a->dir);     //SubArvore Direita
        printf("%d ",a->info);    // Raiz
    }
    printf("\n");
}

void ImprimirEmLargura(ARVORE *a){
    if(a != NULL){
        int i;
        int h = Altura(a);
        for(i=0; i<h; i++){
            ImprimirNivel(a, 0,i);
            printf("\n");
        }
    }
    printf("\n");
}

// Imprimir Maiores ou Igual 
void ImprimirMaioresIguais(ARVORE *a, int x){
    if(a != NULL){
        if(a->info >= x){
            printf("%d ", a->info);
            ImprimirMaioresIguais(a->esq,x);
            ImprimirMaioresIguais(a->dir,x);
        }
        else   
             ImprimirMaioresIguais(a->dir,x);
    }
    printf("\n");
}

void ImprimirEntreXeY(ARVORE *a, int x,int y){
    if(a != NULL)
        if(a->info <= x)
            ImprimirEntreXeY(a->dir, x, y);
        else if(a->info >= x)
            ImprimirEntreXeY(a->esq, x, y);
        else {
            printf("%d", a->info);
            ImprimirEntreXeY(a->esq, x, y);
            ImprimirEntreXeY(a->dir, x, y);
        }
}

//3 - Verificar se um elemento x existe na árvore
int Existir (ARVORE *a, int x){
    if(a==NULL)
        return 0;
    else if (x == a->info)
        return 1;
    else if(x < a->info)
       return Existir(a->esq,x);
    else
        return Existir(a->dir,x);
}

//5.1 - Imprimir os nós folhas da árvore 
void ImprimirFolha(ARVORE *a){
    if(a != NULL){
        if(a->esq == NULL  &&  a->dir ==NULL )
            printf("%d ",a->info);
    }
    ImprimirFolha(a->esq);
    ImprimirFolha(a->dir);
    printf("\n");
}

//5.2 - Imprimir as folhas menores que um valor x
void ImprimirFolhaMenor(ARVORE *a, int x){
    if(a != NULL){
        if(a->info < x){
            if(a->esq == NULL  &&  a->dir ==NULL )
                printf("%d ",a->info);
            ImprimirFolhaMenor(a->esq, x);
            ImprimirFolhaMenor(a->dir, x);
        } else
            ImprimirFolhaMenor(a->esq, x);
    }
    printf("\n");
}


//6.1 - Verificar se uma arvore está balanceada
int Balanceada(ARVORE *a){
    if(a==NULL) 
        return 1;
    else {
        if(Balanceada(a->esq) == 0 || Balanceada(a->dir) == 0)
            return 0;
        else{
            int he = Altura(a->esq);
            int hd = Altura(a->dir);
            if( abs(he-hd) >1 )
                return 0;
            else
                return 1;
        }
    }
}

//4.1 - Contar Arvore
int ContarArvore(ARVORE *a){
	if(a == NULL)
		return 0;
	else 
        return 1+ContarArvore(a->esq) + ContarArvore(a->dir);
}

//7.1 - Verificar se uma árvore é cheia
int ArvoreCheia(ARVORE *a){
    if(ContarArvore(a) == (pow(2,Altura(a))-1)) 
        return 1;
    else   
        return 0;
}

//4.2 - Verificar  o nível de um nó x
int NivelNo(ARVORE *a, int x){
    if(x == a->info)
        return 0;
    else if(x < a->info)   
        return NivelNo(a->esq,  x) +1;
    else 
        return NivelNo(a->dir,  x) +1;
}
//5.1 - Imprimir o nível de um nó x
void ImprimirNo(ARVORE *a, int No,int nivel){
    if(a!=NULL){
        if(No == a->info  )
            printf("%d", nivel);
        else if (No < a->info)
            ImprimirNo(a->esq, No,nivel+1);
        else 
            ImprimirNo(a,No,nivel+1);  
    }
    printf("\n");
}
// Rotação a esquerda geral
ARVORE *RotacaoEsq(ARVORE *a){
    if(a->dir->FB == -1)
        a = RotacaoEsqDupla(a);
    else 
        a = RotacaoEsqSimples(a);
    return a;
}

//Rotação a esquerda simples
ARVORE *RotacaoEsqSimples(ARVORE *arv){
    // Os nós 'c' e 'b' serão aqueles com FB modificado
    ARVORE *c = arv;
    ARVORE *b = c->dir;

    c->dir = b->esq;
    b->esq = c;
    if(b->FB == 1){
        c->FB = 0;
        b->FB = 0;
    }else {
        c->FB = 1;
        b->FB = -1;
    }
    arv = b;
    return arv;
}

//Rotação a esquerda dupla
ARVORE *RotacaoEsqDupla(ARVORE *arv){
    // Os nós 'a','b','c' serão aqueles com FBs modificado
    ARVORE *a = arv;
    ARVORE *c = a->dir;
    ARVORE *b = c->esq; // O nó b será a nova raiz

    c->esq = b->dir;
    a->dir = b->esq;
    b->esq = a;
    b->dir = c;

    // Setando os valores dos FBs de acordo com FB da nova raiz.
    switch (b->FB){
        case  -1:
            a->FB = 0;
            c->FB = 1;
        break;
        
        case  0:
            a->FB = 0;
            c->FB = 0;
        break;

        case  +1:
            a->FB = -1;
            c->FB = 0;
        break;
    }
    b->FB = 0;
    arv = b;
    return arv;
}

//Rotação a direita geral 
ARVORE *RotacaoDir(ARVORE *arv){
    if(arv->esq->FB == 1)
        arv = RotacaoDirDupla(arv);
    else 
        arv = RotacaoDirSimples(arv);
    return arv;
}

//Rotação a direita simples
ARVORE *RotacaoDirSimples(ARVORE *arv){
    //Os nós 'a' e 'b' serão aqueles com FB modificados.
    ARVORE *a = arv->esq;
    ARVORE *b = arv;

    b->esq = a->dir;
    a->dir = b;
    if(a->FB == -1){
        a->FB = 0;
        b->FB = 0;
    }else {
        a->FB = 1;
        b->FB = -1;
    }
    arv = a;
    return arv;
}

// Rotação a direita dupla 
ARVORE *RotacaoDirDupla(ARVORE *arv){
    // Os nós 'a','b','c' serão aqueles com FBs modificados.
    ARVORE *c = arv;
    ARVORE *a = c->esq;
    ARVORE *b = a->dir;

    c->esq = b->dir;
    a->dir = b->esq;
    b->esq = a;
    b->dir = c;

    //Setando os valores dos FBs de acordo com FB da nova raiz.
    switch (b->FB)
    {
        case -1:
            a->FB = 0;
            c->FB = 1;
        break;
    
        case 0:
            a->FB = 0;
            c->FB = 0;
        break;

        case +1:
            a->FB = -1;
            c->FB = 0;
        break;
    }
    b->FB = 0;
    arv = b;
    return arv;
}

//6.2 - Inserir elemento na Árvore
ARVORE *Inserir(ARVORE *a, int x, int *hMudou){
    if(a == NULL){
        a = CriaNo(x);
        a->esq = NULL;
        a->dir = NULL;
        a->FB = 0;
        *hMudou = 1;
    }
    else if(x <= a->info){
        a->esq = Inserir(a->esq,x, hMudou);
        if(*hMudou == 1){
            switch(a->FB){
                case -1:
                    a = RotacaoDir(a);
                    *hMudou = 0;
                break;

                case 0:
                    a ->FB = -1;
                    *hMudou = 1;
                break;

                case +1:
                    a ->FB = 0;
                    *hMudou = 0;
                break;
            }
        }
    } 
    else {
        a->dir = Inserir(a->dir,x,hMudou);
        if(*hMudou == 1){
            switch (a->FB) {
                case -1:
                    a->FB = 0;
                    *hMudou = 0;
                break;
            
                case 0:
                    a->FB = +1;
                    *hMudou = 1;
                break;

                case +1:
                    a = RotacaoEsq(a);
                    *hMudou = 0;
                break;
            }
        }
    }
    return a;
}

//Contar Niveis 
int ContarNivel(ARVORE *a, int cont, int n){
    if(a==NULL )
        return 0;
    else    
        if(cont == n)
            return 1;
        else
            return ContarNivel(a->esq,cont+1,n)+ContarNivel(a->dir,cont+1,n);
}

// Destruir Arvore
ARVORE *Destruir (ARVORE *a){
    if(a != NULL){
        a->esq = Destruir(a->esq);
        a->dir = Destruir(a->dir);
        free(a);
    } 
    return NULL;
}

//Remover um nó da árvore
ARVORE *Remover (ARVORE *a, int x, int *hMudou) { 
    if(a != NULL){
        if(a->info == x){
            //Verificar se é folha 
            if(a->esq == NULL && a->dir == NULL){
                free(a);
                *hMudou = 1;
                return NULL;
            }
            //Verificar se um dos filhos é nulo
            else if(a->esq == NULL || a->dir == NULL){
                ARVORE *aux;
                if(a->esq == NULL)
                    aux = a->dir;
                else 
                    aux = a->esq;
                free(a);
                *hMudou = 1;
                return aux;
            }
            //Nenhum filho nulo
            else {
                ARVORE *maiorEsq = a->esq;
                while(maiorEsq->dir != NULL)
                    maiorEsq = maiorEsq->dir;
                
                a->info = maiorEsq->info;
                a->esq = Remover(a->esq, a->info, hMudou);

                if(*hMudou == 1){
                    switch (a->FB){
                        case -1:
                            a->FB = 0;
                            *hMudou = 1;
                        break;

                        case 0:
                            a->FB = 1;
                            *hMudou = 0;
                        break;

                        case +1:{
                            int aux = a->dir->FB;
                            a = RotacaoEsq(a);

                            if(aux == 0)
                                *hMudou = 0;
                            else 
                                *hMudou = 1;
                        break;
                        }
                    }
                }
            }
        }
        else if(x < a->info){
            a->esq = Remover(a->esq, x, hMudou);
            if(*hMudou == 1){
                switch (a->FB){
                    case -1:
                        a->FB = 0;
                        *hMudou = 1;
                    break;

                    case 0:
                        a->FB = 1;
                        *hMudou = 0;
                    break;

                    case +1:{
                        int aux = a->dir->FB;
                        a = RotacaoEsq(a);

                        if(aux == 0)
                            *hMudou = 0;
                        else 
                            *hMudou = 1;
                    break;
                    }
                }
            }
        }
        else {
            a->dir = Remover(a->dir, x, hMudou);

            if(*hMudou == 1){
                switch (a->FB) {
                    case +1:
                        a->FB = 0;
                        *hMudou =1;    
                    break;

                    case 0:
                        a->FB = -1;
                        *hMudou = 0;    
                    break;
                
                    case -1:
                        int aux = a->esq->FB;
                        a = RotacaoDir(a);

                        if(aux == 0)
                            *hMudou = 0;
                        else 
                            *hMudou = 1;
                    break;
                    
                }
            }
        }
    }
    return a;
} 