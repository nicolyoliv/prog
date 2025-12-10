#include <stdio.h> 
#include <stdlib.h>
#include "biblioteca.h"



int main(){

int n;
tBiblioteca *b = InicializarBiblioteca();
printf("Lista de operacoes:\n");
    printf("1 - Cadastrar livros.\n");
    printf("2 - Remover livros.\n");
    printf("3 - Listar todos os livros cadastrados.\n");


    scanf(" %d\n", &n);
int op[n];
for(int i = 0; i<n;i++){
scanf(" %d\n", &op[i]);

if(op[i]== 1){
    tLivros *l = CriaLivro();
   LerLivro(l);
   AdicionarLivroNaBiblioteca(b,l);
}
else if(op[i]==2){
    char titulo[100];
    scanf("%s", titulo);
    RemoverLivroDaBiblioteca(b, titulo);
}
else if(op[i]==3){
    ListarLivrosDaBiblioteca(b);
}else{
    printf("Operacao invalida!\n");
    return 0;
}
}
ApagaBiblioteca(b);
    return 0;
}