#include <stdio.h>
#include "paciente.h"

/**
 * @brief Retorna o número do cartão SUS do paciente.
 * 
 * @param p Ponteiro para a estrutura de dados tPaciente contendo as informações do paciente.
 * @return Retorna uma string contendo o número do cartão SUS do paciente.
 */
char* GetCartaoSusPaciente(tPaciente* p);

/**
 * @brief Retorna a quantidade de lesões do paciente.
 * 
 * @param p Ponteiro para a estrutura de dados tPaciente contendo as informações do paciente.
 * @return Retorna a quantidade de lesões do paciente.
 */
int GetQtdLesoesPaciente(tPaciente* p);

/**
 * @brief Retorna a quantidade de cirurgias necessárias para tratar as lesões do paciente.
 * 
 * @param p Ponteiro para a estrutura de dados tPaciente contendo as informações do paciente.
 * @return Retorna a quantidade de cirurgias necessárias para tratar as lesões do paciente.
 */
int GetQtdCirurgiasPaciente(tPaciente* p);

/**
 * @brief Retorna a data de nascimento do paciente.
 * 
 * @param p Ponteiro para a estrutura de dados tPaciente contendo as informações do paciente.
 * @return Retorna a data de nascimento do paciente.
 */
tData* GetNascimentoPaciente(tPaciente* p);

/**
 * @brief Cria uma estrutura do tipo tPaciente
 * 
 * @return Retorna um ponteiro para a estrutura de dados tPaciente
 */
tPaciente* CriaPaciente();

/**
 * @brief Lê informações sobre um paciente do usuário.
 * 
 * @return Retorna um ponteiro para a estrutura de dados tPaciente contendo as informações lidas.
 */
void LePaciente(tPaciente* p);

/**
 * @brief Imprime as informações de um paciente na saída padrão.
 * 
 * @param p Ponteiro para a estrutura de dados tPaciente contendo as informações do paciente.
 */
void ImprimePaciente(tPaciente* p);

/**
 * @brief Libera a memória alocada para uma estrutura de dados tPaciente.
 * 
 * @param p Ponteiro para a estrutura de dados tPaciente a ser liberada.
 */
void LiberaPaciente(tPaciente* p);


/**
 * @brief Adiciona uma lesão à lista de lesões do paciente.
 * 
 * @param p Ponteiro para a estrutura de dados tPaciente contendo as informações do paciente.
 * @param l Ponteiro para a estrutura de dados tLesao contendo as informações da lesão.
*/
void AdicionaLesaoPaciente(tPaciente* p, tLesao* l);

