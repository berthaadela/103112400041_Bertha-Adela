#ifndef SOAL2_H
#define SOAL2_H

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void insertLast(Node*& head, Node*& tail, int value);
void deleteLast(Node*& head, Node*& tail);
void viewForward(Node* head);
void reverseList(Node*& head, Node*& tail);

#endif