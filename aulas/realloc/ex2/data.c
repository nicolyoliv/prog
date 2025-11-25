#include "data.h"
#include <stdio.h>
#include <stdlib.h>
 struct Data {
    int dia, mes, ano;
 };

/**
 * @brief Aloca dinamicamente uma estrutura do tipo tData, e a retorna. 
 * Os campos dessa estrutura devem ser preenchidos inicialmente com -1.
 * 
 * @return tData - Data "Vazia"
 */
tData* CriaData(){
    tData* data = (tData*) malloc (sizeof(tData));
    if(data ==NULL){
        exit(1);
    }
    data->dia = -1;
    data->mes = -1;
    data->ano = -1;
    return data;
}

/**
 * @brief Lê o dia, mês e ano e armazena em uma estrutura tData alocada dinamicamente.
 * 
 * @param data - Ponteiro para a estrutura onde os dados serão armazenados. Lembre-se: Não pode ter valor NULL.
 */
void LeData(tData* data){
 scanf(" %d/%d/%d\n", &data->dia ,&data->mes , &data->ano);
}

/**
 * @brief Libera a memória alocada dinamicamente para uma estrutura do tipo tData, passada como parâmetro
 * @param data - Ponteiro para a estrutura onde os dados estão armazenados. 
*/
void LiberaData(tData* data){
free(data);
}
