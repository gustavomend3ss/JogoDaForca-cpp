# 🎮 Jogo da Forca em C++

![C++](https://img.shields.io/badge/C++-11-blue.svg)
![Platform](https://img.shields.io/badge/platform-Windows-lightgrey)
![Status](https://img.shields.io/badge/status-Estudo-green)

Implementação do clássico **Jogo da Forca** em **C++**, executado no terminal.

O jogador deve descobrir a palavra secreta chutando letras até acertar todas ou atingir o limite de erros.

Este projeto foi desenvolvido durante os estudos de **Introdução à Linguagem C++**, explorando estruturas da STL, manipulação de arquivos e organização de código em funções.

# 📸 Exemplo de execução

*********************
*** Jogo da Forca ***
*********************

Chutes errados: 

_ _ _ _ _ _ _ _ 

Seu chute: A
Você acertou! Seu chute está na palavra.

_ _ _ A _ _ _ _


# 📌 Funcionalidades

- 🎲 Palavra secreta sorteada aleatoriamente
- 🔤 Exibição da palavra com letras ocultas
- ❌ Registro de chutes errados
- ✔️ Revelação das letras corretas
- 📂 Leitura de palavras de um arquivo externo
- ➕ Possibilidade de adicionar novas palavras ao banco


# 🧠 Conceitos de C++ utilizados
Durante o desenvolvimento foram aplicados diversos conceitos importantes:

### Estruturas de dados
- `string`
- `map`
- `vector`

### Estruturas de controle
- `if / else`
- `for`
- `while`

### Manipulação de arquivos
- `ifstream`
- `ofstream`

### Geração de números aleatórios
- `srand()`
- `rand()`

### Organização do código
- separação do código em funções

# 📚 Bibliotecas utilizadas

```cpp
#include <iostream> -> entrada e saída de dados
#include <string> -> manipulação de palavras
#include <map> -> estrutura de dicionário
#include <vector> -> lista dinâmica
#include <fstream> -> leitura e escrita de arquivos
#include <ctime> / #include <cstdlib> -> números aleatórios
#include <windows.h> -> configuração UTF-8 no console

# 📂 Estrutura do projeto

JogoDaForca
│
├── forca.cpp
├── lista.txt
└── README.md

# 📄 Arquivo de palavras

O arquivo lista.txt contém o banco de palavras utilizadas pelo jogo.

Exemplo:
5
MORANGO
ABACATE
UVA
MELANCIA
LIMAO

## 🛠️ Compilação com Makefile

O projeto também utiliza **Makefile** para automatizar o processo de compilação.

O Make permite que o programa seja compilado com apenas um comando no terminal, evitando a necessidade de digitar todo o comando `g++` manualmente.

### Makefile utilizado

```make
CXX = g++

CXXFLAGS = -std=c++11 -fexec-charset=UTF-8

forca: forca.cpp
	$(CXX) $(CXXFLAGS) forca.cpp -o forca

| Elemento               | Função                                       |
| ---------------------- | -------------------------------------------- |
| `CXX`                  | define qual compilador será utilizado        |
| `CXXFLAGS`             | define parâmetros adicionais para compilação |
| `-std=c++11`           | habilita recursos da versão C++11            |
| `-fexec-charset=UTF-8` | permite exibição correta de acentos          |

Basta executar no terminal:
make

Se o programa já estiver compilado e não houver alterações no código, o Make exibirá:
make: 'forca' is up to date.

Executar o programa:
./forca



