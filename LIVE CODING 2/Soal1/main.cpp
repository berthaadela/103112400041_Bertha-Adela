#include <iostream>
#include "bst.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    root = insertNode(root, 60);
    insertNode(root, 50);
    insertNode(root, 47);
    insertNode(root, 56);
    insertNode(root, 52);
    insertNode(root, 65);
    insertNode(root, 70);
    insertNode(root, 68);
    insertNode(root, 81);
    cout << "=== Transversal InOrder ===" << endl;
    inOrder(root);
    cout << endl;
    cout << "Node MostLeft: " <<
    mostLeft(root) << endl;
    cout << "Node MostRight: " <<
    mostRight(root) << endl;
    searchByBeratBadan(root, 70);

    return 0;
}