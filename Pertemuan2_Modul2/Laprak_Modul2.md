# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahasa C++ (Bagian Kedua)</h1>
<p align="center">Bertha Adela - 103112400041</p>

## Dasar Teori
Array adalah sekumpulan elemen-elemen yang tersusun secara sekuensial, serta memiliki tipe data yang sama [1]. Array disusun berdasarkan indeks dan diawali dengan indeks 0.

### A. Array <br/>
#### 1. Array satu dimensi
Array satu dimensi terdiri dari elemen-elemen yang nilainya boleh berbeda [1]. Array ini hanya tersusun dalam satu baris.
#### 2. Array dua dimensi
Array dua dimensi digambarkan seperti matriks [1]. Array ini tersusun atas baris dan kolom [1].

### B. Pointer <br/>
Pointer adalah penunjuk lokasi memori [2]. Memori dapat diubah ke alamat lain [2]. Dengan menggunakan pointer, maka pencarian data akan lebih efisien. Terdapat dua buah operator pointer.
#### 1. Operator &
Operator ini adalah operator alamat [2]. Untuk mengetahui letak variabel disimpan, beri tanda ampersand (&) di depan variabel [2].
#### 2. Operator *
Operator ini adalah operator reference [2]. Digunakan untuk mengakses nilai yang tersimpan secara langsung dengan memberi tanda asterisk (*) didepan variabel [2]. 

## Guided 

### 1. Array and Pointer

```C++
#include <iostream>
using namespace std;

int main() {
    int arr[] = {10,20,30,40,50};
    int* ptr= arr; //pointer yang menunjuk ke elemen pertama array

    //mengakses elemen array menggunakan pointer
    for(int i=0; i < 5; i++) {
        cout << "Elemen array ke-" << i+1 << "menggunakan pointer: "<< *(ptr+i) << endl;
    }
    //mengakses elemen array menggunakan indeks
    for(int i = 0; i < 5; i++) {
        cout << "Elemen array ke-" << i+1 << "menggunakan indeks: " << arr[i] << endl;
    }
    return 0;
}
```
Kode di atas menunjukkan bahwa pemanggilan elemen pada array ada dua cara. Cara pertama menggunakan pointer, sedangkan cara kedua menggunakan indeks.

### 2. Call by Pointer

```C++
#include <iostream>
using namespace std;

void ubahNilai(int*ptr) {
    *ptr = 20; //mengubah nilai yang ditunjuk oleh pointer
}
int main() {
    int x = 10;
    cout << "Nilai sebelum diubah: " << x << endl;

    ubahNilai(&x); //mengirimkan alamat memori x ke fungsi
    cout << "Nilai setelah diubah: " << x << endl;

    return 0;
}
```
Kode di atas menunjukkan bahwa elemen yang ditunjuk oleh pointer dapat diubah. 

### 3. Call by Reference

```C++
#include <iostream>

using namespace std;

void ubahNilai(int& ref) {
    ref = 20; //mengubah nilai melalui referensi
}

int main() {
    int x = 10;
    cout << "Nilai sebelum diubah: " << x << endl;

    ubahNilai(x); //mengirim referensi ke x
    cout << "Nilai setelah diubah: " << x << endl;

    return 0;
}
```
Value dalam variabel x dapat diubah melalui referensi.

### 4. Function Procedure

```C++
#include <iostream>
using namespace std;

int cariMAX(int arr[], int ukuran) {
    int MAX = arr[0];
    for(int i = 1; i < ukuran; i++) {
        if(arr[i] > MAX) {
            MAX = arr[i];
        }
    }
    return MAX;
}

void operasiAritmatika(int arr[], int ukuran) {
    int totalJumlah = 0;
    for(int i = 0; i < ukuran; i++) {
        totalJumlah += arr[i];
    }
    cout << "total penjumlahan : " << totalJumlah << endl;
    int totalKali = 1;
    for(int i = 0; i < ukuran; i++) {
        totalKali *= arr[i];
    }
    cout << "total perkalian : " << totalKali << endl;
}

int main() {
    const int ukuran = 5;
    int arr[ukuran];
    for(int i = 0; i < ukuran; i++) {
        cout << "masukkan nilai array ke-" << i << " : ";
        cin >> arr [i];
    }
    cout << endl;
    cout << "nilai terbesar dalam array : " << cariMAX(arr, ukuran) << endl;

    operasiAritmatika(arr, ukuran);
    return 0;
}
```
Kode di atas melakukan pencarian nilai terbesar, hasil penjumlahan, perkalian pada semua elemen array.


## Unguided 

### 1. Diketahui 2 buah matriks 3x3 seperti dibawah ini : <br/>matriksA = [7 12 22, 31 6 41, 15 19 36]<br/> MatriksB = [11 34 7, 3 25 41, 5 18 33].<br/>Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3 tersebut. Buat prosedur untuk masing-masing operasi yang dilakukan; jumlahMatriks() untuk operasi penjumlahan, kurangMatriks() untuk pengurangan, dan kaliMatriks() untuk perkalian. Buat program tersebut menggunakan menu switch-case seperti berikut ini :
<br/>--- Menu Program Matriks ---<br/>1. Penjumlahan matriks<br/>2. Pengurangan matriks<br/>3. Perkalian matriks<br/>4. Keluar

```C++
#include <iostream>
using namespace std;

void tampilkan(int arr[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
void jumlahMatriks(int a[3][3], int b[3][3], int c[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}
void kurangMatriks(int a[3][3], int b[3][3], int c[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}

void kaliMatriks(int a[3][3], int b[3][3], int c[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            c[i][j] = a[i][j] * b[i][j];
        }
    }
}

int main() {
    int pilihan;
    int matriksA[3][3] = {
        {7,12,22},
        {31,6,41},
        {15,19,36}
    };
    int matriksB[3][3] = {
        {11,34,7},
        {3,25,41},
        {5,18,33}
    };
    int outputMatriks[3][3];

    cout << "Matriks A" << endl;
    tampilkan(matriksA);
    cout << endl;

    cout << "Matriks B" << endl;
    tampilkan(matriksB);
    cout << endl;
    
    cout << "--- Menu Program Matriks ---" << endl;
    cout << "1. Penjumlahan matriks" << endl;
    cout << "2. Pengurangan matriks" << endl;
    cout << "3. Perkalian matriks" << endl;
    cout << "Pilihan: ";
    cin >> pilihan;


    switch (pilihan) {
        case 1:
        jumlahMatriks(matriksA, matriksB, outputMatriks);
        cout << "Hasil Matriks: " << endl;
        tampilkan(outputMatriks);
        return 1;
        case 2:
        kurangMatriks(matriksA, matriksB, outputMatriks);
        cout << "Hasil Matriks: " << endl;
        tampilkan(outputMatriks);
        return 2;
        case 3:
        kaliMatriks(matriksA, matriksB, outputMatriks);
        cout << "Hasil Matriks: " << endl;
        tampilkan(outputMatriks);
        return 3;
        default:
        cout << "Tidak ada pilihan " << pilihan;
        return 0;
    }
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan2_Modul2/Output-Penjumlahan-Unguided-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan2_Modul2/Output-Pengurangan-Unguided-1.png)

##### Output 3
![Screenshot Output Unguided 1_1](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan2_Modul2/Output-Perkalian-Unguided-1.png)

##### Output 4
![Screenshot Output Unguided 1_2](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan2_Modul2/Output-Default-Unguided-1.png)

Matriks 3x3 menggunakan perulangan didalam perulangan. Matriks A pada variabel matriksA, matriks B pada variabel matriksB. Hasil operasi dimasukkan ke matriks kosong yang dinamakan outputMatriks. Penjumlahan, pengurangan, perkalian dibuat terpisah pada fungsi yang berbeda. Fungsi tampilkan() digunakan untuk menampilkan matriks, khususnya untuk outputMatriks.

### 2. Buatlah program menghitung luas dan keliling persegi panjang dengan proses perhitungan dan perubahan nilainya menggunakan pointer, seperti berikut:
1) Buatlah 3 variabel integer di fungsi main(): panjang (beri nilai 10), lebar (beri nilai 5), dan
luas (beri nilai 0).
2) Deklarasikan dua pointer: ptrPanjang yang menunjuk ke variabel panjang, dan ptrLebar
yang menunjuk ke variabel lebar.
3) Hitung luas persegi panjang tersebut dan simpan hasilnya ke dalam variabel luas.
Syarat: Proses perhitungan ini wajib menggunakan ptrPanjang dan ptrLebar.
4) Cetak nilai luas ke layar.
5) Setelah itu, ubah nilai panjang menjadi 12 dan lebar menjadi 6, juga hanya melalui
pointer ptrPanjang dan ptrLebar.
6) Cetak nilai panjang dan lebar yang baru untuk membuktikan bahwa
nilainya telah berubah.


```C++
#include <iostream>
using namespace std;
void ubahNilai(int *pointer1, int *pointer2) {
    *pointer1 = 12;
    *pointer2 = 6;
}
int luasPersegi(int *p1, int *p2) {
    return *p1 * *p2;
}
int kelilingPersegi(int *p1, int *p2) {
    return *p1 * 2 + *p2 * 2;
}

int main() {
    int panjang = 10;
    int lebar = 5;
    int luas = 0;
    int* ptrPanjang = &panjang;
    int* ptrLebar =  &lebar;


    cout << "---Nilai Awal---" << endl;
    cout << "Panjang: " << panjang << endl;
    cout << "Lebar: " << lebar << endl;
    cout << endl;

    cout << "---Hasil Perhitungan---" << endl;
    cout << "Luas Persegi Panjang: " << luasPersegi(ptrPanjang,ptrLebar) << endl;
    cout << "Keliling Persegi Panjang: " << kelilingPersegi(ptrPanjang,ptrLebar) << endl;
    cout << endl;

    ubahNilai(&panjang, &lebar);

    cout << "---Nilai Setelah Diubah Melalui Pointer---" << endl;
    cout << "Panjang Baru: " << *ptrPanjang << endl;
    cout << "Lebar Baru: " << *ptrLebar << endl;
    cout << "Luas Baru: " << luasPersegi(ptrPanjang,ptrLebar) << endl;
    cout << "Keliling Baru: " << kelilingPersegi(ptrPanjang,ptrLebar) << endl;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan2_Modul2/Output-Pointer-Unguided-2.png)

Value pada suatu variabel dapat diubah dengan menggunakan fungsi ubahNilai(). Fungsi ini mendeklarasikan dua buah pointer, pointer1 bervalue 12 dan pointer2 bervalue 6. Fungsi ini akan mengubah value pointer ptrPanjang dan pointer ptrLebar. Sehingga ketika pointer dipanggil kembali, hasilnya akan berbeda.

## Kesimpulan
Pointer sangat berguna untuk mengubah suatu value dari variabel tanpa perlu mengubah kode. Dengan menggunakan pointer, pencarian data akan lebih efisien.

## Referensi
[1] Pratama, M. A. (2020). STRUKTUR DATA ARRAY DUA DIMENSI PADA PEMROGRAMAN C++.
<br/> [2] Arimbi, Y. F. D. Mengenal tipe data pointer.
<br/>