#ifndef PESSOA_H
#define PESSOA_H

#include "data.h"

#define TAMNOME 20
#define TAMCPF 11

// Definição da struct opaca para Pessoa
typedef struct pessoa tPessoa;

/**
 * @brief Aloca e inicializa uma nova estrutura tPessoa.
 * * @param nome Nome da pessoa.
 * @param cpf CPF da pessoa.
 * @param d Ponteiro para a data de nascimento (tData*).
 * @return tPessoa* Ponteiro para a nova pessoa.
 */
tPessoa* CriaPessoa(char* nome, char* cpf, tData *d);

/**
 * @brief Libera a memória alocada dinamicamente para a pessoa.
 * * @param p Ponteiro para a pessoa a ser liberada.
 */
void LiberaPessoa(tPessoa* p);

/**
 * @brief Lê os dados de uma pessoa da entrada padrão.
 * * @return tPessoa* Ponteiro para a nova pessoa lida.
 */
tPessoa* LePessoa();

/**
 * @brief Imprime os dados de uma pessoa.
 * * @param p Ponteiro para a pessoa a ser impressa.
 */
void ImprimePessoa(tPessoa* p);

/**
 * @brief Retorna o nome da pessoa.
 */
char* GetNome(tPessoa* pessoa);

/**
 * @brief Retorna o CPF da pessoa.
 */
char* GetCPF(tPessoa* pessoa);

/**
 * @brief Verifica se o CPF da pessoa é válido.
 */
int VerificaCPFValidoPessoa(char *cpf);

#endif