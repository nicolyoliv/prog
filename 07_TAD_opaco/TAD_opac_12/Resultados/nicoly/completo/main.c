#include <stdio.h>
#include "array.h"

int main(){
    Array *a = CriarArray();

    LerArray(a);
    OrdenarArray(a);

    int elemento;
    scanf("%d", &elemento);

    int indice = BuscaBinariaArray(a, elemento);

    if(indice == -1){
        printf("Elemento %d não encontrado no array (-1).\n", elemento);
    } else {
        printf("Elemento %d encontrado no índice %d.\n", elemento, indice);
    }

    DestruirArray(a);
    return 0;
}
