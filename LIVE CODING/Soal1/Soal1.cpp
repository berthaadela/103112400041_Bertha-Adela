#include "Soal1.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
}

address alokasi(string nama) {
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->next = Nil;
    return nodeBaru;
}
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List) == true) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void deletebyName(linkedlist &List, string nama) {
    /* I.S. list mungkin kosong
       F.S. menghapus node dengan nama tertentu dari list */
    if (isEmpty(List) == true) {
        cout << "List kosong. Tidak ada yang dihapus." << endl;
    } else {
        address nodeBantu = List.first;
        address prevNode = Nil;
        bool found = false;

        while (nodeBantu != Nil && !found) {
            if (nodeBantu->isidata.nama == nama) {
                found = true;
            } else {
                prevNode = nodeBantu;
                nodeBantu = nodeBantu->next;
            }
        }

        if (found) {
            if (prevNode == Nil) { // Node yang dihapus adalah node pertama
                List.first = nodeBantu->next;
            } else {
                prevNode->next = nodeBantu->next;
            }
            dealokasi(nodeBantu);
            cout << "Node dengan nama " << nama << " telah dihapus." << endl;
        } else {
            cout << "Nama " << nama << " tidak ditemukan dalam list." << endl;
        }
    }
}

void hitungGenap(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. menghitung dan menampilkan jumlah nama dengan panjang karakter genap */
    if (isEmpty(List) == true) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        int count = 0;
        while (nodeBantu != Nil) {
            if (nodeBantu->isidata.nama.length() % 2 == 0) {
                count++;
            }
            nodeBantu = nodeBantu->next;
        }
        cout << "Jumlah nama dengan panjang karakter genap: " << count << endl;
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List) == true) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << nodeBantu->isidata.nama << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}