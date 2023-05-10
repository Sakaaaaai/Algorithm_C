#include <stdio.h>


typedef struct{
  
  int number;
  char ch;
  
} card;


void Bubble(card *, int);

void Selection(card *, int);


int main(){
  int i, j, flag = 0, data, minj;

  scanf("%d", &data);
  
  card Bub[data], Sel[data];
  
  for(i=0; i<data; i++)
    {
      
    scanf(" %c%d", &Bub[i].number, &Bub[i].ch);
    
    Sel[i] = Bub[i];
    
  }
 
  Bubble(Bub, data);
  
  printf("Stable\n");
  
  Selection(Sel, data);
  
  for(i=0; i<data; i++)
    {
      
      if(Bub[i].number != Sel[i].number)
	{
	  flag++;
	}
    }
  
  
  if(flag>0)
    {
      printf("Not stable\n");
    }
  
  else  printf("Stable\n");
  
  return 0;
  
}


void Bubble(card *Bub,  int data){
  
  int i, j, minj;
  card tmp;
  
  for(i=0; i<data; i++)
    {
      
    for(j=data-1; j>i; j--)
      {
	
      if(Bub[j].ch < Bub[j-1].ch)
	{
	  
	tmp = Bub[j];
	Bub[j] = Bub[j-1];
	Bub[j-1] = tmp;
	
      }
    }
  }
  
  for(i = 0; i < data-1; i++)
    {
      printf("%c%d", Bub[i].number, Bub[i].ch);
      printf(" ");  
    }
  
  printf("%c%d", Bub[i].number, Bub[i].ch);
  printf("\n");
  
}


void Selection(card *Sel, int data){
  
  int i, j, a, minj;
  card tmp;
  
  for(i=0; i<data; i++)
    {
      minj = i;
      
      for(j=i; j<data; j++)
	{
	  
	  if(Sel[j].ch < Sel[minj].ch)
	    {
	      minj=j;
	    }
      
	}
    
      tmp = Sel[i];
      Sel[i] = Sel[minj];
      Sel[minj] = tmp;
    
    }

  for(i = 0; i < data-1; i++)
    {      
      printf("%c%d", Sel[i].number, Sel[i].ch);         
      printf(" ");	
    }
  
  printf("%c%d", Sel[i].number, Sel[i].ch);
  
  printf("\n");
  
}

