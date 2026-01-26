#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "banco.h"


int main(){

tBanco* b = CriaBanco();
tAgencia* a = NULL;
tConta* c = NULL;

char op;
int num;
LeBanco(b);

while(1){

    scanf(" %c\n", &op);
    if(op == 'F'){
        ImprimeRelatorioBanco(b);
        DestroiBanco(b);
        break;
    }else if(op == 'A'){
        a= CriaAgencia();
        LeAgencia(a);
        AdicionaAgencia(b, a);
    }else if(op == 'C'){
        c = CriaConta();
        LeConta(c);
        scanf(" %d\n", &num);
        InsereContaBanco(b, num, c);
    }


}



    return 0;
}