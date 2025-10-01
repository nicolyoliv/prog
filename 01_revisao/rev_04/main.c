#include <stdio.h>
#include <math.h>


int transforme(int n){
int cont = 0, soma = 0;
    while(n>0){
        int resto = n%8;
        n=n/8;
soma += resto * pow(10,cont);
 cont++;
    }
    return soma;
}


int main(){

int x, res=0;

scanf("%d", &x);

res = transforme(x);

printf("%d", res);
    return 0;
}