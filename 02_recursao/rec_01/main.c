#include <stdio.h>
#include <string.h>


#define MAX 1000

void ImprimeInvertido(char* string){

    int i, inicio = 0;

    int tam = strlen(string);

    if(tam > 0 && string[tam -1] == '\n'){
        string[tam  - 1] = '\0';
        tam --;
    }

    for(i = 0; i<= tam; i++){

        if(string[i] == ' '|| string[i] == '\0'){

        int fim = i-1;

        for(int j = fim; j>= inicio; j--){
            printf("%c", string[j]);
        }
        if(string[i] == ' '){
                printf(" ");
        }
            inicio = i+1;
        }

    }
     printf("\n");
}



int main(){

    char c[MAX];
 
    if(fgets(c, MAX, stdin) != NULL){

     ImprimeInvertido(c);
    }
    return 0;
}
