#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "histograma.h"


/**
 * @brief Estrutura para representar um Histograma.
 */
 struct tHistograma {
    int* contPixel;
    int quantIntervalo;
    int tamIntervalo;
 };

/**
 * @brief Função para calcular o histograma de uma imagem.
 * @param img Ponteiro para a imagem.
 * @param nIntervalos Número de intervalos no histograma.
 * @return Ponteiro para o histograma calculado.
 */
Histograma *CalcularHistograma(Imagem *img, int nIntervalos){
   Histograma *h = (Histograma* )calloc(1, sizeof(Histograma));
   if(h==NULL){
      exit(1);
   }
   h->quantIntervalo = nIntervalos;
   h->tamIntervalo = (256 + nIntervalos - 1)/nIntervalos;
   h->contPixel = calloc(nIntervalos, sizeof(int));
   if(h->contPixel == NULL){
      exit(1);
   }

   for(int i = 0; i<ObterAltura(img)* ObterLargura(img);i++){
      int valorPixel;
      if(ObterTipoImagem(img)== FLOAT){
         float * data = (float*)ObterDadosImagem(img);
         valorPixel= data[i]*255;
      }else{
         int* data = (int*)ObterDadosImagem(img);
         valorPixel = data[i];
      }

      int intervaloInd = valorPixel/h->tamIntervalo;
      if (intervaloInd >= nIntervalos) {
    intervaloInd = nIntervalos - 1;
}
   h->contPixel[intervaloInd]++;
}
return h;
}
/**
 * @brief Função para imprimir um histograma na tela.
 * @param histograma Ponteiro para o histograma a ser exibido.
 */
void MostrarHistograma(Histograma *histograma){
   for(int i=0; i<histograma->quantIntervalo;i++){
        printf("[%d, %d): %d\n", i * histograma->tamIntervalo, (i + 1) * histograma->tamIntervalo, histograma->contPixel[i]);

   }
}

/**
 * @brief Função para destruir um histograma.
 * @param histograma Ponteiro para o histograma a ser destruído.
 */
void DestruirHistograma(Histograma *histograma){
   free(histograma->contPixel);
   free(histograma);
}

