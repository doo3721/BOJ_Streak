#include <stdio.h>

void	ft_sort(int *a, int n, int k)
{
	int idx, count, max, max_i;

	count = 0;
	while (n - 1)
	{
		idx = 0;
		max = 0;
		max_i = 0;
		while (idx < n)
		{
			if (max < a[idx])
			{
				max = a[idx];
				max_i = idx;
			}
			idx++;
		}

		if (max_i != n - 1)
		{
			a[max_i] = a[n - 1];
			a[n - 1] = max;
			count++;
		}

		if (count == k)
		{
			printf("%d %d", a[max_i], a[n - 1]);	
			break ;
		}

		n--;
	}

	if (count < k)
		printf("-1");
}

int main(void)
{
	int	a[500000];
	int n, k, idx;

	scanf("%d%d", &n, &k);

	idx = 0;
	while (idx < n)
		scanf("%d", &a[idx++]);

	ft_sort(a, n, k);
	
	return (0);
}