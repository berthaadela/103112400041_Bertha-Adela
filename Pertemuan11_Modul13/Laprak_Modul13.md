# <h1 align="center">Laporan Praktikum Modul 13 - MULTI LINKED LIST</h1>
<p align="center">Bertha Adela - 103112400041</p>

## Dasar Teori
Dalam struktur multi linked list, setiap node tidak hanya memiliki satu data dan satu penunjuk seperti pada singly linked list, tetapi dapat menyimpan banyak data dan memiliki lebih dari satu pointer yang menghubungkan ke node lainnya [1]. Selain itu, multi linked list mengorganisasikan data secara multi dimensi sehingga memudahkan proses pencarian dan penyisipan data[2].

## Guided 

### 1. Guided 1

#### multilist.h
```C++
#ifndef MULTILIST_H
#define MULTILIST_H

#include <iostream>
using namespace std;

typedef struct nodeParent *NodeParent; //alias pointer ke struct nodeParent
typedef struct nodeChild *NodeChild; //alias pointer ke struct nodeChild
struct nodeChild { //node child
    string idMakanan;
    string namaMakanan;
    NodeChild next;
    NodeChild prev;
};

struct listAnak {
    NodeChild first;
    NodeChild last;
};

struct nodeParent { //nodeParent
    string idKategoriMakanan;
    string namaKategoriMakanan;
    NodeParent next;
    NodeParent prev;
    listAnak L_Anak;
};

struct listInduk { //listParent
    NodeParent first;
    NodeParent last;
};

//createlist
void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &LAnak);

//alokasi & dealokasi parent
NodeParent alokasiNodeParent(string idKategoriMakanan, string namaKategoriMakanan);
void dealokasiNodeParent(NodeParent &nodeInduk);

//alokasi & dealokasi child
NodeChild alokasiNodeChild(string idKategoriMakanan, string namaKategoriMakanan);
void dealokasiNodeChild(NodeChild &nodeAnak);

//operasi pada parent
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent);
void hapusListAnak(listAnak &LAnak);
void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev);

//operasi pada child
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild);
void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev);
void findChildById(listInduk &LInduk, string IDCari);

//operasi print
void printStrukturMLL(listInduk &LInduk);

#endif
```
#### multilist.cpp
```C++
#include "multilist.h"
#include <iostream>

using namespace std;

//create list
void createListInduk(listInduk &LInduk){
    LInduk.first = LInduk.last = NULL;
}

void createListAnak(listAnak &LAnak){
    LAnak.first = LAnak.last = NULL;
}

//alokasi & dealokasi parent
NodeParent alokasiNodeParent(string idKategoriMakanan, string namaKategoriMakanan){
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->idKategoriMakanan = idKategoriMakanan;
    nodeBaruParent->namaKategoriMakanan = namaKategoriMakanan;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListAnak(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

void dealokasiNodeParent(NodeParent &nodeInduk){
    if(nodeInduk != NULL) {
        nodeInduk->next = nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

//alokasi & delaokasi child
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan){
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->idMakanan = idMakanan;
    nodeBaruChild->namaMakanan = namaMakanan;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeChild(NodeChild &nodeAnak){
    if(nodeAnak != NULL) {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

//operasi pada parent
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent){
    if(LInduk.first == NULL) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->prev = LInduk.last;
        LInduk.last->next = nodeBaruParent;
        LInduk.last = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->namaKategoriMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Induk!" << endl;
}

void hapusListAnak(listAnak &LAnak){
    NodeChild nodeBantu = LAnak.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LAnak.first = LAnak.last = NULL;
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeParent nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LInduk.last = nodePrev;
            }
            nodeHapus->next = NULL;
            if(nodeHapus->L_Anak.first != NULL){
                hapusListAnak(nodeHapus->L_Anak);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << nodePrev->namaKategoriMakanan << " berhasil dihapus beserta anak-anaknya!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

//operasi pada child
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild){
    if(LAnak.first == NULL) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->namaMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Anak!" << endl;
}

void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev){
    if(LAnak.first == NULL){
        cout << "List anak kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeChild nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LAnak.last = nodePrev;
            }
            nodeHapus->next = NULL;
            dealokasiNodeChild(nodeHapus);
            cout << "Node child setelah node " << nodePrev->namaMakanan << " berhasil dihapus!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}
void findChildByID(listInduk &LInduk, string IDCari){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        int ketemu = false;
        while(nodeBantuParent != NULL){
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->idMakanan == IDCari) {
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->namaKategoriMakanan << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child (ID Makanan) : " << nodeBantuChild->idMakanan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent (ID Kategori Makanan): " << nodeBantuParent->idKategoriMakanan << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;
                    ketemu = true;
                    break;
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if(ketemu){
                break;
            } else {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if(!ketemu){
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

//operasi print
void printStrukturMLL(listInduk &LInduk){
    if(LInduk.first == NULL) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Kategori Makanan : " << nodeBantuParent->idKategoriMakanan << endl;
            cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;

            //print list anak dari node parentnya
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Makanan : " << nodeBantuChild->idMakanan << endl;
                    cout << "      Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
    }
}
```
#### main.cpp
```C++
#include "multilist.h"
#include <iostream>

using namespace std;

int main() {
    //1.Inisiasi List
    listInduk LInduk;
    createListInduk(LInduk);
    //2. Membuat Data Parent (Kategori Makanan)
    NodeParent K01 = alokasiNodeParent("K01", "Makanan");
    insertLastParent(LInduk, K01);
    NodeParent K02 = alokasiNodeParent("K01", "Minuman");
    insertLastParent(LInduk, K02);
    NodeParent K03 = alokasiNodeParent("K01", "Dessert");
    insertLastParent(LInduk, K03);

    //3.Memasukkan Data Child (Menu Makanan) ke
    //Makanan
    NodeChild M01 = alokasiNodeChild("M01", "Nasi Goreng Spesial");
    insertLastChild(K01->L_Anak, M01);
    NodeChild M02 = alokasiNodeChild("M02", "Ayam Bakar Madu");
    insertLastChild(K01->L_Anak, M02);
    //Minuman
    NodeChild D02 = alokasiNodeChild("M03", "Jus Alpukat");
    insertLastChild(K02->L_Anak, D02);
    NodeChild D01 = alokasiNodeChild("M04", "Es Teh Manis");
    insertLastChild(K02->L_Anak, D01);
    //Dessert
    NodeChild S01 = alokasiNodeChild("S01", "Puding Coklat");
    insertLastChild(K03->L_Anak, S01);

    //4. Print mll setelah insert-insert
    printStrukturMLL(LInduk);
    cout << endl;

    //5. Searching Node Child
    findChildById(LInduk, "D01");
    cout << endl;
    //6. Delete Node Child
    deleteAfterChild(K01->L_Anak, M01);
    cout << endl;
    //7. Delete Node Parent
    deleteAfterParent(LInduk, K02);
    cout << endl;
    //8. Print MLL setelah Delete-Delete
    printStrukturMLL(LInduk);
    cout << endl;
    return 0;
}
```
Program ini mensimulasikan sistem kategori dan menu menggunakan Multi Linked List, dengan operasi: insert parent & child, pencarian child, penghapusan child, penghapusan parent, dan penampilan struktur data.


## Unguided 

### 1. Buatlah ADT Multi Linked List sebagai berikut didalam file "MultiLL.h" :
![Screenshot Soal Unguided 1_1](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan11_Modul13/SOALUNGUIDED1_1.png)
![Screenshot Soal Unguided 1_2](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan11_Modul13/SOALUNGUIDED1_2.png)
<br/>Kemudian buatlah implementasi ADT Multi Linked List tersebut pada file "MultiLL.cpp"
<br/>Kemudian pada file "main.cpp" lakukan operasi INSERT sebagaimana sehingga bentuk
dari multi linked listnya seperti ini :
![Screenshot Soal Unguided 1_3](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan11_Modul13/SOALUNGUIDED1_3.png)
![Screenshot Soal Unguided 1_4](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan11_Modul13/SOALUNGUIDED1_4.png)
<br/>Setelah melakukan INSERT, lakukan operasi PRINT dengan memanggil prosedur
printMLLStructure().
<br/>(Lampirkan screenshot output hasil print pada laporan)
<br/>Ekspektasi output :
<br/>
![Screenshot Soal Unguided 1_5](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan11_Modul13/SOALUNGUIDED1_5.png)

#### MultiLL.h
```C++
#ifndef MULTILL_H
#define MULTILL_H

#include <string>

using namespace std;

typedef struct golonganHewan {
    string idGolongan;
    string namaGolongan;
} golonganHewan;

typedef struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
} dataHewan;

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

typedef struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
} nodeChild;

typedef struct listChild {
    NodeChild first;
    NodeChild last;
} listChild;

typedef struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
} nodeParent;

typedef struct listParent {
    NodeParent first;
    NodeParent last;
} listParent;

bool isEmptyParent(listParent LParent);
bool isEmptyChild(listChild LChild);
void createListParent(listParent &LParent);
void createListChild(listChild &LChild);
NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);
void deallocNodeParent(NodeParent &NParent);
void deallocNodeChild(NodeChild &NChild);
void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);
void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertLastChild(listChild &LChild, NodeChild newNChild);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);
void deleteListChild(listChild &LChild);
void printMLLStructure(listParent LParent);

#endif
```
#### MultiLL.cpp
```C++
#include "MultiLL.h"
#include <iostream>
using namespace std;

bool isEmptyParent(listParent LParent) {
    return (LParent.first == NULL && LParent.last == NULL);
}
bool isEmptyChild(listChild LChild) {
    return (LChild.first == NULL && LChild.last == NULL);
}
void createListParent(listParent &LParent) {
    LParent.first = NULL;
    LParent.last = NULL;
}
void createListChild(listChild &LChild) {
    LChild.first = NULL;
    LChild.last = NULL;
}
NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent NParent = new nodeParent;
    NParent->isidata.idGolongan = idGol;
    NParent->isidata.namaGolongan = namaGol;
    NParent->next = NULL;
    NParent->prev = NULL;
    createListChild(NParent->L_Child);
    return NParent;
}
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild NChild = new nodeChild;
    NChild->isidata.idHewan = idHwn;
    NChild->isidata.namaHewan = namaHwn;
    NChild->isidata.habitat = habitat;
    NChild->isidata.ekor = tail;
    NChild->isidata.bobot = weight;
    NChild->next = NULL;
    NChild->prev = NULL;
    return NChild;
}
void deallocNodeParent(NodeParent &NParent) {
    delete NParent;
}
void deallocNodeChild(NodeChild &NChild) {
    delete NChild;
}
void insertFirstParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = newNParent;
        LParent.last = newNParent;
    } else {
        newNParent->next = LParent.first;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
}
void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = newNParent;
        LParent.last = newNParent;
    } else {
        LParent.last->next = newNParent;
        newNParent->prev = LParent.last;
        LParent.last = newNParent;
    }
}
void deleteFirstParent(listParent &LParent) {
    if (!isEmptyParent(LParent)) {
        NodeParent NDelete = LParent.first;
        if (LParent.first == LParent.last) {
            LParent.first = NULL;
            LParent.last = NULL;
        } else {
            LParent.first = LParent.first->next;
            LParent.first->prev = NULL;
        }
        deallocNodeParent(NDelete);
    }
}
void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeParent NDelete = NPrev->next;
        NPrev->next = NDelete->next;
        if (NDelete == LParent.last) {
            LParent.last = NPrev;
        } else {
            NDelete->next->prev = NPrev;
        }
        deallocNodeParent(NDelete);
    }
}
void insertFirstChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = newNChild;
        LChild.last = newNChild;
    } else {
        newNChild->next = LChild.first;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
}
void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = newNChild;
        LChild.last = newNChild;
    } else {
        LChild.last->next = newNChild;
        newNChild->prev = LChild.last;
        LChild.last = newNChild;
    }
}
void deleteFirstChild(listChild &LChild) {
    if (!isEmptyChild(LChild)) {
        NodeChild NDelete = LChild.first;
        if (LChild.first == LChild.last) {
            LChild.first = NULL;
            LChild.last = NULL;
        } else {
            LChild.first = LChild.first->next;
            LChild.first->prev = NULL;
        }
        deallocNodeChild(NDelete);
    }
}
void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeChild NDelete = NPrev->next;
        NPrev->next = NDelete->next;
        if (NDelete == LChild.last) {
            LChild.last = NPrev;
        } else {
            NDelete->next->prev = NPrev;
        }
        deallocNodeChild(NDelete);
    }
}
void deleteListChild(listChild &LChild) {
    while (!isEmptyChild(LChild)) {
        deleteFirstChild(LChild);
    }
}
void printMLLStructure(listParent LParent) {
    if (isEmptyParent(LParent)) {
        cout << "Multi-Level List is empty." << endl;
        return;
    }
    NodeParent PParent = LParent.first;
    int parentKe = 1;
    int childKe = 1;
    while (PParent != NULL) {
        cout << "=== " << "Parent " << parentKe++ << " ===" << endl;
        cout << "ID Golongan : " << PParent->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << PParent->isidata.namaGolongan << endl;
        NodeChild PChild = PParent->L_Child.first;
        if (isEmptyChild(PParent->L_Child)) {
            cout << "  (tidak ada child)" << endl;
        } else {
            while (PChild != NULL) {
                cout << "   - Child " << childKe++ << endl;
                cout << "       ID Hewan: " << PChild->isidata.idHewan << endl;
                cout << "       Nama Hewan : " << PChild->isidata.namaHewan << endl;
                cout << "       Habitat: " << PChild->isidata.habitat << endl;
                cout << "       Ekor: " << (PChild->isidata.ekor ? "1" : "0") << endl;
                cout << "       Bobot: " << PChild->isidata.bobot << endl;
                PChild = PChild->next;
            }
        }
        PParent = PParent->next;
        childKe = 1;
    }
}
```
#### main.cpp
```C++
#include "MultiLL.h"
#include <iostream>
using namespace std;

int main() {
    listParent LParent;
    createListParent(LParent);
    NodeParent N1 = allocNodeParent("G001", "Aves");
    insertLastParent(LParent, N1);
    NodeParent N2 = allocNodeParent("G002", "Mamalia");
    insertLastParent(LParent, N2);
    NodeParent N3 = allocNodeParent("G003", "Pisces");
    insertLastParent(LParent, N3);
    NodeParent N4 = allocNodeParent("G004", "Amfibi");
    insertLastParent(LParent, N4);
    NodeParent N5 = allocNodeParent("G005", "Reptil");
    insertLastParent(LParent, N5);

    NodeChild C1 = allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3);
    insertLastChild(N1->L_Child, C1);
    NodeChild C2 = allocNodeChild("AV002", "Bebek", "Air", true, 2);
    insertLastChild(N1->L_Child, C2);

    NodeChild C3 = allocNodeChild("M001", "Harimau", "Hutan", true, 200);
    insertLastChild(N2->L_Child, C3);
    NodeChild C4 = allocNodeChild("M002", "Gorila", "Hutan", false, 160);
    insertLastChild(N2->L_Child, C4);
    NodeChild C5 = allocNodeChild("M001", "Kucing", "Darat", true, 4);
    insertLastChild(N2->L_Child, C5);

    NodeChild C6 = allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2);
    insertLastChild(N4->L_Child, C6);

    printMLLStructure(LParent);
}
```
### Output Unguided 1 :
![Screenshot Output Unguided 1_1](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan11_Modul13/Output1.png)

Program ini akan membuat struktur multi linked list dengan id parent G001, G002, G003, G004, dan G005.
<br/>Parent G001 dialokasikan child AV001 dan AV002.
<br/>Parent G002 dialokasikan child M001, M002, dan M003.
<br/>Parent G004 dialokasikan child AM001.

### 2. Tambahkan prosedur searchHewanByEkor(input/output LParent : listParent, input tail : Boolean) yang digunakan untuk melakukan operasi SEARCHING hewan-hewan yang memiliki EKOR FALSE (pencarian dilakukan dengan menelusuri list child yang ada pada masing-masing node parent). Kemudian panggil prosedur tersebut pada main.cpp.
<br/>Ekspektasi output :
<br/>
![Screenshot Soal Unguided 2_1](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan11_Modul13/SOALUNGUIDED2_1.png)

#### MultiLL.h
```C++
#ifndef MULTILL_H
#define MULTILL_H

#include <string>

using namespace std;

typedef struct golonganHewan {
    string idGolongan;
    string namaGolongan;
} golonganHewan;

typedef struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
} dataHewan;

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

typedef struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
} nodeChild;

typedef struct listChild {
    NodeChild first;
    NodeChild last;
} listChild;

typedef struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
} nodeParent;

typedef struct listParent {
    NodeParent first;
    NodeParent last;
} listParent;

bool isEmptyParent(listParent LParent);
bool isEmptyChild(listChild LChild);
void createListParent(listParent &LParent);
void createListChild(listChild &LChild);
NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);
void deallocNodeParent(NodeParent &NParent);
void deallocNodeChild(NodeChild &NChild);
void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);
void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertLastChild(listChild &LChild, NodeChild newNChild);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);
void deleteListChild(listChild &LChild);
void printMLLStructure(listParent LParent);
void searchHewanByEkor(listParent LParent, bool tail);

#endif
```
#### MultiLL.cpp
```C++
#include "MultiLL.h"
#include <iostream>
using namespace std;

bool isEmptyParent(listParent LParent) {
    return (LParent.first == NULL && LParent.last == NULL);
}
bool isEmptyChild(listChild LChild) {
    return (LChild.first == NULL && LChild.last == NULL);
}
void createListParent(listParent &LParent) {
    LParent.first = NULL;
    LParent.last = NULL;
}
void createListChild(listChild &LChild) {
    LChild.first = NULL;
    LChild.last = NULL;
}
NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent NParent = new nodeParent;
    NParent->isidata.idGolongan = idGol;
    NParent->isidata.namaGolongan = namaGol;
    NParent->next = NULL;
    NParent->prev = NULL;
    createListChild(NParent->L_Child);
    return NParent;
}
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild NChild = new nodeChild;
    NChild->isidata.idHewan = idHwn;
    NChild->isidata.namaHewan = namaHwn;
    NChild->isidata.habitat = habitat;
    NChild->isidata.ekor = tail;
    NChild->isidata.bobot = weight;
    NChild->next = NULL;
    NChild->prev = NULL;
    return NChild;
}
void deallocNodeParent(NodeParent &NParent) {
    delete NParent;
}
void deallocNodeChild(NodeChild &NChild) {
    delete NChild;
}
void insertFirstParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = newNParent;
        LParent.last = newNParent;
    } else {
        newNParent->next = LParent.first;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
}
void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = newNParent;
        LParent.last = newNParent;
    } else {
        LParent.last->next = newNParent;
        newNParent->prev = LParent.last;
        LParent.last = newNParent;
    }
}
void deleteFirstParent(listParent &LParent) {
    if (!isEmptyParent(LParent)) {
        NodeParent NDelete = LParent.first;
        if (LParent.first == LParent.last) {
            LParent.first = NULL;
            LParent.last = NULL;
        } else {
            LParent.first = LParent.first->next;
            LParent.first->prev = NULL;
        }
        deallocNodeParent(NDelete);
    }
}
void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeParent NDelete = NPrev->next;
        NPrev->next = NDelete->next;
        if (NDelete == LParent.last) {
            LParent.last = NPrev;
        } else {
            NDelete->next->prev = NPrev;
        }
        deallocNodeParent(NDelete);
    }
}
void insertFirstChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = newNChild;
        LChild.last = newNChild;
    } else {
        newNChild->next = LChild.first;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
}
void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = newNChild;
        LChild.last = newNChild;
    } else {
        LChild.last->next = newNChild;
        newNChild->prev = LChild.last;
        LChild.last = newNChild;
    }
}
void deleteFirstChild(listChild &LChild) {
    if (!isEmptyChild(LChild)) {
        NodeChild NDelete = LChild.first;
        if (LChild.first == LChild.last) {
            LChild.first = NULL;
            LChild.last = NULL;
        } else {
            LChild.first = LChild.first->next;
            LChild.first->prev = NULL;
        }
        deallocNodeChild(NDelete);
    }
}
void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeChild NDelete = NPrev->next;
        NPrev->next = NDelete->next;
        if (NDelete == LChild.last) {
            LChild.last = NPrev;
        } else {
            NDelete->next->prev = NPrev;
        }
        deallocNodeChild(NDelete);
    }
}
void deleteListChild(listChild &LChild) {
    while (!isEmptyChild(LChild)) {
        deleteFirstChild(LChild);
    }
}
void printMLLStructure(listParent LParent) {
    if (isEmptyParent(LParent)) {
        cout << "Multi-Level List is empty." << endl;
        return;
    }
    NodeParent PParent = LParent.first;
    int parentKe = 1;
    int childKe = 1;
    while (PParent != NULL) {
        cout << "=== " << "Parent " << parentKe++ << " ===" << endl;
        cout << "ID Golongan : " << PParent->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << PParent->isidata.namaGolongan << endl;
        NodeChild PChild = PParent->L_Child.first;
        if (isEmptyChild(PParent->L_Child)) {
            cout << "  (tidak ada child)" << endl;
        } else {
            while (PChild != NULL) {
                cout << "   - Child " << childKe++ << endl;
                cout << "       ID Hewan: " << PChild->isidata.idHewan << endl;
                cout << "       Nama Hewan : " << PChild->isidata.namaHewan << endl;
                cout << "       Habitat: " << PChild->isidata.habitat << endl;
                cout << "       Ekor: " << (PChild->isidata.ekor ? "1" : "0") << endl;
                cout << "       Bobot: " << PChild->isidata.bobot << endl;
                PChild = PChild->next;
            }
        }
        PParent = PParent->next;
        childKe = 1;
    }
}

void searchHewanByEkor(listParent LParent, bool tail) {
    if (isEmptyParent(LParent)) {
        cout << "Multi-Level List is empty." << endl;
        return;
    }
    NodeParent PParent = LParent.first;
    bool found = false;
    int ChildKeBerapa = 1;
    int ParentKeBerapa = 1;
    while (PParent != NULL) {
        NodeChild PChild = PParent->L_Child.first;
        while (PChild != NULL) {
            if (PChild->isidata.ekor == tail)  {
                found = true;
                cout << "Data ditemukan pada list anak dari node parent " << PParent->isidata.idGolongan << " pada posisi ke-" << ChildKeBerapa << endl;
                cout << "--- Data Child ---" << endl;
                cout << "ID Child: " << PChild->isidata.idHewan << endl;
                cout << "posisi dalam list anak : posisi ke-" << ChildKeBerapa << endl;
                cout << "Nama Hewan: " << PChild->isidata.namaHewan << endl;
                cout << "Habitat: " << PChild->isidata.habitat << endl;
                cout << "Ekor: " << PChild->isidata.ekor << endl;
                cout << "Bobot: " << PChild->isidata.bobot << endl;
                cout << "----------------------------------------" << endl;
                cout << "--- Data Parent ---" << endl;
                cout << "ID Parent: " << PParent->isidata.idGolongan << endl;
                cout << "posisi dalam list induk : posisi ke-" << ParentKeBerapa << endl;
                cout << "Nama golongan : " << PParent->isidata.namaGolongan << endl;
                cout << "----------------------------------------------------------------" << endl;
            }
            PChild = PChild->next;
            ChildKeBerapa++;
        }
        PParent = PParent->next;
        ParentKeBerapa++;
        ChildKeBerapa = 1;
    }
    if (!found) {
        cout << "Tidak ada hewan dengan ekor " << (tail ? "1" : "0") << " ditemukan." << endl;
    }
}
```
#### main.cpp
```C++
#include "MultiLL.h"
#include <iostream>
using namespace std;

int main() {
    listParent LParent;
    createListParent(LParent);
    NodeParent N1 = allocNodeParent("G001", "Aves");
    insertLastParent(LParent, N1);
    NodeParent N2 = allocNodeParent("G002", "Mamalia");
    insertLastParent(LParent, N2);
    NodeParent N3 = allocNodeParent("G003", "Pisces");
    insertLastParent(LParent, N3);
    NodeParent N4 = allocNodeParent("G004", "Amfibi");
    insertLastParent(LParent, N4);
    NodeParent N5 = allocNodeParent("G005", "Reptil");
    insertLastParent(LParent, N5);

    NodeChild C1 = allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3);
    insertLastChild(N1->L_Child, C1);
    NodeChild C2 = allocNodeChild("AV002", "Bebek", "Air", true, 2);
    insertLastChild(N1->L_Child, C2);

    NodeChild C3 = allocNodeChild("M001", "Harimau", "Hutan", true, 200);
    insertLastChild(N2->L_Child, C3);
    NodeChild C4 = allocNodeChild("M002", "Gorila", "Hutan", false, 160);
    insertLastChild(N2->L_Child, C4);
    NodeChild C5 = allocNodeChild("M001", "Kucing", "Darat", true, 4);
    insertLastChild(N2->L_Child, C5);

    NodeChild C6 = allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2);
    insertLastChild(N4->L_Child, C6);

    searchHewanByEkor(LParent, false);
    return 0;
}
```
### Output Unguided 2 :
![Screenshot Output Unguided 2_1](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan11_Modul13/Output2.png)

Program ini akan mencari hewan yang tidak memiliki ekor serta menampilkan informasi parent dari hewan yang tidak memiliki ekor.

### 3. Lakukan operasi DELETE dengan menghapus node G004 yang ada pada list parent (list child dari node tersebut juga terhapus), kemudian lakukan lagi operasi PRINT dengan memanggil prosedur printMLLStructure(). Sehingga bentuk dari multi linked listnya berubah menjadi seperi ini :
![Screenshot Soal Unguided 3_1](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan11_Modul13/SOALUNGUIDED3_1.png)
<br/>(Lampirkan screenshot output hasil print setelah dilakukan delete pada laporan).
<br/>Ekspektasi output :
<br/>
![Screenshot Soal Unguided 3_2](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan11_Modul13/SOALUNGUIDED3_2.png)

#### MultiLL.h
```C++
#ifndef MULTILL_H
#define MULTILL_H

#include <string>

using namespace std;

typedef struct golonganHewan {
    string idGolongan;
    string namaGolongan;
} golonganHewan;

typedef struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
} dataHewan;

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

typedef struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
} nodeChild;

typedef struct listChild {
    NodeChild first;
    NodeChild last;
} listChild;

typedef struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
} nodeParent;

typedef struct listParent {
    NodeParent first;
    NodeParent last;
} listParent;

bool isEmptyParent(listParent LParent);
bool isEmptyChild(listChild LChild);
void createListParent(listParent &LParent);
void createListChild(listChild &LChild);
NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);
void deallocNodeParent(NodeParent &NParent);
void deallocNodeChild(NodeChild &NChild);
void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);
void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertLastChild(listChild &LChild, NodeChild newNChild);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);
void deleteListChild(listChild &LChild);
void printMLLStructure(listParent LParent);
void searchHewanByEkor(listParent LParent, bool tail);

#endif
```
#### MultiLL.cpp
```C++
#include "MultiLL.h"
#include <iostream>
using namespace std;

bool isEmptyParent(listParent LParent) {
    return (LParent.first == NULL && LParent.last == NULL);
}
bool isEmptyChild(listChild LChild) {
    return (LChild.first == NULL && LChild.last == NULL);
}
void createListParent(listParent &LParent) {
    LParent.first = NULL;
    LParent.last = NULL;
}
void createListChild(listChild &LChild) {
    LChild.first = NULL;
    LChild.last = NULL;
}
NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent NParent = new nodeParent;
    NParent->isidata.idGolongan = idGol;
    NParent->isidata.namaGolongan = namaGol;
    NParent->next = NULL;
    NParent->prev = NULL;
    createListChild(NParent->L_Child);
    return NParent;
}
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild NChild = new nodeChild;
    NChild->isidata.idHewan = idHwn;
    NChild->isidata.namaHewan = namaHwn;
    NChild->isidata.habitat = habitat;
    NChild->isidata.ekor = tail;
    NChild->isidata.bobot = weight;
    NChild->next = NULL;
    NChild->prev = NULL;
    return NChild;
}
void deallocNodeParent(NodeParent &NParent) {
    delete NParent;
}
void deallocNodeChild(NodeChild &NChild) {
    delete NChild;
}
void insertFirstParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = newNParent;
        LParent.last = newNParent;
    } else {
        newNParent->next = LParent.first;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
}
void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = newNParent;
        LParent.last = newNParent;
    } else {
        LParent.last->next = newNParent;
        newNParent->prev = LParent.last;
        LParent.last = newNParent;
    }
}
void deleteFirstParent(listParent &LParent) {
    if (!isEmptyParent(LParent)) {
        NodeParent NDelete = LParent.first;
        if (LParent.first == LParent.last) {
            LParent.first = NULL;
            LParent.last = NULL;
        } else {
            LParent.first = LParent.first->next;
            LParent.first->prev = NULL;
        }
        deallocNodeParent(NDelete);
    }
}
void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeParent NDelete = NPrev->next;
        NPrev->next = NDelete->next;
        if (NDelete == LParent.last) {
            LParent.last = NPrev;
        } else {
            NDelete->next->prev = NPrev;
        }
        deallocNodeParent(NDelete);
    }
}
void insertFirstChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = newNChild;
        LChild.last = newNChild;
    } else {
        newNChild->next = LChild.first;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
}
void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = newNChild;
        LChild.last = newNChild;
    } else {
        LChild.last->next = newNChild;
        newNChild->prev = LChild.last;
        LChild.last = newNChild;
    }
}
void deleteFirstChild(listChild &LChild) {
    if (!isEmptyChild(LChild)) {
        NodeChild NDelete = LChild.first;
        if (LChild.first == LChild.last) {
            LChild.first = NULL;
            LChild.last = NULL;
        } else {
            LChild.first = LChild.first->next;
            LChild.first->prev = NULL;
        }
        deallocNodeChild(NDelete);
    }
}
void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeChild NDelete = NPrev->next;
        NPrev->next = NDelete->next;
        if (NDelete == LChild.last) {
            LChild.last = NPrev;
        } else {
            NDelete->next->prev = NPrev;
        }
        deallocNodeChild(NDelete);
    }
}
void deleteListChild(listChild &LChild) {
    while (!isEmptyChild(LChild)) {
        deleteFirstChild(LChild);
    }
}
void printMLLStructure(listParent LParent) {
    if (isEmptyParent(LParent)) {
        cout << "Multi-Level List is empty." << endl;
        return;
    }
    NodeParent PParent = LParent.first;
    int parentKe = 1;
    int childKe = 1;
    while (PParent != NULL) {
        cout << "=== " << "Parent " << parentKe++ << " ===" << endl;
        cout << "ID Golongan : " << PParent->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << PParent->isidata.namaGolongan << endl;
        NodeChild PChild = PParent->L_Child.first;
        if (isEmptyChild(PParent->L_Child)) {
            cout << "  (tidak ada child)" << endl;
        } else {
            while (PChild != NULL) {
                cout << "   - Child " << childKe++ << endl;
                cout << "       ID Hewan: " << PChild->isidata.idHewan << endl;
                cout << "       Nama Hewan : " << PChild->isidata.namaHewan << endl;
                cout << "       Habitat: " << PChild->isidata.habitat << endl;
                cout << "       Ekor: " << (PChild->isidata.ekor ? "1" : "0") << endl;
                cout << "       Bobot: " << PChild->isidata.bobot << endl;
                PChild = PChild->next;
            }
        }
        PParent = PParent->next;
        childKe = 1;
    }
}
void searchHewanByEkor(listParent LParent, bool tail) {
    if (isEmptyParent(LParent)) {
        cout << "Multi-Level List is empty." << endl;
        return;
    }
    NodeParent PParent = LParent.first;
    bool found = false;
    int ChildKeBerapa = 1;
    int ParentKeBerapa = 1;
    while (PParent != NULL) {
        NodeChild PChild = PParent->L_Child.first;
        while (PChild != NULL) {
            if (PChild->isidata.ekor == tail)  {
                found = true;
                cout << "Data ditemukan pada list anak dari node parent " << PParent->isidata.idGolongan << " pada posisi ke-" << ChildKeBerapa << endl;
                cout << "--- Data Child ---" << endl;
                cout << "ID Child: " << PChild->isidata.idHewan << endl;
                cout << "posisi dalam list anak : posisi ke-" << ChildKeBerapa << endl;
                cout << "Nama Hewan: " << PChild->isidata.namaHewan << endl;
                cout << "Habitat: " << PChild->isidata.habitat << endl;
                cout << "Ekor: " << PChild->isidata.ekor << endl;
                cout << "Bobot: " << PChild->isidata.bobot << endl;
                cout << "----------------------------------------" << endl;
                cout << "--- Data Parent ---" << endl;
                cout << "ID Parent: " << PParent->isidata.idGolongan << endl;
                cout << "posisi dalam list induk : posisi ke-" << ParentKeBerapa << endl;
                cout << "Nama golongan : " << PParent->isidata.namaGolongan << endl;
                cout << "----------------------------------------------------------------" << endl;
            }
            PChild = PChild->next;
            ChildKeBerapa++;
        }
        PParent = PParent->next;
        ParentKeBerapa++;
        ChildKeBerapa = 1;
    }
    if (!found) {
        cout << "Tidak ada hewan dengan ekor " << (tail ? "1" : "0") << " ditemukan." << endl;
    }
}
```
#### main.cpp
```C++
#include "MultiLL.h"
#include <iostream>
using namespace std;

int main() {
    listParent LParent;
    createListParent(LParent);
    NodeParent N1 = allocNodeParent("G001", "Aves");
    insertLastParent(LParent, N1);
    NodeParent N2 = allocNodeParent("G002", "Mamalia");
    insertLastParent(LParent, N2);
    NodeParent N3 = allocNodeParent("G003", "Pisces");
    insertLastParent(LParent, N3);
    NodeParent N4 = allocNodeParent("G004", "Amfibi");
    insertLastParent(LParent, N4);
    NodeParent N5 = allocNodeParent("G005", "Reptil");
    insertLastParent(LParent, N5);


    NodeChild C1 = allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3);
    insertLastChild(N1->L_Child, C1);
    NodeChild C2 = allocNodeChild("AV002", "Bebek", "Air", true, 2);
    insertLastChild(N1->L_Child, C2);

    NodeChild C3 = allocNodeChild("M001", "Harimau", "Hutan", true, 200);
    insertLastChild(N2->L_Child, C3);
    NodeChild C4 = allocNodeChild("M002", "Gorila", "Hutan", false, 160);
    insertLastChild(N2->L_Child, C4);
    NodeChild C5 = allocNodeChild("M001", "Kucing", "Darat", true, 4);
    insertLastChild(N2->L_Child, C5);

    NodeChild C6 = allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2);
    insertLastChild(N4->L_Child, C6);


    deleteListChild(N4->L_Child);
    deleteAfterParent(LParent, N3);
    printMLLStructure(LParent);
    
    return 0;
}
```
### Output Unguided 3 :
![Screenshot Output Unguided 3_1](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan11_Modul13/Output3.png)

Program ini akan menghapus node parent dengan menghapus list childnya terlebih dahulu dari parentnya, kemudian menghapus node parentnya.

## Kesimpulan
Multi linked list memungkinkan setiap node memiliki lebih dari satu pointer sehingga dapat memanipulasi data yang kompleks. Struktur ini memudahkan pengelolaan data dengan hubungan bertingkat.

## Referensi
[1]Patel, S. H., & Mahariba, A. J. (2019). Word search puzzle using multi-linked lists.
International Journal of Engineering and Advanced Technology (IJEAT). <br/>
[2]Goponenko, A., & Carroll, S. (2019). A C++ implementation of a lock-free priority queue
based on multi-dimensional linked list. Retrieved from ResearchGate.