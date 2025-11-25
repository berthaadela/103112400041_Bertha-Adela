#ifndef QUEUEPENGIRIMAN_H
#define QUEUEPENGIRIMAN_H
#include <iostream>
using namespace std;
struct Paket {
    string KodeResi;
    string NamaPengirim;
    int BeratBarang;
    string Tujuan;
};

const int MAX = 5;
struct QueueEkspedisi {
    Paket data[MAX];
    int Head;
    int Tail;
};

bool isEmpty(QueueEkspedisi &Q);
bool isFull(QueueEkspedisi &Q);
void createQueue(QueueEkspedisi &Q);
void enQueue(QueueEkspedisi &Q, Paket pkt);
void deQueue(QueueEkspedisi &Q, Paket &pkt);
void viewQueue(QueueEkspedisi Q);
void TotalBiayaPengiriman(QueueEkspedisi Q);
#endif