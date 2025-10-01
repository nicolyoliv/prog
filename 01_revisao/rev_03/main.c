#include <stdio.h>

int main(){

int n;

scanf("%d", &n);
    int x[n];

for(int i = 0; i<n; i++){
    scanf("%d", &x[i]);
}

for(int i = 0; i<n; i++){
    int count=0;
    for(int j = 0; j<n; j++){
        if(x[i] == x[j]){
            count++;
        }      
    }
     if(count==1){
        printf("%d ", x[i]);
    }else{
        printf("NENHUM\n");
        break;
    }
}

    return 0;
}