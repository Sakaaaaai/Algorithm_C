/*
input
8
insert 30
insert 88
insert 12
insert 1
insert 20
insert 17
insert 25
print

output
 1 12 17 20 25 30 88
 30 12 1 20 17 25 88
*/


#include <stdio.h>
#include <string.h>

#define NIL -1

typedef struct{
  int key;
  int left;
  int right;
}NODE;

int stack;
NODE data[500000];

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

int main(){
int n, i, in, F=1;

scanf("%d", &n);

for(i=0;i<=n;i++) data[i].key = data[i].left = data[i].right = -1;

stack = 0;

while(n--){
char array[100];

scanf("%s", array);

if(!strcmp(array, "insert")){
    
  scanf("%d", &in);

  if(F){
data[stack++].key = in;
    F = 0;
  }

  else insert(in);
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
    

