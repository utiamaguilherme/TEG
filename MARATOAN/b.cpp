#include <bits/stdc++.h>
#define MAX 100009

using namespace std;

long long inv, arr[MAX], aux[MAX];
int m, k;   

void merge(int l, int r){
    if(l == r)  return;
    
    int m = (l+r)/2;
    
    merge(l,m);
    merge(m+1,r);
    
    int i = l;
    int j = m + 1;
    int k = l;
    
    while ( i <= m and j <= r ) {
        if ( arr [i] > arr [j] ) {
            aux[k++] = arr[j++];
            inv += j - k;
        }
        else 
            aux [k++] = arr[i++];
    }
    while ( i <= m) aux [ k++] = arr [ i++];
    for ( i = l ; i < k; i++) arr[i] = aux[i];
        
}

int bubble(int k){
    int r=0;
    for(int i=0; i<k; i++){
        for(int j=1; j<m; j++){
            if(arr[j-1] > arr[j]){
                r++;
                int t = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = t;
            }
        }
    }
    return r;
}

int main(){
    int n; cin >> n;
    for(int a = 1; a<=n; a++){
        cin >> m >> k;
        
        for(int i=0; i<m; i++){
            arr[i] = m-i;
        }      
              
        cout << bubble(k) << endl;;
        
        for(int i=0; i<m; i++){
            cout << arr[i] << " ";
        }cout << endl;
        
        
        merge(0, m);
        
                for(int i=0; i<m; i++){
            cout << arr[i] << " ";
        }cout << endl;
            
        
        long long value;    cin >> value;
        
        cout << "Case #" << a << ": " << inv % value << "\n";
    }
}
