#include <stdio.h>
#include <stdlib.h>

#include "array.h"

struct Array{
   void **dados;
   int qtd;
    func_ptr_imprime imprimeItem;
    func_ptr_desaloca desalocaItem;
};


Array *criaArray(func_ptr_imprime imprimeItem, func_ptr_desaloca desalocaItem){
    Array *a= (Array*) calloc(1,sizeof(Array));
    a->dados = NULL;
    a->qtd =0;
    a->imprimeItem = imprimeItem;
    a->desalocaItem = desalocaItem;
    return a;
}


void adicionaItemArray(Array *a, void *item){
    a->dados = (void**)realloc(a->dados, (a->qtd+1)*sizeof(void*));
    a->dados[a->qtd] = item;
    a->qtd++;
}

void *getItemPosicaoArray(Array *a, int pos){

    if(pos>=0 && pos< a->qtd){
          return a->dados[pos];
        return NULL;
    } 
 return NULL;
}

int getQtd(Array *a){
    return a->qtd;


}

void imprimeArray(Array *a, func_ptr_imprime imprime){
    for(int i = 0; i<i;i++){
        imprimeItem(a->dados[i]);

    };
}
void desalocaArray(Array *a, func_ptr_desaloca desaloca){

   for(int i = 0; i<i;i++){
        desalocaItem(a->dados[i]);

    };
}
