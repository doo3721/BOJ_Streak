#include <stdio.h>

static int	dp[101][10][10];


int	main(void)
{
	int n, i, j, k, sum;

	scanf("%d", &n);
	i = 1;
	while (i < 10)
	{
		dp[1][i][i] = 1;
		i++;
	}

	i = 2;
	while (i <= n)
	{
		j = 0;
		while (j < 10)
		{
			if (j == 0)
				dp[i][j][j] = dp[i][8][]
		}
	}
	printf("%d", sum);
	return (0);
}