#include <stdio.h>
#include "livros.h"
#include <string.h>


void criaLivro(Livro *l, char *titulo, char *autor, int ed, int pag){
    
    strcpy(l->titulo, titulo);
    strcpy(l->autor, autor);
    l->edicao = ed;
    l->npagina = pag;


}
