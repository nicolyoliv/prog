#include "agendatarefas.h"
#include "tarefaimprime.h"
#include "tarefasoma.h"
#include "tarefamultiplica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

int quant;
printf("Digite o numero de tarefas:\n");
scanf("%d", &quant);

tAgendaTarefas * agenda = CriaAgendaDeTarefas(quant);

for(int i = 0; i< quant; i++){
    int prio;
    char tipo;
    char msg[100];
   
    scanf("%d %c", &prio, &tipo);

    if(tipo == 'I'){
        scanf(" %[^\n]s", msg);
        tImpr *imprime = CriaTarefaImprimir(msg);
        CadastraTarefaNaAgenda(agenda, prio, imprime, ExecutaTarefaImprimir, DestroiTarefaImprimir);
    }else if(tipo == 'S'){
        float n1, n2;
        scanf("%f %f", &n1, &n2);
        tSoma* soma = CriaTarefaSoma(n1, n2);
        CadastraTarefaNaAgenda(agenda, prio, soma, ExecutaTarefaSoma, DestroiTarefaSoma);
    }else if(tipo == 'M'){
                float n1, n2;
        scanf("%f %f", &n1, &n2);
        tMult* mult = CriaTarefaMultiplicar(n1, n2);
        CadastraTarefaNaAgenda(agenda, prio, mult, ExecutaTarefaMultiplicar, DestroiTarefaMultiplicar);

    }else{
           printf("\nDigite um tipo de tarefa suportado (I/S/M))");
                scanf(" %[^\n]\n", msg);
                i--;
    }

}


    ExecutarTarefasDaAgenda(agenda);
    DestroiAgendaDeTarefas(agenda);


    return 0;
}