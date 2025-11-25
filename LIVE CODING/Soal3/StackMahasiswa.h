#ifndef STACKMAHASISWA_H
#define STACKMAHASISWA_H
#include <iostream>
using namespace std;
struct Mahasiswa {
    string Nama;
    string NIM;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
};

const int MAX_SIZE = 6;

struct StackMahasiswa {
    Mahasiswa data[MAX_SIZE];
    int Top;
};

bool isEmpty(StackMahasiswa &S);
bool isFull(StackMahasiswa &S);
void createStack(StackMahasiswa &S);
void Push(StackMahasiswa &S, Mahasiswa mhs);
void Pop(StackMahasiswa &S, Mahasiswa &mhs);
void Update(StackMahasiswa &S, string NIM, int posisi);
void View(StackMahasiswa S);
void SearchNilaiAkhir(StackMahasiswa StackMHS, float NilaiAkhirMin, float NilaiAkhirMax);
void MaxNilaiAkhir(StackMahasiswa StackMHS);
#endif