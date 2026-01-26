#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gerenciadorpacotes.h"


int main(){

int op;
int tipo, tam;
int idx;
tGerenciador* g = CriaGerenciador();

while(1){

printf("\nEscolha uma opcao:\n");
printf("\t\t(1) Cadastrar um novo pacote\n");
printf("\t\t(2) Imprimir um pacote especifico\n");
printf("\t\t(3) Imprimir todos os pacotes e sair\n");



scanf("%d", &op);
if(op == 3){
    ImprimirTodosPacotes(g);
    DestroiGerenciador(g);
    break;
}else if(op == 1){
    printf("Digite o tipo (0-char, 1-int) e o numero de elementos do pacote/mensagem:");
    scanf("%d %d", &tipo, &tam);
    if(tipo > 1){
        printf("Digite um tipo valido!\n");
        continue;
    }
    tPacote* pac = CriaPacote(tipo, tam);
    LePacote(pac);
    AdicionaPacoteNoGerenciador(g, pac);
}else if(op == 2){
scanf("%d", &idx);

ImprimirPacoteNoIndice(g, idx);
}else if(op > 3){
    printf("Escolha uma opcao valida para o menu!\n");

}




}

    return 0;
}