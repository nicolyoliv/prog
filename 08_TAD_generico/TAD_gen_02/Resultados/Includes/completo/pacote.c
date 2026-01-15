#include "pacote.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


 struct pacote {
    Type type;
    int numElem;
    void *data;
 };

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar um pacote a ser transmitido
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tPacote* CriaPacote(Type type, int numElem){
    tPacote *p = (tPacote*)calloc(1, sizeof(tPacote));
    if(p == NULL){
        exit(1);
    }

    p->numElem = numElem;
    p->type = type;

    if(type == CHAR){
        p->data = (char*)malloc(sizeof(char)*numElem+1);

    }else if(type== INT){
        p->data = (int*)malloc(sizeof(int)*numElem);

    }
    if(p->data == NULL){
        free(p);
        return NULL;
    }
    return  p;

}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param pac - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiPacote(tPacote* pac){
    free(pac->data);
    free(pac);

}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param pac - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LePacote(tPacote* pac){
    if(pac->type == INT){
        for(int i = 0; i<pac->numElem;i++){
            scanf("%d", &((int*)pac->data)[i]);
        }
    }
    if(pac->type == CHAR){
        for(int i = 0; i<pac->numElem;i++){
            scanf("%s", (char*)pac->data);
        }
    }

}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param pac - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimePacote(tPacote* pac){
    
      if(pac->type == INT){
        for(int i = 0; i<pac->numElem;i++){
            printf("%d", ((int*)pac->data)[i]);
        }
    }
    if(pac->type == CHAR){
        for(int i = 0; i<pac->numElem;i++){
            printf("%c", ((char*)pac->data)[i]);
        }
    }
printf("\n");
}

/**
 * @brief Calcula a soma de verificacao de um pacote e a armazena internamente
 *
 * @param pac - O vetor genérico que terá sua soma de verificacao calculada
 */
void CalculaSomaVerificacaoPacote(tPacote* pac){
    int soma = 0;
    if(pac->type == INT){
        for(int i = 0; i<pac->numElem;i++){
            soma += ((int*)pac->data)[i];
        } 
    }if(pac->type == CHAR){
        for(int i = 0; i<pac->numElem;i++){
             soma += ((char*)pac->data)[i];
        }
    }
  
}

