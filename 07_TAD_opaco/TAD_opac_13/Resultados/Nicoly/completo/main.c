#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "paciente.h"


#define MAX_PAC 100
#define MAX_LES 100

int main(){

char comando;
Paciente *p[MAX_PAC];
int quantL=0, quantP=0, quantC =0, soma =0;
Data *dataBase = criaData(12, 9, 2023);


while(1){
    scanf(" %c\n", &comando);
    if(comando == 'F'){
        break;
    }else if(comando== 'P' && quantP< MAX_PAC){

        p[quantP]=lerPaciente();
        quantP++;
        
    }else if(comando == 'L'&&quantL<MAX_LES){
        Lesao *nova = lerLesao();

        int vinculo =0;

        for(int i = 0; i<quantP;i++){
            if(strcmp(getCartaoSusPaciente(p[i]), getCartaoSusLesao(nova))==0){
               adicionaLesaoPaciente(p[i], nova);
                vinculo = 1;
                if(verificaCirurgicaLesao(nova)){
                quantC++;
            }
            break;
        }
    }
if(vinculo){
    quantL++;
}else{
    liberaLesao(nova);
}
    }

     

}
   for(int i = 0; i<quantP;i++){
        soma += calculaIdadePaciente(p[i], dataBase);
        }

        int mediaI = 0;
        if(quantP>0){
            mediaI = soma/quantP;

        }

        printf("TOTAL PACIENTES: %d\n", quantP);
if(quantP >0){
printf("MEDIA IDADE (ANOS): %d\n", mediaI);
}else{
    printf("MEDIA IDADE (ANOS): -\n");
}
printf("TOTAL LESOES: %d\n", quantL);
printf("TOTAL CIRURGIAS: %d\n", quantC);
printf("LISTA DE PACIENTES:\n");
    for(int i =0; i<quantP;i++){
     
       imprimePaciente(p[i]);
      
    }

     for(int i = 0; i<quantP;i++){
        liberaPaciente(p[i]);
     }
     liberaData(dataBase);
    return 0;
}