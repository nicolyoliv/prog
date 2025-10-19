#include <stdio.h>
#include "jogada.h"


/**
 * Lê uma jogada e retorna uma estrutura do tipo tJogada e define o valor da variavel sucesso.
 * Se a jogada foi lida com sucesso, ou seja, foi lido um valor para x e outro para y, sucesso = 1, caso contrário, sucesso = 0.
 * @return a jogada lida.
 */
tJogada LeJogada(){
    tJogada jogada;
    int numLidos;
    
    numLidos = scanf("%d %d", &jogada.x, &jogada.y);
    
    if (numLidos != 2) {
        
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
        
        jogada.sucesso = 0;
        
        jogada.x = -1;
        jogada.y = -1;
        
    } else {
        jogada.sucesso = 1;
    }
    
    return jogada; 
}


/**
 * Retorna a coordenada X da jogada.
 * 
 * @param jogada a jogada.
 * 
 * @return a coordenada X da jogada.
 */
int ObtemJogadaX(tJogada jogada){
    return jogada.x;
}


/**
 * Retorna a coordenada Y da jogada.
 * 
 * @param jogada a jogada.
 * 
 * @return a coordenada Y da jogada.
 */
int ObtemJogadaY(tJogada jogada){
    return jogada.y;
}


/**
 * Retorna 1 se a jogada foi bem sucedida e 0 caso contrário.
 * 
 * @param jogada a jogada.
 * 
 * @return 1 se a jogada foi bem sucedida, 0 caso contrário.
 */
int FoiJogadaBemSucedida(tJogada jogada){
    if(jogada.x >=0 && jogada.x<=2 && jogada.y >=0 && jogada.y<=2){
        return 1;
    }else{
        return 0;
    }
}

