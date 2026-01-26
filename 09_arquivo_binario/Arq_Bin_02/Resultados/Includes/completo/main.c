#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "base_alunos.h"
#include "aluno.h"


int main() {
    char caminhoArquivo[100];
    
    // Lê o caminho do arquivo que o sistema de teste fornece (ex: Casos/1/alunos.bin)
    if (scanf("%s", caminhoArquivo) != 1) {
        return 1;
    }

    tBaseAlunos* b = CriarBaseAlunos();
    
    // Usa a variável com o caminho lido, e não "alunos.bin" fixo
    LerBaseAlunos(b, caminhoArquivo);
    
    printf("Coeficiente de Rendimento Medio da base de alunos: %.2f\n", GetCoeficienteRendimentoMedioBaseAlunos(b));
    
    DestruirBaseAlunos(b);

    return 0;
}