#include <stdio.h>
#include <math.h>

typedef struct{

    float x, y, raio;
}tCirculo;

float calcDist(tCirculo alvo, tCirculo tiro){

    float dist = sqrt(pow((alvo.x-tiro.x),2)+pow((tiro.y-alvo.y),2));

    return dist;
}

int main(){

    tCirculo alvo, tiro;


    float dist = 0.0, soma = 0.0;

    scanf("%f %f %f %f %f %f", &alvo.x, &alvo.y, &alvo.raio, &tiro.x, &tiro.y, &tiro.raio);

    soma = alvo.raio+tiro.raio;

dist = calcDist(alvo, tiro) ;

if(dist<=soma){
    printf("ACERTOU\n");
}else{
    printf("ERROU\n");
}

    return 0;
}