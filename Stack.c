/*
input
1 2 + 3 4 - *

output
-3
*/

#include<stdio.h>
#include<stdlib.h>


int top, S[200];

void push(int x);
int pop();
  
int main(){
  int first, second,x, top=0;
  char s[200];


  while(scanf("%s",s)!=EOF){
	
    switch(s[0]){
      
    case '*':
      x = pop() * pop();
      push(x);
      break;

    case '+':
      x = pop() + pop();
      push(x);
      break;

    case '-':
      first = pop();
	second = pop();
      push(second-first);
      break;
      
    }
    if(s[0] != '*' && s[0] != '-' && s[0] != '+'){
      x = atoi(s);
      push(x);
    }
  }


  printf("%d\n",pop());
  return 0;
    
}


void push(int x){

  top = top + 1;
  
  S[top]=x;
}


int pop(){
    top = top - 1;
    return S[top+1];
}

