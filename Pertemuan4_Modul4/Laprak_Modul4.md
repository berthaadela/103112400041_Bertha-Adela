# <h1 align="center">Laporan Praktikum Modul 4 - SINGLY LINKED LIST (BAGIAN PERTAМА)</h1>
<p align="center">Bertha Adela - 103112400041</p>

## Dasar Teori
Struktur data adalah cara untuk menyimpan, mengatur, dan mengelola data dan dapat memengaruhi performa program dalam hal kecepatan, efisiensi memori, dan kemudahan implementasi [1].Pada struktur data, sering digunakan Array dan Linked List[2]. Berikut adalah beberapa perbedaannya:<br/>
- Array lebih efisien dalam pencarian data sedangkan Linked List lebih fleksibel dalam penambahan dan penghapusan data [2].
- Waktu akses Linked List lebih lambat daripada Array [3].
- Memori Linked List dialokasikan secara dinamis sedangkan memori array dialokasikan secara statis [3].
<br/>
Berikut adalah fungsi-fungsi yang digunakan di Modul 4 pada guided dan unguided untuk membuat single linked list.<br/>
<br/>Fungsi___________________ Tujuan______________________________
<br/>`createList`_____________ Inisialisasi list kosong____________
<br/>`isEmpty`________________ Mengecek apakah list kosong_________
<br/>`alokasi`________________ Membuat node baru___________________
<br/>`dealokasi`______________ Menghapus node______________________
<br/>`insertFirst`____________ Menambah node di awal_______________
<br/>`insertLast`_____________ Menambah node di akhir______________
<br/>`insertAfter`____________ Menambah node di tengah_____________
<br/>`delFirst`_______________ Menghapus node pertama______________
<br/>`delLast`________________ Menghapus node terakhir_____________
<br/>`delAfter`_______________ Menghapus node setelah node tertentu
<br/>`printList` / `printInfo` Menampilkan seluruh isi list________
<br/>`nbList`_________________ Menghitung jumlah node______________
<br/>`deleteList`_____________ Menghapus seluruh node______________


## Guided 

### 1. Guided 1

#### Header
```C++
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif
```
#### Implementasi Fungsi
```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

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
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
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
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
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

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List) == true) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```
#### Program Utama
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```
Program di atas adalah single linked list menggunakan ADT (Abstract Data Type). Program ini berfungsi untuk menyimpan dan menampilkan data mahasiswa.

### 2. Guided 2

```C++
// list.h

//Header guard digunakan untuk mencegah file header yang sama
//di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
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

#endif

// list.cpp

#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

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

//pembuatan node baru
address alokasi(string nama, string nim, int umur) { 

    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node
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

    if (Prev != Nil) { //Previous (sebelumnya) tidak boleh NULL
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
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
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
    cout << "List sudah terhapus!" << endl;
}



// main.cpp

#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "ISI LIST SETELAH DILAKUKAN INSERT" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "ISI LIST SETELAH DILAKUKAN DELETE" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "ISI LIST SETELAH DILAKUKAN HAPUS LIST" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
Program di atas adalah single linked list tanpa ADT. Program ini berfungsi untuk menyimpan, menampilkan, menghapus, menghitung data mahasiswa. Selain itu, program ini juga dapat menghapus seluruh data mahasiswa.


## Unguided 

### 1. Buatlah ADT Singly Linked list sebagai berikut di dalam file "Singlylist.h"
![Screenshot Soal Unguided 1_1](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan4_Modul4/soalunguided1-1.png)
Kemudian buatlah implementasi dari procedure-procedure yang digunakan didalam file
"Singlylist.cpp"
Kemudian buat program utama didalam file "main.cpp" dengan implementasi sebagai
berikut :
![Screenshot Soal Unguided 1_2](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan4_Modul4/soalunguided1-2.png)
Sehingga linkedlist yang dibuat akan seperti ini :
![Screenshot Soal Unguided 1_3](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan4_Modul4/soalunguided1-3.png)<br/>
Output yang diharapkan :
![Screenshot Soal Unguided 1_4](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan4_Modul4/soalunguided1-4.png)

#### Header
```C++
#ifndef UNGUIDED1_H
#define UNGUIDED1_H
#define Nil NULL

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef int infotype;
typedef struct ElmList *address;
typedef struct ElmList {
    infotype info;
    address next;
} ElmList;
typedef struct {
    address first;
} List;
void CreateList(List *L);
address alokasi(infotype x);
void dealokasi(address P);
void printInfo(List L);
void insertFirst(List *L, address P);

#endif
```

#### Implementasi Fungsi
```C++
#include "unguided1.h"
#include <iostream>
using namespace std;

void CreateList(List *L) {
    L->first = nullptr;
}
address alokasi(infotype x) {
    address P = new ElmList;
    if (P != nullptr) {
        P->info = x;
        P->next = nullptr;
    }
    return P;
}
void dealokasi(address P) {
    delete P;
}
void printInfo(List L) {
    address P = L.first;
    if (P == nullptr) {
        cout << "List kosong." << endl;
    } else {
        cout << "Isi list: ";
        while (P != nullptr) {
            cout << P->info << " ";
            P = P->next;
        }
        cout << endl;
    }
}
void insertFirst(List *L, address P) {
    if (P != nullptr) {
        P->next = L->first;
        L->first = P;
    }
}
```

#### Program Utama
```C++
#include <iostream>
#include <cstdlib>
#include "unguided1.h"
using namespace std;

int main(){
List* L;
address P1, P2, P3, P4, P5 = Nil;
CreateList(L);

P1 = alokasi (2);
insertFirst (L,P1);

P2 = alokasi(0);
insertFirst (L,P2);

P3 = alokasi (8);
insertFirst (L, P3);

P4 = alokasi (12);
insertFirst (L,P4);

P5 = alokasi (9);
insertFirst (L,P5);

printInfo(*L);
return 0;
}
```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan4_Modul4/outputunguided1.png)

Program di atas adalah single linked list menggunakan ADT (Abstract Data Type). Program ini mengalokasikan data untuk setiap node. Setelah data dialokasikan, data akan ditampilkan menggunakan printInfo() yang berparameter pointer L, yaitu pointer List.

### 2. Dari soal Latihan pertama,
lakukan penghapusan node 9 menggunakan deleteFirst(), node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh
node menggunakan deleteList().
Output yang diharapkan :
![Screenshot Soal Unguided 2_1](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan4_Modul4/soalunguided2-1.png)

#### Header
```C++
#ifndef UNGUIDED1_H
#define UNGUIDED1_H
#define Nil NULL

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef int infotype;
typedef struct ElmList *address;
typedef struct ElmList {
    infotype info;
    address next;
} ElmList;
typedef struct {
    address first;
} List;
void CreateList(List *L);
address alokasi(infotype x);
void dealokasi(address P);
void printInfo(List *L);
void insertFirst(List *L, address P);
bool isEmpty(List L);
void delFirst(List *L);
void delLast(List *L);
void delAfter(List *L, address nodePrev);
void deleteList(List *L);
int nbList(List *L);

#endif
```

#### Implementasi Fungsi
```C++
#include "unguided2.h"
#include <iostream>
using namespace std;

void CreateList(List *L) {
    L->first = nullptr;
}
address alokasi(infotype x) {
    address P = new ElmList;
    if (P != nullptr) {
        P->info = x;
        P->next = nullptr;
    }
    return P;
}
void dealokasi(address P) {
    delete P;
}
void printInfo(List *L) {
    address P = (*L).first;
    if (P == nullptr) {
        cout << "List kosong." << endl;
    } else {
        cout << "Isi list: ";
        while (P != nullptr) {
            cout << P->info << " ";
            P = P->next;
        }
        cout << endl;
        cout << "Jumlah Node: "<< nbList(L) << endl;
    }
}
void insertFirst(List *L, address P) {
    if (P != nullptr) {
        P->next = L->first;
        L->first = P;
    }
}

bool isEmpty(List L) {
    if(L.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void delFirst(List* L){

    address nodeHapus;
    if (isEmpty(*L) == false) {
        nodeHapus = (*L).first;
        (*L).first = (*L).first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(List* L){

    address nodeHapus, nodePrev;
    if(isEmpty(*L) == false){
        nodeHapus = (*L).first;
        if(nodeHapus->next == Nil){
            (*L).first = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(List *L, address nodePrev) {
    if (isEmpty(*L)) {
        cout << "List kosong!" << endl;
    } else if (nodePrev != Nil && nodePrev->next != Nil) {
        address nodeHapus = nodePrev->next;
        nodePrev->next = nodeHapus->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

int nbList(List *L) {
    int count = 0;
    address P = (*L).first;

    while (P != nullptr) {
        count++;
        P = P->next;
    }

    return count;
}

void deleteList(List *L){

    address nodeBantu, nodeHapus;
    nodeBantu = (*L).first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    (*L).first = Nil; 
    cout << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah Node: "<< nbList(L);

}
```

#### Program Utama
```C++
#include <iostream>
#include <cstdlib>
#include "unguided2.h"
using namespace std;

int main(){
List* L = new List;
address P1, P2, P3, P4, P5 = Nil;
CreateList(L);

P1 = alokasi (2);
insertFirst (L, P1);

P2 = alokasi(0);
insertFirst (L, P2);

P3 = alokasi (8);
insertFirst (L, P3);

P4 = alokasi (12);
insertFirst (L, P4);

P5 = alokasi (9);
insertFirst (L, P5);

delFirst(L);
delAfter(L, P4);
delLast(L);
printInfo(L);
deleteList(L);

return 0;
}
```

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan4_Modul4/outputunguided2.png)

Program di atas adalah single linked list menggunakan ADT (Abstract Data Type). Program ini adalah lanjutan dari soal pertama yang ditambahkan prosedur deleteFirst(), deleteLast(), deleteAfter(), nbList(), dan deleteList(). Penghapusan node 9 menggunakan deleteFirst(), node
2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Setelah itu program menampilkan
jumlah node yang tersimpan menggunakan nbList(), kemudian menghapus seluruh
node menggunakan deleteList().



## Kesimpulan
Array dan linked list memiliki kekurangan dan kelebihannya masing-masing. Penggunaan struktur data yang tepat akan mempengaruhi kinerja yang optimal.

## Referensi
[1] Yolandari, N. A., Zulfi, M. F., Butarbutar, L. E., & Rajagukguk, G. (2024). Menganalisis tingkat efisiensi struktur data array dan linked list untuk mengelola data mahasiswa dari segi kecepatan eksekusi dan penggunaan memori. Jurnal Kajian Ilmiah Multidisipliner, 8(10). Retrieved from https://sejurnal.com/pub/index.php/jkim/article/view/4900
<br/> [2] Sofianti, H. A., Manullang, Y. V., Tampubolon, N. A., Naibaho, L. H., & Gunawan, I. (2024). Implementasi struktur data array dan linked list dalam pengelolaan data mahasiswa. Menulis: Jurnal Penelitian Nusantara. Retrieved from https://padangjurnal.web.id/index.php/menulis/article/view/417
<br/> [3] Wijoyo, A., Azzahra, A., Nabila, D., Silviana, F., & Lusiyanti. (2024). Perbandingan struktur linked list dan array dalam manajemen memori. JRIIN : Jurnal Riset Informatika dan Inovasi, 1(12), 1290-1293. Retrieved from https://jurnalmahasiswa.com/index.php/jriin/article/view/957
