/*
input
5
0 3 2 3 3 1 1 2
1 2 0 2 3 4
2 3 0 3 3 1 4 1
3 4 2 1 0 1 1 4 4 3
4 2 2 1 3 3

output
0 0
1 2
2 2
3 1
4 3
*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX 100000
#define WHITE 0
#define BLACK -1

typedef struct{
  int k;
  int *wgt;
  int *num;
}vector;

int n;
vector M[MAX];

void dijkstra(){
  int i, u, v, minv, tmp;
  int d[n], color[n];

  for( i=0; i<n; i++ ){
      d[i] = INT_MAX;
      color[i] = WHITE;
    }

  d[0] = 0;                  
  while(1){
      minv = INT_MAX;          
      for( i=0; i<n; i++ ){
          if( minv > d[i] && color[i] != BLACK ){
	      u = i;
	      minv = d[i];
	    }
      }
      if( minv == INT_MAX ) break;  
      
      color[u] = BLACK;
      
      for( v=0; v<M[u].k; v++ ){
          tmp = M[u].num[v];  
          if( color[tmp] != BLACK ){
	      if( d[tmp] > d[u] + M[u].wgt[v] )d[tmp] = d[u] + M[u].wgt[v];
		
	    }
      }
    }
    for( i=0; i<n; i++ )printf("%d %d\n", i, d[i]);
}
int main(){
  int i, j, u, k, v, c,p;
  
  scanf("%d", &n);
  
  for( i=0; i<n; i++ ){
      scanf("%d%d", &p, &M[i].k);
      M[p].wgt = (int *)malloc( M[i].k * sizeof(int));
      M[p].num = (int *)malloc( M[i].k * sizeof(int));

      for( j=0; j<M[i].k; j++ ) scanf("%d%d", &M[p].num[j], &M[p].wgt[j]);
  }

  dijkstra();

  for( i=0; i<n; i++ ){
      free( M[i].wgt );
      free( M[i].num );
  }
  return 0;
}
