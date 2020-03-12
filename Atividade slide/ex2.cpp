#include <bits/stdc++.h>

using namespace std;

int main() {

    int nodes, edges; cin >> nodes >> edges;
    int nodeA, nodeB;

    int grafo[nodes][nodes+1];
    memset(grafo, 0, sizeof(grafo));

    for(int i=0; i<edges; i++){
        cin >> nodeA >> nodeB;
        grafo[--nodeA][--nodeB] = 1;
        grafo[nodeA][nodes]++;
        grafo[nodeB][nodes]++;
    }

    for(int i=0; i<nodes; i++){
        for(int j=0; j<nodes; j++){
            cout << grafo[i][j] << " ";
        }
        cout << " No " << i+1 << " -> grau = " << grafo[i][nodes] << endl;
    }

    return 0;
}
