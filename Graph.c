/*
input
4
1 2 2 4
2 1 4
3 0
4 1 3

output
0 1 0 1
0 0 0 1
0 0 0 0
0 0 1 0
*/

#include<stdio.h>

#define N 101


int queue[N][N];

void Clear(int );

void Print(int );


int main(){
  int i,j;
  int n,k,u,v;

  scanf("%d",&n);

  Clear(n);

  for(i=0;i<n;i++){

    scanf("%d%d",&u,&k);

    for(j=0;j<k;j++){

      scanf("%d",&v);

      queue[i][v-1] = 1;
    }

  }

Print(n);

    return 0;

}

void Clear(int n){

int i,j;

for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      queue[i][j]=0;
      
}

void Print (int n){

int i,j;

for(i=0;i<n;i++){

      if(i!=0)printf("\n");

      for(j=0;j<n;j++){

       	printf("%d",queue[i][j]);

	if(j!=n-1)printf(" ");

      }
    }

    printf("\n");
}
