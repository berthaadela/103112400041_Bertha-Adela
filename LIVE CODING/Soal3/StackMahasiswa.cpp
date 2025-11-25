#include "StackMahasiswa.h"
#include <iostream>
using namespace std;

bool isEmpty(StackMahasiswa &S) {
    return S.Top == -1;
}
bool isFull(StackMahasiswa &S) {
    return S.Top == MAX_SIZE - 1;
}
void createStack(StackMahasiswa &S) {
    S.Top = -1;
}
void Push(StackMahasiswa &S, Mahasiswa mhs) {
    if (!isFull(S)) {
        S.Top++;
        S.data[S.Top] = mhs;
    } else {
        cout << "Stack penuh, tidak bisa menambahkan data." << endl;
    }
}
void Pop(StackMahasiswa &S, Mahasiswa &mhs) {
    if (!isEmpty(S)) {
        mhs = S.data[S.Top];
        S.Top--;
    } else {
        cout << "Stack kosong, tidak bisa menghapus data." << endl;
    }
}
void Update(StackMahasiswa &S, string NIM, int posisi) {
    if (posisi >= 0 && posisi <= S.Top) {
        if (S.data[posisi].NIM == NIM) {
            S.data[posisi].Nama = "Heizou";
            S.data[posisi].NIM = "77777";
            S.data[posisi].NilaiTugas = 99.9;
            S.data[posisi].NilaiUTS = 88.8;
            S.data[posisi].NilaiUAS = 77.7;
        } else {
            cout << "NIM tidak sesuai pada posisi yang diberikan." << endl;
        }
    } else {
        cout << "Posisi tidak valid." << endl;
    }
}

void View(StackMahasiswa S) {
    if (isEmpty(S)) {
        cout << "Stack kosong." << endl;
    } else {
        cout << "Data Mahasiswa dalam Stack:" << endl;
        for (int i = S.Top; i >= 0; i--) {
            cout << "Posisi " << i << ": " << S.data[i].Nama << ", NIM: " << S.data[i].NIM
                 << ", Nilai Tugas: " << S.data[i].NilaiTugas
                 << ", Nilai UTS: " << S.data[i].NilaiUTS
                 << ", Nilai UAS: " << S.data[i].NilaiUAS << endl;
        }
    }
}

void SearchNilaiAkhir(StackMahasiswa StackMHS, float NilaiAkhirMin, float NilaiAkhirMax) {
    if (isEmpty(StackMHS)) {
        cout << "Stack kosong." << endl;
    } else {
        cout << "Mahasiswa dengan Nilai Akhir antara " << NilaiAkhirMin << " dan " << NilaiAkhirMax << ":\n";
        bool found = false;
        for (int i = 0; i <= StackMHS.Top; i++) {
            float NilaiAkhir = 0.3 * StackMHS.data[i].NilaiTugas + 0.35 * StackMHS.data[i].NilaiUTS + 0.35 * StackMHS.data[i].NilaiUAS;
            if (NilaiAkhir >= NilaiAkhirMin && NilaiAkhir <= NilaiAkhirMax) {
                cout << StackMHS.data[i].Nama << ", NIM: " << StackMHS.data[i].NIM
                     << ", Nilai Akhir: " << NilaiAkhir << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "Tidak ada mahasiswa yang ditemukan dalam rentang nilai tersebut." << endl;
        }
    }
}

void MaxNilaiAkhir(StackMahasiswa StackMHS) {
    if (isEmpty(StackMHS)) {
        cout << "Stack kosong." << endl;
    } else {
        float maxNilaiAkhir = -1.0;
        Mahasiswa topStudent;
        for (int i = 0; i <= StackMHS.Top; i++) {
            float NilaiAkhir = 0.3 * StackMHS.data[i].NilaiTugas + 0.35 * StackMHS.data[i].NilaiUTS + 0.35 * StackMHS.data[i].NilaiUAS;
            if (NilaiAkhir > maxNilaiAkhir) {
                maxNilaiAkhir = NilaiAkhir;
                topStudent = StackMHS.data[i];
            }
        }
        cout << "Mahasiswa dengan Nilai Akhir tertinggi:\n";
        cout << topStudent.Nama << ", NIM: " << topStudent.NIM
             << ", Nilai Akhir: " << maxNilaiAkhir << endl;
    }
}