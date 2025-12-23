#include "graf.h"

int main() {
    Graph G;
    CreateGraph(G);

    adrNode A = InsertNode(G, 'A');
    adrNode B = InsertNode(G, 'B');
    adrNode C = InsertNode(G, 'C');
    adrNode D = InsertNode(G, 'D');
    adrNode E = InsertNode(G, 'E');

    ConnectNode(A, B);
    ConnectNode(B, E);
    ConnectNode(C, B);
    ConnectNode(C, D);

    cout << "Membangun Jaringan Distribusi Vaksin" << endl;
    PrintInfoGraph(G);

    cout << "\nDFS dari A: ";
    PrintDFS(G, A);

    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->next;
    }

    cout << "\nBFS dari A: ";
    PrintBFS(G, A);

    return 0;
}
