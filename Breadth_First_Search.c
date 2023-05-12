#include <stdio.h>
#include <string.h>

#define MAX 100
#define INF 1000000
#define NIL -1

typedef struct Num
{
int a;
int b;
int c;
}Number;


int main()
{
  int A[MAX][MAX], queue[MAX], data[MAX];
  int cnt[MAX];
  int i, j;
  int id, n, head=0, tail=0;

  Number Num;

  scanf("%d", &n);

  for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < n ; j++){

            A[i][j] = 0;

        } 
    }

  for(i = 0 ; i < n ; i++){

    scanf("%d%d", &Num.a, &Num.b);

    for(j = 0 ; j < Num.b ; j++){

      scanf("%d", &Num.c);

      A[Num.a-1][Num.c-1] = 1;
    }
  }

  queue[tail] = 0;

  tail++;; 

  data[0] = 0;

  for(i = 1 ; i < n ; i++)data[i] = INF;
  
  while(tail != head){

  head++;

   id = queue[head-1];

    for(i = 0 ; i < n ; i++){

	    if(A[id][i] == 0 || data[i] < data[id]+1 || cnt[i] == 1 || data[i] != INF) continue;

	    data[i] = data[id]+1;

	    queue[tail] = i;

        tail++;
        
      cnt[i] = 1;
    }
  }

  for(i = 0 ; i < n ; i++){

    if(data[i] == INF) data[i] = NIL;

    printf("%d %d\n", i+1, data[i]); 
  } 

  return 0;
}



