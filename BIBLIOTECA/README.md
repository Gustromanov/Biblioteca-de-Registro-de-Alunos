# 📚 Sistema de Gestão de Alunos

Este projeto é um sistema de **cadastro e gerenciamento de alunos** desenvolvido em **linguagem C**.  
Ele permite inserir, listar, atualizar, remover alunos, gerenciar notas e gerar estatísticas acadêmicas.  
Foi criado como exercício prático de manipulação de arrays, ponteiros e funções em C.

---

## 🚀 Funcionalidades

- 📌 **Cadastrar aluno** (nome, matrícula e notas)  
- 📋 **Listar alunos** com todas as informações  
- ✏️ **Atualizar dados** de um aluno existente  
- ❌ **Remover aluno** pelo número de matrícula  
- 📝 **Atualizar notas** de um aluno  
- 📊 **Calcular médias** individuais  
- ✅ **Verificar aprovação/reprovação** (média ≥ 7.0 = aprovado)  
- 📈 **Exibir estatísticas gerais**: menor nota, maior nota e média geral de um aluno
- 🔎 **Mostrar endereços de memória** (para fins de estudo da contiguidade dos arrays)  

---

## ⚙️ Requisitos para execução

### 🔹 Linux (Ubuntu/Debian/Fedora/Arch ou similares)
- Sistema operacional baseado em Linux  
- Compilador **GCC** instalado  
  - No Ubuntu/Debian, instale com:  
    ```bash
    sudo apt update
    sudo apt install build-essential -y
    ```
  - No Fedora:  
    ```bash
    sudo dnf install gcc gcc-c++ make -y
    ```
  - No Arch Linux:  
    ```bash
    sudo pacman -S base-devel gcc
    ```
- Terminal para compilar e executar o programa  

---

### 🔹 Windows
- Sistema operacional **Windows 10/11**  
- Compilador **MinGW (GCC para Windows)** ou **TDM-GCC**  
  - Download: [MinGW-w64](http://mingw-w64.org/doku.php/download)  
- Variável de ambiente **PATH** configurada para o `bin` do MinGW  
- Uso do **Prompt de Comando (cmd)** ou **PowerShell** para compilar e executar  

---

✅ Após instalar os requisitos, basta seguir os comandos de compilação já mostrados na seção anterior.


## 📂 Estrutura do Projeto

/biblioteca-alunos
│── main.c # Arquivo principal (menu e fluxo do programa)
│── biblioteca.c # Implementação das funções de gerenciamento
│── biblioteca.h # Arquivo de cabeçalho com definições e protótipos
│── programa.exe # Executável compilado (Windows)
│── README.md # Este arquivo

⚠️ O executável (`programa` ou `programa.exe`) será gerado dentro dessa mesma pasta após a compilação.

---

## ▶️ Como compilar e executar

### 🔹 No **Linux/macOS**

1. Abra o terminal dentro da pasta do projeto.  
2. Compile com o comando:

   ```bash
   gcc main.c biblioteca.c -o programa
   ./programa 


### 🔹 No **Windows**

1. Abra o terminal dentro da pasta do projeto.  
2. Compile com o comando:
     .\programa.exe


### 📖 Exemplo de uso (menu)
  
  --- MENU ---
1. Cadastrar aluno
2. Listar alunos
3. Atualizar aluno
4. Remover aluno
5. Atualizar nota
6. Calcular media
7. Verificar aprovacao
8. Estatisticas (minimo, maximo, media)
9. Mostrar enderecos de memoria
0. Sair
Escolha uma opcao:


## 🧪 Exemplo prático de execução

### ✅ Exemplo 1 – Aluno Aprovado

--- MENU ---
1. Cadastrar aluno
Escolha uma opcao: 1
Nome : Maria Silva
Matricula: 101
Nota 1: 8
Nota 2: 7
Nota 3: 9
Aluno cadastrado com sucesso!

--- MENU ---
6. Calcular media
Escolha uma opcao: 6

### Saída esperada:

Aluno: Maria Silva
Media: 8.00

### Verificação de aprovação (opção 7)

Aluno: Maria Silva | Media: 8.00 | Aprovado

### ❌ Exemplo 2 – Aluno Reprovado

--- MENU ---
1. Cadastrar aluno
Escolha uma opcao: 1
Nome : João Souza
Matricula: 102
Nota 1: 4
Nota 2: 5
Nota 3: 6
Aluno cadastrado com sucesso!

--- MENU ---
7. Verificar aprovacao
Escolha uma opcao: 7

### Saída esperada:

Aluno: João Souza | Media: 5.00 | Reprovado


### 📊 Exemplo 3 – Estatísticas gerais

--- MENU ---
8. Estatisticas (minimo, maximo, media)
Escolha uma opcao: 8

### Saída esperada:

Menor nota: 4.00
Maior nota: 9.00
Media geral: 6.83

## 👨‍💻 Autores

- Vinicius Nascimento Araújo;
- Gustavo Batista;
- Vitor Pizolato da Silva.