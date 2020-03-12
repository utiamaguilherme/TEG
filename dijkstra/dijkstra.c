
#include <stdio.h>

int output[61], idx = 0;

const long inf = 1e6;

int n, e;//quant nodos e arestas

int custo[61][61], R[61], F[61], S[61];
int inicio;
void lerGrafo();
void dijkstra();
void solve(int);
void get(int);

int main() {

    // no inicial
    scanf("%d",&inicio);

    lerGrafo();
    dijkstra();
    solve( inicio );

    return(0);
}

void lerGrafo() {

     int i,j,x,y;
     float c;

     scanf("%d", &n);
     for(i=1;i<=n;i++) {
         for(j=1;j<=n;j++) {
            if(i == j)    custo[i][j] = 0;
            else    custo[i][j] = inf;

         }
     }

     while(scanf( "%d %d %f", &x, &y, &c) != EOF) {
            custo[x][y] = c;
     }

     for(i=1;i<=n;i++) {
         for(j=1;j<=n;j++) {
             printf("%5d ", custo[i][j]);
         }
             printf("\n");
     }
}

void dijkstra(){
     int i, j, k, start = 1, min, pos = 0;
     for(i=1;i<=n;i++) {
         R[i] = custo[start][i];

         if(i!=start)
            if(R[i] < inf) F[i] = start;
     }
     S[start] = 1;

     //executa n-1 vezes
     for(i=1;i<=n-1;i++) {
         min = inf;
         for(j=1;j<=n;j++) {
            if(S[j] == 0)
             if(R[j]<min){
                min = R[j];
                pos = j;
             }
         }
         S[ pos ] = 1;
         for(j=1;j<=n;j++) {
             if(S[j] == 0)
                if(R[ j ] > R[ pos ] + custo[ pos ][ j ]) {
                   R[ j ] = R[ pos ] + custo[ pos ][ j ];
                   F[ j ] = pos;
                }
         }
     }
}

void solve(int node ) {
     int i;
     get(node);
     printf("\n\nO Custo de 1 para %d = %d\nCaminho mais curto eh -> ", inicio, R[inicio]);
     for(i=0;i<n;i++) {
         if(output[i]) printf("%d ", output[i]);
     }
     printf("\n");
}

void get(int node ) {
     if(F[ node ]) get( F[ node ] );
     output[idx++] = node;
}
