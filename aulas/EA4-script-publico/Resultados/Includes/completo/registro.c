#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "registro.h"





/*
Função que recebe o número de um log e o caminho da pasta de logs e retorna um Registro de partida
lido do arquivo binário correspondente ao log.

@param logNum: Número do log
@param pastaLogs: Caminho da pasta de logs (já com a barra no final)
*/
Registro leRegistro(int logNum, char *pastaLogs){
    char caminho[256];  // buffer seguro

  

    sprintf(caminho, "%slog_%d.bin", pastaLogs, logNum);

    FILE *f = fopen(caminho, "rb");
   

    Registro reg = {0};

    fread(&reg.idPartida, sizeof(int), 1, f);

    for (int i = 0; i < MAX_JOGADOR_PARTIDA; i++) {
        reg.jogadores[i] = leJogador(f);
    }

    fclose(f);
    return reg;
}


/*
Função que busca um jogador em um registro de partida a partir do ID do jogador.
Se o jogador for encontrado, ele é retornado. Caso contrário, um jogador é criado com ID -1 e retornado.

@param r: Registro de uma partida
@param idJog: ID do jogador a ser buscado
*/
Jogador buscaJogadorRegistro(Registro r, int idJog){
        for(int i = 0; i<MAX_JOGADOR_PARTIDA; i++){
            if(getIdJogador(r.jogadores[i])== idJog){
return  r.jogadores[i];         
 }
        }
        return inicializaJogador(-1);
}

