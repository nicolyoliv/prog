#include <stdlib.h>
#include <string.h>
#include "produto.h"

struct Produto {
   int codigo;
   char nome[50];
   float preco;
   int quant;
};

tProduto *CriaProduto(int codigo, char *nome, float preco, int quantidade){
    tProduto *p = calloc(1, sizeof(tProduto));
    if(p == NULL){
        exit(1);
    }


 p->quant = quantidade;
 p->preco = preco;
 p->codigo = codigo;
 strcpy(p->nome, nome);

 return p;
}

tProduto *LeProduto(FILE *arquivo){
    tProduto *p = calloc(1, sizeof(tProduto));
    if(p == NULL){
        exit(1);
    }

    int codigo;
   char nome[50];
   float preco;
   int quant;


    fread(&p->codigo, sizeof(int), 1, arquivo);
    fread(p->nome, sizeof(char), 50, arquivo);
    fread(&p->preco, sizeof(float), 1, arquivo);
    fread(&p->quant, sizeof(int), 1, arquivo);

   return p;

}

int TemEstoqueProduto(tProduto *produto){
    if(produto->quant>0){
        return 1;
    }return 0;
}

void ImprimeProduto(tProduto *produto){
    printf("%d;%s;%.2f\n", produto->codigo, produto->nome, produto->preco);

}

void DestroiProduto(tProduto *produto){
    free(produto);
}
