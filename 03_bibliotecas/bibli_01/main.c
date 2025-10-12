#include <stdio.h>
#include "esfera_utils.h"

int main(){

    float raio, vol, area;

    scanf("%f", &raio);

    area = calcula_area(raio);
    vol = calcula_volume(raio);

    printf("Area: %.2f\n", area);
    printf("Volume: %.2f\n", vol);



}