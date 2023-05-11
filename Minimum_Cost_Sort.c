#include <stdio.h>

int pertition(int a[],int left,int right){
    int i,j,k,l;
    k=left-1;
    for(i=left;i<right-1;i++){
        if(a[i]<=a[right-1]){
            k++;
            l=a[i]; a[i]=a[k]; a[k]=l;
        }
    }
    l=a[k+1]; a[k+1]=a[right-1]; a[right-1]=l;
    return k+1;
}

void quicksort(int a[],int left,int right){
    int mid;
    if(left+1<right){
        mid = pertition(a,left,right);
        quicksort(a,left,mid);
        quicksort(a,mid+1,right);
    }
}

int minn(int a,int b){
    if(a<b){return a;}
    return b;
}

int solve(int a[1000],int b[1000],int min,int n){
    int v[1000];
    int t[10001];
    int i,cur,s,lmin,an,ans;
    ans=0;
    for(i=0;i<n;i++){v[i]=0;}
    quicksort(b,0,n);
    for(i=0;i<n;i++){t[b[i]]=i;}
    for(i=0;i<n;i++){
        if(v[i]==1){continue;}
        cur=i; s=0; lmin=10001; an=0;
        while(1){
            v[cur]=1; an++;
            if(lmin>a[cur]){lmin=a[cur];}
            s+=a[cur];
            cur=t[a[cur]];
            if(v[cur]==1){break;}
        }
        ans += minn(s+(an-2)*lmin,lmin+s+(an+1)*min);
    }
    return ans;
}

int main(void){
    int n,i,min;
    int a[1000];
    int b[1000];
    scanf("%d",&n);
    min=100000;
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
        if(min>a[i]){min=a[i];}
    }
    printf("%d\n",solve(a,b,min,n));
    
}
