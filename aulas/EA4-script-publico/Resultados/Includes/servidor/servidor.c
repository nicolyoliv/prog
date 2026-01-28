#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "servidor.h"


/*
Função que lê todos os registros de partidas de um servidor a partir da entrada padrão e retorna um servidor
com todos os registros de partidas lidos. Conforme a especificação da atividade.

@return Servidor: Servidor com todos os registros de partidas lidos
*/
Servidor leRegistrosServidor() {
    Servidor s;
    char pasta[100] = "logs_partidas/"; // Caminho padrão do exercício

    // CORREÇÃO: scanf exige o & para o endereço da variável
    if (scanf("%d", &s.nPartidas) != 1) {
        s.nPartidas = 0;
        return s;
    }

    for (int i = 0; i < s.nPartidas; i++) {
        // leRegistro precisa do índice (i) e da pasta
        s.partidas[i] = leRegistro(i, pasta);
    }
    return s;
}

/*
Função que recebe um servidor já preenchido com os dados de todas as partidas e um ID de jogador.
A partir dessas informações, ela busca as estatísticas do jogador em todas as partidas que ele participou.
Se o jogar não for encontrado, um jogador com ID -1 é criado e retornado.
Se o jogador for encontrado em apenas uma partida, ele é retornado.
Se o jogador for encontrado em mais de uma partida, suas estatísticas são agregadas e o jogador é retornado.

@param s: Servidor
@param idJog: ID do jogador
*/
Jogador buscaDadosJogadorServidor(Servidor s, int idJog) {
    Jogador total = inicializaJogador(-1); // Começa com ID -1
    int encontrouPeloMenosUma = 0;

    for (int i = 0; i < s.nPartidas; i++) {
        Jogador daPartida = buscaJogadorRegistro(s.partidas[i], idJog);
        
        if (getIdJogador(daPartida) != -1) {
            if (!encontrouPeloMenosUma) {
                // Primeira vez que achamos o jogador, inicializamos com os dados dele
                total = inicializaJogador(idJog);
                encontrouPeloMenosUma = 1;
            }
            // Agrega as estatísticas (K, D, A)
            total = atualizaJogador(total, idJog, 
                                    getKillsJogador(daPartida), 
                                    getDeathsJogador(daPartida), 
                                    getAssistsJogador(daPartida));
        }
    }
    return total; // Retorna o acumulado ou o jogador com ID -1 se nunca apareceu
}

/*
Função que recebe um servidor já criado e preenchido e imprime um relatório com as estatísticas de um conjunto de jogadores
solicitados a partir da entrada padrão. O relatório é impresso conforme o formato especificado na descrição da atividade.
*/
void criaRelatorioServidor(Servidor s) {
    int nJogadoresBusca, idBusca;
    
    // Lê quantos jogadores serão consultados
    if (scanf("%d", &nJogadoresBusca) != 1) return;

    for (int i = 0; i < nJogadoresBusca; i++) {
        scanf("%d", &idBusca);
        
        Jogador resultado = buscaDadosJogadorServidor(s, idBusca);
        
        if (getIdJogador(resultado) == -1) {
            printf("Jogador %d: -\n", idBusca);
        } else {
            printaJogador(resultado);
        }
    }
}

