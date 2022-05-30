#include <stdio.h>
#include <stdlib.h>

void	ft_solve(char **map, int y, int x, int m_y, int m_x)
{
	if (m_y - y <= 3 || m_x - x <= 3)
	{
		map[y][x] = '*';
		map[y][x + 1] = '*';
		map[y][x + 2] = '*';
		map[y + 1][x] = '*';
		map[y + 1][x + 2] = '*';
		map[y + 2][x] = '*';
		map[y + 2][x + 1] = '*';
		map[y + 2][x + 2] = '*';
	}
	else
	{
		ft_solve(map, y,					 x, 					m_y - (m_y - y) / 3 * 2, m_x - (m_x - x) / 3 * 2);
		ft_solve(map, y,					 x + (m_x - x) / 3, 	m_y - (m_y - y) / 3 * 2, m_x - (m_x - x) / 3 	);
		ft_solve(map, y,					 x + (m_x - x) / 3 * 2, m_y - (m_y - y) / 3 * 2, m_x 					);
		ft_solve(map, y + (m_y - y) / 3,	 x, 					m_y - (m_y - y) / 3,	 m_x - (m_x - x) / 3 * 2);
		ft_solve(map, y + (m_y - y) / 3,	 x + (m_x - x) / 3 * 2, m_y - (m_y - y) / 3,	 m_x 					);
		ft_solve(map, y + (m_y - y) / 3 * 2, x, 					m_y, 					 m_x - (m_x - x) / 3 * 2);
		ft_solve(map, y + (m_y - y) / 3 * 2, x + (m_x - x) / 3, 	m_y, 			 		 m_x - (m_x - x) / 3 	);
		ft_solve(map, y + (m_y - y) / 3 * 2, x + (m_x - x) / 3 * 2, m_y, 			 		 m_x 					);
	}
}

int main(void)
{
	char	*map[2187];
	int		n, idx, s_idx;

	scanf("%d", &n);

	idx = 0;
	while (idx < n)
	{
		map[idx] = malloc(sizeof(char) * (n + 2));
		s_idx = 0;
		while (s_idx < n)
			map[idx][s_idx++] = ' ';
		map[idx][n] = '\n';
		map[idx][n + 1] = 0;
		idx++;
	}

	ft_solve(map, 0, 0, n, n);

	idx = 0;
	while (idx < n)
		printf("%s", map[idx++]);
	return (0);
}