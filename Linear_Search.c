#include <stdio.h>

int main()
{
  int array_1[10000],array_2[500], i, j, n_1, n_2, count=0;
  
  scanf("%d",&n_1);
  for(i=0;i<n_1;i++)scanf("%d",&array_1[i]);

  scanf("%d",&n_2);
  for(j=0;j<n_2;j++)scanf("%d",&array_2[j]);

  for(j=0;j<n_2;j++){
    for(i=0;i<n_1;i++){
      
      if(array_2[j] == array_1[i]){
	count++;
	break;	
      }
    }
  }
  
  printf("%d\n",count);
  
  return 0;
}

