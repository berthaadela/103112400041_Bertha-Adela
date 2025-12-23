#include "mll.h"
#include <iostream>
using namespace std;

int main() {
    listParent LParent;
    createListParent(LParent);
    NodeParent N1 = allocNodeParent("G001", "Action");
    insertLastParent(LParent, N1);
    NodeParent N2 = allocNodeParent("G002", "Comedy");
    insertLastParent(LParent, N2);
    NodeParent N3 = allocNodeParent("G003", "Horror");
    insertLastParent(LParent, N3);
    NodeParent N4 = allocNodeParent("G004", "Romance");
    insertLastParent(LParent, N4);


    NodeChild C1 = allocNodeChild("FA001", "The Raid", 101, 2011, 7.6);
    insertLastChild(N1->L_Child, C1);

    NodeChild C2 = allocNodeChild("FC001", "Agak Laen", 119, 2024, 8.0);
    insertLastChild(N2->L_Child, C2);
    NodeChild C3 = allocNodeChild("FC002", "My Stupid Boss", 108, 2016, 6.8);
    insertLastChild(N2->L_Child, C3);

    NodeChild C4 = allocNodeChild("FH001", "Pengabdi Setan", 107, 2017, 8.4);
    insertLastChild(N3->L_Child, C4);

    NodeChild C5 = allocNodeChild("FR001", "Habibie & Ainun", 118, 2012, 7.6);
    insertLastChild(N4->L_Child, C5);
    NodeChild C6 = allocNodeChild("FR002", "Dilan 1990", 110, 2018, 6.6);
    insertLastChild(N4->L_Child, C6);

    printMLLStructure(LParent);
}