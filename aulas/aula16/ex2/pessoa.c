#include "pessoa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura
struct pessoa{
    char nome [TAMNOME];
    tData *Nasc; // Deve ser tData*
    char cpf[TAMCPF];
};

/**
 * @brief Aloca e inicializa uma nova estrutura tPessoa.
 */
tPessoa* CriaPessoa(char* nome, char* cpf, tData *d){
    // CORREÇÃO: Tamanho correto e uso de tPessoa
    tPessoa* p = (tPessoa*) calloc(1, sizeof(tPessoa));
    if (p == NULL) {
        exit(1);
    }

    p->nome[TAMNOME - 1] = '\0'; 
    
  
    p->cpf[TAMCPF - 1] = '\0'; 
    
    p->Nasc = d; 

    return p;
}

/**
 * @brief Libera a memória alocada dinamicamente para a pessoa.
 */
void LiberaPessoa(tPessoa* p){
    if (p == NULL) return;
    
    // CORREÇÃO: Não usamos free(p->nome) ou free(p->cpf) pois são arrays internos (alocação estática no struct)
    
    // Libera a data de nascimento, se não for NULL
    if (p->Nasc != NULL) {
        LiberaData(p->Nasc);
    }
    
    free(p);
}

/**
 * @brief Lê os dados de uma pessoa da entrada padrão.
 */
void LePessoa(tPessoa* p){
    char nome[TAMNOME];
    char cpf[TAMCPF];
    tData *d = CriaData();


scanf("%[^\n]\n", nome);

    scanf("%[^\n]\n", nome);
   
    LeData(d);

    strcpy(p->nome, nome);
    strcpy(p->cpf, cpf);
    p->Nasc = d;
}

/**
 * @brief Imprime os dados de uma pessoa.
 */
void ImprimePessoa(tPessoa* p){
    if (p == NULL) return;
    printf("Nome: %s\n", p->nome);
    printf("CPF: %s\n", p->cpf);
    printf("Nascimento: ");
    ImprimeDataExtenso(p->Nasc);
    printf("\n");
}

/**
 * @brief Retorna o nome da pessoa.
 */
char* GetNome(tPessoa* pessoa){
    return pessoa->nome;
}

/**
 * @brief Retorna o CPF da pessoa.
 */
char* GetCPF(tPessoa* pessoa){
    return pessoa->cpf;
}

/**
 * @brief Verifica se o CPF da pessoa é válido (Implementação básica).
 */
int VerificaCPFValidoPessoa(char *cpf){
    // Implementação simplificada: verifica apenas o tamanho (10 caracteres + '\0')
    if (strlen(cpf) != TAMCPF - 1) { 
        return 0; // Inválido se o tamanho não for o esperado (10)
    }
    
    // Aqui deveria vir a lógica completa de validação do CPF (dígitos verificadores)
    return 1;
}