#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aluno.h"


int main(){

int quant = 0;
printf("Digite o numero de alunos: ");
scanf("%d", &quant);

Aluno** a = CriaVetorAlunos(quant);
LeAlunos(a, quant);
SalvaAlunosBinario(a, "alunos.bin", quant);
LiberaAlunos(a, quant);

Aluno** alunosCarregados = CriaVetorAlunos(quant);
CarregaAlunosBinario(alunosCarregados, "alunos.bin");
ImprimeAlunos(alunosCarregados, quant);
LiberaAlunos(alunosCarregados, quant);
    return 0;
}