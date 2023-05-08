/*
input
6
30 35
35 15
15 5
5 10
10 20
20 25

output
15125
*/


#include <stdio.h>
#include <math.h>

#define N 100

int Min(int X,int Y){
    if(X<Y)return X;
    else return Y;
}

int A[N + 1],B[N + 1][N + 1];

int main(){
    int i,j,k,num;
    int n;
    
   scanf("%d",&n);

    for( i = 1;i <= n;++i)scanf("%d %d",&A[i - 1],&A[i]);

    for( num = 2;num <= n;++num){

        for( i = 1;i <= n - num + 1;++i){

             j = i + num - 1;

            B[i][j] = INFINITY;

            for( k = i;k <= j - 1;++k)B[i][j] = Min(B[i][j],B[i][k] + B[k + 1][j] + A[i - 1] * A[k] * A[j]);            
        }
        
    }

   printf("%d\n",B[1][n]);

   return 0;
}
