#include <stdio.h>
#include "calc.h"
#include <stdio.h>


typedef int(*opCallback)(int, int);

opCallback operacoes[128] = {NULL};


void inicializa_array_operacoes() {
    operacoes['+'] = soma; // ‘+’ = 43
    operacoes['-'] = sub; // ‘-’ = 45
    operacoes['*'] = mult; // ‘-’ = 45
    operacoes['/'] = div; // ‘-’ = 45


}

int calculadora(char op_cod, int num1, int num2) {
   
    return operacoes[op_cod](num1, num2);
}

int main(){
    int a = 10;
    int b = 20;
    inicializa_array_operacoes();
    printf("R: %d", calculadora('+', a,b));



    return 0;
}