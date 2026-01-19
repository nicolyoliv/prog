#include "banco.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TAM_NOME 50

/**
 * @brief Estrutura para representar um banco.
 */
 struct Banco {
    char nome[TAM_NOME];
    Vector *agencias;
    int qAgencia;
 };

/**
 * @brief Função para criar um novo banco.
 * @return Um ponteiro para o novo banco criado. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tBanco *CriaBanco(){
    tBanco* b = (tBanco*)calloc(1,sizeof(tBanco));
    if(b==NULL){
        exit(1);
    }
    b->agencias = VectorConstruct();
    b->qAgencia = 0;
    return b;
}

/**
 * @brief Função para destruir um banco.
 * @param banco O banco a ser destruído.
 */
void DestroiBanco(tBanco *banco){
    VectorDestroy(banco->agencias, DestroiAgencia);
    free(banco);
}

/**
 * @brief Função para ler o nome de um banco.
 * @param banco O banco a ser lido.
 */
void LeBanco(tBanco *banco){
    scanf("%[^\n]\n", banco->nome);
}

/**
 * @brief Função para adicionar uma agência a um banco.
 * @param banco O banco.
 * @param agencia A agência a ser adicionada.
 */
void AdicionaAgencia(tBanco *banco, tAgencia *agencia){
    VectorPushBack(banco->agencias, agencia);
    banco->qAgencia++;
}

/**
 * @brief Função para inserir uma conta em uma agência pertencente ao banco.
 * @param banco O banco.
 * @param numAgencia O número da agência.
 * @param cliente A conta a ser inserida.
 * @pre A agência deve pertencer ao banco.
*/
void InsereContaBanco(tBanco *banco, int numAgencia, tConta *cliente){
    for(int i = 0; i<banco->qAgencia;i++){
        tAgencia* agencia = (tAgencia*)VectorGet(banco->agencias, i);
        if(ComparaAgencia(numAgencia, agencia)){
            AdicionaConta(agencia, cliente);
            return;
        }
    }
            printf("Agencia nao encontrada.\n");

    
}

/**
 * @brief Função para imprimir o relatório de um banco, com o nome do banco e a lista de agências.
 * @param banco O banco.
 */
void ImprimeRelatorioBanco(tBanco *banco){
    printf("%s\n", banco->nome);
    printf("Lista de agencias:\n");
    for(int i = 0;i<banco->qAgencia;i++){
        tAgencia *agencia = (tAgencia*)VectorGet(banco->agencias,i);
        ImprimeDadosAgencia(agencia);
                printf("\n");

    }

}
