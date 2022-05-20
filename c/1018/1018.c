#include <stdio.h>
#include <stdlib.h>

static int	count = 0;

void	ft_map_check(char **map, int n_s, int m_s)
{
	int n_idx;
	int m_idx;

	n_idx = n_s;
	count = 0;
	while (n_idx < n_s + 8)
	{
		m_idx = m_s;
		while (m_idx < m_s + 8)
		{
			if (n_idx != n_s || m_idx != m_s)
			{
				if (((n_idx - n_s) % 2 == 0 && (m_idx - m_s) % 2 == 1)
				|| ((n_idx - n_s) % 2 == 1 && (m_idx - m_s) % 2 == 0))
				{
					if (map[n_idx][m_idx] == map[n_s][m_s])
						count++;
				}
				else
				{
					if (map[n_idx][m_idx] != map[n_s][m_s])
						count++;
				}
			}
			m_idx++;
		}
		n_idx++;
	}

	if (count > 32)
		count = 64 - count;
}

int	main(void)
{
	int 	n;
	int 	m;
	int		n_idx;
	int 	m_idx;
	int 	min;
	char	**map;

	scanf("%d%d", &n, &m);
	map = malloc(sizeof(char *) * n);

	n_idx = 0;
	while (n_idx < n)
	{
		map[n_idx] = malloc(sizeof(char) * (m + 1));
		scanf("%s", map[n_idx]);
		n_idx++;
	}

	n_idx = 0;
	min = 3000;
	while (n_idx <= (n - 8))
	{
		m_idx = 0;
		while (m_idx <= (m - 8))
		{
			ft_map_check(map, n_idx, m_idx);
			if (min > count)
				min = count;
			m_idx++;
		}
		n_idx++;
	}
	free(map);
	printf("%d\n", min);
	return (0);
}