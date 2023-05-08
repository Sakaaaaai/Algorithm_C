/*
input
5
1 2 3 4 5
3
3 4 1
output
3
*/

#include <stdio.h>

#define N 100000

int binarySearch(int);

int array[N],data;

int main()
{
  int sourse,i, j, n, count=0;
  
  scanf("%d",&data);
  
  for(i=0;i<data;i++)scanf("%d",&array[i]);

  
  scanf("%d",&n);
  
  for(j=0;j<n;j++){
    
    scanf("%d",&sourse);
    
    if(binarySearch(sourse)==1){
      count++;
    }
  }

  printf("%d\n",count);
  
  return 0;
}


int binarySearch(int k) {
  
    int le = 0, ri = data, mid;
    
    while (le < ri) {
      
        mid = (le + ri) / 2;
	
        if (k == array[mid]){
	  return 1;
	}
	
        if (k > array[mid]){
	  le = mid + 1;
	}
	
        else if (k < array[mid]){
	  ri = mid;
	}
    }
    return 0;
}

