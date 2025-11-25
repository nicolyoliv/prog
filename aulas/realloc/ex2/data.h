#ifndef _data
#define _data

typedef struct Data tData;

/**
 * @brief Aloca dinamicamente uma estrutura do tipo tData, e a retorna. 
 * Os campos dessa estrutura devem ser preenchidos inicialmente com -1.
 * 
 * @return tData - Data "Vazia"
 */
tData* CriaData();

/**
 * @brief Lê o dia, mês e ano e armazena em uma estrutura tData alocada dinamicamente.
 * 
 * @param data - Ponteiro para a estrutura onde os dados serão armazenados. Lembre-se: Não pode ter valor NULL.
 */
void LeData(tData* data);

/**
 * @brief Libera a memória alocada dinamicamente para uma estrutura do tipo tData, passada como parâmetro
 * @param data - Ponteiro para a estrutura onde os dados estão armazenados. 
*/
void LiberaData(tData* data);

void imprimeData(tData* data);
#endif