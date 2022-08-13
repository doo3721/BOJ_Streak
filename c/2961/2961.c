#include <stdio.h>
#define INT_MAX 2147483647
#define ABS(X) ((2 * ((X) > 0) - 1) * (X))

static int	n, m, a[10], b[10], bit[10];

static void	ft_solve(int i, int is_insert)
{
	int j, x, y;

	if (i == n)
	{
		j = 0;
		x = 1;
		y = 0;
		while (j < n)
		{
			x *= (bit[j] == 1 ? a[j] : 1);
			y += (bit[j] == 1 ? b[j] : 0);
			j++;
		}
		if (y == 0)
			return ;
		m = m > ABS(x - y) ? ABS(x - y) : m;
		return ;
	}
	bit[i] = is_insert;
	ft_solve(i + 1, 0);
	ft_solve(i + 1, 1);
}

int main(void)
{
	int	i;
	scanf("%d", &n);

	i = 0;
	while (i < n)
	{
		scanf("%d%d", &a[i], &b[i]);
		i++;
	}
	m = INT_MAX;
	ft_solve(0, 0);
	ft_solve(0, 1);
	printf("%d", m);
	return (0);
}