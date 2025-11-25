#ifndef ALUNO_H
#define ALUNO_H

typedef struct{
    float nota;
}Aluno;

Aluno* criaAluno(int quant);
float calcNota(Aluno *a);
void liberaNota(Aluno *a);



#endif