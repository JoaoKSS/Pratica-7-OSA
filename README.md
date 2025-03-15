<h2>Organização e Sistemas de Arquivos 2024/2</h2>

<h3>Sobre a Atividade</h3>

Este projeto contém uma implementação em C++ de uma Árvore B, incluindo as operações de inserção, remoção e busca. Além disso, a implementação possibilita salvar a estrutura da árvore em um arquivo binário e convertê-la para um arquivo de texto para facilitar a visualização. A ideia principal é auxiliar no entendimento dos conceitos das árvores B e permitir testes comparativos com simulações online, como as vistas no [site de visualização de Árvores B](https://www.cs.usfca.edu/~galles/visualization/BTree.html).

## Funcionalidades

- **Inserção:** Adiciona novos elementos na árvore, mantendo a propriedade balanceada da Árvore B.
- **Remoção:** Remove elementos da árvore, realizando os devidos ajustes para manter o balanceamento.
- **Busca:** Realiza a busca de chaves tanto na memória quanto diretamente no arquivo binário.
- **Armazenamento em Arquivo:** Salva a estrutura atual da árvore em um arquivo binário (`arvore_b.bin`) e converte este arquivo para um formato texto (`arvore_b.txt`), facilitando a visualização da estrutura.

## Estrutura do Projeto

- **main.cpp:** Função principal que realiza inserções, remoções e busca de chaves, além de salvar e converter a árvore para arquivos.
- **BTree.h / BTree.cpp:** Implementações das classes `BTree` e `BTreeNode`, contendo os métodos principais da Árvore B.
- **makefile:** Arquivo para compilação do projeto (compatível com Linux e Windows).
- **Instruções de Uso.txt:** Guia com a explicação do conceito geral do projeto e as instruções de configuração e execução.
- **.vscode/settings.json:** Configurações do Visual Studio Code (arquivo atualmente vazio).

## Configuração e Execução

1. **Configuração da Árvore:**
   - No arquivo `main.cpp`, ajuste a ordem da árvore conforme a necessidade. O comentário no código indica os diferentes graus possíveis (ex.: `BTree btree(1);`, `BTree btree(2);`, etc.).

2. **Compilação e Execução:**
   - Em sistemas Linux ou via terminal, basta executar o comando:
     ```
     make run
     ```
     No Windows, certifique-se de ter o compilador `g++` instalado e configure o ambiente conforme necessário.

3. **Visualização:**
   - Após a execução, o arquivo binário (`arvore_b.bin`) é gerado contendo a árvore e suas informações.
   - A conversão para texto é feita e salva em `arvore_b.txt`, permitindo uma visualização clara da estrutura da árvore, com informações como ponteiros, IDs e chaves.

## Exemplos de Uso

Durante a execução, o programa realiza os seguintes passos:
- Insere um conjunto de chaves específicas na árvore.
- Salva a árvore em um arquivo binário e gera um arquivo de texto para visualização.
- Remove as chaves na mesma ordem de inserção, mostrando o processo de reestruturação da árvore.
- Realiza buscas diretamente no arquivo binário para confirmar a presença ou ausência de chaves.

## Considerações

- O projeto foi desenvolvido com base em conceitos clássicos de árvores B e pode ser utilizado como base para estudos ou projetos mais robustos.
- A formatação e a indentação na saída (arquivo TXT) facilitam o entendimento da hierarquia e dos nós internos da árvore.
