#include <stdio.h>
#include <stdlib.h>

void	ft_solve(char **map, int y, int x, int m_y, int m_x)
{
	if (m_y - y == 3 || m_x - x == 5)
	{
		map[y][x + 2] = '*';
		map[y + 1][x + 1] = '*';
		map[y + 1][x + 3] = '*';
		map[y + 2][x] = '*';
		map[y + 2][x + 1] = '*';
		map[y + 2][x + 2] = '*';
		map[y + 2][x + 3] = '*';
		map[y + 2][x + 4] = '*';
		return ;
	}
	else
	{
		ft_solve(map, y + (m_y - y) / 2, x, m_y, m_x - (m_x - x) / 2 - 1);
		ft_solve(map, y + (m_y - y) / 2, x + (m_x - x) / 2 + 1, m_y, m_x);
		ft_solve(map, y, x + (m_x - x) / 4 + 1, m_y - (m_y - y) / 2,  m_x - (m_x - x) / 4 - 1);
	}
}

int main(void)
{
	char	*map[3072];
	int		y_n, x_n, idx, s_idx;

	scanf("%d", &y_n);
	x_n = (y_n / 3) * 5 + (y_n / 3) - 1;

	idx = 0;
	while (idx < y_n)
	{
		map[idx] = malloc(sizeof(char) * (x_n + 2));
		s_idx = 0;
		while (s_idx <= x_n + 1)
		{
			if (s_idx == x_n)
				map[idx][s_idx] = '\n';
			else if (s_idx == x_n + 1)
				map[idx][s_idx] = 0;
			else
				map[idx][s_idx] = ' ';
			s_idx++;
		}
		idx++;
	}

	ft_solve(map, 0, 0, y_n, x_n);

	idx = 0;
	while (idx < y_n)
		printf("%s", map[idx++]);
	return (0);
}