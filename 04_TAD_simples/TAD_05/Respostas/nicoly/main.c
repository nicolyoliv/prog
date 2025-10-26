#include <stdio.h>
#include <string.h>
#include "conta.h"


int main(){

    int quant, id, numero, comando, contasCriadas = 0;
    float valor = 0.0;
    char nome[20], cpf[15];

    scanf("%d", &quant);

   
    tUsuario usuario[quant];
    tConta conta[quant];    

    while(1){


        scanf("%d", &comando);

      

        if(comando == 0){
            return 0;
        }else if(comando == 1){

           
            scanf("%d %f",&id, &valor);
            for(int i = 0; i<contasCriadas;i++){
            if(VerificaConta(conta[i], id)){
            conta[i] = SaqueConta(conta[i],valor);
                }
            }
    }else if(comando == 2){
         
            scanf("%d %f",&id, &valor);
            for(int i = 0; i<contasCriadas;i++){

            if(VerificaConta(conta[i], id)){
           conta[i]= DepositoConta(conta[i], valor);
            }
        }
    }
        else if(comando == 3){

        scanf("%s %s %d", nome, cpf, &numero);
        if(contasCriadas <quant){
        
        conta[contasCriadas++] = CriaConta(numero, CriaUsuario(nome, cpf));
        }
    
    }else if(comando == 4){
        printf("===| Imprimindo Relatorio |===\n");
        for(int j = 0; j<contasCriadas; j++){
            ImprimeConta(conta[j]);
            printf("\n");
        }
    }else{
         printf("Operacao invalida!\n");
                break;
    }
    }

    return 0;
}