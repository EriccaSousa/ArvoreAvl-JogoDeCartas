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
    Lista *l = criarl();

    int carta = 1;

    for(int i = 1; i < 53; i = i + 4){
        inserirl(l, carta, i - 1);
        inserirl(l, carta, i);
        inserirl(l, carta, i + 1);
        inserirl(l, carta, i + 2);
        carta++;
    }
    
    return l;
}

Jogador criar_jogador(){
    Jogador jogador;

    jogador.a = criara();
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
            num = rand() % qtd_elem(l);
            carta = removerl(l, num);
            inserira(jog[i].a, carta);
        }
    }

    for(int i = 0; i < 3; i++){
        printf("\nJogador %d: ", i);
        imprimira(jog[i].a, 1);
    }
}

int main(){

    jogo();
    return 0;
}