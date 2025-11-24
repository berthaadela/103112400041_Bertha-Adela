# <h1 align="center">Laporan Praktikum Modul 8 - QUEUE</h1>
<p align="center">Bertha Adela - 103112400041</p>

## Dasar Teori
Queue menerapkan FIFO (First In First Out) di mana elemen yang pertama kali masuk akan menjadi elemen pertama yang keluar [1]. Penerapan queue di dunia nyata salah satunya adalah antrian cetak pada printer [1]. Hal bertujuan untuk menciptakan keadilan dan keteraturan dalam urutan pelayanan [2].

Operasi yang sering digunakan pada queue adalah enqueue(), dequeue(), peek(), isFull(),
isEmpty() [3]. Operasi-operasi tersebut bertujuan untuk manipulasi data dan cek antrean [3].

Enqueue() → menambahkan data ke belakang antrean,
dequeue() → menghapus dari antrean depan,
peek() → melihat isi antrean paling depan,
isFull() → mengecek apakah antrean penuh, dan
isEmpty() → mengecek apakah antrean kosong.

## Guided 

### 1. Guided 1
#### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

#define Nil nullptr 

typedef struct node*address;
struct node {
    int dataAngka;
    address next;
};

struct queue{
    address head;
    address tail;
};

bool isEmpty(queue Q);
void createQueue(queue &Q);
address alokasi(int angka);
void dealokasi(address &node);

void enQueue(queue &Q, address nodeBaru);
void deQueue(queue &Q);
void updateQueue(queue &Q, int posisi);
void viewQueue(queue Q);
void searchData(queue Q, int data);

#endif
```
#### queue.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

bool isEmpty(queue Q){
    if(Q.head == Nil){
        return true;
    } else {
        return false;
    }
}

void createQueue(queue &Q){
    Q.head =  Q.tail = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void enQueue(queue &Q, address nodeBaru){
    if(isEmpty(Q) == true){
        Q.head = Q.tail = nodeBaru;
    } else {
        Q.tail->next = nodeBaru;
        Q.tail = nodeBaru;
    }
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q){
    if(isEmpty(Q)){
        cout << "Queue kosong!" << endl;
        return;
    }

    address nodeHapus = Q.head;

    int nilai = nodeHapus->dataAngka;

    Q.head = Q.head->next;
    if(Q.head == Nil){
        Q.tail = Nil;
    }

    nodeHapus->next = Nil;
    dealokasi(nodeHapus);

    cout << "Node " << nilai << " berhasil dihapus dari queue!" << endl;
}


void updateQueue(queue &Q, int posisi){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = Q.head;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(queue Q, int data){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam queue!" << endl;
            cout << endl;
        }
    }
}
```
#### main.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    queue Q;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createQueue(Q);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    enQueue(Q, nodeA);
    enQueue(Q, nodeB);
    enQueue(Q, nodeC);
    enQueue(Q, nodeD);
    enQueue(Q, nodeE);

    cout << "--- Queue setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "---Queue setelah deQueue 2 kali---" << endl;
    viewQueue(Q);
    cout << endl;

    updateQueue(Q, 2);
    updateQueue(Q, 1);
    updateQueue(Q, 4);
    cout << endl;

    cout << "---Queue setelah update---" << endl;
    viewQueue(Q);
    cout << endl;

    searchData(Q, 4);
    searchData(Q, 9);

    return 0;
}
```
Program ini dimulai dengan membuat antrian kosong, lalu memasukkan lima data bernilai 1 sampai 5 ke bagian belakang antrian. Setelah itu, isi antrian ditampilkan, kemudian dua data terdepan dihapus. Selanjutnya, program memberi kesempatan untuk mengubah nilai pada posisi tertentu, menampilkan kembali hasil perubahannya, dan terakhir mencari apakah suatu data ada di dalam antrian.


### 2. Guided 2
#### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 5

struct Queue {
    int info[MAX_QUEUE];
    int head;
    int tail;
    int count;
};

void createQueue(Queue &Q);

bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enQueue(Queue &Q, int x);
int deQueue(Queue &Q);
void printInfo(Queue Q);
#endif
```
#### queue.cpp
```C++
#include "queue.h" 
#include <iostream>

using namespace std;

void createQueue(Queue &Q) {
    Q.head = 0; 
    Q.tail = 0; 
    Q.count = 0;
}

bool isEmpty(Queue Q) {
    return Q.count == 0; //Kembalikan true jika jumlah elemen adalah 0
}

bool isFull(Queue Q) {
    return Q.count == MAX_QUEUE; // Kembalikan true jika jumlah elemen sama dengan maks
}

// Definisi prosedur untuk menambahkan elemen (enqueue)
void enQueue(Queue &Q, int x) {
    if (!isFull(Q)) { 
        Q.info[Q.tail] = x; // Masukkan data (x) ke posisi ekor (tail)
        // Pindahkan ekor secara circular (memutar)
        Q.tail = (Q.tail + 1) % MAX_QUEUE; 
        Q.count++; //Tambah jumlah elemen
    } else { 
        cout << "Antrean Penuh!" << endl;
    }
}

//Definisi fungsi untuk menghapus elemen (dequeue)
int deQueue(Queue &Q) {
    if (!isEmpty(Q)) { 
        int x = Q.info[Q.head]; // Ambil data di posisi  (head)
        Q.head = (Q.head + 1) % MAX_QUEUE;
        Q.count--; // Kurangi jumlah elemen
        return x;
    } else {
        cout << "Antrean Kosong!" << endl;
        return -1;
    }
}

// Definisi prosedur untuk menampilkan isi queue 
void printInfo(Queue Q) {
    cout << "Isi Queue: [ ";
    if (!isEmpty(Q)) { 
        int i = Q.head; // Mulai dari head
        int n = 0; //Penghitung elemen yang sudah dicetak
        while (n < Q.count) { // Ulangi sebanyak jumlah elemen
            cout << Q.info[i] << " "; // Cetak info
            i = (i + 1) % MAX_QUEUE; // Geser i secara circular
            n++; // Tambah penghitung
        }
    }
    cout << "]" << endl;
}
```
#### main.cpp
```C++
#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    Queue Q;
    createQueue(Q);
    printInfo(Q);

    cout << "\n Enqueue 3 Elemen" << endl;
    enQueue(Q, 5);
    printInfo(Q);
    enQueue(Q, 2);
    printInfo(Q);
    enQueue(Q, 7);
    printInfo(Q);

    cout << "\n Dequeue 1 Elemen" << endl;
    cout << "Elemen keluar:" << deQueue(Q) << endl;
    printInfo(Q);

    cout << "\n Enqueue 1 Elemen" << endl;
    enQueue(Q, 4);
    printInfo(Q);

    cout << "\nDequeue 2 Elemen" << endl;
    cout << "Elemen keluar: " << deQueue(Q) << endl;
    cout << "Elemen keluar: " << deQueue(Q) << endl;
    printInfo(Q);

    return 0;
    
}
```
Program ini menunjukkan cara kerja queue menggunakan array yang berputar. Data dimasukkan dari belakang menggunakan enQueue, dan data yang keluar selalu data yang paling depan menggunakan deQueue. Karena menggunakan sistem circular, posisi head dan tail akan berbalik ke awal jika sudah sampai ujung array. Setiap ada perubahan, isi antrean ditampilkan agar terlihat perpindahan datanya. 


## Unguided 

### 1. Buatlah ADT Queue menggunakan ARRAY sebagai berikut di dalam file "queue.h":
![Screenshot Soal Unguided 1_1](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan8_Modul8/soal1.png)
Buatlah implementasi ADT Queue pada file "queue.cpp" dengan menerapkan mekanisme
queue Alternatif 1 (head diam, tail bergerak).
![Screenshot Soal Unguided 1_2](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan8_Modul8/soal2.png)

#### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

const int MAX = 5;
typedef int infotype;

struct Queue {
    infotype info[MAX];
    int head, tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif

```
#### queue.cpp
```C++
#include <iostream>
#include "queue.h"
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return Q.tail == -1;
}

bool isFullQueue(Queue Q) {
    return Q.tail == MAX - 1;
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh, tidak bisa enqueue." << endl;
        return;
    }

    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail++;
    }

    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong, tidak bisa dequeue." << endl;
        return -1;
    }

    int x = Q.info[0];

    for (int i = 0; i < Q.tail; i++) {
        Q.info[i] = Q.info[i + 1];
    }

    Q.tail--;

    if (Q.tail == -1) {
        Q.head = -1;
    }

    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << "\t | ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
        return;
    }

    for (int i = 0; i <= Q.tail; i++) {
        cout << Q.info[i] << " ";
    }
    cout << endl;
}

```
#### main.cpp
```C++
#include <iostream>
using namespace std;
#include "queue.h"

int main() {
    cout << "Hello World!" << endl;
    Queue Q;
    createQueue(Q);
    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;
    printInfo(Q);
    enqueue(Q,5);
    printInfo(Q);
    enqueue(Q,2);
    printInfo(Q);
    enqueue(Q,7);
    printInfo(Q);
    dequeue(Q);
    printInfo(Q);
    dequeue(Q);
    printInfo(Q);
    enqueue(Q,4);
    printInfo(Q);
    dequeue(Q);
    printInfo(Q);
    dequeue(Q);
    printInfo(Q);
    return 0;
}
```
### Output Unguided 1 :
![Screenshot Output Unguided 1_1](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan8_Modul8/output1.png)

Program di atas menerapkan mekanisme queue Alternatif 1 dimana head diam namun tail bergerak.

### 2. Buatlah implementasi ADT Queue pada file "queue.cpp" dengan menerapkan mekanisme queue Alternatif 2 (head bergerak, tail bergerak).

#### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

const int MAX = 5;
typedef int infotype;

struct Queue {
    infotype info[MAX];
    int head, tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif

```
#### queue.cpp
```C++
#include <iostream>
#include "Queue.h"
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1);
}

bool isFullQueue(Queue Q) {
    return ((Q.tail + 1) % MAX == Q.head);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh, tidak bisa enqueue." << endl;
        return;
    }

    if (isEmptyQueue(Q)) {
        Q.head = Q.tail = 0;
    } else {
        Q.tail = (Q.tail + 1) % MAX;
    }

    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong, tidak bisa dequeue." << endl;
        return -1;
    }

    infotype x = Q.info[Q.head];

    if (Q.head == Q.tail) {
        Q.head = Q.tail = -1;
    } else {
        Q.head = (Q.head + 1) % MAX;
    }

    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << "\t | ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
        return;
    }

    int i = Q.head;
    while (true) {
        cout << Q.info[i] << " ";
        if (i == Q.tail) break;
        i = (i + 1) % MAX;
    }
    cout << endl;
}

```
#### main.cpp
```C++
#include <iostream>
using namespace std;
#include "queue.h"

int main() {
    cout << "Hello World!" << endl;
    Queue Q;
    createQueue(Q);
    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;
    printInfo(Q);
    enqueue(Q,5);
    printInfo(Q);
    enqueue(Q,2);
    printInfo(Q);
    enqueue(Q,7);
    printInfo(Q);
    dequeue(Q);
    printInfo(Q);
    dequeue(Q);
    printInfo(Q);
    enqueue(Q,4);
    printInfo(Q);
    dequeue(Q);
    printInfo(Q);
    dequeue(Q);
    printInfo(Q);
    return 0;
}
```

### Output Unguided 2 :
![Screenshot Output Unguided 2_1](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan8_Modul8/output2.png)

Program di atas menerapkan mekanisme queue Alternatif 2 dimana head dan tail bergerak.

### 3.  Buatlah implementasi ADT Queue pada file "queue.cpp" dengan menerapkan mekanisme queue Alternatif 3 (head dan tail berputar).

#### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

const int MAX = 5;
typedef int infotype;

struct Queue {
    infotype info[MAX];
    int head, tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif

```
#### queue.cpp
```C++
#include <iostream>
#include "queue.h"
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1);
}

bool isFullQueue(Queue Q) {
    return ((Q.tail + 1) % MAX == Q.head);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh, tidak bisa enqueue." << endl;
        return;
    }

    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } 
    else {
        Q.tail = (Q.tail + 1) % MAX;
    }

    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong, tidak bisa dequeue." << endl;
        return -1;
    }

    infotype x = Q.info[Q.head];

    if (Q.head == Q.tail) {
        Q.head = -1;
        Q.tail = -1;
    }
    else {
        Q.head = (Q.head + 1) % MAX;
    }

    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << "\t | ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
        return;
    }

    int i = Q.head;
    while (true) {
        cout << Q.info[i] << " ";
        if (i == Q.tail) break;
        i = (i + 1) % MAX;
    }

    cout << endl;
}

```
#### main.cpp
```C++
#include <iostream>
using namespace std;
#include "queue.h"

int main() {
    cout << "Hello World!" << endl;
    Queue Q;
    createQueue(Q);
    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;
    printInfo(Q);
    enqueue(Q,5);
    printInfo(Q);
    enqueue(Q,2);
    printInfo(Q);
    enqueue(Q,7);
    printInfo(Q);
    dequeue(Q);
    printInfo(Q);
    dequeue(Q);
    printInfo(Q);
    enqueue(Q,4);
    printInfo(Q);
    dequeue(Q);
    printInfo(Q);
    dequeue(Q);
    printInfo(Q);
    return 0;
}
```
### Output Unguided 3 :
![Screenshot Output Unguided 3_1](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan8_Modul8/output3.png)

Program di atas meneraokan mekanisme queue Alternatif 3 dimana head dan tail berputar.

## Kesimpulan
Queue adalah struktur data yang bekerja dengan prinsip FIFO, sehingga data yang masuk lebih dulu akan keluar lebih dulu. Struktur ini banyak dipakai pada sistem yang membutuhkan urutan layanan yang jelas, seperti antrian printer. Dengan operasi dasar seperti enqueue, dequeue, peek, isFull, dan isEmpty, queue dapat mengatur data secara sederhana namun tetap tertib dan efisien.

## Referensi
[1] Trijayanti, A., Huda, A. L., Musafa, M. F. A., & Nurcholis, M. A. (2023). Implementasi struktur data antrian queue dalam sistem penjadwalan proses. Jurnal Publikasi Teknik Informatika, 3(4). https://journalcenter.org/index.php/jupti/article/view/4170
<br/> [2] Sahid, S., Sahnadi, F., Ardiansyah, M., Fardiansyah, T., & Alfiansyah, A. (2024). Implementasi queue berbasis linked list pada aplikasi web manajemen antrian. Jurnal Ilmu Komputer dan Informatika, 8(1). https://jurnal.globalscients.com/index.php/jiki/article/view/709
<br/> [3] Sarevska, M. (2024). Data structures comparison for element deletion including stack and queue. WSEAS Communications, 3(5), 104-115. https://wseas.com/journals/communications/2024/a305104-015(2024).pdf