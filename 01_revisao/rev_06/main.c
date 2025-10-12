#include <stdio.h>
#include <string.h> 
#include <ctype.h>

#define TAM_MAX 100 


int main(){
int lim;
char c[TAM_MAX];
int tam;
int promo = 0;

//c=onde armazenar
// tam_max =  quant max
//stdin= entrada
if(scanf("%d", &lim) != 1) return 1;

int ch;
while ((ch = getchar()) != '\n' && ch != EOF); 

if (fgets(c, TAM_MAX, stdin) != NULL) {

//strlen = retorna tam ate '\0'
    tam = strlen(c);

    if(tam > 0 && c[tam -1] == '\n'){
        c[tam -1] = '\0'; // substitui '\n' por '\0'
        tam -- ;
    }

}

 // Percorre todos os 256 possíveis valores ASCII para garantir a ORDEM
    for (int ascii_val = 0; ascii_val < 256; ascii_val++) {
        char char_atual = (char)ascii_val;
        int cont = 0;

        // Verifica se o caractere atual (pela ordem ASCII) existe na string
        // e se é alfanumérico (requisito do problema)
        if (isalnum(char_atual)) {
            
            // Laço para contar a frequência deste caractere na string 'c'
            for (int k = 0; k < tam; k++) {
                if (c[k] == char_atual) {
                    cont++;
                }
            }
            
            // Aplica a condição de promoção e imprime UMA ÚNICA VEZ
            if (cont >= lim) {
                promo = 1;
                printf("%c: %d\n", char_atual, cont);
            }
        }
    }

    // 4. IMPRESSÃO DO REQUISITO "NENHUM"
    if (!promo) {
        printf("NENHUM\n");
    }

    return 0;
}