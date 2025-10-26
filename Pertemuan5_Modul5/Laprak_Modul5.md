# <h1 align="center">Laporan Praktikum Modul 5 - SINGLY LINKED LIST (Bagian Kedua)</h1>
<p align="center">Bertha Adela - 103112400041</p>

## Dasar Teori
Searching adalah proses pencarian data pada suatu array atau list [1]. Searching juga merupakan syarat untuk dapat menyisipkan data tertentu di tengah suatu array atau list.

### A. Binary Search <br/>
Binary search adalah metode pencarian data yang dibagi menjadi tengah, kiri, dan kanan. Jika data yang dicari lebih besar dari data yang ditengah, maka program akan mengecek sebelah kanan. Sebaliknya, jika data yang dicari lebih kecil dari data yang ditengah, maka program akan mengecek sebelah kiri. Pencarian berlanjut hanya pada separuh array atau list yang terpilih [2]. Hal ini bertujuan untuk mengurangi jumlah elemen yang perlu diperiksa [2]. Metode pencarian ini hanya bisa dilakukan jika data pada array atau list terurut membesar (ascending). 

### B. Linear Search <br/>
Linear search atau sequential search adalah metode pencarian data dengan mengecek elemen satu per satu dari awal hingga akhir suatu array atau list [1]. Metode pencarian ini cocok untuk data yang tidak terurut [1]. 

## Guided 

### 1. Guided 1

#### Header
```C++
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include <iostream>
using namespace std;

struct buah {
    string nama;
    int jumlah;
    float harga;
};

typedef buah dataBuah;
typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct

struct node { // node untuk isi dari linked listnya, isi setiap node adalah data & pointer
    dataBuah isidata;
    address next;
};

struct linkedlist{ // ini linked listnya
    address first;
};

// semua function & prosedur yang akan dipakai
// Materi modul 4

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5 (part 1 - update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

#endif
```
#### Implementasi Fungsi
```C++

#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}
//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}
```
#### Program Utama
```C++
#include <iostream>

#include "listBuah.h"
using namespace std;

int main() {
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    //A - C - D - B - E

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    return 0;

}
```
Program ini adalah latihan create, insert, delete, traverse, count, serta update node menggunakan pointer.

### 2. Guided 2

#### Binary
```C++
#include <iostream>
using namespace std;
// Definisi node
struct Node { // Memiliki 2 bagian yaitu data dan pointer
    int data;
    Node* next;
};

// Fungsi untuk pencarian linear
Node* binarySearch(Node* head, int key) { // Node* ini pointer (kembalian)
    // head ini pointer ke node pertama // key ini data yang dicari
    int size = 0; // var size diisi 0

    for(Node* current = head; current; current = current->next) size++; 
    // current adalah pointer yang digunakan untuk menyusuri linked list
    Node *start = head;// start adalah pointer yang menunjukkan ke node pertama
    Node *end = nullptr; //end adalah pointer yang menunjuk ke node terakhir
    // (null karena linked list tidak memiliki node terakhir yang pasti)

    while (size > 0){ // selama masih ada elemen > 0
        int mid = size / 2; // bagi size jadi 2
        Node *midNode = start; // midNode adalah pointer yang menunjuk ke node tengah
        for (int i = 0; i < mid; ++i) midNode =
        midNode->next; //pindah ke node tengah

        if (midNode->data == key) return midNode; //jika ditemukan data yang cocok, kembalikan node
        if (midNode->data < key) {//Jika data midNode lebih kecil dari key, kita cari di bagian kanan
            start = midNode->next; //Mulai pencarian dari node setelah midNode
        }
        else { // jika data midNode lebih besar dari key, kita cari di bagian kiri
            end = midNode; // Batasi pencarian ke bagian kiri
        }
        size -= mid; // kita mengurangi size dengan mid
    }
    return nullptr; // Jika key tidak ditemukan

}

// Prosedur untuk menambahkan node
void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};

    if (!head) { // jika head null, head diisi node baru
        head = newNode;
    } else {
        Node* temp = head; // mulai dari head
        while (temp->next) { 
            temp = temp->next; // pindah ke node berikutnya sampai ketemu di node terakhir
        }
        temp->next = newNode;
    }
}

int main() {
    Node* head = nullptr; // inisiasi head list masih kosong

    append(head, 10); //menambah node
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    Node* result = binarySearch(head, 40); // result ini pointer untuk mencari data 20

    cout << (result ? "Found" : "NotFound") << endl;

    return 0;
}

```
#### Linear
```C++
#include <iostream>
using namespace std;
// Definisi node
struct Node { // Memiliki 2 bagian yaitu data dan pointer
    int data;
    Node* next;
};

// Fungsi untuk pencarian linear
Node* linearSearch(Node* head, int key) {
    Node* current = head;

    while (current != nullptr) {// selama masih ada node
        if (current->data == key) { // jika data ketemu
            return current;  // pindah ke node
        }
        current = current->next;
    }

    return nullptr;  // tidak ditemukan
}

// Prosedur untuk menambahkan node
void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};

    if (!head) { // jika head null, head diisi node baru
        head = newNode;
    } else {
        Node* temp = head; // mulai dari head
        while (temp->next) { 
            temp = temp->next; // pindah ke node berikutnya sampai ketemu di node terakhir
        }
        temp->next = newNode;
    }
}

int main() {
    Node* head = nullptr; // inisiasi head list masih kosong

    append(head, 10); //menambah node
    append(head, 20);
    append(head, 30);

    Node* result = linearSearch(head, 20); // result ini pointer untuk mencari data 20

    cout << (result ? "Found" : "NotFound") << endl;

    return 0;
}

```
Program-program pada guided 2 merupakan contoh penggunaan binary search dan linear search untuk melakukan pencarian data pada linked list.

## Unguided 

### 1. Implementasikan program C++ yang menggunakan algoritma Binary Search pada Linked List untuk mencari elemen tertentu. Program harus mampu:
1. Membuat linked list dengan menambahkan node di akhir<br/>
2. Mengimplementasikan binary search pada linked list<br/>
3. Menampilkan detail proses pencarian dan hasil akhir<br/>
#### Petunjuk Tugas 1:
• Gunakan struktur Node dengan data integer dan pointer next<br/>
• Implementasikan fungsi append() untuk menambah node<br/>
• Implementasikan fungsi binarySearch() yang mengembalikan pointer ke node yang ditemukan<br/>
• Data dalam linked list harus terurut (ascending) untuk binary search bekerja dengan benar<br/>
• Tampilkan langkah-langkah pencarian dan posisi tengah setiap iterasi<br/>
• Program utama harus membuat linked list dengan minimal 5 elemen dan melakukan pencarian<br/>
#### Ekspetasi Output:
![Screenshot Soal Unguided 1_1](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan5_Modul5/EkspektasiOutput1.png)

```C++
#include <iostream>
using namespace std;
// Definisi node
struct Node { // Memiliki 2 bagian yaitu data dan pointer
    int data;
    Node* next;
};

// Fungsi untuk pencarian linear
Node* binarySearch(Node* head, int key) {
    cout << "Proses pencarian: ";

    int size = 0;
    for (Node* current = head; current; current = current->next) size++;

    Node* start = head;
    int hitung = 0;

    while (start && size > 0) {
        int mid = size / 2;
        Node* midNode = start;

        // Pindah ke node tengah
        for (int i = 0; i < mid; ++i) {
            if (midNode->next)
                midNode = midNode->next;
            else
                break;
        }

        hitung++;
        cout << endl << "Iterasi " << hitung << ": Mid = " << midNode->data << " (indeks tengah)";

        if (midNode->data == key) {
            cout << " - DITEMUKAN!" << endl;
            return midNode;
        }
        else if (midNode->data < key) { // cari di kanan
            start = midNode->next;
            size -= (mid + 1); // kurangi elemen kiri + mid
        }
        else { // midNode->data > key, cari di kiri
            // tetap start, tapi size hanya sampai mid
            size = mid;
        }
    }

    cout << endl << "Tidak ada elemen tersisa" << endl;
    return nullptr;
}


// Prosedur untuk menambahkan node
void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};

    if (!head) { // jika head null, head diisi node baru
        head = newNode;
    } else {
        Node* temp = head; // mulai dari head
        while (temp->next) { 
            temp = temp->next; // pindah ke node berikutnya sampai ketemu di node terakhir
        }
        temp->next = newNode;
    }
}

// Fungsi untuk menampilkan linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) cout << " -> "; // untuk tampilan lebih rapi
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr; // inisiasi head list masih kosong
    int input;

    append(head, 10); //menambah node
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);

    cout << "Linked list yang dibuat: ";
    printList(head);
    Node* result;

    // mencari nilai pertama
    cout << "Mencari nilai: ";
    cin >> input;
    cout << endl;
    result = binarySearch(head, input);
    cout << endl;

    cout << "Hasil: Nilai " << input << " "<< (result ? "DITEMUKAN" : "TIDAK DITEMUKAN") << " pada linked list" << endl;
    if (result) {
        cout << "Alamat Node: " << result << endl;
        cout << "Data Node: " << result->data << endl;
        if (result->next != nullptr) {
            cout << "Node Berikutnya: " << result->next->data << endl;
        } else {
            cout << "Node ini adalah node terakhir (tidak punya node berikutnya)" << endl;
        }
    }

    // mencari nilai kedua
    cout << "Mencari nilai: ";
    cin >> input;
    cout << endl;
    result = binarySearch(head, input);
    cout << endl;

    cout << "Hasil: Nilai " << input << " "<< (result ? "DITEMUKAN" : "TIDAK DITEMUKAN") << " pada linked list" << endl;
    if (result) {
        cout << "Alamat Node: " << result << endl;
        cout << "Data Node: " << result->data << endl;
        if (result->next != nullptr) {
            cout << "Node Berikutnya: " << result->next->data << endl;
        } else {
            cout << "Node ini adalah node terakhir (tidak punya node berikutnya)" << endl;
        }
    }
    
    return 0;
}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan5_Modul5/OutputUnguided1.png)

Program tersebut menampilkan linked list, mencari data di dalam linked list, menjelaskan langkah-langkah proses pencariannya dengan menggunakan metode pencarian Binary Search. Jika data ditemukan, program memberi keterangan alamat node, data node, dan node berikutnya.

### 2. Implementasikan program C++ yang menggunakan algoritma Linear Search pada Linked List untuk mencari elemen tertentu. Program harus mampu:
1. Membuat linked list dengan menambahkan node di akhir<br/>
2. Mengimplementasikan linear search pada linked list<br/>
3. Menampilkan detail proses pencarian dan hasil akhir<br/>
#### Petunjuk Tugas 2:
• Gunakan struktur Node dengan data integer dan pointer next<br/>
• Implementasikan fungsi append() untuk menambah node<br/>
• Implementasikan fungsi linearSearch() yang mengembalikan pointer ke node yang ditemukan<br/>
• Data dalam linked list tidak perlu terurut untuk linear search<br/>
• Tampilkan setiap langkah pencarian dan node yang sedang diperiksa<br/>
• Program utama harus membuat linked list dengan minimal 3 elemen dan melakukan pencarian<br/>
#### Ekspektasi Output:
![Screenshot Soal Unguided 2_1](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan5_Modul5/EkspektasiOutput2.png)

```C++
#include <iostream>
using namespace std;
// Definisi node
struct Node { // Memiliki 2 bagian yaitu data dan pointer
    int data;
    Node* next;
};

// Fungsi untuk pencarian linear
Node* linearSearch(Node* head, int key) {
    Node* current = head;
    int iterasi = 0;
    cout << "Proses Pencarian: " << endl;

    while (current != nullptr) {// selama masih ada node
        iterasi=iterasi+1;
        if (current->data == key) { // jika data ketemu
            cout << "Memeriksa Node " << iterasi << ": " << current->data << " (SAMA) - DITEMUKAN!" << endl;
            return current;  // pindah ke node
        }
        cout << "Memeriksa Node " << iterasi << ": " << current->data << " (tidak sama)" << endl;
        current = current->next;
    }
    cout << "Tidak ada node lagi yang tersisa";
    return nullptr;  // tidak ditemukan
}

// Prosedur untuk menambahkan node
void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};

    if (!head) { // jika head null, head diisi node baru
        head = newNode;
    } else {
        Node* temp = head; // mulai dari head
        while (temp->next) { 
            temp = temp->next; // pindah ke node berikutnya sampai ketemu di node terakhir
        }
        temp->next = newNode;
    }
}

// Fungsi untuk menampilkan linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) cout << " -> "; // untuk tampilan lebih rapi
        current = current->next;
    }
    cout << endl;
}

int main() {

    Node* head = nullptr; // inisiasi head list masih kosong
    int input;

    append(head, 10); //menambah node
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    cout << "Linked list yang dibuat: ";
    printList(head);
    Node* result;

    // mencari nilai pertama
    cout << "Mencari nilai: ";
    cin >> input;
    cout << endl;
    result = linearSearch(head, input);
    cout << endl;

    cout << "Hasil: Nilai " << input << " "<< (result ? "DITEMUKAN" : "TIDAK DITEMUKAN") << " pada linked list" << endl;
    if (result) {
        cout << "Alamat Node: " << result << endl;
        cout << "Data Node: " << result->data << endl;
        if (result->next != nullptr) {
            cout << "Node Berikutnya: " << result->next->data << endl;
        } else {
            cout << "Node ini adalah node terakhir (tidak punya node berikutnya)" << endl;
        }
    }

    // mencari nilai kedua
    cout << "Mencari nilai: ";
    cin >> input;
    cout << endl;
    result = linearSearch(head, input);
    cout << endl;

    cout << "Hasil: Nilai " << input << " "<< (result ? "DITEMUKAN" : "TIDAK DITEMUKAN") << " pada linked list" << endl;
    if (result) {
        cout << "Alamat Node: " << result << endl;
        cout << "Data Node: " << result->data << endl;
        if (result->next != nullptr) {
            cout << "Node Berikutnya: " << result->next->data << endl;
        } else {
            cout << "Node ini adalah node terakhir (tidak punya node berikutnya)" << endl;
        }
    }

    
    return 0;
}

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan5_Modul5/OutputUnguided2.png)

Program tersebut menampilkan linked list, mencari data di dalam linked list, menjelaskan langkah-langkah proses pencariannya dengan menggunakan metode pencarian Linear Search. Jika data ditemukan, program memberi keterangan alamat node, data node, dan node berikutnya.


## Kesimpulan
Running time pada metode pencarian Binary Search lebih cepat dibandingkan Linear Search. Hal ini dikarenakan Linear Search akan mengecek satu per satu dari awal hingga akhir suatu array atau list. Sementara itu, Binary Search akan menyeleksi pencarian yang lebih efisien dengan cara membandingkan elemen yang dicari dengan elemen yang berada di tengah suatu array atau list.

## Referensi
[1] Kurhade, A., & Takawale, N. N. (2024). Comparative study of searching algorithm: Linear search and binary search. International Journal of Advanced Research in Computer and Communication Engineering, 13(5). https://doi.org/10.17148/IJARCCE.2024.13506 <br/>
[2] Putri, R. N. M. (2025). Implementasi dan analisis algoritma binary search. Maliki Interdisciplinary Journal, 3(2), 289-294. https://urj.uin-malang.ac.id/index.php/mij/article/view/14003