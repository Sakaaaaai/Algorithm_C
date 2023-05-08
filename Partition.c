/*
input
12
13 19 9 5 12 8 7 4 21 2 6 11

output
9 5 8 7 4 2 6 [11] 21 13 19 12
*/


#include <stdio.h>

int a[100000],n;

void swap(int A, int B){
    int tmp;
    tmp = a[A];
    a[A] = a[B];
    a[B] = tmp;
}

int part(int p,int r){
  int i = p-1,j;

  for(j=p;j<r;j++){
    if(a[j]<=a[r]){
      i++;

      swap(i,j);

    }
  }
   
    swap(i+1,r);

    return i+1;
}

int main(){
  int n,i,id;

  scanf("%d",&n);

  for(i=0;i<n;i++)scanf("%d",&a[i]);

  id = part(0,n-1);

  for(i=0;i<id;i++)printf("%d ",a[i]);

  printf("[%d] ",a[i++]);

  for(;i<n-1;i++) printf("%d ",a[i]);

  printf("%d\n",a[i]);

  return 0;
}

