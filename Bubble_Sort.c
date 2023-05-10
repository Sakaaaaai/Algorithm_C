#include<stdio.h>
int main()
{
  int data,b[100],i,j,n=0,tmp;
  
  scanf("%d",&data);
  
  for(i=0;i<data;i++)
    {
    scanf("%d",&b[i]);
  }
  
  for(i=0;i<data-1;i++)
    {
    for(j=data-1;j>i;j--)
      {
      if(b[j]<b[j-1])
	{
	  
	tmp = b[j];
	b[j]=b[j-1];
	b[j-1]=tmp;
	n++;
	
      }
    }
  }
  for(i=0;i<data-1;i++)
    {
    printf("%d ",b[i]);
  }
  printf("%d\n",b[i]);
  printf("%d\n",n);
  return 0;
}

