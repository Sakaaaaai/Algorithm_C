#include <stdio.h>
#include <string.h>

#define LEN 100001

typedef struct p{
  char name[10];
  int time;
}data;


void enqueue(data);
data dequeue(void);
  
data Q[LEN];
int head, tail, n;

int main(){
  
  int lap_time = 0, min, i, q;
  data x;

  head = 1;

  scanf("%d%d", &n, &q);

  for (i = 1; i < n+1; i++)scanf("%s %d", Q[i].name, &Q[i].time);
    
  tail = n+1;

  while(head != tail){
    x = dequeue();
    
    if(q <= x.time)min = q;
    else min = x.time;
    
    x.time = x.time - min;
    
    lap_time = lap_time + min;
    
    if(x.time > 0){
      enqueue(x);
    }
    
    else{
      printf("%s %d\n",x.name ,lap_time);
    }
    
  }
  
  return 0;
  
}


void enqueue(data x){
  
  Q[tail] = x;
  
  tail = (tail + 1)%(LEN - 1);
}


data dequeue(void){
  data x;
  
  x = Q[head];
  
  head = (head + 1)%(LEN - 1);
  
  return x;
}


