#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_contato.h"
#include "vector.h"

 struct ListaContato {
    Vector *contato;
    int quant;
 };

/**
 * @brief Cria uma lista de contatos.
 * 
 * @return tListaContato* Retorna um ponteiro para a lista de contatos criada. Caso não seja possível alocar memória, encerra o programa.
*/
tListaContato *CriarListaContato(){
    tListaContato* l = (tListaContato*)calloc(1, sizeof(tListaContato));
    if(l==NULL){
        exit(1);

    }
    l->contato = VectorConstruct();
    return l;
}

/**
 * @brief Libera a memória alocada para uma lista de contatos.
 * 
 * @param l Ponteiro para a lista de contatos a ser liberada.
*/
void DestruirListaContato(tListaContato *l) {
    if (!l) return;
    VectorDestroy(l->contato, (void (*)(DataType))DestruirContato);
    free(l); // CORREÇÃO: Libera a struct tListaContato
}

/**
 * @brief Adiciona um contato a uma lista de contatos, somente se o contato ainda não existir na lista 
 * (não pode haver dois contatos com o mesmo nome e/ou número de telefone).
 * 
 * @param l Ponteiro para a lista de contatos.
 * @param contato Ponteiro para o contato a ser adicionado.
*/
void AdicionarContatoListaContato(tListaContato *l, tContato *contato){
    int total = VectorSize(l->contato);
    for(int i = 0; i < total; i++){
        tContato *existente = (tContato*)VectorGet(l->contato, i);
        if(ComparaNomeContato(existente, contato) || ComparaTelefoneContato(existente, contato)){
            printf("\nJa existe um contato com esse nome e/ou numero de telefone\n");
            DestruirContato(contato); // Libera o contato que não será usado
            return;
        }
    }
    VectorPushBack(l->contato, contato);
}

/**
 * @brief Carrega uma lista de contatos de um arquivo binário.
 * Se o arquivo não existir, a lista de contatos permanece vazia.
 * Dica: Se o arquivo não existir, o ponteiro para o arquivo será NULL. Portanto, se o ponteiro for NULL, a função deve retornar sem fazer nada.
 * 

 *  - char[100]: nome
 *  - char[20]: telefone
 * 
 * @param l Ponteiro para a lista de contatos.
 * @param nomeArquivo Nome do arquivo binário de onde a lista de contatos será carregada.
*/
void CarregarListaContato(tListaContato *l, char* nomeArquivo){
    FILE* f = fopen(nomeArquivo, "rb");
    if(!f) return; // Essencial para não dar crash

    int quantidade;
    if(fread(&quantidade, sizeof(int), 1, f) == 1){
        for(int i = 0; i < quantidade; i++){
            tContato *c = CarregarContato(f);
            if(c) VectorPushBack(l->contato, c); // Adiciona ao vetor!
        }
    }
    fclose(f);
}
/**
 * @brief Salva uma lista de contatos em um arquivo binário.
 * 
 * Formato do arquivo binário:
 * - int: quantidade de contatos
 * - para cada contato:
 *  - char[100]: nome
 *  - char[20]: telefone
 * 
 * @param l Ponteiro para a lista de contatos.
 * @param nomeArquivo Nome do arquivo binário onde a lista de contatos será salva.
*/
void SalvarListaContato(tListaContato *l, char* nomeArquivo) {
    FILE* f = fopen(nomeArquivo, "wb");
    if (!f) return;

    int total = VectorSize(l->contato); // Use o tamanho real do vetor
    fwrite(&total, sizeof(int), 1, f);
    
    for (int i = 0; i < total; i++) { // Use 'total' aqui
        tContato *c = (tContato*)VectorGet(l->contato, i);
        SalvarContato(c, f);
    }
    fclose(f);
}

/**
 * @brief Busca um contato na lista de contatos pelo número de telefone e imprime as informações do contato na tela.
 * Se o contato não existir, imprime "Contato nao encontrado".
 * 
 * @param l Ponteiro para a lista de contatos.
*/
void BuscarPorNumeroTelefoneListaContato(tListaContato *l) {
    unsigned long int telefone;
    if (scanf("%lu", &telefone) != 1) return;

    int total = VectorSize(l->contato);
    int encontrado = 0;

    for (int i = 0; i < total; i++) {
        tContato *c = (tContato*)VectorGet(l->contato, i);
        if (GetTelefoneContato(c) == telefone) { 
            ImprimirContato(c);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) printf("\nContato nao encontrado\n");
}

/**
 * @brief Busca um contato na lista de contatos pelo nome.
*/
void BuscarPorNomeListaContato(tListaContato *l) {
    char nome[100];
    // O espaço antes de % garante que ignore quebras de linha pendentes
    if (scanf(" %[^\n]", nome) != 1) return; 

    int total = VectorSize(l->contato);
    int encontrado = 0;

    for (int i = 0; i < total; i++) {
        tContato *c = (tContato*)VectorGet(l->contato, i);
        if (strcmp(GetNomeContato(c), nome) == 0) {
            ImprimirContato(c);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) printf("\nContato nao encontrado\n");
}

/**
 * @brief Imprime a lista de contatos na tela seguindo a formatação exata.
*/
void ImprimirListaContato(tListaContato *l) {
    int total = VectorSize(l->contato);
    // Apenas imprime o título se houver contatos ou conforme exigido pelo teste
    printf("\nLista de contatos cadastrados\n");
    
    for (int i = 0; i < total; i++) {
        tContato *c = (tContato*)VectorGet(l->contato, i);
        ImprimirContato(c);
    }
    printf("\n");
}
/**
 * @brief Remove um contato da lista de contatos caso ele exista.
 * 
 * @param l Ponteiro para a lista de contatos.
*/
void RemoverContatoListaContato(tListaContato *l){
    unsigned long int telefone;
    scanf("%lu", &telefone);
    
    int total = VectorSize(l->contato);
    for(int i = 0; i < total; i++){
        tContato *c = (tContato*)VectorGet(l->contato, i);
        if(GetTelefoneContato(c) == telefone){
            // Se o Vector não destrói o dado sozinho, destrua-o antes de remover o ponteiro
            DestruirContato(c); 
            VectorRemove(l->contato, i);
            printf("\nContato removido com sucesso\n");
            return;
        }
    }
    printf("\nNao existe um contato cadastrado com esse numero de telefone\n");
}

