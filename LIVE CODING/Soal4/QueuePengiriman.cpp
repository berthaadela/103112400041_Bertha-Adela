#include "QueuePengiriman.h"
#include <iostream>
using namespace std;
bool isEmpty(QueueEkspedisi &Q) {
    return Q.Head == -1 && Q.Tail == -1;
}
bool isFull(QueueEkspedisi &Q) {
    return Q.Tail == MAX - 1;
}
void createQueue(QueueEkspedisi &Q) {
    Q.Head = -1;
    Q.Tail = -1;
}
void enQueue(QueueEkspedisi &Q, Paket pkt) {
    if (isFull(Q)) {
        cout << "Queue penuh, tidak bisa menambahkan paket baru." << endl;
    } else {
        if (isEmpty(Q)) {
            Q.Head = 0;
        }
        Q.Tail++;
        Q.data[Q.Tail] = pkt;
    }
}

void deQueue(QueueEkspedisi &Q, Paket &pkt) {
    if (isEmpty(Q)) {
        cout << "Queue kosong, tidak ada paket untuk dihapus." << endl;
    } else {
        pkt = Q.data[Q.Head];
        if (Q.Head == Q.Tail) {
            Q.Head = -1;
            Q.Tail = -1;
        } else {
            Q.Head++;
        }
    }
}
void viewQueue(QueueEkspedisi Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong." << endl;
    } else {
        cout << "Isi Queue Ekspedisi:" << endl;
        for (int i = Q.Head; i <= Q.Tail; i++) {
            cout << "Paket " << (i - Q.Head + 1) << ": "
                 << "Kode Resi: " << Q.data[i].KodeResi << ", "
                 << "Nama Pengirim: " << Q.data[i].NamaPengirim << ", "
                 << "Berat Barang: " << Q.data[i].BeratBarang << "kg, "
                 << "Tujuan: " << Q.data[i].Tujuan << endl;
        }
    }
}

void TotalBiayaPengiriman(QueueEkspedisi Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong." << endl;
    } else {
        int totalBiaya = 0;
        for (int i = Q.Head; i <= Q.Tail; i++) {
            int biayaPerKg;
            biayaPerKg = 8250;
            totalBiaya += Q.data[i].BeratBarang * biayaPerKg;
        }
        cout << "Total Biaya Pengiriman: Rp " << totalBiaya << endl;
    }
}