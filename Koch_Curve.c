/*
input
1

output
0.00000000 0.00000000
33.33333333 0.00000000
50.00000000 28.86751346
66.66666667 0.00000000
100.00000000 0.00000000
*/


#include <stdio.h>
#include <math.h>

typedef struct{
  double x;
  double y;
}Coor;

void Calcu(int,Coor,Coor);

int main(){
  int n;
  Coor start={0,0}, end={100,0};

  scanf("%d",&n);
  
  
  printf("%.5lf %.5lf\n",start.x,start.y);
  
  Calcu(n,start,end);
  
  printf("%.5lf %.5f\n",end.x,end.y);
  
  return 0;
}

void Calcu(int n, Coor st, Coor e){

  Coor s, t, u;

  if(n == 0)return;
  
  s.x = (2.0*st.x + 1.0*e.x) / 3.0;
  s.y = (2.0*st.y + 1.0*e.y) / 3.0;
    
  t.x = (1.0*st.x + 2.0*e.x) / 3.0;
  t.y = (1.0*st.y + 2.0*e.y) / 3.0;
    
  u.x = (st.x + e.x)/2 + (st.y - e.y)/(2 * sqrt(3));
  u.y = (-st.x + e.x)/(2 * sqrt(3)) + (st.y + e.y)/2;

  Calcu(n-1,st,s);
    
  printf("%.5lf %.5lf\n",s.x,s.y);
      
  Calcu(n-1,s,u);
  printf("%.5lf %.5lf\n",u.x,u.y);
      
  Calcu(n-1,u,t);
  printf("%.5lf %.5lf\n",t.x,t.y);
    
  Calcu(n-1,t,e);
 
}

