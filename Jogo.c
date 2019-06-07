#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include "lista.h"


typedef struct jogador{
    Arvore *a;
    int vitorias;
}Jogador;

typedef struct partida{
    int carta;
    Jogador jog;
}Partida;

Lista* lista_cartas(){
    Lista *l = criarLista();

    int carta = 1;

    for(int i = 1; i < 53; i = i + 4){
        inserirLista(l, carta, i - 1);
        inserirLista(l, carta, i);
        inserirLista(l, carta, i + 1);
        inserirLista(l, carta, i + 2);
        carta++;
    }
    
    return l;
}

Jogador criar_jogador(){
    Jogador jogador;

    jogador.a = criarArvore();
    jogador.vitorias = 0;
    return jogador;
}

void jogo(){

    Jogador jog[3];

    printf("teste");
    for(int i = 0; i < 3; i++){
        jog[i] = criar_jogador();
    }

    Lista *l = lista_cartas();
    int num = 0;
    int carta = 0;
    for(int i = 0; i < 10; i++){
        for(int i = 0; i < 3; i++){
            num = rand() % qtd_elemLista(l);
            carta = removerLista(l, num);
            inserirArvore(jog[i].a, carta);
        }
    }

    for(int i = 0; i < 3; i++){
        printf("\nJogador %d: ", i);
        imprimirArvore(jog[i].a, 1);
    }

    int a = buscar_ordenada(jog, 2);

    printf("Busca: %d", a);
}

int main(){

    //jogo();

    Arvore *arvore;

    arvore = criarArvore();

    int i = 0, valor = 0;

    for(i = 0; i < 10; i++){
        printf("Informe o valor: ");
        scanf("%d", &valor);

        inserirArvore(arvore, valor);
    }

    imprimirArvore(arvore, 3);

    system("pause");
    return 0;
}