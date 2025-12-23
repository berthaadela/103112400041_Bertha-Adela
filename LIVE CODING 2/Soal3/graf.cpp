#include "graf.h"
#include <stack>
#include <queue>

void CreateGraph(Graph &G) {
    G.first = NULL;
}

adrNode InsertNode(Graph &G, infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->next = NULL;

    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->next != NULL)
            Q = Q->next;
        Q->next = P;
    }
    return P;
}

void ConnectNode(adrNode N1, adrNode N2) {
    adrEdge E1 = new ElmEdge;
    E1->node = N2;
    E1->next = N1->firstEdge;
    N1->firstEdge = E1;

    adrEdge E2 = new ElmEdge;
    E2->node = N1;
    E2->next = N2->firstEdge;
    N2->firstEdge = E2;
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << P->info << " : ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

void PrintDFS(Graph G, adrNode start) {
    stack<adrNode> S;
    S.push(start);

    while (!S.empty()) {
        adrNode x = S.top();
        S.pop();

        if (x->visited == 0) {
            x->visited = 1;
            cout << x->info << " ";

            adrEdge E = x->firstEdge;
            while (E != NULL) {
                if (E->node->visited == 0) {
                    S.push(E->node);
                }
                E = E->next;
            }
        }
    }
}

void PrintBFS(Graph G, adrNode start) {
    queue<adrNode> Q;
    Q.push(start);

    while (!Q.empty()) {
        adrNode x = Q.front();
        Q.pop();

        if (x->visited == 0) {
            x->visited = 1;
            cout << x->info << " ";

            adrEdge E = x->firstEdge;
            while (E != NULL) {
                if (E->node->visited == 0) {
                    Q.push(E->node);
                }
                E = E->next;
            }
        }
    }
}
