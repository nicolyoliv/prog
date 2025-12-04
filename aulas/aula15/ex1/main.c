#include <stdio.h>
#include "array.h"

void imprimeInteiro(void *item){
    int *d = (int *)item;
    printf("nota = %d\n", *d);
}
void desacolaInteiro(void *item){
        int *d = (int *)item;
free(d);
}

int main(){

Array *notas = criaArray(imprimeInteiro, desacolaInteiro);

while (1)
{
    int *n = (int*) calloc(1, sizeof(int));
    scanf("%d\n", n);
    if(*n==-1){
        free(n);
        break;
    }
    adicionaItemArray(notas, n);
}
imprimeArray(notas);
desalocaArray(notas);

    return 0;
}