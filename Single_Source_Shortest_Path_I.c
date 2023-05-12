#include <stdio.h>
//#include <math.h>

#define MAX 101
#define INFTY 9999999
#define NIL -1

#define WHITE 0
#define GRAY 1
#define BLACK 2

int n,data[MAX][MAX];
int d[MAX],color[MAX];

typedef struct num
{
    int A;
    int B;
    int C;
    int D;
    int min;
} Num;

Num number;

void print(void){
    int i;
for(i=0;i<n;i++){
    printf("%d ",i);
    if(d[i]!=INFTY)printf("%d\n",d[i]);
    else printf("-1\n");
  }
}

void setup(){
int i,j;

scanf("%d",&n);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      data[i][j]=INFTY;
    }
  }
  
  for(i=0;i<n;i++){

    scanf("%d%d",&number.C,&number.A);

    for(j=0;j<number.A;j++){

      scanf("%d%d",&number.D,&number.B);

      data[number.C][number.D]=number.B;
    }
  }
}

int main(){
  int i,j;
    
  setup();

  number.C=0;
  number.D=0;

  for(i=0;i<n;i++){
    d[i]=INFTY;
    color[i]=WHITE;
  }

  d[0]=0;
  color[0]=GRAY;

  for(;;){
    number.min=INFTY;
    number.C=NIL;

    for(i=0;i<n;i++){

      if(number.min>d[i] && color[i]!=BLACK){
	number.C=i;
	number.min=d[i];
      }
    }
  
    if(number.C==NIL)break;
    color[number.C]=BLACK;

    for(number.D=0;number.D<n;number.D++){
      if(color[number.D]!=BLACK && data[number.C][number.D]!=INFTY){
	if(d[number.D]>d[number.C]+data[number.C][number.D]){
	  d[number.D]=d[number.C]+data[number.C][number.D];
	  color[number.D]=GRAY;
	}
      }
    }
  }

  print();
  
  return 0;
}


