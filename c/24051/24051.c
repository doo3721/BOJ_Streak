#include <stdio.h>

void	ft_sort(int *a, int n, int k)
{
	int idx, count, i_n, new_a;

	count = 0;
	i_n = 1;
	while (i_n < n)
	{
		idx = i_n - 1;
		new_a = a[i_n];

		while (idx >= 0 && new_a < a[idx])
		{
			a[idx + 1] = a[idx];
			count++;
			if (count == k)
				printf("%d", a[idx + 1]);
			idx--;
		}

		if (idx + 1 != i_n)
		{
			a[idx + 1] = new_a;
			count++;
			if (count == k)
				printf("%d", a[idx + 1]);
		}

		i_n++;
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