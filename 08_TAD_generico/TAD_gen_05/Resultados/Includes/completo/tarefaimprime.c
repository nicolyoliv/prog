#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tarefaimprime.h"


 struct impr {
    char *msg;
 };

/**
 * @brief Cria uma tarefa do tipo impressão em tela
 * 
 * @param msg - A mensagem que deve ser impressa em tela
 *
 * @return Um ponteiro para a tarefa criada
 */
tImpr* CriaTarefaImprimir(char *msg){
    tImpr* i = (tImpr*)calloc(1,sizeof(tImpr));
    if(i==NULL){
        exit(1);
    }
    i->msg = malloc(strlen(msg)+1);
    if(i->msg == NULL){
        exit(1);
    }
    strcpy(i->msg, msg);
    return i;
}

/**
 * @brief Função que executa uma tarefa de impressão em tela
 *
 * @param imp - Ponteiro para a tarefa a ser executada
 *
 */
void ExecutaTarefaImprimir(void *imp){
    tImpr* i = (tImpr*)imp;
    if(imp){
        printf("\n%s", i->msg);
   } else {
        printf("Erro ao executar tarefa de impressao\n");
    }
}

/**
 * @brief Função que destrói (libera a memória) uma tarefa de impressão em tela
 *
 * @param imp - Ponteiro para a tarefa a ser destruída
 *
 */
void DestroiTarefaImprimir(void *imp){
    tImpr* i = (tImpr*)imp;
    free(i->msg);
    free(i);
}