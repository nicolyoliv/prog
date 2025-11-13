#ifndef LIVRO_H
#define LIVRO_H


#include <stdio.h>

#define MAX_TITULO 100
#define MAX_AUTOR 50

typedef struct{
    char titulo [MAX_TITULO];
    char autor [MAX_AUTOR];
    int edicao;
    int nPaginas;
}Livro;

Livro* criaLivro(char *titulo, char *autor, int ed, int pag);

void liberaLivro(Livro *l);


#endif




