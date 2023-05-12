#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define NMAX 100000
#define WMAX l000000000
#define ViMAX l000000000
#define WiMAX l000000000
#define LARGE 1
#define EPS 0.0000000001
int dcmp(double x) { if (fabs(x) < EPS) return 0; return x <= 0 ? -1 : 1; }


long int sort_idx[NMAX];
long int  w[NMAX], p[NMAX];
double ratio[NMAX];

void swap(long int* a, long int* b)
{
    long int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partion(long int arr[], long int p, long int r)
{
    long int pivotIndex, pivot, i = p - 1, j;
    if (r - p > LARGE)
        pivotIndex = p + rand() % (r - p + 1);
    else
        pivotIndex = p;

    pivot = arr[pivotIndex];
    swap(&arr[pivotIndex], &arr[r]);
    for (j = p; j < r; j++)
    {
        //if (arr[j] < pivot)
        //if (cmp(&pivotIndex, &j))
        if (dcmp(ratio[arr[j]] - ratio[pivot]) == 1)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }

    }
    swap(&arr[i + 1], &arr[r]);
    return i + 1;
}

void quick_sort(long int arr[], long int p, long int q, long int sub_u)
{
    long int i, j, w_sum=0,w_sum_left = 0;
    if (p < q)
    {
        for (i = p;i <= q;i++) w_sum += w[sort_idx[i]];
        if (sub_u >= w_sum) return;
        j = partion(arr, p, q);
        w_sum_left = 0;
        for (i = p;i <= j-1; i++) w_sum_left += w[sort_idx[i]];
        if (sub_u <= w_sum_left)
            quick_sort(arr, p, j - 1, sub_u);
        else
            if (sub_u > w_sum_left + w[sort_idx[j]])
                quick_sort(arr, j + 1, q, sub_u - w_sum_left- w[sort_idx[j]]);
    }
}


int main()
{
    long int n, m, i, j, u, temp, total_profit = 0, x;

    double  xr, total_weight = 0;

    //Reading number of items
    scanf("%ld", &n);

    //Reading the capacity of the knapsack 
    scanf("%ld", &m);

    //Initializing remaining capacity of Knapsack (u)
    u = m;

    //Reading the Weights and Reading the Profit values
    for (i = 0; i < n; i++)
    {
        scanf("%ld", &p[i]);
        scanf("%ld", &w[i]);
        sort_idx[i] = i;
        ratio[i] = (double)p[i] / w[i];
    }
    u = m;
    quick_sort(sort_idx, 0, n - 1,u);

    //Calculating Total Profit & Total Weight 

    u = m;
    for (j = 0;j < n && u >= w[sort_idx[j]];j++) {
        total_profit += p[sort_idx[j]];
        u -= w[sort_idx[j]];
    }
    x = j;
    //printf("u=%ld, w=%ld, p=%ld, total_profit =%ld,%.12lf\n", u, w[sort_idx[x]],p[sort_idx[x]], total_profit, ratio[sort_idx[x]]);
    //Displaying Total Profit and Total Weight 
    if (w[sort_idx[x]] > u && x <= n - 1)
        printf("%.12lf\n", total_profit + (double)u * ratio[sort_idx[x]]);
    else
        printf("%ld\n", total_profit);

}
