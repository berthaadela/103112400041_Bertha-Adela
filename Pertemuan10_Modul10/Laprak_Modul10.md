# <h1 align="center">Laporan Praktikum Modul 10 - TREE (BAGIAN PERTAMA)</h1>
<p align="center">Bertha Adela - 103112400041</p>

## Dasar Teori
Tree adalah struktur data yang saling terhubung antar node-node (simpul) oleh garis penghubung yang dinamakan edge (cabang). Node paling atas adalah root (akar) dan node yang tidak memiliki anak disebut leaf (daun). Setiap node bisa memiliki lebih dari satu node turunan yang membentuk subtree dan terhubung langsung lewat cabang tersebut. Struktur data tree sangat bermanfaat dalam berbagai bidang, misalnya untuk menggambarkan hierarki organisasi, mengolah dan menyimpan kumpulan kata, serta menjadi dasar bagi struktur data lanjutan seperti heap dan set asosiatif. Di lain sisi, tree juga sering digunakan dalam banyak algoritma yang memerlukan pengelompokan data secara hierarkis [1].

Sebuah tree memiliki beberapa istilah penting [2]:
Node (Simpul): Setiap elemen data dalam tree direpresentasikan sebagai sebuah node.
Root Node (Simpul Akar): Node yang berada di posisi paling atas dalam tree disebut root.
Internal / Non-Terminal Node: Node yang bukan root tetapi memiliki minimal satu anak disebut node internal atau non-terminal.
External / Terminal / Leaf Node: Node yang tidak memiliki anak disebut node eksternal atau leaf (daun).
Degree of a Node (Derajat Node): Derajat suatu node menunjukkan berapa banyak subtree atau anak yang dimiliki node tersebut.
Siblings (Saudara Kandung Node): Node-node yang memiliki induk (ancestor) yang sama disebut siblings atau saudara.
Level (Tingkat): Setiap node dalam tree berada pada tingkat tertentu. Root selalu berada pada level 0, anak-anaknya berada di level 1, cucunya di level 2, dan seterusnya hingga level terdalam dalam tree.
Path (Jalur): Path adalah urutan edge (cabang) yang tersambung dari node asal menuju node tujuan.
Depth/Height (Kedalaman/Tinggi Tree): Jumlah level atau level maksimum yang dimiliki sebuah tree disebut kedalaman atau tinggi tree.
Branch (Cabang): Bagian akhir dari tree yang berujung pada leaf node disebut cabang.

Berbagai jenis algoritma dapat digunakan untuk melakukan penelusuran pada struktur tree. Beberapa di antaranya adalah preorder traversal, inorder traversal, dan postorder traversal[2].

Pre-order traversal: dimulai dari node akar dan dilanjut ke node berikutnya sesuai urutan kunjungannya[3].
Inorder traversal: subtree kiri dikunjungi terlebih dahulu, node akar diproses, lalu subtree kanan ditelusuri[4].
Postorder traversal: node anak dikunjungi terlebih dahulu sebelum node induknya, jika terdapat beberapa anak (siblings), maka anak-anaknya akan ditelusuri dari kiri ke kanan [5].

## Guided 

### 1. Guided 1 - Rekursif Pangkat 2
```C++
#include <iostream>
using namespace std;

int pangkat_2(int x) {
    if (x == 0) {
        return 1;
    } else if (x > 0) {
        return 2 * pangkat_2(x - 1);
    }
}

int main() {
    cout << "=== REKURSIF PANGKAT 2 ===" << endl;
    int x;
    cout << "masukkan nilai x: ";
    cin >> x;
    cout << "pangkat 2 dari " << x << " adalah : " << pangkat_2(x);

    return 0;
}
```
Program ini mengulas kembali logika pada penerapan rekursif pangkat 2.

### 2. Guided 2 - BST1
#### BST1.h
```C++
#ifndef BST1_H
#define BST1_H
#include <iostream>
using namespace std;

typedef int infotype;
typedef struct Node*address;
struct Node{
    infotype info;
    address left;
    address right;
};
bool isEmpty(address root);
void createTree(address &root); //function untuk membuAt BST nya (root direset)
//Alokasi&Insert
address newNode(infotype x); //function untuk memasukkan data (infotype) kedalam node
address insertNode(address root, infotype x); // function untuk memasukkan node kedalam BST

//Traversal
void preOrder(address root); //traversal preOrder
void inOrder(address root); //traversal inOrder
void postOrder(address root); //traversal postOrder

//Utilities
int countNodes(address root); //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
int treeDepth(address root); //function untuk menghitung height atau kedalaman atau level tree

#endif
```
#### BST1.cpp
```C++
#include "BST1.h"
#include <iostream>

using namespace std;

//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}
```
#### main.cpp
```C++
#include <iostream>
#include "BST1.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "Binary Search Tree Insert & Traversal" << endl;
    cout << endl;

    root = insertNode(root, 20); // Root awal
    insertNode(root, 10);
    insertNode(root, 35);
    insertNode(root, 5);
    insertNode(root, 18);
    insertNode(root, 40);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << "Hasil PreOrder Traversal : ";
    preOrder(root);
    cout << endl;

    cout << "Hasil PostOrder Traversal : ";
    postOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;


    return 0;
}
```
Program ini menjelaskan penerapan tree, memasukkan angka2 sehingga terbentuk pencabangan node, menerapkan metode penelurusan pre order; inorder; serta postorder, menghitung jumlah node, dan menghitung kedalaman tree.

### 3. Guided 3 - BST2
#### BST2.h
```C++
#ifndef BST1_H
#define BST1_H
#include <iostream>
using namespace std;

typedef int infotype;
typedef struct Node*address;
struct Node{
    infotype info;
    address left;
    address right;
};
bool isEmpty(address root);
void createTree(address &root); //function untuk membuAt BST nya (root direset)
//Alokasi&Insert
address newNode(infotype x); //function untuk memasukkan data (infotype) kedalam node
address insertNode(address root, infotype x); // function untuk memasukkan node kedalam BST

//Traversal
void preOrder(address root); //traversal preOrder
void inOrder(address root); //traversal inOrder
void postOrder(address root); //traversal postOrder

//Utilities
int countNodes(address root); //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
int treeDepth(address root); //function untuk menghitung height atau kedalaman atau level tree

//FUNCTION & PROSEDUR BARU
//searching
void searchByData(address root, infotype x); //function untuk melakukan searching data tertentu
//mostLeft & mostRight
address mostLeft(address root); //function untuk menampilkan mostLeft atau node paling kiri
                                //node dengan nilai terkecil
address mostRight(address root);//function untuk menampilkan mostRight atau node paling kanan
                                //node dengan nilai terbesar
//delete
bool deleteNode(address &root, infotype x); //function untuk menghapus node tertentu didalam BST
                                
void deleteTree(address &root); //prosedur untuk menghapus BST

#endif
```
#### BST2.cpp
```C++
#include "BST2.h"
#include <iostream>

using namespace std;

//FUNCTION & PROSEDUR SEBELUMNYA
//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}


//FUNCTION & PROSEDUR BARU
//searching
void searchByData(address root, infotype x) { //function untuk melakukan searching data tertentu
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        address nodeBantu = root;
        address parent = NULL;
        bool ketemu = false;
        while(nodeBantu != NULL){
            if(x < nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(x > nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(x == nodeBantu->info){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam BST!" << endl;
            cout << "Data Angka : " << nodeBantu->info << endl;

            //menampilkan parentnya & pengecekan sibling
            address sibling = NULL;
            if(parent != NULL){
                cout << "Parent : " << parent->info << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != NULL){
                cout << "Sibling : " << sibling->info << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != NULL){
                cout << "Child kiri : " << nodeBantu->left->info << endl;
            } else if(nodeBantu->left == NULL){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != NULL){
                cout << "Child kanan : " << nodeBantu->right->info << endl;
            } else if(nodeBantu->right == NULL){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}


//mostleft & mostright
address mostLeft(address root) { //function untuk menampilkan mostleft atau node paling kiri (node dengan nilai terkecil) didalam BST
    while (root->left != NULL){
        root = root->left;
    }
    return root;
}

address mostRight(address root) { //function untuk menampilkan mostright atau node paling kanan (node dengan nilai terbesar) didalam BST
    while (root->right != NULL){
        root = root->right;
    }
    return root;
}


//delete
bool deleteNode(address &root, infotype x) { //function untuk menghapus node tertentu didalam BST (menghapus berdasarkan parameter infotype)
    if (root == NULL) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (x < root->info) {
            return deleteNode(root->left, x);
        } else if (x > root->info) {
            return deleteNode(root->right, x);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (root->left == NULL && root->right == NULL) {
                address temp = root;
                root = NULL;
                delete temp;
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (root->left == NULL) {
                address temp = root;
                root = root->right;
                delete temp;
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (root->right == NULL) {
                address temp = root;
                root = root->left;
                delete temp;
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                address successor = mostLeft(root->right);
                //salin data successor ke node saat ini
                root->info = successor->info;
                //hapus successor pada subtree kanan
                return deleteNode(root->right, successor->info);
            }
            return true; //berhasil dihapus
        }
    }
}

void deleteTree(address &root) { //prosedur untuk menghapus BST (menghapus seluruh node BST)
    if(root == NULL){
        return;
    } else {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = NULL;
    }
}
```
#### main.cpp
```C++
#include <iostream>
#include "BST2.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "=== Binary Search Tree ==" << endl;
    cout << endl;

    root = insertNode(root, 30); // Root awal
    insertNode(root, 15);
    insertNode(root, 35);
    insertNode(root, 11);
    insertNode(root, 17);
    insertNode(root, 20);
    insertNode(root, 38);
    insertNode(root, 16);
    insertNode(root, 22);
    insertNode(root, 33);
    insertNode(root, 18);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;

    cout << endl;
    searchByData(root, 17);
    
    cout << endl;
    cout << "Node mostleft : " << mostLeft(root)->info << endl;
    cout << "Node mostright : " << mostRight(root)->info << endl;

    cout << endl;
    infotype angkaHapus;
    cout << "Masukkan angka yang ingin dihapus: ";
    cin >> angkaHapus;
    //misal angka yang dihapus adalah angka 17
    if(deleteNode(root, angkaHapus)){
        cout << "Data " << angkaHapus << " berhasil dihapus!" << endl;
    } else {
        cout << "Data " << angkaHapus << " tidak ditemukan!" << endl;
    }
    cout << endl;

    searchByData(root, 17);
    cout << endl;
    searchByData(root, 18);

    cout << endl;
    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    deleteTree(root);
    cout << "Seluruh tree berhasil dihapus!" << endl;

    cout << endl;
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        cout << "Hasil InOrder Traversal : ";
        inOrder(root);
    }

    return 0;
}
```
Program ini menambahkan fungsi pencarian dan fungsi menghapus dari program sebelumnya.


## Unguided 

### 1. Unguided 1
![Screenshot Soal Unguided 1_1](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan10_Modul10/soalunguided1.png)
#### bstree.h
```C++
#ifndef TREE_H
#define TREE_H
#define Nil nullptr
typedef int infotype;
struct Node;
typedef Node* address;

struct Node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void printInorder(address root);
#endif

```
#### bstree.cpp
```C++
#include "bstree.h"
#include <iostream>

using namespace std;

address alokasi(infotype x) {
    address P = new Node;
    P->info = x;
    P->left = Nil;
    P->right = Nil;
    return P;
}
void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } else {
        if (x < root->info) {
            insertNode(root->left, x);
        } else if (x > root->info) {
            insertNode(root->right, x);
        }
    }
}
address findNode(infotype x, address root) {
    if (root == Nil) {
        return Nil;
    } else {
        if (x == root->info) {
            return root;
        } else if (x < root->info) {
            return findNode(x, root->left);
        } else {
            return findNode(x, root->right);
        }
    }
}
void printInorder(address root) {
    if (root != Nil) {
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}

```
#### main.cpp
```C++
#include <iostream>
#include "bstree.h"
using namespace std;
int main() {
    cout << "Hello World" << endl;
    address root = Nil;
    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6);
    insertNode(root,7);
    printInorder(root);
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan10_Modul10/outputunguided1.png)

Program ini akan membuat suatu tree dan langsung diurutkan secara inorder sehingga menghasilkan tree 1 - 2 - 3 - 4 - 5 - 6 - 7 - .

### 2. Unguided 2
Buatlah fungsi untuk menghitung jumlah node dengan fungsi berikut.
➢ fungsi hitungJumlahNode( root:address ) : integer
/* fungsi mengembalikan integer banyak node yang ada di dalam BST*/
➢ fungsi hitungTotalInfo( root:address, start:integer ) : integer
/* fungsi mengembalikan jumlah (total) info dari node-node yang ada di dalam BST*/
➢ fungsi hitungKedalaman( root:address, start:integer ) : integer
/* fungsi rekursif mengembalikan integer kedalaman maksimal dari binary tree */
![Screenshot Soal Unguided 2_1](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan10_Modul10/soalunguided2.png)

#### bstree.h
```C++
#ifndef TREE_H
#define TREE_H
#define Nil nullptr
typedef int infotype;
struct Node;
typedef Node* address;

struct Node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void printInorder(address root);
int hitungJumlahNode(address root);
int hitungTotalInfo(address root);
int hitungKedalaman(address root, int start);
#endif
```
#### bstree.cpp
```C++
#include "bstree.h"
#include <iostream>

using namespace std;

address alokasi(infotype x) {
    address P = new Node;
    P->info = x;
    P->left = Nil;
    P->right = Nil;
    return P;
}
void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } else {
        if (x < root->info) {
            insertNode(root->left, x);
        } else if (x > root->info) {
            insertNode(root->right, x);
        }
    }
}
address findNode(infotype x, address root) {
    if (root == Nil) {
        return Nil;
    } else {
        if (x == root->info) {
            return root;
        } else if (x < root->info) {
            return findNode(x, root->left);
        } else {
            return findNode(x, root->right);
        }
    }
}
void printInorder(address root) {
    if (root != Nil) {
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}
int hitungJumlahNode(address root) {
    if (root == Nil) {
        return 0;
    } else {
        return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
    }
}
int hitungTotalInfo(address root) {
    if (root == Nil) {
        return 0;
    } else {
        return root->info + hitungTotalInfo(root->left) + hitungTotalInfo(root->right);
    }
}
int hitungKedalaman(address root, int start) {
    if (root == Nil) {
        return start - 1;
    } else {
        int leftDepth = hitungKedalaman(root->left, start + 1);
        int rightDepth = hitungKedalaman(root->right, start + 1);
        return (leftDepth > rightDepth) ? leftDepth : rightDepth;
    }
}
```
#### main.cpp
```C++
#include <iostream>
#include "bstree.h"
using namespace std;
int main() {
    cout << "Hello World" << endl;
    address root = Nil;
    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6);
    insertNode(root,7);
    printInorder(root);
    cout<<"\n";
    cout<<"kedalaman : "<<hitungKedalaman(root,0)<<endl;
    cout<<"jumlah Node : "<<hitungJumlahNode(root)<<endl;
    cout<<"total : "<<hitungTotalInfo(root)<<endl;
    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan10_Modul10/outputunguided2.png)

Program ini akan menampilkan kedalaman tree, jumlah node, dan total informasi di setiap node pada tree.

### 3. Unguided 3
Print tree secara pre-order dan post-order.
#### bstree.h
```C++
#ifndef TREE_H
#define TREE_H
#define Nil nullptr
typedef int infotype;
struct Node;
typedef Node* address;

struct Node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void printInorder(address root);
void printPreorder(address root);
void printPostorder(address root);
int hitungJumlahNode(address root);
int hitungTotalInfo(address root);
int hitungKedalaman(address root, int start);
#endif
```
#### bstree.cpp
```C++
#include "bstree.h"
#include <iostream>

using namespace std;

address alokasi(infotype x) {
    address P = new Node;
    P->info = x;
    P->left = Nil;
    P->right = Nil;
    return P;
}
void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } else {
        if (x < root->info) {
            insertNode(root->left, x);
        } else if (x > root->info) {
            insertNode(root->right, x);
        }
    }
}
address findNode(infotype x, address root) {
    if (root == Nil) {
        return Nil;
    } else {
        if (x == root->info) {
            return root;
        } else if (x < root->info) {
            return findNode(x, root->left);
        } else {
            return findNode(x, root->right);
        }
    }
}
void printInorder(address root) {
    if (root != Nil) {
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}
void printPreorder(address root) {
    if (root != Nil) {
        cout << root->info << " - ";
        printPreorder(root->left);
        printPreorder(root->right);
    }
}
void printPostorder(address root) {
    if (root != Nil) {
        printPostorder(root->left);
        printPostorder(root->right);
        cout << root->info << " - ";
    }
}
int hitungJumlahNode(address root) {
    if (root == Nil) {
        return 0;
    } else {
        return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
    }
}
int hitungTotalInfo(address root) {
    if (root == Nil) {
        return 0;
    } else {
        return root->info + hitungTotalInfo(root->left) + hitungTotalInfo(root->right);
    }
}
int hitungKedalaman(address root, int start) {
    if (root == Nil) {
        return start - 1;
    } else {
        int leftDepth = hitungKedalaman(root->left, start + 1);
        int rightDepth = hitungKedalaman(root->right, start + 1);
        return (leftDepth > rightDepth) ? leftDepth : rightDepth;
    }
}
```
#### main.cpp
```C++
#include <iostream>
#include "bstree.h"
using namespace std;
int main() {
    cout << "Hello World" << endl;
    address root = Nil;
    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6);
    insertNode(root,7);
    
    cout << "Print secara Preorder: ";
    printPreorder(root);
    cout << endl;
    cout << "Print secara Postorder: ";
    printPostorder(root);
    
    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan10_Modul10/outputunguided3.png)

Pada program ini, fungsi main akan menampilkan tree secara preorder dan menampilkan tree secara postorder.

## Kesimpulan
Tree adalah struktur data yang tersusun atas simpul-simpul yang saling terhubung melalui cabang. Setiap simpul memiliki peran dan kedudukannya masing-masing, mulai dari simpul akar, simpul internal, hingga simpul daun sebagai bagian paling akhir. Struktur ini membentuk hubungan hierarkis yang memudahkan pengelompokan data dan banyak dimanfaatkan dalam berbagai bidang komputasi. Beragam istilah seperti level, path, degree, dan height membantu menggambarkan posisi serta hubungan antar simpul di dalam tree. Dalam penerapannya, tree dapat ditelusuri dengan beberapa metode, antara lain preorder, inorder, dan postorder traversal, yang masing-masing memiliki urutan kunjungan berbeda sesuai kebutuhan pengolahan data.

## Referensi
[1] Ginting, S. H. N., Effendi, H., Kumar, S., Marsisno, W., Sitanggang, Y. R. U., Anwar, K., ... & Smrti, N. N. E. (2024). Pengantar struktur data. Penerbit Mifandi Mandiri Digital, 1(01).
<br/> [2] Bala, R., & Dhingra, S. (2018). A review on tree traversal techniques. International Journal of Advanced Research Ideas and Innovations in Technology/4 (3), 2365-3.
<br/> [3] Yonathan, A., Alibasa, M. J., & Riskiana, R. R. (2024). Generating automated test case from sequence diagram using Pre-order Traversal. Procedia Computer Science, 234, 1730-1737.
<br/> [4] Morris, J. M. (1979). Traversing binary trees simply and cheaply. Information Processing Letters, 9(5), 197-200.
<br/> [5] Valiente, G. (2021). Tree Traversal. In Algorithms on Trees and Graphs: With Python Code (pp. 87-111). Cham: Springer International Publishing.