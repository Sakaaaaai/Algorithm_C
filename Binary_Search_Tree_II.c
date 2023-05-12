#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NIL -1

typedef struct{
  int key;
  int left;
  int right;
}NODE;

int stack;
NODE data[500000];

void insert(int);
void In(int);
void Pre(int);
int Find(int,int);
 

int main(){
int n, i, in, F=1, judge;

scanf("%d", &n);

for(i=0;i<=n;i++) data[i].key = data[i].left = data[i].right = NIL;

stack = 0;

while(n--){
char array[100];

scanf("%s", array);

if(array[0] == 'i'){
    
  scanf("%d", &in);

  if(F){
data[stack++].key = in;
    F = 0;
  }

  else insert(in);
}
else if(array[0] == 'f'){
      scanf("%d", &in);

      judge = Find(0, in);
      if(judge == 1)printf("yes\n");
      else printf("no\n");
      
}
else{
  In(0);

  printf("\n");

  Pre(0);

  printf("\n");
}

}
  return 0;
}
    
void insert(int x){
int A = 0;

while(1){
if(x < data[A].key){
  if(data[A].left == NIL){
    data[A].left = stack;
    data[stack++].key = x;
    break;
  }
  else A = data[A].left;
    }
    else{
  if(data[A].right == NIL){
    data[A].right = stack;
    data[stack++].key = x;
    break;
  }
  else A = data[A].right;
    }
}
}

void In(int A){
  if(data[A].left != NIL)In(data[A].left);

  printf(" %d", data[A].key);
  
  if(data[A].right != NIL)In(data[A].right);
}
 
void Pre(int A){

  printf(" %d", data[A].key);

  if(data[A].left != NIL)Pre(data[A].left);
  if(data[A].right != NIL)Pre(data[A].right);

}

int Find(int A, int x){
  if(data[A].key == x) return 1;

  if(x < data[A].key && data[A].left != NIL) {
    if(Find(data[A].left, x)) return 1;
  }

  if(data[A].key < x && data[A].right != NIL){
    if(Find(data[A].right, x)) return 1;
  }
  
  return 0;
}
