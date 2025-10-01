#include <stdio.h>
#include <stdlib.h>

#define MAX 100 

typedef struct {
    int r; 
    int c; 
} Posicao;


int main() {
    int M, N; 
    int mapa[MAX][MAX];
    int visitado[MAX][MAX] = {0}; 
    
    int Xi, Yi, Xf, Yf;
    char prioridade[5]; 
    
    Posicao caminho[MAX * MAX]; 
    int caminho_idx = 0; 
    int r_atual, c_atual; 

   
    scanf("%d %d", &M, &N);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &mapa[i][j]);
        }
    }

    scanf("%d %d", &Xi, &Yi);
    scanf("%d %d", &Xf, &Yf);
    
    scanf("%s", prioridade);
    
    r_atual = Xi - 1;
    c_atual = Yi - 1;

    Xf = Xf - 1;
    Yf = Yf - 1;


    visitado[r_atual][c_atual] = 1;
    caminho[caminho_idx++] = (Posicao){Xi, Yi};

    while (r_atual != Xf || c_atual != Yf) {
        
        int moveu = 0; 
        for (int i = 0; i < 4; i++) {
            char direcao = prioridade[i];
            
            int r_prox = r_atual; 
            int c_prox = c_atual; 
            
            if (direcao == 'C') { 
                r_prox--;
            } else if (direcao == 'B') { 
                r_prox++;
            } else if (direcao == 'D') { 
                c_prox++;
            } else if (direcao == 'E') { 
                c_prox--;
            }
            
            
            if (r_prox >= 0 && r_prox < M && c_prox >= 0 && c_prox < N) {
                
                if (mapa[r_prox][c_prox] == 0) {
                    
                    if (visitado[r_prox][c_prox] == 0) {
                        
                        
                        r_atual = r_prox;
                        c_atual = c_prox;
                        
                        visitado[r_atual][c_atual] = 1;
                        
                        caminho[caminho_idx++] = (Posicao){r_atual + 1, c_atual + 1};
                        
                        moveu = 1;
                        break; 
                    }
                }
            }
        } 
        if (moveu == 0) {
            break; 
        }
    } 

    for (int i = 0; i < caminho_idx; i++) {
        printf("(%d,%d)%s", caminho[i].r, caminho[i].c, (i < caminho_idx - 1) ? " " : "");
    }
    printf("\n");

    return 0;
}