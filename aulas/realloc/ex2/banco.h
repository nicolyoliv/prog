#ifndef banco
#define banco
 #include "pessoa.h"

typedef struct {


    tPessoa **dados;
    int tamUsado;
    int tamAlocado;
}Banco;

Banco* criaBanco();
void liberaBanco(Banco **b);
void insereBanco(Banco **b, tPessoa *p);

#endif