#include <stdio.h>
#include "loja.h"



int main(){
int quant;
int op;

scanf(" %d\n", &quant);
tLoja *loja[quant];
int lojasCadastradas =0;


while(1){
scanf(" %d\n", &op);

if(op==0){
    break;
}else if(op==1){
   if(lojasCadastradas == quant){
         continue;
    }else{
        int id;
        float aluguel;
        scanf(" %d %f\n", &id, &aluguel);
        loja[lojasCadastradas] = AbreLoja(id, aluguel);
        lojasCadastradas++;
    }
}else if(op==2){
   char nome[100];
   float salario, comissao;
   int idLoja;
   scanf("%s %f %f", nome, &salario, &comissao);
   scanf("%d", &idLoja);

   for(int i = 0; i<lojasCadastradas;i++){
    if(VerificaIdLoja(loja[i], idLoja)){
        tVendedor *v = RegistraVendedor(nome, salario, comissao);
        ContrataVendedor(loja[i], v);
    }
   }
}else if(op==3){
        char nome[100];
   float valor;
        scanf("%s %f", nome, &valor);
            for(int i = 0; i<lojasCadastradas;i++){

        RegistraVenda(loja[i], nome,valor );

    }
}else if(op==4){
    for(int i=0;i<lojasCadastradas;i++){
        CalculaLucro(loja[i]);
        ImprimeRelatorioLoja(loja[i]);
    }
}



}
    for(int i=0;i<lojasCadastradas;i++){
        ApagaLoja(loja[i]);
    }




    return 0;
}