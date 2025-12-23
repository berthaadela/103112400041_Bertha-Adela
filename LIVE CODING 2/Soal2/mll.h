#ifndef MLL_H
#define MLL_H

#include <string>

using namespace std;

typedef struct golonganHewan {
    string idGenre;
    string namaGenre;
} golonganHewan;

typedef struct dataHewan {
    string idFilm;
    string judulFilm;
    int durasiFilm;
    int tahunTayang;
    float ratingFilm;
} dataHewan;

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

typedef struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
} nodeChild;

typedef struct listChild {
    NodeChild first;
    NodeChild last;
} listChild;

typedef struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
} nodeParent;

typedef struct listParent {
    NodeParent first;
    NodeParent last;
} listParent;

bool isEmptyParent(listParent LParent);
bool isEmptyChild(listChild LChild);
void createListParent(listParent &LParent);
void createListChild(listChild &LChild);
NodeParent allocNodeParent(string idGenre, string judulFilm);
NodeChild allocNodeChild(string idFilm, string judulFilm, int durasiFilm, int tahunTayang, float ratingFilm);
void deallocNodeParent(NodeParent &NParent);
void deallocNodeChild(NodeChild &NChild);
void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);
void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertLastChild(listChild &LChild, NodeChild newNChild);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);
void deleteListChild(listChild &LChild);
void printMLLStructure(listParent LParent);

#endif
