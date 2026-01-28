#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aluno.h"

 struct Aluno{
    char *nome;
    char *dataNascimento;
    char *curso;
    float prctConclusao;
    float cfRendimento;

 } ;

/**
 * @brief Cria um novo aluno.
 * @param nome Nome do aluno.
 * @param dataNascimento Data de nascimento do aluno.
 * @param curso Curso do aluno.
 * @param prctConclusao Percentual de conclusão do curso.
 * @param cfRendimento Coeficiente de rendimento do aluno.
 * @return Um ponteiro para a estrutura do aluno criada. Caso a alocação falhe, a função termina o programa.
 */
tAluno *CriaAluno(char *nome, char *dataNascimento, char *curso, float prctConclusao, float cfRendimento){
    tAluno* a = (tAluno*)calloc(1, sizeof(tAluno));
    if(a== NULL){
        exit(1);
    }

    a->nome = (char*)malloc((strlen(nome)+1)*sizeof(char));
    a->dataNascimento = (char*)malloc((strlen(dataNascimento)+1)*sizeof(char));
    a->curso = (char*)malloc((strlen(curso)+1)*sizeof(char));

    strcpy(a->nome, nome);
    strcpy(a->dataNascimento, dataNascimento);
    strcpy(a->curso, curso);

    a->cfRendimento = cfRendimento;
    a->prctConclusao = prctConclusao;
    return a;

}

/**
 * @brief Destroi um aluno.
 * @param aluno Ponteiro para a estrutura do aluno a ser destruída.
 */
void DestroiAluno(tAluno *aluno){
        free(aluno->nome);
        free(aluno->dataNascimento);
        free(aluno->curso);
        free(aluno);

}

/**
 * @brief Lê um aluno da entrada padrão.
 * @return Um ponteiro para a estrutura do aluno lida.
 */
tAluno *LeAluno(){
    char nome[50];
    char dataNascimento[50];
    char curso[50];
    float prctConclusao;
    float cfRendimento;
    scanf("%s\n", nome);
    scanf("%s\n", dataNascimento);
    scanf("%[^\n]\n", curso);
    scanf("%f\n", &prctConclusao);
    scanf("%f\n", &cfRendimento);

return CriaAluno(nome, dataNascimento, curso,  prctConclusao,  cfRendimento);



}

/**
 * @brief Compara o nome de dois alunos.
 * @param aluno1 Ponteiro para a estrutura do primeiro aluno.
 * @param aluno2 Ponteiro para a estrutura do segundo aluno.
 * @return Um inteiro indicando o resultado da comparação, conforme a função strcmp.
 */
int ComparaNomeAluno(tAluno *aluno1, tAluno *aluno2){
    return strcmp(aluno1->nome, aluno2->nome);
}

/**
 * @brief Salva um aluno em um arquivo binário.
 * @param aluno Ponteiro para a estrutura do aluno a ser salva.
 * @param file Ponteiro para o arquivo onde o aluno será salvo.
 * @return Um inteiro indicando o número de bytes salvos deste aluno.
 */
int SalvaAluno(tAluno *aluno, FILE *file){
    int bytes = 0;
    int tam;

    tam = strlen(aluno->nome) + 1;
    bytes += fwrite(&tam, sizeof(int), 1, file) * sizeof(int);
    bytes += fwrite(aluno->nome, sizeof(char), tam, file);

    tam = strlen(aluno->dataNascimento) + 1;
    bytes += fwrite(&tam, sizeof(int), 1, file) * sizeof(int);
    bytes += fwrite(aluno->dataNascimento, sizeof(char), tam, file);

    tam = strlen(aluno->curso) + 1;
    bytes += fwrite(&tam, sizeof(int), 1, file) * sizeof(int);
    bytes += fwrite(aluno->curso, sizeof(char), tam, file);

    bytes += fwrite(&aluno->prctConclusao, sizeof(float), 1, file) * sizeof(float);
    bytes += fwrite(&aluno->cfRendimento, sizeof(float), 1, file) * sizeof(float);

    return bytes;
}


/**
 * @brief Carrega um aluno de um arquivo binário.
 * @param aluno Ponteiro para a estrutura do aluno a ser carregada.
 * @param file Ponteiro para o arquivo de onde o aluno será carregado.
 * @return Um inteiro indicando o número de bytes lidos deste aluno.
 */
int CarregaAluno(tAluno *aluno, FILE *file){
    int bytes = 0;
    int tam;

    free(aluno->nome);
    free(aluno->dataNascimento);
    free(aluno->curso);

    bytes += fread(&tam, sizeof(int), 1, file) * sizeof(int);
    aluno->nome = malloc(tam);
    bytes += fread(aluno->nome, sizeof(char), tam, file);

    bytes += fread(&tam, sizeof(int), 1, file) * sizeof(int);
    aluno->dataNascimento = malloc(tam);
    bytes += fread(aluno->dataNascimento, sizeof(char), tam, file);

    bytes += fread(&tam, sizeof(int), 1, file) * sizeof(int);
    aluno->curso = malloc(tam);
    bytes += fread(aluno->curso, sizeof(char), tam, file);

    bytes += fread(&aluno->prctConclusao, sizeof(float), 1, file) * sizeof(float);
    bytes += fread(&aluno->cfRendimento, sizeof(float), 1, file) * sizeof(float);

    return bytes;
}


/**
 * @brief Imprime o nome de um aluno na saída padrão.
 * @param aluno Ponteiro para a estrutura do aluno cujo nome será impresso.
 */
void ImprimeNomeAluno(tAluno *aluno){
    printf("%s\n", aluno->nome);
}
