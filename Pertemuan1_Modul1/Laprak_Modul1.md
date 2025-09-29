# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Bertha Adela - 103112400041</p>

## Dasar Teori
Pemrograman dikelompokkan menjadi dua, yaitu high level language dan low level language [1]. C++ termasuk ke dalam level high level language [1]. Bahasa ini disebut high level language karena berorientasi ke bahasa manusia, dengan kata lain mudah dipahami manusia [1]. Low level language adalah bahasa yang berorientasi ke bahasa mesin [1]. Pada level ini bahasa hanya mengenal bilangan biner, yaitu 0 atau 1 [1]. 

### A. Struktur Data C++<br/>
#### 1. Dasar C++
Baris pertama dalam memulai program C++ adalah #include < iostream > (tanpa spasi) [3]. Setelah itu semua kode harus diakhiri dengan tanda ; (titik koma). Setelah #include < iostream > (tanpa spasi) , buat baris baru berisi using namespace std;.
<br/>Buat fungsi main setelah tipe data, contohnya: int main() {}. Operasi dilakukan didalam tanda {} (kurung kurawal).

#### 2. Tipe Data
Tipe data pada bahasa C++ diantaranya adalah:
int, float, double, char, const, void, return [3].

#### 3. Deklarasi Variabel
Cara mendeklarasikan variabel yaitu harus menentukan tipe data dahulu sebelum nama variabel. Contoh:
int angka;
<br/>float bilangan;
<br/>string huruf;

#### 4. Input C++
Input C++ menggunakan cin >> (nama variabel) dan ditutup dengan ; (kurung kurawal).
Contoh:
<br/>cin >> angka;
<br/><br/>Bisa double input atau lebih
<br/>cin >> angka >> huruf;
<br/><br/>Bisa ditambah endl untuk membuat baris baru
<br/>cin >> string >> endl;
<br/><br/>Untuk memasukkan value ke dalam variabel secara langsung sama dengan sebagian besar bahasa pemrograman lainnya. Contoh:
<br/>angka = 10;
<br/>bilangan = bilangan - 1;
<br/>huruf = "sapi";

#### 5. Output C++
Output C++ menggunakan cout << (nama variabel/angka/string) dan ditutup dengan ; (kurung kurawal). Contoh:
<br/>cout << angka;
<br/>cout << "string langsung";
<br/>cout << 90;

### B. Operator
#### 1. Operator Aritmatika
Penjumlahan: + , contoh : 10 + 10 = 20
<br/>Pengurangan: - , contoh : 10 - 10 = 0
<br/>Perkalian: * , contoh : 10 * 10 = 100
<br/>Pembagian: / , contoh : 10 / 10 = 1
<br/>Sisa Bagi: % , contoh : 10 % 10 = 0, contoh : 10 % 2 = 8;
#### 2. Operator Logika
AND : &&
<br/>OR : ||
#### 3. Operator Hubungan
Kurang dari: <
<br/>Kurang dari sama dengan <=
<br/>Lebih dari: >
<br/>Lebih dari sama dengan: >=
<br/>Sama dengan: ==
<br/>Tidak sama dengan: !=

### C. Linked List<br/>
Linked list adalah suatu sistem untuk menyimpan data yang saling terkait berisi dua buah elemen yaitu integer dan pointer [2]. Linked list biasanya terurut dan memungkinkan untuk diterapkan operasi aritmatika [2]. Linked list efektif untuk pencarian data, lebih cepat untuk menemukan suatu data dibandingkan array karena linked list sudah memiliki alamat.

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
Program di atas adalah contoh aritmatika pada penjumlahan, pengurangan, perkalian, pembagian, dan sisa bagi dalam bahasa c++ dengan menginputkan angka pertama dengan angka kedua sebagai objek operasinya.
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
Program di atas berfungsi untuk membandingkan antara dua buah input bertipe integer apabila input pertama lebih dari atau kurang dari input kedua serta apabila input pertama sama atau berbeda dengan input kedua. 

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
Program di atas akan melakukan operasi aritmatika penjumlahan atau pengurangan dari kedua input sesuai dengan pilihan, jika memilih selain dari pilihan, maka operasi aritmatika tidak dilakukan kemudian program memberi output "pilihan salah".

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
Program di atas menerapkan for loop, while loop, dan do while dalam bahasa c++.

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
Program di atas berfungsi untuk menyimpan nama dan nilai siswa untuk 3 siswa dalam bahasa c++.

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

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan1_Modul1/Output2_Unguided1.png)

Unguided 1 menggunakan tipe data float, menggunakan operator aritmatika +, -, *, dan / yang berfungsi untuk penjumlahan, pengurangan, perkalian, dan pembagian.

### 2. Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di-input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100.

```C++
#include <iostream>
using namespace std;

int main() {
    int angka;
    string angka_satuan[10] = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};

    cout << "Masukkan angka (0 - 100): ";
    cin >> angka;
    int puluhan = angka / 10;
    int satuan = angka % 10;

    if (angka == 0) {
        cout << "nol";
    } else if (angka == 10) {
        cout << "sepuluh";
    } else if (angka == 11) {
        cout << "sebelas";
    } else if (angka > 11 && angka < 20) {
        cout << angka_satuan[satuan] << " belas";
    } else if (angka >= 20 && angka < 100) {
        cout << angka_satuan[puluhan] << " puluh";
        if (satuan != 0) {
            cout << " " << angka_satuan[satuan];
        }
    } else if (angka >= 1 && angka <= 9) {
        cout << angka_satuan[angka];
    } else if (angka == 100) {
        cout << "seratus";
    } else {
        cout << "angka tidak valid";
    }

    cout << endl;
    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan1_Modul1/Output1_Unguided2.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan1_Modul1/Output2_Unguided2.png)

Unguided 2 menggunakan indeks array sebagai satuan dari angka 1 hingga angka 9. Array indeks ke-0 dikosongkan dan "nol" dimasukkan ke dalam kondisi if karena hanya dipakai sekali. Jika satuan maka diambil dari array indeks ke-(angka % 10) sedangkan untuk puluhan diambil dari array indeks ke-(angka / 10). Perkondisian diantara angka 0 s.d. 100 yang dipisah adalah angka 0, 10, 11, dan 100. Angka 12 hingga 19 menggunakan kondisi array indeks ke-(angka % 10) ditambah dengan string "belas", Angka 20 hingga 99 menggunakan kondisi array indeks ke-(angka / 10) ditambah dengan string "puluh" (namun jika sisa bagi 10 tidak sama dengan 0, maka ditambah dengan array indeks ke-(angka % 10)), Angka 1 hingga 9 hanya perlu memanggil indeks dari array secara langsung, dan jika angka input di luar dari ketentuan maka output berupa string "angka tidak valid".

### 3. Buatlah program yang dapat memberikan input dan output sbb.

```C++
#include <iostream>
using namespace std;

int main() {
    int angka;
    cin >> angka;
    for (int b = angka; b >= 1; b--) {
        for (int s = 1; s <= angka-b; s++) {
            cout << "  ";
        }
        for (int i = b; i >= 1; i--) {
            cout << i << " ";
        }
        cout << "* ";
        for (int j = 1; j <= b; j++) {
            cout << j;
            cout << " ";
        }
        cout << endl;
    }
    for (int s = 1; s <= angka; s++) {
        cout << "  ";
    }
    cout << "*" << endl;

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan1_Modul1/Output1_Unguided3.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/berthaadela/103112400041_Bertha-Adela/blob/main/Pertemuan1_Modul1/Output2_Unguided3.png)

Unguided 3 menghasilkan output berupa bilangan yang diinputkan akan urut mengecil dikurangi dengan satu hingga berhenti pada angka 1, kemudian dilanjutkan string "* " sebagai cermin, lalu dilanjutkan bilangan urut membesar ditambah 1 dari angka 1 menuju angka input. Setiap baris berikutnya angka pertama dihapus beserta angka terakhir setelah cermin. Terakhir hanya string "*" yang tersisa.
<br/>for (int b = angka; b >= 1; b--) adalah perulangan utama menurun,
<br/>for (int s = 1; s <= angka-b; s++) membuat spasi bertambah setiap perulangan,
<br/>for (int i = b; i >= 1; i--) membuat angka menurun setiap perulangan,
<br/>cout << "* "; sebagai cermin diantara batas perulangan angka menurun dengan perulangan angka menaik,
<br/>for (int j = 1; j <= b; j++) membuat angka menaik setiap perulangan,
<br/>for (int s = 1; s <= angka; s++) berfungsi sebagai spasi terakhir setelah perulangan lainnya berakhir dan hanya tersisa satu buah cermin.

## Kesimpulan
Bahasa C++ tidak jauh berbeda dengan bahasa pemrograman Go. Tantangan yang ada untuk saat ini adalah menggunakan format yang berbeda, seperti penempatan titik koma yang harus berada di akhir barisan kode. Bahasa pemrograman ini lebih mudah dipelajari karena berorientasi dengan bahasa manusia, namun bahasa ini lebih kompleks daripada bahasa pemrograman lainnya.

## Referensi
[1] Dewi, L. J. E. (2010). Media Pembelajaran Bahasa Pemrograman C++. Jurnal Pendidikan Teknologi dan Kejuruan, 7(1).
<br/> [2] Siregar, A. A. N. (2019, April 25). Pengertian Linked Object. https://doi.org/10.31219/osf.io/dmwr3.
<br/> [3] Satrio, E., & Pakpahan, S. (2019). Pemrograman C++ Untuk Pembelajar Mandiri (Vol. 1). Penerbit Cahaya INFORMATIKA.
