#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "professor.h"

struct Professor {
    char *nome;
    char *dataNascimento;
    char *departamento;
};

/**
 * @brief Cria um novo professor.
 */
tProfessor *CriaProfessor(char *nome, char *dataNascimento, char *departamento){
    tProfessor *p = (tProfessor *)calloc(1, sizeof(tProfessor));
    if(p == NULL){
        exit(1);
    }

    p->nome = (char *)malloc(strlen(nome) + 1);
    p->dataNascimento = (char *)malloc(strlen(dataNascimento) + 1);
    p->departamento = (char *)malloc(strlen(departamento) + 1);

    strcpy(p->nome, nome);
    strcpy(p->dataNascimento, dataNascimento);
    strcpy(p->departamento, departamento);

    return p;
}

/**
 * @brief Destroi um professor.
 */
void DestroiProfessor(tProfessor *prof){
    if(prof == NULL) return;

    free(prof->nome);
    free(prof->dataNascimento);
    free(prof->departamento);
    free(prof);
}

/**
 * @brief Lê um professor da entrada padrão.
 */
tProfessor *LeProfessor(){
    char nome[50];
    char dataNascimento[50];
    char departamento[50];

    scanf("%s\n", nome);
    scanf("%s\n", dataNascimento);
    scanf("%[^\n]\n", departamento);

    return CriaProfessor(nome, dataNascimento, departamento);
}

/**
 * @brief Compara o nome de dois professores.
 */
int ComparaNomeProfessor(tProfessor *prof1, tProfessor *prof2){
    return strcmp(prof1->nome, prof2->nome);
}

/**
 * @brief Salva um professor em arquivo binário.
 */
int SalvaProfessor(tProfessor *prof, FILE *file){
    int bytes = 0;
    int tam;

    tam = strlen(prof->nome) + 1;
    bytes += fwrite(&tam, sizeof(int), 1, file) * sizeof(int);
    bytes += fwrite(prof->nome, sizeof(char), tam, file);

    tam = strlen(prof->dataNascimento) + 1;
    bytes += fwrite(&tam, sizeof(int), 1, file) * sizeof(int);
    bytes += fwrite(prof->dataNascimento, sizeof(char), tam, file);

    tam = strlen(prof->departamento) + 1;
    bytes += fwrite(&tam, sizeof(int), 1, file) * sizeof(int);
    bytes += fwrite(prof->departamento, sizeof(char), tam, file);

    return bytes;
}

/**
 * @brief Carrega um professor de arquivo binário.
 */
int CarregaProfessor(tProfessor *prof, FILE *file){
    int bytes = 0;
    int tam;


    free(prof->nome);
    free(prof->dataNascimento);
    free(prof->departamento);

    bytes += fread(&tam, sizeof(int), 1, file) * sizeof(int);
    prof->nome = (char *)malloc(tam);
    bytes += fread(prof->nome, sizeof(char), tam, file);

    bytes += fread(&tam, sizeof(int), 1, file) * sizeof(int);
    prof->dataNascimento = (char *)malloc(tam);
    bytes += fread(prof->dataNascimento, sizeof(char), tam, file);

    bytes += fread(&tam, sizeof(int), 1, file) * sizeof(int);
    prof->departamento = (char *)malloc(tam);
    bytes += fread(prof->departamento, sizeof(char), tam, file);

    return bytes;
}

/**
 * @brief Imprime o nome de um professor.
 */
void ImprimeNomeProfessor(tProfessor *prof){
    printf("%s\n", prof->nome);
}
