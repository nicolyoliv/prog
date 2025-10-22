#include <stdio.h>
#include "eleicao.h"


/**
 * @brief Inicializa uma eleição com valores padrão (zerando os votos invalidos).
 * Ainda nessa função, é lido a quantidade de candidatos e os candidatos são lidos e armazenados.
 * @return Eleição inicializada.
 */
tEleicao InicializaEleicao(){
    tEleicao eleicao;

    int pres = 0;
    int gov = 0;
    int quantCand;
  
    eleicao.votosBrancosPresidente = 0;
    eleicao.votosNulosPresidente = 0;
    eleicao.votosBrancosGovernador = 0;
    eleicao.votosNulosGovernador = 0;

    scanf("%d", &quantCand);

    for(int i = 0; i < quantCand; i++){
        tCandidato novoCand = LeCandidato();
        
        if(novoCand.cargo == 'P' && pres < MAX_CANDIDATOS_POR_CARGO){
            eleicao.presidentes[pres] = novoCand;
            pres++;
        }else if(novoCand.cargo == 'G' && gov < MAX_CANDIDATOS_POR_CARGO){
            eleicao.governadores[gov] = novoCand;
            gov++;
        }
    }

    eleicao.totalPresidentes = pres;
    eleicao.totalGovernadores = gov;

    int quantEle;

    scanf("%d", &quantEle);

    for(int i = 0; i< quantEle; i++){
    eleicao.eleitores[i]= LeEleitor();        
    }


    eleicao.totalEleitores = quantEle;

    return eleicao;
}

/**
 * @brief Realiza uma eleição.
 * Nessa função, é lido a quantidade de eleitores e os eleitores são lidos e armazenados.
 * @param eleicao Eleição a ser realizada.
 * @return Eleição com os resultados da votação.
 */
tEleicao RealizaEleicao(tEleicao eleicao){

    tEleicao eleicao;
    int branco = 0;
    int nulo = 0;

    for(int i= 0; i<eleicao.totalEleitores; i ++){

        int votoP = ObtemVotoPresidente(eleicao.eleitores[i]);
        int votoG = ObtemVotoGovernador(eleicao.eleitores[i]);
        int candPEncontrado = 0;
        int candGEncontrado = 0;

       for(int j = 0; j< eleicao.totalPresidentes; j++){
        
        if(VerificaIdCandidato(eleicao.presidentes[j], votoP)){
        eleicao.presidentes[j] = IncrementaVotoCandidato(eleicao.presidentes[j]);       
        candPEncontrado = 1;
        break;
            }
       }
        if(candPEncontrado == 0){
            if(votoP == 0){
                eleicao.votosBrancosPresidente++;
            }else{
                eleicao.votosNulosPresidente++;
            }
       }

          for(int j = 0; j< eleicao.totalGovernadores; j++){
        
        if(VerificaIdCandidato(eleicao.governadores[j], votoP));
        eleicao.governadores[j] = IncrementaVotoCandidato(eleicao.governadores[j]);       
        candGEncontrado = 1;

        break;

        }
        if(candGEncontrado == 0){
            if(votoG == 0){
                eleicao.votosBrancosGovernador++;
            }else{
                eleicao.votosNulosGovernador++;
            }
        }

    }
    return eleicao;
}

/**
 * @brief Imprime o resultado da eleição na tela a partir da apuração dos votos.
 * @param eleicao Eleição a ser impressa.
 */
void ImprimeResultadoEleicao(tEleicao eleicao) {

   
    int maxVotosPres = -1;
    int indiceVencedorPres = -1;
    int totalVotosValidosPres = 0;
    int houveEmpatePres = 0; 
    int totalVotosInvalidosPres = eleicao.votosBrancosPresidente + eleicao.votosNulosPresidente;
    
    for (int i = 0; i < eleicao.totalPresidentes; i++) {
        int votosCandidatoAtual = ObtemVotos(eleicao.presidentes[i]);
        totalVotosValidosPres += votosCandidatoAtual; 
        
        if (votosCandidatoAtual > maxVotosPres) {
            
            maxVotosPres = votosCandidatoAtual;
            indiceVencedorPres = i;
            houveEmpatePres = 0; 
        } else if (votosCandidatoAtual == maxVotosPres && maxVotosPres > 0) {
            houveEmpatePres = 1; 
        }
    }

    printf("- PRESIDENTE ELEITO: ");

    if (indiceVencedorPres == -1 || maxVotosPres == 0) {
        printf("NINGUEM\n");
    } 
    else if (houveEmpatePres) {
    RealizaEleicao(eleicao);
    }
    else if (maxVotosPres < totalVotosInvalidosPres) {
        printf("NINGUEM\n");
    } else {
        tCandidato vencedor = eleicao.presidentes[indiceVencedorPres];
        float perc = CalculaPercentualVotos(vencedor, totalVotosValidosPres); 
        
        ImprimeCandidato(vencedor, perc);
        printf("\n");
    }

    int maxVotosGov = -1;
    int indiceVencedorGov = -1;
    int totalVotosValidosGov = 0;
    int houveEmpateGov = 0;
    int totalVotosInvalidosGov = eleicao.votosBrancosGovernador + eleicao.votosNulosGovernador;

    for (int i = 0; i < eleicao.totalGovernadores; i++) {
        int votosCandidatoAtual = ObtemVotos(eleicao.governadores[i]);
        totalVotosValidosGov += votosCandidatoAtual;
        
        if (votosCandidatoAtual > maxVotosGov) {
            maxVotosGov = votosCandidatoAtual;
            indiceVencedorGov = i;
            houveEmpateGov = 0; 
        } else if (votosCandidatoAtual == maxVotosGov && maxVotosGov > 0) {
            houveEmpateGov = 1;
        }
    }
    printf("- GOVERNADOR ELEITO: ");
    
    if (indiceVencedorGov == -1 || maxVotosGov == 0) {
        printf("NINGUEM\n");
    } else if (houveEmpateGov) {
        printf("NOVA ELEIÇÃO\n"); 
    } else if (maxVotosGov < totalVotosInvalidosGov) {
        printf("NINGUEM\n");
    } else {
        tCandidato vencedor = eleicao.governadores[indiceVencedorGov];
        float perc = CalculaPercentualVotos(vencedor, totalVotosValidosGov);
        
        ImprimeCandidato(vencedor, perc);
        printf("\n");
    }
}