#include "ponto.h"
#include <stdio.h>
#include <math.h>


int main(){


    float x1, y1, x2, y2;

    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);

Ponto p1 = pto_cria(x1, y1);
Ponto p2 = pto_cria(x2, y2);

printf("%g\n", pto_distancia(p1, p2));



    return 0;
}