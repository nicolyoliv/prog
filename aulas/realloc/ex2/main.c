#include <stdio.h>
#include "pessoa.h"

#define TAM_INCIO 20
#define TAMINCREMENTO 20

int main(){

char cod;
int tamAlocado = TAM_INCIO;
int tamUsado = 0;

tPessoa * bancoPessoa = (tPessoa*) calloc(TAM_INICIO, sizeof(tPessoa));
tPessoa* pessoa;


while(1){

scanf("%c\n", &cod);

if(cod == 'f'){
    break;
}else if(cod == 'p'){
    pessoa = lePessoa();

if(tamUsado == tamAlocado){
    tamAlocado += TAMINCREMENTO;
    bancoPessoa = 
}

    bancoPessoa[tamUsado] = *pessoa;
    tamUsado++;
}



}
for(int i=0; i<tamUsado;i++){
    imprimePessoa(&bancoPessoa[i]);
}


for(int i=0; i<tamUsado;i++){
    liberaPessoa(&bancoPessoa[i]);
}

free(bancoPessoa);
    return 0;
}