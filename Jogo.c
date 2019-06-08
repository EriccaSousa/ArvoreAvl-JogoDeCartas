#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arvore.h"
#include "lista.h"


typedef struct jogador{
    Arvore *a;
    int vitorias;
}Jogador;

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

void partida(Jogador jog[3]){ 
    
    int menor[3] = {0,0,0};
   
    for(int y = 0; y < 3; y++){
        printf("\nJogador %d ", y + 1);
        menor[y] = busca_menor(jog[y].a);
        removerArvore(jog[y].a, menor[y]);
        printf("Jogou a carta: %d", menor[y]);
    }
    if((menor[0] > menor[1] && menor[1] >= menor[2]) || (menor[0] > menor[2] && menor[2] >= menor[1])){
        printf("\nJogador 1 venceu a rodada!");
        jog[0].vitorias++;
    }else if((menor[1] > menor[0] && menor[0] >= menor[2]) || (menor[1] > menor[2] && menor[2] >= menor[0])){
        printf("\nJogador 2 venceu a rodada!");
        jog[1].vitorias++;
    }else if((menor[2] > menor[1] && menor[1] >= menor[0]) || (menor[2] > menor[0] && menor[0] >= menor[1])){
        printf("\nJogador 3 venceu a rodada!");
        jog[2].vitorias++;
    }else if(menor[0] == menor[1] && menor[0] > menor[2]){
        printf("\nJogador 1 e 2 empataram!");
        jog[0].vitorias++;
        jog[1].vitorias++;
    }else if(menor[2] == menor[0] && menor[2] > menor[1]){
        printf("\nJogador 1 e 3 empataram!");
        jog[0].vitorias++;
        jog[2].vitorias++;
    }else if(menor[1] == menor[2] && menor[1] > menor[0]){
        printf("\nJogador 2 e 3 empataram!");
        jog[1].vitorias++;
        jog[2].vitorias++;
    }else if(menor[0] == menor[1] == menor[2]){
        printf("\nTodos empataram!");
        jog[0].vitorias++;
        jog[1].vitorias++;
        jog[2].vitorias++;
    }
    
    return;

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
    srand(time(NULL));
    for(int i = 0; i < 10; i++){
        for(int i = 0; i < 3; i++){
            num = rand() % qtd_elemLista(l);
            carta = removerLista(l, num);
            inserirArvore(jog[i].a, carta);
        }
    }

    for(int i = 0; i < 3; i++){
        printf("\nJogador %d: ", i);
        imprimirArvore(jog[i].a, 2);
    }
    int menor;
  
    for(int i = 0; i < 10; i++){
        printf("\n ------ Rodada %d ------", i+1);
        partida(jog);
    }
        
    printf("\n-------- Pontuacao final -------- ");
    printf("\nJogador 1: %d", jog[0].vitorias);
    printf("\nJogador 2: %d", jog[1].vitorias);
    printf("\nJogador 3: %d", jog[2].vitorias);

    return;
}

int main(){

    jogo();

 /*
    Arvore *arvore;

    arvore = criarArvore();

    int i = 0, valor = 0;

    for(i = 0; i < 10; i++){
        printf("Informe o valor: ");
        scanf("%d", &valor);

        inserirArvore(arvore, valor);
    }

    imprimirArvore(arvore, 3);

    */
    system("pause");
    return 0;
}