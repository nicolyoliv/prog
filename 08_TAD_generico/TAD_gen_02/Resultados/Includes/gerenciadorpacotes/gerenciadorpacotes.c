#include "gerenciadorpacotes.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

 struct gerenciadorpacotes {
    tPacote **pacote;
    int tam;
 };

/**
 * @brief Cria uma TAD que gerencia pacotes. O pacote é um TAD genérico.
 *
 *
 * @return O gerenciador de pacotes
 */
tGerenciador* CriaGerenciador(){
    tGerenciador *g = calloc(1, sizeof(tGerenciador));
    if(g==NULL){
        exit(1);
    }
    g->pacote = NULL;
    g->tam=0;

    return g;
}

/**
 * @brief Adiciona um pacote ao gerenciador de pacotes.
 *
 * @param geren O gerenciador de pacotes que armazenará o pacote 
 * @param pac O pacote que queremos adicionar no gerenciador.
 *
 */
void AdicionaPacoteNoGerenciador(tGerenciador* geren, tPacote* pac){
    geren->pacote = realloc(geren->pacote, (geren->tam+1) * sizeof(tPacote*));
    geren->pacote[geren->tam] = pac;
    geren->tam++;
}


/**
 * @brief Destrói um gerenciador de pacotes
 *
 * @param geren O gerenciador de pacotes que será destruído (memória liberada)
 *
 */
void DestroiGerenciador(tGerenciador* geren){
    for(int i=0; i<geren->tam;i++){
      DestroiPacote(geren->pacote[i]);
    }free(geren->pacote);
    free(geren);
}

/**
 * @brief Imprime um pacote específico do gerenciador de pacotes.
 *
 * @param geren - O gerenciador de pacotes que terá um pacote impresso
 * @param idx - O índice do pacote a ser impresso (começa em zero!)
 *
 */
void ImprimirPacoteNoIndice(tGerenciador* geren, int idx){
    if(idx<0 || idx >= geren->tam){
        return;
    }ImprimePacote(geren->pacote[idx]);
}


/**
 * @brief Imprime todos os pacotes de um gerenciador de pacotes
 *
 * @param geren O gerenciador de pacotes que terá seus pacotes impressos
 *
 */
void ImprimirTodosPacotes(tGerenciador* geren){
    for(int i = 0;i<geren->tam;i++){
        ImprimePacote(geren->pacote[i]);
    }
}