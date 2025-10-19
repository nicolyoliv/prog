#include <stdio.h>
#include "jogador.h"
#include "jogada.h"
/**
 * Cria um jogador com o id passado como parâmetro e retorna o jogador criado.
 * 
 * @param idJogador o id do jogador (1 ou 2).
 * 
 * @return tJogador o jogador criado.
 */
tJogador CriaJogador(int idJogador){
    tJogador jogador;

    jogador.id = idJogador;
    return jogador;
}


/**
 * Recebe um jogador e um tabuleiro e retorna o tabuleiro com a jogada do jogador.
 * 
 * @param jogador o jogador que fará a jogada.
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return o tabuleiro atualizado com a jogada do jogador.
 */
tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro){
    int x, y;
    tJogada jogada;
    int jogadaInvalida;

 do{

    printf("Digite uma posicao (x e y):\n");
    jogada = LeJogada();
    x = ObtemJogadaX(jogada);
    y = ObtemJogadaY(jogada);
    
    jogadaInvalida = 0;
    
    if(!EhPosicaoValidaTabuleiro(x, y) || !EstaLivrePosicaoTabuleiro(tabuleiro, x, y)){
        printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", x, y);
        jogadaInvalida = 1 ; 
    }else if(!EstaLivrePosicaoTabuleiro(tabuleiro, x, y)){
        printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", x, y);
        jogadaInvalida = 1;
    }   
}while(jogadaInvalida);
    printf("Jogada [%d,%d]!\n", x, y);
    tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, jogador.id, x, y);
    return tabuleiro;
}


/**
 * Recebe um jogador e um tabuleiro e retorna 1 se o jogador venceu e 0 caso contrário.
 * 
 * @param jogador o jogador a ser verificado.
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return 1 se o jogador venceu, 0 caso contrário.
 */
int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro){
    int peca = jogador.id;

    for(int i = 0; i<=TAM_TABULEIRO; i++){
            if(tabuleiro.posicoes[i][0] == peca &&
                tabuleiro.posicoes[i][1] == peca &&
                tabuleiro.posicoes[i][2] == peca ){
                    return 1;
                }
        }
    for(int i = 0; i<=TAM_TABULEIRO; i++){
            if(tabuleiro.posicoes[0][i] == peca &&
                tabuleiro.posicoes[1][i] == peca &&
                tabuleiro.posicoes[2][i] == peca ){
                    return 1;
                }
        }
   
            if(tabuleiro.posicoes[0][0] == peca &&
                tabuleiro.posicoes[1][1] == peca &&
                tabuleiro.posicoes[2][2] == peca ){
                    return 1;
                }
       if(tabuleiro.posicoes[0][2] == peca &&
                tabuleiro.posicoes[1][1] == peca &&
                tabuleiro.posicoes[2][0] == peca ){
                    return 1;
                }
      
return 0;
}

