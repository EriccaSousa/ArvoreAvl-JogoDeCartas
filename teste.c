#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main(){
    int i = 0, valor = 0;

    Arvore *a;
    a = criarArvore();

    for(i = 1; i < 10; i++){
        printf("Informe um valor: ");
        scanf("%d", &valor);

        inserirArvore(a, valor);
    }
    
    printf("\nArvore informada: ");
        imprimirArvore(a, 3);

    system("pause");
    return 0;
}