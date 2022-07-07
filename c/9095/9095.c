#include <stdio.h>

static int	dp[11] = {0, };

int main(void)
{
	int	idx, t, n;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	idx = 4;
	while (idx < 11)
	{
		dp[idx] = dp[idx - 1] + dp[idx - 2] + dp[idx - 3]; 
		idx++;
	}

	scanf("%d", &t);
	while (t)
	{
		scanf("%d", &n);
		printf("%d\n", dp[n]);
		t--;
	}
	return (0);
}