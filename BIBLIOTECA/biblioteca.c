#include <stdio.h>
#include <string.h>
#include "biblioteca.h"

// ==================================================================Funcao 1 - Cadastrar aluno======================================================================
void cadastrarAluno(char nomes[][MAX_NOME], int matriculas[], float notas[][MAX_NOTAS], int *total) {
    if (*total >= MAX_ALUNOS) {
        printf("Limite de alunos atingido.\n");
        return;
    }

    printf("Nome : ");
    
    getchar();
    fgets(nomes[*total], MAX_NOME, stdin);

    printf("Matricula: ");
    scanf("%d", &matriculas[*total]);

    for (int i = 0; i < MAX_NOTAS; i++) {
        printf("Nota %d: ", i + 1);
        scanf("%f", &notas[*total][i]);
    }

    (*total)++;
    printf("Aluno cadastrado com sucesso!\n");
}

/*
Esta fun  o permite cadastrar um novo aluno no sistema.
Ela recebe os arrays de nomes, matr culas e notas, al m de um ponteiro para o total de alunos.
Primeiro, verifica se o limite de alunos foi atingido. Em seguida, solicita ao usu rio o nome,
a matr cula e as tr s notas do aluno. Ap s o cadastro, incrementa o contador total via ponteiro,
garantindo que o valor seja atualizado fora da fun  o.   uma fun  o essencial para iniciar o uso do sistema.
*/

// ==================================================================  Funcao 2 - Listar alunos =====================================================================
void listarAlunos(char nomes[][MAX_NOME], int matriculas[], float notas[][MAX_NOTAS], int total) {
    if (total < 1) {
	printf("\n######################################\n");

        printf("Nenhum aluno cadastrado.\n Utilize a opcao de cadastros primeiro.\n");
	printf("\n######################################\n");

        return;
    }

    printf("\n--- Lista de Alunos ---\n");
    for (int i = 0; i < total; i++) {
        printf("Nome: %s | Matricula: %d | Notas: ", nomes[i], matriculas[i]);
        for (int j = 0; j < MAX_NOTAS; j++) {
            printf("%.2f ", notas[i][j]);
        }
        printf("\n");
    }
}

/*
A fun  o de listagem percorre todos os registros de alunos cadastrados e imprime suas
informa  es: nome, matr cula e notas. Ela utiliza dois loops: o primeiro para iterar sobre os
alunos e o segundo para exibir as notas de cada um.    til para visualizar rapidamente os dados armazenados no sistema.
*/

// ========================== ======================================    Funcao 3 - Atualizar aluno   ==================================================================
void atualizarAluno(char nomes[][MAX_NOME], int matriculas[], int total) {
    int mat;
    if (total < 1) {
	printf("\n######################################\n");

        printf("Nenhum aluno cadastrado.\n Utilize a opcao de cadastros primeiro.\n");
	printf("\n######################################\n");

        return;
    }
    printf("Digite a matricula do aluno a atualizar: ");
    scanf("%d", &mat);

    for (int i = 0; i < total; i++) {
        if (matriculas[i] == mat) {
            printf("Novo nome : ");
            getchar();
   	        fgets(nomes[i], MAX_NOME, stdin);
            printf("Aluno atualizado!\n");
            return;
         }

        
    }
    printf("Aluno nao encontrado.\n");
}

/*
Esta fun  o permite atualizar os dados de um aluno j  existente.
O usu rio informa a matr cula, e o sistema busca esse aluno no array.
Se encontrado, o nome e as notas s o substitu dos pelos novos valores informados.
Caso a matr cula n o exista, uma mensagem de erro   exibida. A fun  o garante que os dados estejam sempre atualizados.
*/

// ================================================================================   Funcao 4 - Remover aluno   =======================
void removerAluno(char nomes[][MAX_NOME], int matriculas[], float notas[][MAX_NOTAS], int *total) {
    int mat;
     if ((*total) < 1) {
	printf("\n######################################\n");
        printf("Nenhum aluno cadastrado.\n Utilize a opcao de cadastros primeiro.\n");
	printf("\n######################################\n");

        return;
    }

    printf("Digite a matricula do aluno a remover: ");
    scanf("%d", &mat);

    for (int i = 0; i < *total; i++) {
        if (matriculas[i] == mat) {
            for (int j = i; j < *total - 1; j++) {
                strcpy(nomes[j], nomes[j + 1]);
                matriculas[j] = matriculas[j + 1];
                for (int k = 0; k < MAX_NOTAS; k++) {
                    notas[j][k] = notas[j + 1][k];
                }
            }
            (*total)--;
            printf("Aluno removido!\n");
            return;
        }
    }
    printf("Aluno nao encontrado.\n");
}

/*
A fun  o de remo  o busca o aluno pela matr cula e, se encontrado, desloca todos os elementos seguintes uma posi  o para tr s,
 sobrescrevendo o aluno removido. Isso mant m a contiguidade dos dados. O total de alunos   decrementado via ponteiro.
   uma fun  o importante para manter o sistema limpo e atualizado.
*/

// =========================================================================  Funcao 5 - Cadastrar nota   ================================
void atualizarNota(int matriculas[], float notas[][MAX_NOTAS], int total) {
    int mat;
     if (total < 1) {
	printf("\n######################################\n");

        printf("Nenhum aluno cadastrado.\n Utilize a opcao de cadastros primeiro.\n");
	printf("\n######################################\n");

        return;
    }

    printf("Digite a matricula do aluno: ");
    scanf("%d", &mat);

    for (int i = 0; i < total; i++) {
        if (matriculas[i] == mat) {
            for (int j = 0; j < MAX_NOTAS; j++) {
                printf("Nova nota %d: ", j + 1);
                scanf("%f", &notas[i][j]);
            }
            printf("Notas atualizadas!\n");
            return;
        }
    }
    printf("Aluno nao encontrado.\n");
}

/*
Esta fun  o permite alterar as notas de um aluno espec fico. Ap s informar a matr cula, o sistema localiza o aluno
e solicita as novas notas. Se a matr cula n o for encontrada, exibe uma mensagem de erro.
   til para corrigir ou atualizar avalia  es.
*/

//============================================================================= Funcao 6 - Calcular media   ==========================================================
void calcularMedia(char nomes[][MAX_NOME], float notas[][MAX_NOTAS], int total) {
     if (total < 1) {
	printf("\n######################################\n");

        printf("Nao ha notas cadastradas.\n");
	printf("\n######################################\n");

        return;
    }

    for (int i = 0; i < total; i++) {
        float soma = 0;
        for (int j = 0; j < MAX_NOTAS; j++) {
            soma += notas[i][j];
        }
        float media = soma / MAX_NOTAS;
        printf("Aluno: %s | Media: %.2f\n", nomes[i], media);
    }
}

/*
A fun  o calcula a m dia das notas de cada aluno. Para isso, soma as tr s notas e divide por tr s.
Em seguida, imprime o nome do aluno e sua m dia.   uma fun  o simples, mas essencial para avaliar o desempenho acad mico.
*/

// ================================================================================  Funcao 7 - Verificar aprovacao  =================================================
void verificarAprovacao(char nomes[][MAX_NOME], float notas[][MAX_NOTAS], int total) {
     if (total < 1) {
	printf("\n######################################\n");

        printf("Nenhum aluno cadastrado.\n Utilize a opcao de cadastros primeiro.\n");
	printf("\n######################################\n");

        return;
    }

    for (int i = 0; i < total; i++) {
        float soma = 0;
        for (int j = 0; j < MAX_NOTAS; j++) {
            soma += notas[i][j];
        }
        float media = soma / MAX_NOTAS;
        printf("Aluno: %s | Media: %.2f | %s\n", nomes[i], media, media >= 7.0 ? "Aprovado" : "Reprovado");
    }
}

/*
Esta fun  o verifica se cada aluno est  aprovado ou reprovado com base na m dia.
A m dia   calculada como na fun  o anterior, e o resultado   comparado com o valor m nimo de aprova  o (7.0).
A fun  o imprime o status de cada aluno, facilitando o acompanhamento do rendimento.
*/

//========================================================================    Funcao 8 - Estatisticas   ==============================================================
void estatisticasNotas(float notas[][MAX_NOTAS], int total, int matriculas[]) {
     float min;
     float max; 
     float media;
     int mat;
     if (total < 1) {
	printf("\n######################################\n");

        printf("Nao ha notas cadastradas.\n Indisponivel.\n");
	printf("\n######################################\n");
        return;
    }
    printf("Digite a matricula do aluno: ");
    scanf("%d", &mat);

    min = notas[0][0];
    max = notas[0][0];
    float soma = 0;
    int count = 0;
   
    for (int i = 0; i < total; i++) {
	 if (matriculas[i] == mat) {
		for (int j = 0; j < MAX_NOTAS; j++) {
         	 	float nota = notas[i][j];
		 	if (nota < min) min = nota;
       		 	if (nota > max) max = nota;
         	 	soma += nota;
         	 	count++;
        	 }
   	 

    	 	media = (count > 0) ? soma / count : 0;
		printf("Menor nota: %.2f\nMaior nota: %.2f\nMedia geral: %.2f\n", min, max, media);
	 	return;
     	 }
     }
     printf("Aluno nao encontrado.\n Veja se a matricula esta correta.\n");


}

/*
Esta fun  o calcula tr s estat sticas importantes: a menor nota, a maior nota e a m dia geral de todas
as notas cadastradas. Ela percorre todos os alunos e todas as notas, atualizando os valores conforme necess rio.
Os resultados s o retornados via ponteiros, permitindo m ltiplos retornos em uma  nica fun  o.
*/

// ===============================================================================================   Funcao 9 - Mostrar enderecos de memoria  =========================
void mostrarEnderecos(char nomes[][MAX_NOME], int matriculas[], float notas[][MAX_NOTAS], int total) {
    if (total < 1) {
	printf("\n######################################\n");

        printf("Nenhum aluno cadastrado.\n Utilize a opcao de cadastros primeiro.\n");
	printf("\n######################################\n");

        return;
    }
    printf("\n--- Enderecos de memoria dos alunos ---\n");
    for (int i = 0; i < total; i++) {
        printf("Aluno %d: Nome=%p Matricula=%p Notas=%p\n", i + 1,
               (void*)&nomes[i], (void*)&matriculas[i], (void*)&notas[i]);
    }
}

/*
Esta fun  o imprime os endere os de mem ria dos dados de cada aluno: nome, matr cula e notas.
Isso    til para verificar se os dados est o armazenados de forma cont gua na mem ria, como exigido no trabalho.
O uso de (void*) garante que os ponteiros sejam exibidos corretamente no printf.
Essa fun  o refor a o entendimento sobre como os arrays est o organizados na mem ria.*/
