#include<stdio.h>

int main()
{
  int i, j, n, A[100], minj, tmp, count=0;
	
  scanf("%d",&n);
	
  for(i = 0;i <= n-1;i++)
    {

      scanf("%d",&A[i]);
    }
  
  for(i = 0;i <= n-1;i++)
    {
      minj = i;
      
      for(j=i;j<=n-1;j++)
	{
	  
	  if(A[minj]>A[j])
	    {
	      minj=j;
	    }
	}
      
      if(i < minj)
	{
	  tmp=A[minj];
	  A[minj]=A[i];
	  A[i]=tmp;
	  count++;
	}
      
    }
  printf("%d",A[0]);
  
  for(i=1;i<=n-1;i++)
    {
      printf(" %d",A[i]);
    }
  
  printf("\n");
  printf("%d\n",count);
  
  return 0;
}

