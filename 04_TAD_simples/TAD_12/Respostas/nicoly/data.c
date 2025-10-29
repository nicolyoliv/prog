#include <stdio.h>
#include "data.h"
/*typedef struct {
    int dia;
    int mes;
    int ano;
} Data;*/

/*
Função que cria uma data a partir do dia, mês e ano fornecidos e retorna a data criada.
@param dia: Dia da data.
@param mes: Mês da data.
@param ano: Ano da data.
@return Data criada.
*/
Data criaData(int dia, int mes, int ano){
    Data data;

    data.dia = dia;
    data.mes = mes;
    data.ano = ano;
    return data;
}

/*
Função que lê uma data do formato DD/MM/AAAA a partir da entrada padrão e retorna a data lida.
@return Data lida.
*/
Data lerData(){
    Data data;
    int dia, mes, ano;

    scanf(" %d/%d/%d\n", &dia, &mes, &ano);
    data = criaData(dia, mes, ano);
    return data;
}

/*
Função que calcula a diferença em anos entre duas datas. A diferença é calculada como o número de anos completos entre a data inicial e a data atual.
Ex: Se a data inicial for 15/08/2000 e a data atual for 14/08/2023, a diferença será 22 anos. 
@param inicial: Data inicial.
@param atual: Data atual.
@return Diferença em anos entre as duas datas.
*/
int diferencaAnoData(Data inicial, Data atual){
    int diferenca = 0;
    diferenca = atual.ano- inicial.ano;
    if(atual.ano> inicial.ano){
    if((atual.mes==inicial.mes && atual.dia < inicial.dia) || (atual.mes<inicial.mes)){
        diferenca--;
        }
    }
    return diferenca;
}

/*
Função que imprime uma data no formato DD/MM/AAAA.
@param d: Data a ser impressa.
*/
void imprimeData(Data d){
    printf("%.2d/%.2d/%d\n", d.dia, d.mes, d.ano);
}


