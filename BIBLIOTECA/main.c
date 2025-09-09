#include <stdio.h>
#include "biblioteca.h"

int main() {
    // Declara��o das estruturas principais
    char nomes[MAX_ALUNOS][MAX_NOME];       // Armazena os nomes dos alunos
    int matriculas[MAX_ALUNOS];             // Armazena as matr�culas
    float notas[MAX_ALUNOS][MAX_NOTAS];     // Armazena as notas dos alunos
    int total = 0;                          // Contador de alunos cadastrados
    int opcao;                              // Armazena a op��o do menu
    float min, max, media;                  // Vari�veis para estat�sticas

    // Loop principal do menu
    do {
        // Exibi��o do menu de op��es
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

        // Switch para executar a fun��o correspondente � op��o escolhida
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
                estatisticasNotas(notas, total, matriculas); // Retorna m�ltiplos valores via ponteiros
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

    } while(opcao != 0); // Repete at� que o usu�rio escolha sair

    return 0;
}
