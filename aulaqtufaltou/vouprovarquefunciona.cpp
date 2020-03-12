#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> grafo[1000];
int visitados[1000];
int brancos=0;

void dfs(int next){
  int cores[10];
  memset(cores, -1, sizeof cores);
  for(auto g : grafo[next]){
    if(g.second != -1)
      cores[g.second] = 0;
  }
  cout << next << " ";
  for(auto& g : grafo[next]){
    if(g.second == -1){
      for(int i=0; i<10; i++){
        if(cores[i]){
          g.second = i;
          if(i==0){
            // cout << " branco " << endl;
            brancos++;
          }
        }
      }
      dfs(g.first);
    }
  }
}
//
// int bfs(int first){
//   queue<int> fila;
//   fila.push(first)
//   int brancos=0;
//
//   while(!fila.empty()){
//     int next = fila.top(); fila.pop();
//     for(vector<int,int>& g : grafo[next]){
//       fila.push(g.first);
//
//     }
//
//
//
//   }
// }

int main(){

  int a, b;

  set<int> vertices;
  memset(visitados, -1, sizeof visitados);
  cin >> a >> b;
  pair<int,int> fst, snd;
  fst.first = a;
  fst.second = -1;
  snd.first = b;
  snd.second = -1;
  grafo[0].push_back(fst);
  grafo[0].push_back(snd);
  grafo[a].push_back({0, 0});
  grafo[b].push_back({0, 0});
  grafo[a].push_back(snd);
  grafo[b].push_back(fst);
  vertices.insert(a);
  vertices.insert(b);

  while(cin >> a >> b){
    int i=0;
    fst.first = a;
    fst.second = -1;
    snd.first = b;
    snd.second = -1;
    while(!grafo[i].empty()){
      if(i > 1)
        i = grafo[i][0].first;
      else
        i = grafo[i][1].first;
      cout << i << endl;
    }
    grafo[i].push_back(fst);

    while(!grafo[i].empty()){
      if(i > 1)
        i = grafo[i][0].first;
      else
        i = grafo[i][1].first;
    }
    grafo[i].push_back(snd);

    grafo[a].push_back(snd);
    grafo[b].push_back(fst);
  }

  dfs(0);
  cout << endl;
  int v = vertices.size();

  v = ceil((float)v / 2.0);
  cout << brancos << " ? " << v << endl;
  if(brancos == v){
    cout << "Grupo harmonico\n";
  }else{
    cout << "Grupo violento!\n";
  }
}
