#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "nba.h"


 struct nba {

 };

/**
 * @brief Cria uma nova instância da NBA.
 * 
 * @return tNBA Retorna um ponteiro para a nova instância da NBA.
 */
tNBA CriaNBA();

/**
 * @brief Roda a NBA, permitindo a interação com o usuário.
 * 
 * @param nba Ponteiro para a instância da NBA a ser executada.
 * @return tNBA Retorna um ponteiro para a instância da NBA após a execução.
 */
tNBA RodaNBA(tNBA nba);

/**
 * @brief Imprime o relatório final da NBA.
 * 
 * @param nba Ponteiro para a instância da NBA a ser impressa.
 */
void ImprimeRelatorioNBA(tNBA nba);

/**
 * @brief Libera a memória alocada para a instância da NBA.
 * 
 * @param nba Ponteiro para a instância da NBA a ser liberada.
 */
void LiberaNBA(tNBA nba);

