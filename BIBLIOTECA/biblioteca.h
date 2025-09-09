#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#define MAX_ALUNOS 100
#define MAX_NOTAS 3
#define MAX_NOME 50

// Funcoes principais

// Cadastra um novo aluno, incluindo nome, matr�cula e notas
void cadastrarAluno(char nomes[][MAX_NOME], int matriculas[], float notas[][MAX_NOTAS], int *total);

// Lista todos os alunos cadastrados com suas informa��es
void listarAlunos(char nomes[][MAX_NOME], int matriculas[], float notas[][MAX_NOTAS], int total);

// Atualiza os dados de um aluno existente com base na matr�cula
void atualizarAluno(char nomes[][MAX_NOME], int matriculas[], int total);

// Remove um aluno do sistema com base na matr�cula
void removerAluno(char nomes[][MAX_NOME], int matriculas[], float notas[][MAX_NOTAS], int *total);

// Permite alterar as notas de um aluno espec�fico
void atualizarNota(int matriculas[], float notas[][MAX_NOTAS], int total);

// Calcula e exibe a m�dia das notas de cada aluno
void calcularMedia(char nomes[][MAX_NOME], float notas[][MAX_NOTAS], int total);

// Verifica se cada aluno est� aprovado ou reprovado com base na m�dia
void verificarAprovacao(char nomes[][MAX_NOME], float notas[][MAX_NOTAS], int total);

// Calcula estat�sticas gerais: menor nota, maior nota e m�dia geral
void estatisticasNotas(float notas[][MAX_NOTAS], int total, int matriculas[]);

// Mostra os endere�os de mem�ria dos dados dos alunos para verificar contiguidade
void mostrarEnderecos(char nomes[][MAX_NOME], int matriculas[], float notas[][MAX_NOTAS], int total);

#endif
