#include <stdio.h>

void	ft_print_n(int n, char c)
{
	while (n)
	{
		printf("%c", c);
		n--;
	}
}

void	ft_print_blank_star(int idx, int n)
{
	while (idx)
	{
		if (idx == n || idx == 1)
			printf("*");
		else
			printf(" ");
		idx--;
	}
}

void	ft_star(int a, int b)
{
	int idx;

	idx = a < b ? a : b;
	ft_print_n(idx, ' ');

	if (a < b)
	{
		idx = b;
		if (a == 0)
			ft_print_n(idx, '*');
		else
			ft_print_blank_star(idx, b);
	}
	else
	{
		idx = a;
		if (b == 0)
			ft_print_n(idx, '*');
		else
			ft_print_blank_star(idx, a);
	}

	idx = a < b ? 2 * (b - a - 1) - 1 : 2 * (a - b - 1) - 1;
	ft_print_n(idx, ' ');

	if (a < b)
	{
		idx = b;
		if (a == 0)
			ft_print_n(idx, '*');
		else
			ft_print_blank_star(idx, b);
	}
	else
	{
		idx = a;
		if (b == 0)
			ft_print_n(idx, '*');
		else
			ft_print_blank_star(idx, a);
	}
}

void	ft_print_mid(int n)
{
	int	idx;

	idx = n - 1;
	ft_print_n(idx, ' ');

	idx = n;
	ft_print_blank_star(idx, n);

	idx = n - 1;
	ft_print_blank_star(idx, n);
}

int main(void)
{
	int		n, idx;

	scanf("%d", &n);

	idx = 0;
	while (idx < n - 1)
	{
		ft_star(idx++, n);
		printf("\n");
	}

	ft_print_mid(n);
	printf("\n");

	idx = n - 2;
	while (idx >= 0)
	{
		ft_star(n, idx--);
		printf("\n");
	}
	return (0);
}