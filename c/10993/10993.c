#include <stdio.h>

int	ft_test(int n)
{
	int num;

	num = 0;
	while (n - 1)
	{
		num += 1 << (n - 1);
		n--;
	}
	return (num);
}

void	ft_tri(char map[][2047], int y, int x, int y_n, int x_n)
{
	int	idx, x_idx;

	idx = y;
	while (idx < y_n)
	{
		if (idx == y_n - 1)
		{	
			x_idx = x;
			while (x_idx < x_n)
				map[idx][x_idx++] = '*';
		}
		else
		{
			map[idx][x + (x_n - x) / 2 - (idx - y)] = '*';
			map[idx][x + (x_n - x) / 2 + (idx - y)] = '*';
		}
		idx++;
	}
}

void	ft_r_tri(char map[][2047], int y, int x, int y_n, int x_n)
{
	int	idx, x_idx;

	idx = y;
	while (idx < y_n)
	{
		if (idx == y)
		{	
			x_idx = x;
			while (x_idx < x_n)
				map[idx][x_idx++] = '*';
		}
		else
		{
			map[idx][x + (x_n - x) / 2 - (y_n - 1 - idx)] = '*';
			map[idx][x + (x_n - x) / 2 + (y_n - 1 - idx)] = '*';
		}
		idx++;
	}
}

void	ft_solve(char map[][2047], int y, int x, int y_n, int x_n, int n)
{
	if (n % 2 == 1)
		ft_tri(map, y, x, y_n, x_n);
	else
		ft_r_tri(map, y, x, y_n, x_n);
	
	if (--n == 0)
		return ;
	
	if (n % 2 == 1)
		ft_solve(map, y + 1,			 x + (x_n - x) / 4 + 1, y_n - (y_n - y) / 2,	 x_n - (x_n - x) / 4 - 1, n);
	else
		ft_solve(map, y + (y_n - y) / 2, x + (x_n - x) / 4 + 1, y_n - 1,				 x_n - (x_n - x) / 4 - 1, n);
}

int main(void)
{
	char	map[1023][2047];
	int 	n, y_n, x_n, idx, s_idx;

	scanf("%d", &n);
	y_n = 1 + ft_test(n);
	x_n = 1 + 2 * ft_test(n);

	idx = 0;

	if (n % 2 == 1)
	{
		while (idx < y_n)
		{
			s_idx = 0;
			while (s_idx <= x_n / 2 + idx)
				map[idx][s_idx++] = ' ';
			map[idx][x_n / 2 + idx + 1] = '\n';
			map[idx][x_n / 2 + idx + 2] = 0;
			idx++;
		}
	}
	else
	{
		while (idx < y_n)
		{
			s_idx = 0;
			while (s_idx < x_n / 2 + (y_n - idx))
				map[idx][s_idx++] = ' ';
			map[idx][x_n / 2 + (y_n - idx)] = '\n';
			map[idx][x_n / 2 + (y_n - idx) + 1] = 0;
			idx++;
		}
	}

	ft_solve(map, 0, 0, y_n, x_n, n);

	idx = 0;
	while (idx < y_n)
		printf("%s", map[idx++]);
	return (0);
}