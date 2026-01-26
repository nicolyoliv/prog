#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "imagem.h"


/**
 * @brief Estrutura para representar uma imagem.
 */
 struct tImagem {
 int m, n;
 int tipo;
 Tipo *pixel;
 };

/**
 * @brief Função para ler uma imagem de um arquivo binário e aloca-la na memória.
 * @param path O caminho para o arquivo de imagem.
 * @return Um ponteiro para a imagem lida. Se houver erro (de leitura ou alocação de memória), a função imprime uma mensagem de erro e termina o programa.
 */
Imagem *LerImagem(const char *caminho){
FILE* f = fopen(caminho, "rb");
if(f==NULL){
    exit(1);
}
Imagem* i = (Imagem*)calloc(1, sizeof(Imagem));
if(i==NULL){
    exit(1);
}

fread(&i->m, sizeof(int), 1, f);
fread(&i->n, sizeof(int), 1, f);
fread(&i->tipo, sizeof(int), 1, f);

int total = i->m * i->n;
i->pixel= malloc(total * 4);




    fread(i->pixel, 4, total, f);




fclose(f);
return i;
}

/**
 * @brief Função para destruir uma imagem.
 * @param img A imagem a ser destruída.
 */
void DestruirImagem(Imagem *img){


free(img->pixel);
free(img);
}

/**
 * @brief Função para obter a altura de uma imagem.
 * @param img A imagem.
 * @return A altura da imagem.
 */
int ObterAlturaImagem(Imagem *img){
return img->m;
}

/**
 * @brief Função para obter a largura de uma imagem.
 * @param img A imagem.
 * @return A largura da imagem.
 */
int ObterLarguraImagem(Imagem *img){
return img->n;
}

/**
 * @brief Função para obter o tipo de uma imagem.
 * @param img A imagem.
 * @return O tipo da imagem.
 */
Tipo ObterTipoImagem(Imagem *img){
return img->tipo;
}

/**
 * @brief Função para obter os dados de uma imagem.
 * @param img A imagem.
 * @return Um ponteiro para os dados da imagem.
 */
void *ObterDadosImagem(Imagem *img){
return (void*)img->pixel;
}

