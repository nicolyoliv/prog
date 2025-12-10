#include "vendedor.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

 struct Vendedor {
    char *nome;
    float valortotal;
    float salario;
    float perc;

 };


/**
 * @brief Registra um novo vendedor.
 * 
 * @param nome Nome do vendedor.
 * @param salario Salário base do vendedor.
 * @param prct_comissao Porcentagem de comissão do vendedor.
 * @return tVendedor Retorna a estrutura do tipo tVendedor com os dados do vendedor registrado.
 */
tVendedor* RegistraVendedor(char* nome, float salario, float prct_comissao){
    tVendedor *v = (tVendedor*) calloc(1, sizeof(tVendedor));
    if(v==NULL){
        exit(1);
    }
v->nome = (char*) malloc(100 * sizeof(char));
    if(v->nome == NULL){
        exit(1);
    }
    strcpy(v->nome, nome);
    v->salario = salario;
    v->perc = prct_comissao;
    v->valortotal = 0.0;

return v;
}

/**
 * @brief Libera a memória alocada para um vendedor.
 * 
 * @param vendedor Ponteiro para o vendedor a ser apagado.
 */
void ApagaVendedor(tVendedor* vendedor){
    free(vendedor->nome);
    free(vendedor);
}

/**
 * @brief Verifica se o nome de um vendedor é igual a outro.
 * 
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor a ser verificado.
 * @param nome Nome do vendedor a ser comparado.
 * @return int Retorna 1 se o nome do vendedor é igual ao nome passado como parâmetro, ou 0 caso contrário.
 */
int VerificaNomeVendedor(tVendedor* vendedor, char* nome){
    if(strcmp(vendedor->nome, nome)==0){
        return 1;
    }
    return 0;
}

/**
 * @brief Contabiliza uma venda para um vendedor.
 * 
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor (será alterada)
 * @param valor Valor da venda a ser contabilizada.
 */
void ContabilizaVenda(tVendedor* vendedor, float valor){
    vendedor->valortotal+=valor;
}

/**
 * @brief Obtém o salário de um vendedor.
 * 
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor.
 * @return float Retorna o salário do vendedor.
 */
float GetSalario(tVendedor* vendedor){
    return vendedor->salario;
}

/**
 * @brief Obtém a comissão de um vendedor.
 * 
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor.
 * @return float Retorna a comissão do vendedor.
 */
float GetComissao(tVendedor* vendedor){
    return vendedor->valortotal*vendedor->perc;
}

/**
 * @brief Obtém o total vendido por um vendedor.
 * 
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor.
 * @return float Retorna o total vendido pelo vendedor.
 */
float GetTotalVendido(tVendedor* vendedor){
    return vendedor->valortotal;
}

/**
 * @brief Obtém o total recebido por um vendedor.
 * 
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor.
 * @return float Retorna o total recebido pelo vendedor (salário + comissão).
 */
float GetTotalRecebido(tVendedor* vendedor){
    return vendedor->salario+GetComissao(vendedor);
}

/**
 * @brief Imprime o relatório de um vendedor.
 * 
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor.
 */
void ImprimeRelatorioVendedor(tVendedor* vendedor){
    printf("%s > Total vendido: R$%.2f\n", vendedor->nome, GetTotalVendido(vendedor));
    printf("     Total recebido: R$%.2f\n", GetTotalRecebido(vendedor));
}