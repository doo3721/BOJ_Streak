#include <stdio.h>

void	ft_sort(int *a, int n, int k)
{
	int idx, count, max, i_n;

	count = 0;
	i_n = n;
	while (i_n - 1)
	{
		idx = 0;
		while (idx < i_n - 1)
		{
			if (a[idx] > a[idx + 1])
			{
				max = a[idx];
				a[idx] = a[idx + 1];
				a[idx + 1] = max;
				count++;
			}
			if (count == k)
			{
				printf("%d %d", a[idx], a[idx + 1]);
				break ;
			}
			idx++;
		}

		if (count == k)
			break ;

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