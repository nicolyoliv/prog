#include <stdio.h>
#include "aluno.h"
#include <string.h>


int main(){

int n;
scanf("%d", &n);
tAluno* aluno[n];


for(int i =0 ; i<n;i++){
aluno[i] = CriaAluno();
LeAluno(aluno[i]);

}


for(int i = 0; i < n - 1; i++) { 
    for(int j = 0; j < n - i - 1; j++) { 
        if(ComparaMatricula(aluno[j], aluno[j+1]) == 1) { 
            tAluno* temp = aluno[j]; 
            aluno[j] = aluno[j+1];
            aluno[j+1] = temp;
        }
    }
}
for(int i =0; i<n;i++){

if(VerificaAprovacao(aluno[i])){
    ImprimeAluno(aluno[i]);
}
}
for(int i =0; i<n;i++){
    ApagaAluno(aluno[i]);
}
    return 0;
}
