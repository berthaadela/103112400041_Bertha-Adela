# <h1 align="center">Laporan Praktikum Modul 7 - STACK</h1>
<p align="center">Bertha Adela - 103112400041</p>

## Dasar Teori
Konsep stack menerapkan LIFO (Last In, First Out) dimana elemen paling terakhir dimasukkan adalah elemen yang dihapus terlebih dahulu[1]. Stack digunakan dalam banyak jenis aplikasi, termasuk menghitung ekspresi, mengatur penggunaan memori, dan menjalankan fungsi secara rekursi [2].

Beberapa operasi fundamentalnya:
1. Push (Menambah Data)
Fungsi: Menempatkan elemen baru ke bagian paling atas dari stack.
Kondisi Error: Jika stack sudah penuh (stack overflow), operasi push tidak dapat dilakukan.
Contoh:
stack.push(5)   # Stack menjadi [5]
stack.push(10)  # Stack menjadi [5, 10]

2. Pop (Menghapus Data)
Fungsi: Mengambil dan menghapus elemen yang berada di posisi paling atas stack, lalu mengembalikan nilainya.
Kondisi Error: Jika stack kosong (stack underflow), operasi pop gagal dilakukan.
Contoh:
stack.pop()  # Mengembalikan 10, stack berubah menjadi [5]

3. Peek / Top (Melihat Elemen Teratas)
Fungsi: Menampilkan nilai elemen paling atas tanpa menghapusnya dari stack.
Kondisi Error: Jika stack kosong, operasi peek menghasilkan nilai kosong (null) atau error.
Contoh:
stack.peek()  # Mengembalikan 5 (stack tetap [5])

4. isEmpty (Memeriksa Apakah Stack Kosong)
Fungsi: Mengecek apakah stack tidak memiliki elemen.
Hasil:
True → jika stack kosong
False → jika masih ada elemen di dalamnya
Contoh:
stack.is_empty()  # False (karena masih ada elemen [5])

5. isFull (Memeriksa Apakah Stack Penuh)
Fungsi: Mengecek apakah stack telah mencapai kapasitas maksimum (khusus implementasi stack berbasis array).
Hasil:
True → jika stack penuh
False → jika masih tersedia ruang

## Guided 

### 1. Guided 1
#### stack.h
```C++
#ifndef STACK_H
#define STACK_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef struct node *address;

struct node {
    int dataAngka;
    address next;
};

struct stack {
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);
void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack &listStack);
void searchData(stack &listStack, int data);

#endif
```
#### stack.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
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

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        int data = nodeHapus->dataAngka;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  data << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi <= 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
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

void view(stack listStack){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
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
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```
#### main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```
Program ini membuat struktur data stack menggunakan linked list, data disimpan dalam node-node yang saling terhubung.

### 2. Guided 2

#### stack.h
```C++
#ifndef STACK_H

#include <iostream>
#define MaxEl 20
#define Nil -1

typedef int infotype;

struct Stack {
    infotype info[MaxEl];
    int top;
};

void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif
```
#### stack.cpp
```C++
#include "stack.h"
using namespace std;

void CreateStack(Stack &S) {
    S.top = Nil;
}

bool isEmpty(Stack S) {
    return S.top == Nil;
}

bool isFull(Stack S) {
    return S.top == MaxEl - 1;
}

void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack Penuh!" << endl;
    }
}

infotype pop(Stack &S) {
    infotype x = -999;
    if (!isEmpty(S)) {
        x = S.info[S.top];
        S.top--;
    } else {
        cout << "Stack Kosong!" << endl;
    }
    return x;
}


void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack Kosong" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    if (!isEmpty(S)) {
        Stack temp1, temp2;
        CreateStack(temp1); CreateStack(temp2);
        while (!isEmpty(S)) { push(temp1, pop(S)); }
        while (!isEmpty(temp1)) { push(temp2, pop(temp1)); }
        while (!isEmpty(temp2)) { push(S, pop(temp2)); }
    }
}
```
#### main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    Stack S;
    CreateStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    cout << "Stack Awal:" << endl;
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    cout << "Stack Setelah dibalik:" << endl;
    printInfo(S);

    return 0;
}
```
Program ini membuat sebuah stack (tumpukan) menggunakan array, lalu melakukan beberapa operasi dasar seperti push, pop, menampilkan isi stack, dan membalik urutannya dengan fungsi balikStack().


## Unguided 

### 1. Buatlah ADT Stack menggunakan ARRAY sebagai berikut di dalam file "stack.h":
![Screenshot Soal Unguided 1_1](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan7_Modul7/soal1unguided1.png)
Buatlah implementasi ADT Stack menggunakan Array pada file "stack.cpp" dan "main.cpp"
![Screenshot Soal Unguided 1_2](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan7_Modul7/soal2unguided1.png)
#### stack.h
```C++
#ifndef UNGUIDED1_H
#define UNGUIDED1_H
#include <iostream>
using namespace std;

const int MaxEl = 20;
const int Nil = -1;

typedef int infotype;

struct Stack {
    infotype info[MaxEl];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif

```
#### stack.cpp
```C++
#include "unguided1.h"
#include <iostream>
using namespace std;

void createStack(Stack &S) {
    S.top = Nil;
}

void push(Stack &S, infotype x) {
    if (S.top < MaxEl - 1) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

infotype pop(Stack &S) {
    if (S.top != Nil) {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    } else {
        cout << "Stack kosong!" << endl;
        return Nil;
    }
}

void printInfo(Stack S) {
    if (S.top == Nil) {
        cout << "Stack kosong" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    Stack temp1, temp2;
    createStack(temp1);
    createStack(temp2);

    while (S.top != Nil) {
        push(temp1, pop(S));
    }

    while (temp1.top != Nil) {
        push(temp2, pop(temp1));
    }

    while (temp2.top != Nil) {
        push(S, pop(temp2));
    }
}

```
#### main.cpp
```C++
#include "unguided1.h"
#include <iostream>
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    push(S,3);
    push(S,4);
    push(S,8);
    pop(S);
    push(S,2);
    push(S,3);
    pop(S);
    push(S,9);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```

### Output Unguided 1 :

![Screenshot Output Unguided 1_1](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan7_Modul7/outputunguided1.png)

Program ini menambah elemen(push), menghapus elemen(pop), menampilkan isi stack(printInfo), kemudian membalik urutan elemen dalam stack(balikStack).

### 2. Tambahkan prosedur pushAscending( in/out S : Stack, in x : integer)
![Screenshot Soal Unguided 2_1](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan7_Modul7/soal1unguided2.png)
#### stack.h
```C++
#ifndef UNGUIDED2_H
#define UNGUIDED2_H
#include <iostream>
using namespace std;

const int MaxEl = 20;
const int Nil = -1;

typedef int infotype;

struct Stack {
    infotype info[MaxEl];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);
bool isEmpty(Stack S);
bool isFull(Stack S);

#endif

```
#### stack.cpp
```C++
#include "unguided2.h"
#include <iostream>
using namespace std;

void createStack(Stack &S) {
    S.top = Nil;
}

void push(Stack &S, infotype x) {
    if (S.top < MaxEl - 1) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

infotype pop(Stack &S) {
    if (S.top != Nil) {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    } else {
        cout << "Stack kosong!" << endl;
        return Nil;
    }
}

void printInfo(Stack S) {
    if (S.top == Nil) {
        cout << "Stack kosong" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    Stack temp1, temp2;
    createStack(temp1);
    createStack(temp2);

    while (S.top != Nil) {
        push(temp1, pop(S));
    }

    while (temp1.top != Nil) {
        push(temp2, pop(temp1));
    }

    while (temp2.top != Nil) {
        push(S, pop(temp2));
    }
}

bool isEmpty(Stack S) {
    return S.top == Nil;
}

bool isFull(Stack S) {
    return S.top == MaxEl - 1;
}

void pushAscending(Stack &S, infotype x) {
    Stack temp;
    createStack(temp);

    while (!isEmpty(S) && S.info[S.top] > x) {
        push(temp, pop(S));
    }

    push(S, x);

    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }
}

```
#### main.cpp
```C++
#include "unguided2.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    pushAscending(S,3);
    pushAscending(S,4);
    pushAscending(S,8);
    pushAscending(S,2);
    pushAscending(S,3);
    pushAscending(S,9);
    printInfo(S);
    cout << "balik stack" <<endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan7_Modul7/outputunguided2.png)


Program ini memasukkan elemen ke stack, kemudian mengurutkan elemen elemen secara ascending.

### 3. Tambahkan prosedur getInputStream( in/out S : Stack ). Prosedur akan terus membaca dan menerima input user dan memasukkan setiap input ke dalam stack hingga user menekan tombol enter. Contoh: gunakan cin.get() untuk mendapatkan inputan user.
![Screenshot Soal Unguided 3_1](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan7_Modul7/soal1unguided3.png)

#### stack.h
```C++
#ifndef UNGUIDED3_H
#define UNGUIDED3_H
#include <iostream>
using namespace std;

const int MaxEl = 20;
const int Nil = -1;

typedef int infotype;

struct Stack {
    infotype info[MaxEl];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);
bool isEmpty(Stack S);
bool isFull(Stack S);
void getInputStream(Stack &S);
#endif

```
#### stack.cpp
```C++
#include "unguided3.h"
#include <iostream>
using namespace std;

void createStack(Stack &S) {
    S.top = Nil;
}

void push(Stack &S, infotype x) {
    if (S.top < MaxEl - 1) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

infotype pop(Stack &S) {
    if (S.top != Nil) {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    } else {
        cout << "Stack kosong!" << endl;
        return Nil;
    }
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i];

            if (i > 0) cout << " ";
        }
        cout << endl;
    }
}


void balikStack(Stack &S) {
    Stack temp1, temp2;
    createStack(temp1);
    createStack(temp2);

    while (S.top != Nil) {
        push(temp1, pop(S));
    }

    while (temp1.top != Nil) {
        push(temp2, pop(temp1));
    }

    while (temp2.top != Nil) {
        push(S, pop(temp2));
    }
}

bool isEmpty(Stack S) {
    return S.top == Nil;
}

bool isFull(Stack S) {
    return S.top == MaxEl - 1;
}

void pushAscending(Stack &S, infotype x) {
    Stack temp;
    createStack(temp);
    while (!isEmpty(S) && S.info[S.top] > x) {
        push(temp, pop(S));
    }
    push(S, x);
    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }
}

void getInputStream(Stack &S) {
    cout << "Masukkan karakter (ENTER untuk berhenti): ";

    char c;

    while (true) {
        c = cin.get();
        if (c == '\n') {
            break;
        }
        if (c >= '0' && c <= '9') {
            int angka = c - '0';
            push(S, angka);
        }
    }
}

```
#### main.cpp
```C++
#include "unguided3.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    getInputStream(S);
    printInfo(S);
    cout<< "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```
### Output Unguided 3 :

![Screenshot Output Unguided 3_1](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan7_Modul7/outputunguided3.png)

Program ini membaca karakter satu per satu dari keyboard.

## Kesimpulan
Stack merupakan struktur data yang bekerja dengan prinsip LIFO, yaitu elemen yang terakhir masuk akan menjadi elemen pertama yang dikeluarkan. Struktur ini banyak dipakai pada berbagai proses komputasi seperti evaluasi ekspresi, pengelolaan memori, hingga pemanggilan fungsi secara rekursif. Dalam penggunaannya, stack memiliki beberapa operasi dasar, seperti push untuk menambah elemen ke bagian atas, pop untuk mengambil elemen teratas, serta peek untuk melihat elemen tersebut tanpa menghapusnya. Selain itu, terdapat juga pengecekan kondisi melalui isEmpty untuk mengetahui apakah stack kosong dan isFull untuk memastikan apakah kapasitas stack sudah terisi penuh. Kelima operasi ini menjadi dasar agar stack dapat bekerja dengan baik dan mencegah terjadinya kesalahan seperti overflow atau underflow.

## Referensi
[1] Amaylia, S., Salamah, S., & Ru'iya, H. (2022). Application of stack data structure. Journal of Applied Smart Information Systems (JASIC), 3(2), 110-117.
<br/> [2] Setiyawan, R. D., Hermawan, D., Abdillah, A. F., Mujayanah, A., & Vindua, R. (2024). Penggunaan struktur data stack dalam pemrograman C++ dengan pendekatan array dan linked list. JUTECH: Journal of Education and Technology, 5(2), 484-498. https://doi.org/10.31932/jutech.v5i2.4263