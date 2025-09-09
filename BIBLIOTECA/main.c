#include <stdio.h>
#include "biblioteca.h"

int main() {
    // Declaração das estruturas principais
    char nomes[MAX_ALUNOS][MAX_NOME];       // Armazena os nomes dos alunos
    int matriculas[MAX_ALUNOS];             // Armazena as matrículas
    float notas[MAX_ALUNOS][MAX_NOTAS];     // Armazena as notas dos alunos
    int total = 0;                          // Contador de alunos cadastrados
    int opcao;                              // Armazena a opção do menu
    float min, max, media;                  // Variáveis para estatísticas

    // Loop principal do menu
    do {
        // Exibição do menu de opções
        printf("\n--- MENU ---\n");
        printf("1. Cadastrar aluno\n");
        printf("2. Listar alunos\n");
        printf("3. Atualizar aluno\n");
        printf("4. Remover aluno\n");
        printf("5. Atualizar nota\n");
        printf("6. Calcular media\n");
        printf("7. Verificar aprovacao\n");
        printf("8. Estatisticas (minimo, maximo, media)\n");
        printf("9. Mostrar enderecos de memoria\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        // Switch para executar a função correspondente à opção escolhida
        switch(opcao) {
            case 1:
                cadastrarAluno(nomes, matriculas, notas, &total);
                break;

            case 2:
                listarAlunos(nomes, matriculas, notas, total);
                break;

            case 3:
                atualizarAluno(nomes, matriculas, total);
                break;

            case 4:
                removerAluno(nomes, matriculas, notas, &total);
                break;

            case 5:
                atualizarNota(matriculas, notas, total);
                break;

            case 6:
                calcularMedia(nomes, notas, total);
                break;

            case 7:
                verificarAprovacao(nomes, notas, total);
                break;

            case 8:
                estatisticasNotas(notas, total, matriculas); // Retorna múltiplos valores via ponteiros
                break;

            case 9:
                mostrarEnderecos(nomes, matriculas, notas, total);
                break;

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while(opcao != 0); // Repete até que o usuário escolha sair

    return 0;
}
