#include <stdio.h>

float	ft_min_disc(int a, int b, int c)
{
	int		num, idx;
	float	f_idx;

	num = b * b - 4 * a * c;

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

int main(void)
{
	int 	a2, a1, a0, c, n0;
	float	min_disc;
	float	max_x;

	scanf("%d%d%d%d%d", &a2, &a1, &a0, &c, &n0);

	if (a2 == c)
	{
		if ((a1 == 0 && a0 >= 0) || (a1 < 0 && n0 >= a0 / a1))
			printf("1");
		else
			printf("0");
	}
	else if (c > a2)
	{
		min_disc = ft_min_disc(c - a2, -a1, -a0);
		max_x = (float) (a1 + min_disc) / (float) (2 * (c - a2));

		if (n0 >= max_x)
			printf("1");
		else
			printf("0");
	}
	else
		printf("0");

	return (0);
}