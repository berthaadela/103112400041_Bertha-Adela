#include "QueuePengiriman.h"

#include <iostream>
using namespace std;

int main() {
    QueueEkspedisi Q;
    createQueue(Q);

    cout << "--- Komaniya Ekspress ---" << endl;
    cout << "1. Input Data Paket" << endl;
    cout << "2. Hapus Data Paket" << endl;
    cout << "3. Tampilkan Data Paket" << endl;
    cout << "Pilihan anda: ..." << endl;

    enQueue(Q, {"123456", "Hutao", 14, "Sumeru"});
    enQueue(Q, {"234567", "Ayaka", 10, "Fontaine"});
    enQueue(Q, {"345678", "Bennet", 7, "Natlan"});
    enQueue(Q, {"456789", "Furina", 16, "Liyue"});
    enQueue(Q, {"567890", "Nefer", 6, "Inazuma"});

    viewQueue(Q);
    cout << endl;
    deQueue(Q, Q.data[Q.Head]);
    viewQueue(Q);
    TotalBiayaPengiriman(Q);

}