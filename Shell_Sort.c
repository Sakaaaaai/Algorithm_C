#include <stdio.h>

#define MAX_N 1000000
#define MAX_M 100
#define min(a,b) a < b ? a : b

void shellSort(int*,int);
void insertionSort(int*,int,int);
void print(int*,int*,int,int);

int cnt;

int main(){
  int N,i,a[MAX_N];

  scanf("%d" ,&N);
  for(i = 0 ; i < N ; i++){
    scanf("%d" ,a+i);
  }
  shellSort(a,N);

  return 0;
}

void shellSort(int a[],int N){
  int G[MAX_M],p = 0,m,i;
  cnt = 0;

  for(m = 1 ; m*3+1 < N ; m = m*3+1){};
  for(; m > 0 ; m /= 3){
    G[p++] = m;
  }

  p = min(p,100);
  for(i = 0 ; i < p ; i++){
    insertionSort(a,N,G[i]);
  }
  print(a,G,N,p);
}

void insertionSort(int a[],int N,int g){
  int i,v,j;

  for(i = g ; i < N ; i++){
    v = a[i]; j = i - g;
    while(j >= 0 && a[j] > v){
      a[j+g] = a[j];
      j -= g;
      cnt++;
    }
    a[j+g] = v;
  }
}

void print(int a[],int G[],int N,int m){
  int i;
  
  printf("%d\n" ,m);
  for(i = 0 ; i < m ; i++){
    if(i != m-1){
      printf("%d " ,G[i]);
    }else{
      printf("%d\n" ,G[i]);
    }
  }
  printf("%d\n" ,cnt);
  for(i = 0 ; i < N ; i++){
    printf("%d\n" ,a[i]);
  }
}
