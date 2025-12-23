#include "mll.h"
#include <iostream>
using namespace std;

bool isEmptyParent(listParent LParent) {
    return (LParent.first == NULL && LParent.last == NULL);
}
bool isEmptyChild(listChild LChild) {
    return (LChild.first == NULL && LChild.last == NULL);
}
void createListParent(listParent &LParent) {
    LParent.first = NULL;
    LParent.last = NULL;
}
void createListChild(listChild &LChild) {
    LChild.first = NULL;
    LChild.last = NULL;
}
NodeParent allocNodeParent(string idFilm, string namaGenre) {
    NodeParent NParent = new nodeParent;
    NParent->isidata.idGenre = idFilm;
    NParent->isidata.namaGenre = namaGenre;
    NParent->next = NULL;
    NParent->prev = NULL;
    createListChild(NParent->L_Child);
    return NParent;
}
NodeChild allocNodeChild(string idFilm, string judulFilm, int durasiFilm, int tahunTayang, float ratingFilm) {
    NodeChild NChild = new nodeChild;
    NChild->isidata.idFilm = idFilm;
    NChild->isidata.judulFilm = judulFilm;
    NChild->isidata.durasiFilm = durasiFilm;
    NChild->isidata.tahunTayang = tahunTayang;
    NChild->isidata.ratingFilm = ratingFilm;
    NChild->next = NULL;
    NChild->prev = NULL;
    return NChild;
}
void deallocNodeParent(NodeParent &NParent) {
    delete NParent;
}
void deallocNodeChild(NodeChild &NChild) {
    delete NChild;
}
void insertFirstParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = newNParent;
        LParent.last = newNParent;
    } else {
        newNParent->next = LParent.first;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
}
void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = newNParent;
        LParent.last = newNParent;
    } else {
        LParent.last->next = newNParent;
        newNParent->prev = LParent.last;
        LParent.last = newNParent;
    }
}
void deleteFirstParent(listParent &LParent) {
    if (!isEmptyParent(LParent)) {
        NodeParent NDelete = LParent.first;
        if (LParent.first == LParent.last) {
            LParent.first = NULL;
            LParent.last = NULL;
        } else {
            LParent.first = LParent.first->next;
            LParent.first->prev = NULL;
        }
        deallocNodeParent(NDelete);
    }
}
void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeParent NDelete = NPrev->next;
        NPrev->next = NDelete->next;
        if (NDelete == LParent.last) {
            LParent.last = NPrev;
        } else {
            NDelete->next->prev = NPrev;
        }
        deallocNodeParent(NDelete);
    }
}
void insertFirstChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = newNChild;
        LChild.last = newNChild;
    } else {
        newNChild->next = LChild.first;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
}
void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = newNChild;
        LChild.last = newNChild;
    } else {
        LChild.last->next = newNChild;
        newNChild->prev = LChild.last;
        LChild.last = newNChild;
    }
}
void deleteFirstChild(listChild &LChild) {
    if (!isEmptyChild(LChild)) {
        NodeChild NDelete = LChild.first;
        if (LChild.first == LChild.last) {
            LChild.first = NULL;
            LChild.last = NULL;
        } else {
            LChild.first = LChild.first->next;
            LChild.first->prev = NULL;
        }
        deallocNodeChild(NDelete);
    }
}
void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeChild NDelete = NPrev->next;
        NPrev->next = NDelete->next;
        if (NDelete == LChild.last) {
            LChild.last = NPrev;
        } else {
            NDelete->next->prev = NPrev;
        }
        deallocNodeChild(NDelete);
    }
}
void deleteListChild(listChild &LChild) {
    while (!isEmptyChild(LChild)) {
        deleteFirstChild(LChild);
    }
}
void printMLLStructure(listParent LParent) {
    if (isEmptyParent(LParent)) {
        cout << "Multi-Level List is empty." << endl;
        return;
    }
    NodeParent PParent = LParent.first;
    int parentKe = 1;
    int childKe = 1;
    while (PParent != NULL) {
        cout << "=== " << "Parent " << parentKe++ << " ===" << endl;
        cout << "ID Genre : " << PParent->isidata.idGenre << endl;
        cout << "Nama Genre : " << PParent->isidata.namaGenre << endl;
        NodeChild PChild = PParent->L_Child.first;
        if (isEmptyChild(PParent->L_Child)) {
            cout << "  (tidak ada child)" << endl;
        } else {
            while (PChild != NULL) {
                cout << "   - Child " << childKe++ << endl;
                cout << "       ID Film: " << PChild->isidata.idFilm << endl;
                cout << "       Judul Film : " << PChild->isidata.judulFilm << endl;
                cout << "       Durasi Film : " << PChild->isidata.durasiFilm<< endl;
                cout << "       Tahun Tayang : " << PChild->isidata.tahunTayang << endl;
                cout << "       Rating Film : " << PChild->isidata.ratingFilm << endl;
                PChild = PChild->next;
            }
        }
        PParent = PParent->next;
        childKe = 1;
    }
}
