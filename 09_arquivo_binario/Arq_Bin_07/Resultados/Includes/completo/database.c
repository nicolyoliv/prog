#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database.h"
#include "aluno.h"
#include "professor.h"

struct Database {
    int qtdAlunos;
    int qtdProfessores;
    tAluno **alunos;
    tProfessor **professores;
};

tDatabase *CriaDatabase() {
    tDatabase *db = calloc(1, sizeof(tDatabase));
    if (!db) exit(1);
    return db;
}

void DestroiDatabase(tDatabase *db) {
    for (int i = 0; i < db->qtdAlunos; i++)
        DestroiAluno(db->alunos[i]);

    for (int i = 0; i < db->qtdProfessores; i++)
        DestroiProfessor(db->professores[i]);

    free(db->alunos);
    free(db->professores);
    free(db);
}

void LeDatabase(tDatabase *db) {
    scanf("%d", &db->qtdAlunos);
    db->alunos = malloc(db->qtdAlunos * sizeof(tAluno*));

    for (int i = 0; i < db->qtdAlunos; i++)
        db->alunos[i] = LeAluno();

    scanf("%d", &db->qtdProfessores);
    db->professores = malloc(db->qtdProfessores * sizeof(tProfessor*));

    for (int i = 0; i < db->qtdProfessores; i++)
        db->professores[i] = LeProfessor();
}

void OrdenaDatabase(tDatabase *db) {
    qsort(db->alunos, db->qtdAlunos, sizeof(tAluno*),
          (int (*)(const void*, const void*)) ComparaNomeAluno);

    qsort(db->professores, db->qtdProfessores, sizeof(tProfessor*),
          (int (*)(const void*, const void*)) ComparaNomeProfessor);
}

int SalvarDatabase(tDatabase *db, FILE *file) {
    int bytes = 0;

    bytes += fwrite(&db->qtdAlunos, sizeof(int), 1, file) * sizeof(int);
    for (int i = 0; i < db->qtdAlunos; i++)
        bytes += SalvaAluno(db->alunos[i], file);

    bytes += fwrite(&db->qtdProfessores, sizeof(int), 1, file) * sizeof(int);
    for (int i = 0; i < db->qtdProfessores; i++)
        bytes += SalvaProfessor(db->professores[i], file);

    return bytes;
}

int CarregaDatabase(tDatabase *db, FILE *file) {
    int bytes = 0;

    // Lendo Alunos
    if (fread(&db->qtdAlunos, sizeof(int), 1, file) != 1) return bytes;
    bytes += sizeof(int);
    db->alunos = malloc(db->qtdAlunos * sizeof(tAluno*));

    for (int i = 0; i < db->qtdAlunos; i++) {
        // Criamos um aluno com strings vazias para alocar a struct
        // A função CarregaAluno vai liberar essas strings e alocar as reais
        db->alunos[i] = CriaAluno("", "", "", 0, 0); 
        bytes += CarregaAluno(db->alunos[i], file);
    }

    // Lendo Professores
    if (fread(&db->qtdProfessores, sizeof(int), 1, file) != 1) return bytes;
    bytes += sizeof(int);
    db->professores = malloc(db->qtdProfessores * sizeof(tProfessor*));

    for (int i = 0; i < db->qtdProfessores; i++) {
        // Criamos um professor "vazio"
        db->professores[i] = CriaProfessor("", "", "");
        bytes += CarregaProfessor(db->professores[i], file);
    }

    return bytes;
}

void ImprimeDatabase(tDatabase *db) {
    printf("\nAlunos:\n");
    for (int i = 0; i < db->qtdAlunos; i++)
        ImprimeNomeAluno(db->alunos[i]);

    printf("\nProfessores:\n");
    for (int i = 0; i < db->qtdProfessores; i++)
        ImprimeNomeProfessor(db->professores[i]);
}
