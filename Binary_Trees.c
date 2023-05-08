/*
input
9
0 1 4
1 2 3
2 -1 -1
3 -1 -1
4 5 8
5 6 7
6 -1 -1
7 -1 -1
8 -1 -1

output
node 0: parent = -1, sibling = -1, degree = 2, depth = 0, height = 3, root
node 1: parent = 0, sibling = 4, degree = 2, depth = 1, height = 1, internal node
node 2: parent = 1, sibling = 3, degree = 0, depth = 2, height = 0, leaf
node 3: parent = 1, sibling = 2, degree = 0, depth = 2, height = 0, leaf
node 4: parent = 0, sibling = 1, degree = 2, depth = 1, height = 2, internal node
node 5: parent = 4, sibling = 8, degree = 2, depth = 2, height = 1, internal node
node 6: parent = 5, sibling = 7, degree = 0, depth = 3, height = 0, leaf
node 7: parent = 5, sibling = 6, degree = 0, depth = 3, height = 0, leaf
node 8: parent = 4, sibling = 5, degree = 0, depth = 2, height = 0, leaf
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct { 
    int parent;
    int left;
    int right;
    } Node;

Node node[10000];

int n, A_1[10000], tmp[10000];

void depth_cal(int,int);
int height_cal(int);
int sib_cal(int);
void print(int);

int main(void) {
  int v, left, right, root = 0;

  scanf("%d",&n);

  for(int i=0;i<n;i++) node[i].parent = -1;

  for(int i=0;i<n;i++) {

    scanf("%d %d %d",&v,&left,&right);

    node[v].left  = left;
    node[v].right = right;

    if(left != -1) node[left].parent = v;
    if(right != -1) node[right].parent = v;
  }
  
  for(int i=0; i<n; i++)if(node[i].parent == -1) root = i;
  
  depth_cal(root,0);
  height_cal(root);
  
  for(int i=0;i<n;i++) print(i);
  
  return 0;
}

void depth_cal(int data,int d) {
  if(data == -1) return;

  A_1[data] = d;

  depth_cal(node[data].left, d+1);
  depth_cal(node[data].right,d+1);
}

int height_cal(int data) {
  int data_a = 0, data_b = 0;
  if(node[data].left != -1)data_a = height_cal(node[data].left) + 1;

  if(node[data].right != -1)data_b = height_cal(node[data].right) + 1;

  return tmp[data] = (data_a > data_b ? data_a : data_b);
}


int sib_cal(int data) {
  if( node[data].parent == -1 ) return -1;

  if(node[node[data].parent].left != data && node[node[data].parent].left != -1 )return node[node[data].parent].left;

  if(node[node[data].parent].right != data && node[node[data].parent].right != -1 )return node[node[data].parent].right;

  return -1;
}

void print(int data) {
     int a = 0;
  printf("node %d: ",data);
  printf("parent = %d, ",node[data].parent);
  printf("sibling = %d, ",sib_cal(data));
 
  if(node[data].left  != -1) a++;
  if(node[data].right != -1) a++;

  printf("degree = %d, ",a);
  printf("depth = %d, ",A_1[data]);
  printf("height = %d, ",tmp[data]);
  
  if(node[data].parent == -1) {
    printf("root\n");
  }
  
   else if(node[data].left == -1 && node[data].right == -1) {
    printf("leaf\n");
  } 
  
  else {
    printf("internal node\n");
  }
}


