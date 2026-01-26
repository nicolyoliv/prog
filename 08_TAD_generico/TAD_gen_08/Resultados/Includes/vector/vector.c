#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vector.h"

 struct Vector {
    DataType *vetor;
    int tamanho;
 };

/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct(){
    Vector * v = (Vector*)calloc(1,sizeof(Vector));
    if(v == NULL){
        exit(1);
    }
    return v;
}

/**
 * @brief Adiciona um elemento no final do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, DataType val){
    v->tamanho++;
    if(!v->tamanho){
        v->vetor = (DataType*)calloc(1, sizeof(DataType));
    }else{
        v->vetor = (DataType*)realloc(v->vetor, v->tamanho*sizeof(DataType));
    }
    v->vetor[v->tamanho-1]= val;
}

/**
 * @brief Remove o primeiro elemento do vetor e organiza os demais elementos, ou seja, 
 * o segundo elemento passa a ser o primeiro, o terceiro passa a ser o segundo, e assim por diante.
 * 
 * @param v Ponteiro para o vetor
 * @return DataType Elemento removido
*/
DataType VectorPopFront(Vector *v){
if(v->tamanho == 0){
        exit(1);
    }

    DataType removido = v->vetor[0];

    for(int i = 1; i < v->tamanho; i++){
        v->vetor[i - 1] = v->vetor[i];
    }

    v->tamanho--;

    if(v->tamanho > 0){
        v->vetor = realloc(v->vetor, v->tamanho * sizeof(DataType));
    }else{
        free(v->vetor);
        v->vetor = NULL;
    }

    return removido;
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return DataType Elemento do vetor
*/
DataType VectorGet(Vector *v, int i){
    return v->vetor[i];
}

/**
 * @brief Retorna o tamanho do vetor
 * 
 * @param v Ponteiro para o vetor
 * @return int Tamanho do vetor
*/
int VectorSize(Vector *v){
    return v->tamanho;
}

/**
 * @brief Libera a memória alocada para o vetor
 * 
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
*/
void VectorDestroy(Vector *v, void (*destroy)(DataType)){
    for(int i = 0; i<v->tamanho;i++){
        destroy(v->vetor[i]);
    }
    free(v->vetor);
    free(v);
}

