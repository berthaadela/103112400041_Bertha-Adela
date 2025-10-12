# <h1 align="center">Laporan Praktikum Modul 3 - ABSTRACT DATA TYPE (ADT)</h1>
<p align="center">Bertha Adela - 103112400041</p>

## Dasar Teori
Abstract Data Type (ADT) adalah sekumpulan objek dan sekumpulan operasi pada objek [1]. "ADT adalah definisi TYPE dan sekumpulan PRIMITIF (operasi dasar) terhadap
TYPE tersebut" (Rachman, 2003) [2]. TYPE berupa struct pada bahasa C [2]. PRIMITIF dikelompokkan menjadi: 
• Konstruktor/Kreator, pembentuk nilai type. Semua objek (variabel) bertype tsb
harus melalui konstruktor. Biasanya namanya diawali Make.
• Selektor, untuk mengakses komponen type (biasanya namanya diawali dengan
Get)
• Prosedur pengubah nilai komponen (biasanya namanya diawali Get)
• Validator komponen type, yang dipakai untuk mentest apakah dapat membentuk
type sesuai dengan batasan
• Destruktor/Dealokator, yaitu untuk "menghancurkan" nilai objek (sekaligus
memori penyimpannya)
• Baca/Tulis, untuk interface dengan input/output device
• Operator relational, terhadap type tsb untuk mendefinisikan lebih besar, lebih
kecil, sama dengan, dsb
• Aritmatika terhadap type tsb, karena biasanya aritmatika dalam bahasa
pemrograman hanya terdefinisi untuk bilangan numerik
• Konversi dari type tersebut ke type dasar dan sebaliknya [2].

ADT berfungsi untuk menyembunyikan suatu program sehingga tak terlihat oleh user. Terdapat 3 file untuk menerapkan ADT.

### A. Header/Kerangka <br/>
Header berfungsi sebagai supplier (penyedia type dan primitif) [2]. Mendefinisikan type atau struct dan fungsi-fungsi primitif.

### B. Implementasi Fungsi <br/>
Implementasi fungsi merupakan lanjutan dari supplier [2]. Mengimplementasikan fungsi-fungsi primitif.

### C. Main Program/Program Utama <br/>
Main program sebagai client (pengguna) [2]. Merupakan bagian yang terlihat user. Main program memakai supply.

## Guided 

### 1. Mahasiswa

#### Header
```C++
#ifndef MAHASISWA_H
#define MAHASISWA_H

//Definisi Tipe (Struct)
struct mahasiswa
{
    char nim[10];
    int nilai1, nilai2;
};

//Deklarasi Primitif (Fungsi)
void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);

#endif
```

#### Implementasi Fungsi
```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

//Realisasi dari Fungsi inputMhs
void inputMhs(mahasiswa &m) {
    cout << "Input NIM: ";
    cin >> m.nim;
    cout << "Input Nilai 1: ";
    cin >> m.nilai1;
    cout << "Input Nilai 2: ";
    cin >> m.nilai2;
}

//Realisasi dari Fungsi rata2
float rata2(mahasiswa m){
    return (float)(m.nilai1+m.nilai2)/2;
}
```

#### Program Utama
```C++
#include <iostream>
#include "mahasiswa.h"
#include <cstdlib>

using namespace std;

int main() {
    mahasiswa mhs;

    inputMhs(mhs);

    cout << "Rata-rata nilai adalah: " << rata2(mhs) << endl;

    system("pause");

    return 0;
}
```
Guided 1 menjelaskan tentang penerapan ADT untuk mencari nilai rata-rata mahasiswa.

### 2. Struct

```C++
#include<iostream>
using namespace std;

struct mahasiswa{
    string nama;
    float nilai1, nilai2; 
};

void inputMhs(mahasiswa &m){
    cout << "Masukan nama mahasiswa: ";
    cin >> m.nama;
    cout << "Masukan nilai 1: ";
    cin >> m.nilai1;
    cout << "Masukan nilai 2: ";
    cin >> m.nilai2;
}

//Realisasi dari fungsi rata2
float rata2(mahasiswa m){
    return float (m.nilai1 + m.nilai2)/2;
}

int main(){
    mahasiswa mhs; //Pemanggilan Struct
    inputMhs(mhs); //Pemanggilan Prosedur
    cout << "Rata-rata: " << rata2(mhs);
    return 0;
}
```
Guided 2 adalah kode menghitung rata2 nilai mahasiswa tanpa menggunakan ADT. 



## Unguided 

### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3*uts+0.4*uas+0.3*tugas.

#### Header
```C++
#ifndef UNGUIDED1_H
#define UNGUIDED1_H

struct mahasiswa
{
    char nama[10], nim[10];
    int uts, uas, tugas;
};

void inputM(mahasiswa &m);
float nilaiAkhir(mahasiswa m);

#endif

```

#### Implementasi Fungsi
```C++
#include <iostream>
#include "unguided1.h"
using namespace std;


void inputM(mahasiswa &m) {
    cout << "Input Nama: ";
    cin >> m.nama;
    cout << "Input NIM: ";
    cin >> m.nim;
    cout << "Input Nilai UTS: ";
    cin >> m.uts;
    cout << "Input Nilai UAS: ";
    cin >> m.uas;
    cout << "Input Nilai Tugas: ";
    cin >> m.tugas;
}

float nilaiAkhir(mahasiswa m) {
    return (float) 0.3*m.uts + 0.4*m.uas + 0.3*m.tugas;
}
```

#### Program Utama
```C++
#include <iostream>
#include <cstdlib>
#include "unguided1.h"
using namespace std;

int main() {
    mahasiswa moh;
    inputM(moh);
    cout << "Nilai Akhir: " << nilaiAkhir(moh);
    system("pause");
    return 0;
}
```

### Output Unguided 1 :

![Screenshot Output Unguided 1](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan3_Modul3/OutputUnguided1.png)

Pada header terdapat struct mahasiswa yang menyimpan nama, nim, nilai uts, nilai uas, dan nilai tugas, serta prosedur dan fungsi. Implementasi fungsi lebih menjabarkan kerangka header, dimana void inputM() dan float nilaiAkhir() dirumuskan. Program Utama mengatur posisi kode agar dapat dieksekusi.

### 2.  Buatlah ADT pelajaran sebagai berikut di dalam file "pelajaran.h":
    Type pelajaran <
        namaMapel : string
        kodeMapel : string
    >
    function create_pelajaran( namapel : string, kodepel: string ) → pelajaran
    procedure tampil_pelajaran( input pel: pelajaran )

Buatlah implementasi ADT pelajaran pada file "pelajaran.cpp"
Cobalah hasil implementasi ADT pada file "main.cpp"

    using namespace std;
    int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";
    pelajaran pel = create_pelajaran (namapel,kodepel);
    tampil_pelajaran(pel);
    return 0;
    }

Contoh output hasil:
    nama pelajaran : Struktur Data
    nilai : STD

#### Header
```C++
#ifndef UNGUIDED2_H
#define UNGUIDED2_H
#include <iostream>
using namespace std;

struct pelajaran
{
    string namapel, kodepel;
};

pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(const pelajaran &pel);

#endif
```

#### Implementasi Fungsi
```C++
#include "unguided2.h"
using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran p;
    p.namapel = namapel;
    p.kodepel = kodepel;
    return p;
}

void tampil_pelajaran(const pelajaran &p) {
    cout << "Nama Mapel: " << p.namapel << endl;
    cout << "Kode Mapel: " << p.kodepel << endl;
}
```

#### Program Utama
```C++
#include <iostream>
#include <cstdlib>
#include "unguided2.h"
using namespace std;

int main() {
string namapel = "Struktur Data";
string kodepel = "STD";
pelajaran pel = create_pelajaran(namapel, kodepel);
tampil_pelajaran(pel);

return 0;
}
```

### Output Unguided 2 :

![Screenshot Output Unguided 2](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan3_Modul3/OutputUnguided2.png)

Diberikan keterangan mengenai header dan main program pada soal. Implementasi fungsi untuk mencari rumus create_pelajaran dan tampil_pelajaran. agar fungsi create_pelajaran cocok dengan pelajaran pel, berarti fungsi create_pelajaran menggunakan struct sebagai tipe datanya. 

### 3.  Buatlah program dengan ketentuan :
- 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer
- fungsi/prosedur yang menampilkan isi sebuah array integer 2D
- fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu
- fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer

#### Header
```C++
#ifndef ARRAY2D_H
#define ARRAY2D_H

void tampilkan(int arr[3][3]);

void tukarDalamArray(int arr[3][3], int baris1, int kolom1, int baris2, int kolom2);

void tukarPointer(int* ptr1, int* ptr2);

#endif
```

#### Implementasi Fungsi
```C++
#include <iostream>
#include "unguided3.h"
using namespace std;

void tampilkan(int arr[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void tukarPointer(int* ptr1, int* ptr2) {
    int simpan = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = simpan;
}

void tukarDalamArray(int arr[3][3], int baris1, int kolom1, int baris2, int kolom2) {
    int simpan = arr[baris1][kolom1];
    arr[baris1][kolom1] = arr[baris2][kolom2];
    arr[baris2][kolom2] = simpan;
}
```

#### Program Utama
```C++
#include <iostream>
#include "unguided3.h"
using namespace std;

int main() {
    int arr1[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    int arr2[3][3] = {
        {11,12,13},
        {14,15,16},
        {17,18,19}
    };
    int *ptr1, *ptr2;
    int baris1, kolom1, baris2, kolom2;
    int input;

    while (true) {
        cout << "=== MENU ===" << endl;
        cout << "1. Tampilkan Array" << endl;
        cout << "2. Tukar Isi Array 1" << endl;
        cout << "3. Tukar Isi Array 2" << endl;
        cout << "4. Tukar Pointer" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> input;

        switch (input) {
        case 1:
            cout << "Array Kesatu" << endl;
            tampilkan(arr1);
            cout << "Array Kedua" << endl;
            tampilkan(arr2);
            break;
        case 2:
            cout << "Dari Baris ke (0-2): "; cin >> baris1;
            cout << "Dari Kolom ke (0-2): "; cin >> kolom1;
            cout << "Menuju Baris ke (0-2): "; cin >> baris2;
            cout << "Menuju Kolom ke (0-2): "; cin >> kolom2;
            if (baris1 < 0 || baris1 > 2 || kolom1 < 0 || kolom1 > 2 ||
                baris2 < 0 || baris2 > 2 || kolom2 < 0 || kolom2 > 2) {
                cout << "Indeks tidak valid!\n";
                break;
            }
            tukarDalamArray(arr1, baris1, kolom1, baris2, kolom2);
            break;
        case 3:
            cout << "Dari Baris ke (0-2): "; cin >> baris1;
            cout << "Dari Kolom ke (0-2): "; cin >> kolom1;
            cout << "Menuju Baris ke (0-2): "; cin >> baris2;
            cout << "Menuju Kolom ke (0-2): "; cin >> kolom2;
            if (baris1 < 0 || baris1 > 2 || kolom1 < 0 || kolom1 > 2 ||
                baris2 < 0 || baris2 > 2 || kolom2 < 0 || kolom2 > 2) {
                cout << "Indeks tidak valid!\n";
                break;
            }
            tukarDalamArray(arr2, baris1, kolom1, baris2, kolom2);
            break;
        case 4:
            cout << "Array 1 Baris (0-2): "; cin >> baris1;
            cout << "Array 1 Kolom (0-2): "; cin >> kolom1;
            cout << "Array 2 Baris (0-2): "; cin >> baris2;
            cout << "Array 2 Kolom (0-2): "; cin >> kolom2;
            if (baris1 < 0 || baris1 > 2 || kolom1 < 0 || kolom1 > 2 ||
                baris2 < 0 || baris2 > 2 || kolom2 < 0 || kolom2 > 2) {
                cout << "Indeks tidak valid!\n";
                break;
            }
            ptr1 = &arr1[baris1][kolom1];
            ptr2 = &arr2[baris2][kolom2];
            tukarPointer(ptr1, ptr2);
            break;
        case 5:
            return 0;
        default:
            cout << "Tidak ada pilihan " << input;
        }
    }
}
```

### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan3_Modul3/OutputUnguided3_1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan3_Modul3/OutputUnguided3_2.png)

##### Output 3
![Screenshot Output Unguided 3_3](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan3_Modul3/OutputUnguided3_3.png)

##### Output 4
![Screenshot Output Unguided 3_4](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan3_Modul3/OutputUnguided3_4.png)

##### Output 5
![Screenshot Output Unguided 3_2](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan3_Modul3/OutputUnguided3_5.png)

Pada poin pertama, dibutuhkan 2 buah array dan 2 buah pointer. Diterapkan pada program utama pada bagian deklarasi variabel.
Pada poin kedua, dibutuhkan fungsi untuk menampilkan array 2D. Maka dari itu, fungsi tersebut dibuat pada header dan dirumuskan pada implementasi fungsi. Fungsi bernama tampilkan(). Pada program utama, dibuat switch case untuk menggunakan fungsi ini. Case 1 adalah case untuk menampilkan kedua buah array.
Pada poin ketiga, dibutuhkan fungsi untuk menukar isi array 2D. Sama halnya dengan poin kedua, fungsi dibuat pada header dan dirumuskan pada implementasi fungsi. Fungsi ini bernama tukarDalamArray(). Pada bagian program utama, dibuat dua buah pilihan switch case untuk memilih array yang nilainya ingin ditukar. Case 2 untuk array pertama dan case 3 untuk array kedua.  Setelah memilih array maka user perlu input baris dan kolom elemen yang ingin menukar dan elemen yang ditukar.
Pada poin terakhir, dibutuhkan fungsi untuk menukar elemen pada array yang ditunjuk oleh pointer. Fungsi ini hanya menukar pointernya, sehingga saat ditampilkan kembali, nilainya tampak tertukar.

## Kesimpulan
ADT berguna untuk menampilkan sebagian program yang hanya berkaitan dengan user/client. Type berisi struct, primitif berisi banyak hal diantaranya berhubungan dengan fungsi-fungsi. Header sebagai kerangka, pendeklarasian type dan primitif. Implementasi fungsi lanjutan dari header, melengkapi header, dan merumuskan header. Program Utama adalah client/user/pengguna.  

## Referensi
[1] Schmidt, D. C., ADTs, D. O. U., & ADTs, B. I. C++ Support for Abstract Data Types.
<br/>[2] Rachman, D. A. Perkenalan Abstrak Data Type.