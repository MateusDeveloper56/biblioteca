/**
 * Faculdade - Aula prática
 * @file Sistema de biblioteca em C
 * @details Objetivo - Implementar o cadastro e a listagem de livros usando um array estático. foco em structs, estrada/saída de dados e organização básica.
 */

 /**
  * Importando bibliotecas
  */
#include <stdio.h> 
#include <stdlib.h>
#include <string.h> // Para strcspn() 

/**
 * Definindo constantes globais
 */
#define MAX_LIVROS 50
#define TAM_STRING 100

/**
 * Definição de estrutura para representar um livro
 */
struct Livro {
    int id;
    char nome [TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    char titulo[TAM_STRING];
    int edicao;
    int ano_publicacao;
};
typedef struct Livro Livro;

/**
 * Definição de estrutura para representar a biblioteca
 */
// typedef struct {
//     Livro livros[MAX_LIVROS];
//     int totalLivros;
// } Biblioteca;

/**
 * Limpar o buffer de entrada
 */
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/**
 * Função principal (main)
 */
int main() {
    struct Livro biblioteca[MAX_LIVROS];
    int totalLivros = 0;
    int opcao;

    /**
     * Laço principal do menu.
     */
    do {
        printf("\nSistema de Biblioteca\n");
        printf("1. Cadastrar Livro\n");
        printf("2. Listar Livros\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        limparBufferEntrada();

        switch (opcao) {
            case 1:
                if (totalLivros < MAX_LIVROS) {
                    Livro novo_livro;
                    novo_livro.id = totalLivros + 1;

                    printf("Digite o nome do livro: ");
                    fgets(novo_livro.nome, TAM_STRING, stdin);
                    novo_livro.nome[strcspn(novo_livro.nome, "\n")] = 0; // Remover nova linha

                    printf("Digite o autor do livro: ");
                    fgets(novo_livro.autor, TAM_STRING, stdin);
                    novo_livro.autor[strcspn(novo_livro.autor, "\n")] = 0;

                    printf("Digite a editora do livro: ");
                    fgets(novo_livro.editora, TAM_STRING, stdin);
                    novo_livro.editora[strcspn(novo_livro.editora, "\n")] = 0;

                    printf("Digite o titulo do livro: ");
                    fgets(novo_livro.titulo, TAM_STRING, stdin);
                    novo_livro.titulo[strcspn(novo_livro.titulo, "\n")] = 0;

                    printf("Digite a edicao do livro: ");
                    scanf("%d", &novo_livro.edicao);
                    limparBufferEntrada();

                    printf("Digite o ano de publicacao do livro: ");
                    scanf("%d", &novo_livro.ano_publicacao);
                    limparBufferEntrada();

                    biblioteca[totalLivros] = novo_livro;
                    totalLivros++;

                    printf("Livro cadastrado com sucesso!\n");
                } else {
                    printf("Capacidade maxima de livros atingida!\n");
                }

                printf("\nPressione Enter para continuar...");
                getchar();
                break;

            case 2:
                if (totalLivros == 0) {
                    printf("Nenhum livro cadastrado.\n");
                } else {
                    printf("\nLista de Livros Cadastrados:\n");
                    for (int i = 0; i < totalLivros; i++) {
                        printf("ID: %d\n", biblioteca[i].id);
                        printf("Nome: %s\n", biblioteca[i].nome);
                        printf("Autor: %s\n", biblioteca[i].autor);
                        printf("Editora: %s\n", biblioteca[i].editora);
                        printf("Titulo: %s\n", biblioteca[i].titulo);
                        printf("Edicao: %d\n", biblioteca[i].edicao);
                        printf("Ano de Publicacao: %d\n", biblioteca[i].ano_publicacao);
                        printf("-------------------------\n");
                    }
                }

                printf("\nPressione Enter para continuar...");
                getchar();
                break;

            case 3:
                printf("Saindo do sistema...\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 3);

    return 0;
}


