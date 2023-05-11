#include<stdio.h>

#define N 200

int n, A[N];

int calcu(int , int );

int main(){
  
  int a, m, i, data;
    
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&A[i]);
    
    scanf("%d",&a);
    
    for(i=0;i<a;i++){
      
        scanf("%d",&m);
	
	data = calcu(0,m);
	
	  switch(data){
		       
	  case 1:
	  printf("yes\n");
	  break;

	  case 0:
	  printf("no\n");
	  break;
	  
	  }
    }
    return 0;
}



int calcu(int i, int m){
  
  int ans;
  
    if(m == 0) return 1;
    if(i >= n) return 0;
    
    ans = calcu(i + 1, m) || calcu(i + 1, m - A[i]);
    
    return ans;
}

