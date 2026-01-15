#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tadgen.h"



 struct generic {
    Type type;
    int numElem;
    void *data;
 };

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar tanto inteiros quanto floats
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tGeneric* CriaGenerico(Type type, int numElem){
    tGeneric *gen = (tGeneric*) calloc(1, sizeof(tGeneric));
    if(gen==NULL){
        exit(1);
    }
    gen->type = type;
    gen->numElem = numElem;

    if(type == INT){
        gen->data = (int*) malloc(sizeof(int) * numElem);
    }else if(type == FLOAT){
        gen->data = (float*) malloc(sizeof(float) * numElem); 
    }

    if(gen->data == NULL){
        free(gen);
        return NULL;
    }
    return gen;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param gen - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiGenerico(tGeneric* gen){
    free(gen->data);
    free(gen);
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param gen - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LeGenerico(tGeneric* gen){
    if(gen->type == INT){
        for(int i = 0; i< gen->numElem;i++){
            scanf("%d", &((int*)gen->data)[i]);
        }
    }else if(gen->type == FLOAT){
        for(int i = 0; i< gen->numElem;i++){
            scanf("%f", &((float*)gen->data)[i]);
        }
    }
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param gen - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimeGenerico(tGeneric* gen){
    printf("\nDigite o vetor:\n");

    if(gen->type == INT){
        for(int i = 0; i<gen->numElem;i++){
            printf("%d ", ((int*)gen->data)[i]);
        }
    }else if(gen->type == FLOAT){
        for(int i = 0; i<gen->numElem;i++){
            printf("%.2f ", ((float*)gen->data)[i]);
        }
    }
    printf("\n");
}
