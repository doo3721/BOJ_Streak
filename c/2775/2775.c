#include <stdio.h>

int	ft_solve(int k, int n)
{
	int ans;

	if (k == 0)
		ans = n;
	else
	{
		ans = 0;
		while (n)
		{
			ans += ft_solve(k - 1, n);
			n--;
		}
	}
	return (ans);
}

int main(void)
{
	int t, k, n, idx;

	scanf("%d", &t);

	idx = 0;
	while(idx < t)
	{
		scanf("%d%d", &k, &n);
		printf("%d\n", ft_solve(k, n));
		idx++;
	}
	return (0);
}