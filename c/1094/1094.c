#include <stdio.h>

static int	dp[1000001] = {0, };

int main(void)
{
	int	n, idx;

	scanf("%d", &n);

	dp[1] = 1;
	dp[2] = 2;
	idx = 3;
	while (idx <= n)
	{
		dp[idx] = (dp[idx - 1] + dp[idx - 2]) % 15746;
		idx++;
	}
	printf("%d", dp[n]);
	return (0);
}