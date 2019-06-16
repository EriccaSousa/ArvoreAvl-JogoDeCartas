#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arvore.h"
#include "lista.h"


typedef struct jogador{
    Arvore *a;
    int vitorias;
    int vitorias_partidas;
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

    if((menor[0] > menor[1] && menor[0] > menor[2])){
        printf("\nJogador 1 venceu a rodada!");
        jog[0].vitorias++;
    }else if((menor[1] > menor[0] && menor[1] > menor[2])){
        printf("\nJogador 2 venceu a rodada!");
        jog[1].vitorias++;
    }else if((menor[2] > menor[1] && menor[2] > menor[0])){
        printf("\nJogador 3 venceu a rodada!");
        jog[2].vitorias++;
    }
    //Casos de empate:
    else if(menor[0] == menor[1] && menor[0] > menor[2]){
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

void jogo(Jogador jog[3]){

    int num = 0;
    int carta = 0;

    Lista *l = lista_cartas();
    
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
    for(int i = 0; i < 10; i++){
        printf("\n ------ Rodada %d ------", i+1);
        partida(jog);
    }
        
    printf("\n-------- Pontuacao final -------- ");
    printf("\nJogador 1: %d", jog[0].vitorias);
    printf("\nJogador 2: %d", jog[1].vitorias);
    printf("\nJogador 3: %d", jog[2].vitorias);

    //casos de empate:
    if((jog[0].vitorias == jog[1].vitorias) && (jog[0].vitorias == jog[2].vitorias) && (jog[1].vitorias == jog[2].vitorias)) {
        printf("\nA partida terminou empatada!\n");
        jog[0].vitorias_partidas++;
        jog[1].vitorias_partidas++;
        jog[2].vitorias_partidas++;

    }
    if(jog[0].vitorias == jog[1].vitorias){
        printf("\nJogadores 1 e 2 empataram!!\n");
        jog[0].vitorias_partidas++;
        jog[1].vitorias_partidas++;
    }
    if(jog[0].vitorias == jog[2].vitorias){
        printf("\nJogadores 1 e 3 empataram!!\n"); 
        jog[0].vitorias_partidas++;
        jog[2].vitorias_partidas++;
    }
    if(jog[1].vitorias == jog[2].vitorias){
        printf("\nJogadores 2 e 3 empataram!!\n");
        jog[1].vitorias_partidas++;
        jog[2].vitorias_partidas++;
    }
    //Casos de vitoria:
    if((jog[0].vitorias > jog[1].vitorias) && (jog[0].vitorias > jog[2].vitorias)){
        printf("\nParabens Jogador 1, voce venceu!!\n");
        jog[0].vitorias_partidas++;
    }
    if((jog[1].vitorias > jog[0].vitorias) && (jog[1].vitorias > jog[2].vitorias)){
        printf("\nParabens Jogador 2, voce venceu!!\n");
        jog[1].vitorias_partidas++;
    }
    if((jog[2].vitorias > jog[1].vitorias) && (jog[2].vitorias > jog[0].vitorias)){
        printf("\nParabens Jogador 3, voce venceu!!\n");
        jog[2].vitorias_partidas++;
    }
    printf("\n");

    return;
}

int main(){
    
    int qtd = 0;
    Jogador jog[3];

    printf("teste");
    for(int i = 0; i < 3; i++){
        jog[i] = criar_jogador();
    }

    printf("\nDigite a quantidade de partidas: ");
    scanf("%d", &qtd);

    for(int i = 0; i < qtd; i++){
        printf("\n\nPARTIDA %d\n", i + 1);
        jogo(jog);
    }

    system("pause");
    return 0;
}