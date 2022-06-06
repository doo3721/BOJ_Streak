#include <stdio.h>
#include <stdlib.h>

int	ft_check(long long *tree, int n, int m, long long h)
{
	int			idx;
	long long	sum;

	idx = 0;
	sum = 0;
	while (idx < n)
	{
		sum += (tree[idx] - h) > 0 ? tree[idx] - h : 0;
		idx++;
	}

	if (sum >= m)
		return (1);
	else
		return (0);
}

void	ft_search(long long *tree, int n, int m, long long *h)
{
	long long	min_h, max_h, mid_h;

	min_h = 0;
	max_h = *h;
	while (min_h < max_h)
	{
		mid_h = (min_h + max_h) / 2;
		if (ft_check(tree, n, m, mid_h))
			min_h = mid_h + 1;
		else
			max_h = mid_h;
	}

	while (!(ft_check(tree, n, m, max_h)))
		max_h--;
	
	*h = max_h;
}

int main(void)
{
	int			n, m, idx;
	long long	*tree;
	long long 	h;

	scanf("%d%d", &n, &m);
	tree = malloc(sizeof(long long) * n);

	idx = 0;
	h = 0;
	while (idx < n)
	{
		scanf("%lld", &tree[idx]);
		if (h < tree[idx])
			h = tree[idx];
		idx++;
	}

	ft_search(tree, n, m, &h);

	printf("%lld", h);
	free(tree);
	return (0);
}