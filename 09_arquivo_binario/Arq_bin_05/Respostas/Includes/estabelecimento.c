#include <stdio.h>
#include <stdlib.h>
#include "estabelecimento.h"
#include "vector.h"

struct Estabelecimento {
    Vector *produtos;
};

tEstabelecimento *CriaEstabelecimento(){
    tEstabelecimento *e = calloc(1, sizeof(tEstabelecimento));
    if(!e) exit(1);
    e->produtos = VectorConstruct();
    return e;
}

void AdicionaProdutoEstabelecimento(tEstabelecimento *est, tProduto *produto){
    VectorPushBack(est->produtos, produto);
}

void LeEstabelecimento(tEstabelecimento *est){
    char nomeArquivo[100];
    scanf("%s", nomeArquivo);

    FILE *f = fopen(nomeArquivo, "rb");
    if(!f) exit(1);

    int qtd;
    fread(&qtd, sizeof(int), 1, f);

    for(int i = 0; i < qtd; i++){
        tProduto *p = LeProduto(f);
        AdicionaProdutoEstabelecimento(est, p);
    }

    fclose(f);
}

void ImprimeProdutosEmFaltaEstabelecimento(tEstabelecimento *est){
    int encontrou = 0;
  printf("Produtos em falta:\n");
            printf("Codigo;Nome;Preco\n");
    for(int i = 0; i < VectorSize(est->produtos); i++){
        tProduto *p = (tProduto*)VectorGet(est->produtos, i);
        if(!TemEstoqueProduto(p)){
          
            ImprimeProduto(p);
            encontrou = 1;
        }
    }

    if(!encontrou){
        printf("Nao ha produtos em falta!\n");
    }
}

void DestroiEstabelecimento(tEstabelecimento *est){
    VectorDestroy(est->produtos, (void*)DestroiProduto);
    free(est);
}
