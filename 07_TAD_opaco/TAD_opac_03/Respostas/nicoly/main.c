#include <stdio.h>
#include "locadora.h"


int main(){

char op[20];
tLocadora* locadora = CriarLocadora();

    while(1){
        scanf("%s", op);

        if(!strcmp(op, "Cadastrar")){
            LerCadastroLocadora(locadora);
            OrdenarFilmesLocadora(locadora);
            scanf("%*c");
        }else if(!strcmp(op, "Alugar")){
            LerAluguelLocadora(locadora);
            scanf("%*c");
        }else if(!strcmp(op, "Devolver")){
            LerDevolucaoLocadora(locadora);
            scanf("%*c");
        } else if (!strcmp(op, "Estoque")) {
            ConsultarEstoqueLocadora(locadora);
            scanf("%*[^#]#");
        }else {
            break;
        }

        *op = '\0';
    }
       ConsultarLucroLocadora(locadora);
    DestruirLocadora(locadora);
    return 0;
}