#include "calculadora.h"
#include <stdio.h>

int main() {
    printf("Soma: %2.f\n", soma(1.1, 2.2));
    printf("Subtração: %2.f\n", subtrai(1.1, 2.2));
    printf("Multiplicação: %2.f\n", multiplica(1.1, 2.2));
    printf("Divisão: %2.f\n", divide(1.1, 2.2));
    return 0;
}
