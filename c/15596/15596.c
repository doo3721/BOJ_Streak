#include <stdio.h>

long long	sum(int *a, int n)
{
	long long	ans;

	ans = 0;
	while (--n >= 0)
		ans += a[n];
	return (ans);
}