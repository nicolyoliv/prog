#include "banco.h"





Banco* criaBanco(){

Banco *b  = (*Banco) calloc(1,sizeof(Banco));
b->dados = (tPessoa**) calloc(1, sizeof(tPessoa*));
b->tamUsado = 0;
b->tamAlocado = 1;

return b;

}
void liberaBanco(Banco *b){
    for(int i =0; i<b->tamUsado;i++){
        LiberaPessoa(b->dados[i]);
    }
    free(b);
}
void insereBanco(Banco *b, tPessoa *p){
if(b->tamUsado == b->tamAlocado){
    b->tamAlocado+=1;
    b->dados = (tPessoa**) realloc(b->dados, b->tamAlocado *sizeof(tPessoa*));
}
b->dados[b->tamUsado] = p;
b->tamUsado++;
}

void impreimeBanco(Banco *b){
    for(int i = 0;i<b->tamUsado;i++){
        printf("-------Pessoa------\n");
        ImprimePessoa(b);

    }
}
