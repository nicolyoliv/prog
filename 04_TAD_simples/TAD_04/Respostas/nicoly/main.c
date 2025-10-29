#include <stdio.h>
#include <string.h>
#include "aluno.h"


int main(){


int quant;

    scanf("%d", &quant);
tAluno aluno[quant];


    for(int i = 0; i<quant; i++){
        aluno[i] = LeAluno(); 
    }

    for (int i = 0; i < quant - 1; i++) {
        for (int j = i; j < quant-i-1; j++) {
            if (ComparaMatricula(aluno[i], aluno[j+1]) == 1) {
                tAluno aux = aluno[j];
                aluno[j] = aluno[j+1];
               aluno[j+1] = aux;
            }
        }
    }
    for(int i = 0; i< quant; i++){
        if(VerificaAprovacao(aluno[i])){
        ImprimeAluno(aluno[i]);
    }
}
    return 0;
}