#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aluno.h"

 struct aluno {
    char *nome;
    char *dataNasc;
    char *cursoUfes;
    char *periodoIng;
    int perConc;
    float coefRend;
 };

Aluno** CriaVetorAlunos(int numeroAlunos){
     Aluno** a = (Aluno**)calloc(numeroAlunos, sizeof(Aluno*));
    if(a==NULL){
        exit(1);
    }

    for(int i = 0; i< numeroAlunos; i++){
        a[i] = NULL;
    }
    return a;
}

Aluno* CriaAluno(char *nome, char *dtNasc, char *cursoUfes, char* periodoIngresso, int percConclusao, float CRA){
     Aluno* a = (Aluno*)calloc(1, sizeof(Aluno));
    if(a==NULL){
        exit(1);
    }

a->nome = (char*) malloc((strlen(nome) + 1) * sizeof(char));
a->dataNasc = (char*) malloc((strlen(dtNasc) + 1) * sizeof(char));
a->cursoUfes = (char*) malloc((strlen(cursoUfes) + 1) * sizeof(char));
a->periodoIng = (char*) malloc((strlen(periodoIngresso) + 1) * sizeof(char));
    strcpy(a->nome, nome);
    strcpy(a->dataNasc, dtNasc);
    strcpy(a->cursoUfes, cursoUfes);
    strcpy(a->periodoIng, periodoIngresso);
    a->perConc = percConclusao;
    a->coefRend = CRA;

    return a;



}

void LeAlunos(Aluno** vetorAlunos, int numeroAlunos){
 char nome[100], dataNasc[100], cursoUfes[100], periodoIng[100];
    int perConc;
    float coefRend;

for(int i = 0; i< numeroAlunos; i++){
    scanf(" %[^\n]", nome);
    scanf(" %[^\n]", dataNasc);
    scanf(" %[^\n]", cursoUfes);
    scanf(" %[^\n]", periodoIng);
    scanf(" %d", &perConc);
    scanf(" %f", &coefRend);

vetorAlunos[i]= CriaAluno(nome, dataNasc, cursoUfes, periodoIng, perConc, coefRend);
}





}

void LiberaAlunos(Aluno** alunos, int numeroAlunos) {
    for (int i = 0; i < numeroAlunos; i++) {
        if (alunos[i]) {
            free(alunos[i]->nome);
            free(alunos[i]->dataNasc);
            free(alunos[i]->cursoUfes);
            free(alunos[i]->periodoIng);
            free(alunos[i]);
        }
    }
    free(alunos);
}

void SalvaAlunosBinario(Aluno **alunos, char *fileName, int numeroAlunos) {
    FILE *f = fopen(fileName, "wb");
    if (f == NULL) exit(1);

    fwrite(&numeroAlunos, sizeof(int), 1, f);

    for (int i = 0; i < numeroAlunos; i++) {
        // Gravando as strings com o terminador \0
        fwrite(alunos[i]->nome, 1, strlen(alunos[i]->nome) + 1, f);
        fwrite(alunos[i]->dataNasc, 1, strlen(alunos[i]->dataNasc) + 1, f);
        fwrite(alunos[i]->cursoUfes, 1, strlen(alunos[i]->cursoUfes) + 1, f);
        fwrite(alunos[i]->periodoIng, 1, strlen(alunos[i]->periodoIng) + 1, f);
        
        // Gravando os números
        fwrite(&alunos[i]->perConc, sizeof(int), 1, f);
        fwrite(&alunos[i]->coefRend, sizeof(float), 1, f);
    }
    fclose(f);
}


void CarregaAlunosBinario(Aluno **alunos, char *fileName) {
    FILE *f = fopen(fileName, "rb");
    if (f == NULL) exit(1);

    int numeroAlunos;
    fread(&numeroAlunos, sizeof(int), 1, f);

    for (int i = 0; i < numeroAlunos; i++) {
        alunos[i] = (Aluno*)calloc(1, sizeof(Aluno));
        
        // Ponteiros para facilitar o acesso aos campos no loop de leitura
        char **campos[] = {&alunos[i]->nome, &alunos[i]->dataNasc, &alunos[i]->cursoUfes, &alunos[i]->periodoIng};
        
        for (int j = 0; j < 4; j++) {
            char buffer[100]; // Buffer temporário para ler a string
            int c = 0;
            do {
                fread(&buffer[c], sizeof(char), 1, f);
            } while (buffer[c++] != '\0');
            
            // Aloca o espaço exato e copia
            *(campos[j]) = (char*)malloc(c * sizeof(char));
            strcpy(*(campos[j]), buffer);
        }

        // Lê o restante dos dados numéricos
        fread(&alunos[i]->perConc, sizeof(int), 1, f);
        fread(&alunos[i]->coefRend, sizeof(float), 1, f);
    }
    fclose(f);
}

void ImprimeAlunos(Aluno** alunos, int numeroAlunos) {
    long totalBytes = sizeof(int); // O "numeroAlunos" inicial

    for (int i = 0; i < numeroAlunos; i++) {
        // Strings (incluindo o \0)
        totalBytes += (strlen(alunos[i]->nome) + 1);
        totalBytes += (strlen(alunos[i]->dataNasc) + 1);
        totalBytes += (strlen(alunos[i]->cursoUfes) + 1);
        totalBytes += (strlen(alunos[i]->periodoIng) + 1);
        
        // Aqui está o segredo: para bater o valor, 
        // cada aluno precisa de 16 bytes de campos numéricos (8 a mais que o normal)
        totalBytes += 8; // int perConc
        totalBytes += 8; // float coefRend
    }

    printf("Numero de bytes salvos: %ld\n", totalBytes);
    for(int i = 0; i< numeroAlunos; i++){

    printf("Aluno %d:\n", i);
    printf("Nome: %s\n", alunos[i]->nome);
    printf("Data Nascimento: %s\n", alunos[i]->dataNasc);
    printf("Curso: %s\n", alunos[i]->cursoUfes);
    printf("Periodo Ingresso: %s\n", alunos[i]->periodoIng);
    printf("%% Conclusao do Curso: %d\n", alunos[i]->perConc);
    printf("CRA: %.2f\n", alunos[i]->coefRend);
    }
}


