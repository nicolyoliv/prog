#include <stdio.h>

int SomaElementosPares(int* vet, int numElementos){

int sum=0;

for(int i = 0; i< numElementos; i++){
    if(vet[i]%2==0){
    sum += vet[i];
    }
}
return sum;
}


int main(){

int n;

scanf("%d", &n);

for(int i = 0; i<n; i++){

    int x;

    int soma  = 0;

    scanf("%d", &x);

    int num[x];

    for(int j = 0; j<x; j++){
        scanf("%d", &num[j]);
    
    }
        soma = SomaElementosPares( num, x);

printf("%d\n", soma);


}

    return 0;
}