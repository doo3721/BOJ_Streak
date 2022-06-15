#include <stdio.h>

void	ft_sort(int *a, int *b, int n)
{
	int idx, max, max_i, is_equal, i_n;

	
	is_equal = 1;
	idx = 0;
	while (idx < n)
	{
		if (a[idx] != b[idx])
		{
			is_equal = 0;
			break ;
		}
		idx++;
	}

	if (is_equal)
	{
		printf("1");
		return ;
	}

	i_n = n;
	while (i_n - 1)
	{
		idx = 0;
		max = 0;
		max_i = 0;
		is_equal = 1;
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
		}

		idx = 0;
		while (idx < n)
		{
			if (a[idx] != b[idx])
			{
				is_equal = 0;
				break ;
			}
			idx++;
		}
		
		if (is_equal)
			break ;
		
		i_n--;
	}

	printf("%d", is_equal);
}

int main(void)
{
	int	a[10000];
	int b[10000];
	int n, idx;

	scanf("%d", &n);

	idx = 0;
	while (idx < n)
		scanf("%d", &a[idx++]);
	
	idx = 0;
	while (idx < n)
		scanf("%d", &b[idx++]);

	ft_sort(a, b, n);
	
	return (0);
}