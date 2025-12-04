#ifndef ARRAY_H
#define ARRAY_H

typedef void(*func_ptr_imprime)(void *item);
typedef void(*func_ptr_desaloca)(void *item);

typedef struct Array Array;





Array *criaArray();
void adicionaItemArray(Array *a, void *item);
void *getItemPosicaoArray(Array *a, int pos);
int getQtd(Array *a);
void imprimeArray(Array *a);



#endif