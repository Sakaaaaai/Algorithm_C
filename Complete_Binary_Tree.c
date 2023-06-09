#include <stdio.h>

#define MAX 250

int data[MAX+1];

int Cal(int ,int );

int main(){
  int i;
  int n, x;

  scanf("%d", &n);

  for(i=1;i<=n;i++) scanf("%d", &data[i]);

  for(i=1;i<=n;i++){
    printf("node %d: key = %d, ", i, Cal(1,i));

    if(i/2)printf("parent key = %d, ", Cal(2,i));

    if(2*i<=n)printf("left key = %d, ", Cal(3,i));

    if(2*i+1<=n)printf("right key = %d, ", Cal(4,i));

printf("\n");
  }
  return 0;
}

// 1 = key  2 = parent  3 = left  4 = right

int Cal(int A,int num){
    int ans;

        switch(A) {
        case 1:
        ans = data[num];
        return ans;
            break;

        case 2:
        ans = data[num/2];
        return ans;
            break;

        case 3:
        ans = data[2*num];
        return ans;
            break;

        case 4:
        ans = data[2*num+1];
        return ans;   
            break;
        }
    return 0;
}
