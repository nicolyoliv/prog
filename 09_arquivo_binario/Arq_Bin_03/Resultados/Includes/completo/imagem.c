#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "imagem.h"



/**
 * @brief Estrutura para representar uma imagem.
 */
 struct tImagem {
    int m, n;
    int tipo;
    Tipo **pixel;

 };

/**
 * @brief Função para ler uma imagem de um arquivo binário e aloca-la na memória.
 * A função também armazena o número de bytes lidos na estrutura Imagem.
 * @param path O caminho para o arquivo de imagem.
 * @return Um ponteiro para a imagem lida. Se houver erro (de leitura ou alocação de memória), a função imprime uma mensagem de erro e termina o programa.
 */
Imagem *LerImagem(const char *caminho) {
    FILE *f = fopen(caminho, "rb");
    if (!f) {
        printf("Erro ao abrir o arquivo %s\n", caminho);
        exit(1);
    }

    Imagem *img = (Imagem *)calloc(1, sizeof(Imagem));
    if (!img) exit(1);

    // CORREÇÃO: Usar 'f' e não 'caminho'
    fread(&img->m, sizeof(int), 1, f);
    fread(&img->n, sizeof(int), 1, f);
    fread(&img->tipo, sizeof(int), 1, f);

    // ALOCAÇÃO DA MATRIZ: Importante!
    img->pixel = (Tipo **)malloc(img->m * sizeof(Tipo *));
    for (int l = 0; l < img->m; l++) {
        img->pixel[l] = (Tipo *)malloc(img->n * sizeof(Tipo));
        
        // LEITURA: Lê a linha inteira de uma vez (mais rápido)
        if (img->tipo == FLOAT) {
            fread(img->pixel[l], sizeof(float), img->n, f);
        } else {
            fread(img->pixel[l], sizeof(int), img->n, f);
        }
    }

    fclose(f);
    return img;
}

/**
 * @brief Função para destruir uma imagem.
 * @param img A imagem a ser destruída.
 */
void DestruirImagem(Imagem *img){
for(int l = 0; l<img->m;l++){
         
                free(img->pixel[l]);
}
free(img->pixel);
free(img);
}

/**
 * @brief Função para obter o número de bytes lidos de uma imagem.
 * @param img A imagem.
 * @return O número de bytes lidos.
 */
int ObterNumeroBytesLidos(Imagem *img){
   int soma = (img->m * img->n) +3 ;

        return soma;
}

/**
 * @brief Função para imprimir uma imagem.
 * @param img A imagem.
 */
void ImprimirImagem(Imagem *img) {
    for (int l = 0; l < img->m; l++) {
        for (int c = 0; c < img->n; c++) {
            if (img->tipo == FLOAT) {
                float val = *(float*)&img->pixel[l][c];
                printf("%.2f ", val);
            } else {
                int val = *(int*)&img->pixel[l][c];
                printf("%d ", val);
            }
        }
        printf("\n");
    }
}

