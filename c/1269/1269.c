#include <stdio.h>
#include <stdlib.h>

static int	a[200000];

int ft_cmp(const void *a, const void *b)
{
	int x, y;

	x = *(int *)a;
	y = *(int *)b;

	if (x > y)
		return (1);
	else if (x < y)
		return (-1);
	return (0);
}

int	ft_search(int *a, int t, int n)
{
	int l, r, m;

	l = 0;
	r = n;
	while (l <= r)
	{
		m = (l + r) / 2;
		if (a[m] == t)
			return (1);
		else if (a[m] > t)
			r = m - 1;
		else
			l = m + 1;
	}
	return (0);
}

int main(void)
{
	int n, m, i, t, c;

	scanf("%d %d", &n, &m);
	i = 0;
	while (i < n)
		scanf("%d", &a[i++]);

	qsort(a, n, sizeof(int), ft_cmp);

	i = 0;
	c = 0;
	while (i < m)
	{
		scanf("%d", &t);
		c += ft_search(a, t, n - 1);
		i++;
	}

	printf("%d", n + m - 2 * c);
	return (0);
}