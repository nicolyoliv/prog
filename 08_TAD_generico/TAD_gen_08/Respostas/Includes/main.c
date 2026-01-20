#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fila.h"
#include "movel.h"
#include "vector.h"


int main(){

    int quant;
    Fila * fila = FilaConstruct();
    tMovel *movel = NULL;
    scanf("%d\n", &quant);
    for(int i = 0; i<quant;i++){
        int op[100];
        scanf(" %s", op);
        if(strcmp(op, "ENTRADA")== 0){

            movel = LeMovel();
           FilaPush(fila, movel);
        }else if(strcmp(op, "PRODUZIR")== 0){
            movel = (tMovel*)FilaPop(fila);
            ImprimeMovel(movel);
            DestroiMovel(movel);
        }
    }
FilaDestroy(fila, DestroiMovel);

    return 0;
}

