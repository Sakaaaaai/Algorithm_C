/*
input
6
D 3
H 2
D 1
S 3
D 2
C 1

output
Not stable
D 1
C 1
D 2
H 2
D 3
S 3
*/


#include<stdio.h>

#define N 100000
#define NIL -1

int partition(int,int);
void quicksort(int,int);
void print(void);
int judge(void);

char array_ch[N], array_ch2[N], tmp_ch;
int array_1[N], array_2[N], n, tmp;

int main(){
    
  int i,j;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf(" %c %d",&array_ch[i],&array_1[i]);
    array_ch2[i]=array_ch[i];
    array_2[i]=array_1[i];
  }
  
  quicksort(0,n-1);

  print();
    
  return 0;
}

int partition(int p,int r){
  int x, i, j, sub;

  x=array_1[r];
  i=p-1;

  for(j=p;j<r;j++){
    if(array_1[j]<=x){
      i++;
 
      tmp_ch=array_ch[i];
      array_ch[i]=array_ch[j];
      array_ch[j]=tmp_ch;

      tmp=array_1[i];
      array_1[i]=array_1[j];
      array_1[j]=tmp;
    }
  }

  tmp_ch=array_ch[i+1];
  array_ch[i+1]=array_ch[r];
  array_ch[r]=tmp_ch;

  tmp=array_1[i+1];
  array_1[i+1]=array_1[r];
  array_1[r]=tmp;

  return i+1;
}

void quicksort(int p,int r){
  int q;
  
  if(p<r){
    q=partition(p,r);
    quicksort(p,q-1);
    quicksort(q+1,r);
  }
}

void print(void){
int i;
if(judge()==0) printf("Stable\n");

  else printf("Not stable\n");
  
  for(i=0;i<n;i++) printf("%c %d\n",array_ch[i],array_1[i]);
}

int judge(void){
  int i, j;

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){

      if(array_1[i]==array_2[j]){
	array_2[j]=NIL;
	if(array_ch[i]!=array_ch2[j]) return 1;
	else break;
      }
    }
  }
  
  return 0;
}



