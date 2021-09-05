#include<stdio.h>

int FactorialTail(int n, int acc)
{
	if (n == 1) return acc;
	return FactorialTail(n - 1, acc * n);
}
void main()
{
    printf("%d\n",FactorialTail(4,1));
}