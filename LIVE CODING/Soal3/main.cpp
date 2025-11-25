#include "StackMahasiswa.h"

#include <iostream>
using namespace std;

int main() {
    StackMahasiswa StackMHS;
    createStack(StackMHS);

    Mahasiswa mhs1 = {"Venti", "11111", 75.7, 82.1, 65.5};
    Mahasiswa mhs2 = {"Xiao", "22222", 87.4, 88.9, 81.9};
    Mahasiswa mhs3 = {"Kazuha", "33333", 92.3, 88.8, 82.4};
    Mahasiswa mhs4 = {"Wanderer", "44444", 95.5, 85.5, 90.5};
    Mahasiswa mhs5 = {"Lynette", "55555", 77.7, 65.4, 79.9};
    Mahasiswa mhs6 = {"Chasca", "66666", 99.9, 93.6, 87.3};

    Push(StackMHS, mhs1);
    Push(StackMHS, mhs2);
    Push(StackMHS, mhs3);
    Push(StackMHS, mhs4);
    Push(StackMHS, mhs5);
    Push(StackMHS, mhs6);

    View(StackMHS);
    cout << endl;

    Mahasiswa poppedMhs;
    Pop(StackMHS, poppedMhs);
    cout << "Data Mahasiswa yang di-Pop:" << endl;
    cout << poppedMhs.Nama << ", NIM: " << poppedMhs.NIM << endl << endl;

    cout << "Data Mahasiswa setelah Pop:" << endl;
    View(StackMHS);
    cout << endl;

    Update(StackMHS, "44444", 3);

    cout << "Data Mahasiswa setelah Update:" << endl;
    View(StackMHS);
    cout << endl;

    SearchNilaiAkhir(StackMHS, 85.5, 95.5);
    MaxNilaiAkhir(StackMHS);
    return 0;
}