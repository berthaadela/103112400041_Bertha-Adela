#include "Soal2.h"
#include <iostream>
using namespace std;

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int menu, nilai;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert Last\n";
        cout << "2. Delete Last\n";
        cout << "3. View Forward\n";
        cout << "4. Reverse & View\n";
        cout << "0. Exit\n";
        cout << "Pilih: ";
        cin >> menu;

        switch(menu) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                insertLast(head, tail, nilai);
                break;
            case 2:
                deleteLast(head, tail);
                break;
            case 3:
                viewForward(head);
                break;
            case 4:
                reverseList(head, tail);
                viewForward(head);
                break;
        }

    } while(menu != 0);

    return 0;
}