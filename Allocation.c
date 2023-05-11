#include<stdio.h>
#define MAX 100000

long long w[MAX];
long long n,k;

long long ni(long long);

int main(){
  int i,j;
  long long vn,l,r,m;
  long long sum=0;
  //vn=最大積載量を決めた時積むことができる荷物の個数

  scanf("%lld%lld", &n, &k);

  //事前にw[i]の累積和を取って置く
  for(i=0;i<n;i++){
    scanf("%d", &w[i]);
    sum += w[i];
  }

  //pの探索に二分探索を適応する
  //vnの値はpに比例するので二分探索をもちいることができる
  //pの最小値は0、最大値はw[i]全ての和
  //全ての和にすることによって、探索回数を少しでも少なくできる
  l = 0;
  r = sum;
  while(l<r){
    m = (l+r)/2;
    vn = ni(m);
    if(vn>=n){
      r = m;
    }else{
      l = m+1;
    }
  }

  //二分探索時のrこそが最小値を示す
  printf("%lld\n", r);
  

  return 0;
}

//vnを求める関数ni
long long ni(long long p){
  long long  i,sum=0,j=0;

  for(i=0;i<k;i++){
    sum = 0;
    while((sum+w[j])<=p){
      sum += w[j];
      j++;
      if(j==n)return n;
    }
  }

  return j;
}
  

  

