
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "paciente.h"

#define  QTD_LES 10 

struct  Paciente{
    char *nome;
    Data *data;
    char* cartaoSus;
    char genero; 
    int quantles;
    Lesao **lesao;
    int quantCir;
};


Paciente *criaPaciente(char *nome, char *cartaoSus, char genero, Data *dataNasc){
    Paciente *p = (Paciente*) calloc(1, sizeof(Paciente));
        if(p== NULL){
            exit(1);
    }
    p->nome = (char*)malloc(MAX_NOME_PAC*sizeof(char));
    if(p->nome == NULL){
        exit(1);
    }
      p->cartaoSus = (char*)malloc(MAX_CARTAO_SUS*sizeof(char));
    if(p->cartaoSus == NULL){
        exit(1);
    }
    p->lesao = (Lesao**) malloc(QTD_LES*sizeof(Lesao*));
        if(p->lesao == NULL){
            exit(1);
    }
    strcpy(p->nome, nome);
    strcpy(p->cartaoSus, cartaoSus);
    p->genero = genero;
    p->data = dataNasc;
    p->quantles =0;
    p->quantCir =0;

    return p;

}


Paciente *lerPaciente(){
    char nome[MAX_NOME_PAC];
    int dia, mes, ano;
    char cartaoSus[MAX_CARTAO_SUS];
    char genero;

    scanf(" %[^\n]\n", nome);
    Data *data = lerData();
    scanf(" %[^\n]\n", cartaoSus);
    scanf(" %c\n", &genero);;
    return criaPaciente(nome, cartaoSus, genero, data);


}


void adicionaLesaoPaciente(Paciente *p, Lesao *l){
    if(strcmp(getCartaoSusLesao(l), p->cartaoSus)==0){
        if(p->quantles<QTD_LES){
           
            p->lesao[p->quantles] = l;
            p->quantles++;
        }
      
    }
 
}


int calculaIdadePaciente(Paciente *p, Data *dataBase){
    
    return diferencaAnoData(p->data, dataBase);
}


char *getCartaoSusPaciente(Paciente *p){
    return p->cartaoSus;
}


int getNumLesoesPaciente(Paciente *p){
    return p->quantles;
}


int qtdLesoesCirurgicasPaciente(Paciente *p){
    int quant=0;
    for(int i = 0;i<p->quantles;i++){
    if(verificaCirurgicaLesao(p->lesao[i])){
        quant++;
    }
}
    return quant;
}


void imprimePaciente(Paciente *p){
    if(p->quantles>0){
    printf("- %s - ", p->nome);
    for(int i = 0;i<p->quantles;i++){
        imprimeIdLesao(p->lesao[i]);
    }
    printf("\n");
}
}


void liberaPaciente(Paciente *p){
    for(int i = 0;i<p->quantles;i++){
        liberaLesao(p->lesao[i]);
    }
    liberaData(p->data);
    free(p->lesao);
    free(p->nome);
    free(p->cartaoSus);
    free(p);
}

