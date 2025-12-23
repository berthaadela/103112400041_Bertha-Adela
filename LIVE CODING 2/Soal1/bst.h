#ifndef BST_H

#define BST_H
#include <iostream>

using namespace std;
typedef int infotype;
typedef struct Node*address;
struct Node{
    infotype info;
    address left;
    address right;
};
bool isEmpty(address root);
void createTree(address &root);
address newNode(infotype x);
address insertNode(address root, infotype x);
void searchByBeratBadan(address root, infotype x);
address mostLeft(address root);
address mostRight(address root);
void inOrder(address root);

#endif