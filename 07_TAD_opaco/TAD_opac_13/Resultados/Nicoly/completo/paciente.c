
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

/*
Função que cria um paciente a partir dos parâmetros fornecidos.
@param nome: Nome do paciente.
@param cartaoSus: Cartão SUS do paciente.
@param genero: Gênero do paciente.
@param dataNasc: Data de nascimento do paciente.
@return Ponteiro para o paciente criado.
*/
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

/*
Função que lê os dados de um paciente a partir da entrada padrão. Consulte o enunciado e/ou os casos de teste para o formato esperado.
@return Ponteiro para o paciente lido.
*/
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

/*
Função que adiciona uma lesão ao paciente.
Basicamente, a lesão é adicionada à lista de lesões do paciente realizando toda a alocação dinâmica necessária.
@param p: Ponteiro para o paciente ao qual a lesão será vinculada.
@param l: Ponteiro para a lesão a ser vinculada ao paciente.
*/
void adicionaLesaoPaciente(Paciente *p, Lesao *l){
    if(strcmp(getCartaoSusLesao(l), p->cartaoSus)==0){
        if(p->quantles<QTD_LES){
           
            p->lesao[p->quantles] = l;
            p->quantles++;
        }
      
    }
 
}

/*
Função que calcula a idade do paciente em anos completos com base em uma data de referência.
@param p: O paciente cuja idade será calculada.
@param dataBase: A data de referência para o cálculo da idade.
@return A idade do paciente em anos completos.
*/
int calculaIdadePaciente(Paciente *p, Data *dataBase){
    
    return diferencaAnoData(p->data, dataBase);
}

/*
Função que obtém o cartão SUS de um paciente.
@param p: Ponteiro para o paciente do qual se deseja obter o cartão SUS.
@return Ponteiro para cartão SUS do paciente.
*/
char *getCartaoSusPaciente(Paciente *p){
    return p->cartaoSus;
}

/*
Função que obtém o número de lesões associadas a um paciente.
@param p: Ponteiro para o paciente cuja quantidade de lesões será obtida.
@return O número de lesões do paciente.
*/
int getNumLesoesPaciente(Paciente *p){
    return p->quantles;
}

/*
Função que calcula a quantidade de lesões cirúrgicas (malignas) associadas a um paciente.
@param p: Ponteiro para o paciente cuja quantidade de lesões cirúrgicas será calculada.
@return A quantidade de lesões cirúrgicas do paciente.
*/
int qtdLesoesCirurgicasPaciente(Paciente *p){
    int quant=0;
    for(int i = 0;i<p->quantles;i++){
    if(verificaCirurgicaLesao(p->lesao[i])){
        quant++;
    }
}
    return quant;
}

/*
Função que imprime o nome do paciente e o ID das lesões associadas a ele (exatamente como solicitado no enunciado e nos casos de teste).
@param p: Ponteiro para o paciente cujas informações serão impressas.
*/
void imprimePaciente(Paciente *p){
    if(p->quantles>0){
    printf("- %s - ", p->nome);
    for(int i = 0;i<p->quantles;i++){
        imprimeIdLesao(p->lesao[i]);
    }
    printf("\n");
}
}

/*
Função que libera a memória alocada para um paciente.
@param p: Ponteiro para o paciente a ser liberado.
*/
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

