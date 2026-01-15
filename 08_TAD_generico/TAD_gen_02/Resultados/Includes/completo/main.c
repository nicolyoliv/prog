#include "gerenciadorpacotes.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main(){

int op, tipo, numElem, idx;
tGerenciador *g = CriaGerenciador();
do{

printf("\nEscolha uma opcao:\n");
printf("(1) Cadastrar um novo pacote\n");
printf("(2) Imprimir um pacote especifico\n");
printf("(3) Imprimir todos os pacotes e sair\n");
scanf("%d", &op);
if(op== 1){
    printf("Digite o tipo (0-char, 1-int) e o numero de elementos do pacote/mensagem:");
    scanf("%d %d", &tipo, &numElem);
    if(tipo !=0 && tipo !=1){
        printf("Digite um tipo valido!\n");
      continue;

    }
tPacote *p = CriaPacote(tipo, numElem);
LePacote(p);
AdicionaPacoteNoGerenciador(g, p);
}else if(op==2){
    scanf("%d", &idx);
    ImprimirPacoteNoIndice(g, idx);
}else if(op>3){
    printf("Escolha uma opcao valida para o menu!\n");
  
}
}while(op!=3);
ImprimirTodosPacotes(g);

DestroiGerenciador(g);

    return 0;
}