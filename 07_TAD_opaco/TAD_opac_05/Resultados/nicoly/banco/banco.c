#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "banco.h"
#include "conta.h"

#define TAM 5
 struct Banco {

    tConta** conta; 
    int quant;
    int contaAloc;
 };

/**
 * @brief Cria um novo banco, com 5 contas alocadas e nenhuma conta aberta.
 * Se não for possível alocar memória, o programa é encerrado.
 * 
 * @return Um ponteiro para o novo banco criado.
 */
tBanco *CriaBanco(){
// 1. Aloca a estrutura do Banco
    tBanco* banco = (tBanco*) malloc(sizeof(tBanco));
    if(banco == NULL){
        exit(EXIT_FAILURE);
    }
    
    // 2. Aloca o array inicial de ponteiros para contas (TAM = 10)
    banco->conta = (tConta**) malloc(TAM * sizeof(tConta*));
    if(banco->conta == NULL){
        free(banco);
        exit(EXIT_FAILURE);
    }
    
    // 3. Inicializa os ponteiros no array para NULL
    for(int i = 0; i < TAM; i++){
        banco->conta[i] = NULL; // Correção: Atribuição (=)
    }
    
    banco->quant = 0;
    banco->contaAloc = TAM;
    return banco;
}

/**
 * @brief Desaloca a memória de um banco e de todas as suas contas.
 * 
 * @param banco Ponteiro para o banco a ser destruído.
 */
void DestroiBanco(tBanco *banco){
if(banco){
    for(int i=0; i<banco->quant;i++){
        DestroiConta(banco->conta[i]);
    }
}
free(banco->conta);
free(banco);

}

/**
 * @brief Abre uma nova conta no banco e a adiciona ao vetor de contas.
 * 
 * @param banco Ponteiro para o banco onde a conta será aberta.
 */
void AbreContaBanco(tBanco *banco){
// 1. Verifica se precisa REALOCAR
    if(banco->quant == banco->contaAloc){
        banco->contaAloc += TAM;
        
        // REALOCAÇÃO (realloc)
        tConta** novoArray = (tConta**) realloc(banco->conta, banco->contaAloc * sizeof(tConta*));
        if (novoArray == NULL) {
                                // Se falhar, o estado anterior (banco->conta) é preservado.
            return;
        }
        banco->conta = novoArray;

        // Opcional: inicializar os novos ponteiros para NULL
        for (int i = banco->quant; i < banco->contaAloc; i++) {
            banco->conta[i] = NULL;
        }
    }

    // 2. Cria e Lê a conta no índice correto (banco->quant)
    banco->conta[banco->quant] = CriaConta();
    LeConta(banco->conta[banco->quant]); // Correção: Passa a conta recém-criada
    
    banco->quant++;
}

/**
 * @brief Realiza um saque em uma conta do banco se ela existir e tiver saldo suficiente.
 * Nessa função é necessário ler o número da conta e o valor do saque.
 * 
 * @param banco Ponteiro para o banco onde a conta será sacada.
 */
void SaqueContaBanco(tBanco *banco){
int numero=0;
float valor=0.0;
scanf("%d %f\n", &numero,&valor);

for(int i = 0; i < banco->quant; i++){
    if(VerificaConta(banco->conta[i], numero)){
        // Realiza a transação
        SaqueConta(banco->conta[i], valor); // ou DepositoConta
        break; // <-- Adicionado para sair do loop
    }
}
}
/**
 * @brief Realiza um depósito em uma conta do banco se ela existir.
 * Nessa função é necessário ler o número da conta e o valor do depósito. 
 * 
 * @param banco Ponteiro para o banco onde a conta será depositada.
 */
void DepositoContaBanco(tBanco *banco){
int numero=0;
float valor=0.0;
scanf("%d %f\n", &numero,&valor);

for(int i = 0;i<banco->quant;i++){

if(VerificaConta(banco->conta[i], numero)){
DepositoConta(banco->conta[i], valor);
}}
}

/**
 * @brief Realiza uma transferência entre duas contas do banco se elas existirem e a conta de origem tiver saldo suficiente.
 * Nessa função é necessário ler o número da conta de origem, o número da conta de destino e o valor da transferência.
 * 
 * @param banco Ponteiro para o banco onde as contas estão.
 */
void TransferenciaContaBanco(tBanco *banco){

int numero1 = 0, numero2 = 0;
    float valor = 0.0;
    // CORREÇÃO: Formato de leitura correto para float (valor)
    scanf("%d %d %f", &numero1, &numero2, &valor); 

    tConta *origem = NULL;
    tConta *destino = NULL;

    // Busca das contas. A transferência só será feita APÓS o loop.
    for(int i = 0; i < banco->quant; i++){
        // Busca a Origem
        if(origem == NULL && VerificaConta(banco->conta[i], numero1)){
            origem = banco->conta[i];
        }
        // Busca o Destino
        if(destino == NULL && VerificaConta(banco->conta[i], numero2)){
            destino = banco->conta[i];
        }
        
        // Otimização: Se ambas foram encontradas, para a busca
        if(origem != NULL && destino != NULL){
            break; 
        }
    }
    
    // CORREÇÃO: Transação Única. Executa SOMENTE se ambas foram localizadas
    if(origem != NULL && destino != NULL){
        TransferenciaConta(origem, destino, valor);
    }
}

/**
 * @brief Imprime o relatório do banco, com todas as contas e seus respectivos dados.
 * 
 * @param banco Ponteiro para o banco a ser impresso.
 */
void ImprimeRelatorioBanco(tBanco *banco){
printf("===| Imprimindo Relatorio |===\n");
for(int i = 0; i<banco->quant;i++){
    ImprimeConta(banco->conta[i]);
    printf("\n");
}

}