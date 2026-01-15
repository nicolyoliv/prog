#include "relatorio.h"
#include "aluno.h"
#include "vector.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

int qtdA;
scanf("%d", &qtdA);

Vector* alunos = VectorConstruct();
for(int i = 0; i< qtdA; i++){
    tAluno* aluno = CriaAluno();
    LeAluno(aluno);
    VectorPushBack(alunos, aluno);
}

ImprimeRelatorio(alunos);
VectorDestroy(alunos, DestroiAluno);

    return 0;
}