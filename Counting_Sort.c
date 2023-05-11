#include<stdio.h>
#include<stdlib.h>

int array[10000];

void print(int n){
int i, j, count=0;

for(i=0;i<10000;i++)
    {
        for(j=0;j<array[i];j++)
        {
            printf("%d",i);
            if(count<n-1){
                printf(" ");
                count++;
            }
        }
    }
    printf("\n");
}


int main()
{
    
    int n,i,b,j,c=0;

    scanf("%d",&n);
    for(i=0;i<10000;i++){
        array[i]=0;
    }
    for(i=0;i<n;i++){
        scanf("%d",&b);
        array[b]++;
    }
print(n);
    return 0;
}

