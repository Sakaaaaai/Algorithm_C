/*
input
147 105

output
21
*/

#include <stdio.h>

int gcb(int, int);

int main()
{
  int x, y, ans;

  scanf("%d",&x);
  scanf("%d",&y);
  
  ans = gcb(x,y);

  printf("%d\n",ans);
  return 0;
}

int gcb(int x, int y)
{
  int z;
  if(y == 0)
    
    {
      return x;
    }
  
  else
    {
      
      z = x%y;
      
      return gcb(y, z);
    }
}
      

