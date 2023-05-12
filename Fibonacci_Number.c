#include<stdio.h>

#define N 45

int data[N];

int Fibonacci(int n)
{
	if (n == 0 || n == 1) return data[n] = 1;

	if (data[n]) return data[n];

	else return data[n] = (Fibonacci(n - 1) + Fibonacci(n - 2));
}

int main(void)
{
	int n;

	scanf("%d", &n);

	printf("%d\n", Fibonacci(n));

    return 0;
}
