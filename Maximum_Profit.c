/*
input
6
5
3
1
3
4
3
output
3
*/



#include <stdio.h>

#define N 200000

int main()
{
  int i, n, min, dif, data, inte, a;

  scanf("%d %d %d",&n, &min, &inte);
 
  dif = inte - min;
    
  if (inte < min )
    {
      min = inte;
    }
    
  for ( i=2;i<n;i++)
    {
      
      scanf("%d", &data);
    
      a = data - min;
    
      if (data < min )
	{
	  min = data;
	}
	
      if ( a > dif)
	{
	  dif = a;
	}
    
    }
  
  printf("%d\n",dif );
  
  return 0;
}

