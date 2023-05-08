/*
input
xyzz
yz

output
1
*/

#include <stdio.h>
#include <string.h>
#define TMAX 1000001
#define PMAX 10001
int main(){
  char T[TMAX],P[PMAX];
  int i,l,m;
   
  scanf("%s",T);
  scanf("%s",P);
   
  l=strlen(T);
  m=strlen(P);
   
  for(i=0;i<l;i++){
    if(strncmp(&T[i],P,m)==0) printf("%d\n",i);
  }
  return 0; 
}  
