#include <stdio.h>

int main(void)
{
	long long	n;

	scanf ("%lld", &n);

	n = (n - 2) * (n - 1) * n / 6;

	printf("%lld\n3", n);
}