#include <stdio.h>
#include <stdlib.h>

static int	n, m, b, min_h, max_h, time;

int	ft_check(int **map, int h)
{
	int n_idx, m_idx, temp_b, t_time;

	temp_b = b;
	t_time = 0;
	n_idx = 0;
	while (n_idx < n)
	{
		m_idx = 0;
		while (m_idx < m)
		{
			if (h - map[n_idx][m_idx] > 0)
			{
				temp_b -= (h - map[n_idx][m_idx]) ;
				t_time += (h - map[n_idx][m_idx]);
			}
			m_idx++;
		}
		n_idx++;
	}

	if (temp_b >= 0 && !t_time)
	{
		if (t_time <= time)
		{
			time = t_time;
			return (3);
		}
		else
			return (2);
	}

	n_idx = 0;
	while (n_idx < n)
	{
		m_idx = 0;
		while (m_idx < m)
		{
			if (map[n_idx][m_idx] - h > 0)
			{
				temp_b += (map[n_idx][m_idx] - h);
				t_time += (map[n_idx][m_idx] - h) * 2;
			}
			m_idx++;
		}
		n_idx++;
	}

	if (temp_b >= 0 && !t_time)
	{
		if (t_time <= time)
		{
			time = t_time;
			return (1);
		}
		else
			return (0);
	}
	return (0);
}

void	ft_search(int **map)
{
	int left, right, mid;

	time = 2000000000;
	left = min_h;
	right = max_h;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (ft_check(map, mid) == 3)
			left = mid + 1;
		else if (ft_check(map, mid) == 2)
			right = mid;
		else if (ft_check(map, mid) == 1)
			left = mid + 1;
		else
			right = mid;
	}

	while (!ft_check(map, right))
		right--;
	
	max_h = right;
}

int main(void)
{
	int n_idx, m_idx;
	int **map;

	scanf("%d%d%d", &n, &m, &b);

	map = malloc(sizeof(int *) * n);

	n_idx = 0;
	min_h = 256;
	min_h = 0;
	while (n_idx < n)
	{
		map[n_idx] = malloc(sizeof(int) * m);
		m_idx = 0;
		while (m_idx < m)
		{
			scanf("%d", &map[n_idx][m_idx]);
			if (min_h > map[n_idx][m_idx])
				min_h = map[n_idx][m_idx];
			else if (max_h < map[n_idx][m_idx])
				max_h = map[n_idx][m_idx];
			m_idx++;
		}
		n_idx++;
	}

	ft_search(map);
	printf("%d %d", time, max_h);

	free(map);
	return (0);
}