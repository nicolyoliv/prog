#include "aluno.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void imprimeNotas(float *notas, int n){
    for(int i = 0; i<n; i++){
        printf("%f\n", notas[i]);
    }
};

void lerNotas(float *notas, int n){
    for(int i = 0; i<n; i++){
        scanf("%f\n", &notas[i]);
    }
};
float calcMedia(float *notas, int n){
    float soma = 0;
    for(int i = 0; i<n; i++){
        soma +=notas[i];
    }
return soma/n;
};
float calcDesv(float *notas, int n){
    float somadiff = 0.0, diff= 0.0;
    float media = calcMedia(notas, n);
    for(int i = 0; i<n; i++){
        diff = pow(notas[i]- media,2);
        somadiff +=diff;
    }
return sqrt(diff/n);
};

int main(){

int n;
float *notas, media = 0.0, desv = 0.0;
scanf("%d\n", &n);

notas = (float*) calloc (n, sizeof(float));
lerNotas(notas, n);
imprimeNotas(notas, n);
media = calcMedia(notas, n);
desv = calcDesv(notas, n);
free(notas);


}