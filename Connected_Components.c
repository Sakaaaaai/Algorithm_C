#include<stdio.h>

#define N 100000

int A[N];

void res(int a,int b);
int sum(int a, int b);
int search(int p);

int main()
{

  int n,m,i,a,b,c;

  for(i=0; i<N; i++) A[i]=i;

  scanf("%d%d",&n,&m);

  for(i=0; i<m; i++){
    scanf("%d%d",&a,&b);
    res(a,b);
  }

  scanf("%d",&c);
  for(i=0; i<c; i++){
    scanf("%d%d",&a,&b);
    if(sum(a,b)==1)printf("yes\n");
    else printf("no\n");
  }
  return 0;
}

void res(int a, int b)
{

  a=search(a);
  b=search(b);

  if(a==b)return;

  A[b]=a;
}

int sum(int a, int b)
{

  if(search(a)==search(b))return 1;
  else return 0;
}
int search(int p)
{
  if(p==A[p])return p;
  return A[p]=search(A[p]);
}

