#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "base_alunos.h"
#include "aluno.h"

/**
 * @brief Estrutura para representar uma base de alunos.
 */
 struct BaseAlunos {
    int quant;
    tAluno** aluno;
 };

/**
 * @brief Função para criar uma nova base de alunos.
 * 
 * @return Um ponteiro para a base de alunos recém-criada. Se houver erro na alocação de memória, o programa é encerrado.
 */
tBaseAlunos* CriarBaseAlunos(){
    tBaseAlunos* b = (tBaseAlunos*)calloc(1, sizeof(tBaseAlunos));
    if(b==NULL){
        exit(1);
    }
    b->aluno = NULL;
    b->quant = 0;
    return b;
}

/**
 * @brief Função para destruir uma base de alunos.
 * 
 * @param baseAlunos A base de alunos a ser destruída.
 */
void DestruirBaseAlunos(tBaseAlunos* baseAlunos){
    for(int i = 0; i< baseAlunos->quant;i++){
        DestruirAluno(baseAlunos->aluno[i]);
    }
    free(baseAlunos->aluno);
    free(baseAlunos);
}

/**
 * @brief Função para ler uma base de alunos de um arquivo binário.
 * 
 * @param baseAlunos A base de alunos para ler o arquivo.
 * @param nomeArquivo O nome do arquivo a ser lido.
 */
void LerBaseAlunos(tBaseAlunos* baseAlunos, char* nomeArquivo){
   FILE *f = fopen(nomeArquivo, "rb");
    if (!f) exit(1);
    fread(&baseAlunos->quant, sizeof(int),1, f );
    baseAlunos->aluno = (tAluno**)malloc(baseAlunos->quant* sizeof(tAluno*));
    for(int i = 0; i<baseAlunos->quant; i++){
        baseAlunos->aluno[i] = LeAluno(f);
    }
fclose(f);
}

/**
 * @brief Função para obter o coeficiente de rendimento médio de uma base de alunos.
 * 
 * @param baseAlunos A base de alunos para obter o coeficiente de rendimento médio.
 * @return O coeficiente de rendimento médio da base de alunos.
 */
float GetCoeficienteRendimentoMedioBaseAlunos(tBaseAlunos* baseAlunos){

    float media = 0.0;
    float soma = 0.0;
    for(int i = 0; i<baseAlunos->quant; i++){
    soma += GetCoeficienteRendimentoAluno(baseAlunos->aluno[i]);
     }
    return soma/baseAlunos->quant;
    }

