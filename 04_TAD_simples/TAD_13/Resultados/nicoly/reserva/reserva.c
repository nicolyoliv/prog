#include <stdio.h>
#include <string.h>
#include "reserva.h"


/**typedef struct
{
    Morador morador;
    Area area;
    Data data;
    int qtdConvidados;
} Reserva;
*/
/**
 * Função que recebe os dados necessários para criar uma reserva
 * e retorna a reserva criada.
 * morRes: Morador que está fazendo a reserva
 * aRes: Área que está sendo reservada
 * dRes: Data da reserva
 * qtdConvidados: Quantidade de convidados que o morador irá levar
 *
 * Retorna uma Reserva com os dados informados
 */
Reserva criaReserva(Morador morRes, Area aRes, Data dRes, int qtdConvidados){
    Reserva r;

    r.morador = morRes;
    r.area = aRes;
    r.data = dRes;
    r.qtdConvidados = qtdConvidados;
    return r;
}

/**
 * Função que verifica se é possível realizar uma reserva solicitada com os dados informados.
 * Essa verificação é baseada em todas as regras de reserva de áreas comuns descritas na especificação.
 *
 * agendaReservas: array que armazena todas as reservas de áreas comuns já realizadas
 * nRes: quantidade de reservas contidas no array agendaReservas
 * morRes: Morador que está solicitando a reserva
 * aRes: Área que está sendo solicitada
 * dRes: Data da reserva solicitada
 * qtdConvidados: Quantidade de convidados que o morador irá levar
 *
 * Retorna 1 se a reserva pode ser realizada e 0 caso contrário
 */
int verificaSolicitacaoReserva(Reserva *agendaReservas, int nRes, Morador morRes, Area aRes, Data dRes, int qtdConvidados){

    if(calculaIdadeMorador(morRes, dRes)<18){
        return 0;
    }if(qtdConvidados>getCapacidadeArea(aRes)){
        return 0;
    }
    for(int i = 0; i<nRes;i++){
        if(comparaMorador(agendaReservas[i].morador, morRes)&& comparaData(agendaReservas[i].data, dRes)){
            return 0;
        }
    }
    for(int i = 0; i<nRes;i++){
        if(comparaArea(agendaReservas[i].area, aRes) && comparaData(agendaReservas[i].data, dRes)){
            return 0;
        }
    }
    return 1;
}

/**
 * Função que imprime todas as informações de uma Reserva conforme o formato
 * descrito na especificação. Dica: veja o arquivo de saída nos casos de teste.
 *
 */
void imprimeReserva(Reserva r){

    int ocup =0;
    int capacidade = 0;
    capacidade = getCapacidadeArea(r.area);
    ocup = (int)((float)r.qtdConvidados*100)/capacidade;
printf("--------- RESERVA -----------\n");
printf("Morador:\n");
imprimeMorador(r.morador);
printf("\n");
printf("Area reservada:\n");
imprimeArea(r.area);
printf("Data da reserva: ");
imprimeData(r.data);
printf("\n");
printf("Quantidade de convidados: %d\n", r.qtdConvidados);
printf("Taxa de ocupação: %d%%\n", ocup);
printf("\n");
printf("------------------------------\n");
}
