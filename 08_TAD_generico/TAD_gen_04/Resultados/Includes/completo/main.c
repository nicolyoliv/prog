#include "banco.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

int numAgencia;
char op;

tBanco *banco = CriaBanco();
tAgencia *agencia = NULL;
tConta *conta = NULL;

LeBanco(banco);

while(1){
scanf(" %c\n", &op);
if(op== 'F'){
    ImprimeRelatorioBanco(banco);
    DestroiBanco(banco);
    break;
}else if(op== 'A'){
    agencia = CriaAgencia();
    LeAgencia(agencia);
    AdicionaAgencia(banco, agencia);
  
}else if(op== 'C'){
    conta = CriaConta();
    LeConta(conta);
     scanf(" %d\n", &numAgencia);
    InsereContaBanco(banco, numAgencia, conta);

}


}


    return 0;
}