#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "imagem.h"



/**
 * @brief Estrutura para representar uma imagem.
 */
 struct tImagem {
    int altura, largura;
    Tipo tipo;
    void *dados;
 };

/**
 * @brief Função para obter a altura de uma imagem.
 * @param img Ponteiro para a imagem.
 * @return Altura da imagem.
 */
int ObterAltura(Imagem *img){
    return img->altura;
}

/**
 * @brief Função para obter a largura de uma imagem.
 * @param img Ponteiro para a imagem.
 * @return Largura da imagem.
 */
int ObterLargura(Imagem *img){
    return img->largura;
}

/**
 * @brief Função para obter o tipo de dados de uma imagem.
 * @param img Ponteiro para a imagem.
 * @return Tipo de dados da imagem.
 */
Tipo ObterTipoImagem(Imagem *img){
    return img->tipo;
}

/**
 * @brief Função para obter os dados de uma imagem.
 * Note que a imagem é uma matriz, mas os dados podem ser armazenados de forma linear (vetor).
 * @param img Ponteiro para a imagem.
 * @return Ponteiro para os dados da imagem.
 */
void *ObterDadosImagem(Imagem *img){
    return img->dados;

}

/**
 * @brief Função para criar uma imagem.
 * @param altura Altura da imagem.
 * @param largura Largura da imagem.
 * @param tipo Tipo de dados da imagem.
 * @return Ponteiro para a imagem criada. Caso não seja possível criar a imagem, o programa é encerrado.
 */
Imagem *CriarImagem(int altura, int largura, Tipo tipo){
    Imagem* i = (Imagem*)calloc(1, sizeof(Imagem));
    if(i==NULL){
        exit(1);
    }
    i->altura = altura;
    i->largura = largura;
    i->tipo = tipo;

    return i;

}

/*
 * @brief Função para ler uma imagem, primeiro lendo a altura, largura e tipo de dados (tudo na mesma linha seperado por espaço). Em seguida, lê os dados da imagem.
 * @return Ponteiro para a imagem lida. (Crie a imagem com a função CriarImagem).
 */
Imagem *LerImagem(){
    int largura, altura, tipoInt;
   

    scanf("%d %d %d\n", &altura, &largura, &tipoInt);

    Tipo tipo = (Tipo)tipoInt;

    Imagem* img = CriarImagem(altura, largura, tipoInt);

    int tam = largura * altura;


    if(tipo == FLOAT){
        img->dados = malloc(sizeof(float) * tam);
            for(int i = 0; i<tam; i++){
                scanf(" %f", &((float*)img->dados)[i]);
            }

    }else if(tipo == INT){
        img->dados = malloc(sizeof(int) * tam);
            for(int i = 0; i<tam; i++){
                scanf(" %d", &((int*)img->dados)[i]);
            }
    }
return img;
    
}

/**
 * @brief Função para imprimir uma imagem.
 * @param img Ponteiro para a imagem.
 */
void ImprimirImagem(Imagem *img){
    if(img->tipo == FLOAT){
      float *d = (float*)img->dados;
        for(int i = 0; i<img->altura; i++){
            for(int j = 0; j<img->largura; j++){
                printf("%.2f", d[i *img->largura + j]);
            }
            printf("\n");
        }
    }
    if(img->tipo == INT){
        int *d = (int*)img->dados;
        for(int i = 0; i<img->altura; i++){
            for(int j = 0; j<img->largura; j++){
                printf("%d", d[i*img->largura+j]);
            }
            printf("\n");
        }
    }
}

/**
 * @brief Função para destruir uma imagem.
 * @param img Ponteiro para a imagem.
 */
void DestruirImagem(Imagem *img){
    free(img->dados);
    free(img);
}

