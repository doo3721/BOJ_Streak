#include <stdio.h>

void	ft_u_star(int a, int b)
{
	int idx;

	idx = 0;
	while (idx < a)
	{
		if (idx % 2 == 0)
			printf("*");
		else
			printf(" ");
		idx++;
	}

	idx = b - 2 * a;
	if (a % 2 == 0)
	{
		while (idx)
		{
			printf("*");
			idx--;
		}
	}
	else
	{
		while (idx)
		{
			printf(" ");
			idx--;
		}
	}

	idx = a;
	while (idx)
	{
		if (idx % 2 == 0)
			printf(" ");
		else
			printf("*");
		idx--;
	}
}

void	ft_d_star(int a, int b)
{
	int idx;

	idx = 0;
	while (idx < (b - (2 * a - 1)) / 2)
	{
		if (idx % 2 == 0)
			printf("*");
		else
			printf(" ");
		idx++;
	}

	idx = 2 * a - 1;
	if (a % 2 == 1)
	{
		while (idx)
		{
			printf("*");
			idx--;
		}
	}
	else
	{
		while (idx)
		{
			printf(" ");
			idx--;
		}
	}

	idx = (b - (2 * a - 1)) / 2;
	while (idx)
	{
		if (idx % 2 == 0)
			printf(" ");
		else
			printf("*");
		idx--;
	}
}

int main(void)
{
	int n, idx;

	scanf("%d", &n);

	idx = 0;
	while (idx < 2 * n - 2)
	{
		ft_u_star(idx++, (2 * n - 1) * 2 - 1);
		printf("\n");
	}
	
	idx = 1;
	while (idx <= 2 * n - 1)
	{
		ft_d_star(idx++, (2 * n - 1) * 2 - 1);
		printf("\n");
	}
	return (0);
}