#include <stdio.h>

static int	arr[301] = {0, };
static int	dp[301] = {0, };

static int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int	main(void)
{
	int	n, idx;

	scanf("%d%d%d", &n, &arr[1], &arr[2]);

	dp[1] = arr[1];
	dp[2] = dp[1] + arr[2];
	idx = 3;
	while (idx <= n)
	{
		scanf("%d", &arr[idx]);
		dp[idx] = ft_max(dp[idx - 2], dp[idx - 3] + arr[idx - 1]) + arr[idx];
		idx++;
	}
	printf("%d", dp[n]);
	return (0);
}