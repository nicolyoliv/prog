#include "relatorio.h"
#include "aluno.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Imprime o relatorio de uma coleção de alunos.
 * O relatorio deve possuir a media das notas, porcentagem de alunos aprovados e porcentagem de cada gênero.
 * 
 * @param alunos Ponteiro para o vetor de alunos.
*/
void ImprimeRelatorio(Vector *alunos){
    int tamanho = VectorSize(alunos);
    float qAprovados = 0;
    float qMasculino = 0, qFeminino = 0, qOutros = 0;
    float totalNotas = 0;

    for(int i = 0; i<tamanho;i++){
        tAluno* aluno = (tAluno*) VectorGet(alunos, i);
        totalNotas += GetNotaAluno(aluno);
        if(GetNotaAluno(aluno)>=6){
            qAprovados++;
        }if(GetGeneroAluno(aluno)== 'F'){
            qFeminino++;
        }else if(GetGeneroAluno(aluno)== 'M'){
            qMasculino++;
        }else{
            qOutros++;
        }
    }
            printf("Media das notas: %.2f\n",  totalNotas/(float) tamanho);
    printf("Porcentagem de alunos aprovados: %.2f%%\n", (qAprovados/tamanho)*100.0);
    printf("Porcentagem de cada genero:\n");
    printf("Masculino: %.2f%%\n", (qMasculino/tamanho)*100.0);
    printf("Feminino: %.2f%%\n", (qFeminino/tamanho)*100.0) ;
    printf("Outro: %.2f%%\n", (qOutros/tamanho)*100.0);
 

}