#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "base_alunos.h"
#include "aluno.h"


int main() {
    char caminhoArquivo[100];
    
    if (scanf("%s", caminhoArquivo) != 1) {
        return 1;
    }

    tBaseAlunos* b = CriarBaseAlunos();
    
    LerBaseAlunos(b, caminhoArquivo);
    
    printf("Coeficiente de Rendimento Medio da base de alunos: %.2f\n", GetCoeficienteRendimentoMedioBaseAlunos(b));
    
    DestruirBaseAlunos(b);

    return 0;
}