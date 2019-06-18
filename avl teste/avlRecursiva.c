#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#define ESQUERDA 1
#define DIREITA 2

struct no{
    int valor;
    No *esq;
    No *dir;
    int fatorBal;//altura da sub-arvore;
};

struct arvore{
    No *raiz;
};


Arvore* criarArvore(){
    Arvore *a = (Arvore*) malloc(sizeof(Arvore));
    a->raiz = NULL;
    return(a);
}

Arvore* inserirA(Arvore *a, int valor){
    No *aux = a->raiz;
    aux = inserirArvore(aux, valor);
    a->raiz = aux;
    return a;
}
Arvore* removerA(Arvore *a, int valor){
    No *aux = a->raiz;
    aux = removerArvore(aux, valor);
    a->raiz = aux;
    return a;
}

int vaziaArvore(No *no){
    if(no == NULL)
        return 1;
    else
        return 0;
}

int cheiaArvore(No *no){
    return 0;
}

void imprimir_no(No *n, int ordem){
    //pre ordem
    if(ordem == 1){
        if (n != NULL) {
            printf(" -%d- ", n->valor);
            imprimir_no(n->esq, 1);
            imprimir_no(n->dir, 1);
        }
    }
    
    //in ordem
    if(ordem == 2){
        if (n != NULL) {
            imprimir_no(n->esq, 2);
            printf(" -%d- ", n->valor);
            imprimir_no(n->dir, 2);
        }
    }
    
    //pós ordem
    if(ordem == 3){
        if (n != NULL) {
            imprimir_no(n->esq, 3);
            imprimir_no(n->dir, 3);
            printf(" -%d- ", n->valor);
        }
    }
}

void imprimirArvore(Arvore *a, int ordem){
    imprimir_no(a->raiz, ordem);
}

void liberarArvore(No *no){
    free(no);
}


int busca_menor(Arvore *a){
    int menor = a->raiz->valor;
    No *temp = a->raiz;

    if(vaziaArvore(a->raiz)){
        return -1;
    }
    while(temp->esq != NULL){
        temp = temp->esq;
    }
    menor = temp->valor;
    return menor;
}

int noRaiz(No *n){
    return n->valor;
}

void insere(No **no, int valor){
    *no = inserirArvore(*no, valor);
}

No* inserirArvore(No *no, int valor){

    if(no == NULL){
        return criarNo(valor);
    }

    if(valor < no->valor){
        no->esq = inserirArvore(no->esq, valor);
            if(altura(no->esq) - altura(no->dir) >= 2){
                if(valor < (no->esq->valor)){
                    no = rotacaoLL(no);
                }else{
                    no = rotacaoLR(no);
                }
            }
    }else if(valor > no->valor){
            no->dir = inserirArvore(no->dir, valor);
                if(altura(no->dir) - altura(no->esq) >= 2){
                    if(no->dir->valor < valor){
                        no = rotacaoRR(no);
                    }else{
                        no = rotacaoRL(no);
                    }
                }
    }else if(valor == no->valor){
        return NULL;
    }
    no->fatorBal = maior(altura(no->esq), altura(no->dir)) + 1;
    return no;
}
 
No* removerArvore(No *no, int valor){
    if(no == NULL){
        return NULL;
    }
    if(valor < no->valor){
            no->esq = removerArvore(no->esq, valor);

            if(altura(no->esq) - altura(no->dir) >= 2){
                if(altura(no->dir->esq) <= altura(no->dir->dir)){
                    no = rotacaoRR(no);
                }
                else{
                    no = rotacaoLL(no);
                }
            }
    }else if(no->valor == valor){
        if(no->dir == NULL){
            no = NULL;
        }else if(no->dir != NULL){
            no = no->dir;
        }
    }
    return no;
}
 
int altura(No *no) {
  if(no == NULL){
      return -1;
  }else{
      return no->fatorBal;
  }
}

int maior(int x, int y){
    if(x > y) return x;
    else return y;
}

No* rotacaoLL(No *no){

    No *aux = no->esq;
    no->esq = aux->dir;
    aux->dir = no;
    no->fatorBal = (maior(altura(no->dir), altura(no->esq)) + 1);
    aux->fatorBal = (maior(altura(no->esq), no->fatorBal) + 1);
    return aux;
}

No* rotacaoRR(No *no){

    No *aux = no->dir;
    no->dir = aux->esq;
    aux->esq = no;
    no->fatorBal = (maior(altura(no->dir), altura(no->esq)) + 1);
    aux->fatorBal = (maior(altura(no->dir), no->fatorBal) + 1);

    return aux;
}

No* rotacaoRL(No *no){
    no->dir = rotacaoLL(no->dir);
    return(rotacaoRR(no));
}

No* rotacaoLR(No *no){
    no->esq = rotacaoRR(no->esq);
    return(rotacaoLL(no));
}

No* criarNo(int valor){
    No *no = (No*) malloc(sizeof(No));
    if(no == NULL){
        //Alocacao falhou!
        return 0;
    }
    no->valor = valor;
    no->fatorBal = 0;
    no->esq = NULL;
    no->dir = NULL;
    return no;
}