#include <bits/stdc++.h>

using namespace std;

int n, p, q, m;
unsigned int SA, SB, SC;
unsigned long long ans;

vector<pair<unsigned int, unsigned int>> stk;

unsigned int rng61() {
    
    SA ^= SA << 16;
    SA ^= SA >> 5;
    SA ^= SA << 1;
    unsigned int t=SA;
    SA=SB;
    SB=SC;
    SC ^= t ^ SA;
    return SC;
}

int gen() {

    if(scanf("%d%d%d%d%u%u%u", &n, &p, &q, &m, &SA, &SB, &SC) == EOF)
        return -1;
    for(int i=1; i<=n; i++){
        if(rng61() % (p+q) < p) {
            if(!stk.empty()){
                unsigned int a = rng61() % m + 1;
                stk.push_back({a, (a < stk[stk.size()-1].second ? stk[stk.size()-1].second : a)});
            }
            else{
                stk.push_back({rng61() % m + 1, 0});
            }
        }
        else{
            stk.pop_back();
        }
        if(stk.size() > 0){ 
          ans ^= (i*stk[stk.size()-1].second);
       }else {
         ans ^= (i*0);
       }
    }
}

long long cont;

int main(){
    cont = 1;
    while(gen() != -1){       
        cout << "Case #" << cont << ": " << ans;
        stk.clear();
        ans = 0;        
        cont++;        
    }
}
