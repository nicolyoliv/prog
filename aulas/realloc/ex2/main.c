#include <stdio.h>
#include "pessoa.h"
#include "banco.h"
#define TAM_INCIO 20
#define TAMINCREMENTO 20

int main(){

char cod;
int tamAlocado = TAM_INCIO;
int tamUsado = 0;

// tPessoa **bancoPessoa = (tPessoa**) calloc(TAM_INCIO, sizeof(tPessoa*));
// tPessoa*  pessoa = LePessoa();


while(1){

scanf("%c\n", &cod);

if(cod == 'f'){
    break;
}else if(cod == 'p'){
    tPessoa *pessoa = lePessoa();
    insereBanco(banco, pessoa);

if(tamUsado == tamAlocado){
    tamAlocado += TAMINCREMENTO;
    bancoPessoa = (tPessoa**) realloc(bancoPessoa,TAMINCREMENTO* sizeof(tPessoa*));
}

    bancoPessoa[tamUsado] = pessoa;
    tamUsado++;
}



}
for(int i=0; i<tamUsado;i++){
    imprimePessoa(bancoPessoa[i]);
}


for(int i=0; i<tamAlocado;i++){
    liberaPessoa(bancoPessoa[i]);
}

free(bancoPessoa);
    return 0;
}


