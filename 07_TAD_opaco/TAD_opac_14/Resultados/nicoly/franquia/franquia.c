#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "franquia.h"

#define MAX_CONF 6
/**
 * @brief Estrutura que representa uma franquia.
 * 
 * A estrutura franquia contém informações sobre o nome da franquia, sua conferência e seu desempenho em casa e fora.
 * 
 */
 struct franquia {
    char *nome;
    char *conf;
    int vitD;
    int derD;
    int vitF;
    int derF;
};


/**
 * @brief Lê uma franquia da entrada padrao e retorna um ponteiro para ela.
 * 
 * @return tFranquia Retorna um ponteiro para a franquia lida.
 */
tFranquia LeFranquia(){
tFranquia f = calloc(1, sizeof(struct franquia));
if(f==NULL){
    exit(1);
}
f->nome = (char*)malloc(MAX_NOME*sizeof(char));
if(f->nome==NULL){
    exit(1);
}
f->conf = (char*)malloc(MAX_CONF*sizeof(char));
if(f->conf==NULL){
    exit(1);
}
scanf(" %s ", f->nome);
scanf(" %s ", f->conf);
return f;

}

/**
 * @brief Libera a memória alocada para uma franquia.
 * 
 * @param f Ponteiro para a franquia a ser liberada.
 */
void LiberaFranquia(tFranquia f){
      free(f->nome);
      free(f->conf);
      free(f);
}

/**
 * @brief Imprime as informações de uma franquia.
 * 
 * @param f Ponteiro para a franquia a ser impressa.
 */
void ImprimeFranquia(tFranquia f){
    int der = f->derD+f->derF;
    int vit = f->vitD+f->vitF;
    int total =(f->derD + f->derF + f->vitD +  f->vitF);
    float apro = 0.0;
if(total>0){
apro = (float) (f->vitD+f->vitF) / (f->derD + f->derF + f->vitD +  f->vitF);
}else{
    apro  = 0.0;
}
    printf("%s", f->nome);
if(strcmp(f->conf, "OESTE")==0){
    printf(" [CO] ");
    }else{
    printf(" [CL] ");

    }
    printf("%d %d %.2f %d %d\n", vit, der, apro*100, f->vitD, f->vitF);
}

/**
 * @brief Retorna o nome da franquia.
 * 
 * @param f Ponteiro para a franquia.
 * @return char* Retorna o nome da franquia.
 */
char * GetNomeFranquia(tFranquia f){
    return f->nome;
}

/**
 * @brief Retorna a conferência da franquia.
 * 
 * @param f Ponteiro para a franquia.
 * @return char* Retorna a conferência da franquia.
 */
char * GetConferenciaFranquia(tFranquia f){
    return f->conf;
}

/**
 * @brief Adiciona uma vitória em casa para a franquia.
 * 
 * @param f Ponteiro para a franquia.
 */
void AdicionaVitoriaCasaFranquia(tFranquia f){
 f->vitD++;
}

/**
 * @brief Adiciona uma vitória fora de casa para a franquia.
 * 
 * @param f Ponteiro para a franquia.
 */
void AdicionaVitoriaForaFranquia(tFranquia f){
 f->vitF++;
}

/**
 * @brief Adiciona uma derrota em casa para a franquia.
 * 
 * @param f Ponteiro para a franquia.
 */
void AdicionaDerrotaCasaFranquia(tFranquia f){
     f->derD++;

}

/**
 * @brief Adiciona uma derrota fora de casa para a franquia.
 * 
 * @param f Ponteiro para a franquia.
 */
void AdicionaDerrotaForaFranquia(tFranquia f){
         f->derF++;

}

/**
 * @brief Retorna o número de vitórias em casa da franquia.
 * 
 * @param f Ponteiro para a franquia.
 * @return int Retorna o número de vitórias em casa da franquia.
 */
int GetVitoriaCasaFranquia(tFranquia f){
    return f->vitD;
 
}

/**
 * @brief Retorna o número de vitórias fora de casa da franquia.
 * 
 * @param f Ponteiro para a franquia.
 * @return int Retorna o número de vitórias fora de casa da franquia.
 */
int GetVitoriaForaFranquia(tFranquia f){
    return f->vitF;

}

/**
 * @brief Retorna o número de derrotas em casa da franquia.
 * 
 * @param f Ponteiro para a franquia.
 * @return int Retorna o número de derrotas em casa da franquia.
 */
int GetDerrotaCasaFranquia(tFranquia f){
    return f->derD;

}

/**
 * @brief Retorna o número de derrotas fora de casa da franquia.
 * 
 * @param f Ponteiro para a franquia.
 * @return int Retorna o número de derrotas fora de casa da franquia.
 */
int GetDerrotaForaFranquia(tFranquia f){
    return f->derF;

}
