#include <stdio.h>
#include "arvore.h"

int main(){
  int opc, valor, r;
  Arvore *a;
  do{
	printf("Digite a opção desejada: \n 1- Criar Arvore \n2- Inserir \n 3- Remover \n 4- Imprimir \n5- Verificar se a Arvore está vazia \n 6- sair");
    	scanf("%d", &opc);
	
	switch(opc){
	  case 1:
         a = criar();
 		 printf("arvore criada com sucesso");
 	     break;
	  case 2:
 	    printf("Digite o valor a ser inserido na Arvore");
 		scanf("%d", &valor);
        inserir(a, valor);
	    break;
	  case 3:
 	    printf("Digite o valor a ser removido");
 		scanf("%d", &valor);
  	    r = remover(a, valor);
            
	    if(r) printf("O valor %d foi removido com sucesso", valor);
        else printf("O valor %d não existe na árvore", valor);
	    break;
	  case 4:
 	    printf("Qual o tipo de percurso 1-pré-ordem, 2-in-ordem, 3-Pós-ordem");
 		scanf("%d", &r);
		imprimir(a, r);
        break;
	  case 5:
	 	if(vazia(a)) printf("A arvore está vazia");
		else printf("A arvore não está vazia");
		break;
	  case 6:
        liberar(a);
		printf("Programa encerrado com sucesso");
		break;
      default: printf("Opção Inválida");
	}
  }while(opc != 6);
  return(0);
}
