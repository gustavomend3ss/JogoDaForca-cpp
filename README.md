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

## 📚 Bibliotecas utilizadas

O projeto utiliza algumas bibliotecas da linguagem C++ para lidar com entrada de dados, manipulação de estruturas e leitura de arquivos.

```cpp
#include <iostream>   // entrada e saída de dados
#include <string>     // manipulação de palavras
#include <map>        // estrutura de dicionário
#include <vector>     // lista dinâmica
#include <fstream>    // leitura de arquivos
#include <ctime>      // números aleatórios
#include <windows.h>  // configuração UTF-8 no console

#pragma region  📁 O Projeto
O projeto possui a seguinte organização de arquivos:

```text
JogoDaForca/
│
├── forca.cpp
├── palavras.txt
├── makefile
└── README.md
```
- **forca.cpp** → arquivo principal contendo toda a lógica do jogo  
- **palavras.txt** → banco de palavras utilizado pelo jogo  
- **makefile** → arquivo responsável por automatizar a compilação  
- **README.md** → documentação do projeto  


## 📄 Arquivo de palavras

O arquivo **palavras.txt** contém o conjunto de palavras que podem ser utilizadas pelo jogo.

Formato do arquivo:

```text
6
MARACUJA
ABACATE
LIMAO
UVA
MELAO
MELANCIA
```
A primeira linha indica **quantas palavras existem no arquivo**.  
As linhas seguintes representam as palavras disponíveis para o jogo.

Durante a execução, o programa lê esse arquivo utilizando a biblioteca:

```cpp
#include <fstream>
```

Isso permite que o programa carregue palavras externas sem precisar alterar o código-fonte.

## ⚙️ Compilação com Makefile

O projeto utiliza **Makefile** para automatizar o processo de compilação.

Normalmente, para compilar um programa em C++, precisaríamos executar um comando manualmente no terminal.  
Com o **Make**, basta executar um único comando, tornando o processo mais prático e organizado.


## 📦 Makefile utilizado

O arquivo **makefile** define como o projeto deve ser compilado.

```makefile
CXX = g++

CXXFLAGS = -std=c++11 -fexec-charset=UTF-8

forca: forca.cpp
	$(CXX) $(CXXFLAGS) forca.cpp -o forca
```

## 📖 Explicação dos elementos

| Elemento               | Função                                          |
| ---------------------- | ----------------------------------------------- |
| `CXX`                  | define qual compilador será utilizado           |
| `CXXFLAGS`             | define parâmetros adicionais de compilação      |
| `-std=c++11`           | habilita recursos da versão C++11               |
| `-fexec-charset=UTF-8` | permite exibição correta de acentos no terminal |


## ▶️ Como compilar

No terminal, execute:

```bash
make
```

Se o programa já estiver compilado e não houver alterações no código, o Make exibirá:

```text
make: 'forca' is up to date.
```

## 🚀 Como executar

Após a compilação:

```bash
./forca
```

O jogo será iniciado diretamente no terminal.


