# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Muhammad Dhimas Hafizh Fathurrahman - 2311102151</p>

## Dasar Teori
isi dengan penjelasan dasar teori disertai referensi jurnal (gunakan kurung siku [] untuk pernyataan yang mengambil refernsi dari jurnal).
contoh :
Linked list atau yang disebut juga senarai berantai adalah Salah satu bentuk struktur data yang berisi kumpulan data yang tersusun secara sekuensial, saling bersambungan, dinamis, dan terbatas[1]. Linked list terdiri dari sejumlah node atau simpul yang dihubungkan secara linier dengan bantuan pointer.

### A. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

### B. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

## Guided 

### 1. Aritmatika

```C++
#include <iostream>
using namespace std;

int main() {
    int angka1, angka2;
    cout << "masukkan angka 1 : ";
    cin >> angka1;
    cout << "masukkan angka 2 : ";
    cin >> angka2;

    cout << "penjumlahan : " << angka1 + angka2 << endl;
    cout << "pengurangan : " << angka1 - angka2 << endl;
    cout << "perkalian : " << angka1 * angka2 << endl;
    cout << "pembagian : " << angka1 / angka2 << endl;
    cout << "sisa bagi : " << angka1 % angka2 << endl;

    return 0;
}
```
Guided 1 adalah contoh aritmatika pada penjumlahan, pengurangan, perkalian, pembagian, dan sisa bagi dalam bahasa c++ dengan menginputkan angka pertama dengan angka kedua sebagai objek operasinya.
### 2. Perbandingan

```C++
#include <iostream>
using namespace std;

int main() {
    int angka1, angka2;
    cout << "masukkan angka 1 : ";
    cin >> angka1;
    cout << "masukkan angka 2 : ";
    cin >> angka2;

    if (angka1 < angka2) {
        cout << angka1 << " kurang dari " << angka2 << endl;
    } else {
        cout << angka1 << " lebih dari " << angka2 << endl;
    }


    if (angka1 == angka2) {
        cout << angka1 << " sama dengan " << angka2 << endl;
    } else if (angka1 != angka2){
        cout << " angka berbeda" << endl;
    }

    return 0;
}
```
Guided 2 berfungsi untuk membandingkan antara dua buah input bertipe integer apabila input pertama lebih dari atau kurang dari input kedua serta apabila input pertama sama atau berbeda dengan input kedua. 

### 3. Switch-Case

```C++
#include <iostream>
using namespace std;

int main() {
    int pilihan, angka1, angka2;
    cout << "masukkan angka 1 : ";
    cin >> angka1;
    cout << "masukkan angka 2 : ";
    cin >> angka2;
    
    cout << "MENU" << endl;
    cout << "1.penjumlahan" << endl;
    cout << "2.pengurangan" << endl;
    cout << "masukkan pilihan : ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            cout << "penjumlahan : " << angka1 + angka2 << endl;
            cout << endl;
        break;
        case 2:
            cout << "pengurangan : " << angka1 - angka2 << endl;
            cout << endl;
        break;
        default:
            cout << "pilihan salah" << endl;
    }
    return 0;
}

```
Guided 3 akan melakukan operasi aritmatika penjumlahan atau pengurangan dari kedua input sesuai dengan pilihan, jika memilih selain dari pilihan, maka operasi aritmatika tidak dilakukan kemudian program memberi output "pilihan salah".

### 4. Loop

```C++
#include <iostream>
using namespace std;

int main() {
    int angka1;
    cout << "masukkan angka 1 : ";
    cin >> angka1;

    for(int i = 0; i < angka1; i++) { //increment
        cout << i << " - ";
    }
    cout << endl;

    int j = 20;
    while ( j > angka1) {
        cout << j << " - ";
        j--; //decrement
    }

    cout << endl;
    int k = 10;
    do {
        cout << k << " - ";
    } while (k < angka1);

    return 0;
}
```
Guided 4 menerapkan for loop, while loop, dan do while dalam bahasa c++.

### 5. Array

```C++
#include <iostream>
using namespace std;

int main() {
    const int MAX = 3;
    struct rapot {
        char nama[3];
        float nilai;
    };
    rapot siswa[MAX];

    for(int i=0; i<MAX; i++) {
        cout << "masukkan nama siswa : ";
        cin >> siswa[i].nama;
        cout << "masukkan nilai siswa : ";
        cin >> siswa[i].nilai;
        cout << endl;
    }

    int j = 0;
    while (j < MAX){
        cout << "Nama siswa : " << siswa[j].nama << ", Nilai " << siswa[j].nilai << endl;
        j++;
    }
    return 0;
}
```
Guided 5 berfungsi untuk menyimpan nama dan nilai siswa untuk 3 siswa dalam bahasa c++.

## Unguided 

### 1. Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.

```C++
#include <iostream>
using namespace std;

int main() {
    float angka1, angka2;
    cout << "masukkan angka 1 : ";
    cin >> angka1;
    cout << "masukkan angka 2 : ";
    cin >> angka2;

    cout << "penjumlahan : " << angka1 + angka2 << endl;
    cout << "pengurangan : " << angka1 - angka2 << endl;
    cout << "perkalian : " << angka1 * angka2 << endl;
    cout << "pembagian : " << angka1 / angka2 << endl;

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan1_Modul1/Output1_Unguided1.png)

contoh :
![Screenshot Output Unguided 1_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided1-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan1_Modul1/Output2_Unguided1.png)

penjelasan unguided 1 

### 2. Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di-input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100.

```C++
source code unguided 2
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 2_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided2-1.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 2

### 3. Buatlah program yang dapat memberikan input dan output sbb.

```C++
source code unguided 3
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 3_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided3-1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 3

## Kesimpulan
...

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
