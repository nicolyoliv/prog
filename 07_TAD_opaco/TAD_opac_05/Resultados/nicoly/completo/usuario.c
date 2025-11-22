#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "usuario.h"

#define MAX_NOME 20
#define MAX_CPF 15

 struct Usuario {
    char nome[MAX_NOME];
    char cpf[MAX_CPF];
 };

/**
 * @brief Cria um novo usuário.
 * Se não for possível alocar memória, o programa é encerrado.
 * 
 * @return Um ponteiro para o novo usuário criado.
 */
tUsuario *CriaUsuario(){
tUsuario* usuario = (tUsuario*) malloc (sizeof(tUsuario));
if(usuario == NULL){
exit(1);
}

usuario->nome[0] = '\0';
usuario->cpf[0] = '\0';
return usuario;
}

/**
 * @brief Desaloca a memória de um usuário.
 * 
 * @param user Ponteiro para o usuário a ser destruído.
 */
void DestroiUsuario(tUsuario *user){
free(user);

}

/**
 * @brief Lê os dados de um usuário da entrada padrão.
 * 
 * @param user Ponteiro para o usuário a ser lido.
 */
void LeUsuario(tUsuario *user){
scanf("%s ", user->nome);
scanf("%s ", user->cpf);
}

/**
 * @brief Imprime os dados de um usuário.
 * 
 * @param user Ponteiro para o usuário a ser impresso.
 */
void ImprimeUsuario(tUsuario *user){
printf("Nome: %s\n", user->nome);
printf("CPF: %s\n", user->cpf);


}
