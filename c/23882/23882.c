#include <stdio.h>

void	ft_sort(int *a, int n, int k)
{
	int idx, count, max, max_i, i_n;

	count = 0;
	i_n = n;
	while (i_n - 1)
	{
		idx = 0;
		max = 0;
		max_i = 0;
		while (idx < i_n)
		{
			if (max < a[idx])
			{
				max = a[idx];
				max_i = idx;
			}
			idx++;
		}

		if (max_i != i_n - 1)
		{
			a[max_i] = a[i_n - 1];
			a[i_n - 1] = max;
			count++;
		}

		if (count == k)
		{
			idx = 0;
			while (idx < n)
				printf("%d ", a[idx++]);
			break ;
		}

		i_n--;
	}

	if (count < k)
		printf("-1");
}

int main(void)
{
	int	a[10000];
	int n, k, idx;

	scanf("%d%d", &n, &k);

	idx = 0;
	while (idx < n)
		scanf("%d", &a[idx++]);

	ft_sort(a, n, k);
	
	return (0);
}