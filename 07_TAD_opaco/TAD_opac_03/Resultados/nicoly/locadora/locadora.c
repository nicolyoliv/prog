#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "locadora.h"

#define MAX_FILMES 1000

struct Locadora {
    tFilme** filme; 
    int numFilmes; 
    int lucro; 
};

tLocadora* CriarLocadora () {
    tLocadora* locadora = (tLocadora*) malloc(sizeof(tLocadora));
    
    if (locadora == NULL) {
        printf("Falha na alocacao de memoria\n");
        exit(1);
    }

    locadora->filme = (tFilme**) malloc(MAX_FILMES * sizeof(tFilme*));

    if (locadora->filme == NULL) {
        printf("Falha na alocacao de memoria\n");
        exit(1);
    }
    
    for (int i = 0; i < MAX_FILMES; i++) {
        locadora->filme[i] = NULL;
    }

    locadora->numFilmes = 0;
    locadora->lucro = 0;

    return locadora;
}

void DestruirLocadora (tLocadora* locadora) {
    for (int i = 0; i < locadora->numFilmes; i++) {
        DestruirFilme(locadora->filme[i]);
    }
    free(locadora->filme);
    free(locadora);
}

int VerificarFilmeCadastrado (tLocadora* locadora, int codigo) {
    for (int i = 0; i < locadora->numFilmes; i++) {
        if (EhMesmoCodigoFilme(locadora->filme[i], codigo)) {
            return 1;
        }
    }
    return 0;
}

void CadastrarFilmeLocadora (tLocadora* locadora, tFilme* filme) {
    int codigo = ObterCodigoFilme(filme);
    
    // USAR a função auxiliar. Se retornar 1, o filme JÁ EXISTE.
    if (VerificarFilmeCadastrado(locadora, codigo)) {
        printf("Filme ja cadastrado no estoque\n");
        DestruirFilme(filme); // LIBERA A MEMÓRIA DO FILME DUPLICADO
        return;
    }

    // Se o filme for novo e houver espaço
    if (locadora->numFilmes < MAX_FILMES) {
        locadora->filme[locadora->numFilmes] = filme;
        locadora->numFilmes++;
        printf("Filme cadastrado - %d - ", codigo);
        ImprimirNomeFilme(locadora->filme[locadora->numFilmes - 1]);
        printf("\n");
    } else {
        // Tratar o caso de limite máximo (embora MAX_FILMES=100 seja o limite do problema)
        DestruirFilme(filme);
    }
}

void LerCadastroLocadora (tLocadora* locadora) {
    int codigo;
    char c;
    
    // Leitura no formato: ##,@@,$$$,%%
    while (scanf("%d,", &codigo) == 1) { 
        tFilme* novoFilme = CriarFilme(); // 1. Aloca um NOVO filme
        LeFilme(novoFilme, codigo);      // 2. Lê os dados no novo filme
        CadastrarFilmeLocadora(locadora, novoFilme); // 3. Cadastra (ou destrói)
        
        // Verifica o caractere de parada ou próximo número
        if (scanf(" %c", &c) == 1 && c == '#') {
            break; // Fim do bloco
        } else if (c == '#') {
             break; // Caso em que o '#' já foi lido
        } else {
            // Devolve o caractere lido ao buffer (para ler o próximo código)
            ungetc(c, stdin); 
        }
    }
}

void AlugarFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos) {
    int qtdAlugados = 0;
    int custo = 0;
    
    for (int i = 0; i < quantidadeCodigos; i++) {
        if (!VerificarFilmeCadastrado(locadora, codigos[i])) {
            printf("Filme %d nao cadastrado.\n", codigos[i]);
        } else {
            for (int j = 0; j < locadora->numFilmes; j++) {
                if (EhMesmoCodigoFilme(locadora->filme[j], codigos[i])) {
                    tFilme* filme = locadora->filme[j];
                    int codigo = ObterCodigoFilme(filme);
                    int qtdEstoque = ObterQtdEstoqueFilme(filme);

                    if (!qtdEstoque) {
                        printf("Filme %d - ", codigo);
                        ImprimirNomeFilme(filme);
                        printf(" nao disponivel no estoque. Volte mais tarde.\n");
                    } else {
                        AlugarFilme(filme);
                        custo += ObterValorFilme(filme);
                        qtdAlugados++;
                    }
                    break;
                }
            }
        }
    }

    if (qtdAlugados > 0) {
        printf("Total de filmes alugados: %d com custo de R$%d\n", qtdAlugados, custo);
    } 

    printf("\n");
}
void LerAluguelLocadora (tLocadora* locadora) {
    int codigos[MAX_FILMES]; // Armazena códigos temporariamente
    int qtdCodigos = 0;
    int codigo;
    char c;

    // Tenta ler um número; se conseguir, armazena e continua
    while (scanf("%d", &codigo) == 1) {
        codigos[qtdCodigos++] = codigo;
        
        // Em seguida, verifica o próximo caractere. Se for '#' ou EOF, para.
        if (scanf(" %c", &c) == 1) {
            if (c == '#') {
                break; 
            } else {
                // Se não for '#' (é um espaço ou nova linha), devolve o caractere para o buffer
                ungetc(c, stdin); 
            }
        } else {
            // Se EOF (fim de arquivo), para
            break; 
        }

        if (qtdCodigos >= MAX_FILMES) break; // Proteção contra overflow
    }

    AlugarFilmesLocadora(locadora, codigos, qtdCodigos);
}
void DevolverFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos) {
    for (int i = 0; i < quantidadeCodigos; i++) {
        if (!VerificarFilmeCadastrado(locadora, codigos[i])) {
            printf("Filme %d nao cadastrado.\n", codigos[i]);
        } else {
            for (int j = 0; j < locadora->numFilmes; j++) {
                if (EhMesmoCodigoFilme(locadora->filme[j], codigos[i])) {
                    tFilme* filme = locadora->filme[j];
                    int codigo = ObterCodigoFilme(filme);
                    int qtdAlugada = ObterQtdAlugadaFilme(filme);
                    int valor = ObterValorFilme(filme);
                  
                    if (!qtdAlugada) {
                        printf("Nao e possivel devolver o filme %d - ", codigo);
                        ImprimirNomeFilme(filme);
                        printf(".\n");
                    } else {
                        DevolverFilme(filme);
                        locadora->lucro += valor;
                        printf("Filme %d - ", codigo);
                        ImprimirNomeFilme(filme);
                        printf(" Devolvido!\n");
                    }
                    break;
                }
            }
        }
    }
}

void LerDevolucaoLocadora (tLocadora* locadora) {
    int codigo[MAX_FILMES];
    int qtdCodigos = 0;
    int i = 0;

    while (1) {
        if (scanf("%d", &codigo[i++]) == 1) {
            qtdCodigos++;
        } else {
            break;
        }
    }

    DevolverFilmesLocadora(locadora, codigo, qtdCodigos);
}

void OrdenarFilmesLocadora (tLocadora* locadora) {
    for (int i = 0; i < locadora->numFilmes - 1; i++) {
        for (int j = i + 1; j < locadora->numFilmes; j++) {
            if (CompararNomesFilmes(locadora->filme[i], locadora->filme[j]) > 0) {
                tFilme* aux = locadora->filme[i];
                locadora->filme[i] = locadora->filme[j];
                locadora->filme[j] = aux;
            }
        }
    }
}

void ConsultarEstoqueLocadora (tLocadora* locadora) {
    printf("~ESTOQUE~\n");
    for (int i = 0; i < locadora->numFilmes; i++) {
        tFilme* filme = locadora->filme[i];
        int codigo = ObterCodigoFilme(filme);
        int qtdEstoque = ObterQtdEstoqueFilme(filme);

        printf("%d - ", codigo);
        ImprimirNomeFilme(filme);
        printf(" Fitas em estoque: %d\n", qtdEstoque);
    }
    printf("\n");
}

void ConsultarLucroLocadora (tLocadora* locadora) {
    if (locadora->lucro) {
        printf("Lucro total R$%d\n", locadora->lucro);
    }
}