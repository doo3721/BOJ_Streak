#include <stdio.h>
#include <stdlib.h>

static int	n, k;

void	ft_sort(int *a)
{
	int idx, i_n, new_a;

	i_n = 1;
	while (i_n < n)
	{
		idx = i_n - 1;
		new_a = a[i_n];

		while (idx >= 0 && new_a < a[idx])
		{
			a[idx + 1] = a[idx];
			if (!(--k))
			{
				printf("%d", a[idx + 1]);
				exit(0);
			}
			idx--;
		}

		if (idx + 1 != i_n)
		{
			a[idx + 1] = new_a;
			if (!(--k))
			{
				printf("%d", a[idx + 1]);
				exit(0);
			}
		}

		i_n++;
	}

	if (k)
		printf("-1");
}

int main(void)
{
	int	a[10000];
	int idx;

	scanf("%d%d", &n, &k);

	idx = 0;
	while (idx < n)
		scanf("%d", &a[idx++]);

	ft_sort(a);
	
	return (0);
}