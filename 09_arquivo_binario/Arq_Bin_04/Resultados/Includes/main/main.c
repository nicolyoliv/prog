#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "histograma.h"


int main(){

    int n;
    char caminho[100];

    scanf("%s", caminho);
    scanf("%d", &n);

    Imagem* i = LerImagem(caminho);
    Histograma* h = CalcularHistograma(i, n);
    MostrarHistograma(h);
    DestruirImagem(i);
    DestruirHistograma(h);


    return 0;
}