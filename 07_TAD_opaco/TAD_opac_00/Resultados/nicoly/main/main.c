#include <stdio.h>
#include "circulo.h"


int main(){

float x1, y1, r, px, py;
tPonto ponto;
tCirculo circulo;

scanf("%f %f %f %f %f", &x1, &y1, &r, &px, &py);

ponto = Pto_Cria(px, py);
circulo = Circulo_Cria(x1, y1, r);
int resultado = Circulo_Interior(circulo, ponto);
printf("%d\n", resultado);
  Circulo_Apaga(circulo);
    Pto_Apaga(ponto);

    return 0;
}