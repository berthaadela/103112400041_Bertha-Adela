# <h1 align="center">Laporan Praktikum Modul 14 - GRAPH</h1>
<p align="center">Bertha Adela - 103112400041</p>

## Dasar Teori
Graf merupakan himpunan benda-benda yang disebut node (verteks), dimana node
terhubung oleh sisi (edge)[1]. Graph banyak digunakan dalam penggambaran hubungan antara objek satu dengan .[2].

Simpul adalah objek sembarang seperti kota, atom-atom, titik-titik, maupun benda-benda yang dapat dijabarkan[2]. Busur adalah hubungan antar objek yang memaknai relasi antar objek [2].

1. Graf Tak Berarah
adalah Graf yang sisinya tidak memiliki arah dimana urutan pasangan simpul yang dihubungkan oleh sisi tidak diperhatikan[1].
2. Graf Berarah
adalah Graf yang semua sisinya berarah[1]. Pada graf berarah, urutan pasangan simpul sangat diperhatikan[1]. Kesalahan dapat membuat makna yang berbeda[1].

Depth-First Search
Teknik DFS (Depth-First Search) bekerja dengan melakukan penelusuran ke arah yang lebih dalam terlebih dahulu[3]. Saat menemukan jalan buntu atau jalur pertama telah habis dijelajahi, pencarian akan kembali satu tingkat ke atas untuk mencoba cabang berikutnya[3]. Dalam penerapannya pada pemrograman, DFS menggunakan struktur data stack (tumpukan data), dengan prinsip Last In, First Out (LIFO), artinya elemen yang terakhir dimasukkan ke dalam tumpukan akan menjadi elemen pertama yang dikeluarkan[3].

Breadth-First Search
Algoritma BFS (Breadth-First Search) melakukan pencarian secara melebar, dimulai dari initial state[3]. Data yang dimasukkan terlebih dahulu akan diproses lebih dulu[3]. Dalam implementasinya pada pemrograman, BFS menggunakan struktur data queue (antrian) dengan prinsip First In, First Out (FIFO), artinya elemen yang masuk terlebih dahulu akan keluar lebih dulu[3].
## Guided 

#### graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    bool visited;
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct Graph {
    adrNode first;
};

//Prototypes
void createGraph(Graph &G);
adrNode allocateNode(infoGraph X);
void insertNode(Graph &G, infoGraph X);
void connectNode(Graph &G, infoGraph start, infoGraph end);
void printGraph(Graph G);
#endif
```
#### graph_edge.cpp
```C++
#include "graph.h"

adrNode findNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void connectNode(Graph &G, infoGraph start, infoGraph end) {
    adrNode pStart = findNode(G, start);
    adrNode pEnd = findNode(G, end);
    if (pStart != NULL && pEnd != NULL) {
        adrEdge newEdge = new ElmEdge;
        newEdge->node = pEnd;
        newEdge->next = pStart->firstEdge;
        // Insert First di list edge
        pStart->firstEdge = newEdge;
    }
}
```
#### graph_init.cpp
```C++
#include "graph.h"

void createGraph(Graph &G) {
    G.first = NULL;
}
adrNode allocateNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = false;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

void insertNode(Graph &G, infoGraph X) {
    adrNode P = allocateNode(X);
    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}
```
#### graph_print.cpp
```C++
#include "graph.h"

void printGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << " terhubung ke: ";
        adrEdge E = P->firstEdge;
        if (E == NULL) {
            cout << "None";
        } else {
            while (E != NULL) {
                cout << E->node->info << " ";
                E = E->next;
            }
        }
        cout << endl;
        P = P->next;
    }
}
```
#### main.cpp
```C++
#include <iostream>
#include "graph.h"
using namespace std;

int main() {
    Graph G;
    createGraph(G);

    // Menambahkan Node A, B, C, D
    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');

    // Menghubungkan Node
    connectNode(G, 'A', 'B');
    connectNode(G, 'A', 'C');
    connectNode(G, 'B', 'D');
    connectNode(G, 'C', 'D');

    // Print the graph
    cout << "Isi Graph:" << endl;
    printGraph(G);

    return 0;
}
```
Program akan membuat suatu graf kemudian mencetak isi graf.

## Unguided

### 1. Buatlah ADT Graph tidak berarah file "graph.h":
![Screenshot Soal Unguided 1_1](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan12_Modul14/SoalU1.png)
#### graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
adrNode InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);

#endif
```
#### graph.cpp
```C++
#include "graph.h"
#include <stack>
#include <queue>

void CreateGraph(Graph &G) {
    G.first = NULL;
}

adrNode InsertNode(Graph &G, infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->next = NULL;

    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->next != NULL)
            Q = Q->next;
        Q->next = P;
    }
    return P;
}

void ConnectNode(adrNode N1, adrNode N2) {
    adrEdge E1 = new ElmEdge;
    E1->node = N2;
    E1->next = N1->firstEdge;
    N1->firstEdge = E1;

    adrEdge E2 = new ElmEdge;
    E2->node = N1;
    E2->next = N2->firstEdge;
    N2->firstEdge = E2;
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << P->info << " : ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}
```
#### main.cpp
```C++
#include "graph.h"

int main() {
    Graph G;
    CreateGraph(G);

    adrNode A = InsertNode(G, 'A');
    adrNode B = InsertNode(G, 'B');
    adrNode C = InsertNode(G, 'C');
    adrNode D = InsertNode(G, 'D');
    adrNode E = InsertNode(G, 'E');
    adrNode F = InsertNode(G, 'F');
    adrNode Gg = InsertNode(G, 'G');
    adrNode H = InsertNode(G, 'H');

    ConnectNode(A, B);
    ConnectNode(A, C);
    ConnectNode(B, D);
    ConnectNode(B, E);
    ConnectNode(C, F);
    ConnectNode(C, Gg);
    ConnectNode(D, H);
    ConnectNode(E, H);
    ConnectNode(F, H);
    ConnectNode(Gg, H);

    cout << "Adjacency List:" << endl;
    PrintInfoGraph(G);
    return 0;
}
```
### Output Unguided 1
![Screenshot Output Unguided 1_1](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan12_Modul14/OutputU1.png)

Program akan membuat graf tak berarah. Program akan mencetak daftar ketetanggaan tiap node.

### Unguided 2

#### graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
adrNode InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);

void PrintDFS(Graph G, adrNode start);

#endif
```
#### graph.cpp
```C++
#include "graph.h"
#include <stack>
#include <queue>

void CreateGraph(Graph &G) {
    G.first = NULL;
}

adrNode InsertNode(Graph &G, infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->next = NULL;

    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->next != NULL)
            Q = Q->next;
        Q->next = P;
    }
    return P;
}

void ConnectNode(adrNode N1, adrNode N2) {
    adrEdge E1 = new ElmEdge;
    E1->node = N2;
    E1->next = N1->firstEdge;
    N1->firstEdge = E1;

    adrEdge E2 = new ElmEdge;
    E2->node = N1;
    E2->next = N2->firstEdge;
    N2->firstEdge = E2;
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << P->info << " : ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

void PrintDFS(Graph G, adrNode start) {
    stack<adrNode> S;
    S.push(start);

    while (!S.empty()) {
        adrNode x = S.top();
        S.pop();

        if (x->visited == 0) {
            x->visited = 1;
            cout << x->info << " ";

            adrEdge E = x->firstEdge;
            while (E != NULL) {
                if (E->node->visited == 0) {
                    S.push(E->node);
                }
                E = E->next;
            }
        }
    }
}
```
#### main.cpp
```C++
#include "graph.h"

int main() {
    Graph G;
    CreateGraph(G);

    adrNode A = InsertNode(G, 'A');
    adrNode B = InsertNode(G, 'B');
    adrNode C = InsertNode(G, 'C');
    adrNode D = InsertNode(G, 'D');
    adrNode E = InsertNode(G, 'E');
    adrNode F = InsertNode(G, 'F');
    adrNode Gg = InsertNode(G, 'G');
    adrNode H = InsertNode(G, 'H');

    ConnectNode(A, B);
    ConnectNode(A, C);
    ConnectNode(B, D);
    ConnectNode(B, E);
    ConnectNode(C, F);
    ConnectNode(C, Gg);
    ConnectNode(D, H);
    ConnectNode(E, H);
    ConnectNode(F, H);
    ConnectNode(Gg, H);

    cout << "Adjacency List:" << endl;
    PrintInfoGraph(G);

    cout << "\nDFS dari A: ";
    PrintDFS(G, A);

    return 0;
}
```

### Output Unguided 2
![Screenshot Output Unguided 2_1](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan12_Modul14/OutputU2.png)

Fitur DFS ditambahkan, program akan melakukan print DFS.

### Unguided 3

#### graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
adrNode InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);

void PrintDFS(Graph G, adrNode start);
void PrintBFS(Graph G, adrNode start);

#endif
```
#### graph.cpp
```C++
#include "graph.h"
#include <stack>
#include <queue>

void CreateGraph(Graph &G) {
    G.first = NULL;
}

adrNode InsertNode(Graph &G, infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->next = NULL;

    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->next != NULL)
            Q = Q->next;
        Q->next = P;
    }
    return P;
}

void ConnectNode(adrNode N1, adrNode N2) {
    adrEdge E1 = new ElmEdge;
    E1->node = N2;
    E1->next = N1->firstEdge;
    N1->firstEdge = E1;

    adrEdge E2 = new ElmEdge;
    E2->node = N1;
    E2->next = N2->firstEdge;
    N2->firstEdge = E2;
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << P->info << " : ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

void PrintDFS(Graph G, adrNode start) {
    stack<adrNode> S;
    S.push(start);

    while (!S.empty()) {
        adrNode x = S.top();
        S.pop();

        if (x->visited == 0) {
            x->visited = 1;
            cout << x->info << " ";

            adrEdge E = x->firstEdge;
            while (E != NULL) {
                if (E->node->visited == 0) {
                    S.push(E->node);
                }
                E = E->next;
            }
        }
    }
}

void PrintBFS(Graph G, adrNode start) {
    queue<adrNode> Q;
    Q.push(start);

    while (!Q.empty()) {
        adrNode x = Q.front();
        Q.pop();

        if (x->visited == 0) {
            x->visited = 1;
            cout << x->info << " ";

            adrEdge E = x->firstEdge;
            while (E != NULL) {
                if (E->node->visited == 0) {
                    Q.push(E->node);
                }
                E = E->next;
            }
        }
    }
}
```
#### main.cpp
```C++
#include "graph.h"

int main() {
    Graph G;
    CreateGraph(G);

    adrNode A = InsertNode(G, 'A');
    adrNode B = InsertNode(G, 'B');
    adrNode C = InsertNode(G, 'C');
    adrNode D = InsertNode(G, 'D');
    adrNode E = InsertNode(G, 'E');
    adrNode F = InsertNode(G, 'F');
    adrNode Gg = InsertNode(G, 'G');
    adrNode H = InsertNode(G, 'H');

    ConnectNode(A, B);
    ConnectNode(A, C);
    ConnectNode(B, D);
    ConnectNode(B, E);
    ConnectNode(C, F);
    ConnectNode(C, Gg);
    ConnectNode(D, H);
    ConnectNode(E, H);
    ConnectNode(F, H);
    ConnectNode(Gg, H);

    cout << "Adjacency List:" << endl;
    PrintInfoGraph(G);

    cout << "\nDFS dari A: ";
    PrintDFS(G, A);

    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->next;
    }

    cout << "\nBFS dari A: ";
    PrintBFS(G, A);

    return 0;
}
```

### Output Unguided 3
![Screenshot Output Unguided 1_1](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan12_Modul14/OutputU3.png)

Fitur BFS ditambahkan, program akan melakukan print BFS.

## Kesimpulan
Dalam struktur data, graph berfungsi sebagai cara untuk mengaitkan satu informasi dengan informasi lain[1]. Graf memiliki sifat menjaga konsistensi, sehingga informasi yang tersimpan dapat dikembalikan ke bentuk permasalahan awal tanpa mengurangi akurasi data sebelum disimpan dalam graf[1]. DFS menelusuri jalur lebih dalam terlebih dahulu, kembali satu tingkat saat menemui jalan buntu, dan menggunakan struktur data stack dengan prinsip Last In, First Out (LIFO)[3]. Sedangkan BFS menelusuri graf secara melebar, memproses elemen yang masuk lebih dulu menggunakan queue dengan prinsip First In, First Out (FIFO).[3]

## Referensi
[1] Anggara, F. D. (2009). Studi dan Implementasi Struktur Data Graf. Jurnal Sekolah Teknik Elektro dan Informatika Institut Teknologi Bandung, Bandung.
<br/> [2] Himawan, B., Maulana, D., Amelia, V., & Hidayat, T. (2008). Implementasi Graf dalam Penyimpanan Data Struktur Bangunan. In Seminar Nasional Aplikasi Teknologi Informasi (SNATI).
<br/> [3] Yuliana, Y., Noviyanti, N., & Qulub, M. (2024). IMPLEMENTASI ALGORITMA DEPTH-FIRST SEARCH DAN BREADTH-FIRST SEARCH PADA DOKUMEN AKREDITASI. JOURNAL OF SCIENCE AND SOCIAL RESEARCH, 7(1), 197-204.