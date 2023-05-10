#include <stdio.h>
#include <math.h>

int main()
{
  int i, j, data, f=0, a, count=0;

  while(scanf("%d",&data) != EOF)
    {
      f = 0;
      
      for(i=2;i<=sqrt(data);i++){
    
	a = data % i;
    
	if(a == 0)
	  {
	
	    f = 1;
	    break;
	 
	  }

	
      }
      
      if(f == 0)count++;
      
    }
  
  printf("%d\n",count);
  
  return 0;
}

