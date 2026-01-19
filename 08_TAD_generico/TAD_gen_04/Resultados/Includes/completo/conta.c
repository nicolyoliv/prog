#include "conta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 50

/**
 * @brief Estrutura para representar uma conta bancária.
 */
 struct Conta {
    int num;
    char nome[TAM_NOME];
    float saldo;
 };

/**
 * @brief Função para criar uma nova conta bancária.
 * @return Um ponteiro para a nova conta bancária criada. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tConta *CriaConta(){
    tConta* c = (tConta*)calloc(1,sizeof(tConta));
    if(c==NULL){
        exit(1);
    }
    return c;
}

/**
 * @brief Função para destruir uma conta bancária.
 * @param conta A conta bancária a ser destruída.
 */
void DestroiConta(DataType conta){
    tConta * contaPtr = (tConta*)conta;
    free(contaPtr);
}

/**
 * @brief Função para ler uma conta bancária no formato "numero;nome do cliente;saldo inicial".
 * @param conta A conta bancária a ser lida.
 */
void LeConta(tConta *conta){
    scanf("%d;%[^;];%f", &conta->num, conta->nome, &conta->saldo);

}

/**
 * @brief Função para obter o saldo de uma conta bancária.
 * @param conta A conta bancária.
 * @return O saldo da conta bancária.
 */
float GetSaldoConta(tConta *conta){
    return conta->saldo;
}