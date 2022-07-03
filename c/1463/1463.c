#include <stdio.h>
#define INF 1000000

static int	dp[INF + 1];

int	ft_min(int a, int b)
{
	return (a <= b ? a : b);
}

int main(void)
{
	int n, i;

	scanf("%d", &n);

	dp[1] = 0;
	i = 2;
	while (i <= INF)
		dp[i++] = INF;
	
	i = 1;
	while (i <= n)
	{
		dp[i + 1] = ft_min(dp[i] + 1, dp[i + 1]);
		if (i * 2 <= INF)
			dp[i * 2] = ft_min(dp[i] + 1, dp[i * 2]);
		if (i * 3 <= INF)
			dp[i * 3] = ft_min(dp[i] + 1, dp[i * 3]);
		i++;
	}
	printf("%d", dp[n]);
	return (0);
}