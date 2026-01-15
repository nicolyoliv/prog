
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lesao.h"


struct  Lesao{
    char *cartaoSus;
    char *id;
    char *diag;
    char *regiao;
    int malig;
};


Lesao *criaLesao(char *cartaoSus, char *id, char *diagnostico, char *regiao, int malignidade){
    Lesao *l = (Lesao*)calloc(1, sizeof(Lesao));
    if(l==NULL){
        exit(1);
    }
    l->cartaoSus = (char*)malloc(MAX_CARTAO_LES * sizeof(char));
    if(l->cartaoSus==NULL){
        exit(1);
    }
    l->diag = (char*)malloc(MAX_DIAG_LES * sizeof(char));
    if(l->diag==NULL){
        exit(1);
    }
    l->id = (char*)malloc(MAX_ID_LES * sizeof(char));
    if(l->id==NULL){
        exit(1);
    }
    l->regiao = (char*)malloc(MAX_REG_LES * sizeof(char));
    if(l->regiao==NULL){
        exit(1);
    }
    
    strcpy(l->cartaoSus , cartaoSus);
    strcpy(l->id , id);
    strcpy(l->diag , diagnostico);
    strcpy(l->regiao , regiao);

    l->malig = malignidade;
    return l;
}


Lesao *lerLesao(){
    char cartaoSus[MAX_CARTAO_LES];
    char id[MAX_ID_LES];
    char diag[MAX_DIAG_LES];
    char regiao[MAX_REG_LES];
    int malig;
    scanf(" %[^\n]\n", cartaoSus);
    scanf(" %[^\n]\n", id);
    scanf(" %[^\n]\n", diag);
    scanf(" %[^\n]\n", regiao);
    scanf(" %d\n", &malig);
    return criaLesao(cartaoSus, id, diag, regiao, malig);
}


char *getCartaoSusLesao(Lesao *l){
    return l->cartaoSus;
}


int verificaCirurgicaLesao(Lesao *l){
    if(l->malig > 50){
        return 1;
    }return 0;
}


void imprimeIdLesao(Lesao *l){
    printf("%s\n", l->id);
}


void liberaLesao(Lesao *l){
    free(l->cartaoSus);
    free(l->id);
    free(l->diag);
    free(l->regiao);
    free(l);
}

