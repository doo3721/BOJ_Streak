#include <stdio.h>

int	ft_four_multi(int n)
{
	int	num;

	num = 0;
	while (n - 1)
	{
		num += 4;
		n--;
	}
	return (num);
}

void	ft_solve(char map[][399], int y, int x, int y_n, int x_n)
{
	int y_idx, x_idx;

	y_idx = y;
	while (y_idx < y_n - 1)
	{
		if (y_idx >= y + 2)
			map[y_idx][x_n - 1] = '*';
		map[y_idx++][x] = '*';
	}
	
	x_idx = x;
	while (x_idx < x_n)
	{
		if (x_idx >= x + 2)
			map[y + 1][x_idx] = '*';
		map[y_n - 1][x_idx++] = '*';
	}

	if (x_n - x == 1)
		return ;
	
	ft_solve(map, y + 2, x + 2, y_n - 2, x_n - 2);
}

int main(void)
{
	char	map[399][399];
	int		n, y_n, x_n, idx, s_idx;

	scanf("%d", &n);

	x_n = 1 + ft_four_multi(n);
	y_n = 1 + ft_four_multi(n) + (n > 1 ? 2 : 0);

	idx = 0;
	while (idx < y_n)
	{
		s_idx = 0;
		if (idx == 0)
		{
			while (s_idx < x_n)
				map[idx][s_idx++] = '*';
		}
		else if (idx == 1)
		{
			map[idx][1] = '\n';
			map[idx++][2] = 0;
			continue;
		}
		else
		{
			while (s_idx < x_n)
				map[idx][s_idx++] = ' ';
		}
		map[idx][x_n] = '\n';
		map[idx++][x_n + 1] = 0;
	}
	if (x_n != 1 && y_n != 1)
		ft_solve(map, 1, 0, y_n, x_n);

	idx = 0;
	while (idx < y_n)
		printf("%s", map[idx++]);
	return (0);
}