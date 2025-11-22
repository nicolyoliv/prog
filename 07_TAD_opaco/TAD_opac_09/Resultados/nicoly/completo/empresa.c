#include "empresa.h"
#include <stdio.h>


 struct empresa {
  int idemp;
  tFuncionario** funcionario;
  int quant;

 };


/**
 * @brief Cria uma empresa "vazia"
 * 
 * Seus atributos devem ser inicializados com NULL (ponteiros), ou -1 caso contrário
 * @return TEmpresa* Ponteiro para empresa criada a partir do Id fornecido.
 */
tEmpresa* CriaEmpresa(){
tEmpresa* e = (tEmpresa*)malloc(sizeof(tEmpresa));
if(e == NULL){
    exit(1);
}
e->idemp = -1;
e->funcionario = NULL;
e->quant = 0;

return e;
}

/**
 * @brief Le os dados de uma empresa da entrada padrao.
 * @param *empresa - ponteiro para empresa que terá seus dados preenchidos
 */
void LeEmpresa(tEmpresa* empresa){
  int id, quant;

    if (scanf("%d %d", &id, &quant) != 2) {
        exit(1);
    }

    empresa->idemp= id;
    empresa->quant = 0;

    for (int i = 0; i < quant; i++) {
        tFuncionario* f = CriaFuncionario();
        LeFuncionario(f);
        ContrataFuncionarioEmpresa(empresa, f);
    }
}

/**
 * @brief Libera toda a memória alocada dinamicamente para uma empresa
 * @param *empresa - ponteiro para empresa que terá seus dados apagados e memória liberada
 */
void ApagaEmpresa(tEmpresa* empresa){
    for(int i = 0; i<empresa->quant; i++){
        ApagaFuncionario(empresa->funcionario[i]);
    }
    free(empresa->funcionario);
free(empresa);

}


/**
 * @brief Adiciona um funcionario a uma empresa caso o id do funcionario ainda nao esteja registrado na empresa.
 * 
 * @param empresa Ponteiro para Empresa em que o funcionario deve ser adicionado.
 * @param funcionario Ponteiro para Funcionario que deve ser adicionado a empresa.
  */
void ContrataFuncionarioEmpresa(tEmpresa* empresa, tFuncionario* funcionario){

    // Verifica duplicata
    for(int i = 0; i < empresa->quant; i++){
        if(GetIdFuncionario(funcionario) == GetIdFuncionario(empresa->funcionario[i])){
            printf("A empresa %d ja possui um funcionario com o id %d\n",
                   empresa->idemp, GetIdFuncionario(funcionario));
            ApagaFuncionario(funcionario);
            return;
        }
    }

    // Aumenta o vetor para caber +1 funcionário
    empresa->funcionario = (tFuncionario**) realloc(
        empresa->funcionario,
        (empresa->quant + 1) * sizeof(tFuncionario*)
    );

    if (empresa->funcionario == NULL) {
        printf("Erro de alocacao!\n");
        exit(1);
    }

    // Adiciona no final
    empresa->funcionario[empresa->quant] = funcionario;
    empresa->quant++;
}

/**
 * @brief Imprime todos os dados de um empresa.
 * 
 * @param empresa Ponteiro para Empresa a ser impressa no terminal.
 */
void ImprimeEmpresa(tEmpresa *empresa){
    printf("Empresa %d:\n", empresa->idemp);
for(int i = 0;i<empresa->quant;i++){
    ImprimeFuncionario(empresa->funcionario[i]);
}
}