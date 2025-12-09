#include <stdio.h>
#include <stdlib.h>

//void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));

int comparaArrayInteiros(const void *d1, const void *d2){
    int a = *(int*)d1;
    int b = *(int*)d2;


    if(a>b){
        return 1;
    }else if(b>a){
        return -1;
    }else{
        return 0;
    }
}  

void imprimeArray(int *array, int tam){
    for(int i = 0;i<tam;i++){
        printf("%d", array[i]);
    }
}

int *copiaArray(int *original, int tam){
   int *copia = (int*) calloc(tam, sizeof(int));
    for(int i = 0;i<tam;i++){
        copia[i] = original[i];
    }
    return copia;
}

void copiaArray2(int *original, int *copia, int tam){
     for(int i = 0;i<tam;i++){
         copia[i] = original[i];
     }
 }
int main(){

    int notas[] = {1, 5, 7, 10, 4, 11, 6, 2, 1, 3};
    int tam = 10;
    int *copiaNota = copiaArray(notas, tam); 
 qsort( *notas, tam, sizeof(int), comparaArrayInteiros);

imprimeArray(copiaNota, tam);

free(copiaNota);


    return 0;
}