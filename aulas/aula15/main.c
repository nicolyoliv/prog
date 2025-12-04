#include <stdio.h>
    float calcmedia(int *nota, int quant, char tipo){
        float soma = 0.0;
        for(int i =0; i<quant; i++){
            if(tipo == 'i'){
                int *notasInterias = (int*)nota;
               
            soma += notasInterias[i];
        }else if(tipo == 'f'){
             float *notasInterias = (float*)nota;
               
            soma += notasInterias[i];
        }
    }
        return soma/quant;
    }


int main(){
    int qtd =5;
    int nota1[] = {1,7,9,10,10};
    int nota2[] = {5.6, 7.9, 8.8, 7.7, 4.5};

printf("-media 1: %f\n", calcmedia(nota1, qtd, 'i'));
printf("-media 2: %f\n", calcmedia(nota2, qtd, 'f'));

    return 0;
}