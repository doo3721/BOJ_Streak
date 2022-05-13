#include <stdio.h>
#include <stdlib.h>

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

int	ft_point_cmp(t_point a_p, t_point b_p)
{
	if (a_p.x > b_p.x)
		return (1);
	else if (a_p.x == b_p.x)
	{
		if (a_p.y > b_p.y)
			return (1);
		else if (a_p.y == b_p.y)
			return (0);
	}
	return (-1);
}

void	ft_point_swap(t_point *a_p, t_point *b_p)
{
	t_point	temp;

	temp = *a_p;
	*a_p = *b_p;
	*b_p = temp;
}

void	ft_quicksort(t_point *points, int left, int right)
{
	int		i_left;
	int		i_right;
	t_point	pivot;

	i_left = left;
	i_right = right;
	pivot = points[(left + right) / 2];
	while (i_left <= i_right)
	{
		while (ft_point_cmp(points[i_left], pivot) < 0)
			i_left++;
		while (ft_point_cmp(pivot, points[i_right]) < 0)
			i_right--;
		if (i_left <= i_right)
		{
			ft_point_swap(&points[i_left], &points[i_right]);
			i_left++;
			i_right--;
		}
	}
	if (left < i_right)
		ft_quicksort(points, left, i_right);
	if (i_left < right)
		ft_quicksort(points, i_left, right);
}

int	main(void)
{
	t_point	*points;
	int		count;
	int		idx;

	scanf("%d", &count);

	points = malloc(sizeof(t_point) * count);
	if (!points)
		return (0);
	idx = 0;
	while (idx < count)
	{
		scanf("%d", &points[idx].x);
		scanf("%d", &points[idx].y);
		idx++;
	}

	ft_quicksort(points, 0, count - 1);

	idx = 0;
	while (idx < count)
	{
		printf("%d %d\n", points[idx].x, points[idx].y);
		idx++;
	}
	free(points);
	return (0);
}

/*
좀 더  간편하게 만들수 있는 알고리즘을 만들 것
*/