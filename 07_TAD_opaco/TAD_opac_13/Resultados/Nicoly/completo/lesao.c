
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

/*
Função que cria uma lesão a partir dos parâmetros fornecidos.
@param cartaoSus: Cartão SUS do paciente associado à lesão.
@param id: Identificador único da lesão.
@param diagnostico: Diagnóstico da lesão.
@param regiao: Região do corpo onde a lesão está localizada.
@param malignidade: Indicador de malignidade (1 para maligna, 0 para benigna).
@return Ponteiro para a lesão criada.
*/
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

/*
Função que lê os dados de uma lesão a partir da entrada padrão. Consulte o enunciado e/ou os casos de teste para o formato esperado.
@return Ponteiro para a lesão lida.
*/
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

/*
Função que obtém o cartão SUS associado a uma lesão.
@param l: Ponteiro para a lesão da qual se deseja obter o cartão SUS.
@param cartaoSus: String onde o cartão SUS será armazenado.
*/
char *getCartaoSusLesao(Lesao *l){
    return l->cartaoSus;
}

/*
Função que verifica se uma lesão é cirúrgica (maligna).
@param l: Ponteiro para a lesão a ser verificada.
@return 1 se a lesão for cirúrgica (maligna), 0 caso contrário.
*/
int verificaCirurgicaLesao(Lesao *l){
    if(l->malig > 50){
        return 1;
    }return 0;
}

/*
Função que imprime o identificador de uma lesão.
@param l: Ponteiro para a lesão cuja identificação será impressa.
*/
void imprimeIdLesao(Lesao *l){
    printf("%s\n", l->id);
}

/*
Função que libera a memória alocada para uma lesão.
@param l: Ponteiro para a lesão a ser liberada.
*/
void liberaLesao(Lesao *l){
    free(l->cartaoSus);
    free(l->id);
    free(l->diag);
    free(l->regiao);
    free(l);
}

