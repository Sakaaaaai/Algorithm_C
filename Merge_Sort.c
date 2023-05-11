#include <stdio.h>
#include <math.h>

#define N 500000

void merge(int* ,int ,int ,int );
void mergeSort(int* ,int ,int );
  
int S[N], count=0;

int main()
{
  int i, j, n;

  scanf("%d",&n);

  for(i=0;i<n;i++)scanf("%d",&S[i]);

  mergeSort(S, 0, n);
 
  for(j=0;j<n-1;j++)printf("%d ",S[j]);
 
  printf("%d\n",S[j]);

  printf("%d\n",count);

  return 0;
}

void merge(int* A,int left,int mid,int right){
  
  int n1, n2, i, j, k;
  
  n1 = mid - left;
  n2 = right - mid;
  
  int l[n1],r[n2];

  for(i=0;i<n1;i++)l[i] = A[left+i];
  for(i=0;i<n2;i++)r[i] = A[mid+i];
  
  l[n1] = INFINITY;
  r[n2] = INFINITY;
  
  i=0;
  j=0;
  
  for(k=left;k<right;k++){
    
    if(l[i] <= r[j]){
      A[k] = l[i];
      i++;
      count++;
    }

    else {
      A[k]=r[j];
      j++;
      count++;
    }
  }
}
  
void mergeSort(int* A,int left,int right){
  
  int mid;
  
  mid = (left+right)/2;
  
  if(left+1<right){
    
    mid = (left+right)/2;
    
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}

