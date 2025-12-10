#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


struct Array {
    int *num;
    int tam;
};


/**
 * @brief Inicializa um novo array.
 */
Array *CriarArray(){
    Array *a = (Array*) calloc(1, sizeof(Array));
    if(a == NULL){
        exit(1);
    }
    a->num = NULL;
    a->tam = 0;
    return a;
}


/**
 * @brief Libera a memória do array.
 */
void DestruirArray(Array *array){
    if(array == NULL) return;

    free(array->num);   // num é vetor de int
    free(array);
}


/**
 * @brief Lê elementos até encontrar um número seguido de ponto.
 * Formatos válidos: "1 2 3."   ou   "10 22 5." etc.
 */
void LerArray(Array *array){
    char entrada[50];

    while (1) {
        scanf("%s", entrada);

        int len = strlen(entrada);

        // caso termine com ponto
        int temPonto = (entrada[len - 1] == '.');

        if(temPonto) entrada[len - 1] = '\0';

        int valor = atoi(entrada);

        array->tam++;
        array->num = realloc(array->num, array->tam * sizeof(int));
        if(array->num == NULL) exit(1);

        array->num[array->tam - 1] = valor;

        if(temPonto) break;
    }
}


/**
 * @brief Ordena usando Bubble Sort.
 */
void OrdenarArray(Array *array){
    if(array->tam <= 1) return;

    for(int i = 0; i < array->tam - 1; i++){
        for(int j = 0; j < array->tam - i - 1; j++){
            if(array->num[j] > array->num[j + 1]){
                int temp = array->num[j];
                array->num[j] = array->num[j + 1];
                array->num[j + 1] = temp;
            }
        }
    }
}


/**
 * @brief Busca binária padrão.
 */
int BuscaBinariaArray(Array *array, int elementoBuscado){
    int inicio = 0;
    int fim = array->tam - 1;

    while(inicio <= fim){
        int meio = (inicio + fim) / 2;

        if(array->num[meio] == elementoBuscado)
            return meio;

        if(array->num[meio] < elementoBuscado)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }

    return -1;
}
