#include "data.h"
#include <stdio.h>

/**
 * @brief Lê uma data da entrada padrão.
 * @return Um ponteiro para a data lida.
 */
tData* LeData(){
    tData* data = (tData*) calloc(1, sizeof(tData));


int dia, mes, ano;


    scanf("%d/%d/%d\n", &dia, &mes, &ano);

    data = CriaData(dia, mes,ano);
return data;
}

/**
 * @brief Cria uma data com o dia, mês e ano fornecidos. Se a alocação falhar, o programa é encerrado.
 * @param dia O dia da data.
 * @param mes O mês da data.
 * @param ano O ano da data.
 * @return Um ponteiro para a data criada.
 */
tData* CriaData(int dia, int mes, int ano){

    tData* data = (tData*) calloc(1, sizeof(tData));
        if(data == NULL){
            exit(1);
        }

        data->dia = dia;
        data->ano = ano;
        data->mes = mes;

        return data;
    
}

/**
 * @brief Libera a memória alocada para uma data.
 * @param d Um ponteiro para a data a ser liberada.
 */
void LiberaData(tData* d);

/**
 * @brief Calcula a idade de uma pessoa com base na data de nascimento e em uma data para calcular a idade.
 * @param nascimento Um ponteiro para a data de nascimento da pessoa.
 * @param diacalc Um ponteiro para a data para calcular a idade.
 * @return A idade da pessoa.
 */
int CalculaIdadeData(tData* nascimento, tData* diacalc);

/**
 * @brief Imprime uma data na saída padrão.
 * @param d Um ponteiro para a data a ser impressa.
 */
void ImprimeData(tData* d);

