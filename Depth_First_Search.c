#include <stdio.h>

#define WHITE 10
#define GRAY 20
#define BLACK 30

#define N 100
#define N_2 200

int time = 0;

int d[N_2],f[N_2];
int color[N], u[N], outdegree[N];
int v[N][N];
int n;

void visit(int u){
    int i = 0; 
    color[u] = GRAY;
    d[u] = ++time;
    for(i = 0;i < outdegree[u]; i++){
        if(color[v[u][i]] == WHITE){
        visit(v[u][i]);    
        }
    }
    color[u] = BLACK;
    f[u] = ++time;
}


void Print(int n){

int i;

for(i = 1; i<=n; i++){
    printf("%d %d %d\n",i,d[i],f[i] );
 }
}


int main(void){

int i, j;
int n;

scanf("%d",&n);

for(i=0;i<n;i++){

    scanf("%d",&u[i]);

    color[u[i]] = WHITE;

    scanf("%d",&outdegree[u[i]]);

    for(j = 0;j< outdegree[u[i]]; j++ ){

        scanf("%d",&v[u[i]][j]);

    }
}

for(i = 1;i<=n;i++){
    if(color[i] == WHITE){
        visit(i);
    }
}

Print(n);

return 0;

}

