#include <stdio.h>

void	ft_solve(int n, int *prime)
{
	int idx;
	int ans[2];

	idx = n / 2;
	while (idx >= 2)
	{
		if (!prime[idx] && !prime[n - idx])
		{
			ans[0] = idx;
			ans[1] = n - idx;
			break ;
		}
		idx--;
	}
	printf("%d %d\n", ans[0], ans[1]);
}

int main(void)
{
	int n, num, i, j;
	int prime[10000] = {0, };

	prime[0] = 1;
	prime[1] = 1;
	i = 2;
	while (i * i <= 10000)
	{
		if (!prime[i])
		{
			j = 2;
			while (i * j <= 10000)
			{
				prime[i * j] = 1;
				j++;
			}
		}
		i++;
	}

	scanf("%d", &n);

	while (n)
	{
		scanf("%d", &num);
		ft_solve(num, prime);
		n--;
	}

	return (0);
}