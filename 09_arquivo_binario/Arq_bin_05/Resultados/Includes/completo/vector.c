#include <stdlib.h>
#include "vector.h"

struct Vector {
    DataType *dados;
    int tamanho;
};

Vector *VectorConstruct(){
   Vector* v = (Vector*)calloc(1, sizeof(Vector));
   if(v==NULL){
    exit(1);
}
return v;
}

void VectorPushBack(Vector *v, DataType val){
   v->dados = realloc(v->dados, (v->tamanho+1)*sizeof(DataType));
   v->dados[v->tamanho++] = val;
}

DataType VectorGet(Vector *v, int i){
    return v->dados[i];
}

int VectorSize(Vector *v){
    return v->tamanho;
}

void VectorDestroy(Vector *v, void (*destroy)(DataType)){
   for(int i = 0; i<v->tamanho; i++){
    destroy(v->dados[i]);
   }free(v->dados);
   free(v);
}
