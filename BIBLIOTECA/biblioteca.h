#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#define MAX_ALUNOS 100
#define MAX_NOTAS 3
#define MAX_NOME 50

// Funcoes principais

// Cadastra um novo aluno, incluindo nome, matrícula e notas
void cadastrarAluno(char nomes[][MAX_NOME], int matriculas[], float notas[][MAX_NOTAS], int *total);

// Lista todos os alunos cadastrados com suas informações
void listarAlunos(char nomes[][MAX_NOME], int matriculas[], float notas[][MAX_NOTAS], int total);

// Atualiza os dados de um aluno existente com base na matrícula
void atualizarAluno(char nomes[][MAX_NOME], int matriculas[], int total);

// Remove um aluno do sistema com base na matrícula
void removerAluno(char nomes[][MAX_NOME], int matriculas[], float notas[][MAX_NOTAS], int *total);

// Permite alterar as notas de um aluno específico
void atualizarNota(int matriculas[], float notas[][MAX_NOTAS], int total);

// Calcula e exibe a média das notas de cada aluno
void calcularMedia(char nomes[][MAX_NOME], float notas[][MAX_NOTAS], int total);

// Verifica se cada aluno está aprovado ou reprovado com base na média
void verificarAprovacao(char nomes[][MAX_NOME], float notas[][MAX_NOTAS], int total);

// Calcula estatísticas gerais: menor nota, maior nota e média geral
void estatisticasNotas(float notas[][MAX_NOTAS], int total, int matriculas[]);

// Mostra os endereços de memória dos dados dos alunos para verificar contiguidade
void mostrarEnderecos(char nomes[][MAX_NOME], int matriculas[], float notas[][MAX_NOTAS], int total);

#endif
