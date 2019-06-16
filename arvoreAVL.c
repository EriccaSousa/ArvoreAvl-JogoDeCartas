#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#define ESQUERDA 1
#define DIREITA 2

struct no{
    int valor;
    No *esq;
    No *dir;
    int fatorBal;//Altura da sub-arvore;
};

struct arvore{
    No *raiz;
};

Arvore* criarArvore(){
    Arvore *a = (Arvore*) malloc(sizeof(Arvore));
    a->raiz = NULL;
    return(a);
}


int vaziaArvore(Arvore *a){
    if(a->raiz == NULL)
        return 1;
    else
        return 0;
}

int cheiaArvore(Arvore *a){
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

void inserirArvore(Arvore *a, int valor){
    No *temp  = a->raiz;
    No *ant = NULL;
    No *aux = NULL;
    int verifica = 0;
    int pos=0;
    
    No *n = (No*) malloc(sizeof(No));
    n->valor = valor;
    n->esq = NULL;
    n->dir = NULL;
    n->fatorBal = 0;
    
    if(vaziaArvore(a)){
        a->raiz = n;
    }else{
        while(temp != NULL){
            if(verifica == 1)
                aux = ant;
            if(valor <= temp->valor){
                ant = temp;
                temp = temp->esq;
                pos = ESQUERDA;
                verifica = 1;
            }else{
                if(valor >= temp->valor){
                    ant = temp;
                    temp = temp->dir;
                    pos = DIREITA;
                    verifica = 1;

                } 
            }
            
        }
        
        if(pos == ESQUERDA){
            ant->esq = n;
            if(altura(aux->esq) - altura(aux->dir) == 2)
                if(valor < ant->esq->valor)
                    aux = rotacaoRR(aux);
                else
                    aux = rotacaoLR(aux);
        }else if(pos == DIREITA){
            ant->dir = n;
            if(altura(aux->dir) - altura(aux->esq) == 2)
                if(valor > aux->dir->valor)
                    aux = rotacaoLL(aux);
                else
                    ant = rotacaoRL(aux);
        } 
    }
}

int removerArvore(Arvore *a, int valor){
    if(!vaziaArvore(a)){
        //percorrendo a árvore com temp
        No *temp = a->raiz;
        No *ant =NULL;
        int pos_temp = 0;
        while(temp!=NULL){
            if(valor == temp->valor) break;
            ant = temp;
            if(valor < temp->valor){
               temp = temp->esq;
               pos_temp = ESQUERDA;
            }else if (valor > temp->valor){
                     temp = temp->dir;
                     pos_temp = DIREITA;
            }
        } // o fluxo sai deste laço com temp apontando para null quando não encontra o valor ou com temp apontando para a posição que tem o valor
        
        // caso que o valor não é encontrado
        if(temp == NULL) return 0;
        
        // quando o valor está em um nó que não tem direita nem esquerda
        if(temp->esq == NULL && temp->dir == NULL){
                if(temp == a->raiz) a->raiz = NULL;
                else if(pos_temp == ESQUERDA) ant->esq = NULL;
                     else ant->dir = NULL;
                free(temp);
                return(1);
        }
        
        // quando não tem esquerda mas tem direita
        if (temp->esq == NULL && temp->dir != NULL){
            if(temp == a->raiz) a->raiz = a->raiz->dir;
            if(pos_temp == ESQUERDA) ant->esq = temp->dir;
            else if(pos_temp == DIREITA) ant->dir = temp->dir;
            free(temp);
            return(1);
        }
        
        // quando não tem direita mas tem esquerda
        if (temp->dir == NULL && temp->esq != NULL){
            if(temp == a->raiz) a->raiz = a->raiz->esq;
            if(pos_temp == ESQUERDA) ant->esq = temp->esq;
            else if(pos_temp == DIREITA) ant->dir = temp->esq;
            free(temp);
            return(1);
        }
        
        //quando tem direita e esquerda. Pega o maior elemento da esquerda (elemento mais a direita da esquerda) e troca de lugar com o valor a ser removido
        No *temp2;
        No *ant2 = NULL;
        if(temp->esq != NULL && temp->dir != NULL){
            temp2 = temp->esq;
            while(temp2->dir!=NULL){
                ant2 = temp2;
                temp2 = temp2->dir;
            }
            
            temp->valor = temp2->valor;
            if(ant2 != NULL) ant2->dir = temp2->esq;
            // if(ant2 != NULL) ant2->dir = NULL;
            
            if(temp->esq == temp2) temp->esq = temp2->esq;
            
            free(temp2);
            return(1);
        }
            
    }
    
    return(0); // quando está vazia retorna 0
}

void liberarArvore(Arvore *a){
    free(a);
}


int busca_menor(Arvore *a){
    int menor = a->raiz->valor;
    No *temp = a->raiz;
    No *ant = NULL;

    if(vaziaArvore(a)){
        return -1;
    }
    while(temp->esq != NULL){
      
        temp = temp->esq;
    }
    menor = temp->valor;
    return menor;
}

/* 
int altura(No *no) {
  if (no == NULL) return -1;

  int alturaEsq = altura(no->esq);  
  int alturaDir = altura(no->dir);

  if(alturaEsq == alturaDir){
      return 1;
  }else if(alturaEsq > alturaDir){
      return alturaEsq + 1;
  }else return alturaDir + 1;
}*/



int altura(No *no){
    if(!no) 
        return -1;
    return(no->fatorBal);
}

/* 
int calcularBalanceamento(Arvore *a){
    a->raiz->fatorBal = (altura(a->raiz->esq) - altura(a->raiz->dir));

    return a->raiz->fatorBal;
}*/

int maior(int x, int y){
    if(x > y) return x;
    else return y;
}

No *rotacaoRR(No *no){
    No *aux = no->esq;

    no->esq = aux->dir;
    aux->dir = no;

    no->fatorBal = (maior(altura(no->esq), altura(no->dir)) + 1);
    aux->fatorBal = (maior(altura(no->esq), no->fatorBal) + 1);

    return aux;
}

No *rotacaoLL(No *no){
    No *aux = no->dir;

    no->dir = aux->esq;
    aux->esq = no;

    no->fatorBal = (maior(altura(no->esq), altura(no->dir)) + 1);
    aux->fatorBal = (maior(altura(no->dir), no->fatorBal) + 1);

    return aux;
}

No *rotacaoLR(No *no){
    no->esq = rotacaoLL(no->esq);

    return(rotacaoRR(no));
}

No *rotacaoRL(No *no){
    no->dir = rotacaoRR(no->dir);

    return(rotacaoLL(no));
}
 
