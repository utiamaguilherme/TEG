#include <bits/stdc++.h>

#define max 100
#define sz(x) sizeof(x)
#define ll long long

using namespace std;

vector<ll> vet;


int main(void){
    int nos, arestas;
    // cout << "1. Direcionado" << endl << "2. nao-direcionado" << endl;
    int n;
    while(cin >> n){

        cin >> nos >> arestas;
        ll graph[nos][nos];
        int no1,no2;
        memset(graph, 0, sz(graph));
        int grau[nos];
        memset(grau, 0, sz(grau));
        switch(n){
            case 1:
            cout << "Direcionado: " << endl;
            for(int i=0; i<arestas; i++){

                    cin >> no1 >>no2;
                    graph[--no1][--no2] = 1;

                    grau[no1] += 1;
                    grau[no2] += 1;

            }

            for(int i=0; i<nos; i++){
                for(int j=0; j<nos; j++){
                    cout << graph[i][j] << " ";
                }
                cout << "-> Grau do no " << i+1 << ": " << grau[i] << endl;

            }
            break;


            case 2:

            cout << "Nao Direcionado: " << endl;
                for(int j=0; j<arestas; j++){
                    cin >> no1 >>no2;
                    if(no1 >= no2)  graph[--no1][--no2] += 1;
                    else    graph[--no2][--no1] += 1;
                    grau[no1] += 1;
                    grau[no2] += 1;

                }

                for(int i=0; i<nos; i++){
                    for(int j=0; j<nos; j++){
                        cout << graph[i][j] << " ";
                    }
                    cout << "-> Grau do no " << i+1 << ": " << grau[i] << endl;

                }
                break;
        }

                // cout << "1. Direcionado" << endl << "2. nao-direcionado" << endl;
    }

}
