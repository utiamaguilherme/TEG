#include <bits/stdc++.h>
#define TAM 55

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<long long, pii > iii;


using namespace std;
int m, n;
int mat[TAM][TAM];
int caso;
long long ans;
vii *graph;
int dist[TAM][TAM];

void dijkstra(int o, int d){
    memset(dist,0x3F3F3F3F, sizeof(dist));
    priority_queue<iii, vector<iii>, greater<iii> > pq;
    dist[origem]= 0;
    pq.push({dist[o][d], {o,d}})
    while(!pq.empty()){
        
    }
}
int main(){

    cin >> caso;
    for(int i=0; i<caso; i++){
        cin >> m >> n;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cin >> mat[i][j];
            }
        }
        for(int i=0; i<n; i++)
            dijkstra(0, i);


        cout << "Caso #" << i+1 << " : CUSTO: " << ans << endl;
    }

}
