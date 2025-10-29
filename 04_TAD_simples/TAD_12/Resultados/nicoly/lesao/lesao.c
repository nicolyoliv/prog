#include <string.h>
#include <stdio.h>
#include "lesao.h"

/*#define MAX_CARTAO_LES 19
#define MAX_ID_LES 11
#define MAX_DIAG_LES 101
#define MAX_REG_LES 101

typedef struct {
    char cartaoSus[MAX_CARTAO_LES];
    char id[MAX_ID_LES];
    char diagnostico[MAX_DIAG_LES];
    char regiao[MAX_REG_LES];
    int malignidade;
} Lesao;*/

/*
Função que cria uma lesão a partir dos parâmetros fornecidos.
@param cartaoSus: Cartão SUS do paciente associado à lesão.
@param id: Identificador único da lesão.
@param diagnostico: Diagnóstico da lesão.
@param regiao: Região do corpo onde a lesão está localizada.
@param malignidade: Indicador de malignidade (1 para maligna, 0 para benigna).
@return A lesão criada.
*/
Lesao criaLesao(char *cartaoSus, char *id, char *diagnostico, char *regiao, int malignidade){

    Lesao l;
    strcpy(l.cartaoSus, cartaoSus);
    strcpy(l.id, id);
    strcpy(l.diagnostico, diagnostico);
    strcpy(l.regiao, regiao);
    l.malignidade = malignidade;
    return l;


}

/*
Função que lê os dados de uma lesão a partir da entrada padrão. Consulte o enunciado e/ou os casos de teste para o formato esperado.
@return A lesão lida.
*/
Lesao lerLesao(){
    Lesao l;
    char cartaoSus[MAX_CARTAO_LES], id[MAX_ID_LES], diagnostico[MAX_DIAG_LES], regiao[MAX_REG_LES];
    int malignidade = 0;

    scanf(" %[^\n]\n", cartaoSus);
    scanf(" %[^\n]\n", id);
    scanf(" %[^\n]\n", diagnostico);
    scanf(" %[^\n]\n", regiao);
    scanf("%d", &malignidade);

    l = criaLesao(cartaoSus, id, diagnostico, regiao, malignidade);
    return l;
}

/*
Função que obtém o cartão SUS associado a uma lesão.
@param l: A lesão da qual se deseja obter o cartão SUS.
@param cartaoSus: String onde o cartão SUS será armazenado.
*/
void getCartaoSusLesao(Lesao l, char *cartaoSus){
    strcpy(cartaoSus, l.cartaoSus);
}

/*
Função que verifica se uma lesão é cirúrgica (maligna).
@param l: A lesão a ser verificada.
@return 1 se a lesão for cirúrgica (maligna), 0 caso contrário.
*/
int verificaCirurgicaLesao(Lesao l){
    if(l.malignidade>=50){
        return 1;
    }return 0;
}

/*
Função que imprime o identificador de uma lesão.
@param l: A lesão cuja identificação será impressa.
*/
void imprimeIdLesao(Lesao l){
    printf("%s ", l.id);
}

