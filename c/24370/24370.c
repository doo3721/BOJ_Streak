#include <stdio.h>

float	ft_min_disc(int a, int b, int c)
{
	int		num, idx;
	float	f_idx;

	num = b * b - 4 * a * c;

	if (num <= 0)
		return (num);

	idx = 1;
	while (idx * idx <= num)
	{
		if (idx * idx == num)
			return (idx);
		idx++;
	}
	
	f_idx = idx - 1;
	while (f_idx * f_idx <= num)
	{
		if (f_idx * f_idx == num)
			return (f_idx);
		f_idx += 0.1;
	}
	f_idx -= 0.1;
	return (f_idx);
}

int	ft_big_o(int a2, int a1, int a0, int c, int n0)
{
	float	min_disc;
	float	max_x;

	if (a2 == c)
	{
		if ((a1 == 0 && a0 <= 0) || (a1 < 0 && n0 >= a0 / a1))
			return (1);
		else
			return (0);
	}
	else if (c > a2)
	{
		min_disc = ft_min_disc(c - a2, -a1, -a0);

		if (min_disc > 0)
		{
			max_x = (float) (a1 + min_disc) / (float) (2 * (c - a2));

			if (n0 >= max_x)
				return (1);
			else
				return (0);
		}
		else
			return (1);
	}
	else
		return (0);
}

int	ft_big_omega(int a2, int a1, int a0, int c, int n0)
{
	float	min_disc;
	float	max_x;

	if (a2 == c)
	{
		if ((a1 == 0 && a0 >= 0) || (a1 > 0 && n0 >= a0 / a1))
			return (1);
		else
			return (0);
	}
	else if (a2 > c)
	{
		min_disc = ft_min_disc(a2 - c, a1, a0);

		if (min_disc > 0)
		{
			max_x = (float) (-a1 + min_disc) / (float) (2 * (a2 - c));

			if (n0 >= max_x)
				return (1);
			else
				return (0);
		}
		else
			return (1);
	}
	else
		return (0);
}

int main(void)
{
	int a2, a1, a0, c1, c2, n0;
	int	is_big_o, is_big_omega;

	scanf("%d%d%d%d%d%d", &a2, &a1, &a0, &c1, &c2, &n0);

	is_big_o = ft_big_o(a2, a1, a0, c2, n0);
	is_big_omega = ft_big_omega(a2, a1, a0, c1, n0);

	if (is_big_o && is_big_omega)
		printf("1");
	else
		printf("0");
	
	return (0);
}