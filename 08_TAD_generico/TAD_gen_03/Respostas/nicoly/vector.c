#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


 struct Vector {
    data_type *vetor;
    int tamanho;
 };

/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct(){
    Vector* v = (Vector*)calloc(1,sizeof(Vector));
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
void VectorPushBack(Vector *v, data_type val){
    v->tamanho++;
    if(!v->tamanho){
        v->vetor = (data_type*)calloc(1,sizeof(data_type));

    }else{
        v->vetor = (data_type*)realloc(v->vetor, v->tamanho * sizeof(data_type));
    }
    v->vetor[v->tamanho-1]= val;
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return data_type Elemento do vetor
*/
data_type VectorGet(Vector *v, int i){
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
void VectorDestroy(Vector *v, void (*destroy)(data_type)){
    for(int i = 0; i<VectorSize(v);i++){
        destroy(v->vetor[i]);
    }
    free(v->vetor);
    free(v);
}