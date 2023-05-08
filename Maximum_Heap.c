/*
input
10
4 1 3 2 16 9 10 14 8 7
output
 16 14 10 8 7 9 3 2 4 1
*/

#include<stdio.h>

#define Max

int H;

// 1 = key  2 = parent  3 = left  4 = right

int Cal(int A,int num){
    int ans;

        switch(A) {
        case 1:
        ans = num;
        return ans;
            break;

        case 2:
        ans = num/2;
        return ans;
            break;

        case 3:
        ans = 2*num;
        return ans;
            break;

        case 4:
        ans = 2*num+1;
        return ans;   
            break;
        }
    return 0;
}

void MaxHeap(int data[],int i){

	int num = i;

	if(Cal(3,i)<=H && data[Cal(3,i)]>data[num])num=Cal(3,i);
	
	if(Cal(4,i)<=H && data[Cal(4,i)]>data[num])num=Cal(4,i);

	if(num!=i){
        int tmp;

        tmp =data[i];
	    data[i]=data[num];
	    data[num]=tmp;

		MaxHeap(data,num);
	}
}

void BuildHeap(int data[]){
	int i;
	for(i=H/2;i>=1;i--){
		MaxHeap(data,i);
	}
}

int main(void){

	int data[500001];
	int i;

	scanf("%d",&H);

	for(i=1;i<=H;i++)scanf("%d",&data[i]);
	BuildHeap(data);

	for(i=1;i<=H;i++)printf(" %d",data[i]);
	printf("\n");

	return 0;
}

	
