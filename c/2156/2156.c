#include <stdio.h>
#include <unistd.h>

static int	arr[10001];
static int	dp[10001];

static int	ft_max(int a, int b)
{
	return (a >= b ? a : b);
}
static int	ft_max3(int a, int b, int c)
{
	int max;

	max = ft_max(a, b);
	max = max == a ? ft_max(a, c) : ft_max(b, c);
	return (max);
}

int	main(void)
{
	int n, idx;

	scanf("%d%d%d", &n, &arr[1], &arr[2]);

	dp[1] = arr[1];
	dp[2] = dp[1] + arr[2];

	idx = 3;
	write(1, "-2147\n", 6);
	while (idx <= n)
	{
		scanf("%d", &arr[idx]);
		dp[idx] = ft_max3(arr[idx] + arr[idx - 1] + dp[idx - 3], \
						arr[idx] + dp[idx - 2], + dp[idx - 1]);
		idx++;
	}
	printf("%d", dp[n]);
	return (0);
}