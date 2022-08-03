#include <stdio.h>

static int	cost[10];

int main(void)
{
	int n, k, i, count;

	scanf("%d%d", &n, &k);

	i = 0;
	while (i < n)
		scanf("%d", &cost[i++]);

	count = 0;
	i = n - 1;
	while (i >= 0 && k)
	{
		while (k / cost[i])
		{
			count++;
			k -= cost[i];
		}
		i--;
	}
	printf("%d", count);
	return (0);
}