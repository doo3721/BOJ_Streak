#include <stdio.h>
#include <stdlib.h>

static int	n;

void	ft_equal(int *a, int *b)
{
	int idx;

	idx = 0;
	while (idx < n)
	{
		if (a[idx] != b[idx])
			return ;
		idx++;
	}

	printf("1");
	exit(0);
}

void	ft_sort(int *a, int *b)
{
	int idx, i_n, new_a;

	ft_equal(a, b);
	i_n = 1;
	while (i_n < n)
	{
		idx = i_n - 1;
		new_a = a[i_n];

		while (idx >= 0 && new_a < a[idx])
		{
			a[idx + 1] = a[idx];
			if (a[idx + 1] == b[idx + 1])
				ft_equal(a, b);
			idx--;
		}

		if (idx + 1 != i_n)
		{
			a[idx + 1] = new_a;
			if (a[idx + 1] == b[idx + 1])
				ft_equal(a, b);
		}

		i_n++;
	}

	printf("0");
}

int main(void)
{
	int	a[10000];
	int b[10000];
	int idx;

	scanf("%d", &n);

	idx = 0;
	while (idx < n)
		scanf("%d", &a[idx++]);
	
	idx = 0;
	while (idx < n)
		scanf("%d", &b[idx++]);

	ft_sort(a, b);
	
	return (0);
}