#include "Soal2.h"
#include <iostream>
using namespace std;

void insertLast(Node*& head, Node*& tail, int value) {
    Node* baru = new Node{value, nullptr, nullptr};
    if (!head) {
        head = tail = baru;
    } else {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
}

void deleteLast(Node*& head, Node*& tail) {
    if (!head) return;
    if (head == tail) {
        delete head;
        head = tail = nullptr;
        return;
    }
    Node* hapus = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete hapus;
}

void viewForward(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reverseList(Node*& head, Node*& tail) {
    Node* curr = head;
    Node* temp = nullptr;

    while (curr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    temp = head;
    head = tail;
    tail = temp;
}
