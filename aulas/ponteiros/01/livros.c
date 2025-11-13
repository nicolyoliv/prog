#include <stdio.h>
#include "livros.h"
#include <string.h>
#include <stdlib.h>


Livro * criaLivro( char *titulo, char *autor, int ed, int pag){
    Livro *l = (Livro*) malloc(sizeof(Livro));

    strcpy(l->titulo, titulo);
    strcpy(l->autor, autor);
    l->edicao = ed;
    l->nPaginas = pag;
return l;

}

void liberaLivro(Livro *l){
    free(l);
}