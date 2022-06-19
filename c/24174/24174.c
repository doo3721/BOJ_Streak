#include <stdio.h>
#include <stdlib.h>

static int	n, k;

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_heapify(int *a, int x, int m)
{
	int l, r, s;

	l = 2 * x;
	r = 2 * x + 1;
	if (r <= m)
	{
		if (a[l] < a[r])
			s = l;
		else
			s = r;
	}
	else if (l <= m)
		s = l;
	else
		return ;
	
	if (a[s] < a[x])
	{
		ft_swap(&a[x], &a[s]);
		if (!(--k))
		{
			l = 1;
			while (l <= n)
				printf("%d ", a[l++]);
			exit(0);
		}
		ft_heapify(a, s, m);
	}
}

void	ft_bulid_min_heap(int *a)
{
	int idx;

	idx = n;
	while (idx / 2 >= 1)
	{
		ft_heapify(a, idx / 2, n);
		idx--;
	}
}

void	ft_sort(int *a)
{
	int idx;

	ft_bulid_min_heap(a);

	idx = n;
	while (idx > 1)
	{
		ft_swap(&a[1], &a[idx]);
		if (!(--k))
		{
			idx = 1;
			while (idx <= n)
				printf("%d ", a[idx++]);
			exit(0);
		}
		ft_heapify(a, 1, idx - 1);
		idx--;
	}
}

int main(void)
{
	int	a[500001];
	int idx;

	scanf("%d%d", &n, &k);

	idx = 1;
	while (idx <= n)
		scanf("%d", &a[idx++]);

	ft_sort(a);
	if (k)
		printf("-1");
	
	return (0);
}