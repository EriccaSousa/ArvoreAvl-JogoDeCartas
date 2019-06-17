#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main(){
    int i = 0, valor = 0;

    int verifica = 0;
    No *n = NULL;
    Arvore *a = criarArvore();

    for(i = 1; i < 10; i++){
        printf("Informe um valor: ");
        scanf("%d", &valor);
        n = insereAVL(n, valor);
    }
    
    printf("\nArvore informada: ");
        imprimirArvore(n, 2);

    system("pause");
    return 0;
}