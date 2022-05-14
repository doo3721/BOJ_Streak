#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	main(void)
{
	int	a;
	int	b;
	int	c;

	while (1)
	{
		scanf("%d", &a);
		scanf("%d", &b);
		scanf("%d", &c);
		if (!a && !b && !c)
			break ;

		if (a > b && a > c)
			ft_swap(&a, &c);
		else if (b > a && b > c)
			ft_swap(&b, &c);

		if (((a * a) + (b * b)) == (c * c))
			printf("right\n");
		else
			printf("wrong\n");
	}
	return (0);
}