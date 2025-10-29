#include <stdio.h>
#include <string.h>
#include "reserva.h"
#include <locale.h>

#define MAX_LUG 100
#define MAX_MOR 100
#define MAX_RES 100

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int quantA = 0, quantM = 0, quantR = 0;
    Area area[MAX_LUG];
    Morador morador[MAX_MOR];
    Reserva reserva[MAX_RES];
    Data data;
    char id[MAX_TAM_ID], cpf[MAX_TAM_CPF];
    int numConv = 0, aceito = 0, achoucpf =0, achouarea =0;
    scanf(" %d\n", &quantA);

    for (int i = 0; i < quantA; i++)
    {
        area[i] = lerArea();
    }

    scanf(" %d\n", &quantM);

    for (int i = 0; i < quantM; i++)
    {
        morador[i] = lerMorador();
    }
    scanf(" %d\n", &quantR);
    for (int i = 0; i < quantR; i++)
    {
        scanf(" %[^\n]\n", id);
        scanf(" %[^\n]\n", cpf);
        data = lerData();
        scanf(" %d\n", &numConv);

        Morador moradorSel = {0};
        Area areaSel = {0};

        for (int i = 0; i < quantM; i++)
        {
            if (verificaCPFMorador(morador[i], cpf))
            {
                moradorSel = morador[i];
                achoucpf =1;
                break;
            }
        }
        for (int i = 0; i < quantA; i++)
        {
            if (verificaIdArea(area[i], id))
            {
                areaSel = area[i];
                achouarea  =1;
                break;
            }
        }

        if(achouarea ==0 || achoucpf ==0){
            continue;
        }
        if (verificaSolicitacaoReserva(reserva, i, moradorSel, areaSel, data, numConv))
        {

            reserva[aceito] = criaReserva(moradorSel, areaSel, data, numConv);
            aceito++;
        }
    }
    for (int i = 0; i < aceito; i++)
    {

        imprimeReserva(reserva[i]);
    }

    return 0;
}