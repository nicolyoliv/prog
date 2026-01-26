#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fila.h"
#include "movel.h"


int main(){

int quant;

Fila* f = FilaConstruct();
tMovel* m = NULL;

char op[100];
scanf("%d", &quant);
for(int i =0; i<quant; i++){
    scanf("%s", op);
if(strcmp(op, "ENTRADA")== 0){
    m = LeMovel();
    FilaPush(f, m);
}else if(strcmp(op, "PRODUZIR")==0){
    m = (tMovel*)FilaPop(f);
    ImprimeMovel(m);
    DestroiMovel(m);

}


}
FilaDestroy(f, DestroiMovel);

    return 0;
}