/*
input
3
abcbdab
bdcaba
abc
abc
abc
bc

output
4
3
2
*/


#include <stdio.h>
#include <string.h>

#define N 1001 

int Max(int X,int Y){
    if(X>Y)return X;
    else return Y;
}

int data[N][N];
char X[N],Y[N];

int main(){

    int i,j,k;
	int num;

	scanf("%d",&num);

	while(num--){

		scanf("%s %s",X,Y);

		int n = strlen(X);
		int m = strlen(Y);

		for(i=1;i<=n;i++)
           for(j=1;j<=m;j++){

			if(X[i-1]==Y[j-1])data[i][j] = data[i-1][j-1]+1;

			else if(X[i-1]!=Y[j-1]) data[i][j] = Max(data[i-1][j],data[i][j-1]);
			
		   }
        

		printf("%d\n",data[n][m]);

	}
    return 0;
}

