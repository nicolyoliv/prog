#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "agendatarefas.h"

 typedef struct  {
 int prioridade;
 void *tarefa;
 void (*execute)(void*);
 void(*destroi)(void*);
 }Tarefas;

 struct agendatarefas {
    Tarefas *tarefas;
    int capacidade;
    int tamanho;
};

/**
 * @brief Cria uma variável para um tipo genérico que representa uma Agenda de Tarefas
 *
 * @param numElem A quantidade de tarefas que serão armazenadas no agendador
 *
 * @return Um ponteiro para a agenda de tarefas
 */
tAgendaTarefas* CriaAgendaDeTarefas(int numElem){
    tAgendaTarefas* t = (tAgendaTarefas*) calloc(1,sizeof(tAgendaTarefas));
    if(t == NULL){
        exit(1);
    }
    t->tarefas = (Tarefas*)calloc(numElem, sizeof(Tarefas));
    t->capacidade = numElem;
    t->tamanho = 0;
    return t;
}

/**
 * @brief Destroi a agenda de tarefas (libera a memória)
 *
 * @param tar - A agenda que terá seu conteúdo liberado/destruído
 */
void DestroiAgendaDeTarefas(tAgendaTarefas* tar){
  if(tar){
    for(int i = 0; i< tar->tamanho;i++){
        Tarefas TarefaAtual = tar->tarefas[i];
        void(*DestroiFuncao)(void*) = TarefaAtual.destroi;
        void* tarefa = TarefaAtual.tarefa;

        DestroiFuncao(tarefa);
    }
    free(tar->tarefas);
    free(tar);
  }
}

/**
 * @brief Cadastra uma tarefa em um agendador de tarefas
 *
 * @param tar - Pointeiro para a agenda de tarefas
 * @param prioridade - Prioridade de execução da nova tarefa
 * @param tarefa - Ponteiro para nova tarefa a ser executada
 * @param executa - Ponteiro para função (callback) que será chamada quando for a hora de executar a tarefa
 * @param destroi - Ponteiro para função (callback) que será chamada quando for a hora de destruir a tarefa (liberar a memória)
 *
 */
void CadastraTarefaNaAgenda(tAgendaTarefas* tar, int prioridade, void *tarefa, void (*executa)(void*), void (*destroi)(void*) ){
    if(tar && tar->tamanho < tar->capacidade){
        Tarefas novaTarefa = {prioridade, tarefa, executa, destroi};
        tar->tarefas[tar->tamanho++]= novaTarefa;
    }
}   

int compareTarefas(const void *a, const void *b){
    Tarefas *tarefaA = (Tarefas *)a;
    Tarefas *tarefaB = (Tarefas *)b;
    return tarefaB->prioridade - tarefaA->prioridade;
}

/**
 * @brief Executa as tarefas que estão salvas na agenda de tarefas passada como parâmetro.
 *
 * @param tar Agenda de tarefas
 *
 */
void ExecutarTarefasDaAgenda(tAgendaTarefas* tar){
    qsort(tar->tarefas, tar->tamanho, sizeof(Tarefas), compareTarefas);
    for(int i = 0; i<tar->tamanho; i++){
        Tarefas tarefaAtual = tar->tarefas[i];
        void (*executeFuncao)(void*) = tarefaAtual.execute;
        void * tarefa = tarefaAtual.tarefa;
        executeFuncao(tarefa);
    }
}