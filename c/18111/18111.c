#include <stdio.h>

static int n, m, b, ans_t, ans_h, min_h;

void	ft_solve(int map[][500])
{
	int	h, i, j, r_b, f_b, t;

	ans_t = -1;
	h = ans_h;
	while (h >= min_h)
	{
		i = 0;
		r_b = 0;
		f_b = 0;
		while (i < n)
		{
			j = 0;
			while (j < m)
			{
				if (map[i][j] >= h)
					r_b += map[i][j] - h;
				else
					f_b += h - map[i][j];
				j++;
			}
			i++;
		}

		if (r_b + b >= f_b)
		{
			t = r_b * 2 + f_b;
			if (t < ans_t || ans_t < 0)
			{
				ans_h = h;
				ans_t = t;
			}
		}
		h--;
	}
}

int main(void)
{
	int i, j, map[500][500];

	scanf("%d%d%d", &n, &m, &b);

	i = 0;
	ans_h = 0;
	min_h = 257;
	while (i < n)
	{
		j = 0;
		while (j < m)
		{
			scanf("%d", &map[i][j++]);
			if (ans_h < map[i][j - 1])
				ans_h = map[i][j - 1];
			else if (min_h > map[i][j - 1])
				min_h = map[i][j - 1];
		}
		i++;
	}

	ft_solve(map);
	printf("%d %d", ans_t, ans_h);
	return (0);
}