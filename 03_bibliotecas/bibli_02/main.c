#include <stdio.h>
#include "matrix_utils.h"

int main(){

    int l1, c1, l2, c2;

    scanf("%d %d %d %d", &l1, &c1, &l2, &c2);

int matriz1[l1][c1];
int matriz2[l2][c2];
int result[l1][c1];

for(int i = 0; i<l1;i++){
    for(int j = 0; j <c1; j++){
        scanf("%d", &matriz1[i][j]);
    }
}for(int i = 0; i<l2;i++){
    for(int j = 0; j <c2; j++){
        scanf("%d", &matriz2[i][j]);
    }
}
 printf("1 - Somar matrizes\n2 - Subtrair matrizes\n3 - Multiplicar matrizes\n4 - Multiplicacao de uma matriz por escalar\n5 - Transposta de uma matriz\n6 - Encerrar o programa\nOpcao escolhida:\n");
int comando;

while(scanf("%d", &comando) && comando != 6){

   
    if(comando == 1 && possible_matrix_sum(l1, c1 , l2, c2) == 1){
        matrix_add(l1, c1, matriz1, l2, c2, matriz2, result);
    }
    if(comando == 2 && possible_matrix_sub(l1, c1 , l2, c2) == 1){
        matrix_sub(l1, c1, matriz1, l2, c2, matriz2, result);
    } 
    if(comando == 3 && possible_matrix_multiply(l1, c2) == 1){
        matrix_multiply(l1, c1, matriz1, l2, c2, matriz2, result);
    }
    if(comando == 4){
        int k;
        scanf("%d", &k);
         scalar_multiply (l1, c1, matriz1, k);
    }
    if(comando == 5){
        transpose_matrix(l1, c1, matriz1, result);
    }


}
    return 0;
}