#include <stdio.h>
#include <stdlib.h>
  
  int main()
{
  int n, i=0, j=0, array[1000], k, key;
  
  scanf("%d",&n);

  for(i=0;i<n;i++)
    {
      scanf("%d",&array[i]);
    }

 for(k=0;k<n-1;k++)printf("%d ",array[k]);
 printf("%d",array[n-1]);
  printf("\n");
  
  for(i=1;i<n;i++)
    {
      key = array[i];
      j = i - 1;
      
      while(j >= 0 && array[j] > key)
	{
	  array[j+1] = array[j];
	  j--;
	}
      
      array[j+1] = key;
      
      for(k=0;k<n-1;k++)printf("%d ",array[k]);
      printf("%d",array[n-1]);
      printf("\n");
 
    }
   
  return 0;
}



