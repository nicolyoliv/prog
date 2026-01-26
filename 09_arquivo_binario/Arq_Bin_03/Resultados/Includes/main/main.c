#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "imagem.h"



int main(){

char caminho[100];

scanf("%s", caminho);
Imagem* i = LerImagem(caminho);
printf("Numero de bytes lidos: %d\n", ObterNumeroBytesLidos(i));
ImprimirImagem(i);
DestruirImagem(i);

    return 0;
}