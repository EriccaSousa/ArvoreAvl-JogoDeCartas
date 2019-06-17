#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main(){
    int i = 0, valor = 0;

    int verifica = 0;
    No *n = NULL;    
    for(i = 0; i < 8; i++){
        printf("Informe um valor: ");
        scanf("%d", &valor);
        n = inserirArvore(n, valor);
    }
    
    printf("\nArvore informada: ");
        imprimirArvore(n, 2);

    printf("\n ---- valor no raiz: %d ----", noRaiz(n));
    for(int i = 0; i < 8; i++){
        valor = busca_menor(n);
        printf("\nValor: %d", valor);
        n = removerArvore(n, valor);
        printf("\n Arvore removida %d\n", i);
        imprimirArvore(n, 2);
    }
    system("pause");
    return 0;
}