#include <stdio.h>

static long long	dp[101] = {0, };

int main(void)
{
	int t, n, idx;

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;
	idx = 6;
	while (idx <= 100)
	{
		dp[idx] = dp[idx - 5] + dp[idx - 1];
		idx++;
	}

	scanf("%d", &t);

	while (t)
	{
		scanf("%d", &n);
		printf("%lld\n", dp[n]);
		t--;
	}
	return (0);
}