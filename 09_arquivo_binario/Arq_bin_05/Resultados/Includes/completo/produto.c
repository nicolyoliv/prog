#include <stdlib.h>
#include <string.h>
#include "produto.h"

struct Produto {
    int codigo;
    char nome[50];
    float preco;
    int quantidade;
};

tProduto *CriaProduto(int codigo, char *nome, float preco, int quantidade){
    tProduto *p = calloc(1, sizeof(tProduto));
    if(!p) exit(1);
    p->codigo = codigo;
    strcpy(p->nome, nome);
    p->preco = preco;
    p->quantidade = quantidade;
    return p;
}

tProduto *LeProduto(FILE *arquivo){
    tProduto *p = calloc(1, sizeof(tProduto));
    if(!p) exit(1);

    fread(&p->codigo, sizeof(int), 1, arquivo);
    fread(p->nome, sizeof(char), 50, arquivo);
    fread(&p->preco, sizeof(float), 1, arquivo);
    fread(&p->quantidade, sizeof(int), 1, arquivo);

    return p;
}

int TemEstoqueProduto(tProduto *produto){
    return produto->quantidade > 0;
}

void ImprimeProduto(tProduto *produto){
    printf("%d;%s;%.2f\n", produto->codigo, produto->nome, produto->preco);
}

void DestroiProduto(tProduto *produto){
    free(produto);
}
