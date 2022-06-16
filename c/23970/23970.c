#include <stdio.h>

void	ft_sort(int *a, int *b, int n)
{
	int idx, max, i_n, is_equal, s_idx;

	is_equal = 1;
	s_idx = 0;
	while (s_idx < n)
	{
		if (a[s_idx] != b[s_idx])
		{
			is_equal = 0;
			break ;
		}
		s_idx++;
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
		while (idx < i_n - 1)
		{
			is_equal = 0;
			if (a[idx] > a[idx + 1])
			{
				max = a[idx];
				a[idx] = a[idx + 1];
				a[idx + 1] = max;
			}

			if (a[idx] == b[idx] && a[0] == b[0] && a[n - 1] == b[n - 1])
			{
				is_equal = 1;
				s_idx = 0;
				while (s_idx < n)
				{
					if (a[s_idx] != b[s_idx])
					{
						is_equal = 0;
						break ;
					}
					s_idx++;
				}
			}

			if (is_equal)
				break ;

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