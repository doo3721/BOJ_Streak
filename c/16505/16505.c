#include <stdio.h>

int	ft_power(int n)
{
	int num;

	num = 1;
	while (n)
	{
		num *= 2;
		n--;
	}
	return (num);
}

void	ft_solve(char (*map)[1026], int x, int y, int m_x, int m_y)
{
	if (m_x - x == 2 || m_y - y == 2)
	{
		map[x][y] = '*';
		map[x][y + 1] = '*';
		map[x + 1][y] = '*';
		return ;
	}
	else
	{
		ft_solve(map, x, y, m_x - (m_x - x) / 2, m_y - (m_y - y) / 2);
		ft_solve(map, x, y + (m_y - y) / 2, m_x - (m_x - x) / 2, m_y);
		ft_solve(map, x + (m_x - x) / 2, y, m_x, m_y - (m_y - y) / 2);
	}
}

int main(void)
{
	int		n, power, idx, s_idx;
	char	map[1024][1026] = {"", };

	scanf("%d", &n);

	power = ft_power(n);
	idx = 0;
	while (idx < power)
	{
		s_idx = 0;
		while (s_idx < power)
			map[idx][s_idx++] = ' ';
		idx++;
	}

	if (power == 1)
		map[0][0] = '*';
	else
		ft_solve(map, 0, 0, power, power);

	idx = 0;
	while (idx < power)
	{
		if (idx != power - 1)
		{
			map[idx][power - idx] = '\n';
			map[idx][power - idx + 1] = 0;
		}
		else
			map[idx][power - idx] = 0;
		printf("%s", map[idx++]);
	}

	return (0);
}