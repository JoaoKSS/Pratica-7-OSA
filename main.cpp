#include "BTree.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;
// site usado para teste da árvore B: https://www.cs.usfca.edu/~galles/visualization/BTree.html

int main() {
    // Arquivos binário para salvar a arvore e seus endereços 
    string binFilename = "arvore_b.bin";
    // Arquivo txt para visualização da árvore no arquivo binário
    string txtFilename = "arvore_b.txt";

    // Define a ordem da Árvore B (exemplo: ordem = 1, 2 ou 3)
    // usando a formula 2 * ordem = grau máximo da árvore
    // usando a formula ordem = grau mínimo da árvore
    /*------------------------------------------------------------------------------------------*/
    // BTree btree(1); /* Equivale a grau máximo 3 no programa de simulação "B-Trees"*/
    BTree btree(2); /* Equivale a grau máximo 5 no programa de simulação "B-Trees"*/
    // BTree btree(3); /* Equivale a grau máximo 7 no programa de simulação "B-Trees"*/
    /*-----------------------------------------------------------------------------------------*/

    // Vetor de elementos a serem inseridos na árvore
    vector<int> elementos = {15, 3, 8, 23, 1, 9, 14, 18, 10, 20, 5, 6, 12, 30, 2, 4, 7, 11, 13, 16, 19, 21, 26, 28, 27, 29, 17, 22, 25, 24, 31, 35, 33, 36, 32, 34, 38, 37};
    // vector<int> elementos = {20, 40, 10, 30, 15, 35, 7, 26, 18, 22, 5, 42, 13, 46, 27, 8, 32, 38, 24, 45, 25};
    // Cabeçalho para a inserção
     cout << "\n*************************************************\n";
     cout << "*        INICIANDO A INSERÇÃO DA ÁRVORE         *\n";
     cout << "*************************************************\n" << endl;

    for (int chave : elementos) {
        cout << "Inserindo " << chave << "..." << endl;
        btree.insert(chave, "End_" + to_string(chave));
        btree.print_tree();
        cout << "----------------------------------------" << endl;
    }

    // Salva a árvore em arquivo
    btree.saveToFile(binFilename);

    // Coverte o arquivo binário para um arquivo txt para visualização
    btree.convertBinToTxt(binFilename, txtFilename);

    // Vetor de elementos a serem removidos da árvore
    vector<int> elementos2 = {15, 3, 8, 23, 1, 9, 14, 18, 10, 20, 5, 6, 12, 30, 2, 4, 7, 11, 13, 16, 19, 21, 26, 28, 27, 29, 17, 22, 25, 24, 31, 35, 33, 36, 32, 34, 38, 37};
    // vector<int> elementos2 = {15, 3, 8, 23, 1, 9, 14, 18, 10, 20, 6, 12, 30, 2, 4, 7, 11, 13, 16, 19, 21, 26, 28, 27, 29, 17, 22, 25, 24, 31, 35};
    // Cabeçalho para a remoção
     cout << "\n*************************************************\n";
     cout << "*         INICIANDO A REMOÇÃO DA ÁRVORE         *\n";
     cout << "*************************************************\n" << endl;
    // Removendo na mesma ordem das inserções
    for (int chave : elementos2) {
        cout << "Removendo chave " << chave << "..." << endl;
        btree.remove(chave);
        btree.print_tree();
        cout << "----------------------------------------" << endl;
    }

    // Nova função para busca em arquivo binário em vez de memoria
    cout << "\n*************************************************\n";
    cout << "*         INICIANDO A BUSCA NO ARQUIVO          *\n";
    cout << "*************************************************\n" << endl;
    vector<int> chavesBusca = {15, 3, 8, 23, 1, 9, 14, 18, 10, 20, 5, 6, 12, 30, 2, 4, 7, 11, 13, 16, 19, 21, 26, 28, 27, 29, 17, 22, 25, 24, 31, 35, 33, 36, 32, 34, 38, 37};
    // vector<int> chavesBusca = {20, 40, 10, 30, 15, 35, 7, 26, 18, 22, 5, 42, 13, 46, 27, 8, 32, 38, 24, 45, 25};
    for (int chave : chavesBusca) {
        auto resultado = btree.searchInFile(binFilename, chave);
        if (resultado.first) {
            cout << "Chave " << dec << chave << " encontrada no nó com endereço: 0x"
                << hex << resultado.second << dec << endl;
        } else {
            cout << "Chave " << dec << chave << " não encontrada na árvore." << endl;
        }
        cout << "------------------------------------------------------" << endl;
    }

    return 0;
}
