#include "Soal1.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    int pilihan;
    string nama;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;
    cout << "Menu: 1 Insert, 2 Delete, 3 View, 4 Hitung Genap, 0 exit" << endl;
    cin >> pilihan;
    while (pilihan != 999){
        cin >> pilihan;
        switch (pilihan) {
        case 1: cout << "Masukkan nama: ";
                cin >> nama;
                insertLast(List, alokasi(nama));
                break;
        case 2: cout << "Masukkan nama untuk delete: " << endl;
                cin >> nama;
                deletebyName(List, nama);
                break;
        case 3:
                printList(List);
                break;
        case 4:
                hitungGenap(List);
                break;
        case 0:
                return 0;
        default:
                cout << "Pilihan tidak valid!" << endl;
        }
    };
}