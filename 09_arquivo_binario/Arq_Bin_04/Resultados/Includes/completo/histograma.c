#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "histograma.h"


 struct tHistograma {
int *contagem;
int nIntervalos;
int tam;
 };

/**
 * @brief Função para calcular um histograma a partir de uma imagem.
 * @param image A imagem para calcular o histograma.
 * @param n_buckets O número de intervalos no histograma.
 * @return Um ponteiro para o histograma calculado.
 */
Histograma *CalcularHistograma(Imagem *img, int nIntervalos){
    Histograma* h = (Histograma*)malloc(sizeof(Histograma));
    h->nIntervalos = nIntervalos;

    h->tam = (int)ceil(256.0/nIntervalos);
    h->contagem = (int*)calloc(nIntervalos, sizeof(int));

    int total = ObterAlturaImagem(img)*ObterLarguraImagem(img);
    int tipo = ObterTipoImagem(img);

    void* dados = ObterDadosImagem(img);
    for(int i = 0; i < total; i++){
        int valorP;

        if(tipo == FLOAT){
            float p = ((float*)dados)[i];
            valorP = (int)(p * 255);
        } else {
            valorP = ((int*)dados)[i];
        }

        int intervalo = valorP / h->tam;

        if(intervalo >= nIntervalos){
            intervalo = nIntervalos - 1;
        }

        h->contagem[intervalo]++; 
    }
    
    return h;
}

/**
 * @brief Função para exibir um histograma na tela.
 * @param histogram O histograma a ser exibido.
 */
void MostrarHistograma(Histograma *histograma){
   for (int i = 0; i < histograma->nIntervalos; i++) {
        int inicio = i * histograma->tam;
        int fim = inicio + histograma->tam;
         printf("[%d, %d): %d\n", inicio, fim, histograma->contagem[i]);
    }
}

/**
 * @brief Função para destruir um histograma.
 * @param histogram O histograma a ser destruído.
 */
void DestruirHistograma(Histograma *histograma){
   free(histograma->contagem);
   free(histograma);
}

