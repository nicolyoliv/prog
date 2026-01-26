#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "agencia.h"

#define TAM 100

/**
 * @brief Estrutura para representar uma agência bancária.
 */
struct Agencia {
    char nome[TAM];
    tConta** conta;
    int num;
    int tam;

};

/**
 * @brief Função para criar uma nova agência bancária.
 * @return Um ponteiro para a nova agência bancária criada. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tAgencia *CriaAgencia(){
    tAgencia* a = (tAgencia*)calloc(1, sizeof(tAgencia));
    if(a == NULL){
        exit(1);
    }
a->conta = NULL;
a->tam = 0;
    return a;
}

/**
 * @brief Função para destruir uma agência bancária.
 * @param agencia A agência bancária a ser destruída.
 */
void DestroiAgencia(DataType agencia){
    tAgencia* agenciaPtr = (tAgencia*)agencia; 
    for(int i = 0; i<agenciaPtr->tam; i++){
        DestroiConta(agenciaPtr->conta[i]);
    }free(agenciaPtr->conta);
    free(agenciaPtr);
}

/**
 * @brief Função para ler uma agência bancária no formato "numero;nome".
 * @param agencia A agência bancária a ser lida.
 */
void LeAgencia(tAgencia *agencia){
    scanf("%d;%[^\n]\n", &agencia->num, agencia->nome);
}

/**
 * @brief Função para adicionar uma conta bancária a uma agência bancária.
 * @param agencia A agência bancária.
 * @param conta A conta bancária a ser adicionada.
 */
void AdicionaConta(tAgencia *agencia, tConta *conta){
    agencia->conta = realloc(agencia->conta, (agencia->tam+1)* sizeof(tConta*));
    agencia->conta[agencia->tam]= conta;
    agencia->tam++;
}

/**
 * @brief Função para comparar um número de agência bancária com uma agência bancária.
 * @param numAgencia O número da agência bancária.
 * @param agencia2 A agência bancária a ser comparada.
 * @return 1 se os números forem iguais, 0 caso contrário.
 */
int ComparaAgencia(int numAgencia, tAgencia *agencia2){
    if(numAgencia == agencia2->num){
        return 1;
    }else{
        return 0;
    }
}

/**
 * @brief Função para obter o saldo médio das contas de uma agência bancária.
 * @param agencia A agência bancária.
 * @return O saldo médio das contas da agência.
 */
float GetSaldoMedioAgencia (tAgencia *agencia){
    float soma = 0.0;
    for(int i = 0; i<agencia->tam; i++){
        soma +=GetSaldoConta(agencia->conta[i]);
    }
    return soma/agencia->tam;
}

/**
 * @brief Função para imprimir os dados de uma agência bancária (nome, número, número de contas cadastradas e saldo médio).
 * @param agencia A agência bancária.
 */
void ImprimeDadosAgencia(tAgencia *agencia){
    
    printf("\t\tNome: %s\n", agencia->nome);
    printf("\t\tNumero: %d\n", agencia->num);
    printf("\t\tNumero de contas cadastradas: %d\n", agencia->tam);;
    printf("\t\tSaldo médio: R$%.2f\n", GetSaldoMedioAgencia(agencia));
    printf("\n\n");
}

