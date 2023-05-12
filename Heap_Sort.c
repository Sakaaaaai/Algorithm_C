#include<stdio.h>
#define H 200001
int heap[H];

void maxHeapify(int i,int n){
  int left=i*2,right=i*2+1,largest;
  if(left<=n && heap[left]>heap[i])largest=left;
  else largest=i;
  if(right<=n && heap[right]>heap[largest])largest=right;

  if(largest!=i){
    int alt;
    alt=heap[i];
    heap[i]=heap[largest];
    heap[largest]=alt;
    maxHeapify(largest,n);
  }
}

void heapSort(int n){
  //buildMaxHeap
  for(int i=n/2;i>0;i--)maxHeapify(i,n);
  //sort
  int heapSize=n;
  while(heapSize>1){
    int alt=heap[1];
    heap[1]=heap[heapSize];
    heap[heapSize]=alt;
    heapSize--;
    maxHeapify(1,heapSize);
  }
}

void heapDeSort(int n){
  int alt,i,heapSize=1;
  while(heapSize<n){
    i=heapSize;
    while(i>1){
      alt=heap[i/2];
      heap[i/2]=heap[i];
      heap[i]=alt;
      i/=2;
    }
    heapSize++;
    alt=heap[1];
    heap[1]=heap[heapSize];
    heap[heapSize]=alt;
  }
}

int main(){
  int i,n;
  scanf("%d",&n);
  for(i=1;i<n+1;i++)scanf("%d",&heap[i]);
  heapSort(n);
  heapDeSort(n);
  for(i=1;i<n+1;i++){
    if(i-1)printf(" %d",heap[i]);
    else printf("%d",heap[i]);
  }
  printf("\n");
  return 0;
}
