#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#define ESQUERDA 1
#define DIREITA 2

struct no{
    int valor;
    No *esq;
    No *dir;
};

struct arvore{
    No *raiz;
};

Arvore* criar(){
    Arvore *a = (Arvore*) malloc(sizeof(Arvore));
    a->raiz = NULL;
    return(a);
}


int vazia(Arvore *a){
    if(a->raiz == NULL)
        return 1;
    else
        return 0;
}

int cheia(Arvore *a){
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
    
    //in ordem
    if(ordem == 3){
        if (n != NULL) {
            imprimir_no(n->esq, 3);
            imprimir_no(n->dir, 3);
            printf(" -%d- ", n->valor);
        }
    }
}

void imprimir(Arvore *a, int ordem){
    imprimir_no(a->raiz, ordem);
}

void inserir(Arvore *a, int valor){
    No *temp  = a->raiz;
    No *ant = NULL;
    int pos=0;
    
    No *n = (No*) malloc(sizeof(No));
    n->valor = valor;
    n->esq = NULL;
    n->dir = NULL;
    
    if(vazia(a)){
        a->raiz = n;
    }else{
        while(temp != NULL){
            if(valor < temp->valor){
                ant = temp;
                temp = temp->esq;
                pos = ESQUERDA;
            }else{
                if(valor > temp->valor){
                    ant = temp;
                    temp = temp->dir;
                    pos = DIREITA;
                } else if(valor == temp->valor){
                     printf("Valor j� existe na �rvore");
                    free(n);
                    return;
                    }
            }
        }
        
        if(pos == ESQUERDA){
            ant->esq = n;
        }else if(pos == DIREITA) ant->dir = n;
    }
}

int remover(Arvore *a, int valor){
    if(!vazia(a)){
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
            if(ant2 != NULL) ant2->dir = NULL;
            if(temp->esq == temp2) temp->esq = NULL;
            free(temp2);
            return(1);
        }
            
    }
    
    return(0); // quando está vazia retorna 0
}

void liberar(Arvore *a){
    free(a);
}
