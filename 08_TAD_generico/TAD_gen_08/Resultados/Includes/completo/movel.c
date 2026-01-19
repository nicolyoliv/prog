#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "movel.h"
/**
 * @brief Estrutura representando um Movel.
 */
 struct Movel {
    char *nome;
 };

/**
 * @brief Cria um novo Movel.
 * @param nome O nome do Movel.
 * @return Um ponteiro para o novo Movel.
 */
tMovel *CriaMovel(char *nome){
tMovel* m = (tMovel*)calloc(1,sizeof(tMovel));
if(m == NULL){
    exit(1);
}
m->nome = malloc(strlen(nome)+1);

strcpy(m->nome, nome);
return m;
}

/**
 * @brief Destroi um Movel.
 * @param m O Movel a ser destruído.
 */
void DestroiMovel(tMovel *m){
    free(m->nome);
    free(m);
}

/**
 * @brief Lê um Movel.
 * @return O Movel lido.
 */
tMovel *LeMovel(){
    char nome[100];
    scanf(" %[^\n]\n", nome);
    tMovel* m = CriaMovel(nome);
    return m;
}

/**
 * @brief Imprime o nome do movel.
 * @param m O Movel a ser impresso.
 */
void ImprimeMovel(tMovel *m){
    printf("%s\n", m->nome);
}

