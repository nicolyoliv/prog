#include <stdio.h>
#include "livros.h"
#include <stdlib.h>


int main(){

    Livro *l =criaLivro("sla", "sla", 1, 500);
    liberaLivro(l);
    return 0;
}