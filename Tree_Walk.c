#include<stdio.h>

#define MAX 100000

typedef struct Node{
  int parent;
  int right;
  int left;
}Node;


Node array[MAX];

void Pre(int n){
  
  if (n == -1) return;

  printf(" %d",n);

  Pre(array[n].left);

  Pre(array[n].right);
  
}

void In(int n){
  if(n == -1) return;

  In(array[n].left);

  printf(" %d",n);

  In(array[n].right);
  
}

void Post(int n){
  if(n == -1) return;

  Post(array[n].left);
  Post(array[n].right);

  printf(" %d",n);

}

void Print(int data){

  printf("Preorder\n");
  Pre(data);
  printf("\n");

  printf("Inorder\n");
  In(data);
  printf("\n");

  printf("Postorder\n");
  Post(data);
  printf("\n");

}


int main(){

  int i,j,k;  
  int v,lef,rig;
  int data,num;
  

  
  scanf("%d",&num);

  for(i=0;i<num;i++){
    array[i].parent = -1;
  }

  for(i=0;i<num;i++){

    scanf("%d %d %d",&v,&lef,&rig);

    array[v].left = lef;
    array[v].right = rig;

    if(lef != -1) array[lef].parent = v;
    if(rig != -1) array[rig].parent = v;
  }

  for(i=0;i<num;i++){
    if(array[i].parent == -1) data = i;
  }

  Print(data);
  
  return 0;
}



