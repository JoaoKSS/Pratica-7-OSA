#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <cstdint>

using namespace std;

struct NodeDisk {
    int id;                     // Identificador único do nó
    uintptr_t ptrAddress;       // Endereço real do nó (valor de 'this')
    int parentId;               // ID do nó pai (-1 se for raiz)
    uintptr_t parentAddress;    // Endereço real do nó pai (0 se raiz)
    int leaf;                   // 1 se nó é folha; 0 se interno
    int numKeys;                // Quantidade de chaves armazenadas
    int keys[100];              // Vetor fixo para as chaves
    int numChildren;            // Número de filhos
    int childrenIds[101];       // IDs dos nós filhos
    uintptr_t childrenAddresses[101]; // Endereços reais dos nós filhos
};

// Define o tipo para os pares (chave, endereço)
using KeyValue = pair<int, string>;

class BTreeNode {
public:
    int m;                // mínimo de chaves em nós não‑raiz (m = ordem)
    bool leaf;            // indica se é nó folha
    vector<KeyValue> keys;     // vetor de pares (chave, endereço)
    vector<BTreeNode*> children; // vetor de ponteiros para os filhos
    BTreeNode* parent;    // ponteiro para o nó pai

    // Construtor
    BTreeNode(int m, bool leaf = false, BTreeNode* parent = nullptr);

    // Métodos da árvore
    int find_key_index(int key);
    BTreeNode* insert_nonfull(int key, const string& address);
    void split_child(int i);
    void remove(int key, const string& binFilename);
    void remove_from_leaf(int idx);
    void remove_from_nonleaf(int idx, const string& binFilename);
    KeyValue get_predecessor(int idx);
    KeyValue get_successor(int idx);
    void fill(int idx);
    void borrow_from_prev(int idx);
    void borrow_from_next(int idx);
    void merge(int idx);
    void rotate_internal_left();
    void fix_deficiency_upwards();
    void print_node(int level = 0);
};

class BTree {
public:
    int m;            // mínimo de chaves em nós não‑raiz (m = ordem)
    BTreeNode* root;  // ponteiro para a raiz da árvore

    BTree(int ordem);
    pair<BTreeNode*, int> search(int key);
    void insert(int key, const string& address);
    void remove(int key);
    void print_tree();
    void saveToFile(const string& filename);
    static pair<bool, uintptr_t> searchInFile(const string& binFilename, int key);
    void convertBinToTxt(const string& binFilename, const string& txtFilename);
};

#endif 
