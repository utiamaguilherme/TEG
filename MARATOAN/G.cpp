#include <bits/stdc++.h>
#define max 1005
using namespace std;

long long v, e, cEstrada, cEstadio;
int see[max];
long long sumEdg;
long long sumVer;
long long sum;
vector<int> graph[1005];

void dfs(int k){
    see[k] = 1;
    sumVer++;
    for(auto visto : graph[k]){
        sumEdg++;
        if(!see[visto]){
            dfs(visto);
        }
    }
}


int main(void){
    while(scanf("%lld %lld %lld %lld", &v, &e, &cEstrada, &cEstadio) != EOF){
        memset(see,0,sizeof see);
        
        for(int i=0; i<e; i++){
            long long a,b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        for(int i=1; i<=v; i++){
            if(!see[i]){
                sumEdg = 0;
                sumVer = 0;
                dfs(i);
                if(sumVer == 1) continue;
                sumEdg/=2;
                long long n = sumVer-1;
                n = ( (n * (n+1)) / 2 ) - sumEdg;
                
                if(n * cEstrada < sumVer * cEstadio) {
                    sum += n * cEstrada;
                }else{
                    sum += sumVer * cEstadio;
                }
                         
            }
        }
        cout << sum << endl;
        sum = 0;
        for(int i=0; i<=v; i++){
            graph[i].clear();
        }
    }
    
}

