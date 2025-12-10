#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "livro.h"

#define TAM 100
// Estrutura que representa um livro
 struct Livros{
    char *titulo;
    char *autor;
    int ano;
 };


/**
 * Cria um livro "vazio". Ponteiros devem receber null e os atributos numéricos valor -1;
 *
 * @return Um ponteiro para um livro livro "vazio"
 */
tLivros* CriaLivro(){
tLivros* l = (tLivros*) calloc(1,sizeof(tLivros));
if(l==NULL){
    exit(1);
}

l->titulo = (char*) malloc(TAM * sizeof(char));
    if(l->titulo ==NULL){
        exit(1);
    }
l->autor = (char*) malloc(TAM * sizeof(char));
  if(l->autor ==NULL){
        exit(1);
    }

  l->titulo[0] = '\0';
    l->autor[0] = '\0';
    l->ano = -1;


return l;

}

/**
 * Lê os atributos de um livro a partir da entrada padrão (teclado).
 *
 * @param livro Um ponteiro para um livro que receberá os atributos lidos
 */
void LerLivro(tLivros* livro){

char titulo[TAM], autor[TAM];
int ano;



scanf("%s", titulo);
scanf("%s ", autor);
scanf("%d ", &ano);

strcpy(livro->titulo, titulo);
strcpy(livro->autor, autor);
livro->ano = ano;



}

/**
 * Imprime os atributos da TAD tLivros (título, autor e ano de publicação).
 * 
 * @param livro Um ponteiro para o livro cujos atributos serão impressos
*/
void ImprimeLivro(tLivros* livro){
printf("Titulo: %s\n", livro->titulo);
printf("Autor: %s\n", livro->autor);
printf("Ano de Publicacao: %d\n", livro->ano);

}

/**
 * Retorna o título do livro.
 * 
 * @param livro Ponteiro para o livro cujo título será retornado.
 * @return O título do livro.
*/
char *getTitulo(tLivros* livro){
return livro->titulo;
}

/**
 * Função para liberar toda a memória alocada por um livro
 * 
 * @param livro Um ponteiro para o livro cujos atributos serão apagados/liberados
*/
void ApagaLivro(tLivros* livro){
free(livro->titulo);
free(livro->autor);
free(livro);
}

