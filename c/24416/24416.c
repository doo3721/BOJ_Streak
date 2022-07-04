#include <stdio.h>

static int f_cnt, d_cnt;
static int f[41] = {0, };

int fib(int n)
{
	if (n == 1 || n == 2)
	{
		f_cnt++;
		return (1);
	}
	else
		return (fib(n - 1) + fib(n - 2));
}

int	fibonacci(int n)
{
	int i;

	f[1] = f[2] = 1;
	for (i = 3; i <= n; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
		d_cnt++;
	}
	return (f[i]);

}

int main(void)
{
	int n;

	scanf("%d", &n);

	f_cnt = d_cnt = 0;
	fib(n);
	fibonacci(n);

	printf("%d %d", f_cnt, d_cnt);
	return (0);
}