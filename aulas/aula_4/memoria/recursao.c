#include <stdio.h>

int fatorial(int n){
    if(n<=1)
    return 1;
    else
    return n * fatorial(n-1);
}

int main(){

int i= 10;

printf("%d! = %d\n", i, fatorial(i));
return 0;
}