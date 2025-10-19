#include <stdio.h>
#include "jogo.h"

/**
 * Cria um jogo e retorna o jogo criado.
 * 
 * @return o jogo criado.
 */
tJogo CriaJogo(){
    tJogo jogo;

    jogo.tabuleiro = CriaTabuleiro();
    jogo.jogador1 = CriaJogador(1);
    jogo.jogador2 = CriaJogador(2);
    
    return jogo;
}


/**
 * Inicia o jogo, definindo o tabuleiro e os jogadores.
 * 
 * @param jogo o jogo a ser iniciado.
 */
void ComecaJogo(tJogo *jogo){

    int terminou = 0, numJogadas = 0;
    tJogador *jogadorAtual;

    while (terminou == 0 && !AcabouJogo(*jogo)){

        if(numJogadas %2 == 0){
            jogadorAtual = &jogo->jogador1;
        }else{
             jogadorAtual = &jogo->jogador2;
        }
        printf("Jogador %d\n", jogadorAtual->id);
        jogo->tabuleiro = JogaJogador(*jogadorAtual, jogo->tabuleiro);
        numJogadas++;
        ImprimeTabuleiro(jogo->tabuleiro);

       

        if(VenceuJogador(*jogadorAtual, jogo->tabuleiro)){
            terminou = 1;
            ImprimeTabuleiro(jogo->tabuleiro);
            printf("JOGADOR %d Venceu!\n", jogadorAtual->id); 
            break;
        }
      
        }
        if(terminou == 0){
            ImprimeTabuleiro(jogo->tabuleiro);
            printf("FIM DE JOGO: DEU EMPATE!\n");

    }
}


/**
 * Verifica se o jogo acabou (se não há mais posições livres no tabuleiro).
 * 
 * @param jogo o jogo atual.
 * 
 * @return 1 se o jogo acabou, 0 caso contrário.
 */
int AcabouJogo(tJogo jogo){
    if(TemPosicaoLivreTabuleiro(jogo.tabuleiro)){
        return 0;
    }else{
        return 1;
    }
}


/**
 * Verifica se o usuário deseja jogar novamente.
 * 
 * @return 1 se o usuário deseja jogar novamente, 0 caso contrário.
 */
// NOVO E MAIS SEGURO ContinuaJogo() para uso com REDIRECIONAMENTO DE ARQUIVO
int ContinuaJogo(){
    char opcao;
    
    printf("Jogar novamente? (s,n)\n");
    
    if (scanf(" %c", &opcao) != 1) {
         return 0;
    }

    if(opcao == 's' || opcao == 'S'){
        return 1;
    } else {
        return 0;
    }
}

