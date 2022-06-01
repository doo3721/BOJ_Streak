#include <stdio.h>

void	ft_solve(int n)
{
	int idx, s_idx;

	idx = 1;
	while (idx <= n)
	{
		s_idx = 1;
		while (s_idx <= n * 5)
		{
			printf("@");
			s_idx++;
		}
		printf("\n");
		idx++;
	}

	idx = 1;
	while (idx <= n * 4)
	{
		s_idx = 1;
		while (s_idx <= n)
		{
			printf("@");
			s_idx++;
		}
		printf("\n");
		idx++;
	}
}

int main(void)
{
	int n;

	scanf("%d", &n);

	ft_solve(n);

	return (0);
}