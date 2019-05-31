#include <malloc.h>
#include "AVL.h"

struct node{
	int valor;
	struct node* sae;
	struct node* sad;
	struct node* pai;
};

tree* criar(int raiz){
	tree* t =(tree*) malloc(sizeof(tree));
	t->valor = raiz;
	t->sad = NULL;
	t->sae = NULL;
	t->pai = NULL;
	
	return t;
}

tree* criarVazia(){
	tree* t = NULL;
	return t;
}

tree* sae(tree* t){
	return t->sae;
}

tree* sad(tree* t){
	return t->sad;
}

tree* pai(tree* t){
	return t->pai;
}

int isNULL(tree* t){
	if(t == NULL)	return 1;
	else 			return 0;
}

tree* minimum(tree* t){
	tree* sup = t;
	
	while(sup->sae != NULL)	sup = sup->sae;
	
	return sup;
}

tree* maximum(tree* t){
	tree* sup = t;
	
	while(sup->sad != NULL)	sup = sup->sad;
	
	return sup;
}

tree* successor(tree* t){
	if(t->sad != NULL){
		return minimum(t->sad);
	}
	
	tree* sup = pai(t);
	
	while(sup != NULL && t->valor == sup->sad->valor){
		t = sup;
		sup = pai(sup);
	}
	return sup;
}

tree* predecessor(tree* t){
	if(t->sae != NULL){
		return maximum(t->sae);
	}
	
	tree* sup = pai(t);
	
	while(sup->pai != NULL && sup->sae->valor == t->valor){
		t = sup;
		sup = pai(sup);
	}
	return sup;
}

void inserir(tree* t, int valor){
	//Inserindo em uma arv vazia;
	if(t == NULL){
		t = criar(valor);
		return;
	}

	if(valor > t->valor){
		if(t->sad != NULL){
			//Vai pra direita
			return inserir(sad(t), valor);	
		}else{
			//Está vazia, então pode inserir
			tree* sub = criar(valor);
			t->sad = sub;
			sub->pai = t;
		}
	}else{
		if(t->sae != NULL){
			//Vai pra esquerda
			return inserir(sae(t), valor);
		}else{
			//Está vazia, então pode inserir
			tree* sub = criar(valor);
			t->sae = sub;
			sub->pai = t;
		}
	}
	
}

int searchKey(tree* t, int valor){
	if(isNULL(t))			return 0;
	if(t->valor == valor) 	return t->valor;
	
	if(t->valor > valor) 	return searchKey(sae(t), valor);
	else 					return searchKey(sad(t),valor);
}

tree* search(tree* t, int valor){
	if(isNULL(t)) 			return NULL;
	
	if(t->valor == valor) 	return t;
	
	if(t->valor > valor)	return search(sae(t), valor);
	else 					return search(sad(t),valor);
}

void freeNode(tree* t){
	free(t);
}

void itRoot(tree* sup){
	sup = criarVazia();
}

void notChildren(tree* sup){
	
	tree* ant = pai(sup);
	printf("\nValor ant: %d",ant->valor);
	
	if(ant->sad != NULL){
		if(ant->sad->valor == sup->valor){
			ant->sad = NULL;	//Filho da direita
		}else{
			ant->sae = NULL;	//Filho da esquerda
		}
	}else{
		ant->sae = NULL;
	}
	freeNode(sup);
}

void oneChildren(tree* sup){
	if(isNULL(sup->sae)){
		if(sup->valor > sup->pai->valor){
			sup->pai->sad = sad(sup);
			sup->sad->pai = sup->pai;
			freeNode(sup);
		}else{
			sup->pai->sae = sup->sad;
			sup->sad->pai = sup->pai;
			freeNode(sup);
		}
	}else{
		if(sup->valor > sup->pai->valor){
			sup->pai->sad = sae(sup);
			sup->sae->pai = sup->pai;
			freeNode(sup);
		}else{
			sup->pai->sae = sae(sup);
			sup->sae->pai = sup->pai;
			freeNode(sup);
		}
	}
}

void twoChildren(tree* sup){
	tree* ant = pai(sup);
	
	if(sup->valor > ant->valor){
		ant->sad = minimum(sup->sad);
		sup->sae->pai = ant->sad;
		ant->sad->sae = sup->sae;
		if(!isNULL(ant->sad->sae)){
			ant->sad->pai->sae = ant->sad->sae;
		} 
		ant->sad->pai->sae = NULL;
	}else{
		ant->sae = minimum(sup->sad);
		sup->sae->pai = ant->sae;
		ant->sae->sae = sup->sae;
		if(!isNULL(ant->sae->sad)){
			ant->sae->pai->sad = ant->sae->sad;
		} 
		ant->sae->pai->sae = NULL;
	}
	
	
	
}

void Remove(tree* t, int key){
	tree* sup = search(t,key);
	
	if(sup == NULL){
		return;
	}
	
	//Caso 0: É raiz;
	if(pai(sup) == NULL){
		itRoot(sup);
	}
	
	//Caso 1: Não possui filhos (uma folha)
	if(isNULL(sup->sae) && isNULL(sup->sad)){
		notChildren(sup);
		return;
	}
	
	//Caso 2: Possui 1 filho
	if(isNULL(sup->sae) || isNULL(sup->sad)){
		oneChildren(sup);
		return;
	}
	
	//Caso 3: Possui dois filhos 
	twoChildren(sup);
}

void deleteTree(tree* t){
	if(!isNULL(t)){
		deleteTree(t->sae);
		deleteTree(t->sad);
		freeNode(t);
	}
	t = NULL;
}

void emOrdem(tree* t){
	if(!isNULL(t)){
		emOrdem(t->sae);
		printf(" %d",t->valor);
		emOrdem(t->sad);
	}else{
		return;
	}
}

void posOrdem(tree* t){
	if(!isNULL(t)){
		posOrdem(t->sae);
		posOrdem(t->sad);
		printf(" %d",t->valor);
	}else{
		return;
	}
}

void preOrdem(tree* t){
	if(!isNULL(t)){
		printf(" %d",t->valor);
		preOrdem(t->sae);
		preOrdem(t->sad);
	}else{
		return;
	}
}

void printTree(tree* t){
	printf(" <");
	if(!isNULL(t)){
		printf("%d",t->valor);
		printTree(t->sae);
		printTree(t->sad);
	 }
	 printf(">");
}

int altura (tree* t) {
   if (t == NULL) 
      return 0; // altura da árvore vazia
   else {
      int he = altura (t->sae);
      int hd = altura (t->sad);
      if (he < hd) return hd + 1;
      else return he + 1;
   }
}

int fb(tree* t){	//Fator de Balanceamento
	int Q = altura(t->sad) - altura(t->sae);
	return Q;
}

tree* RSE(tree* t){	//Rotação simples a esquerda
	tree* q = t->sad;
	
	if(!isNULL(q->sae)){
		tree* r = q->sae;
		q->sae = t;
		q->pai = t->pai;
		t->sad = r;
		r->pai = q;
	}else{
		q->sae = t;
		q->pai = t->pai;
		t->pai = q;
		t->sad = NULL;
	}
	t = q;
	return t;
}

tree* RSD(tree* t){	//Rotação simples a direita
	tree* q = t->sae;
	
	if(!isNULL(q->sad)){
		tree* r = q->sad;
		q->sad = t;
		q->pai = t->pai;
		t->sae = r;
		r->pai = q;
	}else{
		q->sad = t;
		q->pai = t->pai;
		t->pai = q;
		t->sae = NULL;
	}
	t = q;
	return t;
}

tree* RDE(tree* t){	//Rotação duplamente a esquerda
	t->sad = RSD(t->sad);
	t = RSE(t);
	return t;
}

tree* RDD(tree* t){	//Rotação duplamente a direita
	t->sae = RSE(t->sae);
	t = RSD(t);
	return t;
}

tree* fatorDeRotacao(tree* t){
	int Q = fb(t);
	
	if(Q >= -1 && Q <= 1)	return t; //Balanceada
	
	if(Q > 1){
		if(fb(t->sad) < 0){	
			t = RDE(t);
			printf("\nRotação simples a direita");
		}else{ 
			t = RSE(t);
			printf("\nRotação simples a esquerda");
		}
	}else{
		if(fb(t->sae) > 0){	
			t = RDD(t);
			printf("\nRotação dupla a direita");
		}else{ 
			t = RSD(t);
			printf("\nRotação simples a direita");
		}
	}
	return t;
}

tree* Insert(tree* t, int key){
	inserir(t,key);
	t = fatorDeRotacao(t);
	return t;
}
