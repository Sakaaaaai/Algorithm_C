/*
input
5
0.1500 0.1000 0.0500 0.1000 0.2000
0.0500 0.1000 0.0500 0.0500 0.0500 0.1000

output
2.75000000
*/

#include <stdio.h>
#define N 505
#define INF 10000000005

#define min(a, b) ((a) < (b) ? (a) : (b))

double p[N], q[N];

double func(int, int);

int main(){
    int n, i;

    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%lf", &p[i]);
    for (i = 0; i <= n; i++) scanf("%lf", &q[i]);

    printf("%lf\n", func(0, n));
    
    return 0;
}

double func(int left, int right){
    static double dp[N][N];
    int i;
    double sum = 0;

    if (left == right) return q[left];
    if (dp[left][right] != 0) return dp[left][right];

    dp[left][right] = INF;
    
    for (i = left; i < right; i++) sum += p[i];
    for (i = left; i <= right; i++) sum += q[i];

    for (i = left; i < right; i++){
        dp[left][right] = min(dp[left][right], func(left, i)+func(i+1, right)+sum);
    }
    return dp[left][right];
}
