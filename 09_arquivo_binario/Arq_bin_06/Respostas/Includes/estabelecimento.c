#include <stdio.h>
#include <stdlib.h>
#include "estabelecimento.h"
#include "vector.h"

/**
 * @brief Estrutura para representar um estabelecimento.
 */
 struct Estabelecimento {
    Vector* produto;
 };

/**
 * @brief Função para criar um novo estabelecimento.
 * @return Um ponteiro para o estabelecimento recém-criado. Se houver erro na alocação, o programa é encerrado.
 */
tEstabelecimento *CriaEstabelecimento(){
    tEstabelecimento* e = (tEstabelecimento*)calloc(1, sizeof(tEstabelecimento));
    if(e==NULL){
        exit(1);
    }

    e->produto= VectorConstruct();
    return  e;
}

/**
 * @brief Função para destruir um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento a ser destruído.
 */
void DestroiEstabelecimento(tEstabelecimento *estabelecimento){
    VectorDestroy(estabelecimento->produto,(void*)DestroiProduto);
    free(estabelecimento);
}

/**
 * @brief Função para adicionar um produto a um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento.
 * @param produto Um ponteiro para o produto a ser adicionado.
 */
void AdicionaProdutoEstabelecimento(tEstabelecimento *estabelecimento, tProduto *produto){
    VectorPushBack(estabelecimento->produto, produto);
}

/**
 * @brief Função para ler um estabelecimento de um arquivo binário.
 * Inicialmente, deverá ser lido o nome do arquivo binário pela entrada padrão.
 * O arquivo binário deverá ser composto por um inteiro que representa a quantidade de produtos no estabelecimento, seguido pelos produtos.
 * @param estabelecimento Um ponteiro para o estabelecimento a ser lido.
 */
void LeEstabelecimento(tEstabelecimento *estabelecimento){
    char arquivo[100];
    int quant;

    scanf("%s", arquivo);
    FILE* f = fopen(arquivo, "rb");
    fread(&quant, sizeof(int), 1, f);
    tProduto* p;
    for(int i = 0; i<quant; i++){
        p=LeProduto(f);
        AdicionaProdutoEstabelecimento(estabelecimento, p);

    }
    fclose(f);
}

/**
 * @brief Função para obter o valor total de produtos vendidos em um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento.
 * @return O valor total de produtos vendidos.
*/
float GetValorTotalVendidoEstabelecimento(tEstabelecimento *estabelecimento){
    float total = 0.0;
    int tam = VectorSize(estabelecimento->produto);

    for(int i = 0; i< VectorSize(estabelecimento->produto); i++){
        
        tProduto* p = (tProduto*)VectorGet(estabelecimento->produto, i);
        total += GetPrecoProduto(p) * GetQuantidadeVendidaProduto(p);
    }
    return total;
}

/**
 * @brief Função para imprimir na tela um relatório de um estabelecimento, cotendo o valor total vendido e a porcentagem de cada produto relativo ao total vendido.
 * Formato: Codigo;Nome;Preco;Quantidade vendida
 * @param estabelecimento Um ponteiro para o estabelecimento.
*/
void ImprimeRelatorioEstabelecimento(tEstabelecimento *estabelecimento){
   float totalVendido = GetValorTotalVendidoEstabelecimento(estabelecimento);
    printf("Valor total vendido: R$ %.2f\n",  GetValorTotalVendidoEstabelecimento(estabelecimento));
    printf("Produtos vendidos:\n");
    printf("Codigo;Nome;Preco;Quantidade vendida;Porcentagem\n");
    for(int i = 0; i< VectorSize(estabelecimento->produto); i++){
        tProduto* p = (tProduto*)VectorGet(estabelecimento->produto, i);
        ImprimeProduto(p);
        float valorIndividual = GetPrecoProduto(p) * GetQuantidadeVendidaProduto(p);
        float porcentagem = 0.0;
porcentagem = (valorIndividual / totalVendido) * 100;

printf(";%.2f%%\n", porcentagem);    }
}
